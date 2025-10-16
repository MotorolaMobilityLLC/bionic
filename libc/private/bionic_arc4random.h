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

#pragma once

#include <sys/cdefs.h>

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

// Before first_stage_init runs, some platforms might not have /dev/urandom and
// if they do, reading that node could take seconds if they don't have access to
// a hwrng. Let's skip randomness for those very specific cases.
bool __libc_arc4random_ready();

// arc4random(3) aborts if it's unable to fetch entropy, which might be the case
// on some low-end devices without any hwrng before first_stage_init. GCE
// kernels have a workaround to ensure sufficient entropy during early boot, but
// no device kernels do. This wrapper falls back to AT_RANDOM if the kernel
// doesn't have enough entropy for getrandom(2) or /dev/urandom but note that
// AT_RANDOM only gives us 16 bytes, and they're already taken, so it won't be
// possible to add new callers.
void __libc_arc4random_buf_or_die(void* buf, size_t n);

// Unsafe wrapper during first_stage_init.
uint32_t __libc_arc4random_uniform_or_zero(uint32_t upper_bound);
