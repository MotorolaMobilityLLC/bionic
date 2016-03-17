	.cpu cortex-a53+fp+simd
	.section	.text.unlikely,"ax",%progbits
	.align	2
	.global	cos_kernel
	.type	cos_kernel, %function
cos_kernel:
	stp	x29, x30, [sp, -80]!
	fmov	x3, d0
	mov	w1, 8699
	add	x29, sp, 0
	movk	w1, 0x3fe9, lsl 16
	ubfx	x0, x3, 32, 31
	str	x19, [sp,16]
	cmp	w0, w1
	fmov	d3, d0
	bgt	.L2
	mov	w7, 41117
	movk	w7, 0x3e46, lsl 16
	cmp	w0, w7
	fmov	d16, 1.0e+0
	bgt	.L3
	fcvtzs	w8, d0
	fmov	d0, d16
	cbz	w8, .L4
.L3:
	fmul	d4, d3, d3
	ldr	d1, .LC0
	ldr	d6, .LC3
	ldr	d5, .LC1
	fmul	d7, d4, d1
	fmul	d19, d4, d6
	ldr	d23, .LC4
	fmul	d0, d4, d4
	fsub	d22, d7, d5
	fadd	d24, d19, d23
	ldr	d27, .LC2
	ldr	d29, .LC5
	fmul	d25, d22, d4
	fmul	d26, d24, d4
	fmul	d20, d0, d0
	fmov	d31, 5.0e-1
	fadd	d28, d25, d27
	fsub	d30, d26, d29
	fmul	d21, d4, d31
	fmov	d2, xzr
	fmul	d18, d28, d4
	fmul	d17, d20, d30
	fsub	d1, d16, d21
	fmul	d3, d3, d2
	fadd	d7, d18, d17
	fsub	d16, d16, d1
	fmul	d4, d4, d7
	fsub	d6, d16, d21
	fsub	d19, d4, d3
	fadd	d0, d6, d19
	fadd	d0, d0, d1
	b	.L4
.L2:
	mov	w4, 2146435071
	cmp	w0, w4
	ble	.L5
	fsub	d0, d0, d0
	b	.L4
.L5:
	mov	w2, 27258
	ubfx	x19, x3, 32, 32
	movk	w2, 0x400f, lsl 16
	and	w5, w19, 2147483647
	cmp	w5, w2
	bgt	.L6
	mov	w17, 8699
	and	w18, w19, 1048575
	movk	w17, 0x9, lsl 16
	cmp	w18, w17
	beq	.L7
	mov	w30, 55676
	movk	w30, 0x4002, lsl 16
	cmp	w5, w30
	bgt	.L8
	cmp	w19, wzr
	ldr	d5, .LC6
	ldr	d6, .LC7
	ble	.L9
	fsub	d18, d0, d5
	mov	w0, 1
	fsub	d17, d18, d6
	fsub	d19, d18, d17
	fsub	d18, d19, d6
	b	.L10
.L9:
	fadd	d7, d0, d5
	mov	w0, -1
	fadd	d17, d7, d6
	fsub	d16, d7, d17
	fadd	d18, d16, d6
	b	.L10
.L8:
	cmp	w19, wzr
	ldr	d31, .LC8
	ldr	d2, .LC9
	ble	.L11
	fsub	d0, d0, d31
	mov	w0, 2
	fsub	d17, d0, d2
	fsub	d4, d0, d17
	fsub	d18, d4, d2
	b	.L10
.L11:
	fadd	d3, d0, d31
	mov	w0, -2
	fadd	d17, d3, d2
	fsub	d1, d3, d17
	fadd	d18, d1, d2
	b	.L10
.L6:
	mov	w6, 17979
	movk	w6, 0x401c, lsl 16
	cmp	w5, w6
	bgt	.L12
	mov	w14, 64956
	movk	w14, 0x4015, lsl 16
	cmp	w5, w14
	bgt	.L13
	mov	w16, 55676
	movk	w16, 0x4012, lsl 16
	cmp	w5, w16
	beq	.L7
	cmp	w19, wzr
	ldr	d25, .LC10
	ldr	d26, .LC11
	ble	.L14
	fsub	d29, d0, d25
	mov	w0, 3
	fsub	d17, d29, d26
	fsub	d30, d29, d17
	fsub	d18, d30, d26
	b	.L10
.L14:
	fadd	d27, d0, d25
	mov	w0, -3
	fadd	d17, d27, d26
	fsub	d28, d27, d17
	fadd	d18, d28, d26
	b	.L10
.L13:
	mov	w15, 8699
	movk	w15, 0x4019, lsl 16
	cmp	w5, w15
	beq	.L7
	cmp	w19, wzr
	ldr	d19, .LC12
	ldr	d20, .LC13
	ble	.L15
	fsub	d23, d0, d19
	mov	w0, 4
	fsub	d17, d23, d20
	fsub	d24, d23, d17
	fsub	d18, d24, d20
	b	.L10
.L15:
	fadd	d21, d0, d19
	mov	w0, -4
	fadd	d17, d21, d20
	fsub	d22, d21, d17
	fadd	d18, d22, d20
	b	.L10
.L12:
	mov	w7, 8698
	movk	w7, 0x4139, lsl 16
	cmp	w5, w7
	bgt	.L16
.L7:
	ldr	d20, .LC14
	ldr	d17, .LC15
	fmul	d21, d3, d20
	ldr	d24, .LC6
	ldr	d26, .LC7
	asr	w1, w5, 20
	fadd	d22, d21, d17
	fsub	d23, d22, d17
	fmul	d25, d23, d24
	fmul	d18, d23, d26
	fcvtzs	w0, d23
	fsub	d0, d3, d25
	fsub	d17, d0, d18
	fmov	x3, d17
	ubfx	x4, x3, 52, 11
	sub	w2, w1, w4
	cmp	w2, 16
	ble	.L17
	ldr	d27, .LC16
	ldr	d29, .LC17
	fmul	d28, d23, d27
	fmul	d30, d23, d29
	fsub	d31, d0, d28
	fsub	d2, d0, d31
	fmov	d0, d31
	fsub	d3, d2, d28
	fsub	d18, d30, d3
	fsub	d17, d31, d18
	fmov	x19, d17
	ubfx	x5, x19, 52, 11
	sub	w6, w1, w5
	cmp	w6, 49
	ble	.L17
	ldr	d1, .LC18
	ldr	d4, .LC19
	fmul	d6, d23, d1
	fmul	d7, d23, d4
	fsub	d0, d31, d6
	fsub	d5, d31, d0
	fsub	d16, d5, d6
	fsub	d18, d7, d16
	fsub	d17, d0, d18
.L17:
	fsub	d19, d0, d17
	fsub	d18, d19, d18
	b	.L10
.L16:
	cmp	w5, w4
	ble	.L18
	fsub	d18, d0, d0
	mov	w0, 0
	fmov	d17, d18
	b	.L10
.L18:
	asr	w8, w5, 20
	sub	w2, w8, #1046
	mov	x9, 0
	sub	w10, w5, w2, lsl 20
	bfi	x9, x10, 32, 32
	bfi	x9, x3, 0, 32
	ldr	d2, .LC20
	fmov	d1, x9
	fcvtzs	w11, d1
	scvtf	d0, w11
	fsub	d4, d1, d0
	str	d0, [x29,56]
	fmul	d5, d4, d2
	fcvtzs	w12, d5
	scvtf	d6, w12
	fsub	d7, d5, d6
	str	d6, [x29,64]
	fmul	d16, d7, d2
	fcmp	d16, #0.0
	str	d16, [x29,72]
	bne	.L27
	fcmp	d6, #0.0
	mov	w13, 2
	csinc	w3, w13, wzr, ne
	b	.L19
.L27:
	mov	w3, 3
.L19:
	add	x0, x29, 56
	add	x1, x29, 32
	mov	w4, 1
	bl	__kernel_rem_pio2
	ldr	d17, [x29,32]
	ldr	d18, [x29,40]
	tbz	w19, #31, .L10
	fneg	d17, d17
	fneg	d18, d18
	neg	w0, w0
.L10:
	and	w0, w0, 3
	cmp	w0, 1
	fmov	d20, 5.0e-1
	fmul	d21, d17, d17
	beq	.L22
	cmp	w0, 2
	beq	.L23
	cbnz	w0, .L30
	ldr	d23, .LC0
	ldr	d25, .LC3
	fmul	d24, d21, d23
	fmul	d26, d21, d25
	ldr	d27, .LC1
	ldr	d29, .LC4
	fsub	d28, d24, d27
	fadd	d30, d26, d29
	fmul	d31, d21, d21
	ldr	d6, .LC2
	fmul	d2, d28, d21
	fmul	d3, d30, d21
	ldr	d7, .LC5
	fmul	d1, d31, d31
	fadd	d4, d2, d6
	fsub	d16, d3, d7
	fmul	d0, d21, d20
	fmov	d5, 1.0e+0
	fmul	d19, d4, d21
	fmul	d20, d1, d16
	fsub	d22, d5, d0
	fmul	d17, d18, d17
	fadd	d18, d19, d20
	fsub	d23, d5, d22
	fmul	d21, d21, d18
	fsub	d24, d23, d0
	fsub	d25, d21, d17
	fadd	d26, d24, d25
	fadd	d0, d26, d22
	b	.L4
.L22:
	ldr	d2, .LC21
	ldr	d4, .LC24
	fmul	d3, d21, d2
	ldr	d7, .LC22
	fmul	d1, d21, d21
	fmul	d16, d21, d4
	fsub	d6, d3, d7
	ldr	d19, .LC25
	fmul	d0, d21, d1
	fsub	d5, d16, d19
	fmul	d22, d6, d21
	ldr	d25, .LC23
	fmul	d23, d21, d17
	fmul	d24, d0, d5
	fadd	d26, d22, d25
	fmul	d20, d18, d20
	ldr	d28, .LC26
	fadd	d27, d26, d24
	fmul	d29, d23, d28
	fmul	d30, d23, d27
	fsub	d31, d20, d30
	fmul	d21, d31, d21
	fsub	d18, d21, d18
	fadd	d2, d18, d29
	fsub	d17, d17, d2
	fneg	d0, d17
	b	.L4
.L23:
	ldr	d27, .LC0
	ldr	d29, .LC3
	fmul	d28, d21, d27
	fmul	d30, d21, d29
	ldr	d31, .LC1
	ldr	d3, .LC4
	fsub	d2, d28, d31
	fadd	d1, d30, d3
	fmul	d4, d21, d21
	ldr	d0, .LC2
	fmul	d7, d2, d21
	fmul	d6, d1, d21
	ldr	d5, .LC5
	fmul	d16, d4, d4
	fadd	d19, d7, d0
	fsub	d22, d6, d5
	fmul	d20, d21, d20
	fmov	d23, 1.0e+0
	fmul	d24, d19, d21
	fmul	d25, d16, d22
	fsub	d26, d23, d20
	fmul	d17, d18, d17
	fadd	d18, d24, d25
	fsub	d27, d23, d26
	fmul	d21, d21, d18
	fsub	d28, d27, d20
	fsub	d29, d21, d17
	fadd	d30, d28, d29
	fadd	d31, d30, d26
	fneg	d0, d31
	b	.L4
.L30:
	ldr	d22, .LC21
	ldr	d25, .LC24
	fmul	d23, d21, d22
	ldr	d27, .LC22
	fmul	d24, d21, d21
	fmul	d26, d21, d25
	fsub	d28, d23, d27
	ldr	d30, .LC25
	fmul	d29, d21, d24
	fsub	d31, d26, d30
	fmul	d2, d28, d21
	ldr	d6, .LC23
	fmul	d3, d21, d17
	fmul	d1, d29, d31
	fadd	d4, d2, d6
	fmul	d7, d18, d20
	ldr	d5, .LC26
	fadd	d0, d4, d1
	fmul	d16, d3, d5
	fmul	d19, d3, d0
	fsub	d20, d7, d19
	fmul	d21, d20, d21
	fsub	d18, d21, d18
	fadd	d22, d18, d16
	fsub	d0, d17, d22
.L4:
	ldr	x19, [sp,16]
	ldp	x29, x30, [sp], 80
	ret
	.size	cos_kernel, .-cos_kernel
	.align	3
.LC0:
	.word	432739728
	.word	1056571808
	.align	3
.LC1:
	.word	381768055
	.word	1062650220
	.align	3
.LC2:
	.word	1431655756
	.word	1067799893
	.align	3
.LC3:
	.word	-1098368812
	.word	-1112999191
	.align	3
.LC4:
	.word	-1112231484
	.word	1042411166
	.align	3
.LC5:
	.word	-2137238867
	.word	1049787983
	.align	3
.LC6:
	.word	1413480448
	.word	1073291771
	.align	3
.LC7:
	.word	442655537
	.word	1037087841
	.align	3
.LC8:
	.word	1413480448
	.word	1074340347
	.align	3
.LC9:
	.word	442655537
	.word	1038136417
	.align	3
.LC10:
	.word	2133852160
	.word	1074977148
	.align	3
.LC11:
	.word	-1483500342
	.word	1038683793
	.align	3
.LC12:
	.word	1413480448
	.word	1075388923
	.align	3
.LC13:
	.word	442655537
	.word	1039184993
	.align	3
.LC14:
	.word	1841940611
	.word	1071931184
	.align	3
.LC15:
	.word	0
	.word	1127743488
	.align	3
.LC16:
	.word	442499072
	.word	1037087841
	.align	3
.LC17:
	.word	771977331
	.word	1000544650
	.align	3
.LC18:
	.word	771751936
	.word	1000544650
	.align	3
.LC19:
	.word	622873025
	.word	964395930
	.align	3
.LC20:
	.word	0
	.word	1097859072
	.align	3
.LC21:
	.word	1471282813
	.word	1053236707
	.align	3
.LC22:
	.word	432103893
	.word	1059717536
	.align	3
.LC23:
	.word	286324902
	.word	1065423121
	.align	3
.LC24:
	.word	1523570044
	.word	1038473530
	.align	3
.LC25:
	.word	-1976853269
	.word	1046144486
	.align	3
.LC26:
	.word	1431655753
	.word	1069897045
	.ident	"GCC: (crosstool-NG linaro-1.13.1-4.8-2014.04 - Linaro GCC 4.8-2014.04) 4.8.3 20140401 (prerelease)"
