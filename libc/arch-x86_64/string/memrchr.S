/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2023, 2025 Robert Clausecker <fuz@FreeBSD.org>
 */

#include <private/bionic_asm.h>

#define ALIGN_TEXT	.p2align 4, 0x90

ENTRY(memrchr)
	test		%rdx, %rdx		# empty input?
	je		L(nomatchb)


	lea		(%rdi, %rdx, 1), %ecx	# pointer to end of buffer
	lea		-1(%rdi, %rdx, 1), %rdx	# pointer to last char in buffer
	movd		%esi, %xmm2
	and		$~0x1f, %rdx		# pointer to final 32 buffer bytes
	movdqa		(%rdx), %xmm0		# load last 32 bytes
	movdqa		16(%rdx), %xmm1

	punpcklbw	%xmm2, %xmm2		# c -> cc

	mov		$-1, %r8d
	neg		%ecx
	mov		%r8d, %r9d
	shr		%cl, %r8d		# mask with zeroes after the string

	punpcklwd	%xmm2, %xmm2		# cc -> cccc

	mov		%edi, %ecx
	mov		%r9d, %eax
	shl		%cl, %r9d		# mask with zeroes before the string

	pshufd		$0, %xmm2, %xmm2	# cccc -> cccccccccccccccc

	cmp		%rdx, %rdi		# tail is beginning of buffer?
	cmovae		%r9d, %eax		# if yes, do combined head/tail processing
	and		%r8d, %eax		# mak of bytes in tail part of string

	/* process tail */
	pcmpeqb		%xmm2, %xmm1
	pcmpeqb		%xmm2, %xmm0
	pmovmskb	%xmm1, %esi
	pmovmskb	%xmm0, %ecx
	shl		$16, %esi
	or		%esi, %ecx		# locations of matches
	and		%ecx, %eax		# any match inside buffer?
	jnz		L(precisematchb)

	cmp		%rdx, %rdi		# did the buffer begin here?
	jae		L(nomatchb)		# if yes, we are done

	/* main loop */
	ALIGN_TEXT
0:	movdqa		-32(%rdx), %xmm0	# load previous string chunk
	movdqa		-16(%rdx), %xmm1
	sub		$32, %rdx		# beginning of string reached?
	cmp		%rdx, %rdi
	jae		L(tailb)

	pcmpeqb		%xmm2, %xmm0
	pcmpeqb		%xmm2, %xmm1
	por		%xmm1, %xmm0		# match in either half?
	pmovmskb	%xmm0, %eax
	test		%eax, %eax
	jz		0b

L(matchb):
	pcmpeqb		(%rdx), %xmm2		# redo comparison of first 16 bytes
	pmovmskb	%xmm1, %ecx
	pmovmskb	%xmm2, %eax
	shl		$16, %ecx
	or		%ecx, %eax		# location of matches

L(precisematchb):
	bsr		%eax, %eax		# find location of match
	add		%rdx, %rax		# point to matching byte
	ret

L(tailb):
	pcmpeqb		%xmm2, %xmm1
	pcmpeqb		%xmm2, %xmm0
	pmovmskb	%xmm1, %ecx
	pmovmskb	%xmm0, %eax
	shl		$16, %ecx
	or		%ecx, %eax		# location of matches
	and		%r9d, %eax		# mask out matches before buffer
	bsr		%eax, %edi		# location of match
	lea		(%rdx, %rdi, 1), %rdx	# pointer to match (if any)
	cmovnz		%rdx, %rax		# point to match if present,
	ret					# else null pointer

L(nomatchb):
	xor		%eax, %eax		# return null pointer
	ret
END(memrchr)
