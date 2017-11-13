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
	.file	"s_sin_kernel.c"
	.section	.text.unlikely.sin_kernel,"ax",%progbits
	.align	2
	.global	sin_kernel
	.type	sin_kernel, %function
sin_kernel:
	.fnstart
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 0, uses_anonymous_args = 0
	fmdrr	d30, r0, r1
	stmfd	sp!, {r4, r5, r6, r7, lr}
	.save {r4, r5, r6, r7, lr}
	movw	r1, #8699
	movt	r1, 16361
	.pad #52
	sub	sp, sp, #52
	fmrrd	r2, r3, d30
	movw	r2, #65535
	bic	r3, r3, #-2147483648
	cmp	r3, r1
	bgt	.L2
	movt	r2, 15951
	cmp	r3, r2
	bgt	.L3
	ftosizd	s5, d30
	fmrs	r3, s5	@ int
	cmp	r3, #0
	beq	.L4
.L3:
	fmuld	d24, d30, d30
	fldd	d23, .L31
	fldd	d26, .L31+8
	fldd	d17, .L31+16
	fmscd	d26, d24, d23
	fldd	d27, .L31+24
	fldd	d28, .L31+32
	fmuld	d29, d24, d24
	fldd	d1, .L31+40
	fmscd	d28, d24, d27
	fmacd	d17, d26, d24
	fmuld	d31, d24, d29
	fmuld	d18, d24, d30
	fmacd	d17, d31, d28
	fmscd	d1, d24, d17
	fmacd	d30, d1, d18
	b	.L4
.L2:
	movt	r2, 32751
	cmp	r3, r2
	fsubdgt	d30, d30, d30
	bgt	.L4
.L5:
	fmrrd	r4, r5, d30
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
	fldd	d6, .L31+48
	cmp	r5, #0
	fldd	d21, .L31+56
	fsubdgt	d6, d30, d6
	fadddle	d6, d30, d6
	movgt	r0, #1
	mvnle	r0, #0
	fsubdgt	d30, d6, d21
	fadddle	d30, d6, d21
	fsubdgt	d6, d6, d30
	fsubdle	d6, d6, d30
	fsubdgt	d6, d6, d21
	fadddle	d6, d6, d21
	b	.L10
.L8:
	fldd	d6, .L31+64
	cmp	r5, #0
	fldd	d20, .L31+72
	fsubdgt	d6, d30, d6
	fadddle	d6, d30, d6
	movgt	r0, #2
	mvnle	r0, #1
	fsubdgt	d30, d6, d20
	fadddle	d30, d6, d20
	fsubdgt	d6, d6, d30
	fsubdle	d6, d6, d30
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
	fldd	d6, .L31+80
	cmp	r5, #0
	fldd	d19, .L31+88
	fsubdgt	d6, d30, d6
	fadddle	d6, d30, d6
	movgt	r0, #3
	mvnle	r0, #2
	fsubdgt	d30, d6, d19
	fadddle	d30, d6, d19
	fsubdgt	d6, d6, d30
	fsubdle	d6, d6, d30
	fsubdgt	d6, d6, d19
	fadddle	d6, d6, d19
	b	.L10
.L13:
	movw	r1, #8699
	movt	r1, 16409
	cmp	r3, r1
	beq	.L7
	fldd	d6, .L31+96
	cmp	r5, #0
	fldd	d7, .L31+104
	fsubdgt	d6, d30, d6
	fadddle	d6, d30, d6
	movgt	r0, #4
	mvnle	r0, #3
	fsubdgt	d30, d6, d7
	fadddle	d30, d6, d7
	fsubdgt	d6, d6, d30
	fsubdle	d6, d6, d30
	fsubdgt	d6, d6, d7
	fadddle	d6, d6, d7
	b	.L10
.L12:
	movw	r0, #8698
	movt	r0, 16697
	cmp	r3, r0
	bgt	.L16
.L7:
	fldd	d23, .L31+112
	fldd	d22, .L31+120
	fcpyd	d25, d23
	fcpyd	d18, d30
	fldd	d24, .L31+48
	fmacd	d25, d30, d22
	fldd	d26, .L31+56
	mov	r1, r3, asr #20
	fsubd	d27, d25, d23
	fnmacd	d18, d27, d24
	ftosizd	s3, d27
	fmuld	d16, d27, d26
	fmrs	r0, s3	@ int
	fsubd	d30, d18, d16
	fmrrd	r2, r3, d30
	ubfx	r3, r3, #20, #11
	rsb	r2, r3, r1
	cmp	r2, #16
	ble	.L17
	fldd	d28, .L31+128
	fldd	d29, .L31+136
	fmuld	d30, d27, d28
	fsubd	d31, d18, d30
	fsubd	d18, d18, d31
	fsubd	d16, d18, d30
	fmscd	d16, d27, d29
	fsubd	d30, d31, d16
	fmrrd	r2, r3, d30
	ubfx	ip, r3, #20, #11
	rsb	r1, ip, r1
	cmp	r1, #49
	flddgt	d16, .L31+144
	flddgt	d29, .L31+152
	fmuldgt	d16, d27, d16
	fcpydle	d18, d31
	fsubdgt	d18, d31, d16
	fsubdgt	d31, d31, d18
	fsubdgt	d16, d31, d16
	fmscdgt	d16, d27, d29
	fsubdgt	d30, d18, d16
.L17:
	fsubd	d0, d18, d30
	fsubd	d6, d0, d16
	b	.L10
.L16:
	cmp	r3, r2
	ble	.L18
	fsubd	d30, d30, d30
	mov	r0, #0
	fcpyd	d6, d30
	b	.L10
.L18:
	mov	r6, r3, asr #20
	sub	r7, r6, #1040
	sub	r2, r7, #6
	mov	r0, r4
	mov	lr, r2, asl #20
	rsb	r1, lr, r3
	fldd	d16, .L31+160
	fmdrr	d18, r0, r1
	fmrrd	r6, r7, d30
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
.L26:
	mov	r3, r1
.L19:
	sub	r1, r3, #1
	add	ip, sp, #24
	add	r0, ip, r1, asl #3
	fldd	d5, [r0, #0]
	fcmpzd	d5
	fmstat
	beq	.L26
	mov	lr, #1
	mov	r0, ip
	str	lr, [sp, #0]
	add	r1, sp, #8
	bl	__kernel_rem_pio2(PLT)
	cmp	r5, #0
	fldd	d30, [sp, #8]
	fldd	d6, [sp, #16]
	fnegdlt	d30, d30
	fnegdlt	d6, d6
	rsblt	r0, r0, #0
.L10:
	and	r0, r0, #3
	cmp	r0, #1
	fmuld	d1, d30, d30
	fconstd	d2, #96
	beq	.L23
	cmp	r0, #2
	beq	.L24
	cmp	r0, #0
	bne	.L30
	fldd	d31, .L31
	fldd	d18, .L31+8
	fldd	d16, .L31+16
	fmscd	d18, d1, d31
	fldd	d0, .L31+24
	fmuld	d3, d1, d1
	fldd	d4, .L31+32
	fmscd	d4, d1, d0
	fldd	d5, .L31+40
	fmacd	d16, d18, d1
	fmuld	d7, d1, d3
	fmuld	d20, d1, d30
	fmacd	d16, d7, d4
	fmuld	d19, d20, d16
	fmscd	d19, d6, d2
	fmscd	d6, d19, d1
	fmacd	d6, d20, d5
	fsubd	d30, d30, d6
	b	.L4
.L32:
	.align	3
.L31:
	.word	1471282813
	.word	1053236707
	.word	432103893
	.word	1059717536
	.word	286324902
	.word	1065423121
	.word	1523570044
	.word	1038473530
	.word	-1976853269
	.word	1046144486
	.word	1431655753
	.word	1069897045
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
	.word	1471282813
	.word	1053236707
	.word	432103893
	.word	1059717536
	.word	286324902
	.word	1065423121
	.word	-1976853269
	.word	1046144486
	.word	1431655753
	.word	1069897045
	.word	1431655756
	.word	1067799893
	.word	-2137238867
	.word	1049787983
	.word	381768055
	.word	1062650220
	.word	432739728
	.word	1056571808
	.word	1523570044
	.word	1038473530
	.word	-1112231484
	.word	1042411166
	.word	-1098368812
	.word	-1112999191
.L23:
	fldd	d31, .L31+256
	fldd	d18, .L31+248
	fldd	d16, .L31+232
	fmacd	d18, d1, d31
	fldd	d0, .L31+224
	fmscd	d0, d1, d16
	fldd	d3, .L31+216
	fmuld	d4, d1, d1
	fldd	d5, .L31+208
	fmscd	d3, d18, d1
	fconstd	d7, #112
	fmuld	d20, d4, d4
	fmacd	d5, d0, d1
	fmuld	d19, d20, d3
	fmuld	d2, d1, d2
	fmacd	d19, d5, d1
	fmuld	d6, d6, d30
	fsubd	d30, d7, d2
	fsubd	d21, d7, d30
	fmscd	d6, d1, d19
	fsubd	d22, d21, d2
	faddd	d25, d22, d6
	faddd	d30, d25, d30
	b	.L4
.L24:
	fldd	d21, .L31+168
	fldd	d22, .L31+176
	fmuld	d24, d1, d1
	fldd	d25, .L31+184
	fmscd	d22, d1, d21
	fldd	d23, .L31+240
	fldd	d26, .L31+192
	fmuld	d27, d1, d24
	fldd	d17, .L31+200
	fmscd	d26, d1, d23
	fmacd	d25, d22, d1
	fmuld	d28, d1, d30
	fmacd	d25, d27, d26
	fmuld	d29, d28, d25
	fmscd	d29, d6, d2
	fmscd	d6, d29, d1
	fmacd	d6, d28, d17
	fsubd	d1, d30, d6
	fnegd	d30, d1
	b	.L4
.L30:
	fldd	d3, .L31+256
	fldd	d4, .L31+248
	fldd	d5, .L31+232
	fmacd	d4, d1, d3
	fldd	d7, .L31+224
	fmscd	d7, d1, d5
	fldd	d20, .L31+216
	fmuld	d19, d1, d1
	fldd	d21, .L31+208
	fmscd	d20, d4, d1
	fconstd	d22, #112
	fmuld	d23, d19, d19
	fmacd	d21, d7, d1
	fmuld	d24, d23, d20
	fmuld	d25, d1, d2
	fmacd	d24, d21, d1
	fmuld	d6, d6, d30
	fsubd	d26, d22, d25
	fsubd	d17, d22, d26
	fmscd	d6, d1, d24
	fsubd	d27, d17, d25
	faddd	d28, d27, d6
	faddd	d29, d28, d26
	fnegd	d30, d29
.L4:
	fmrrd	r0, r1, d30
	add	sp, sp, #52
	ldmfd	sp!, {r4, r5, r6, r7, pc}
	.fnend
	.size	sin_kernel, .-sin_kernel
	.ident	"GCC: (crosstool-NG linaro-1.13.1-4.7-2012.10-20121022 - Linaro GCC 2012.10) 4.7.3 20121001 (prerelease)"
	.section	.note.GNU-stack,"",%progbits
