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

struct StrlenTraits {
  // Highway doesn't support direct `char` usage in vector types, presumably
  // because it can vary in signed-ness. `strlen` uses `min` to find `\0`, so
  // unsigned is simplest.
  //
  // It's notable that the highway quick_reference advises against unsigned
  // `min` operations for older CPUs:
  // https://google.github.io/highway/en/master/quick_reference.html#speeding-up-code-for-older-x86-platforms
  //
  // But it's unclear why; instruction timing tables indicate that unsigned and
  // signed bytewise `min` have identical timings.
  using CharType = uint8_t;
  using VectorTag = portable_simd::FullVector<CharType>;
  using VectorType = hn::VFromD<VectorTag>;
};

struct WcslenTraits {
  using CharType = uint32_t;
  using VectorTag = portable_simd::FullVector<CharType>;
  using VectorType = hn::VFromD<VectorTag>;
};

template <typename Traits>
PSIMD_FLATTEN static optional<size_t> index_of_nul(typename Traits::VectorType val,
                                                   size_t chars_to_skip = 0) {
  constexpr typename Traits::VectorTag d;
  const auto all_zeroes = Zero(d);
  // NOTE: The mask that highway generates here is lane-wise.
  const size_t raw_zero_mask = BitsFromMask(d, all_zeroes == val);
  const size_t zero_mask = raw_zero_mask >> chars_to_skip;
  if (!zero_mask) {
    return {};
  }

  const size_t lane_index = stdc_trailing_zeros(zero_mask);
  return optional{lane_index};
}

template <typename Traits>
PSIMD_FLATTEN static optional<const typename Traits::CharType*> ptr_of_nul(
    const void* ptr, typename Traits::VectorType val) {
  if (const optional<size_t> x = index_of_nul<Traits>(val)) {
    return optional{*x + static_cast<const Traits::CharType*>(ptr)};
  }
  return {};
}

template <typename Traits>
PSIMD_FLATTEN static size_t strlen_vectorized(const typename Traits::CharType* s) {
  using CharType = Traits::CharType;
  using VectorTag = Traits::VectorTag;

  constexpr VectorTag d;

  auto [ptr, nul_distance] = align_forward_to_vec<VectorTag>(
      s, [&](auto val, optional<size_t> bytes_to_skip, optional<size_t>) -> optional<size_t> {
        size_t chars_to_skip = 0;
        if (bytes_to_skip) {
          // All wide-char pointers should be suitably aligned.
          PSIMD_DCHECK(*bytes_to_skip % sizeof(CharType) == 0);
          chars_to_skip = *bytes_to_skip / sizeof(CharType);
        }
        if (const optional<size_t> x = index_of_nul<Traits>(val, chars_to_skip)) {
          return optional{*x};
        }
        return {};
      });
  if (nul_distance) {
    return *nul_distance;
  }

  // The simplest implementation from here would be:
  //
  // while (true) {
  //   // check for nul, return if found
  //   ++ptr;
  // }
  //
  // `perf` says that x86_64 CPUs stall on the 'check for nul, return if found'
  // branch really badly, so it's a better balance if we can work in batches.
  // Since batch size must be a power of two, work in batches of 4.
  const auto check_ptr_and_inc = [&]() -> optional<size_t> {
    if (const optional<const CharType*> x = ptr_of_nul<Traits>(ptr, Load(d, ptr))) {
      return optional{static_cast<size_t>(*x - s)};
    }
    ptr += d.MaxLanes();
    return {};
  };

  // Of course, we can only work in batches if it's safe to read more than one
  // vector at a time.
  if (!kReadAheadToPageBoundaryIsOK) {
    while (true) {
      if (const optional<size_t> x = check_ptr_and_inc()) {
        return *x;
      }
    }
  }

  // Here, we have a trade-off to make: "how many very simple checks do we want
  // to do before hitting the loop that's really fast for long strings?"
  //
  // Between here and the "big string" loop, there are between 0 and 3
  // `check_ptr_and_inc`s to bring us up to alignment.
  //
  // We've checked between 1 and kVectorSize bytes so far, and it seems bad to
  // dive into the 'big' case having checked as little as 1 byte, so add a
  // few checks beforehand.
  constexpr size_t kMinBytesUntilStringIsBig = 128;
  // Worst case, we've only read 1 byte so far. Add 1 check to round up.
  constexpr size_t kExtraChecksNeeded = 1 + (kMinBytesUntilStringIsBig - 1) / d.MaxBytes();

#pragma unroll
  for (size_t i = 0; i < kExtraChecksNeeded; ++i) {
    if (const optional<size_t> x = check_ptr_and_inc()) {
      return *x;
    }
  }

  // Now bring ourselves to 4*kVectorAlign alignment.
  constexpr size_t kFourVecAlign = 4 * vector_align(d);
  static_assert(kPageSize % kFourVecAlign == 0);
  const size_t vector_width_from_prev_align =
      (reinterpret_cast<uintptr_t>(ptr) & (kFourVecAlign - 1)) / vector_align(d);
  switch (vector_width_from_prev_align) {
    case 1:
      if (const optional<size_t> x = check_ptr_and_inc()) {
        return *x;
      }
      [[fallthrough]];
    case 2:
      if (const optional<size_t> x = check_ptr_and_inc()) {
        return *x;
      }
      [[fallthrough]];
    case 3:
      if (const optional<size_t> x = check_ptr_and_inc()) {
        return *x;
      }
      break;
    default:
      PSIMD_DCHECK(vector_width_from_prev_align == 0);
  }

  while (true) {
    const auto vec1 = Load(d, ptr);
    const auto vec2 = Load(d, ptr + d.MaxLanes());
    const auto min12 = Min(vec1, vec2);
    const auto vec3 = Load(d, ptr + d.MaxLanes() * 2);
    const auto vec4 = Load(d, ptr + d.MaxLanes() * 3);
    const auto min34 = Min(vec3, vec4);
    const auto min_all = Min(min12, min34);

    const optional<size_t> maybe_index = index_of_nul<Traits>(min_all);
    if (!maybe_index) [[likely]] {
      ptr += 4 * d.MaxLanes();
      continue;
    }

    const size_t index_of_first_zero = *maybe_index;
    // We're in the 'longer string' case, so there's no reason to assume `vec1`
    // is most likely to have the `\0`. Assuming all cases are equally likely,
    // prefer a constant 2 `ptr_of_nul` cost, rather than 1-3.
    if (const optional<const CharType*> x = ptr_of_nul<Traits>(ptr, min12)) {
      if (const optional<const CharType*> x2 = ptr_of_nul<Traits>(ptr, vec1)) {
        return static_cast<size_t>(*x2 - s);
      }
      // If vec1 had no zeroes, then we can assume the min 0 is from vec2.
      return static_cast<size_t>(*x - s) + d.MaxLanes();
    }

    ptr += d.MaxLanes() * 2;
    if (const optional<const CharType*> x = ptr_of_nul<Traits>(ptr, vec3)) {
      return static_cast<size_t>(*x - s);
    }

    // Since nothing else has nul in it, it's guaranteed that the nul is
    // vec4's, so we can use the above `index_of_nul` result.
    ptr += d.MaxLanes();
    return static_cast<size_t>(reinterpret_cast<const CharType*>(ptr) - s) + index_of_first_zero;
  }
}
}  // namespace
}  // namespace portable_simd

PSIMD_LIBC_FUNCTION(size_t, strlen, const char* s) {
  using portable_simd::StrlenTraits;
  return portable_simd::strlen_vectorized<StrlenTraits>(
      reinterpret_cast<const StrlenTraits::CharType*>(s));
}

static size_t simplistic_misaligned_wcslen(const wchar_t* s) {
  size_t len = 0;
  while (*s) {
    ++s;
    ++len;
  }
  return len;
}

PSIMD_LIBC_FUNCTION(size_t, wcslen, const wchar_t* s) {
  using portable_simd::WcslenTraits;

  // We might have received a misaligned pointer. Support that with a slow case
  // if needed. It's expected that the 99% case will be properly-aligned, so no
  // meaningful effort is put into making the misaligned case fast.
  if (reinterpret_cast<uintptr_t>(s) % alignof(wchar_t)) [[unlikely]] {
    return simplistic_misaligned_wcslen(s);
  }

  return portable_simd::strlen_vectorized<WcslenTraits>(
      reinterpret_cast<const WcslenTraits::CharType*>(s));
}

#if defined(__x86_64__)
PSIMD_MAYBE_STRONG_ALIAS(strlen);
PSIMD_MAYBE_STRONG_ALIAS(wcslen);
#elif defined(__aarch64__)
PSIMD_MAYBE_STRONG_ALIAS(wcslen);
#endif
