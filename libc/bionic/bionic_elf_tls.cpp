/*
 * Copyright (C) 2019 The Android Open Source Project
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

#include "private/bionic_elf_tls.h"

#include <sys/param.h>

#include "private/bionic_macros.h"
#include "private/bionic_tls.h"

void StaticTlsLayout::reserve_tcb() {
  offset_bionic_tcb_ = reserve_type<bionic_tcb>();
}

void StaticTlsLayout::reserve_bionic_tls() {
  offset_bionic_tls_ = reserve_type<bionic_tls>();
}

void StaticTlsLayout::finish_layout() {
  // Round the offset up to the alignment.
  offset_ = round_up_with_overflow_check(offset_, alignment_);
}

// The size is not required to be a multiple of the alignment. The alignment
// must be a positive power-of-two.
size_t StaticTlsLayout::reserve(size_t size, size_t alignment) {
  offset_ = round_up_with_overflow_check(offset_, alignment);
  const size_t result = offset_;
  if (__builtin_add_overflow(offset_, size, &offset_)) overflowed_ = true;
  alignment_ = MAX(alignment_, alignment);
  return result;
}

size_t StaticTlsLayout::round_up_with_overflow_check(size_t value, size_t alignment) {
  const size_t old_value = value;
  value = __BIONIC_ALIGN(value, alignment);
  if (value < old_value) overflowed_ = true;
  return value;
}
