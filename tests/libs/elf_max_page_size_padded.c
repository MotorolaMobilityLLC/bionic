/*
 * Copyright (C) 2026 The Android Open Source Project
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

#include <stdint.h>

// Use a non-multiple of 4KiB or 16KiB to ensure segment ends are not
// page-aligned, testing the linker's alignment logic (align_up/down).

#define PADDING_SIZE (0x14000 - 1)
#define PADDING_SECTION(name) __attribute__((section(name)))

// These large paddings ensure that RO, RW, and RX segments span multiple
// 16KiB pages, creating "middle pages" that can be protected.
// Their sizes are deliberately not multiples of 4KiB to test edge cases.
const char ro_padding[PADDING_SIZE] PADDING_SECTION(".rodata") = {1};
      char rw_padding[PADDING_SIZE] PADDING_SECTION(".data")   = {1};
const char rx_padding[PADDING_SIZE] PADDING_SECTION(".text")   = {1};

int loader_test_func(void) {
  // Reference the symbols to prevent them from being optimized away.
  if (ro_padding[0] == 0) return 0;
  if (rw_padding[0] == 0) return 0;
  if (rx_padding[0] == 0) return 0;

  return 1;
}
