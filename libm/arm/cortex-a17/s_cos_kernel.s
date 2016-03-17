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
	.file	"s_cos_kernel.c"
	.section	.text.unlikely.cos_kernel,"ax",%progbits
	.align	2
	.global	cos_kernel
	.type	cos_kernel, %function
cos_kernel:
	.fnstart
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 0, uses_anonymous_args = 0
	fmdrr	d17, r0, r1
	stmfd	sp!, {r4, r5, r6, r7, lr}
	.save {r4, r5, r6, r7, lr}
	movw	r1, #8699
	movt	r1, 16361
	.pad #52
	sub	sp, sp, #52
	fmrrd	r2, r3, d17
	bic	r3, r3, #-2147483648
	cmp	r3, r1
	bgt	.L2
	movw	r2, #41117
	movt	r2, 15942
	cmp	r3, r2
	fconstd	d6, #112
	bgt	.L3
	ftosizd	s5, d17
	fmrs	r3, s5	@ int
	cmp	r3, #0
	fcpydeq	d17, d6
	beq	.L4
.L3:
	fmuld	d2, d17, d17
	fldd	d21, .L29
	fldd	d24, .L29+8
	fldd	d26, .L29+16
	fmacd	d24, d2, d21
	fldd	d27, .L29+24
	fmscd	d27, d2, d26
	fldd	d28, .L29+32
	fmuld	d29, d2, d2
	fldd	d30, .L29+40
	fmscd	d28, d24, d2
	fconstd	d31, #96
	fmuld	d16, d29, d29
	fldd	d18, .L29+48
	fmacd	d30, d27, d2
	fmuld	d0, d16, d28
	fmuld	d3, d2, d31
	fmacd	d0, d30, d2
	fmuld	d4, d17, d18
	fsubd	d5, d6, d3
	fsubd	d17, d6, d5
	fmscd	d4, d2, d0
	fsubd	d7, d17, d3
	faddd	d20, d7, d4
	faddd	d17, d20, d5
	b	.L4
.L2:
	movw	r2, #65535
	movt	r2, 32751
	cmp	r3, r2
	fsubdgt	d17, d17, d17
	bgt	.L4
.L5:
	fmrrd	r4, r5, d17
	movw	ip, #27258
	movt	ip, 16399
	bic	r3, r5, #-2147483648
	cmp	r3, ip
	bgt	.L6
	movw	r2, #8699
	movt	r2, 9
	ubfx	r1, r5, #0, #20
	cmp	r1, r2
	beq	.L7
	movw	ip, #55676
	movt	ip, 16386
	cmp	r3, ip
	bgt	.L8
	fldd	d6, .L29+56
	cmp	r5, #0
	fldd	d21, .L29+64
	fsubdgt	d6, d17, d6
	fadddle	d6, d17, d6
	movgt	r0, #1
	mvnle	r0, #0
	fsubdgt	d17, d6, d21
	fadddle	d17, d6, d21
	fsubdgt	d6, d6, d17
	fsubdle	d6, d6, d17
	fsubdgt	d6, d6, d21
	fadddle	d6, d6, d21
	b	.L10
.L8:
	fldd	d6, .L29+72
	cmp	r5, #0
	fldd	d20, .L29+80
	fsubdgt	d6, d17, d6
	fadddle	d6, d17, d6
	movgt	r0, #2
	mvnle	r0, #1
	fsubdgt	d17, d6, d20
	fadddle	d17, d6, d20
	fsubdgt	d6, d6, d17
	fsubdle	d6, d6, d17
	fsubdgt	d6, d6, d20
	fadddle	d6, d6, d20
	b	.L10
.L6:
	movw	r1, #17979
	movt	r1, 16412
	cmp	r3, r1
	bgt	.L12
	movw	r2, #64956
	movt	r2, 16405
	cmp	r3, r2
	bgt	.L13
	movw	ip, #55676
	movt	ip, 16402
	cmp	r3, ip
	beq	.L7
	fldd	d6, .L29+88
	cmp	r5, #0
	fldd	d19, .L29+96
	fsubdgt	d6, d17, d6
	fadddle	d6, d17, d6
	movgt	r0, #3
	mvnle	r0, #2
	fsubdgt	d17, d6, d19
	fadddle	d17, d6, d19
	fsubdgt	d6, d6, d17
	fsubdle	d6, d6, d17
	fsubdgt	d6, d6, d19
	fadddle	d6, d6, d19
	b	.L10
.L13:
	movw	r1, #8699
	movt	r1, 16409
	cmp	r3, r1
	beq	.L7
	fldd	d6, .L29+104
	cmp	r5, #0
	fldd	d7, .L29+112
	fsubdgt	d6, d17, d6
	fadddle	d6, d17, d6
	movgt	r0, #4
	mvnle	r0, #3
	fsubdgt	d17, d6, d7
	fadddle	d17, d6, d7
	fsubdgt	d6, d6, d17
	fsubdle	d6, d6, d17
	fsubdgt	d6, d6, d7
	fadddle	d6, d6, d7
	b	.L10
.L12:
	movw	r0, #8698
	movt	r0, 16697
	cmp	r3, r0
	bgt	.L16
.L7:
	fldd	d23, .L29+120
	fldd	d22, .L29+128
	fcpyd	d25, d23
	fcpyd	d18, d17
	fldd	d24, .L29+56
	fmacd	d25, d17, d22
	fldd	d26, .L29+64
	mov	r1, r3, asr #20
	fsubd	d27, d25, d23
	fnmacd	d18, d27, d24
	ftosizd	s3, d27
	fmuld	d16, d27, d26
	fmrs	r0, s3	@ int
	fsubd	d17, d18, d16
	fmrrd	r2, r3, d17
	ubfx	r3, r3, #20, #11
	rsb	r2, r3, r1
	cmp	r2, #16
	ble	.L17
	fldd	d28, .L29+136
	fldd	d29, .L29+144
	fmuld	d30, d27, d28
	fsubd	d31, d18, d30
	fsubd	d18, d18, d31
	fsubd	d16, d18, d30
	fmscd	d16, d27, d29
	fsubd	d17, d31, d16
	fmrrd	r2, r3, d17
	ubfx	ip, r3, #20, #11
	rsb	r1, ip, r1
	cmp	r1, #49
	flddgt	d16, .L29+152
	flddgt	d29, .L29+160
	fmuldgt	d16, d27, d16
	fcpydle	d18, d31
	fsubdgt	d18, d31, d16
	fsubdgt	d31, d31, d18
	fsubdgt	d16, d31, d16
	fmscdgt	d16, d27, d29
	fsubdgt	d17, d18, d16
.L17:
	fsubd	d0, d18, d17
	fsubd	d6, d0, d16
	b	.L10
.L16:
	cmp	r3, r2
	ble	.L18
	fsubd	d17, d17, d17
	mov	r0, #0
	fcpyd	d6, d17
	b	.L10
.L18:
	mov	r6, r3, asr #20
	sub	r7, r6, #1040
	sub	r2, r7, #6
	mov	r0, r4
	mov	lr, r2, asl #20
	rsb	r1, lr, r3
	fmrrd	r6, r7, d17
	fmdrr	d18, r0, r1
	fldd	d16, .L29+168
	mov	r3, #3
	ftosizd	s15, d18
	fsitod	d17, s15
	fsubd	d0, d18, d17
	fstd	d17, [sp, #24]
	fmuld	d1, d0, d16
	ftosizd	s1, d1
	fsitod	d2, s1
	fsubd	d3, d1, d2
	fstd	d2, [sp, #32]
	fmuld	d4, d3, d16
	fstd	d4, [sp, #40]
	b	.L19
.L27:
	mov	r3, r1
.L19:
	sub	r1, r3, #1
	add	ip, sp, #24
	add	r0, ip, r1, asl #3
	fldd	d5, [r0, #0]
	fcmpzd	d5
	fmstat
	beq	.L27
	mov	lr, #1
	mov	r0, ip
	str	lr, [sp, #0]
	add	r1, sp, #8
	bl	__kernel_rem_pio2(PLT)
	cmp	r5, #0
	fldd	d17, [sp, #8]
	fldd	d6, [sp, #16]
	fnegdlt	d17, d17
	fnegdlt	d6, d6
	rsblt	r0, r0, #0
.L10:
	and	r0, r0, #3
	cmp	r0, #1
	fconstd	d1, #96
	fmuld	d2, d17, d17
	beq	.L23
	cmp	r0, #2
	beq	.L24
	cmp	r0, #0
	bne	.L28
	fldd	d25, .L29
	fldd	d26, .L29+8
	fldd	d27, .L29+16
	fmacd	d26, d2, d25
	fldd	d28, .L29+24
	fmscd	d28, d2, d27
	fldd	d29, .L29+32
	fmuld	d30, d2, d2
	fldd	d31, .L29+40
	fmscd	d29, d26, d2
	fconstd	d16, #112
	fmuld	d18, d30, d30
	fmacd	d31, d28, d2
	fmuld	d0, d18, d29
	fmuld	d1, d2, d1
	fmacd	d0, d31, d2
	fmuld	d6, d6, d17
	fsubd	d3, d16, d1
	fsubd	d4, d16, d3
	fmscd	d6, d2, d0
	fsubd	d2, d4, d1
	faddd	d5, d2, d6
	faddd	d17, d5, d3
	b	.L4
.L30:
	.align	3
.L29:
	.word	-1098368812
	.word	-1112999191
	.word	-1112231484
	.word	1042411166
	.word	432739728
	.word	1056571808
	.word	381768055
	.word	1062650220
	.word	-2137238867
	.word	1049787983
	.word	1431655756
	.word	1067799893
	.word	0
	.word	0
	.word	1413480448
	.word	1073291771
	.word	442655537
	.word	1037087841
	.word	1413480448
	.word	1074340347
	.word	442655537
	.word	1038136417
	.word	2133852160
	.word	1074977148
	.word	-1483500342
	.word	1038683793
	.word	1413480448
	.word	1075388923
	.word	442655537
	.word	1039184993
	.word	0
	.word	1127743488
	.word	1841940611
	.word	1071931184
	.word	442499072
	.word	1037087841
	.word	771977331
	.word	1000544650
	.word	771751936
	.word	1000544650
	.word	622873025
	.word	964395930
	.word	0
	.word	1097859072
	.word	-1098368812
	.word	-1112999191
	.word	432739728
	.word	1056571808
	.word	381768055
	.word	1062650220
	.word	-2137238867
	.word	1049787983
	.word	1431655756
	.word	1067799893
	.word	-1112231484
	.word	1042411166
	.word	1471282813
	.word	1053236707
	.word	286324902
	.word	1065423121
	.word	1431655753
	.word	1069897045
	.word	-1976853269
	.word	1046144486
	.word	1523570044
	.word	1038473530
	.word	432103893
	.word	1059717536
.L23:
	fldd	d0, .L29+224
	fldd	d3, .L29+264
	fldd	d4, .L29+232
	fmscd	d3, d2, d0
	fldd	d5, .L29+256
	fmuld	d7, d2, d2
	fldd	d20, .L29+248
	fmscd	d20, d2, d5
	fldd	d23, .L29+240
	fmacd	d4, d3, d2
	fmuld	d19, d2, d7
	fmuld	d22, d2, d17
	fmacd	d4, d19, d20
	fmuld	d25, d22, d4
	fmscd	d25, d6, d1
	fmscd	d6, d25, d2
	fmacd	d6, d22, d23
	fsubd	d1, d17, d6
	fnegd	d17, d1
	b	.L4
.L24:
	fldd	d7, .L29+176
	fldd	d20, .L29+216
	fldd	d19, .L29+184
	fmacd	d20, d2, d7
	fldd	d23, .L29+192
	fmscd	d23, d2, d19
	fldd	d22, .L29+200
	fmuld	d25, d2, d2
	fldd	d21, .L29+208
	fmscd	d22, d20, d2
	fconstd	d24, #112
	fmuld	d26, d25, d25
	fmacd	d21, d23, d2
	fmuld	d27, d26, d22
	fmuld	d28, d2, d1
	fmacd	d27, d21, d2
	fmuld	d29, d6, d17
	fsubd	d30, d24, d28
	fsubd	d17, d24, d30
	fmscd	d29, d2, d27
	fsubd	d31, d17, d28
	faddd	d16, d31, d29
	faddd	d18, d16, d30
	fnegd	d17, d18
	b	.L4
.L28:
	fldd	d3, .L29+224
	fldd	d4, .L29+264
	fldd	d5, .L29+232
	fmscd	d4, d2, d3
	fldd	d7, .L29+256
	fmuld	d19, d2, d2
	fldd	d20, .L29+248
	fmscd	d20, d2, d7
	fldd	d21, .L29+240
	fmacd	d5, d4, d2
	fmuld	d23, d2, d19
	fmuld	d22, d2, d17
	fmacd	d5, d23, d20
	fmuld	d24, d22, d5
	fmscd	d24, d6, d1
	fmscd	d6, d24, d2
	fmacd	d6, d22, d21
	fsubd	d17, d17, d6
	b	.L4
.L4:
	fmrrd	r0, r1, d17
	add	sp, sp, #52
	ldmfd	sp!, {r4, r5, r6, r7, pc}
	.fnend
	.size	cos_kernel, .-cos_kernel
	.ident	"GCC: (crosstool-NG linaro-1.13.1-4.7-2012.10-20121022 - Linaro GCC 2012.10) 4.7.3 20121001 (prerelease)"
	.section	.note.GNU-stack,"",%progbits
