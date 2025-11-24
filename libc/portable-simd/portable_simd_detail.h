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

#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <async_safe/CHECK.h>

// TODO(b/452714218): 'Portable' really should mean more than 'AVX2 and SSE'.

// Users are expected to `#define` the level of vectorization they want to emit
// a declaration for (e.g., AVX2, SSE).
//
// This isn't autodetected based on features, since `-march` may give us more
// features than we need (e.g., the SSE TU might be built with
// `-march=skylake`, which would support AVX2).
#if PSIMD_TARGET_AVX2
#define PSIMD_EXPORT_SUFFIX _avx2
// hwy assumes PCLMUL and AES are available for AVX2 by default, but some CPUs
// (e.g., the i3-4000m) shipped with x86-64-v3 support but without AES.
#define HWY_DISABLE_PCLMUL_AES 1
#define HWY_BASELINE_TARGETS HWY_AVX2
#elif PSIMD_TARGET_SSE
#define PSIMD_EXPORT_SUFFIX _sse
// x86-64-v2 makes no guarantees of PCLMUL and AES, but hwy assumes them for
// SSE4.
#define HWY_DISABLE_PCLMUL_AES 1
#define HWY_BASELINE_TARGETS HWY_SSE4
#else
#error "unknown PSIMD_TARGET - want SSE or AVX2"
#endif

// Highway config.
// Highway supports dynamic dispatch, but we have our own ifuncs, so turn all of that off.
#define HWY_COMPILE_ONLY_STATIC 1
// CMake allows you to set this, but it does nothing at present. We're pulling
// highway in as a header-only library, so it seems more forward-compatible to
// make that fact available to highway.
#define HWY_HEADER_ONLY 1
// We have no libcxx for highway to use.
#define HWY_NO_LIBCXX 1

#include <hwy/highway.h>

// Convenience shortcut for "the highway namespace that's been selected through
// PSIMD_TARGET_*."
namespace hn = hwy::HWY_NAMESPACE;

// Set to 1 to enable PSIMD_DCHECKs. Only intended for debugging portable-simd
// routines.
#define PSIMD_DEBUG 0
#define PSIMD_DCHECK(x) CHECK(!(PSIMD_DEBUG) || (x))

// NOTE: `PSIMD_FLATTEN` **ideally** only belongs on `PSIMD_LIBC_FUNCTION`s.
// Clang has a longstanding bug in its `flatten` implementation
// (https://github.com/llvm/llvm-project/issues/60689)
// where flattening doesn't happen transitively, so we (unfortunately) need to
// `FLATTEN` more than just `PSIMD_LIBC_FUNCTION`s.
//
// Once Clang is fixed, PSIMD_FLATTEN should be removed and the attribute
// should be put on `PSIMD_LIBC_FUNCTION`.
#define PSIMD_FLATTEN __attribute__((__flatten__))

// Given e.g., `strlen`, gives back the portable_simd name for the current
// compilation, e.g., `portable_simd_strlen_avx2`.
#define PSIMD_CONCAT1(x, y) x##y
#define PSIMD_CONCAT(x, y) PSIMD_CONCAT1(x, y)
#define PSIMD_LIBC_FUNCTION_NAME(libc_name) \
  PSIMD_CONCAT(PSIMD_CONCAT(portable_simd_, libc_name), PSIMD_EXPORT_SUFFIX)

// If PSIMD_ADD_LIBC_ALIASES is defined, we'll emit strong aliases for each
// function to its corresponding libc function. For example, if this TU defines
// a portable-simd version of `strlen` for SSE, `-DPSIMD_ADD_LIBC_ALIASES` will
// emit a definition of `strlen` as well as `portable_simd_strlen_sse`.
#if defined(PSIMD_ADD_LIBC_ALIASES)
#define PSIMD_MAYBE_STRONG_ALIAS1(libc_name, impl_name) __strong_alias(libc_name, impl_name)
#define PSIMD_MAYBE_STRONG_ALIAS(libc_name) \
  PSIMD_MAYBE_STRONG_ALIAS1(libc_name, PSIMD_LIBC_FUNCTION_NAME(libc_name))
#else
#define PSIMD_MAYBE_STRONG_ALIAS(libc_name)
#endif

// Attributes to place on functions that we 'export', AKA are designed to be
// provided by ifuncs.
//
// The goal is to optimize these maximally, so mark every function hot and
// force as much as inlining as possible.
//
// Example usage is:
// PSIMD_LIBC_FUNCTION(size_t, strlen, const char *) { /* function body */ }
//
// This defines a function called e.g., `portable_simd_strlen_avx2` (where
// `avx2` depends on the SIMD instructions we're targeting). If
// `PSIMD_ADD_LIBC_ALIASES` is enabled, it also adds a strong alias for
// `strlen = portable_simd_strlen_avx2`.
#define PSIMD_LIBC_FUNCTION_IMPL(ret_ty, libc_name, full_name, ...) \
  PSIMD_FLATTEN __attribute__((__hot__)) ret_ty full_name(__VA_ARGS__)
#define PSIMD_LIBC_FUNCTION(ret_ty, libc_name, ...) \
  PSIMD_LIBC_FUNCTION_IMPL(ret_ty, libc_name, PSIMD_LIBC_FUNCTION_NAME(libc_name), __VA_ARGS__)

namespace portable_simd {

// The tag referring to the vector type that we're configured to target. E.g.,
// if PSIMD_TARGET_AVX2 is set, this will be a hwy vector tag that refers to a
// __m256 type.
template <typename T>
using FullVector = hn::FixedTag<T, hn::ScalableTag<T>{}.MaxLanes()>;

template <size_t VectorSize>
struct ScalarByteMask;

template <>
struct ScalarByteMask<128> {
  using type = uint16_t;
};

template <>
struct ScalarByteMask<256> {
  using type = uint32_t;
};

// Usable when you want the most compact type that a mask for a given VectorTag
// fits into.
template <typename T>
using ScalarMaskForD = ScalarByteMask<T{}.MaxBytes() * 8>::type;

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

  T unwrap_or(T val) const {
    if (has_value()) {
      return elem_;
    }
    return val;
  }

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

template <typename VectorTag>
PSIMD_FLATTEN bool can_safely_unaligned_read(const void* ptr) {
  constexpr VectorTag d;
  constexpr size_t max_offset_for_safe_read = kPageSize - d.MaxBytes();
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

template <typename VectorTag>
PSIMD_FLATTEN BackAlignedPtr<const hn::TFromD<VectorTag>> align_backwards(const void* x) {
  constexpr VectorTag d;
  const size_t remove_mask = d.MaxBytes() - 1;
  const uintptr_t ptr = reinterpret_cast<uintptr_t>(x);
  const uintptr_t aligned_ptr = ptr & ~remove_mask;
  const size_t bytes_to_skip = ptr - aligned_ptr;
  return {
      /*ptr=*/reinterpret_cast<const hn::TFromD<VectorTag>*>(aligned_ptr),
      /*skip_bytes=*/bytes_to_skip,
  };
}

// The result of calling align_forward_to_vec. See the docs there.
// Either `ptr` is non-null, or `result` has a value.
template <typename VectorTag, typename Opt, typename T = typename Opt::value_type>
struct GenericAlignResult {
  const hn::TFromD<VectorTag>* ptr;
  optional<T> result;
};

template <
    typename VectorTag, typename Fn,
    typename T = invoke_result_t<Fn, hn::VFromD<VectorTag>, optional<size_t>, optional<size_t>>>
PSIMD_FLATTEN inline GenericAlignResult<VectorTag, T> align_forward_to_vec_known_safe(const void* s,
                                                                                      Fn f) {
  using VectorElem = hn::TFromD<VectorTag>;
  constexpr VectorTag d;
  const auto loaded = LoadU(d, reinterpret_cast<const VectorElem*>(s));
  auto aligned_ptr = reinterpret_cast<uintptr_t>(s);
  const auto overlap_bytes = aligned_ptr & static_cast<uintptr_t>(d.MaxBytes() - 1);
  if (const T x = f(loaded, /*skip_bytes=*/optional<size_t>{}, optional<size_t>{overlap_bytes})) {
    return {nullptr, x};
  }

  aligned_ptr -= overlap_bytes;
  aligned_ptr += d.MaxBytes();
  const auto* ptr = reinterpret_cast<const VectorElem*>(aligned_ptr);
  PSIMD_DCHECK(hn::IsAligned(d, ptr));
  return {ptr, {}};
}

// This function uses VectorTraits to determine 'align forward' `s`. That is:
// - It reads one vector worth of data,
// - It calls `fn` on that (with extra info, see signature below)
// - If `fn` returns a non-empty value, this returns with {nullptr, that_value}
// - Otherwise, this function returns with {ptr_aligned_to_vector_traits,
//   nullopt}.
//
// Fn's signature should be:
//
// optional<T> f(VectorType val, size_t shift_bytes, size_t overlap_bytes)
//
// - `val` is the loaded vector.
// - `shift_bytes` indicates how many bytes _backwards_ we ended up loading.
//   An empty optional is passed if `s` was loaded unaltered. An optional is
//   passed rather than integer value, since this is expected to be inlined,
//   and the constant `true`/`false` on branches is easier to optimize well.
// - `overlap_bytes` is the number of bytes that will overlap between
//   dereferencing `ptr` and the value passed to `f`. That is, if you have a
//   16-byte vector size and passed `s == 0x5`, `f` would be called on a load
//   of `0x5` and `ptr` would be `0x10`. Loading `ptr` would produce 5 bytes
//   that were present in the load of `0x5`. This may be optional(0).
//
// Moreover, `f` can assume
// `shift_bytes.has_value() ^ overlap_bytes.has_value()`.
template <
    typename VectorTag, typename Fn,
    typename T = invoke_result_t<Fn, hn::VFromD<VectorTag>, optional<size_t>, optional<size_t>>>
PSIMD_FLATTEN inline GenericAlignResult<VectorTag, T> align_forward_to_vec(const void* s, Fn f) {
  constexpr VectorTag d;
  if (can_safely_unaligned_read<VectorTag>(s)) [[likely]] {
    return align_forward_to_vec_known_safe<VectorTag>(s, f);
  }
  auto [ptr, skip_bytes] = align_backwards<VectorTag>(s);
  if (const T x = f(Load(d, ptr), optional{skip_bytes}, /*overlap_bytes=*/optional<size_t>{})) {
    return {nullptr, x};
  }
  ptr += d.MaxLanes();
  PSIMD_DCHECK(hn::IsAligned(d, ptr));
  return {ptr, {}};
}

template <
    typename VectorTag, typename Fn,
    typename T = invoke_result_t<Fn, hn::VFromD<VectorTag>, optional<size_t>, optional<size_t>>>
PSIMD_FLATTEN inline GenericAlignResult<VectorTag, T> align_backward_to_vec_known_safe(
    const void* s, Fn f) {
  using VectorElem = hn::TFromD<VectorTag>;
  constexpr VectorTag d;

  const auto loaded = LoadU(d, static_cast<const VectorElem*>(s));
  auto aligned_ptr = reinterpret_cast<uintptr_t>(s);
  const size_t offset_from_aligned = aligned_ptr & static_cast<uintptr_t>(d.MaxLanes() - 1);
  const size_t amount_to_dec = offset_from_aligned ? offset_from_aligned : d.MaxBytes();
  const size_t overlap_bytes = d.MaxBytes() - amount_to_dec;
  if (const T x = f(loaded, /*skip_bytes=*/optional<size_t>{}, optional<size_t>{overlap_bytes})) {
    return {nullptr, x};
  }

  aligned_ptr -= amount_to_dec;
  const auto* ptr = reinterpret_cast<const VectorElem*>(aligned_ptr);
  PSIMD_DCHECK(hn::IsAligned(d, ptr));
  return {ptr, {}};
}

// This is `align_forward_to_vec`, but intended for reverse functions, like
// `memrchr`, so:
// - It takes a pointer that is known to be safe to load *from the end of* (moreover,
//   `*(s + VectorTag{}.MaxBytes() - 1)` must be safe)
// - If loading `s` into a vector is unsafe, this will load at an address
//   _greater than_ `s`, and `skip_bytes` will refer to bytes in the highest
//   lanes of `s`.
template <
    typename VectorTag, typename Fn,
    typename T = invoke_result_t<Fn, hn::VFromD<VectorTag>, optional<size_t>, optional<size_t>>>
PSIMD_FLATTEN inline GenericAlignResult<VectorTag, T> align_backward_to_vec(const void* s, Fn f) {
  constexpr VectorTag d;
  if (can_safely_unaligned_read<VectorTag>(s)) [[likely]] {
    return align_backward_to_vec_known_safe<VectorTag>(s, f);
  }

  // We can't read `s` directly, so we have to advance until we can.
  const size_t bytes_to_next_page = kPageSize - (reinterpret_cast<uintptr_t>(s) % kPageSize);
  s = static_cast<const char*>(s) + bytes_to_next_page;
  const hn::TFromD<VectorTag>* ptr = static_cast<const hn::TFromD<VectorTag>*>(s);
  size_t skip_bytes = bytes_to_next_page;
  if (const T x = f(Load(d, ptr), optional{skip_bytes}, /*overlap_bytes=*/optional<size_t>{})) {
    return {nullptr, x};
  }
  ptr -= d.MaxLanes();
  PSIMD_DCHECK(hn::IsAligned(d, ptr));
  return {ptr, {}};
}

// Helper to make it clearer what operations are referencing vector alignment.
template <typename VectorTag>
constexpr size_t vector_align(VectorTag d) {
  return d.MaxBytes();
}
}  // namespace portable_simd
