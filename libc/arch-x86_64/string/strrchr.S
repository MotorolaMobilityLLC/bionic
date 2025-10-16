/*-
 * Copyright (c) 2023 The FreeBSD Foundation
 *
 * This software was developed by Robert Clausecker <fuz@FreeBSD.org>
 * under sponsorship from the FreeBSD Foundation.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ''AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE
 */

#include <private/bionic_asm.h>

#define ALIGN_TEXT	.p2align 4,0x90	# 16-byte alignment, nop-filled

ENTRY(strrchr)
	mov		%edi, %ecx
	and		$~0xf, %rdi		# align to 16 bytes
	movdqa		(%rdi), %xmm1
	movd		%esi, %xmm0
	and		$0xf, %ecx		# offset from alignment
	pxor		%xmm2, %xmm2
	mov		$-1, %edx
	punpcklbw	%xmm0, %xmm0		# c -> cc
	shl		%cl, %edx		# bits corresponding to bytes in the string
	punpcklwd	%xmm0, %xmm0		# cc -> cccc
	xor		%r8, %r8		# address of latest match
	mov		$1, %esi		# bit mask of latest match
	mov		%rdi, %r9		# candidate location for next match
	add		$16, %rdi		# advance to next chunk

	/* check for match in head */
	pcmpeqb		%xmm1, %xmm2		# NUL byte present?
	pshufd		$0, %xmm0, %xmm0	# cccc -> cccccccccccccccc
	pcmpeqb		%xmm0, %xmm1		# c present?
	pmovmskb	%xmm2, %eax
	pmovmskb	%xmm1, %ecx
	and		%edx, %ecx		# c present in the string?
	and		%edx, %eax		# NUL present in the string?
	jnz		L(end2)

	/* main loop unrolled twice */
	ALIGN_TEXT
0:	movdqa		(%rdi), %xmm1
	test		%ecx, %ecx		# was there a match in the last iter.?
	cmovnz		%r9, %r8		# remember match if any
	cmovnz		%ecx, %esi
	pxor		%xmm2, %xmm2
	pcmpeqb		%xmm1, %xmm2		# NUL byte present?
	pcmpeqb		%xmm0, %xmm1		# c present?
	pmovmskb	%xmm2, %eax
	pmovmskb	%xmm1, %ecx
	test		%eax, %eax		# end of string in first half?
	jnz		L(end)

	movdqa		16(%rdi), %xmm1
	test		%ecx, %ecx		# was there a match in the last iter.?
	cmovnz		%rdi, %r8		# remember match if any
	cmovnz		%ecx, %esi
	pxor		%xmm2, %xmm2
	pcmpeqb		%xmm1, %xmm2		# NUL byte present?
	pcmpeqb		%xmm0, %xmm1		# c present?
	pmovmskb	%xmm2, %eax
	pmovmskb	%xmm1, %ecx
	lea		16(%rdi), %r9
	add		$32, %rdi
	test		%eax, %eax		# end of string in second half?
	jz		0b

	ALIGN_TEXT
L(end2):sub		$16, %rdi
L(end):	lea 		-1(%rax), %edx
	xor		%edx, %eax		# mask of bytes in the string
	and		%eax, %ecx		# c found in the tail?
	cmovnz		%rdi, %r8
	cmovnz		%ecx, %esi
	bsr		%esi, %esi		# last location of c in (R8)
	lea		(%r8, %rsi, 1), %rax	# pointer to match
	ret
END(strrchr)
