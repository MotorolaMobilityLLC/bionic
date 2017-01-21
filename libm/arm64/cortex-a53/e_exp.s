	.cpu cortex-a53+fp+simd
	.section	.text.hot,"ax",%progbits
	.align	2
	.global	exp
	.type	exp, %function
exp:
	fmov	x1, d0
	mov	w2, 41649
	ubfx	x4, x1, 32, 32
	movk	w2, 0x3ff0, lsl 16
	and	w0, w4, 2147483647
	cmp	w0, w2
	lsr	w5, w4, 31
	bhi	.L26
	mov	w3, 11842
	movk	w3, 0x3fd6, lsl 16
	cmp	w0, w3
	bhi	.L27
	mov	w6, 1043333119
	cmp	w0, w6
	bls	.L13
	fmul	d1, d0, d0
	ldr	d2, .LC3
	ldr	d3, .LC4
	ldr	d7, .LC5
	fmul	d5, d1, d2
	ldr	d18, .LC6
	ldr	d21, .LC7
	fmov	d26, 2.0e+0
	fsub	d4, d5, d3
	fmov	d30, 1.0e+0
	fmul	d6, d4, d1
	fadd	d16, d6, d7
	fmul	d17, d16, d1
	fsub	d19, d17, d18
	fmul	d20, d19, d1
	fadd	d22, d20, d21
	fmul	d23, d22, d1
	fsub	d24, d0, d23
	fmul	d25, d0, d24
	fsub	d27, d24, d26
	fdiv	d28, d25, d27
	fsub	d29, d28, d0
	fsub	d0, d30, d29
.L1:
	ret
.L26:
	mov	w15, 11841
	movk	w15, 0x4086, lsl 16
	cmp	w0, w15
	bhi	.L3
	ldr	d4, .LC0
	adrp	x17, .LANCHOR0
	fmul	d17, d0, d4
	sxtw	x16, w5
	add	x18, x17, :lo12:.LANCHOR0
	ldr	d21, .LC1
	ldr	d18, [x18,x16,lsl 3]
	ldr	d23, .LC2
	fadd	d19, d17, d18
	ldr	d24, .LC3
	ldr	d26, .LC4
	ldr	d29, .LC5
	fcvtzs	w5, d19
	ldr	d6, .LC6
	ldr	d1, .LC7
	scvtf	d20, w5
	cmn	w5, #1021
	fmul	d22, d20, d21
	fmul	d21, d20, d23
	fsub	d0, d0, d22
	fsub	d22, d0, d21
	fmul	d23, d22, d22
	fmul	d25, d23, d24
	fsub	d27, d25, d26
	fmul	d28, d27, d23
	fadd	d30, d28, d29
	fmul	d31, d30, d23
	fsub	d5, d31, d6
	fmul	d3, d5, d23
.L24:
	fadd	d2, d1, d3
	fmov	d4, 2.0e+0
	fmul	d7, d2, d23
	fsub	d16, d22, d7
	fmul	d17, d22, d16
	fsub	d18, d4, d16
	fdiv	d19, d17, d18
	fsub	d20, d21, d19
	fsub	d21, d20, d0
	fmov	d0, 1.0e+0
	fsub	d22, d0, d21
	fmov	x3, d22
	fmov	x6, d22
	blt	.L4
	ubfx	x10, x3, 32, 32
	add	w11, w10, w5, lsl 20
	bfi	x6, x11, 32, 32
	fmov	d0, x6
	ret
.L27:
	cbz	w5, .L12
	ldr	d3, .LC1
	ldr	d6, .LC2
	fadd	d5, d0, d3
	ldr	d4, .LC3
	ldr	d18, .LC4
	ldr	d21, .LC5
	fadd	d7, d5, d6
	ldr	d24, .LC6
	ldr	d27, .LC7
	fmov	d0, 2.0e+0
	fmul	d16, d7, d7
	ldr	d2, .LC12
	fmul	d17, d16, d4
	fsub	d19, d17, d18
	fmul	d20, d19, d16
	fadd	d22, d20, d21
	fmul	d23, d22, d16
	fsub	d25, d23, d24
	fmul	d26, d25, d16
	fadd	d28, d26, d27
	fmul	d29, d28, d16
	fsub	d30, d7, d29
	fmul	d31, d7, d30
	fsub	d1, d0, d30
	fmov	d7, 1.0e+0
	fdiv	d3, d31, d1
	fsub	d6, d2, d3
	fsub	d5, d6, d5
	fsub	d16, d7, d5
	fmov	x11, d16
	fmov	x12, d16
	ubfx	x13, x11, 32, 32
	sub	w14, w13, #1048576
	bfi	x12, x14, 32, 32
	fmov	d0, x12
	ret
.L12:
	ldr	d1, .LC1
	ldr	d31, .LC2
	fsub	d0, d0, d1
	ldr	d5, .LC3
	ldr	d4, .LC4
	ldr	d17, .LC5
	fsub	d2, d0, d31
	ldr	d20, .LC6
	ldr	d23, .LC7
	fmov	d28, 2.0e+0
	fmul	d3, d2, d2
	fmov	d1, 1.0e+0
	fmul	d6, d3, d5
	fsub	d7, d6, d4
	fmul	d16, d7, d3
	fadd	d18, d16, d17
	fmul	d19, d18, d3
	fsub	d21, d19, d20
	fmul	d22, d21, d3
	fadd	d24, d22, d23
	fmul	d25, d24, d3
	fsub	d26, d2, d25
	fmul	d27, d2, d26
	fsub	d29, d28, d26
	fdiv	d30, d27, d29
	fsub	d31, d31, d30
	fsub	d0, d31, d0
	fsub	d2, d1, d0
	fmov	x7, d2
	fmov	x8, d2
	ubfx	x9, x7, 32, 32
	add	w10, w9, 1048576
	bfi	x8, x10, 32, 32
	fmov	d0, x8
	ret
.L13:
	ldr	d1, .LC9
	fmov	d2, 1.0e+0
	fadd	d3, d0, d1
	fcmpe	d3, d2
	ble	.L21
	fadd	d0, d0, d2
	ret
.L3:
	mov	w2, 2146435071
	cmp	w0, w2
	bls	.L5
	and	w13, w4, 1048575
	orr	w14, w13, w1
	cbnz	w14, .L28
	cbz	w5, .L1
.L10:
	fmov	d0, xzr
	ret
.L4:
	add	w7, w5, 1000
	ubfx	x8, x3, 32, 32
	add	w9, w8, w7, lsl 20
	bfi	x6, x9, 32, 32
	ldr	d24, .LC11
	fmov	d23, x6
	fmul	d0, d23, d24
	ret
.L21:
	fmul	d5, d0, d0
	ldr	d4, .LC3
	ldr	d7, .LC4
	ldr	d18, .LC5
	fmul	d6, d5, d4
	ldr	d21, .LC6
	ldr	d24, .LC7
	fmov	d29, 2.0e+0
	fsub	d16, d6, d7
	fmul	d17, d16, d5
	fadd	d19, d17, d18
	fmul	d20, d19, d5
	fsub	d22, d20, d21
	fmul	d23, d22, d5
	fadd	d25, d23, d24
	fmul	d26, d25, d5
	fsub	d27, d0, d26
	fmul	d28, d0, d27
	fsub	d30, d27, d29
	fdiv	d31, d28, d30
	fsub	d0, d31, d0
	fsub	d0, d2, d0
	ret
.L28:
	fadd	d0, d0, d0
	ret
.L5:
	ldr	d1, .LC8
	fcmpe	d0, d1
	bgt	.L29
	ldr	d3, .LC10
	fcmpe	d0, d3
	bmi	.L10
	ldr	d2, .LC0
	adrp	x4, .LANCHOR0
	fmul	d7, d0, d2
	sxtw	x1, w5
	add	x0, x4, :lo12:.LANCHOR0
	ldr	d18, .LC1
	ldr	d16, [x0,x1,lsl 3]
	ldr	d20, .LC2
	fadd	d4, d7, d16
	ldr	d24, .LC3
	ldr	d26, .LC4
	ldr	d29, .LC5
	fcvtzs	w5, d4
	ldr	d6, .LC6
	ldr	d3, .LC7
	scvtf	d17, w5
	cmn	w5, #1021
	fmul	d19, d17, d18
	fmul	d21, d17, d20
	fsub	d0, d0, d19
	fsub	d22, d0, d21
	fmul	d23, d22, d22
	fmul	d25, d23, d24
	fsub	d27, d25, d26
	fmul	d28, d27, d23
	fadd	d30, d28, d29
	fmul	d31, d30, d23
	fsub	d5, d31, d6
	fmul	d1, d5, d23
	b	.L24
.L29:
	ldr	d25, .LC9
	fmul	d0, d25, d25
	ret
	.size	exp, .-exp
	.align	3
.LC0:
	.word	1697350398
	.word	1073157447
	.align	3
.LC1:
	.word	-18874368
	.word	1072049730
	.align	3
.LC2:
	.word	897137782
	.word	1038760431
	.align	3
.LC3:
	.word	1925096656
	.word	1046886249
	.align	3
.LC4:
	.word	-976065551
	.word	1052491073
	.align	3
.LC5:
	.word	-1356472788
	.word	1058100842
	.align	3
.LC6:
	.word	381599123
	.word	1063698796
	.align	3
.LC7:
	.word	1431655742
	.word	1069897045
	.align	3
.LC8:
	.word	-17155601
	.word	1082535490
	.align	3
.LC9:
	.word	-2013235812
	.word	2117592124
	.align	3
.LC10:
	.word	-718458799
	.word	-1064875760
	.align	3
.LC11:
	.word	0
	.word	24117248
	.align	3
.LC12:
	.word	897137782
	.word	-1108723217
	.section	.rodata
	.align	4
.LANCHOR0 = . + 0
	.type	halF, %object
	.size	halF, 16
halF:
	.word	0
	.word	1071644672
	.word	0
	.word	-1075838976
	.ident	"GCC: (crosstool-NG linaro-1.13.1-4.8-2014.04 - Linaro GCC 4.8-2014.04) 4.8.3 20140401 (prerelease)"
#if (LDBL_MANT_DIG == 53)
    .weak   expl
    .equ    expl, exp
#endif
