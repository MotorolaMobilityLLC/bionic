/*
 * Copyright (C) 2016 The Android Open Source Project
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

#include "private/bionic_arc4random.h"

#include <stdlib.h>
#include <string.h>
#include <sys/auxv.h>
#include <sys/random.h>
#include <unistd.h>

#include <async_safe/log.h>

void __libc_arc4random_buf_or_die(void* buf, size_t n) {
  if (__libc_arc4random_ready()) {
    arc4random_buf(buf, n);
    return;
  }

  static size_t at_random_bytes_consumed = 0;
  if (at_random_bytes_consumed + n > 16) {
    async_safe_fatal("ran out of AT_RANDOM bytes, have %zu, requested %zu",
                     16 - at_random_bytes_consumed, n);
  }

  memcpy(buf, reinterpret_cast<char*>(getauxval(AT_RANDOM)) + at_random_bytes_consumed, n);
  at_random_bytes_consumed += n;
}

uint32_t __libc_arc4random_uniform_or_zero(uint32_t upper_bound) {
  return __libc_arc4random_ready() ? arc4random_uniform(upper_bound) : 0;
}

bool __libc_arc4random_ready() {
  // This is true for the lifetime of the process...
  static bool is_first_stage_init = getpid() == 1 && access("/proc/self/exe", F_OK) == -1;
  if (!is_first_stage_init) return true;

  // ...while this might change
  static bool getrandom_ready;
  if (getrandom_ready) return true;

  char buf;
  getrandom_ready = getrandom(&buf, 1, GRND_NONBLOCK) == 1;

  return getrandom_ready;
}
