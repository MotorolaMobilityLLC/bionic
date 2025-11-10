/*
 * Copyright (C) 2022 The Android Open Source Project
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

#include <stddef.h>

#include <private/bionic_ifuncs.h>

static bool cpu_supports_x86_64_v3() {
  const static bool result = ([] {
#ifdef __AVX2__
    // All known CPUs with AVX2 support x86-64-v3. If that's available at
    // build-time, the CPU we're building for must support it.
    //
    // This saves a few cycles in ifuncs, and potentially lets the linker's
    // `--gc-sections` remove x86_64_v2 functions when they'll never be used.
    return true;
#else
    __builtin_cpu_init();
    return __builtin_cpu_supports("avx2");
#endif
  })();
  return result;
}

extern "C" {

DEFINE_IFUNC_FOR(memchr) {
  if (cpu_supports_x86_64_v3()) RETURN_FUNC(memchr_func_t, portable_simd_memchr_avx2);
  RETURN_FUNC(memchr_func_t, portable_simd_memchr_sse);
}
MEMCHR_SHIM()

// While we do want to keep alphabetical order, memcpy calls this, so place it
// above that.
DEFINE_IFUNC_FOR(memmove) {
  if (cpu_supports_x86_64_v3()) RETURN_FUNC(memmove_func_t, memmove_avx2);
  RETURN_FUNC(memmove_func_t, memmove_generic);
}
MEMMOVE_SHIM()

DEFINE_IFUNC_FOR(memcpy) {
  return memmove_resolver();
}
MEMCPY_SHIM()

DEFINE_IFUNC_FOR(__memcpy_chk) {
  if (cpu_supports_x86_64_v3()) RETURN_FUNC(__memcpy_chk_func_t, __memcpy_chk_avx2);
  RETURN_FUNC(__memcpy_chk_func_t, __memcpy_chk_generic);
}
__MEMCPY_CHK_SHIM()

DEFINE_IFUNC_FOR(memrchr) {
  if (cpu_supports_x86_64_v3()) RETURN_FUNC(memrchr_func_t, portable_simd_memrchr_avx2);
  RETURN_FUNC(memrchr_func_t, portable_simd_memrchr_sse);
}
MEMRCHR_SHIM()

DEFINE_IFUNC_FOR(memset) {
  if (cpu_supports_x86_64_v3()) RETURN_FUNC(memset_func_t, memset_avx2);
  RETURN_FUNC(memset_func_t, memset_generic);
}
MEMSET_SHIM()

DEFINE_IFUNC_FOR(__memset_chk) {
  if (cpu_supports_x86_64_v3()) RETURN_FUNC(__memset_chk_func_t, __memset_chk_avx2);
  RETURN_FUNC(__memset_chk_func_t, __memset_chk_generic);
}
__MEMSET_CHK_SHIM()

DEFINE_IFUNC_FOR(strlen) {
  if (cpu_supports_x86_64_v3()) RETURN_FUNC(strlen_func_t, portable_simd_strlen_avx2);
  RETURN_FUNC(strlen_func_t, portable_simd_strlen_sse);
}
STRLEN_SHIM()

}  // extern "C"
