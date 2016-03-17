	.cpu cortex-a53+fp+simd
	.file	"e_pow_kernel.c"
	.text
	.align	2
	.global	pow_kernel
	.type	pow_kernel, %function
pow_kernel:
	stp	x29, x30, [sp, -32]!
	fmov	x4, d0
	fmov	x0, d1
	add	x29, sp, 0
	ubfx	x3, x4, 32, 32
	ubfx	x1, x0, 32, 32
	str	d8, [sp,16]
	and	w5, w3, 2147483647
	and	w2, w1, 2147483647
	cbnz	w0, .L2
	fmov	d2, 1.0e+0
	cbnz	w2, .L122
.L3:
	fmov	d0, d2
	ldr	d8, [sp,16]
	ldp	x29, x30, [sp], 32
	ret
.L2:
	mov	w14, 65534
	sub	w15, w3, #1
	movk	w14, 0x7fef, lsl 16
	cmp	w15, w14
	bhi	.L123
.L13:
	mov	w16, 1139802112
	cmp	w2, w16
	bgt	.L14
	mov	w17, 1048575
	cmp	w5, w17
	ble	.L124
	asr	w30, w5, 20
	sub	w7, w30, #1023
.L16:
	mov	w4, 46713
	and	w0, w5, 1048575
	movk	w4, 0xb, lsl 16
	cmp	w0, w4
	fmov	x2, d0
	orr	w9, w0, 1072693248
	bgt	.L125
	mov	w3, 39054
	movk	w3, 0x3, lsl 16
	bfi	x2, x9, 32, 32
	cmp	w0, w3
	fmov	d5, x2
	ble	.L18
	fmov	d16, 1.5e+0
	fmov	d20, 1.0e+0
	fadd	d21, d5, d16
	fsub	d19, d5, d16
	ldr	d22, .LC1
	ldr	d8, .LC2
	fdiv	d25, d20, d21
	fmov	x1, d21
	ldr	d21, .LC3
	and	x10, x1, -4294967296
	fmov	d27, 3.0e+0
	fmov	d23, x10
	scvtf	d24, w7
	ldr	d7, .LC11
	fsub	d4, d23, d16
	fadd	d31, d24, d7
	fsub	d0, d5, d4
	fmul	d28, d19, d25
	fmul	d26, d28, d28
	fmov	x18, d28
	and	x5, x18, -4294967296
	fmul	d17, d26, d22
	fmov	d3, x5
	fmul	d29, d26, d26
	fadd	d2, d17, d8
	fmul	d30, d3, d23
	fmul	d5, d3, d0
	ldr	d0, .LC4
	fmul	d18, d2, d26
	fsub	d6, d19, d30
	ldr	d30, .LC5
	fmul	d16, d3, d3
	fadd	d19, d18, d21
	fsub	d23, d6, d5
	ldr	d5, .LC6
	fadd	d20, d16, d27
	fmul	d4, d19, d26
	fmul	d25, d23, d25
	fadd	d22, d4, d0
	fmul	d17, d25, d3
	fmul	d2, d25, d28
	fmul	d8, d22, d26
	fadd	d6, d17, d2
	ldr	d2, .LC7
	fadd	d18, d8, d30
	ldr	d8, .LC9
	fmul	d26, d18, d26
	fadd	d21, d26, d5
	ldr	d26, .LC10
	fmul	d5, d29, d21
	fadd	d29, d6, d5
	fadd	d19, d20, d29
	fmov	x11, d19
	and	x12, x11, -4294967296
	fmov	d20, x12
	fsub	d27, d20, d27
	fmul	d23, d25, d20
	fmul	d3, d3, d20
	fsub	d16, d27, d16
	fsub	d4, d29, d16
	ldr	d29, .LC8
	fmul	d28, d28, d4
	fadd	d25, d23, d28
	fadd	d0, d3, d25
	fmov	x13, d0
	and	x14, x13, -4294967296
	fmov	d22, x14
	fsub	d17, d22, d3
	fmul	d30, d22, d8
	fmul	d18, d22, d2
	fsub	d6, d25, d17
	fadd	d21, d30, d26
	fadd	d31, d31, d18
	fmul	d19, d6, d29
	fadd	d20, d21, d19
	fadd	d27, d31, d20
	fmov	x15, d27
	and	x16, x15, -4294967296
	fmov	d16, x16
	fsub	d24, d16, d24
	fsub	d7, d24, d7
	fsub	d23, d7, d18
	fsub	d7, d20, d23
.L19:
	fmov	x10, d1
	fmul	d23, d1, d7
	and	x18, x10, -4294967296
	mov	w13, 1071644672
	fmov	d2, x18
	fsub	d1, d1, d2
	fmul	d27, d2, d16
	fmul	d28, d1, d16
	fadd	d26, d28, d23
	fadd	d25, d26, d27
	fmov	x5, d25
	ubfx	x11, x5, 32, 32
	and	w12, w11, 2147483647
	cmp	w12, w13
	ble	.L66
	mov	w14, 1083179007
	cmp	w12, w14
	bgt	.L126
.L21:
	asr	w4, w12, 20
	sub	w0, w4, #1022
	mov	w2, 1048576
	asr	w9, w2, w0
	add	w1, w9, w11
	ubfx	x10, x1, 20, 11
	mov	w5, 1048575
	sub	w18, w10, #1023
	fmov	x3, d5
	asr	w12, w5, w18
	bic	w13, w1, w12
	bfi	x3, x13, 32, 32
	cmp	w11, wzr
	and	x11, x3, -4294967296
	and	w14, w1, w5
	fmov	d5, x11
	mov	w16, 1043
	orr	w15, w14, 1048576
	sub	w17, w16, w10
	fsub	d27, d27, d5
	asr	w6, w15, w17
	csneg	w0, w6, w6, ge
	fadd	d25, d26, d27
.L20:
	fmov	x7, d25
	ldr	d17, .LC16
	and	x8, x7, -4294967296
	ldr	d19, .LC15
	fmov	d18, x8
	ldr	d6, .LC14
	ldr	d23, .LC17
	ldr	d3, .LC19
	fsub	d8, d18, d27
	fmul	d29, d18, d17
	fmul	d21, d18, d6
	ldr	d27, .LC18
	fsub	d20, d26, d8
	ldr	d5, .LC20
	ldr	d17, .LC21
	fmul	d31, d20, d19
	fmov	d19, 2.0e+0
	fadd	d16, d31, d29
	fadd	d30, d21, d16
	fmul	d24, d30, d30
	fsub	d7, d30, d21
	fmul	d1, d24, d23
	fsub	d2, d16, d7
	fmov	d7, 1.0e+0
	fsub	d28, d1, d27
	fmul	d26, d30, d2
	fmul	d25, d28, d24
	fadd	d22, d26, d2
	fadd	d4, d25, d3
	fmul	d0, d4, d24
	fsub	d18, d0, d5
	fmul	d8, d18, d24
	fadd	d29, d8, d17
	fmul	d6, d29, d24
	fsub	d21, d30, d6
	fmul	d20, d30, d21
	fsub	d31, d21, d19
	fdiv	d16, d20, d31
	fsub	d24, d16, d22
	fsub	d30, d24, d30
	fsub	d0, d7, d30
	fmov	x4, d0
	ubfx	x2, x4, 32, 32
	add	w9, w2, w0, lsl 20
	asr	w1, w9, 20
	cmp	w1, wzr
	ble	.L127
	fmov	x0, d0
	bfi	x0, x9, 32, 32
	fmov	d2, x0
	b	.L3
.L122:
	mov	w6, 1072693248
	cmp	w3, w6
	beq	.L128
.L79:
	mov	w7, 2146435072
	cmp	w5, w7
	bgt	.L5
	beq	.L129
.L6:
	mov	w8, 2146435072
	cmp	w2, w8
	beq	.L130
	mov	w9, 1072693248
	cmp	w1, w9
	beq	.L65
	mov	w10, 1073741824
	cmp	w1, w10
	beq	.L131
	mov	w11, 1070596096
	cmp	w1, w11
	beq	.L132
	mov	w12, 1071644672
	cmp	w1, w12
	bne	.L12
	tbnz	w3, #31, .L2
	ldr	d8, [sp,16]
	ldp	x29, x30, [sp], 32
	b	sqrt
.L125:
	sub	w17, w9, #1048576
	bfi	x2, x17, 32, 32
	add	w7, w7, 1
	fmov	d5, x2
.L18:
	fmov	d28, 1.0e+0
	ldr	d8, .LC2
	fadd	d3, d5, d28
	fsub	d25, d5, d28
	scvtf	d30, w7
	ldr	d7, .LC3
	fdiv	d22, d28, d3
	fmov	x30, d3
	fmov	d16, 3.0e+0
	and	x6, x30, -4294967296
	fmov	d4, x6
	fsub	d0, d4, d28
	fsub	d17, d5, d0
	ldr	d5, .LC1
	fmul	d26, d25, d22
	fmul	d21, d26, d26
	fmov	x7, d26
	and	x8, x7, -4294967296
	fmul	d18, d21, d5
	fmov	d2, x8
	fmul	d31, d21, d21
	fadd	d6, d18, d8
	fmul	d29, d2, d4
	ldr	d4, .LC4
	fmul	d19, d2, d17
	fmul	d20, d6, d21
	fsub	d24, d25, d29
	ldr	d17, .LC5
	fmul	d27, d2, d2
	fadd	d23, d20, d7
	fsub	d3, d24, d19
	ldr	d20, .LC6
	fadd	d28, d27, d16
	fmul	d25, d23, d21
	fmul	d22, d3, d22
	fadd	d0, d25, d4
	fmul	d5, d22, d2
	fmul	d8, d22, d26
	fmul	d18, d0, d21
	ldr	d0, .LC7
	fadd	d6, d5, d8
	ldr	d8, .LC9
	fadd	d29, d18, d17
	fmul	d21, d29, d21
	fadd	d19, d21, d20
	ldr	d21, .LC8
	fmul	d5, d31, d19
	fadd	d31, d6, d5
	fadd	d24, d28, d31
	fmov	x4, d24
	and	x0, x4, -4294967296
	fmov	d7, x0
	fsub	d16, d7, d16
	fmul	d23, d22, d7
	fmul	d2, d2, d7
	fsub	d27, d16, d27
	fsub	d28, d31, d27
	fmul	d26, d26, d28
	fadd	d25, d23, d26
	fadd	d3, d2, d25
	fmov	x2, d3
	and	x9, x2, -4294967296
	fmov	d22, x9
	fsub	d4, d22, d2
	fmul	d18, d22, d0
	fmul	d17, d22, d8
	fsub	d29, d25, d4
	fadd	d6, d30, d18
	fmul	d20, d29, d21
	fadd	d19, d17, d20
	fadd	d31, d6, d19
	fmov	x3, d31
	and	x1, x3, -4294967296
	fmov	d16, x1
	fsub	d30, d16, d30
	fsub	d24, d30, d18
	fsub	d7, d19, d24
	b	.L19
.L66:
	mov	w0, 0
	b	.L20
.L131:
	fmul	d2, d0, d0
	b	.L3
.L65:
	fmov	d2, d0
	b	.L3
.L124:
	ldr	d18, .LC0
	fmul	d0, d0, d18
	fmov	x6, d0
	ubfx	x5, x6, 32, 32
	asr	w8, w5, 20
	sub	w7, w8, #1076
	b	.L16
.L12:
	mov	w13, -1074790400
	cmp	w1, w13
	bne	.L2
	fmov	d2, 1.0e+0
	fdiv	d2, d2, d0
	b	.L3
.L132:
	tbnz	w3, #31, .L2
	bl	sqrt
	ldr	d8, [sp,16]
	ldp	x29, x30, [sp], 32
	b	sqrt
.L127:
	ldr	d8, [sp,16]
	ldp	x29, x30, [sp], 32
	b	scalbn
.L126:
	cmp	w11, w14
	ble	.L22
	mov	w6, -1083179008
	add	w7, w11, w6
	orr	w8, w7, w5
	cbnz	w8, .L60
	ldr	d4, .LC13
	fsub	d22, d25, d27
	fadd	d0, d26, d4
	fcmpe	d0, d22
	ble	.L21
.L60:
	ldr	d23, .LC12
	fmul	d2, d23, d23
	b	.L3
.L22:
	mov	w15, 52223
	movk	w15, 0x4090, lsl 16
	cmp	w12, w15
	ble	.L21
	mov	w16, 13312
	movk	w16, 0x3f6f, lsl 16
	add	w17, w11, w16
	orr	w30, w17, w5
	cbnz	w30, .L9
	fsub	d3, d25, d27
	fcmpe	d26, d3
	bhi	.L21
.L9:
	fmov	d2, xzr
	b	.L3
.L123:
	cbnz	w3, .L14
	cbnz	w4, .L13
.L14:
	mov	w17, 2146435072
	cmp	w5, w17
	bgt	.L5
	cset	w18, eq
	cbnz	w18, .L133
.L80:
	mov	w30, 2146435072
	cmp	w2, w30
	bgt	.L5
	beq	.L134
.L81:
	mov	w14, 0
	tbnz	w3, #31, .L135
.L29:
	cbnz	w5, .L31
	cbz	w4, .L120
.L31:
	cbnz	w18, .L120
	tbnz	w3, #31, .L136
	mov	w4, -1139802112
	add	w3, w2, w4
	mov	w2, 1006632959
	cmp	w3, w2
	bhi	.L9
	fmov	d2, d0
	fmov	d0, 1.0e+0
	fcmp	d2, d0
	beq	.L3
	mov	w18, 1072693247
	cmp	w5, w18
	bgt	.L59
	tbz	w1, #31, .L9
	b	.L60
.L135:
	mov	w6, 1128267775
	cmp	w2, w6
	mov	w14, 2
	bgt	.L29
	mov	w7, 1072693247
	cmp	w2, w7
	mov	w14, 0
	ble	.L29
	asr	w8, w2, 20
	cmp	w8, 1043
	ble	.L30
	mov	w15, 1075
	sub	w16, w15, w8
	lsr	w17, w0, w16
	lsl	w30, w17, w16
	cmp	w30, w0
	bne	.L29
	and	w7, w17, 1
	mov	w6, 2
	sub	w14, w6, w7
	b	.L29
.L59:
	cmp	w1, wzr
	bgt	.L60
	b	.L9
.L136:
	cbz	w14, .L137
	cmp	w14, 1
	beq	.L75
	fmov	d8, 1.0e+0
.L39:
	mov	w8, 1139802112
	cmp	w2, w8
	bgt	.L40
	mov	w1, 1048575
	cmp	w5, w1
	fabs	d7, d0
	bgt	.L41
	ldr	d16, .LC0
	fmul	d7, d7, d16
	fmov	x5, d7
	ubfx	x5, x5, 32, 32
	asr	w12, w5, 20
	sub	w11, w12, #1076
.L42:
	mov	w13, 46713
	and	w14, w5, 1048575
	movk	w13, 0xb, lsl 16
	cmp	w14, w13
	fmov	x15, d7
	orr	w16, w14, 1072693248
	ble	.L43
	sub	w1, w16, #1048576
	bfi	x15, x1, 32, 32
	add	w11, w11, 1
	fmov	d21, x15
.L44:
	fmov	d5, 1.0e+0
	ldr	d16, .LC1
	fadd	d17, d21, d5
	fsub	d24, d21, d5
	ldr	d20, .LC2
	scvtf	d7, w11
	fdiv	d30, d5, d17
	fmov	x10, d17
	ldr	d3, .LC3
	and	x5, x10, -4294967296
	fmov	d31, 3.0e+0
	fmov	d6, x5
	fsub	d2, d6, d5
	fsub	d18, d21, d2
	fmul	d29, d24, d30
	fmul	d0, d29, d29
	fmov	x11, d29
	and	x12, x11, -4294967296
	fmul	d21, d0, d16
	fmov	d28, x12
	fmul	d22, d0, d0
	fadd	d19, d21, d20
	fmul	d4, d28, d6
	ldr	d6, .LC4
	fmul	d23, d28, d18
	fmul	d25, d19, d0
	fsub	d27, d24, d4
	ldr	d19, .LC5
	fmul	d26, d28, d28
	fadd	d5, d25, d3
	fsub	d24, d27, d23
	ldr	d23, .LC6
	fadd	d17, d26, d31
	fmul	d2, d5, d0
	fmul	d30, d24, d30
	fadd	d18, d2, d6
	fmul	d16, d30, d28
	fmul	d20, d30, d29
	fmul	d21, d18, d0
	fadd	d25, d16, d20
	fadd	d4, d21, d19
	ldr	d21, .LC7
	ldr	d19, .LC9
	fmul	d0, d4, d0
	fadd	d27, d0, d23
	ldr	d0, .LC8
	fmul	d5, d22, d27
	fadd	d22, d25, d5
	fadd	d3, d17, d22
	fmov	x13, d3
	and	x14, x13, -4294967296
	fmov	d24, x14
	fsub	d31, d24, d31
	fmul	d17, d30, d24
	fmul	d28, d28, d24
	fsub	d26, d31, d26
	fsub	d2, d22, d26
	fmul	d29, d29, d2
	fadd	d30, d17, d29
	fadd	d6, d28, d30
	fmov	x15, d6
	and	x16, x15, -4294967296
	fmov	d18, x16
	fsub	d16, d18, d28
	fmul	d20, d18, d21
	fmul	d25, d18, d19
	fsub	d4, d30, d16
	fadd	d23, d7, d20
	fmul	d27, d4, d0
	fadd	d22, d25, d27
	fadd	d3, d23, d22
	fmov	x17, d3
	and	x30, x17, -4294967296
	fmov	d24, x30
	fsub	d7, d24, d7
	fsub	d31, d7, d20
	fsub	d17, d22, d31
.L45:
	fmov	x7, d1
	fmul	d28, d1, d17
	and	x6, x7, -4294967296
	mov	w3, 1071644672
	fmov	d26, x6
	fsub	d1, d1, d26
	fmul	d29, d26, d24
	fmul	d2, d1, d24
	fadd	d30, d2, d28
	fadd	d6, d30, d29
	fmov	x4, d6
	ubfx	x18, x4, 32, 32
	and	w8, w18, 2147483647
	cmp	w8, w3
	ble	.L76
	mov	w2, 1083179007
	cmp	w8, w2
	ble	.L47
	cmp	w18, w2
	ble	.L48
	mov	w5, -1083179008
	add	w11, w18, w5
	orr	w12, w11, w4
	cbnz	w12, .L115
	ldr	d21, .LC13
	fsub	d16, d6, d29
	fadd	d20, d30, d21
	fcmpe	d20, d16
	bgt	.L115
.L47:
	asr	w13, w8, 20
	sub	w14, w13, #1022
	mov	w15, 1048576
	asr	w16, w15, w14
	add	w17, w16, w18
	ubfx	x30, x17, 20, 11
	mov	w8, 1048575
	sub	w6, w30, #1023
	fmov	x7, d5
	asr	w4, w8, w6
	bic	w3, w17, w4
	bfi	x7, x3, 32, 32
	cmp	w18, wzr
	and	x18, x7, -4294967296
	and	w2, w17, w8
	fmov	d19, x18
	mov	w9, 1043
	orr	w0, w2, 1048576
	sub	w1, w9, w30
	fsub	d29, d29, d19
	asr	w10, w0, w1
	csneg	w0, w10, w10, ge
	fadd	d6, d30, d29
.L46:
	fmov	x5, d6
	ldr	d4, .LC16
	and	x11, x5, -4294967296
	ldr	d3, .LC15
	fmov	d25, x11
	ldr	d27, .LC14
	ldr	d1, .LC17
	ldr	d21, .LC19
	fsub	d23, d25, d29
	fmul	d0, d25, d4
	fmul	d22, d25, d27
	ldr	d25, .LC20
	fsub	d24, d30, d23
	ldr	d30, .LC18
	fmul	d7, d24, d3
	fadd	d31, d7, d0
	ldr	d0, .LC21
	fmov	d7, 2.0e+0
	fadd	d17, d22, d31
	fmul	d28, d17, d17
	fsub	d26, d17, d22
	fmul	d29, d28, d1
	fsub	d2, d31, d26
	fmov	d1, 1.0e+0
	fsub	d6, d29, d30
	fmul	d18, d17, d2
	fmul	d5, d6, d28
	fadd	d16, d18, d2
	fadd	d20, d5, d21
	fmul	d19, d20, d28
	fsub	d23, d19, d25
	fmul	d4, d23, d28
	fadd	d27, d4, d0
	fmul	d22, d27, d28
	fsub	d24, d17, d22
	fmul	d3, d17, d24
	fsub	d31, d24, d7
	fdiv	d28, d3, d31
	fsub	d26, d28, d16
	fsub	d17, d26, d17
	fsub	d0, d1, d17
	fmov	x12, d0
	ubfx	x13, x12, 32, 32
	add	w14, w13, w0, lsl 20
	asr	w15, w14, 20
	cmp	w15, wzr
	ble	.L138
	fmov	x16, d0
	bfi	x16, x14, 32, 32
	fmov	d0, x16
.L55:
	fmul	d2, d0, d8
	b	.L3
.L76:
	mov	w0, 0
	b	.L46
.L138:
	bl	scalbn
	b	.L55
.L43:
	mov	w17, 39054
	movk	w17, 0x3, lsl 16
	bfi	x15, x16, 32, 32
	cmp	w14, w17
	fmov	d21, x15
	ble	.L44
	fmov	d17, 1.5e+0
	fmov	d19, 1.0e+0
	fadd	d18, d21, d17
	fsub	d20, d21, d17
	ldr	d2, .LC1
	ldr	d5, .LC2
	fdiv	d24, d19, d18
	fmov	x30, d18
	fmov	d25, 3.0e+0
	and	x7, x30, -4294967296
	scvtf	d26, w11
	fmov	d22, x7
	ldr	d27, .LC11
	fadd	d29, d26, d27
	fsub	d23, d22, d17
	fsub	d28, d21, d23
	fmul	d30, d20, d24
	fmul	d31, d30, d30
	fmov	x6, d30
	and	x4, x6, -4294967296
	fmul	d0, d31, d2
	fmov	d3, x4
	ldr	d2, .LC4
	fmul	d4, d31, d31
	fadd	d7, d0, d5
	fmul	d6, d3, d22
	fmul	d21, d3, d28
	fmul	d17, d3, d3
	fmul	d16, d7, d31
	fsub	d18, d20, d6
	ldr	d20, .LC3
	fadd	d22, d17, d25
	fadd	d19, d16, d20
	ldr	d16, .LC5
	fsub	d28, d18, d21
	ldr	d20, .LC6
	fmul	d23, d19, d31
	fmul	d24, d28, d24
	fadd	d0, d23, d2
	fmul	d5, d24, d3
	fmul	d6, d24, d30
	fmul	d7, d0, d31
	fadd	d18, d5, d6
	fadd	d21, d7, d16
	ldr	d16, .LC9
	fmul	d31, d21, d31
	fadd	d19, d31, d20
	fmul	d5, d4, d19
	ldr	d19, .LC8
	fadd	d4, d18, d5
	ldr	d18, .LC7
	fadd	d22, d22, d4
	fmov	x3, d22
	and	x2, x3, -4294967296
	fmov	d28, x2
	fsub	d25, d28, d25
	fmul	d23, d24, d28
	fmul	d3, d3, d28
	ldr	d28, .LC10
	fsub	d17, d25, d17
	fsub	d24, d4, d17
	fmul	d30, d30, d24
	fadd	d7, d23, d30
	fadd	d2, d3, d7
	fmov	x18, d2
	and	x8, x18, -4294967296
	fmov	d0, x8
	fsub	d6, d0, d3
	fmul	d21, d0, d16
	fmul	d31, d0, d18
	fsub	d20, d7, d6
	fadd	d29, d29, d31
	fmul	d4, d20, d19
	fadd	d22, d21, d4
	fadd	d25, d22, d28
	fadd	d23, d29, d25
	fmov	x0, d23
	and	x9, x0, -4294967296
	fmov	d24, x9
	fsub	d26, d24, d26
	fsub	d27, d26, d27
	fsub	d3, d27, d31
	fsub	d17, d25, d3
	b	.L45
.L41:
	asr	w10, w5, 20
	sub	w11, w10, #1023
	b	.L42
.L40:
	mov	w0, 2146435072
	cmp	w2, w0
	beq	.L9
	fmov	d1, -1.0e+0
	fmov	d2, d8
	fcmp	d0, d1
	beq	.L3
	mov	w9, 1072693247
	cmp	w5, w9
	bgt	.L56
	tbnz	w1, #31, .L114
.L58:
	ldr	d3, .LC22
	fmul	d4, d2, d3
	fmul	d2, d4, d3
	b	.L3
.L75:
	fmov	d8, -1.0e+0
	b	.L39
.L56:
	cmp	w1, wzr
	ble	.L58
.L114:
	ldr	d5, .LC12
	fmul	d6, d2, d5
	fmul	d2, d6, d5
	b	.L3
.L137:
	fsub	d2, d0, d0
	fdiv	d2, d2, d2
	b	.L3
.L30:
	cbnz	w0, .L29
	mov	w0, 1043
	sub	w9, w0, w8
	asr	w10, w2, w9
	lsl	w11, w10, w9
	cmp	w11, w2
	bne	.L29
	and	w12, w10, 1
	mov	w13, 2
	sub	w14, w13, w12
	b	.L29
.L115:
	ldr	d29, .LC12
	fmul	d8, d8, d29
	fmul	d2, d8, d29
	b	.L3
.L48:
	mov	w0, 52223
	movk	w0, 0x4090, lsl 16
	cmp	w8, w0
	ble	.L47
	mov	w9, 13312
	movk	w9, 0x3f6f, lsl 16
	add	w1, w18, w9
	orr	w10, w1, w4
	cbnz	w10, .L116
	fsub	d18, d6, d29
	fcmpe	d30, d18
	bhi	.L47
.L116:
	ldr	d5, .LC22
	fmul	d8, d8, d5
	fmul	d2, d8, d5
	b	.L3
.L134:
	cbz	w0, .L81
.L5:
	fmov	d27, xzr
	fadd	d28, d0, d27
	fadd	d1, d1, d27
	fadd	d2, d28, d1
	b	.L3
.L130:
	mov	w10, -1072693248
	add	w3, w5, w10
	orr	w18, w3, w4
	fmov	d2, 1.0e+0
	cbz	w18, .L3
	mov	w12, 1072693247
	cmp	w5, w12
	ble	.L8
	fmov	d2, d1
	tbz	w1, #31, .L3
	b	.L9
.L129:
	cbz	w4, .L6
	b	.L5
.L8:
	fneg	d2, d1
	tbz	w1, #31, .L9
	b	.L3
.L120:
	fabs	d6, d0
	tbz	w1, #31, .L36
	fmov	d30, 1.0e+0
	fdiv	d6, d30, d6
.L36:
	cmp	w14, 1
	fmov	d2, d6
	bne	.L3
	fneg	d2, d6
	b	.L3
.L133:
	cbz	w4, .L80
	b	.L5
.L128:
	cbnz	w4, .L79
	b	.L3
	.size	pow_kernel, .-pow_kernel
	.align	3
.LC0:
	.word	0
	.word	1128267776
	.align	3
.LC1:
	.word	1246056175
	.word	1070235176
	.align	3
.LC2:
	.word	-1815487643
	.word	1070433866
	.align	3
.LC3:
	.word	-1457700607
	.word	1070691424
	.align	3
.LC4:
	.word	1368335949
	.word	1070945621
	.align	3
.LC5:
	.word	-613438465
	.word	1071345078
	.align	3
.LC6:
	.word	858993411
	.word	1071854387
	.align	3
.LC7:
	.word	-536870912
	.word	1072613129
	.align	3
.LC8:
	.word	-600177667
	.word	1072613129
	.align	3
.LC9:
	.word	341508597
	.word	-1103220768
	.align	3
.LC10:
	.word	1137692678
	.word	1045233131
	.align	3
.LC11:
	.word	1073741824
	.word	1071822851
	.align	3
.LC12:
	.word	-2013235812
	.word	2117592124
	.align	3
.LC13:
	.word	1697350398
	.word	1016534343
	.align	3
.LC14:
	.word	0
	.word	1072049731
	.align	3
.LC15:
	.word	-17155601
	.word	1072049730
	.align	3
.LC16:
	.word	212364345
	.word	-1105175455
	.align	3
.LC17:
	.word	1925096656
	.word	1046886249
	.align	3
.LC18:
	.word	-976065551
	.word	1052491073
	.align	3
.LC19:
	.word	-1356472788
	.word	1058100842
	.align	3
.LC20:
	.word	381599123
	.word	1063698796
	.align	3
.LC21:
	.word	1431655742
	.word	1069897045
	.align	3
.LC22:
	.word	-1023872167
	.word	27618847
	.ident	"GCC: (crosstool-NG linaro-1.13.1-4.8-2014.04 - Linaro GCC 4.8-2014.04) 4.8.3 20140401 (prerelease)"
