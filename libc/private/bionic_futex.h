/*
 * Copyright (C) 2008 The Android Open Source Project
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
#ifndef _BIONIC_FUTEX_H
#define _BIONIC_FUTEX_H

#include <linux/futex.h>
#include <sys/cdefs.h>
#include <stdbool.h>
#include <stddef.h>

__BEGIN_DECLS

struct timespec;

extern int __futex_syscall4(volatile void* ftx, int op, int value, const struct timespec* timeout);

static inline int __futex_wake(volatile void* ftx, int count) {
  return __futex_syscall4(ftx, FUTEX_WAKE, count, NULL);
}

static inline int __futex_wake_ex(volatile void* ftx, bool shared, int count) {
  return __futex_syscall4(ftx, shared ? FUTEX_WAKE : FUTEX_WAKE_PRIVATE, count, NULL);
}

static inline int __futex_wait(volatile void* ftx, int value, const struct timespec* timeout) {
  return __futex_syscall4(ftx, FUTEX_WAIT, value, timeout);
}

static inline int __futex_wait_ex(volatile void* ftx, bool shared, int value, const struct timespec* timeout) {
  return __futex_syscall4(ftx, shared ? FUTEX_WAIT : FUTEX_WAIT_PRIVATE, value, timeout);
}

__END_DECLS

#endif /* _BIONIC_FUTEX_H */
