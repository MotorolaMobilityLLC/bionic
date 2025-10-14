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

#define ALIGN_TEXT	.p2align 4,0x90		/* 16-byte alignment, nop filled */

ENTRY(memchr)
	test		%rdx, %rdx		# empty input?
	je		L(nomatchb)

	movd		%esi, %xmm2
	mov		%edi, %ecx
	mov		$-1, %r9
	add		%rdi, %rdx		# pointer to end of buffer or to end of
	cmovc		%r9, %rdx		# address space (whichever comes first)
	and		$~0x1f, %rdi		# align to 32 bytes
	movdqa		(%rdi), %xmm0		# load first 32 bytes
	movdqa		16(%rdi), %xmm1

	punpcklbw	%xmm2, %xmm2		# c -> cc

	shl		%cl, %r9d		# mask with zeroes before the string

	punpcklwd	%xmm2, %xmm2		# cc -> cccc

	mov		$-1, %r8d
	xor		%ecx, %ecx
	sub		%edx, %ecx		# edx = -ecx
	shr		%cl, %r8d		# bytes in tail that are part of the buffer

	pshufd		$0, %xmm2, %xmm2	# cccc -> cccccccccccccccc

	add		$32, %rdi		# advance to next 32 bytes
	mov		$-1, %eax
	cmp		%rdx, %rdi		# end of buffer reached during head?
	cmovae		%r8d, %eax		# if yes, do combined head/tail processing
	and		%r9d, %eax		# mask of bytes in head part of string

	/* process head */
	pcmpeqb		%xmm2, %xmm1
	pcmpeqb		%xmm2, %xmm0
	pmovmskb	%xmm1, %esi
	pmovmskb	%xmm0, %ecx
	shl		$16, %esi
	or		%esi, %ecx		# locations of matches
	and		%ecx, %eax		# any match inside buffer?
	jnz		L(precisematchb)

	cmp		%rdx, %rdi		# did the buffer end here?
	jae		L(nomatchb)		# if yes we are done

	/* main loop */
	ALIGN_TEXT
0:	movdqa		(%rdi), %xmm0		# load next string chunk
	movdqa		16(%rdi), %xmm1
	add		$32, %rdi
	cmp		%rdx, %rdi		# ready for main loop?
	jae		L(tailb)

	pcmpeqb		%xmm2, %xmm0
	pcmpeqb		%xmm2, %xmm1
	por		%xmm1, %xmm0		# match in either half?
	pmovmskb	%xmm0, %eax
	test		%eax, %eax
	jz		0b

L(matchb):
	pcmpeqb		-32(%rdi), %xmm2	# redo comparison of first 16 bytes
	pmovmskb	%xmm1, %ecx
	pmovmskb	%xmm2, %eax
	shl		$16, %ecx
	or		%ecx, %eax		# location of matches

L(precisematchb):
	tzcnt		%eax, %eax		# find location of match
	lea		-32(%rdi, %rax, 1), %rax # point to matching byte
	ret

L(tailb):
	pcmpeqb		%xmm2, %xmm1
	pcmpeqb		%xmm2, %xmm0
	pmovmskb	%xmm1, %edx
	pmovmskb	%xmm0, %eax
	shl		$16, %edx
	or		%edx, %eax		# location of matches
	and		%r8d, %eax		# mask out matches beyond buffer
	bsf		%eax, %edx		# location of match
	lea		-32(%rdi, %rdx, 1), %rdx # pointer to match (if any)
	cmovnz		%rdx, %rax		# point to match if present,
	ret					# else null pointer

L(nomatchb):
	xor	%eax, %eax	# return null pointer
	ret
END(memchr)
