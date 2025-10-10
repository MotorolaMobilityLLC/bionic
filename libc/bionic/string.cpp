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

#include <string.h>
#include <xlocale.h>

//
// Core functionality.
//

// https://github.com/ARM-software/optimized-routines/issues/89
#if defined(__aarch64__)
char* strcat(char* dst, const char* src) {
  strcpy(dst + strlen(dst), src);
  return dst;
}
#endif

//
// String delimiter functions.
//

// The approach here is to optimize strcspn()/strspn() and write everything
// else in terms of those two.

// Benchmarking shows that bool[] works better than a bitset,
// and 256 bytes of stack (the latter half of which is never used in practice)
// doesn't seem unreasonable.
static_assert(sizeof(bool) == 1);
static inline void init_delimiter_set(bool* set, const char* delims) {
  for (const uint8_t* d = reinterpret_cast<const uint8_t*>(delims); *d; ++d) {
    set[*d] = true;
  }
}

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

__attribute__((__flatten__))
char* strpbrk(const char* s, const char* delims) {
  size_t i = strcspn(s, delims);
  if (s[i] != '\0') return const_cast<char*>(s) + i;
  return nullptr;
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
