	.cpu cortex-a53+fp+simd
	.section	.text.hot,"ax",%progbits
	.align	2
	.global	log
	.type	log, %function
log:
	fmov	x1, d0
	mov	w2, 2146435071
	ubfx	x0, x1, 32, 32
	cmp	w0, w2
	bgt	.L14
	mov	w3, 1048575
	cmp	w0, w3
	ble	.L4
	and	w5, w0, w3
	add	w4, w5, 610304
	add	w6, w4, 3940
	and	w8, w6, 1048576
	fmov	x7, d0
	eor	w9, w8, 1072693248
	orr	w10, w9, w5
	bfi	x7, x10, 32, 32
	fmov	d1, 1.0e+0
	fmov	d0, x7
	ldr	d4, .LC0
	ldr	d6, .LC1
	ldr	d5, .LC4
	fadd	d3, d0, d1
	fsub	d2, d0, d1
	ldr	d21, .LC5
	ldr	d25, .LC2
	ldr	d27, .LC6
	fdiv	d0, d2, d3
	ldr	d31, .LC3
	mov	w11, 47185
	sub	w12, w5, #397312
	movk	w11, 0x6, lsl 16
	asr	w13, w0, 20
	sub	w14, w12, #1146
	sub	w15, w11, w5
	sub	w16, w13, #1023
	orr	w17, w15, w14
	add	w18, w16, w8, lsr 20
	cmp	w17, wzr
	scvtf	d7, w18
	fmul	d16, d0, d0
	fmul	d17, d16, d16
	fmul	d18, d17, d4
	fmul	d19, d17, d5
	fadd	d20, d18, d6
	fadd	d22, d19, d21
	fmul	d23, d20, d17
	fmul	d24, d22, d17
	fadd	d26, d23, d25
	fadd	d28, d24, d27
	fmul	d29, d26, d17
	fmul	d30, d28, d17
	fadd	d1, d29, d31
	fmul	d3, d1, d16
	fadd	d4, d3, d30
	bgt	.L5
.L9:
	fsub	d18, d2, d4
	cbnz	w18, .L6
	fmul	d21, d18, d0
	fsub	d0, d2, d21
	ret
.L14:
	fadd	d0, d0, d0
	ret
.L6:
	ldr	d5, .LC10
	fmul	d0, d18, d0
	fmul	d19, d7, d5
	ldr	d6, .LC9
	fmul	d7, d7, d6
	fsub	d20, d0, d19
	fsub	d2, d20, d2
	fsub	d0, d7, d2
	ret
.L4:
	and	w18, w0, 2147483647
	orr	w1, w18, w1
	cbz	w1, .L15
	tbnz	w0, #31, .L16
	ldr	d2, .LC8
	fmov	d7, 1.0e+0
	fmul	d0, d0, d2
	ldr	d5, .LC0
	ldr	d21, .LC1
	ldr	d6, .LC4
	fmov	x0, d0
	fmov	x5, d0
	ubfx	x2, x0, 32, 32
	and	w6, w2, 1048575
	add	w3, w6, 610304
	add	w4, w3, 3940
	and	w7, w4, 1048576
	eor	w8, w7, 1072693248
	orr	w9, w8, w6
	bfi	x5, x9, 32, 32
	ldr	d23, .LC5
	fmov	d16, x5
	ldr	d27, .LC2
	ldr	d29, .LC6
	ldr	d1, .LC3
	fadd	d17, d16, d7
	fsub	d2, d16, d7
	mov	w10, 47185
	sub	w11, w6, #397312
	movk	w10, 0x6, lsl 16
	fdiv	d0, d2, d17
	asr	w12, w2, 20
	sub	w13, w11, #1146
	sub	w14, w10, w6
	sub	w15, w12, #1077
	orr	w16, w14, w13
	add	w18, w15, w7, lsr 20
	cmp	w16, wzr
	scvtf	d7, w18
	fmul	d4, d0, d0
	fmul	d18, d4, d4
	fmul	d19, d18, d5
	fmul	d20, d18, d6
	fadd	d22, d19, d21
	fadd	d24, d20, d23
	fmul	d25, d22, d18
	fmul	d26, d24, d18
	fadd	d28, d25, d27
	fadd	d30, d26, d29
	fmul	d31, d28, d18
	fmul	d3, d30, d18
	fadd	d16, d31, d1
	fmul	d17, d16, d4
	fadd	d4, d17, d3
	ble	.L9
.L5:
	fmov	d22, 5.0e-1
	fmul	d23, d2, d22
	fmul	d24, d23, d2
	fadd	d25, d24, d4
	cbnz	w18, .L10
	fmul	d16, d25, d0
	fsub	d17, d24, d16
	fsub	d0, d2, d17
	ret
.L10:
	ldr	d26, .LC10
	fmul	d28, d25, d0
	fmul	d27, d7, d26
	ldr	d29, .LC9
	fmul	d30, d7, d29
	fadd	d31, d28, d27
	fsub	d3, d24, d31
	fsub	d1, d3, d2
	fsub	d0, d30, d1
	ret
.L16:
	fsub	d4, d0, d0
	fmov	d18, xzr
	fdiv	d0, d4, d18
	ret
.L15:
	fmov	d5, xzr
	ldr	d19, .LC7
	fdiv	d0, d19, d5
	ret
	.size	log, .-log
	.align	3
.LC0:
	.word	-549563836
	.word	1069740306
	.align	3
.LC1:
	.word	-1765080098
	.word	1070024292
	.align	3
.LC2:
	.word	-1809673383
	.word	1070745892
	.align	3
.LC3:
	.word	1431655827
	.word	1071994197
	.align	3
.LC4:
	.word	-797391201
	.word	1069783561
	.align	3
.LC5:
	.word	495876271
	.word	1070363077
	.align	3
.LC6:
	.word	-1718093308
	.word	1071225241
	.align	3
.LC7:
	.word	0
	.word	-1018167296
	.align	3
.LC8:
	.word	0
	.word	1129316352
	.align	3
.LC9:
	.word	-18874368
	.word	1072049730
	.align	3
.LC10:
	.word	897137782
	.word	1038760431
	.ident	"GCC: (crosstool-NG linaro-1.13.1-4.8-2014.04 - Linaro GCC 4.8-2014.04) 4.8.3 20140401 (prerelease)"

#if (LDBL_MANT_DIG == 53)
    .weak   logl
    .equ    logl, log
#endif

