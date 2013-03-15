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

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libc_logging.h"

/*
 * Runtime implementation of __builtin____vsprintf_chk.
 *
 * See
 *   http://gcc.gnu.org/onlinedocs/gcc/Object-Size-Checking.html
 *   http://gcc.gnu.org/ml/gcc-patches/2004-09/msg02055.html
 * for details.
 *
 * This vsprintf check is called if _FORTIFY_SOURCE is defined and
 * greater than 0.
 */
extern "C" int __vsprintf_chk(
        char *dest,
        int /*flags*/,
        size_t dest_len_from_compiler,
        const char *format,
        va_list va)
{
    int ret = vsnprintf(dest, dest_len_from_compiler, format, va);

    if ((size_t) ret >= dest_len_from_compiler) {
        __fortify_chk_fail("vsprintf buffer overflow", 0);
    }

    return ret;
}

/*
 * Runtime implementation of __builtin____sprintf_chk.
 *
 * See
 *   http://gcc.gnu.org/onlinedocs/gcc/Object-Size-Checking.html
 *   http://gcc.gnu.org/ml/gcc-patches/2004-09/msg02055.html
 * for details.
 *
 * This sprintf check is called if _FORTIFY_SOURCE is defined and
 * greater than 0.
 */
extern "C" int __sprintf_chk(
        char *dest,
        int flags,
        size_t dest_len_from_compiler,
        const char *format, ...)
{
    va_list va;
    int retval;

    va_start(va, format);
    retval = __vsprintf_chk(dest, flags,
                             dest_len_from_compiler, format, va);
    va_end(va);

    return retval;
}
