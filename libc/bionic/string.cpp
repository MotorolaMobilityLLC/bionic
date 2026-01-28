/*
 * Copyright (C) 2017 The Android Open Source Project
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

// FORTIFY only provides value when the size of the buffer can be
// statically determined, and that's never the case with any calls
// here. b/454067908 shows that leaving it enabled leads to
// suboptimal codegen.
#undef _FORTIFY_SOURCE

#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <xlocale.h>

//
// Core functionality.
//

#if !defined(__x86_64__)
void* memccpy(void* dst, const void* src, int c, size_t n) {
  const char* p = static_cast<const char*>(memchr(src, c, n));
  if (p != nullptr) {
    n = p - static_cast<const char*>(src) + 1;
    memcpy(dst, src, n);
    return static_cast<char*>(dst) + n;
  }
  memcpy(dst, src, n);
  return nullptr;
}
#endif

void* mempcpy(void* dst, const void* src, size_t n) {
  return reinterpret_cast<char*>(memcpy(dst, src, n)) + n;
}

// https://github.com/ARM-software/optimized-routines/issues/89
#if defined(__aarch64__)
char* strcat(char* dst, const char* src) {
  strcpy(dst + strlen(dst), src);
  return dst;
}
#endif

#if defined(__arm__) || defined(__aarch64__)
__attribute__((__flatten__))
char* stpncpy(char* dst, const char* src, size_t dst_n) {
  size_t src_n = strnlen(src, dst_n);
  memcpy(dst, src, src_n);
  memset(dst + src_n, 0, dst_n - src_n);
  return dst + src_n;
}
#endif

#if defined(__arm__) || defined(__aarch64__) || defined(__riscv)
__attribute__((__flatten__))
char* strncpy(char* dst, const char* src, size_t n) {
  stpncpy(dst, src, n);
  return dst;
}
#endif

#if defined(__arm__) || defined(__aarch64__)
__attribute__((__flatten__))
char* strncat(char* dst, const char* src, size_t n) {
  char* result = dst;
  dst += strlen(dst);
  // strncat() writes just one NUL, unlike strncpy().
  char* end = static_cast<char*>(mempcpy(dst, src, strnlen(src, n)));
  *end = '\0';
  return result;
}
#endif

__attribute__((__flatten__))
size_t strlcat(char* dst, const char* src, size_t n) {
  size_t dst_len = strnlen(dst, n);
  if (dst_len == n) return dst_len + strlen(src);
  return dst_len + strlcpy(dst + dst_len, src, n - dst_len);
}

__attribute__((__flatten__))
size_t strlcpy(char* dst, const char* src, size_t n) {
  size_t src_len = strlen(src);
  if (src_len < n) {
    memcpy(dst, src, src_len + 1);
  } else if (n != 0) {
    memcpy(dst, src, n - 1);
    dst[n - 1] = '\0';
  }
  return src_len;
}

//
// String delimiter functions.
//

// The approach here is to optimize strcspn()/strspn() and write everything
// else in terms of those two.

// arm64 and x86_64 have a psimd strspn.
#if defined(__arm__) || defined(__i386__) || defined(__riscv)
#define NEED_GENERIC_STRSPN 1
#else
#define NEED_GENERIC_STRSPN 0
#endif

#if NEED_GENERIC_STRSPN
// Benchmarking shows that bool[] works better than a bitset,
// and 256 bytes of stack (the latter half of which is never used in practice)
// doesn't seem unreasonable.
static_assert(sizeof(bool) == 1);
static inline void init_delimiter_set(bool* set, const char* delims) {
  for (const uint8_t* d = reinterpret_cast<const uint8_t*>(delims); *d; ++d) {
    set[*d] = true;
  }
}
#endif

#if NEED_GENERIC_STRSPN
__attribute__((__flatten__))
size_t strspn(const char* ss, const char* delims) {
  const uint8_t* s = reinterpret_cast<const uint8_t*>(ss);
  const uint8_t* p = s;
  if (delims[0] == '\0') return 0;
  if (delims[1] == '\0') {
    // The common case is a single delimiter, where the set is worse.
    while (*p == delims[0]) ++p;
  } else {
    bool set[256] = {};
    init_delimiter_set(set, delims);
    while (set[*p]) ++p;
  }
  return p - s;
}
#endif

#if NEED_GENERIC_STRSPN
__attribute__((__flatten__))
size_t strcspn(const char* ss, const char* delims) {
  const uint8_t* s = reinterpret_cast<const uint8_t*>(ss);
  const uint8_t* p = s;
  if (delims[0] == '\0' || delims[1] == '\0') {
    // The common case is a single delimiter, where the set is far worse.
    // On arm64 strchrnul() is faster than open coding even for small distances,
    // and orders of magnitude better for large distances.
    return strchrnul(ss, delims[0]) - ss;
  } else {
    bool set[256] = {};
    init_delimiter_set(set, delims);
    while (*p && !set[*p]) ++p;
  }
  return p - s;
}
#endif

__attribute__((__flatten__))
char* strpbrk(const char* s, const char* delims) {
  size_t i = strcspn(s, delims);
  if (s[i] != '\0') return const_cast<char*>(s) + i;
  return nullptr;
}

__attribute__((__flatten__))
char* strsep(char** last, const char* delims) {
  // Already finished?
  char* start = *last;
  if (start == nullptr) return nullptr;

  // Find end of token (first delimiter).
  char* end = start + strcspn(start, delims);
  if (*end != '\0') {
    // Replace delimiter with NUL, point past it.
    *end = '\0';
    *last = end + 1;
  } else {
    // Token ends at end of string.
    // Signal that to next invocation.
    *last = nullptr;
  }

  // Return pointer to start of token.
  return start;
}

__attribute__((__flatten__))
char* strtok_r(char* s, const char* delims, char** last) {
  // Already finished?
  if (s == nullptr && (s = *last) == nullptr) {
    return nullptr;
  }

  // Skip leading delimiters with optimized strspn().
  s += strspn(s, delims);

  // Finished now (no non-delimiters)?
  if (*s == '\0') {
    *last = nullptr;
    return nullptr;
  }

  // Find next delimiter with optimized strcspn().
  *last = s + strcspn(s, delims);
  if (**last != '\0') {
    // Replace delimiter with NUL, point past it.
    **last = '\0';
    *last += 1;
  } else {
    // Token ends at end of string.
    // Signal that to next invocation.
    *last = nullptr;
  }

  // Return pointer to start of token.
  return s;
}

__attribute__((__flatten__))
char* strtok(char* s, const char* delims) {
  static char* last;
  return strtok_r(s, delims, &last);
}

//
// No-op i18n stuff.
//

int strcoll(const char* lhs, const char* rhs) {
  return strcmp(lhs, rhs);
}
__strong_alias(strcoll_l, strcoll);

size_t strxfrm(char* dst, const char* src, size_t n) {
  return strlcpy(dst, src, n);
}
__strong_alias(strxfrm_l, strxfrm);

//
// String duplication functions.
//

char* strdup(const char* s) {
  size_t n = strlen(s) + 1;
  char* result = static_cast<char*>(malloc(n));
  if (result != nullptr) {
    memcpy(result, s, n);
  }
  return result;
}

char* strndup(const char* s, size_t n) {
  n = strnlen(s, n);
  char* result = static_cast<char*>(malloc(n + 1));
  if (result != nullptr) {
    memcpy(result, s, n);
    result[n] = '\0';
  }
  return result;
}
