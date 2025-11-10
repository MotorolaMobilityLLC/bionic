/*
 * Copyright (C) 2025 The Android Open Source Project
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
/*
 * Copyright (c) 2023 SiFive, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the company may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY SIFIVE INC ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL SIFIVE INC BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <private/bionic_asm.h>

#define pRet a0
#define iCh a1
#define pStr a2
#define iVL t0
#define iEndOffset t1
#define iChOffset t0
#define iCurrentVL t0

/* This strrchr implementation supports m1-m8, can tune to hardware */
#define ELEM_LMUL_SETTING m1
#define vMask v0
#define vStr v8
#define vMaskEnd v16
#define vMaskCh v16
#define vMaskFirst v17

ENTRY(strrchr)

    mv pStr, a0
    li pRet, 0
    vsetvli iVL, zero, e8, ELEM_LMUL_SETTING, ta, ma
L(load_vec):
    vle8ff.v vStr, (pStr)
    vmseq.vi vMaskEnd, vStr, 0
    vfirst.m iEndOffset, vMaskEnd /* first occurrence of \0 */
    vmsif.m vMask, vMaskEnd  /* mask up to and including \0 */
    vmseq.vx vMaskCh, vStr, iCh, vMask.t
L(find_last_ch):
    /* TODO: use Zvbb vbrev.v to handle pessimal case where pStr is all ch */
    vfirst.m iChOffset, vMaskCh, vMask.t /* first occurrence of ch */
    bltz iChOffset, L(next)
    add pRet, pStr, iChOffset
    vmsof.m vMaskFirst, vMaskCh      /* clear the one we found */
    vmandn.mm vMaskCh, vMaskCh, vMaskFirst
    j L(find_last_ch)
L(next):
    csrr iCurrentVL, vl
    add pStr, pStr, iCurrentVL
    bltz iEndOffset, L(load_vec) /* Didn't find \0? */
    ret

END(strrchr)
