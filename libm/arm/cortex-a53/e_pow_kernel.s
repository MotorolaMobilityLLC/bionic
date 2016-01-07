	.eabi_attribute 27, 3
	.fpu neon-vfpv4
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 2
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"e_pow_kernel.c"
	.section	.text.pow_kernel,"ax",%progbits
	.align	2
	.global	pow_kernel
	.type	pow_kernel, %function
pow_kernel:
	.fnstart
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r3, r4, r5, r6, r7, r8, r9, r10, fp, lr}
	.save {r3, r4, r5, r6, r7, r8, r9, r10, fp, lr}
	subs	r8, r2, #0
	mov	ip, r1
	fstmfdd	sp!, {d8}
	.vsave {d8}
	mov	r6, r0
	mov	r4, r3
	bic	lr, r1, #-2147483648
	bic	r5, r3, #-2147483648
	bne	.L2
	cmp	r5, #0
	beq	.L54
	mov	r7, #0
	movt	r7, 16368
	cmp	r1, r7
	cmpeq	r0, #0
	beq	.L54
	mov	r9, #0
	movt	r9, 32752
	cmp	lr, r9
	bgt	.L4
	moveq	r10, #1
	movne	r10, #0
	cmp	r0, #0
	moveq	r10, #0
	andne	r10, r10, #1
	cmp	r10, #0
	bne	.L4
	cmp	r5, r9
	beq	.L83
	cmp	r3, r7
	beq	.L56
	cmp	r3, #1073741824
	beq	.L84
	mov	r10, #0
	movt	r10, 16336
	cmp	r3, r10
	beq	.L85
	mov	fp, #0
	movt	fp, 16352
	cmp	r3, fp
	beq	.L86
	mov	r7, #0
	movt	r7, 49136
	cmp	r3, r7
	fmdrreq	d16, r0, r1
	fconstdeq	d17, #112
	fdivdeq	d17, d17, d16
	beq	.L3
.L2:
	movw	r10, #65534
	sub	r9, ip, #1
	movt	r10, 32751
	cmp	r9, r10
	bhi	.L87
.L12:
	mov	r10, #0
	movt	r10, 17392
	cmp	r5, r10
	bgt	.L13
	cmp	lr, #1048576
	bge	.L14
	fmdrr	d5, r0, r1
	fldd	d6, .L95
	fmuld	d2, d5, d6
	fmrrd	r0, r1, d2
	mov	ip, r1, asr #20
	mov	lr, r1
	sub	r6, ip, #1072
	sub	fp, r6, #4
.L15:
	movw	r1, #46713
	ubfx	lr, lr, #0, #20
	movt	r1, 11
	orr	r9, lr, #1069547520
	cmp	lr, r1
	orr	r8, r9, #3145728
	ble	.L16
	sub	r1, r8, #1048576
	add	fp, fp, #1
	fmdrr	d0, r0, r1
.L17:
	fconstd	d8, #112
	fldd	d31, .L95+80
	faddd	d30, d0, d8
	fsubd	d3, d0, d8
	fldd	d20, .L95+96
	fldd	d4, .L95+160
	fdivd	d1, d8, d30
	fmrrd	r4, r5, d30	@ int
	mov	r4, #0
	fldd	d22, .L95+112
	fmdrr	d2, r4, r5
	fldd	d16, .L95+152
	fldd	d7, .L95+144
	fconstd	d24, #8
	fsubd	d29, d2, d8
	fcpyd	d8, d22
	fldd	d17, .L95+136
	fmsr	s11, fp	@ int
	fsubd	d21, d0, d29
	fldd	d23, .L95+104
	fldd	d25, .L95+120
	fsitod	d5, s11
	fmuld	d27, d3, d1
	fmuld	d0, d27, d27
	fmrrd	r0, r1, d27	@ int
	mov	r0, r4
	fmdrr	d26, r0, r1
	fmacd	d20, d0, d31
	fmuld	d18, d0, d0
	fnmacd	d3, d26, d2
	fmuld	d28, d26, d26
	fmacd	d4, d20, d0
	faddd	d6, d28, d24
	fnmacd	d3, d26, d21
	fmacd	d8, d4, d0
	fmuld	d19, d3, d1
	fmuld	d31, d19, d27
	fmacd	d16, d8, d0
	fmacd	d31, d19, d26
	fmacd	d7, d16, d0
	fmuld	d30, d18, d7
	faddd	d3, d31, d30
	faddd	d20, d6, d3
	fmrrd	r0, r1, d20
	mov	r0, r4
	fmdrr	d4, r0, r1
	fsubd	d1, d4, d24
	fmuld	d2, d19, d4
	fmuld	d7, d26, d4
	fsubd	d22, d1, d28
	fsubd	d16, d3, d22
	fmacd	d2, d27, d16
	faddd	d24, d7, d2
	fmrrd	r0, r1, d24
	mov	r0, r4
	fmdrr	d29, r0, r1
	fsubd	d27, d29, d7
	fmuld	d17, d29, d17
	fmuld	d25, d29, d25
	fsubd	d21, d2, d27
	faddd	d0, d5, d25
	fmacd	d17, d21, d23
	faddd	d26, d0, d17
	fmrrd	r0, r1, d26
	mov	r0, r4
	fmdrr	d28, r0, r1
	fsubd	d5, d28, d5
	fsubd	d18, d5, d25
	fsubd	d6, d17, d18
.L18:
	mov	r7, #0
	mov	r5, r3
	mov	r4, r7
	movt	r7, 16352
	fmdrr	d8, r2, r3
	fmdrr	d19, r4, r5
	fmuld	d31, d8, d6
	fsubd	d30, d8, d19
	fmuld	d3, d19, d28
	fmacd	d31, d30, d28
	faddd	d20, d31, d3
	fmrrd	r0, r1, d20
	bic	r3, r1, #-2147483648
	mov	r2, r1
	cmp	r3, r7
	mov	lr, r0
	ble	.L57
	movw	r4, #65535
	movt	r4, 16527
	cmp	r3, r4
	ble	.L20
	cmp	r1, r4
	ble	.L21
	add	r9, r1, #-1090519040
	add	r8, r9, #7340032
	orrs	ip, r8, r0
	bne	.L51
	fldd	d7, .L95+8
	fsubd	d16, d20, d3
	faddd	d24, d31, d7
	fcmped	d24, d16
	fmstat
	ble	.L20
.L51:
	fldd	d17, .L95+192
	fmuld	d17, d17, d17
	b	.L3
.L87:
	cmp	r6, #0
	clz	fp, ip
	mov	r7, fp, lsr #5
	moveq	r7, #0
	cmp	r7, #0
	bne	.L12
.L13:
	mov	r7, #0
	movt	r7, 32752
	cmp	lr, r7
	bgt	.L4
	moveq	r9, #1
	movne	r9, #0
	cmp	r6, #0
	moveq	fp, #0
	andne	fp, r9, #1
	cmp	fp, #0
	bne	.L4
	cmp	r5, r7
	bgt	.L4
	moveq	r7, #1
	movne	r7, #0
	cmp	r8, #0
	moveq	r7, #0
	andne	r7, r7, #1
	cmp	r7, #0
	bne	.L4
	cmp	ip, #0
	blt	.L88
.L25:
	cmp	lr, #0
	cmpeq	r6, #0
	beq	.L81
	cmp	r9, #0
	bne	.L81
	cmp	ip, #0
	blt	.L89
	add	r2, r5, #-1140850688
	add	r3, r2, #1048576
	cmn	r3, #-1006632959
	bhi	.L8
	fmdrr	d0, r0, r1
	fconstd	d17, #112
	fcmpd	d0, d17
	fmstat
	beq	.L3
	movw	r0, #65535
	movt	r0, 16367
	cmp	lr, r0
	ble	.L90
	cmp	r4, #0
	bgt	.L51
.L8:
	fldd	d17, .L95+168
	b	.L3
.L54:
	fconstd	d17, #112
.L3:
	fldmfdd	sp!, {d8}
	fmrrd	r0, r1, d17
	ldmfd	sp!, {r3, r4, r5, r6, r7, r8, r9, r10, fp, pc}
.L4:
	fmdrr	d23, r0, r1
	fmdrr	d28, r2, r3
	fldd	d0, .L95+168
	fldmfdd	sp!, {d8}
	faddd	d26, d23, d0
	faddd	d5, d28, d0
	faddd	d17, d26, d5
	fmrrd	r0, r1, d17
	ldmfd	sp!, {r3, r4, r5, r6, r7, r8, r9, r10, fp, pc}
.L96:
	.align	3
.L95:
	.word	0
	.word	1128267776
	.word	1697350398
	.word	1016534343
	.word	212364345
	.word	-1105175455
	.word	1925096656
	.word	1046886249
	.word	1431655742
	.word	1069897045
	.word	4277811695
	.word	1072049730
	.word	381599123
	.word	1063698796
	.word	2938494508
	.word	1058100842
	.word	3318901745
	.word	1052491073
	.word	0
	.word	1072049731
	.word	1246056175
	.word	1070235176
	.word	1073741824
	.word	1071822851
	.word	2479479653
	.word	1070433866
	.word	3694789629
	.word	1072613129
	.word	1368335949
	.word	1070945621
	.word	3758096384
	.word	1072613129
	.word	1137692678
	.word	1045233131
	.word	341508597
	.word	-1103220768
	.word	858993411
	.word	1071854387
	.word	3681528831
	.word	1071345078
	.word	2837266689
	.word	1070691424
	.word	0
	.word	0
	.word	2281731484
	.word	-29891524
	.word	0
	.word	-2147483648
	.word	2281731484
	.word	2117592124
.L21:
	movw	fp, #52223
	movt	fp, 16528
	cmp	r3, fp
	ble	.L20
	mov	ip, #13312
	movt	ip, 16239
	add	r6, r1, ip
	orrs	ip, r6, r0
	bne	.L8
	fsubd	d2, d20, d3
	fcmped	d31, d2
	fmstat
	bls	.L8
.L20:
	mov	r0, r3, asr #20
	mov	r1, #1048576
	sub	r5, r0, #1020
	mov	r4, r2, lsr #31
	sub	r7, r5, #2
	movw	lr, #65535
	movt	lr, 15
	rsb	fp, r4, #0
	add	r10, r2, r1, asr r7
	ubfx	ip, r10, #20, #11
	ubfx	r3, r10, #0, #20
	sub	r2, ip, #1020
	rsb	r6, ip, #1040
	sub	r9, r2, #3
	add	r8, r6, #3
	mov	r6, #0
	orr	r1, r3, #1048576
	bic	r0, r10, lr, asr r9
	mov	r7, r0
	eor	r5, fp, r1, asr r8
	add	r4, r5, r4
	fmdrr	d29, r6, r7
	mov	r10, r4, asl #20
	fsubd	d3, d3, d29
	faddd	d4, d31, d3
.L19:
	fmrrd	r0, r1, d4	@ int
	mov	r0, #0
	fldd	d27, .L95+16
	fmdrr	d17, r0, r1
	fldd	d25, .L95+40
	fldd	d21, .L95+72
	fldd	d0, .L95+24
	fsubd	d23, d17, d3
	fmuld	d26, d17, d27
	fmuld	d28, d17, d21
	fldd	d5, .L95+64
	fsubd	d18, d31, d23
	fldd	d6, .L95+56
	fldd	d8, .L95+48
	fldd	d31, .L95+32
	fmacd	d26, d18, d25
	fconstd	d3, #0
	fconstd	d20, #112
	faddd	d19, d28, d26
	fmuld	d4, d19, d19
	fcpyd	d7, d19
	fsubd	d1, d19, d28
	fmscd	d5, d4, d0
	fsubd	d2, d26, d1
	fmacd	d2, d19, d2
	fmacd	d6, d5, d4
	fmscd	d8, d6, d4
	fmacd	d31, d8, d4
	fnmacd	d7, d31, d4
	fmuld	d22, d19, d7
	fsubd	d16, d7, d3
	fdivd	d24, d22, d16
	fsubd	d29, d24, d2
	fsubd	d17, d29, d19
	fsubd	d27, d20, d17
	fmrrd	r0, r1, d27
	add	r10, r1, r10
	cmp	r10, #1048576
	movge	r1, r10
	fmdrrge	d17, r0, r1
	bge	.L3
	fldmfdd	sp!, {d8}
	mov	r2, r4
	ldmfd	sp!, {r3, r4, r5, r6, r7, r8, r9, r10, fp, lr}
	b	scalbn(PLT)
.L57:
	fcpyd	d4, d20
	mov	r10, r4
	b	.L19
.L16:
	movw	r5, #39054
	mov	r1, r8
	movt	r5, 3
	cmp	lr, r5
	fmdrr	d0, r0, r1
	ble	.L17
	fconstd	d31, #120
	fconstd	d28, #112
	faddd	d30, d0, d31
	fsubd	d20, d0, d31
	fmsr	s5, fp	@ int
	fldd	d8, .L95+80
	fdivd	d22, d28, d30
	fmrrd	r4, r5, d30	@ int
	mov	r4, #0
	fsitod	d18, s5
	fmdrr	d29, r4, r5
	fldd	d3, .L95+96
	fldd	d17, .L95+160
	fldd	d4, .L95+112
	fsubd	d27, d29, d31
	fldd	d1, .L95+152
	fldd	d7, .L95+144
	fconstd	d5, #8
	fsubd	d21, d0, d27
	fldd	d26, .L95+136
	fldd	d16, .L95+128
	fldd	d25, .L95+120
	fldd	d24, .L95+104
	fldd	d23, .L95+88
	faddd	d19, d18, d23
	fmuld	d2, d20, d22
	fmuld	d0, d2, d2
	fmrrd	r0, r1, d2	@ int
	mov	r0, r4
	fmdrr	d28, r0, r1
	fmacd	d3, d0, d8
	fmuld	d6, d0, d0
	fnmacd	d20, d28, d29
	fmuld	d30, d28, d28
	fmacd	d17, d3, d0
	faddd	d8, d30, d5
	fnmacd	d20, d28, d21
	fmacd	d4, d17, d0
	fmuld	d20, d20, d22
	fmuld	d3, d20, d2
	fmacd	d1, d4, d0
	fmacd	d3, d20, d28
	fmacd	d7, d1, d0
	fmuld	d22, d6, d7
	faddd	d4, d3, d22
	faddd	d17, d8, d4
	fmrrd	r0, r1, d17
	mov	r0, r4
	fmdrr	d29, r0, r1
	fsubd	d1, d29, d5
	fmuld	d7, d20, d29
	fmuld	d27, d28, d29
	fsubd	d5, d1, d30
	fsubd	d21, d4, d5
	fmacd	d7, d2, d21
	faddd	d2, d27, d7
	fmrrd	r0, r1, d2
	mov	r0, r4
	fmdrr	d0, r0, r1
	fsubd	d28, d0, d27
	fmacd	d16, d0, d26
	fmuld	d26, d0, d25
	fsubd	d25, d7, d28
	faddd	d19, d19, d26
	fmacd	d16, d25, d24
	fcpyd	d24, d16
	faddd	d16, d19, d16
	fmrrd	r0, r1, d16
	mov	r0, r4
	fmdrr	d28, r0, r1
	fsubd	d18, d28, d18
	fsubd	d23, d18, d23
	fsubd	d6, d23, d26
	fsubd	d6, d24, d6
	b	.L18
.L14:
	mov	r4, lr, asr #20
	sub	r10, r4, #1020
	sub	fp, r10, #3
	b	.L15
.L83:
	add	fp, lr, #-1073741824
	add	ip, fp, #1048576
	orrs	r1, ip, r0
	beq	.L54
	movw	r6, #65535
	movt	r6, 16367
	cmp	lr, r6
	ble	.L7
	cmp	r3, #0
	fmdrrge	d17, r2, r3
	bge	.L3
	b	.L8
.L81:
	fmdrr	d16, r0, r1
	cmp	r4, #0
	fabsd	d17, d16
	fconstdlt	d16, #112
	fdivdlt	d17, d16, d17
	cmp	r7, #1
	fnegdeq	d17, d17
	b	.L3
.L88:
	movw	r10, #65535
	movt	r10, 17215
	cmp	r5, r10
	movgt	r7, #2
	bgt	.L25
	movw	fp, #65535
	movt	fp, 16367
	cmp	r5, fp
	ble	.L25
	mov	r10, r5, asr #20
	movw	fp, #1043
	cmp	r10, fp
	ble	.L26
	rsb	fp, r10, #1072
	add	r10, fp, #3
	mov	fp, r8, lsr r10
	cmp	r8, fp, asl r10
	andeq	r7, fp, #1
	rsbeq	r7, r7, #2
	b	.L25
.L56:
	fmdrr	d17, r0, r1
	b	.L3
.L85:
	cmp	r1, #0
	blt	.L2
	bl	sqrt(PLT)
	fldmfdd	sp!, {d8}
	ldmfd	sp!, {r3, r4, r5, r6, r7, r8, r9, r10, fp, lr}
	b	sqrt(PLT)
.L86:
	cmp	r1, #0
	blt	.L2
	fldmfdd	sp!, {d8}
	ldmfd	sp!, {r3, r4, r5, r6, r7, r8, r9, r10, fp, lr}
	b	sqrt(PLT)
.L84:
	fmdrr	d25, r0, r1
	fmuld	d17, d25, d25
	b	.L3
.L7:
	cmp	r3, #0
	bge	.L8
	fmdrr	d21, r2, r3
	fnegd	d17, d21
	b	.L3
.L89:
	cmp	r7, #0
	beq	.L91
	cmp	r7, #1
	mov	ip, #0
	fldd	d19, .L95+168
	movt	ip, 17392
	fldd	d17, .L95+184
	fldd	d1, .L95+192
	fldd	d23, .L95+176
	fconstd	d8, #112
	fconstd	d18, #240
	fcpydne	d17, d19
	fcpydne	d23, d1
	fcpydeq	d8, d18
	cmp	r5, ip
	bgt	.L36
	fmdrr	d3, r0, r1
	cmp	lr, #1048576
	movge	r1, lr, asr #20
	movw	r9, #46713
	subge	r1, r1, #1020
	movt	r9, 11
	subge	r1, r1, #3
	fabsd	d7, d3
	flddlt	d3, .L97
	fmuldlt	d7, d7, d3
	fmrslt	lr, s15	@ int
	fmrrd	r4, r5, d7	@ int
	movlt	r1, lr, asr #20
	ubfx	lr, lr, #0, #20
	sublt	r1, r1, #1072
	orr	r8, lr, #1069547520
	sublt	r1, r1, #4
	cmp	lr, r9
	orr	r5, r8, #3145728
	bgt	.L92
	movw	r7, #39054
	movt	r7, 3
	cmp	lr, r7
	fmdrr	d24, r4, r5
	ble	.L40
	fconstd	d6, #120
	fconstd	d29, #112
	faddd	d20, d24, d6
	fsubd	d0, d24, d6
	fldd	d4, .L97+96
	fldd	d21, .L97+104
	fdivd	d18, d29, d20
	fmrrd	r4, r5, d20	@ int
	mov	r4, #0
	fldd	d7, .L97+120
	fmdrr	d5, r4, r5
	fldd	d31, .L97+160
	fldd	d30, .L97+152
	fldd	d22, .L97+144
	fsubd	d25, d5, d6
	fmsr	s13, r1	@ int
	fconstd	d26, #8
	fldd	d3, .L97+128
	fsubd	d16, d24, d25
	fldd	d2, .L97+136
	fsitod	d19, s13
	fldd	d28, .L97+112
	fldd	d6, .L97+8
	fldd	d1, .L97+16
	faddd	d29, d19, d6
	fmuld	d27, d0, d18
	fmuld	d20, d27, d27
	fmrrd	r0, r1, d27	@ int
	mov	r0, r4
	fmdrr	d24, r0, r1
	fmacd	d21, d20, d4
	fmuld	d4, d20, d20
	fnmacd	d0, d24, d5
	fmuld	d5, d24, d24
	fmacd	d7, d21, d20
	faddd	d21, d5, d26
	fnmacd	d0, d24, d16
	fmacd	d31, d7, d20
	fmuld	d0, d0, d18
	fmuld	d18, d0, d27
	fmacd	d30, d31, d20
	fmacd	d18, d0, d24
	fmacd	d22, d30, d20
	fmuld	d7, d4, d22
	faddd	d31, d18, d7
	faddd	d30, d21, d31
	fmrrd	r0, r1, d30
	mov	r0, r4
	fmdrr	d22, r0, r1
	fsubd	d25, d22, d26
	fmuld	d20, d24, d22
	fmuld	d26, d0, d22
	fsubd	d16, d25, d5
	fsubd	d24, d31, d16
	fmacd	d26, d27, d24
	faddd	d4, d20, d26
	fmrrd	r0, r1, d4
	mov	r0, r4
	fmdrr	d5, r0, r1
	fsubd	d21, d5, d20
	fmuld	d28, d5, d28
	fsubd	d0, d26, d21
	faddd	d29, d29, d28
	fmuld	d3, d0, d3
	fmacd	d3, d5, d2
	faddd	d2, d3, d1
	faddd	d1, d29, d2
	fmrrd	r0, r1, d1
	mov	r0, r4
	fmdrr	d31, r0, r1
	fsubd	d19, d31, d19
	fsubd	d6, d19, d6
	fsubd	d18, d6, d28
	fsubd	d0, d2, d18
.L41:
	mov	r4, #0
	mov	r1, r3
	mov	r0, r4
	movt	r4, 16352
	fmdrr	d28, r2, r3
	fmdrr	d27, r0, r1
	fmuld	d30, d28, d0
	fsubd	d26, d28, d27
	fmuld	d25, d27, d31
	fmacd	d30, d26, d31
	faddd	d7, d30, d25
	fmrs	lr, s15	@ int
	fmrs	r10, s14	@ int
	bic	fp, lr, #-2147483648
	cmp	fp, r4
	ble	.L67
	movw	r2, #65535
	movt	r2, 16527
	cmp	fp, r2
	ble	.L43
	cmp	lr, r2
	ble	.L44
	add	r6, lr, #-1090519040
	add	r1, r6, #7340032
	orrs	r2, r1, r10
	bne	.L77
	fldd	d17, .L97+24
	fsubd	d22, d7, d25
	faddd	d4, d30, d17
	fcmped	d4, d22
	fmstat
	bgt	.L77
.L43:
	mov	r9, fp, asr #20
	mov	r8, #1048576
	sub	r5, r9, #1020
	mov	fp, lr, lsr #31
	sub	r4, r5, #2
	movw	r7, #65535
	movt	r7, 15
	rsb	r0, fp, #0
	add	r10, lr, r8, asr r4
	mov	r4, #0
	ubfx	r3, r10, #20, #11
	ubfx	r2, r10, #0, #20
	sub	lr, r3, #1020
	rsb	ip, r3, #1040
	sub	lr, lr, #3
	orr	r1, r2, #1048576
	add	r6, ip, #3
	bic	r9, r10, r7, asr lr
	mov	r5, r9
	eor	r8, r0, r1, asr r6
	add	r2, r8, fp
	fmdrr	d19, r4, r5
	fsubd	d25, d25, d19
	faddd	d7, d30, d25
.L42:
	fmrrd	r0, r1, d7	@ int
	mov	r0, #0
	fldd	d24, .L97+32
	fmdrr	d3, r0, r1
	fldd	d7, .L97+40
	fldd	d21, .L97+48
	fldd	d1, .L97+56
	fsubd	d16, d3, d25
	fmuld	d6, d3, d24
	fmuld	d5, d3, d21
	fldd	d2, .L97+64
	fsubd	d31, d30, d16
	fldd	d0, .L97+72
	fldd	d28, .L97+80
	fldd	d30, .L97+88
	fmacd	d6, d31, d7
	fconstd	d29, #0
	fconstd	d20, #112
	faddd	d26, d5, d6
	fmuld	d18, d26, d26
	fcpyd	d17, d26
	fsubd	d25, d26, d5
	fmscd	d2, d18, d1
	fsubd	d23, d6, d25
	fmacd	d23, d26, d23
	fmacd	d0, d2, d18
	fmscd	d28, d0, d18
	fmacd	d30, d28, d18
	fnmacd	d17, d30, d18
	fmuld	d22, d26, d17
	fsubd	d4, d17, d29
	fdivd	d19, d22, d4
	fsubd	d7, d19, d23
	fsubd	d24, d7, d26
	fsubd	d3, d20, d24
	fmrrd	r0, r1, d3
	add	r7, r1, r2, asl #20
	cmp	r7, #1048576
	movge	r1, r7
	fmdrrge	d7, r0, r1
	blt	.L93
.L48:
	fmuld	d17, d7, d8
	b	.L3
.L90:
	cmp	r4, #0
	bge	.L8
	b	.L51
.L91:
	fmdrr	d21, r0, r1
	fsubd	d1, d21, d21
	fdivd	d17, d1, d1
	b	.L3
.L26:
	cmp	r8, #0
	bne	.L25
	rsb	r8, r10, #1040
	add	r10, r8, #3
	mov	r7, r5, asr r10
	cmp	r5, r7, asl r10
	andeq	r7, r7, #1
	movne	r7, #0
	rsbeq	r7, r7, #2
	b	.L25
.L36:
	mov	r6, #0
	movt	r6, 32752
	cmp	r5, r6
	beq	.L8
	fmdrr	d2, r0, r1
	fcmpd	d2, d18
	fmstat
	fcpydeq	d17, d8
	beq	.L3
	movw	r1, #65535
	movt	r1, 16367
	cmp	lr, r1
	ble	.L94
	cmp	r4, #0
	ble	.L3
.L76:
	fmuld	d17, d23, d1
	b	.L3
.L67:
	mov	r2, r0
	b	.L42
.L98:
	.align	3
.L97:
	.word	0
	.word	1128267776
	.word	1073741824
	.word	1071822851
	.word	1137692678
	.word	1045233131
	.word	1697350398
	.word	1016534343
	.word	212364345
	.word	-1105175455
	.word	4277811695
	.word	1072049730
	.word	0
	.word	1072049731
	.word	1925096656
	.word	1046886249
	.word	3318901745
	.word	1052491073
	.word	2938494508
	.word	1058100842
	.word	381599123
	.word	1063698796
	.word	1431655742
	.word	1069897045
	.word	1246056175
	.word	1070235176
	.word	2479479653
	.word	1070433866
	.word	3758096384
	.word	1072613129
	.word	2837266689
	.word	1070691424
	.word	3694789629
	.word	1072613129
	.word	341508597
	.word	-1103220768
	.word	858993411
	.word	1071854387
	.word	3681528831
	.word	1071345078
	.word	1368335949
	.word	1070945621
	.word	2281731484
	.word	2117592124
.L92:
	sub	r5, r5, #1048576
	add	r1, r1, #1
	fmdrr	d24, r4, r5
.L40:
	fconstd	d7, #112
	fldd	d5, .L97+96
	faddd	d31, d24, d7
	fsubd	d20, d24, d7
	fldd	d0, .L97+104
	fldd	d28, .L97+120
	fdivd	d30, d7, d31
	fmrrd	r4, r5, d31	@ int
	mov	r4, #0
	fldd	d27, .L97+160
	fmdrr	d29, r4, r5
	fldd	d26, .L97+152
	fldd	d25, .L97+144
	fconstd	d22, #8
	fsubd	d4, d29, d7
	fldd	d16, .L97+136
	fldd	d2, .L97+128
	fldd	d1, .L97+112
	fsubd	d19, d24, d4
	fmsr	s9, r1	@ int
	fsitod	d18, s9
	fmuld	d24, d20, d30
	fmuld	d3, d24, d24
	fmrrd	r0, r1, d24	@ int
	mov	r0, r4
	fmdrr	d21, r0, r1
	fmacd	d0, d3, d5
	fmuld	d7, d3, d3
	fnmacd	d20, d21, d29
	fmuld	d6, d21, d21
	fmacd	d28, d0, d3
	faddd	d5, d6, d22
	fnmacd	d20, d21, d19
	fmacd	d27, d28, d3
	fmuld	d31, d20, d30
	fmuld	d20, d31, d24
	fmacd	d26, d27, d3
	fmacd	d20, d31, d21
	fmacd	d25, d26, d3
	fmuld	d28, d7, d25
	faddd	d27, d20, d28
	faddd	d30, d5, d27
	fmrrd	r0, r1, d30
	mov	r0, r4
	fmdrr	d29, r0, r1
	fsubd	d26, d29, d22
	fmuld	d25, d31, d29
	fmuld	d22, d21, d29
	fsubd	d4, d26, d6
	fsubd	d19, d27, d4
	fmacd	d25, d24, d19
	faddd	d3, d22, d25
	fmrrd	r0, r1, d3
	mov	r0, r4
	fmdrr	d7, r0, r1
	fsubd	d21, d7, d22
	fmuld	d16, d7, d16
	fmuld	d1, d7, d1
	fsubd	d6, d25, d21
	faddd	d5, d18, d1
	fmacd	d16, d6, d2
	faddd	d2, d5, d16
	fmrrd	r0, r1, d2
	mov	r0, r4
	fmdrr	d31, r0, r1
	fsubd	d18, d31, d18
	fsubd	d20, d18, d1
	fsubd	d0, d16, d20
	b	.L41
.L44:
	movw	r3, #52223
	movt	r3, 16528
	cmp	fp, r3
	ble	.L43
	mov	r0, #13312
	movt	r0, 16239
	add	ip, lr, r0
	orrs	r2, ip, r10
	bne	.L3
	fsubd	d23, d7, d25
	fcmped	d30, d23
	fmstat
	bhi	.L43
	b	.L3
.L93:
	bl	scalbn(PLT)
	fmdrr	d7, r0, r1
	b	.L48
.L94:
	cmp	r4, #0
	bge	.L3
	b	.L76
.L77:
	fldd	d8, .L97+168
	fmuld	d17, d23, d8
	b	.L3
	.fnend
	.size	pow_kernel, .-pow_kernel
	.ident	"GCC: (GNU) 4.9"
	.section	.note.GNU-stack,"",%progbits
