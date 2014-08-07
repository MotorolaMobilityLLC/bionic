/*
 * Copyright (C) 2012 The Android Open Source Project
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

#include <sys/cdefs.h>

/*
   __stack_chk_fail routine is runtime part of stack protector compiler
   feature. It's implemented in libc and represents die routine when stack
   corruption is detected.

   Calls are generated by compiler and injected into user functions when
   -fstack-protector* options are used.

   __stack_chk_fail_local is wrapper for __stack_chk_fail. Compiler generates
   wrapper calls instead for PIC code only and only on IA32 for optimization
   purpose (see gcc/config/i386/i386.c). Wrapper body is always included into
   executable or library. This is the idea of optimization.

   Glibc is doing this via libc_nonshared.a which is linked automatically
   everytime with libc.so. In bionic we have to bring it within crtfiles
   because libc.so is real library and not a link script like libc.so at glibc.

   For x86_64 or non-PIC code compiler always generates __stack_chk_fail calls.
*/

#ifdef __i386__
extern void __stack_chk_fail();

__LIBC_HIDDEN__ void __stack_chk_fail_local() {
  __stack_chk_fail();
}
#endif
