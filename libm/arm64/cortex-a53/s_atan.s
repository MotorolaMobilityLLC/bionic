	.cpu cortex-a53+fp+simd
	.section	.text.hot,"ax",%progbits
	.align	2
	.global	atan
	.type	atan, %function
atan:
	fmov	x1, d0
	mov	w2, 1072889855
	ubfx	x3, x1, 32, 32
	and	w0, w3, 2147483647
	cmp	w0, w2
	fabs	d1, d0
	ble	.L2
	fmov	d21, 1.5e+0
	fmov	d23, 1.0e+0
	fmul	d22, d1, d21
	fsub	d2, d1, d21
	mov	w7, 32767
	movk	w7, 0x4003, lsl 16
	fadd	d17, d22, d23
	cmp	w0, w7
	fdiv	d24, d2, d17
	bgt	.L3
	fmul	d23, d24, d24
	ldr	d25, .LC0
	ldr	d0, .LC1
	ldr	d27, .LC6
	fmul	d17, d23, d23
	ldr	d4, .LC7
	ldr	d5, .LC2
	ldr	d18, .LC8
	fmul	d1, d17, d25
	fmul	d28, d17, d27
	ldr	d20, .LC3
	ldr	d22, .LC9
	fadd	d26, d1, d0
	fsub	d16, d28, d4
	ldr	d1, .LC4
	ldr	d28, .LC10
	fmul	d3, d26, d17
	fmul	d7, d16, d17
	ldr	d4, .LC5
	fadd	d31, d3, d5
	fsub	d19, d7, d18
	ldr	d5, .LC11
	ldr	d18, .LC12
	fmul	d30, d31, d17
	fmul	d6, d19, d17
	fadd	d21, d30, d20
	fsub	d29, d6, d22
	fmul	d2, d21, d17
	fmul	d25, d29, d17
	fadd	d27, d2, d1
	fsub	d0, d25, d28
	fmul	d26, d27, d17
	fmul	d17, d0, d17
	fadd	d16, d26, d4
	fmul	d23, d16, d23
	fadd	d3, d23, d17
	fmul	d7, d3, d24
	fsub	d31, d7, d5
	fsub	d24, d31, d24
	fsub	d0, d18, d24
	tbnz	w3, #31, .L24
.L1:
	ret
.L2:
	fmov	d3, 1.0e+0
	mov	w4, 1072037887
	fsub	d4, d1, d3
	fadd	d2, d1, d3
	cmp	w0, w4
	fdiv	d6, d4, d2
	ble	.L10
	fmul	d16, d6, d6
	ldr	d27, .LC0
	ldr	d30, .LC1
	ldr	d0, .LC6
	fmul	d26, d16, d16
	ldr	d5, .LC7
	ldr	d18, .LC2
	ldr	d20, .LC8
	fmul	d28, d26, d27
	fmul	d29, d26, d0
	ldr	d23, .LC3
	ldr	d24, .LC9
	fadd	d31, d28, d30
	fsub	d4, d29, d5
	ldr	d28, .LC4
	ldr	d29, .LC10
	fmul	d3, d31, d26
	fmul	d7, d4, d26
	ldr	d5, .LC5
	fadd	d19, d3, d18
	fsub	d21, d7, d20
	ldr	d18, .LC16
	ldr	d20, .LC17
	fmul	d2, d19, d26
	fmul	d22, d21, d26
	fadd	d17, d2, d23
	fsub	d1, d22, d24
	fmul	d25, d17, d26
	fmul	d27, d1, d26
	fadd	d0, d25, d28
	fsub	d30, d27, d29
	fmul	d31, d0, d26
	fmul	d26, d30, d26
	fadd	d4, d31, d5
	fmul	d16, d4, d16
	fadd	d3, d16, d26
	fmul	d7, d3, d6
	fsub	d19, d7, d18
	fsub	d6, d19, d6
	fsub	d0, d20, d6
	tbz	w3, #31, .L1
.L24:
	fneg	d28, d0
	b	.L5
.L10:
	mov	w5, 1071382527
	cmp	w0, w5
	ble	.L12
	fadd	d0, d1, d1
	fmov	d29, 2.0e+0
	ldr	d18, .LC1
	fadd	d30, d1, d29
	fsub	d31, d0, d3
	ldr	d3, .LC0
	ldr	d5, .LC6
	ldr	d20, .LC7
	fdiv	d1, d31, d30
	ldr	d17, .LC2
	ldr	d25, .LC8
	ldr	d28, .LC3
	ldr	d29, .LC9
	fmul	d2, d1, d1
	fmul	d6, d2, d2
	fmul	d4, d6, d3
	fmul	d7, d6, d5
	ldr	d3, .LC4
	fadd	d19, d4, d18
	fsub	d21, d7, d20
	ldr	d7, .LC10
	ldr	d20, .LC5
	fmul	d22, d19, d6
	fmul	d23, d21, d6
	fadd	d24, d22, d17
	fsub	d16, d23, d25
	ldr	d17, .LC18
	ldr	d25, .LC19
	fmul	d26, d24, d6
	fmul	d27, d16, d6
	fadd	d0, d26, d28
	fsub	d30, d27, d29
	fmul	d31, d0, d6
	fmul	d5, d30, d6
	fadd	d4, d31, d3
	fsub	d18, d5, d7
	fmul	d19, d4, d6
	fmul	d6, d18, d6
	fadd	d21, d19, d20
	fmul	d2, d21, d2
	fadd	d22, d2, d6
	fmul	d23, d22, d1
	fsub	d24, d23, d17
	fsub	d1, d24, d1
	fsub	d28, d25, d1
	tbnz	w3, #31, .L23
.L5:
	fmov	d0, d28
	ret
.L3:
	mov	w8, 1141899263
	cmp	w0, w8
	bgt	.L6
	fmov	d0, -1.0e+0
	ldr	d26, .LC0
	fdiv	d29, d0, d1
	ldr	d3, .LC1
	ldr	d5, .LC6
	ldr	d18, .LC7
	ldr	d21, .LC2
	ldr	d2, .LC8
	ldr	d25, .LC3
	ldr	d27, .LC9
	fmul	d30, d29, d29
	fmul	d31, d30, d30
	fmul	d4, d31, d26
	fmul	d16, d31, d5
	ldr	d5, .LC10
	fadd	d7, d4, d3
	fsub	d19, d16, d18
	ldr	d4, .LC4
	ldr	d18, .LC5
	fmul	d6, d7, d31
	fmul	d20, d19, d31
	fadd	d22, d6, d21
	fsub	d23, d20, d2
	ldr	d21, .LC13
	ldr	d2, .LC14
	fmul	d17, d22, d31
	fmul	d24, d23, d31
	fadd	d1, d17, d25
	fsub	d28, d24, d27
	fmul	d0, d1, d31
	fmul	d26, d28, d31
	fadd	d16, d0, d4
	fsub	d3, d26, d5
	fmul	d7, d16, d31
	fmul	d31, d3, d31
	fadd	d19, d7, d18
	fmul	d30, d19, d30
	fadd	d6, d30, d31
	fmul	d20, d6, d29
	fsub	d22, d20, d21
	fsub	d29, d22, d29
	fsub	d28, d2, d29
	tbz	w3, #31, .L5
.L23:
	fneg	d28, d28
	b	.L5
.L12:
	mov	w6, 1044381695
	cmp	w0, w6
	bgt	.L13
	ldr	d5, .LC20
	fmov	d28, d0
	fadd	d7, d0, d5
	fcmpe	d7, d3
	bgt	.L5
.L13:
	fmul	d16, d0, d0
	ldr	d18, .LC0
	ldr	d22, .LC1
	ldr	d20, .LC6
	fmul	d17, d16, d16
	ldr	d24, .LC7
	ldr	d28, .LC2
	ldr	d30, .LC8
	fmul	d19, d17, d18
	fmul	d21, d17, d20
	ldr	d3, .LC3
	ldr	d6, .LC9
	fadd	d23, d19, d22
	fsub	d25, d21, d24
	ldr	d19, .LC4
	ldr	d21, .LC10
	fmul	d26, d23, d17
	fmul	d27, d25, d17
	ldr	d24, .LC5
	fadd	d29, d26, d28
	fsub	d31, d27, d30
	fmul	d1, d29, d17
	fmul	d2, d31, d17
	fadd	d4, d1, d3
	fsub	d5, d2, d6
	fmul	d7, d4, d17
	fmul	d18, d5, d17
	fadd	d20, d7, d19
	fsub	d22, d18, d21
	fmul	d23, d20, d17
	fmul	d17, d22, d17
	fadd	d25, d23, d24
	fmul	d16, d25, d16
	fadd	d26, d16, d17
	fmul	d27, d26, d0
	fsub	d28, d0, d27
	b	.L5
.L6:
	mov	w9, 2146435072
	cmp	w0, w9
	bgt	.L7
	beq	.L26
.L8:
	cmp	w3, wzr
	adrp	x11, .LANCHOR0
	add	x12, x11, :lo12:.LANCHOR0
	ble	.L9
	ldr	d27, [x12]
	ldr	d28, .LC14
	fadd	d28, d27, d28
	b	.L5
.L26:
	cbz	w1, .L8
.L7:
	fadd	d28, d0, d0
	b	.L5
.L9:
	ldr	d25, [x12]
	ldr	d1, .LC15
	fsub	d28, d1, d25
	b	.L5
	.size	atan, .-atan
	.align	3
.LC0:
	.word	-484255215
	.word	1066446138
	.align	3
.LC1:
	.word	611716587
	.word	1068071755
	.align	3
.LC2:
	.word	-1596965551
	.word	1068567910
	.align	3
.LC3:
	.word	-984866706
	.word	1068975565
	.align	3
.LC4:
	.word	-1845459969
	.word	1069697316
	.align	3
.LC5:
	.word	1431655693
	.word	1070945621
	.align	3
.LC6:
	.word	745172015
	.word	-1079856060
	.align	3
.LC7:
	.word	1390345626
	.word	1068359213
	.align	3
.LC8:
	.word	-1351312787
	.word	1068740850
	.align	3
.LC9:
	.word	-31254927
	.word	1069314502
	.align	3
.LC10:
	.word	-1718031420
	.word	1070176665
	.align	3
.LC11:
	.word	2062601149
	.word	1013974920
	.align	3
.LC12:
	.word	-763234661
	.word	1072657163
	.align	3
.LC13:
	.word	856972295
	.word	1016178214
	.align	3
.LC14:
	.word	1413754136
	.word	1073291771
	.align	3
.LC15:
	.word	1413754136
	.word	-1074191877
	.align	3
.LC16:
	.word	856972295
	.word	1015129638
	.align	3
.LC17:
	.word	1413754136
	.word	1072243195
	.align	3
.LC18:
	.word	573531618
	.word	1014639487
	.align	3
.LC19:
	.word	90291023
	.word	1071492199
	.align	3
.LC20:
	.word	-2013235812
	.word	2117592124
	.section	.rodata
	.align	3
.LANCHOR0 = . + 0
	.type	atanlo_3, %object
	.size	atanlo_3, 8
atanlo_3:
	.word	856972295
	.word	1016178214
	.ident	"GCC: (crosstool-NG linaro-1.13.1-4.8-2014.04 - Linaro GCC 4.8-2014.04) 4.8.3 20140401 (prerelease)"
#if (LDBL_MANT_DIG == 53)
    .weak   atanl
    .equ    atanl, atan
#endif
