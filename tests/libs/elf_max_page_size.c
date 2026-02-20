/*
 * Copyright (C) 2024 The Android Open Source Project
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

#include "elf_max_page_size.h"

const int ro0 = RO0;
const int ro1 = RO1;
int rw0 = RW0;

/* Force some padding alignment. Use 4KiB to avoid conflict with Linker's
 * 16KiB compat loading logic, which needs to apply 4KiB offsets.
 */
int rw1 __attribute__((aligned(4096))) = RW1;

int bss0, bss1;

int* const prw0 = &rw0;

/* Ensure RELRO segment is large enough to have "middle pages" in 16KiB.
 * 4096 * 8 bytes = 32KiB (on 64-bit).
 */
int *const big_relro_table[4096] = {
    &rw0,  &bss0, &rw1, &bss1, &rw0,
    &bss0, &rw1,  &bss1
    /* ... The compiler will automatically fill the remaining part with NULL,
       but the preceding relocations are enough to enlarge RELRO. */
};

int loader_test_func(void) {
  // Must reference big_relro_table to ensure it is not removed by gc-sections.
  if (big_relro_table[0] == 0) return 0;

  rw0 += RW0_INCREMENT;
  rw1 += RW1_INCREMENT;

  bss0 += BSS0_INCREMENT;
  bss1 += BSS1_INCREMENT;

  return ro0 + ro1 + rw0 + rw1 + bss0 + bss1 + *prw0;
}
