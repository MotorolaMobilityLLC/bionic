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
	.section	.text.cos_kernel,"ax",%progbits
	.align	2
	.global	cos_kernel
	.type	cos_kernel, %function
cos_kernel:
	.fnstart
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 0, uses_anonymous_args = 0
	fmdrr	d7, r0, r1
	movw	r3, #8699
	stmfd	sp!, {r4, r6, r7, lr}
	.save {r4, r6, r7, lr}
	movt	r3, 16361
	fmrs	r4, s15	@ int
	.pad #48
	sub	sp, sp, #48
	bic	r1, r4, #-2147483648
	cmp	r1, r3
	bgt	.L2
	movw	r4, #41117
	movt	r4, 15942
	cmp	r1, r4
	bgt	.L3
	ftosizd	s3, d7
	fmrs	r1, s3	@ int
	cmp	r1, #0
	fconstdeq	d7, #112
	beq	.L4
.L3:
	fmuld	d2, d7, d7
	fldd	d3, .L45
	fldd	d4, .L45+8
	fldd	d5, .L45+16
	fmacd	d4, d2, d3
	fldd	d6, .L45+24
	fldd	d23, .L45+32
	fmscd	d6, d2, d5
	fmuld	d19, d2, d2
	fldd	d20, .L45+40
	fconstd	d24, #96
	fldd	d25, .L45+48
	fmscd	d23, d4, d2
	fmuld	d26, d19, d19
	fmuld	d21, d2, d24
	fmacd	d20, d6, d2
	fmuld	d7, d7, d25
	fconstd	d27, #112
	fmuld	d28, d26, d23
	fsubd	d22, d27, d21
	fmacd	d28, d20, d2
	fsubd	d29, d27, d22
	fsubd	d30, d29, d21
	fmscd	d7, d2, d28
	faddd	d31, d30, d7
	faddd	d7, d31, d22
.L4:
	fmrrd	r0, r1, d7
	add	sp, sp, #48
	@ sp needed
	ldmfd	sp!, {r4, r6, r7, pc}
.L2:
	movw	r0, #65535
	movt	r0, 32751
	cmp	r1, r0
	bgt	.L44
	movw	r2, #27258
	movt	r2, 16399
	cmp	r1, r2
	bgt	.L6
	movw	r6, #8699
	ubfx	r7, r4, #0, #20
	movt	r6, 9
	cmp	r7, r6
	beq	.L7
	movw	ip, #55676
	movt	ip, 16386
	cmp	r1, ip
	bgt	.L8
	cmp	r4, #0
	fldd	d26, .L45+56
	fldd	d27, .L45+64
	ble	.L9
	fsubd	d30, d7, d26
	fsubd	d6, d30, d27
	fsubd	d31, d30, d6
	fsubd	d7, d31, d27
.L26:
	fmuld	d26, d6, d6
	fldd	d21, .L45+72
	fldd	d27, .L45+80
	fldd	d28, .L45+88
	fmscd	d27, d26, d21
	fldd	d22, .L45+96
	fldd	d29, .L45+104
	fmuld	d30, d26, d26
	fmscd	d29, d26, d22
	fmuld	d31, d26, d6
	fconstd	d0, #96
	fmuld	d1, d26, d30
	fmacd	d28, d27, d26
	fldd	d18, .L45+112
	fmacd	d28, d1, d29
	fmuld	d16, d31, d28
	fmscd	d16, d7, d0
	fmscd	d7, d16, d26
	fmacd	d7, d31, d18
	fsubd	d17, d6, d7
	fnegd	d7, d17
	b	.L4
.L44:
	fsubd	d7, d7, d7
	fmrrd	r0, r1, d7
	add	sp, sp, #48
	@ sp needed
	ldmfd	sp!, {r4, r6, r7, pc}
.L6:
	movw	r6, #17979
	movt	r6, 16412
	cmp	r1, r6
	bgt	.L14
	movw	r3, #64956
	movt	r3, 16405
	cmp	r1, r3
	bgt	.L15
	movw	r2, #55676
	movt	r2, 16402
	cmp	r1, r2
	beq	.L7
	cmp	r4, #0
	fldd	d6, .L45+120
	fldd	d20, .L45+128
	ble	.L16
	fsubd	d22, d7, d6
	fsubd	d6, d22, d20
	fsubd	d23, d22, d6
	fsubd	d7, d23, d20
.L25:
	fmuld	d23, d6, d6
	fldd	d21, .L45+72
	fldd	d24, .L45+80
	fldd	d25, .L45+88
	fmscd	d24, d23, d21
	fldd	d22, .L45+96
	fldd	d26, .L45+104
	fmuld	d27, d23, d23
	fmscd	d26, d23, d22
	fmuld	d28, d23, d6
	fconstd	d29, #96
	fmuld	d30, d23, d27
	fmacd	d25, d24, d23
	fldd	d31, .L45+112
	fmacd	d25, d30, d26
	fmuld	d16, d28, d25
	fmscd	d16, d7, d29
	fmscd	d7, d16, d23
	fmacd	d7, d28, d31
	fsubd	d7, d6, d7
	b	.L4
.L14:
	movw	r7, #8698
	movt	r7, 16697
	cmp	r1, r7
	bgt	.L19
.L7:
	fldd	d0, .L45+136
	mov	r4, r1, asr #20
	fldd	d16, .L45+144
	fcpyd	d17, d0
	fldd	d18, .L45+56
	fldd	d1, .L45+64
	fmacd	d17, d7, d16
	fsubd	d2, d17, d0
	fnmacd	d7, d2, d18
	ftosizd	s13, d2
	fmuld	d20, d2, d1
	fmrs	r0, s13	@ int
	fsubd	d6, d7, d20
	fmrs	r1, s13	@ int
	ubfx	r3, r1, #20, #11
	rsb	r2, r3, r4
	cmp	r2, #16
	ble	.L20
	fldd	d3, .L45+152
	fldd	d4, .L45+160
	fmuld	d5, d2, d3
	fsubd	d19, d7, d5
	fsubd	d6, d7, d19
	fsubd	d20, d6, d5
	fmscd	d20, d2, d4
	fsubd	d6, d19, d20
	fmrs	r6, s13	@ int
	ubfx	r7, r6, #20, #11
	rsb	ip, r7, r4
	cmp	ip, #49
	flddgt	d4, .L45+168
	flddgt	d5, .L45+176
	fmuldgt	d4, d2, d4
	fcpydle	d7, d19
	fsubdgt	d7, d19, d4
	fsubdgt	d20, d19, d7
	fsubdgt	d20, d20, d4
	fmscdgt	d20, d2, d5
	fsubdgt	d6, d7, d20
.L20:
	fsubd	d7, d7, d6
	fsubd	d7, d7, d20
.L21:
	and	r0, r0, #3
	cmp	r0, #1
	beq	.L26
	cmp	r0, #2
	beq	.L27
	cmp	r0, #0
	bne	.L25
.L28:
	fmuld	d0, d6, d6
	fldd	d18, .L45
	fldd	d1, .L45+8
	fldd	d17, .L45+16
	fmacd	d1, d0, d18
	fldd	d2, .L45+24
	fldd	d3, .L45+32
	fmscd	d2, d0, d17
	fmuld	d4, d0, d0
	fldd	d5, .L45+40
	fconstd	d19, #96
	fmuld	d6, d7, d6
	fmscd	d3, d1, d0
	fmuld	d20, d4, d4
	fmuld	d7, d0, d19
	fmacd	d5, d2, d0
	fconstd	d24, #112
	fmuld	d25, d20, d3
	fsubd	d21, d24, d7
	fmacd	d25, d5, d0
	fsubd	d22, d24, d21
	fsubd	d26, d22, d7
	fmscd	d6, d0, d25
	faddd	d27, d26, d6
	faddd	d7, d27, d21
	b	.L4
.L8:
	cmp	r4, #0
	fldd	d24, .L45+184
	fldd	d25, .L45+192
	fsubdgt	d24, d7, d24
	fadddle	d24, d7, d24
	fsubdgt	d6, d24, d25
	fadddle	d6, d24, d25
	fsubdgt	d7, d24, d6
	fsubdle	d24, d24, d6
	fsubdgt	d7, d7, d25
	fadddle	d7, d24, d25
.L27:
	fmuld	d28, d6, d6
	fldd	d29, .L45
	fldd	d30, .L45+8
	fldd	d31, .L45+16
	fmacd	d30, d28, d29
	fldd	d0, .L45+24
	fldd	d1, .L45+32
	fmscd	d0, d28, d31
	fmuld	d18, d28, d28
	fldd	d16, .L45+40
	fmuld	d2, d7, d6
	fmscd	d1, d30, d28
	fmuld	d3, d18, d18
	fconstd	d17, #96
	fmacd	d16, d0, d28
	fmuld	d4, d28, d17
	fconstd	d19, #112
	fmuld	d6, d3, d1
	fsubd	d20, d19, d4
	fmacd	d6, d16, d28
	fsubd	d7, d19, d20
	fsubd	d23, d7, d4
	fmscd	d2, d28, d6
	faddd	d24, d23, d2
	faddd	d25, d24, d20
	fnegd	d7, d25
	b	.L4
.L46:
	.align	3
.L45:
	.word	3196598484
	.word	-1112999191
	.word	3182735812
	.word	1042411166
	.word	432739728
	.word	1056571808
	.word	381768055
	.word	1062650220
	.word	2157728429
	.word	1049787983
	.word	1431655756
	.word	1067799893
	.word	0
	.word	0
	.word	1413480448
	.word	1073291771
	.word	442655537
	.word	1037087841
	.word	1471282813
	.word	1053236707
	.word	432103893
	.word	1059717536
	.word	286324902
	.word	1065423121
	.word	1523570044
	.word	1038473530
	.word	2318114027
	.word	1046144486
	.word	1431655753
	.word	1069897045
	.word	2133852160
	.word	1074977148
	.word	2811466954
	.word	1038683793
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
	.word	1413480448
	.word	1074340347
	.word	442655537
	.word	1038136417
	.word	1413480448
	.word	1075388923
	.word	442655537
	.word	1039184993
	.word	0
	.word	1097859072
.L15:
	movw	r0, #8699
	movt	r0, 16409
	cmp	r1, r0
	beq	.L7
	cmp	r4, #0
	fldd	d5, .L45+200
	fldd	d19, .L45+208
	fsubdgt	d5, d7, d5
	fadddle	d5, d7, d5
	fsubdgt	d6, d5, d19
	fadddle	d6, d5, d19
	fsubdgt	d7, d5, d6
	fsubdle	d5, d5, d6
	fsubdgt	d7, d7, d19
	fadddle	d7, d5, d19
	b	.L28
.L19:
	cmp	r1, r0
	ble	.L22
	fsubd	d7, d7, d7
	fcpyd	d6, d7
	b	.L28
.L9:
	faddd	d28, d7, d26
	faddd	d6, d28, d27
	fsubd	d29, d28, d6
	faddd	d7, d29, d27
	b	.L25
.L22:
	mov	ip, r1, asr #20
	sub	lr, ip, #1040
	sub	r2, lr, #6
	fmrs	r6, s14	@ int
	sub	r7, r1, r2, asl #20
	fldd	d16, .L45+216
	fmdrr	d17, r6, r7
	fmrs	r3, s14	@ int
	ftosizd	s15, d17
	fsitod	d18, s15
	fsubd	d0, d17, d18
	fstd	d18, [sp, #24]
	fmuld	d1, d0, d16
	ftosizd	s1, d1
	fsitod	d2, s1
	fsubd	d3, d1, d2
	fstd	d2, [sp, #32]
	fmuld	d4, d3, d16
	fcmpzd	d4
	fstd	d4, [sp, #40]
	fmstat
	movne	r3, #3
	bne	.L23
	fcmpzd	d2
	fmstat
	moveq	r3, #1
	movne	r3, #2
.L23:
	mov	r1, #1
	add	r0, sp, #24
	str	r1, [sp]
	add	r1, sp, #8
	bl	__kernel_rem_pio2(PLT)
	cmp	r4, #0
	fldd	d6, [sp, #8]
	rsblt	r0, r0, #0
	fldd	d7, [sp, #16]
	fnegdlt	d6, d6
	fnegdlt	d7, d7
	b	.L21
.L16:
	faddd	d7, d7, d6
	faddd	d6, d7, d20
	fsubd	d21, d7, d6
	faddd	d7, d21, d20
	b	.L26
	.fnend
	.size	cos_kernel, .-cos_kernel
	.ident	"GCC: (GNU) 4.9"
	.section	.note.GNU-stack,"",%progbits
