	.cpu cortex-a53+fp+simd
	.section	.text.unlikely,"ax",%progbits
	.align	2
	.global	__ieee754_rem_pio2
	.type	__ieee754_rem_pio2, %function
__ieee754_rem_pio2:
	stp	x29, x30, [sp, -96]!
	fmov	x3, d0
	add	x29, sp, 0
	stp	x19, x20, [sp,16]
	mov	w1, 27258
	ubfx	x20, x3, 32, 32
	movk	w1, 0x400f, lsl 16
	mov	x19, x0
	and	w0, w20, 2147483647
	str	x21, [sp,32]
	cmp	w0, w1
	bgt	.L2
	mov	w15, 8699
	and	w16, w20, 1048575
	movk	w15, 0x9, lsl 16
	cmp	w16, w15
	beq	.L3
	mov	w17, 55676
	movk	w17, 0x4002, lsl 16
	cmp	w0, w17
	bgt	.L4
	cmp	w20, wzr
	ldr	d25, .LC0
	ldr	d20, .LC1
	ble	.L5
	fsub	d22, d0, d25
	mov	w0, 1
	b	.L20
.L5:
	fadd	d21, d0, d25
	mov	w0, -1
	b	.L21
.L4:
	cmp	w20, wzr
	ldr	d24, .LC2
	ldr	d20, .LC3
	ble	.L7
	fsub	d22, d0, d24
	mov	w0, 2
.L20:
	fsub	d29, d22, d20
	fsub	d30, d22, d29
	str	d29, [x19]
	fsub	d31, d30, d20
	str	d31, [x19,8]
	b	.L6
.L7:
	fadd	d21, d0, d24
	mov	w0, -2
.L21:
	fadd	d26, d21, d20
	fsub	d27, d21, d26
	str	d26, [x19]
	fadd	d28, d27, d20
	str	d28, [x19,8]
	b	.L6
.L2:
	mov	w2, 17979
	movk	w2, 0x401c, lsl 16
	cmp	w0, w2
	bgt	.L8
	mov	w12, 64956
	movk	w12, 0x4015, lsl 16
	cmp	w0, w12
	bgt	.L9
	mov	w14, 55676
	movk	w14, 0x4012, lsl 16
	cmp	w0, w14
	beq	.L3
	cmp	w20, wzr
	ldr	d23, .LC4
	ldr	d20, .LC5
	ble	.L10
	fsub	d22, d0, d23
	mov	w0, 3
	b	.L20
.L10:
	fadd	d21, d0, d23
	mov	w0, -3
	b	.L21
.L9:
	mov	w13, 8699
	movk	w13, 0x4019, lsl 16
	cmp	w0, w13
	beq	.L3
	cmp	w20, wzr
	ldr	d19, .LC6
	ldr	d20, .LC7
	ble	.L11
	fsub	d22, d0, d19
	mov	w0, 4
	b	.L20
.L11:
	fadd	d21, d0, d19
	mov	w0, -4
	b	.L21
.L8:
	mov	w4, 8698
	movk	w4, 0x4139, lsl 16
	cmp	w0, w4
	bgt	.L12
.L3:
	ldr	d1, .LC8
	ldr	d2, .LC9
	fmul	d3, d0, d1
	ldr	d5, .LC0
	ldr	d16, .LC1
	asr	w18, w0, 20
	fadd	d4, d3, d2
	fsub	d6, d4, d2
	fmul	d7, d6, d5
	fmul	d2, d6, d16
	fcvtzs	w0, d6
	fsub	d0, d0, d7
	fsub	d17, d0, d2
	fmov	x30, d17
	str	d17, [x19]
	ubfx	x1, x30, 52, 11
	sub	w3, w18, w1
	cmp	w3, 16
	ble	.L13
	ldr	d18, .LC10
	ldr	d20, .LC11
	fmul	d19, d6, d18
	fmul	d21, d6, d20
	fsub	d22, d0, d19
	fsub	d23, d0, d22
	fmov	d0, d22
	fsub	d24, d23, d19
	fsub	d2, d21, d24
	fsub	d25, d22, d2
	fmov	x20, d25
	str	d25, [x19]
	ubfx	x2, x20, 52, 11
	sub	w4, w18, w2
	cmp	w4, 49
	ble	.L13
	ldr	d26, .LC12
	ldr	d28, .LC13
	fmul	d27, d6, d26
	fmul	d29, d6, d28
	fsub	d0, d22, d27
	fsub	d30, d22, d0
	fsub	d31, d30, d27
	fsub	d2, d29, d31
	fsub	d1, d0, d2
	str	d1, [x19]
.L13:
	ldr	d3, [x19]
	fsub	d4, d0, d3
	fsub	d6, d4, d2
	str	d6, [x19,8]
	b	.L6
.L12:
	mov	w5, 2146435071
	cmp	w0, w5
	ble	.L14
	fsub	d18, d0, d0
	mov	w0, 0
	str	d18, [x19,8]
	str	d18, [x19]
	b	.L6
.L14:
	asr	w6, w0, 20
	sub	w2, w6, #1046
	mov	x7, 0
	sub	w8, w0, w2, lsl 20
	bfi	x7, x8, 32, 32
	bfi	x7, x3, 0, 32
	ldr	d2, .LC14
	fmov	d1, x7
	fcvtzs	w9, d1
	scvtf	d0, w9
	fsub	d3, d1, d0
	str	d0, [x29,72]
	fmul	d4, d3, d2
	fcvtzs	w10, d4
	scvtf	d5, w10
	fsub	d6, d4, d5
	str	d5, [x29,80]
	fmul	d7, d6, d2
	fcmp	d7, #0.0
	str	d7, [x29,88]
	bne	.L18
	fcmp	d5, #0.0
	mov	w11, 2
	csinc	w3, w11, wzr, ne
	b	.L15
.L18:
	mov	w3, 3
.L15:
	add	x21, x29, 48
	add	x0, x29, 72
	mov	x1, x21
	mov	w4, 1
	bl	__kernel_rem_pio2
	ld1	{v16.2d}, [x21]
	tbz	w20, #31, .L16
	fneg	v17.2d, v16.2d
	neg	w0, w0
	st1	{v17.2d}, [x19]
	b	.L6
.L16:
	st1	{v16.2d}, [x19]
.L6:
	ldp	x19, x20, [sp,16]
	ldr	x21, [sp,32]
	ldp	x29, x30, [sp], 96
	ret
	.size	__ieee754_rem_pio2, .-__ieee754_rem_pio2
	.align	3
.LC0:
	.word	1413480448
	.word	1073291771
	.align	3
.LC1:
	.word	442655537
	.word	1037087841
	.align	3
.LC2:
	.word	1413480448
	.word	1074340347
	.align	3
.LC3:
	.word	442655537
	.word	1038136417
	.align	3
.LC4:
	.word	2133852160
	.word	1074977148
	.align	3
.LC5:
	.word	-1483500342
	.word	1038683793
	.align	3
.LC6:
	.word	1413480448
	.word	1075388923
	.align	3
.LC7:
	.word	442655537
	.word	1039184993
	.align	3
.LC8:
	.word	1841940611
	.word	1071931184
	.align	3
.LC9:
	.word	0
	.word	1127743488
	.align	3
.LC10:
	.word	442499072
	.word	1037087841
	.align	3
.LC11:
	.word	771977331
	.word	1000544650
	.align	3
.LC12:
	.word	771751936
	.word	1000544650
	.align	3
.LC13:
	.word	622873025
	.word	964395930
	.align	3
.LC14:
	.word	0
	.word	1097859072
	.ident	"GCC: (crosstool-NG linaro-1.13.1-4.8-2014.04 - Linaro GCC 4.8-2014.04) 4.8.3 20140401 (prerelease)"
