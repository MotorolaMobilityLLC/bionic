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

#include <stddef.h>

extern "C" {

// arm64
size_t portable_simd_wcslen_neon(const wchar_t*);
size_t portable_simd_wcslen_neon_mte(const wchar_t*);
wchar_t* portable_simd_wmemchr_neon(const wchar_t*, wchar_t, size_t);
wchar_t* portable_simd_wmemchr_neon_mte(const wchar_t*, wchar_t, size_t);

// x86_64
void* portable_simd_memchr_sse(const void*, int, size_t);
void* portable_simd_memchr_avx2(const void*, int, size_t);
void* portable_simd_memrchr_sse(const void*, int, size_t);
void* portable_simd_memrchr_avx2(const void*, int, size_t);
size_t portable_simd_strcspn_sse(const char*, const char*);
size_t portable_simd_strlen_avx2(const char*);
size_t portable_simd_strlen_sse(const char*);
size_t portable_simd_strnlen_avx2(const char*, size_t);
size_t portable_simd_strnlen_sse(const char*, size_t);
size_t portable_simd_strspn_sse(const char*, const char*);
size_t portable_simd_wcslen_avx2(const wchar_t*);
size_t portable_simd_wcslen_sse(const wchar_t*);
wchar_t* portable_simd_wmemchr_sse(const wchar_t*, wchar_t, size_t);
wchar_t* portable_simd_wmemchr_avx2(const wchar_t*, wchar_t, size_t);
}
