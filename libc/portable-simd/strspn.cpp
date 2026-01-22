/*
 * Copyright (C) 2026 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "portable_simd_detail.h"
#include "portable_simd_exports.h"

namespace portable_simd {
namespace {

// strspn exclusively uses 16B vectors, since:
// 1. The 'large' implementation is written assuming 16B vectors, and would
//    need to be rewritten for larger vector types.
// 2. Larger vectors for the 'small' path only really help as we traverse deep
//    into the haystack; it seems likely that most 'hits' will be early on in
//    the haystack.
//
// Moreover, "it's simpler this way, and probably more than sufficiently fast."
using ElemTy = int8_t;
using FullVec = hn::Full128<ElemTy>;
using FullVecTy = hn::VFromD<FullVec>;
using FullVecM = hn::MFromD<FullVec>;

constexpr static size_t kMaxSmallSize = 4;

// Runs `strspn`-like functions, where `f` provides the implementation.
//
// The signature of `f` should be compatible with:
// optional<size_t> f(FullVecTy v, optional<size_t> ignore_first = {});
//
// where:
//   - `v` is a vector of chars to scan,
//   - `ignore_first` is the number of chars in `v` to ignore (starting at the
//     0th lane)
//   - The return is an empty optional if the algo should keep scanning;
//     otherwise, it's the lane number of the char the algo should stop at in
//     `v` (less `ignore_first`, if provided).
template <typename Fn>
PSIMD_FLATTEN size_t strspn_driver(const ElemTy* haystack, Fn f) {
  constexpr FullVec d;
  size_t total_scanned = 0;
  const auto shift_back_bytes = reinterpret_cast<uintptr_t>(haystack) & (d.MaxBytes() - 1);
  if (shift_back_bytes) {
    static_assert(sizeof(ElemTy) == 1, "Adjust shift_back_bytes calculation");
    const auto this_vec = LoadU(d, haystack - shift_back_bytes);
    if (const optional<size_t> index = f(this_vec, optional<size_t>{shift_back_bytes})) {
      return total_scanned + *index;
    }
    total_scanned = d.MaxBytes() - shift_back_bytes;
  }

  while (true) {
    const auto this_vec = Load(d, haystack + total_scanned);
    if (const optional<size_t> index = f(this_vec)) {
      return total_scanned + *index;
    }
    total_scanned += d.MaxLanes();
  }
}

// Implements `strspn` given an array of `Set` vectors for all `keep` elements.
// Example usage is `strspn_small(p, {Set(d, 'a'), Set(d, 'b')})`, if the `keep`
// elements are "ab".
template <size_t SmallSize>
PSIMD_FLATTEN size_t strspn_small(const ElemTy* haystack, const FullVecTy keep[SmallSize]) {
  constexpr FullVec d;

  const auto index_of_non_needle = [&](const FullVecTy& v, optional<size_t> ignore_first = {})
                                       PSIMD_FLATTEN -> optional<size_t> {
    FullVecM eq_mask = v == keep[0];
    if (ignore_first) {
      eq_mask = Or(eq_mask, FirstN(d, *ignore_first));
    }
#pragma unroll
    for (size_t i = 1; i < SmallSize; ++i) {
      eq_mask = Or(eq_mask, v == keep[i]);
    }

    if (AllTrue(d, eq_mask)) {
      return {};
    }

    size_t index = FindKnownFirstTrue(d, Not(eq_mask));
    if (ignore_first) {
      index -= *ignore_first;
    }
    return optional<size_t>{index};
  };

  return strspn_driver(haystack, index_of_non_needle);
}

template <size_t SmallSize>
PSIMD_FLATTEN size_t strcspn_small(const ElemTy* haystack, const FullVecTy reject[SmallSize]) {
  constexpr FullVec d;

  const auto index_of_needle = [&](const FullVecTy& v, optional<size_t> ignore_first = {})
                                   PSIMD_FLATTEN -> optional<size_t> {
    FullVecM eq_mask = v != Zero(d);
#pragma unroll
    for (size_t i = 0; i < SmallSize; ++i) {
      eq_mask = And(eq_mask, v != reject[i]);
    }

    if (ignore_first) {
      eq_mask = Or(eq_mask, FirstN(d, *ignore_first));
    }

    if (AllTrue(d, eq_mask)) {
      return {};
    }

    size_t index = FindKnownFirstTrue(d, Not(eq_mask));
    if (ignore_first) {
      index -= *ignore_first;
    }
    return optional<size_t>{index};
  };

  return strspn_driver(haystack, index_of_needle);
}

template <typename Fn>
PSIMD_FLATTEN optional<size_t> try_dispatch_to_small_strspnish(const ElemTy* haystack,
                                                               const ElemTy* str,
                                                               bool is_reject_set,
                                                               Fn strspn_small_fn) {
  constexpr FullVec d;

  if (!str[0]) [[unlikely]] {
    if (is_reject_set) {
      return optional<size_t>{__builtin_strlen(reinterpret_cast<const char*>(haystack))};
    }
    return optional<size_t>{0};
  }

  FullVecTy checks[kMaxSmallSize];
  checks[0] = Set(d, str[0]);
#pragma unroll
  for (size_t i = 1; i < kMaxSmallSize; ++i) {
    checks[i] = checks[0];
  }

  bool is_small = false;
#pragma unroll
  for (size_t i = 0; i < kMaxSmallSize; ++i) {
    if (str[i] == 0) {
      // If this is strcspn with a single elem in `str`, we can trivially defer to
      // `strchrnul`, which we have optimized implementations of for the 64-bit
      // architectures.
      //
      // (Note that this branch is expected to fold away after unrolling, and
      // given that `is_reject_set` should be a constant from the caller)
      if (i == 1 && is_reject_set) {
        const auto* res_ptr = reinterpret_cast<const ElemTy*>(
            strchrnul(reinterpret_cast<const char*>(haystack), str[0]));
        const size_t res = res_ptr - haystack;
        return optional<size_t>{res};
      }

      // NOTE: This is not written as `return strspn_small_fn(haystack,
      // checks)` because LLVM's optimizations are more likely to turn that
      // into N inlined function calls to `strspn_small_fn`.
      //
      // Instead, have precisely one unrolled callsite, and N jumps to that,
      // which should be much more compact and closer to what we 'actually'
      // want here.
      is_small = true;
      break;
    }
    checks[i] = Set(d, str[i]);
  }
  if (is_small) {
    return optional<size_t>{strspn_small_fn(haystack, checks)};
  }
  return {};
}

struct VecBitSet {
  PSIMD_FLATTEN static VecBitSet from_large_string(const ElemTy* keep, bool include_nul) {
    constexpr FullVec d;
    // On Brya (mobile Intel from ~2022), four approaches were tested. Listed
    // in order of observed performance on Bionic's benchmarks (earlier is
    // better performance):
    //
    // 1. this one
    // 2. a direct bitset stored in `uint8_t[256 / 8]`
    // 3. maintaining a bitset directly in 128B vector registers
    // 4. a bitset from `uint8_t[256]` (which matches `strspn/strcspn`'s
    //    current implementation), which was later 'compressed' into two
    //    vectors.
    uint64_t lo_lo = 0;
    uint64_t lo_hi = 0;
    uint64_t hi_lo = 0;
    uint64_t hi_hi = 0;

    auto push_bits_into = [](uint8_t c, uint64_t& hi, uint64_t& lo) PSIMD_FLATTEN {
      PSIMD_DCHECK(c <= 0x7F);
      // It's expected that storing to `hi` or `lo` will be unpredictable, so
      // store to both.
      //
      // `bit` represents the bit to set, `is_hi` is either all 1s or 0s,
      // depending on the value of `c & 0x40`.
      const uint64_t bit = 1ULL << (c & 0x3F);
      const uint64_t is_hi = -static_cast<uint64_t>(c >> 6);
      hi |= bit & is_hi;
      lo |= bit & ~is_hi;
    };

    auto push_char = [&](uint8_t c) PSIMD_FLATTEN {
      if (c >= 0x80) [[unlikely]] {
        push_bits_into(c ^ 0x80, hi_hi, hi_lo);
      } else {
        push_bits_into(c, lo_hi, lo_lo);
      }
    };

    size_t i = 0;
#pragma unroll
    for (; i < kMaxSmallSize; ++i) {
      PSIMD_DCHECK(keep[i]);
      push_char(static_cast<uint8_t>(keep[i]));
    }

    for (; keep[i]; ++i) {
      push_char(static_cast<uint8_t>(keep[i]));
    }
    if (include_nul) {
      push_char(0);
    }

    constexpr hn::Full128<uint64_t> d64;

    const auto lo = Dup128VecFromValues(d64, lo_lo, lo_hi);
    const auto hi = Dup128VecFromValues(d64, hi_lo, hi_hi);
    return VecBitSet{BitCast(d, hi), BitCast(d, lo)};
  }

  PSIMD_FLATTEN void flip_all_bits() {
    // Technically this is pointless if `!hi_relevant_`, but the extra check is
    // likely more expensive than just flipping the bits unconditionally.
    hi_ = Not(hi_);
    lo_ = Not(lo_);
    hi_flipped_ = !hi_flipped_;
  }

  PSIMD_FLATTEN optional<size_t> index_of_first_unset(FullVecTy v,
                                                      optional<size_t> ignore_first = {}) const {
    constexpr FullVec d;

    FullVecM eq_mask = test_membership(v, lo_);
    // If `hi_relevant_` is set, then we have chars outside of the standard
    // ASCII range. Technically permitted, but should be incredibly rare.
    if (hi_relevant_) [[unlikely]] {
      const FullVecTy hi_bits = Set(d, static_cast<ElemTy>(0x80));
      eq_mask = Or(eq_mask, test_membership(v ^ hi_bits, hi_));
    } else if (hi_flipped_) {
      eq_mask = Or(eq_mask, v < Zero(d));
    }
    if (ignore_first) {
      eq_mask = Or(eq_mask, FirstN(d, *ignore_first));
    }

    if (AllTrue(d, eq_mask)) {
      return {};
    }

    size_t index = FindKnownFirstTrue(d, Not(eq_mask));
    if (ignore_first) {
      index -= *ignore_first;
    }
    return optional<size_t>{index};
  }

 private:
  VecBitSet(FullVecTy hi, FullVecTy lo)
      : hi_(hi), lo_(lo), hi_relevant_(!AllBits0(FullVec(), hi)), hi_flipped_(false) {}

  // Does membership tests for each lane in v, returning a mask where lane i is
  // set if v[i] is in the bitset represented by lookups.
  //
  // All lanes of v must be in [0, 127]. Anything outside of that is zeroed in
  // the mask.
  PSIMD_FLATTEN static FullVecM test_membership(FullVecTy v, FullVecTy lookups) {
    constexpr FullVec d;

    // These are 128-bit vectors. Bit [i] indicates whether [i] is set.
    static_assert(sizeof(FullVecTy) == 16, "Expected 128-bit vectors");

    // This is a standard bit-set. Bit `i` will be in lane (i / 8) of the
    // lookup vector, at bit (i % 8).

    // ...To that end, move the bitset's lane `(i / 8)` into the lanes
    // corresponding to `v`.
    const auto index_parts = ShiftRight<3>(v);
    const auto lookup_masks = TableLookupBytesOr0(lookups, index_parts);

    // ...And then figure out the bit in each `v[i]` that needs to be set.
    const auto mask_shift_amounts = v & Set(d, 7);
    auto nth_bits = [&](auto v) PSIMD_FLATTEN {
      // The instruction sequence to emulate a bytewise `1 << v[i]` in SSE and
      // AVX are pretty massive; just look up from a table instead.
      if constexpr (kTargetIsX86OrX86_64) {
        alignas(d.MaxBytes()) static const int8_t bits[d.MaxLanes()] = {
            1u << 0, 1u << 1, 1u << 2, 1u << 3, 1u << 4, 1u << 5, 1u << 6, (int8_t)(1u << 7),
        };
        const auto loaded = Load(d, bits);
        return TableLookupBytes(loaded, v);
      } else {
        return Set(d, 1) << v;
      }
    };
    const auto shifted_masks = nth_bits(mask_shift_amounts);

    // ...Finally, it's as simple as `&`.
    return (lookup_masks & shifted_masks) != Zero(d);
  }

  FullVecTy hi_;
  FullVecTy lo_;
  // `hi_relevant_` tracks whether `hi_` is just all unset (or all set, in the
  // case of `hi_flipped_`).
  //
  // Testing this is trivial, should be consistently `false`, and lets us skip
  // a decent number of instructions if it is `false`.
  const bool hi_relevant_;
  // If `!hi_relevant_`, this indicates whether `hi` should be treated as all
  // `true` values.
  bool hi_flipped_;
};

// Mark this `noinline` because it's the uncommon case, and it adds a lot of
// register pressure to its caller on x86_64.
//
// Visually inspecting `objdump`, `noinline` allows `strspn` to operate without
// touching the stack unless it _has_ to call this function. With
// `PSIMD_FLATTEN`, we end up unconditionally saving/restoring 3 registers for
// no reason.
__attribute__((noinline)) size_t strspn_large(const ElemTy* haystack, const ElemTy* keep) {
  const auto bitset = VecBitSet::from_large_string(keep, /*include_nul=*/false);
  return strspn_driver(haystack,
                       [&](FullVecTy v, optional<size_t> ignore_first = {})
                           PSIMD_FLATTEN { return bitset.index_of_first_unset(v, ignore_first); });
}

// Mark this `noinline` because it's the uncommon case, and it adds a lot of
// register pressure to its caller on x86_64.
//
// Visually inspecting `objdump`, `noinline` allows `strcspn` to operate
// without touching the stack unless it _has_ to call this function. With
// `PSIMD_FLATTEN`, we end up unconditionally saving/restoring 4 registers for
// no reason.
__attribute__((noinline)) size_t strcspn_large(const ElemTy* haystack, const ElemTy* reject) {
  // `include_nul` since we're going to run `strspn`, but with membership flipped.
  auto bitset = VecBitSet::from_large_string(reject, /*include_nul=*/true);
  bitset.flip_all_bits();
  return strspn_driver(haystack,
                       [&](FullVecTy v, optional<size_t> ignore_first = {})
                           PSIMD_FLATTEN { return bitset.index_of_first_unset(v, ignore_first); });
}
}  // namespace
}  // namespace portable_simd

PSIMD_LIBC_FUNCTION(size_t, strspn, const char* raw_haystack, const char* raw_keep) {
  const auto* haystack = reinterpret_cast<const portable_simd::ElemTy*>(raw_haystack);
  const auto* keep = reinterpret_cast<const portable_simd::ElemTy*>(raw_keep);

  if (const auto small_result = portable_simd::try_dispatch_to_small_strspnish(
          haystack, keep, /*is_reject_set=*/false,
          portable_simd::strspn_small<portable_simd::kMaxSmallSize>)) {
    return *small_result;
  }

  return portable_simd::strspn_large(haystack, keep);
}

PSIMD_LIBC_FUNCTION(size_t, strcspn, const char* raw_haystack, const char* raw_reject) {
  const auto* haystack = reinterpret_cast<const portable_simd::ElemTy*>(raw_haystack);
  const auto* reject = reinterpret_cast<const portable_simd::ElemTy*>(raw_reject);

  if (const auto small_result = portable_simd::try_dispatch_to_small_strspnish(
          haystack, reject, /*is_reject_set=*/true,
          portable_simd::strcspn_small<portable_simd::kMaxSmallSize>)) {
    return *small_result;
  }
  return portable_simd::strcspn_large(haystack, reject);
}

PSIMD_STRONG_ALIAS(strspn);
PSIMD_STRONG_ALIAS(strcspn);
