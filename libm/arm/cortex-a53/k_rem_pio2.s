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
	.file	"k_rem_pio2.c"
	.section	.text.__kernel_rem_pio2,"ax",%progbits
	.align	2
	.global	__kernel_rem_pio2
	.type	__kernel_rem_pio2, %function
__kernel_rem_pio2:
	.fnstart
	@ args = 4, pretend = 0, frame = 592
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, r6, r7, r8, r9, r10, fp, lr}
	.save {r4, r5, r6, r7, r8, r9, r10, fp, lr}
	movw	r8, #43691
	sub	ip, r2, #3
	movt	r8, 10922
	mov	lr, r3
	fstmfdd	sp!, {d8, d9, d10, d11, d12, d13, d14}
	.vsave {d8, d9, d10, d11, d12, d13, d14}
	.pad #596
	sub	sp, sp, #596
	smull	r8, r9, ip, r8
	mov	r4, ip, asr #31
	mov	r7, r0
	str	r3, [sp, #8]
	sub	r5, lr, #1
	ldr	r3, .L193+40
	rsb	fp, r4, r9, asr #2
	str	r1, [sp, #4]
.LPIC16:
	add	r10, pc, r3
	ldr	r1, [sp, #688]
	bic	r0, fp, fp, asr #31
	str	r0, [sp, #16]
	mvn	ip, r0
	rsb	r3, r5, r0
	ldr	r8, [r10, r1, asl #2]
	mov	r4, ip, asl #5
	sub	r10, r4, ip, asl #3
	adds	lr, r5, r8
	add	r10, r10, r2
	bmi	.L7
	ldr	r1, .L193+44
	add	r2, r3, lr
	add	ip, r2, #1
	add	lr, sp, #112
.LPIC17:
	add	r0, pc, r1
.L6:
	cmp	r3, #0
	ldrge	fp, [r0, r3, asl #2]
	add	r3, r3, #1
	flddlt	d16, .L193
	fmsrge	s15, fp	@ int
	fsitodge	d16, s15
	cmp	r3, ip
	fstmiad	lr!, {d16}
	bne	.L6
.L7:
	cmp	r8, #0
	ldrlt	r3, [sp, #8]
	movlt	r6, r3, asl #3
	blt	.L4
	ldr	r6, [sp, #8]
	add	fp, r8, #1
	add	r4, sp, #432
	add	r1, sp, #112
	add	r0, r4, fp, asl #3
	mov	r6, r6, asl #3
.L8:
	cmp	r5, #0
	blt	.L85
	fldd	d16, .L193
	mov	r2, r7
	add	ip, r1, r6
.L9:
	fldmdbd	ip!, {d17}
	fldmiad	r2!, {d18}
	fmacd	d16, d18, d17
	cmp	r1, ip
	bne	.L9
	fstmiad	r4!, {d16}
	cmp	r4, r0
	add	r1, r1, #8
	bne	.L8
.L4:
	fldd	d9, .L193+8
	vldr	d12, .L193+16
	vldr	d13, .L193+24
	sub	lr, r8, #-1073741823
	fldd	d8, .L193+32
	ldr	fp, .L193+48
	add	r3, sp, #32
	rsb	r6, r6, #0
.LPIC18:
	add	r4, pc, fp
	add	r0, r3, lr, asl #2
	str	r4, [sp, #24]
	mov	r4, r8
	str	r3, [sp, #12]
	str	r0, [sp, #20]
	fconstd	d11, #64
.L40:
	mov	r2, r4, asl #3
	add	ip, sp, #592
	add	r1, ip, r2
	cmp	r4, #0
	fldd	d3, [r1, #-160]
	ble	.L11
	add	lr, sp, #432
	add	fp, sp, #28
	add	r0, lr, r2
.L12:
	fmuld	d0, d3, d9
	fcpyd	d2, d3
	fldmdbd	r0!, {d19}
	ftosizd	s15, d0
	cmp	r0, lr
	fsitod	d1, s15
	fnmacd	d2, d1, d8
	faddd	d3, d1, d19
	ftosizd	s1, d2
	fmrs	r3, s1	@ int
	str	r3, [fp, #4]!
	bne	.L12
.L11:
	fmrrd	r0, r1, d3
	mov	r2, r10
	bl	scalbn(PLT)
	fmdrr	d10, r0, r1
	fmuld	d4, d10, d11
	fmrrd	r0, r1, d4
	bl	floor(PLT)
	cmp	r10, #0
	fmdrr	d6, r0, r1
	fconstd	d5, #32
	fnmacd	d10, d6, d5
	ftosizd	s28, d10
	fsitod	d7, s28
	fsubd	d10, d10, d7
	ble	.L13
	sub	fp, r4, #1
	add	r0, sp, #592
	rsb	r3, r10, #24
	rsb	r9, r10, #23
	add	r2, r0, fp, asl #2
	fmrs	lr, s28	@ int
	ldr	ip, [r2, #-560]
	mov	r1, ip, asr r3
	add	fp, lr, r1
	sub	r3, ip, r1, asl r3
	str	r3, [r2, #-560]
	fmsr	s28, fp	@ int
	mov	r9, r3, asr r9
.L14:
	cmp	r9, #0
	ble	.L17
	fmrs	r0, s28	@ int
	cmp	r4, #0
	add	r2, r0, #1
	fmsr	s28, r2	@ int
	ble	.L182
.L76:
	mov	r1, #0
	add	lr, sp, #28
	mov	ip, r1
	b	.L21
.L194:
	.align	3
.L193:
	.word	0
	.word	0
	.word	0
	.word	1047527424
	.byte	12
	.byte	13
	.byte	14
	.byte	15
	.byte	8
	.byte	9
	.byte	10
	.byte	11
	.byte	4
	.byte	5
	.byte	6
	.byte	7
	.byte	0
	.byte	1
	.byte	2
	.byte	3
	.word	0
	.word	1097859072
	.word	.LANCHOR0-(.LPIC16+8)
	.word	.LANCHOR1-(.LPIC17+8)
	.word	.LANCHOR1-(.LPIC18+8)
.L186:
	cmp	r3, #0
	add	r1, r1, #1
	rsb	r2, r3, #16777216
	movne	ip, #1
	strne	r2, [lr]
	cmp	r4, r1
	ble	.L18
.L21:
	movw	fp, #65535
	cmp	ip, #0
	movt	fp, 255
	ldr	r3, [lr, #4]!
	beq	.L186
	add	r1, r1, #1
	rsb	r0, r3, fp
	cmp	r4, r1
	mov	ip, #1
	str	r0, [lr]
	bgt	.L21
.L18:
	cmp	r10, #0
	ble	.L22
	cmp	r10, #1
	beq	.L23
	cmp	r10, #2
	bne	.L22
	sub	lr, r4, #1
	add	fp, sp, #592
	add	r3, fp, lr, asl #2
	ldr	r0, [r3, #-560]
	ubfx	r2, r0, #0, #22
	str	r2, [r3, #-560]
.L22:
	cmp	r9, #2
	beq	.L187
.L17:
	fcmpzd	d10
	fmstat
	bne	.L25
.L188:
	sub	r0, r4, #1
	cmp	r8, r0
	bgt	.L26
	sub	lr, r4, #-1073741820
	rsb	r2, r8, r4
	and	ip, lr, #1
	cmp	ip, r2
	movcs	ip, r2
	cmp	r2, #8
	movls	ip, r2
	cmp	ip, #0
	beq	.L87
	add	fp, sp, #592
	cmp	ip, #1
	add	r3, fp, r0, asl #2
	sub	r1, r4, #2
	ldr	r3, [r3, #-560]
	beq	.L29
	add	fp, sp, #592
	cmp	ip, #2
	add	fp, fp, r1, asl #2
	sub	r1, r4, #3
	ldr	fp, [fp, #-560]
	orr	r3, r3, fp
	beq	.L29
	add	fp, sp, #592
	cmp	ip, #3
	add	fp, fp, r1, asl #2
	sub	r1, r4, #4
	ldr	fp, [fp, #-560]
	orr	r3, r3, fp
	beq	.L29
	add	fp, sp, #592
	cmp	ip, #4
	add	fp, fp, r1, asl #2
	sub	r1, r4, #5
	ldr	fp, [fp, #-560]
	orr	r3, r3, fp
	beq	.L29
	add	fp, sp, #592
	cmp	ip, #5
	add	fp, fp, r1, asl #2
	sub	r1, r4, #6
	ldr	fp, [fp, #-560]
	orr	r3, r3, fp
	beq	.L29
	add	fp, sp, #592
	cmp	ip, #6
	add	fp, fp, r1, asl #2
	sub	r1, r4, #7
	ldr	fp, [fp, #-560]
	orr	r3, r3, fp
	beq	.L29
	add	fp, sp, #592
	cmp	ip, #8
	add	fp, fp, r1, asl #2
	sub	r1, r4, #8
	ldr	fp, [fp, #-560]
	orr	r3, r3, fp
	addeq	fp, sp, #592
	addeq	fp, fp, r1, asl #2
	subeq	r1, r4, #9
	ldreq	fp, [fp, #-560]
	orreq	r3, r3, fp
.L29:
	cmp	r2, ip
	beq	.L30
.L28:
	rsb	fp, ip, r2
	str	fp, [sp, #28]
	sub	fp, fp, #4
	sub	r2, r2, #1
	rsb	r2, ip, r2
	mov	fp, fp, lsr #2
	cmp	r2, #2
	add	r2, fp, #1
	mov	fp, r2, asl #2
	bls	.L31
	rsb	ip, ip, lr
	ldr	lr, [sp, #12]
	cmp	r2, #1
	add	ip, lr, ip, asl #2
	vld1.64	{d24-d25}, [ip:64]
	vtbl.8	d20, {d24, d25}, d12
	vtbl.8	d21, {d24, d25}, d13
	vmov	q8, q10  @ v4si
	beq	.L32
	vldr	d26, [ip, #-16]
	vldr	d27, [ip, #-8]
	cmp	r2, #2
	vtbl.8	d16, {d26, d27}, d12
	vtbl.8	d17, {d26, d27}, d13
	vorr	q8, q10, q8
	beq	.L32
	vldr	d28, [ip, #-32]
	vldr	d29, [ip, #-24]
	cmp	r2, #3
	vtbl.8	d20, {d28, d29}, d12
	vtbl.8	d21, {d28, d29}, d13
	vorr	q8, q8, q10
	beq	.L32
	vldr	d30, [ip, #-48]
	vldr	d31, [ip, #-40]
	cmp	r2, #4
	vtbl.8	d20, {d30, d31}, d12
	vtbl.8	d21, {d30, d31}, d13
	vorr	q8, q8, q10
	beq	.L32
	vldr	d0, [ip, #-64]
	vldr	d1, [ip, #-56]
	vtbl.8	d18, {d0, d1}, d12
	vtbl.8	d19, {d0, d1}, d13
	vorr	q8, q8, q9
.L32:
	vmov.i32	q9, #0  @ v16qi
	ldr	r2, [sp, #28]
	rsb	r1, fp, r1
	cmp	fp, r2
	vext.8	q1, q8, q9, #8
	vorr	q2, q1, q8
	vext.8	q3, q2, q9, #4
	vorr	q10, q3, q2
	vmov.32	fp, d20[0]
	orr	r3, r3, fp
	beq	.L30
.L31:
	add	ip, sp, #592
	sub	lr, r1, #1
	add	r2, ip, r1, asl #2
	cmp	r8, lr
	ldr	fp, [r2, #-560]
	orr	r3, r3, fp
	bgt	.L30
	add	ip, sp, #592
	sub	r1, r1, #2
	add	lr, ip, lr, asl #2
	cmp	r8, r1
	ldr	r2, [lr, #-560]
	orr	r3, r3, r2
	addle	fp, sp, #592
	addle	ip, fp, r1, asl #2
	ldrle	lr, [ip, #-560]
	orrle	r3, r3, lr
.L30:
	cmp	r3, #0
	bne	.L36
.L26:
	add	lr, sp, #592
	add	r0, lr, r8, asl #2
	ldr	ip, [r0, #-564]
	cmp	ip, #0
	bne	.L88
	ldr	r3, [sp, #20]
	mov	fp, #1
.L38:
	ldr	r1, [r3, #-4]!
	add	fp, fp, #1
	cmp	r1, #0
	beq	.L38
.L37:
	add	ip, r4, fp
	cmp	r4, ip
	bge	.L44
	ldr	lr, [sp, #8]
	add	r3, sp, #592
	ldr	r2, [sp, #16]
	add	r0, r4, lr
	add	fp, ip, lr
	add	r9, r4, r2
	ldr	r1, [sp, #24]
	add	r2, sp, #112
	add	r4, r3, r4, asl #3
	add	r9, r1, r9, asl #2
	sub	lr, r4, #152
	add	r0, r2, r0, asl #3
	add	fp, r2, fp, asl #3
.L43:
	ldr	r3, [r9, #4]!
	cmp	r5, #0
	fldd	d30, .L195
	fmsr	s11, r3	@ int
	fsitod	d14, s11
	fstmiad	r0!, {d14}
	blt	.L41
	mov	r4, r7
	add	r1, r0, r6
	mov	r2, r0
.L42:
	fldmdbd	r2!, {d0}
	fldmiad	r4!, {d16}
	fmacd	d30, d16, d0
	cmp	r2, r1
	bne	.L42
.L41:
	cmp	r0, fp
	fstmiad	lr!, {d30}
	bne	.L43
.L44:
	mov	r4, ip
	b	.L40
.L187:
	fconstd	d22, #112
	cmp	ip, #0
	fsubd	d10, d22, d10
	beq	.L17
	fmrrd	r0, r1, d22
	mov	r2, r10
	bl	scalbn(PLT)
	fmdrr	d23, r0, r1
	fsubd	d10, d10, d23
	fcmpzd	d10
	fmstat
	beq	.L188
.L25:
	fmrrd	r0, r1, d10
	rsb	r2, r10, #0
	bl	scalbn(PLT)
	fmdrr	d8, r0, r1
	fldd	d9, .L195+8
	fcmped	d8, d9
	fmstat
	blt	.L189
	fldd	d11, .L195+16
	add	ip, sp, #592
	add	r1, ip, r4, asl #2
	add	r4, r4, #1
	fmuld	d12, d8, d11
	add	r10, r10, #24
	add	r2, ip, r4, asl #2
	ftosizd	s5, d12
	fsitod	d13, s5
	fnmacd	d8, d13, d9
	ftosizd	s7, d8
	fsts	s7, [r1, #-560]	@ int
	fsts	s5, [r2, #-560]	@ int
.L46:
	mov	r1, #0
	mov	r2, r10
	mov	r0, #0
	movt	r1, 16368
	bl	scalbn(PLT)
	cmp	r4, #0
	fmdrr	d17, r0, r1
	blt	.L47
	add	r0, r4, #1
	ldr	ip, [sp, #12]
	fldd	d27, .L195+16
	add	r10, sp, #432
	mov	fp, r0, asl #3
	add	r5, ip, r0, asl #2
	add	r3, r10, fp
.L48:
	ldr	lr, [r5, #-4]!
	fmsr	s9, lr	@ int
	fsitod	d29, s9
	fmuld	d31, d29, d17
	fmuld	d17, d17, d27
	fstmdbd	r3!, {d31}
	cmp	r3, r10
	bne	.L48
	add	lr, fp, #48
	mov	r2, #0
	add	r6, r3, lr
	fldd	d23, .L195+24
	fldd	d22, .L195
	fldd	d10, .L195+32
	fldd	d21, .L195+40
	fldd	d7, .L195+48
	fldd	d5, .L195+56
	fldd	d3, .L195+64
	fldd	d19, .L195+72
	fldd	d1, .L195+80
	b	.L49
.L190:
	cmp	r2, #0
	blt	.L90
	fcpyd	d13, d22
	movne	r5, #1
	fldd	d12, [r6, #-56]
	moveq	r5, #0
	cmp	r8, #0
	moveq	r5, #0
	andne	r5, r5, #1
	cmp	r5, #0
	fmacd	d13, d12, d23
	fcpyd	d24, d13
	beq	.L52
	fldd	d26, [r6, #-48]
	cmp	r2, #1
	cmpne	r8, #1
	fmacd	d24, d26, d10
	beq	.L52
	fldd	d28, [r6, #-40]
	cmp	r2, #2
	cmpne	r8, #2
	fmacd	d24, d28, d21
	beq	.L52
	fldd	d30, [r6, #-32]
	cmp	r2, #3
	cmpne	r8, #3
	fmacd	d24, d30, d7
	beq	.L52
	fldd	d0, [r6, #-24]
	cmp	r2, #4
	cmpne	r8, #4
	fmacd	d24, d0, d5
	beq	.L52
	fldd	d16, [r6, #-16]
	cmp	r2, #5
	cmpne	r8, #5
	fmacd	d24, d16, d3
	beq	.L52
	fldd	d18, [r6, #-8]
	cmp	r2, #6
	cmpne	r8, #6
	fmacd	d24, d18, d19
	flddne	d2, [r6]
	fmacdne	d24, d2, d1
.L52:
	add	r1, sp, #592
	sub	r6, r6, #8
	add	r5, r1, r2, asl #3
	add	r2, r2, #1
	cmp	r2, r0
	fstd	d24, [r5, #-320]
	beq	.L50
.L49:
	cmp	r8, #0
	bge	.L190
.L90:
	fldd	d24, .L195
	b	.L52
.L87:
	mov	r1, r0
	mov	r3, ip
	b	.L28
.L13:
	bne	.L15
	add	r9, sp, #592
	add	r1, r9, r4, asl #2
	ldr	lr, [r1, #-564]
	mov	r9, lr, asr #23
	b	.L14
.L23:
	sub	r1, r4, #1
	add	lr, sp, #592
	add	fp, lr, r1, asl #2
	ldr	r3, [fp, #-560]
	ubfx	r0, r3, #0, #23
	str	r0, [fp, #-560]
	b	.L22
.L15:
	fconstd	d20, #96
	fcmped	d10, d20
	fmstat
	movlt	r9, #0
	blt	.L17
	fmrs	r2, s28	@ int
	cmp	r4, #0
	movgt	r9, #2
	add	ip, r2, #1
	fmsr	s28, ip	@ int
	bgt	.L76
	fconstd	d21, #112
	mov	r9, #2
	fsubd	d10, d21, d10
	b	.L17
.L85:
	fldd	d16, .L195
	add	r1, r1, #8
	fstmiad	r4!, {d16}
	cmp	r4, r0
	bne	.L8
	b	.L4
.L47:
	ldr	r8, [sp, #688]
	cmp	r8, #3
	addls	pc, pc, r8, asl #2
	b	.L53
.L55:
	b	.L91
	b	.L92
	b	.L92
	b	.L57
	.p2align 1
.L92:
	cmp	r9, #0
	fldd	d10, .L195
	beq	.L66
.L191:
	fnegd	d13, d10
	ldr	r5, [sp, #4]
	fldd	d24, [sp, #272]
	cmp	r4, #0
	fsubd	d12, d24, d10
	fstd	d13, [r5]
	ble	.L83
.L82:
	add	r6, sp, #280
	mov	r7, #1
.L68:
	add	r7, r7, #1
	fldmiad	r6!, {d26}
	cmp	r4, r7
	faddd	d12, d12, d26
	bge	.L68
	cmp	r9, #0
	beq	.L70
.L83:
	fnegd	d12, d12
.L70:
	ldr	r4, [sp, #4]
	fstd	d12, [r4, #8]
	b	.L53
.L91:
	fldd	d25, .L195
.L54:
	cmp	r9, #0
	ldr	r9, [sp, #4]
	fnegdne	d25, d25
	fstd	d25, [r9]
.L53:
	fmrs	r10, s28	@ int
	and	r0, r10, #7
	add	sp, sp, #596
	@ sp needed
	fldmfdd	sp!, {d8-d14}
	ldmfd	sp!, {r4, r5, r6, r7, r8, r9, r10, fp, pc}
.L50:
	ldr	r7, [sp, #688]
	cmp	r7, #3
	addls	pc, pc, r7, asl #2
	b	.L53
.L80:
	b	.L62
	b	.L81
	b	.L81
	b	.L58
	.p2align 1
.L81:
	fldd	d10, .L195
	add	fp, sp, #272
	add	r3, fp, r0, asl #3
.L65:
	fldmdbd	r3!, {d22}
	faddd	d10, d10, d22
	cmp	r3, fp
	bne	.L65
	cmp	r9, #0
	bne	.L191
.L66:
	ldr	r1, [sp, #4]
	cmp	r4, #0
	fldd	d23, [sp, #272]
	fstd	d10, [r1]
	fsubd	d12, d23, d10
	bgt	.L82
	ldr	r4, [sp, #4]
	fstd	d12, [r4, #8]
	b	.L53
.L196:
	.align	3
.L195:
	.word	0
	.word	0
	.word	0
	.word	1097859072
	.word	0
	.word	1047527424
	.word	1073741824
	.word	1073291771
	.word	0
	.word	1047807021
	.word	2147483648
	.word	1022903960
	.word	1610612736
	.word	997772369
	.word	2147483648
	.word	972036995
	.word	1073741824
	.word	947528992
	.word	2147483648
	.word	920879650
	.word	0
	.word	896135965
	.word	0
	.word	0
.L62:
	fldd	d25, .L195+88
	add	r2, sp, #272
	add	r8, r2, r0, asl #3
.L63:
	sub	r4, r4, #1
	fldmdbd	r8!, {d28}
	cmn	r4, #1
	faddd	d25, d25, d28
	bne	.L63
	b	.L54
.L36:
	mov	r1, r0, asl #2
	add	r2, sp, #592
	add	r3, r2, r1
	mov	r4, r0
	sub	r10, r10, #24
	ldr	r0, [r3, #-560]
	cmp	r0, #0
	bne	.L46
	ldr	r5, [sp, #12]
	add	r6, r5, r1
.L45:
	ldr	r7, [r6, #-4]!
	sub	r4, r4, #1
	sub	r10, r10, #24
	cmp	r7, #0
	beq	.L45
	b	.L46
.L88:
	mov	fp, #1
	b	.L37
.L182:
	mov	ip, #0
	b	.L18
.L57:
	cmp	r9, #0
	fldd	d11, .L195+88
	beq	.L192
.L75:
	fldd	d19, [sp, #272]
	ldr	r9, [sp, #4]
	fldd	d3, [sp, #280]
	fnegd	d5, d11
	fnegd	d7, d19
	fnegd	d21, d3
	fstd	d5, [r9, #16]
	fstd	d7, [r9]
	fstd	d21, [r9, #8]
	b	.L53
.L58:
	cmp	r4, #0
	ble	.L57
	mov	r8, r4, asl #3
	add	r10, sp, #272
	add	fp, r10, r8
	add	ip, r8, #8
	mov	r3, fp
	add	r0, r10, ip
	fldd	d9, [fp]
	add	r1, sp, #280
.L71:
	fldmdbd	r3!, {d4}
	faddd	d6, d4, d9
	fsubd	d20, d4, d6
	faddd	d8, d20, d9
	fcpyd	d9, d6
	fstmdbd	r0!, {d8}
	cmp	r0, r1
	fstd	d6, [r3]
	bne	.L71
	cmp	r4, #1
	ble	.L57
	add	r4, r10, r8
	add	r5, r8, #8
	add	r6, r10, r5
	mov	r7, r4
	fldd	d17, [r4]
	mov	r2, r6
	add	r8, sp, #288
.L73:
	fldmdbd	r7!, {d25}
	faddd	d27, d17, d25
	fsubd	d29, d25, d27
	faddd	d31, d17, d29
	fcpyd	d17, d27
	fstmdbd	r2!, {d31}
	cmp	r2, r8
	fstd	d27, [r7]
	bne	.L73
	fldd	d11, .L195+88
.L74:
	fldmdbd	r6!, {d1}
	faddd	d11, d11, d1
	cmp	r6, r8
	bne	.L74
	cmp	r9, #0
	bne	.L75
.L192:
	ldr	ip, [sp, #4]
	add	fp, sp, #272
	ldrd	r10, [fp]
	add	r1, sp, #280
	ldrd	r0, [r1]
	fstd	d11, [ip, #16]
	strd	r10, [ip]
	strd	r0, [ip, #8]
	b	.L53
.L189:
	ftosizd	s3, d8
	add	r7, sp, #592
	add	r6, r7, r4, asl #2
	fsts	s3, [r6, #-560]	@ int
	b	.L46
	.fnend
	.size	__kernel_rem_pio2, .-__kernel_rem_pio2
	.section	.rodata.init_jk,"a",%progbits
	.align	3
.LANCHOR0 = . + 0
	.type	init_jk, %object
	.size	init_jk, 16
init_jk:
	.word	3
	.word	4
	.word	4
	.word	6
	.section	.rodata.ipio2,"a",%progbits
	.align	3
.LANCHOR1 = . + 0
	.type	ipio2, %object
	.size	ipio2, 264
ipio2:
	.word	10680707
	.word	7228996
	.word	1387004
	.word	2578385
	.word	16069853
	.word	12639074
	.word	9804092
	.word	4427841
	.word	16666979
	.word	11263675
	.word	12935607
	.word	2387514
	.word	4345298
	.word	14681673
	.word	3074569
	.word	13734428
	.word	16653803
	.word	1880361
	.word	10960616
	.word	8533493
	.word	3062596
	.word	8710556
	.word	7349940
	.word	6258241
	.word	3772886
	.word	3769171
	.word	3798172
	.word	8675211
	.word	12450088
	.word	3874808
	.word	9961438
	.word	366607
	.word	15675153
	.word	9132554
	.word	7151469
	.word	3571407
	.word	2607881
	.word	12013382
	.word	4155038
	.word	6285869
	.word	7677882
	.word	13102053
	.word	15825725
	.word	473591
	.word	9065106
	.word	15363067
	.word	6271263
	.word	9264392
	.word	5636912
	.word	4652155
	.word	7056368
	.word	13614112
	.word	10155062
	.word	1944035
	.word	9527646
	.word	15080200
	.word	6658437
	.word	6231200
	.word	6832269
	.word	16767104
	.word	5075751
	.word	3212806
	.word	1398474
	.word	7579849
	.word	6349435
	.word	12618859
	.ident	"GCC: (GNU) 4.9"
	.section	.note.GNU-stack,"",%progbits
