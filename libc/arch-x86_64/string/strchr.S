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

ENTRY(strchrnul)
	mov		%edi, %ecx
	and		$~0xf, %rdi		# align to 16 byte
	movdqa		(%rdi), %xmm1
	movd		%esi, %xmm0
	and		$0xf, %ecx		# distance from (%rdi) to start of string
	pxor		%xmm2, %xmm2
	mov		$-1, %edx
	punpcklbw	%xmm0, %xmm0		# c -> cc
	shl		%cl, %edx		# bits corresponding to bytes in the string
	punpcklwd	%xmm0, %xmm0		# cc -> cccc
	add		$16, %rdi

	/* check for match in head */
	pcmpeqb		%xmm1, %xmm2		# NUL bytes present?
	pshufd		$0, %xmm0, %xmm0	# cccc -> cccccccccccccccc
	pcmpeqb		%xmm0, %xmm1		# c present?
	por		%xmm2, %xmm1		# either present?
	pmovmskb	%xmm1, %eax
	and		%edx, %eax		# match in the string?
	jnz		1f

	/* main loop unrolled twice */
	ALIGN_TEXT
0:	movdqa		(%rdi), %xmm1
	pxor		%xmm2, %xmm2
	pcmpeqb		%xmm1, %xmm2		# NUL bytes present?
	pcmpeqb		%xmm0, %xmm1		# c present?
	por		%xmm2, %xmm1		# either present?
	pmovmskb	%xmm1, %eax
	test		%eax, %eax		# match in the string?
	jnz		2f

	movdqa		16(%rdi), %xmm1
	add		$32, %rdi
	pxor		%xmm2, %xmm2
	pcmpeqb		%xmm1, %xmm2		# NUL bytes present?
	pcmpeqb		%xmm0, %xmm1		# c present?
	por		%xmm2, %xmm1		# either present?
	pmovmskb	%xmm1, %eax
	test		%eax, %eax		# match in the string?
	jz		0b

1:	sub		$16, %rdi		# undo advance past buffer
2:	tzcnt		%eax, %eax		# where is the match?
	add		%rdi, %rax		# pointer to found c or NUL
	ret
END(strchrnul)

ENTRY(strchr)
	// if (*strchrnul(s, c) != c) return nullptr;
	// We have to compare against c rather than '\0' to
	// correctly handle strchr(s, '\0'), so we need the push/pop
	// to get c into a suitable register for an x86-64 byte compare.
	push		%rbx
	mov		%esi, %ebx
	call		strchrnul
	xor		%ecx, %ecx
	cmp		%bl, (%rax)
	cmovne		%rcx, %rax
	pop		%rbx
	ret
END(strchr)
