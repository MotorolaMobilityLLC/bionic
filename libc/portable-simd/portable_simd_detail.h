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

#pragma once

// TODO(b/452714218): This codebase is pretty early stages. Particularly
// awkward bits include:
// - it's not actually portable outside of AVX2/SSE yet,
// - that it rolls its own implementation simd intrinsic dispatch.
//
// It would be great if we could instead use something like
// https://github.com/google/highway instead. This has a few blockers/concerns
// noted on ag/36313505/comment/f3b5d44a_9c309a7d/, but overall is _probably_
// the right way forward?
//
// That migration isn't expected to meaningfully change the control flow or
// structure of this code though, so hand-rolling is OK for now.
#include <emmintrin.h>
#include <immintrin.h>
#include <smmintrin.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <async_safe/CHECK.h>

// Set to 1 to enable PSIMD_DCHECKs. Only intended for debugging portable-simd
// routines.
#define PSIMD_DEBUG 0
#define PSIMD_DCHECK(x) CHECK(!(PSIMD_DEBUG) || (x))

// NOTE: `PSIMD_FLATTEN` **ideally** only belongs on `PSIMD_LIBC_FUNCTION`s.
// Clang has a longstanding bug in its `flatten` implementation
// (https://groups.google.com/g/llvm-dev/c/gGRCEi9g4ac/m/sEKFTnTGAwAJ)
// where flattening doesn't happen transitively, so we (unfortunately) need to
// `FLATTEN` more than just `PSIMD_LIBC_FUNCTION`s.
//
// Once Clang is fixed, PSIMD_FLATTEN should be removed and the attribute
// should be put on `PSIMD_LIBC_FUNCTION`.
#define PSIMD_FLATTEN __attribute__((__flatten__))

// Attributes to place on functions that we 'export', AKA are designed to be
// provided by ifuncs.
//
// The goal is to optimize these maximally, so mark every function hot and
// force as much as inlining as possible.
#define PSIMD_LIBC_FUNCTION PSIMD_FLATTEN __attribute__((__hot__))

// Users are expected to `#define` the level of vectorization they want to emit
// a declaration for (e.g., AVX2, SSE).
//
// This isn't autodetected based on features, since `-march` may give us more
// features than we need (e.g., the SSE TU might be built with
// `-march=skylake`, which would support AVX2).
#if PSIMD_TARGET_AVX2
#define PSIMD_INCLUDE_AVX2
#elif !defined(PSIMD_TARGET_SSE) || !PSIMD_TARGET_SSE
#error "unknown PSIMD_TARGET - want SSE or AVX2"
#endif

namespace portable_simd {

namespace {
// Pages are expected to be at minimum 4096 bytes. If a is _guaranteed_ to only
// use e.g., 16KB+ pages, we can see a small benefit by bumping this to 16KB
// for that.
constexpr static size_t kPageSize = 4 * 1024;
constexpr static size_t kMaxSizeT = size_t(-1);

// std::is_trivial_v
template <typename T>
constexpr static bool is_trivial_v = __is_trivial(T);

// Simple optional built to hold a trivial type. This is the minimal interface
// necessary to work around lack of libc++. It also assumes everything is
// eventually inlined, so e.g., useless copies/constructions are optimized out.
template <typename T>
struct optional {
  static_assert(is_trivial_v<T>, "This `optional` only supports trivial values; see description");

  using value_type = T;

  optional() : inhabited_(false) {}
  explicit optional(T x) : elem_(x), inhabited_(true) {}

  optional(const optional&) = default;
  optional(optional&&) = default;

  const T& operator*() const {
    PSIMD_DCHECK(has_value());
    return elem_;
  }
  T& operator*() {
    PSIMD_DCHECK(has_value());
    return elem_;
  }

  bool has_value() const { return inhabited_; }
  explicit operator bool() const { return has_value(); }

 private:
  T elem_;
  bool inhabited_;
};

// std::declval implementation
template <typename T>
T declval();

// std::invoke_result_t implementation
template <typename T, typename... Ts>
using invoke_result_t = decltype(declval<T>()(declval<Ts>()...));
}  // namespace

template <typename T>
struct VectorTraitsBase {
  constexpr static size_t kVectorAlign = alignof(typename T::VectorType);
  constexpr static size_t kVectorSize = sizeof(typename T::VectorType);
};

// Traits conforming with "extensions available with x86-64-v2."
struct VectorTraitsSSE : VectorTraitsBase<VectorTraitsSSE> {
  using VectorType = __m128i;

  static VectorType load_unaligned(const void* ptr) {
    return _mm_loadu_si128(static_cast<const VectorType*>(ptr));
  }

  static VectorType broadcast_byte(uint8_t x) { return _mm_set1_epi8(x); }

  static size_t compare_eq_bytewise_mask(VectorType a, VectorType b) {
    VectorType r = _mm_cmpeq_epi8(a, b);
    return _mm_movemask_epi8(r);
  }

  static VectorType minimum_bytewise_unsigned(VectorType a, VectorType b) {
    return _mm_min_epu8(a, b);
  }
};

#ifdef PSIMD_INCLUDE_AVX2
// Traits conforming with "extensions available with x86-64-v3."
struct VectorTraitsAVX2 : VectorTraitsBase<VectorTraitsAVX2> {
  using VectorType = __m256i;

  static VectorType load_unaligned(const void* ptr) {
    return _mm256_loadu_si256(static_cast<const VectorType*>(ptr));
  }

  static VectorType broadcast_byte(uint8_t x) { return _mm256_set1_epi8(x); }

  static size_t compare_eq_bytewise_mask(VectorType a, VectorType b) {
    VectorType r = _mm256_cmpeq_epi8(a, b);
    return _mm256_movemask_epi8(r);
  }

  static VectorType minimum_bytewise_unsigned(VectorType a, VectorType b) {
    return _mm256_min_epu8(a, b);
  }
};
#endif  // PSIMD_INCLUDE_AVX2

template <typename VectorTraits>
PSIMD_FLATTEN bool can_safely_unaligned_read(const void* ptr) {
  constexpr size_t max_offset_for_safe_read = kPageSize - VectorTraits::kVectorSize;
  const uintptr_t offset_in_page = reinterpret_cast<uintptr_t>(ptr) & (kPageSize - 1);
  return max_offset_for_safe_read >= offset_in_page;
}

template <typename T>
struct BackAlignedPtr {
  // Ptr, guaranteed to be aligned.
  T* ptr;
  // Member indicating how many bytes of 'garbage' were to exist at the front
  // of the vector if you loaded `ptr`.
  size_t skip_bytes;
};

template <typename VectorTraits>
PSIMD_FLATTEN BackAlignedPtr<const typename VectorTraits::VectorType> align_backwards(
    const char* x) {
  using VecT = typename VectorTraits::VectorType;
  const size_t remove_mask = VectorTraits::kVectorAlign - 1;
  const uintptr_t ptr = reinterpret_cast<uintptr_t>(x);
  const uintptr_t aligned_ptr = ptr & ~remove_mask;
  const size_t bytes_to_skip = ptr - aligned_ptr;
  return {
      /*ptr=*/reinterpret_cast<const VecT*>(aligned_ptr),
      /*skip_bytes=*/bytes_to_skip,
  };
}

// The result of calling align_forward_to_vec. See the docs there.
// Either `ptr` is non-null, or `result` has a value.
template <typename VectorTraits, typename Opt, typename T = typename Opt::value_type>
struct GenericAlignForwardResult {
  const typename VectorTraits::VectorType* ptr;
  optional<T> result;
};

// This function uses VectorTraits to determine 'align forward' `s`. That is:
// - It reads one vector worth of data,
// - It calls `fn` on that (with extra info, see signature below)
// - If `fn` returns a non-empty value, this returns with {nullptr, that_value}
// - Otherwise, this function returns with {ptr_aligned_to_vector_traits,
//   nullopt}.
//
// Fn's signature should be:
//
// optional<T> f(VectorType val, size_t shift_bytes)
//
// - `val` is the loaded vector.
// - `shift_bytes` indicates how many bytes _backwards_ we ended up loading.
//   One path hardcodes a 0 here, so checking for 0 (if necessary) will be
//   optimized away in the fast path.
template <typename VectorTraits, typename Fn,
          typename T = invoke_result_t<Fn, typename VectorTraits::VectorType, size_t>>
PSIMD_FLATTEN inline GenericAlignForwardResult<VectorTraits, T> align_forward_to_vec(const char* s,
                                                                                     Fn f) {
  using VecT = typename VectorTraits::VectorType;

  const VecT* ptr;
  if (can_safely_unaligned_read<VectorTraits>(s)) [[likely]] {
    const auto loaded = VectorTraits::load_unaligned(s);
    if (const T x = f(loaded, /*shift_bytes=*/size_t(0))) {
      return {nullptr, x};
    }

    auto aligned_ptr = reinterpret_cast<uintptr_t>(s);
    aligned_ptr &= ~static_cast<uintptr_t>(VectorTraits::kVectorSize - 1);
    ptr = reinterpret_cast<const VecT*>(aligned_ptr);
  } else {
    const auto [back_ptr, skip_bytes] = align_backwards<VectorTraits>(s);
    ptr = back_ptr;
    if (const T x = f(*ptr, skip_bytes)) {
      return {nullptr, x};
    }
  }
  ++ptr;
  return {ptr, {}};
}
}  // namespace portable_simd
