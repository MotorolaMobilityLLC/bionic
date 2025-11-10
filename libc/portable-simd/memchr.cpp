/*
 * Copyright (C) 2025 The Android Open Source Project
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

#include <stdbit.h>
#include <stdint.h>
#include <string.h>

#include "portable_simd_detail.h"
#include "portable_simd_exports.h"

namespace portable_simd {
namespace {

// Highway doesn't support direct `char` usage in vector types, presumably
// because it can vary in signed-ness. `memchr` does not care at all; choose
// signed because hwy docs say it's slightly more efficient on older x86_64
// CPUs. If there's any better argument for unsigned, that should probably be
// preferred.
using CharType = int8_t;
using VectorTag = portable_simd::FullVector<CharType>;

// Both memchr and memrchr share an implementation, with a `Traits` object to
// encapsulate their differences.
struct MemchrTraits {
  constexpr static bool kIsMaxLengthGuaranteed = true;

  // Advance `ptr` in the direction of this memchr.
  PSIMD_FLATTEN static const CharType* advance_ptr(const CharType* p, size_t n = 1) {
    constexpr VectorTag d;
    return p + n * d.MaxBytes();
  }

  // Performs adjustment on `p` before starting the algorithm. Memchr starts at `p`.
  PSIMD_FLATTEN static const CharType* initial_adjust_ptr(const CharType* p, size_t) { return p; }

  // Given a scalar mask indicating which vector element(s) matched our target
  // character, return the offset from the vector pointer of the closest
  // match.
  PSIMD_FLATTEN static size_t byte_offset_of_first(ScalarMaskForD<VectorTag> mask) {
    return stdc_trailing_zeros(mask);
  }

  // Returns the pointer to the closest element in `val` equal to `ch`,
  // provided `val` was loaded from `ptr - bytes_to_skip`. If `count` is
  // non-empty, this will ignore any elements in the highest `count` bytes of
  // `val`.
  PSIMD_FLATTEN static optional<const void*> ptr_of_first(const CharType* ptr,
                                                          hn::VFromD<VectorTag> val, CharType ch,
                                                          optional<size_t> count = {},
                                                          optional<size_t> bytes_to_skip = {}) {
    constexpr VectorTag d;
    const auto all_ch = Set(d, ch);
    const size_t raw_eq_mask = BitsFromMask(d, all_ch == val);
    size_t eq_mask = raw_eq_mask >> bytes_to_skip.unwrap_or(0);

    if (count) {
      const size_t inbounds_mask = ~(kMaxSizeT << *count);
      eq_mask &= inbounds_mask;
    }

    if (!eq_mask) {
      return {};
    }

    return optional<const void*>{ptr + byte_offset_of_first(eq_mask)};
  }

  // `align_forward_to_vec`.
  PSIMD_FLATTEN static auto align_ptr_to_vec(const CharType* s, auto f) {
    return align_forward_to_vec<VectorTag>(s, f);
  }

  // `align_forward_to_vec_known_safe`.
  PSIMD_FLATTEN static auto align_ptr_to_vec_known_safe(const CharType* s, auto f) {
    return align_forward_to_vec_known_safe<VectorTag>(s, f);
  }
};

struct MemrchrTraits {
  constexpr static bool kIsMaxLengthGuaranteed = true;

  // Advance `ptr` in the direction of this memchr.
  PSIMD_FLATTEN static const CharType* advance_ptr(const CharType* p, size_t n = 1) {
    constexpr VectorTag d;
    return p - n * d.MaxBytes();
  }

  // Performs adjustment on `p` before starting the algorithm.
  // Memrchr starts at the end and immediately calls alignment functions that
  // expect the pointer to be adjusted backwards by one vector width.
  PSIMD_FLATTEN static const CharType* initial_adjust_ptr(const CharType* p, size_t count) {
    constexpr VectorTag d;
    return p + count - d.MaxBytes();
  }

  // Given a scalar mask indicating which vector element(s) matched our target
  // character, return the offset from the vector pointer of the farthest
  // match.
  PSIMD_FLATTEN static size_t byte_offset_of_first(ScalarMaskForD<VectorTag> mask) {
    constexpr VectorTag d;
    const size_t leading_zeros = stdc_leading_zeros(mask);
    const size_t distance_of_one = leading_zeros + 1;
    const size_t offset_from_start = d.MaxBytes() - distance_of_one;
    return offset_from_start;
  }

  // Returns the pointer to the farthest element in `val` equal to `ch`,
  // provided `val` was loaded from `ptr - bytes_to_skip`. If `count` is
  // non-empty, this will ignore any elements in the lowest `count` bytes of `val`.
  PSIMD_FLATTEN static optional<const void*> ptr_of_first(const CharType* ptr,
                                                          hn::VFromD<VectorTag> val, CharType ch,
                                                          optional<size_t> count = {},
                                                          optional<size_t> bytes_to_skip = {}) {
    constexpr VectorTag d;
    const auto all_ch = Set(d, ch);

    // NOTE: The size of this type is important; this code ends up simpler if we
    // can rely on this mask only ever containing bits that correspond with
    // vector lanes.
    ScalarMaskForD<VectorTag> eq_mask = BitsFromMask(d, all_ch == val);

    // TODO(gbiv): This was written expecting that `count` and `bytes_to_skip`
    // would both trivially `has_value` or not, so there'll no be actual
    // branches here. It could be nice to either:
    // - have an assertion of that here (though attempts like
    //   `if (!__builtin_constant_p(has_value())) warning_func();` have failed,
    //   despite no branches existing in the LLVM IR related to the optionals),
    //   or
    // - template this on some kind of `const_optional` type so we can `if
    //   constexpr` these branches
    if (bytes_to_skip) {
      eq_mask <<= *bytes_to_skip;
    }

    if (count) {
      const size_t count_mask = kMaxSizeT << (d.MaxBytes() - *count);
      eq_mask &= count_mask;
    }

    if (!eq_mask) {
      return {};
    }
    return optional<const void*>{ptr + byte_offset_of_first(eq_mask)};
  }

  // `align_backward_to_vec`.
  PSIMD_FLATTEN static auto align_ptr_to_vec(const CharType* s, auto f) {
    return align_backward_to_vec<VectorTag>(s, f);
  }

  // `align_backward_to_vec_known_safe`.
  PSIMD_FLATTEN static auto align_ptr_to_vec_known_safe(const CharType* s, auto f) {
    return align_backward_to_vec_known_safe<VectorTag>(s, f);
  }
};

struct StrnlenTraits : MemchrTraits {
  // `strnlen` is `memchr`, with the caveat that we can't assume that `count`
  // bytes *must be* available at the given pointer.
  constexpr static bool kIsMaxLengthGuaranteed = false;

  PSIMD_FLATTEN __attribute__((diagnose_if(true, "This is unsafe, and should never be called",
                                           "error"))) static auto
  align_ptr_to_vec_known_safe(auto...) {
    __builtin_unreachable();
  }
};

template <typename Traits>
PSIMD_FLATTEN static const void* memchr_vectorized(const CharType* s, CharType ch, size_t count) {
  constexpr VectorTag d;

  s = Traits::initial_adjust_ptr(s, count);

  const auto result_from_final_vec = [ch](const CharType* ptr, const auto vec_val, size_t count,
                                          optional<size_t> bytes_to_skip = {}) -> const void* {
    // If `count == 0`, we loaded `vec_val` when we shouldn't have. This is a
    // correctness issue, since `ptr` might've been at the start of a new page.
    PSIMD_DCHECK(count != 0);
    return Traits::ptr_of_first(ptr, vec_val, ch, optional<size_t>{count}, bytes_to_skip)
        .unwrap_or(nullptr);
  };

  if (count <= d.MaxBytes()) {
    // Unlikely because it seems rare that people would depend on 0-sized
    // memrchrs being a very fast case.
    if (count == 0) [[unlikely]] {
      return nullptr;
    }

    // We know for certain that we need 2 or fewer loads to service this request.
    const auto [ptr, maybe_result] = Traits::align_ptr_to_vec(
        s,
        [&](const auto val, optional<size_t> bytes_to_skip, optional<size_t>)
            PSIMD_FLATTEN -> optional<const void*> {
              // If we loaded `ptr` directly, one vector op is all this will
              // take.
              if (!bytes_to_skip.has_value()) {
                return optional{result_from_final_vec(s, val, count)};
              }

              // Reiterating from `align_forward_to_vec`, this is expected to
              // be inlined such that `bytes_to_skip.has_value()` always
              // trivially folds to a constant.
              if (const optional<const void*> x =
                      Traits::ptr_of_first(s, val, ch, optional<size_t>{count}, bytes_to_skip)) {
                return x;
              }

              const auto bytes_read = d.MaxBytes() - *bytes_to_skip;
              if (bytes_read >= count) {
                return optional<const void*>{nullptr};
              }

              count -= bytes_read;
              return {};
            });

    if (maybe_result) {
      return *maybe_result;
    }
    return result_from_final_vec(ptr, Load(d, ptr), count);
  }

  // As long as `count` bytes are guaranteed to be available, we know the full
  // load is safe, since `count` is larger than a full vector.
  auto align_func = [&](auto val, optional<size_t> bytes_to_skip, optional<size_t> overlap_bytes)
                        PSIMD_FLATTEN -> optional<const void*> {
    if (const optional<const void*> x =
            Traits::ptr_of_first(s, val, ch, /*count=*/{}, bytes_to_skip)) {
      // No need to bounds-check, due to `count`'s size.
      return optional<const void*>{*x};
    }
    count -= d.MaxBytes() - overlap_bytes.unwrap_or(0);
    return {};
  };

  GenericAlignResult<VectorTag, optional<const void*>> first_align_result;
  if constexpr (Traits::kIsMaxLengthGuaranteed) {
    first_align_result = Traits::align_ptr_to_vec_known_safe(s, align_func);
  } else {
    first_align_result = Traits::align_ptr_to_vec(s, align_func);
  }
  auto [ptr, maybe_result] = first_align_result;
  if (maybe_result) {
    return *maybe_result;
  }

  // The simplest implementation from here would be:
  //
  // while (true) {
  //   // check for byte, return if found
  //   ++ptr;
  // }
  //
  // `perf` says that x86_64 CPUs stall on 'check for byte, return if found'
  // branches really badly, so it's a better balance if we can work in batches.
  // Work in batches until heuristics say that running down an unrolled
  // loop is likely to be better.
  size_t full_vector_loads_remaining = count / d.MaxBytes();
  constexpr size_t unrolled_loop_size = 4;

  const auto check_ptr_and_advance = [&]() PSIMD_FLATTEN -> optional<const void*> {
    if (const optional<const void*> x = Traits::ptr_of_first(ptr, Load(d, ptr), ch)) {
      return optional{*x};
    }
    ptr = Traits::advance_ptr(ptr);
    return {};
  };

  if (full_vector_loads_remaining >= unrolled_loop_size) {
    const auto needle = Set(d, ch);
    // NOTE: "3 checks per loop," was chosen based on experimentation on Brya,
    // which ships with chips like the 2024 Intel Core 3 100U. 2 loads was as
    // much as 1.1x slower on very long inputs. There was no obvious
    // improvement in doing 4 per loop.
    //
    // That said, just arbitrarily do 2 checks per loop is the size isn't a
    // guaranteed upper-bound. It needs to be _some_ power of two, since this
    // loop can't safely cross a page boundary.
    constexpr size_t checks_per_loop = Traits::kIsMaxLengthGuaranteed ? 3 : 2;

    if constexpr (!Traits::kIsMaxLengthGuaranteed) {
      // If we can't trust the total size, the following loops needs to avoid
      // loading across page boundaries.
      constexpr size_t misaligned_mask = vector_align(d) * 2 - 1;
      if (reinterpret_cast<uintptr_t>(ptr) & misaligned_mask) {
        if (const optional<const void*> x = check_ptr_and_advance()) {
          return *x;
        }
        full_vector_loads_remaining -= 1;
      }
      // (Guard against refactors subtly messing this up).
      PSIMD_DCHECK(full_vector_loads_remaining >= checks_per_loop);
    }

    do {
      // So highway may represent masks as _either_:
      // - a vector which you can convert to a scalar through MaskFromVec(), or
      // - a scalar.
      //
      // It does not allow `operator|` on masks.
      //
      // This implementation was written assuming:
      // - they're vectors (thus converting mask -> vector is free), and
      // - this loop's hot path involves looping (so operations on that path
      //   should be minimized).
      //
      // When that no longer holds, it should be trivial to refactor a bit.
      static_assert(sizeof(hn::MFromD<VectorTag>) == sizeof(hn::VFromD<VectorTag>));
      hn::MFromD<VectorTag> equal_results[checks_per_loop];
#pragma unroll
      for (size_t i = 0; i < checks_per_loop; ++i) {
        const auto v = Load(d, Traits::advance_ptr(ptr, i));
        equal_results[i] = v == needle;
      }

      const auto mask_or = [](const auto a, const auto b) PSIMD_FLATTEN {
        return MaskFromVec(VecFromMask(a) | VecFromMask(b));
      };

      auto merged_eq = mask_or(equal_results[0], equal_results[1]);
#pragma unroll
      for (size_t i = 2; i < checks_per_loop; ++i) {
        merged_eq = mask_or(merged_eq, equal_results[i]);
      }

      const size_t eq_bits = BitsFromMask(d, merged_eq);
      // `[[likely]]` keeps this loop tight.
      if (!eq_bits) [[likely]] {
        full_vector_loads_remaining -= checks_per_loop;
        ptr = Traits::advance_ptr(ptr, checks_per_loop);
        continue;
      }

#pragma unroll
      for (size_t i = 0; i < checks_per_loop - 1; ++i) {
        if (const size_t m = BitsFromMask(d, equal_results[i])) {
          return ptr + Traits::byte_offset_of_first(m);
        }
        ptr = Traits::advance_ptr(ptr, 1);
      }

      // If earlier masks were empty, `eq_bits` only contains bits relevant to
      // the last vector.
      return ptr + Traits::byte_offset_of_first(eq_bits);
    } while (full_vector_loads_remaining >= unrolled_loop_size);
  }

  switch (full_vector_loads_remaining) {
    case 3:
      if (const optional<const void*> x = check_ptr_and_advance()) {
        return *x;
      }
      [[fallthrough]];
    case 2:
      if (const optional<const void*> x = check_ptr_and_advance()) {
        return *x;
      }
      [[fallthrough]];
    case 1:
      if (const optional<const void*> x = check_ptr_and_advance()) {
        return *x;
      }
      [[fallthrough]];
    case 0:
      if (const size_t residual_count = count % d.MaxBytes()) {
        return result_from_final_vec(ptr, Load(d, ptr), residual_count);
      }
      return nullptr;
    default:
      __builtin_unreachable();
  }
}
}  // namespace
}  // namespace portable_simd

PSIMD_LIBC_FUNCTION(void*, memchr, const void* ptr, int ch, size_t count) {
  return const_cast<void*>(portable_simd::memchr_vectorized<portable_simd::MemchrTraits>(
      reinterpret_cast<const portable_simd::CharType*>(ptr), ch, count));
}

PSIMD_LIBC_FUNCTION(void*, memrchr, const void* ptr, int ch, size_t count) {
  return const_cast<void*>(portable_simd::memchr_vectorized<portable_simd::MemrchrTraits>(
      reinterpret_cast<const portable_simd::CharType*>(ptr), ch, count));
}

PSIMD_LIBC_FUNCTION(size_t, strnlen, const char* ptr, size_t count) {
  const char* s =
      static_cast<const char*>(portable_simd::memchr_vectorized<portable_simd::StrnlenTraits>(
          reinterpret_cast<const portable_simd::CharType*>(ptr), '\0', count));
  if (!s) {
    return count;
  }
  return static_cast<size_t>(s - ptr);
}
