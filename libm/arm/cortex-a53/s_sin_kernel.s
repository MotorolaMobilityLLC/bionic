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
	.section	.text.sin_kernel,"ax",%progbits
	.align	2
	.global	sin_kernel
	.type	sin_kernel, %function
sin_kernel:
	.fnstart
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 0, uses_anonymous_args = 0
	fmdrr	d7, r0, r1
	movw	r2, #8699
	stmfd	sp!, {r4, lr}
	.save {r4, lr}
	movt	r2, 16361
	movw	r0, #65535
	fmrs	r4, s15	@ int
	.pad #48
	sub	sp, sp, #48
	bic	r3, r4, #-2147483648
	cmp	r3, r2
	bgt	.L2
	movt	r0, 15951
	cmp	r3, r0
	bgt	.L3
	ftosizd	s3, d7
	fmrs	ip, s3	@ int
	cmp	ip, #0
	beq	.L4
.L3:
	fmuld	d4, d7, d7
	fldd	d5, .L45
	fldd	d21, .L45+8
	fldd	d23, .L45+16
	fmscd	d21, d4, d5
	fldd	d6, .L45+24
	fldd	d24, .L45+32
	fmuld	d20, d4, d4
	fmscd	d24, d4, d6
	fldd	d19, .L45+40
	fmuld	d22, d4, d7
	fmuld	d25, d4, d20
	fmacd	d23, d21, d4
	fmacd	d23, d25, d24
	fmscd	d19, d4, d23
	fmacd	d7, d19, d22
.L4:
	fmrrd	r0, r1, d7
	add	sp, sp, #48
	@ sp needed
	ldmfd	sp!, {r4, pc}
.L2:
	movt	r0, 32751
	cmp	r3, r0
	bgt	.L44
	movw	r1, #27258
	movt	r1, 16399
	cmp	r3, r1
	bgt	.L6
	movw	r2, #8699
	ubfx	r1, r4, #0, #20
	movt	r2, 9
	cmp	r1, r2
	beq	.L7
	movw	r0, #55676
	movt	r0, 16386
	cmp	r3, r0
	bgt	.L8
	cmp	r4, #0
	fldd	d26, .L45+48
	fldd	d27, .L45+56
	ble	.L9
	fsubd	d30, d7, d26
	fsubd	d6, d30, d27
	fsubd	d31, d30, d6
	fsubd	d7, d31, d27
.L26:
	fmuld	d24, d6, d6
	fldd	d19, .L45+64
	fldd	d22, .L45+72
	fldd	d25, .L45+80
	fmacd	d22, d24, d19
	fldd	d26, .L45+88
	fldd	d27, .L45+96
	fmscd	d26, d24, d25
	fmuld	d28, d24, d24
	fldd	d29, .L45+104
	fconstd	d30, #96
	fmuld	d7, d7, d6
	fmscd	d27, d22, d24
	fmuld	d31, d28, d28
	fmuld	d17, d24, d30
	fmacd	d29, d26, d24
	fconstd	d0, #112
	fmuld	d1, d31, d27
	fsubd	d2, d0, d17
	fmacd	d1, d29, d24
	fsubd	d18, d0, d2
	fsubd	d16, d18, d17
	fmscd	d7, d24, d1
	faddd	d3, d16, d7
	faddd	d7, d3, d2
	b	.L4
.L44:
	fsubd	d7, d7, d7
	fmrrd	r0, r1, d7
	add	sp, sp, #48
	@ sp needed
	ldmfd	sp!, {r4, pc}
.L6:
	movw	ip, #17979
	movt	ip, 16412
	cmp	r3, ip
	bgt	.L14
	movw	r2, #64956
	movt	r2, 16405
	cmp	r3, r2
	bgt	.L15
	movw	ip, #55676
	movt	ip, 16402
	cmp	r3, ip
	beq	.L7
	cmp	r4, #0
	fldd	d6, .L45+112
	fldd	d20, .L45+120
	ble	.L16
	fsubd	d22, d7, d6
	fsubd	d6, d22, d20
	fsubd	d23, d22, d6
	fsubd	d7, d23, d20
.L25:
	fmuld	d23, d6, d6
	fldd	d22, .L45+64
	fldd	d24, .L45+72
	fldd	d25, .L45+80
	fmacd	d24, d23, d22
	fldd	d26, .L45+88
	fldd	d27, .L45+96
	fmscd	d26, d23, d25
	fmuld	d28, d23, d23
	fldd	d29, .L45+104
	fconstd	d30, #96
	fmuld	d31, d7, d6
	fmscd	d27, d24, d23
	fmuld	d17, d28, d28
	fmuld	d0, d23, d30
	fmacd	d29, d26, d23
	fconstd	d16, #112
	fmuld	d18, d17, d27
	fsubd	d1, d16, d0
	fmacd	d18, d29, d23
	fsubd	d2, d16, d1
	fsubd	d3, d2, d0
	fmscd	d31, d23, d18
	faddd	d4, d3, d31
	faddd	d5, d4, d1
	fnegd	d7, d5
	b	.L4
.L14:
	movw	r2, #8698
	movt	r2, 16697
	cmp	r3, r2
	bgt	.L19
.L7:
	fldd	d17, .L45+128
	mov	r3, r3, asr #20
	fldd	d16, .L45+136
	fcpyd	d18, d17
	fldd	d0, .L45+48
	fldd	d2, .L45+56
	fmacd	d18, d7, d16
	fsubd	d3, d18, d17
	fnmacd	d7, d3, d0
	ftosizd	s13, d3
	fmuld	d21, d3, d2
	fmrs	r0, s13	@ int
	fsubd	d6, d7, d21
	fmrs	r4, s13	@ int
	ubfx	ip, r4, #20, #11
	rsb	r2, ip, r3
	cmp	r2, #16
	ble	.L20
	fldd	d4, .L45+144
	fldd	d5, .L45+152
	fmuld	d19, d3, d4
	fsubd	d20, d7, d19
	fsubd	d6, d7, d20
	fsubd	d21, d6, d19
	fmscd	d21, d3, d5
	fsubd	d6, d20, d21
	fmrs	r1, s13	@ int
	ubfx	r4, r1, #20, #11
	rsb	r3, r4, r3
	cmp	r3, #49
	flddgt	d5, .L45+160
	flddgt	d19, .L45+168
	fmuldgt	d5, d3, d5
	fcpydle	d7, d20
	fsubdgt	d7, d20, d5
	fsubdgt	d21, d20, d7
	fsubdgt	d21, d21, d5
	fmscdgt	d21, d3, d19
	fsubdgt	d6, d7, d21
.L20:
	fsubd	d7, d7, d6
	fsubd	d7, d7, d21
.L21:
	and	r0, r0, #3
	cmp	r0, #1
	beq	.L26
	cmp	r0, #2
	beq	.L27
	cmp	r0, #0
	bne	.L25
.L28:
	fmuld	d20, d6, d6
	fldd	d21, .L45
	fldd	d23, .L45+8
	fldd	d19, .L45+16
	fmscd	d23, d20, d21
	fldd	d22, .L45+24
	fldd	d24, .L45+32
	fmuld	d25, d20, d20
	fmscd	d24, d20, d22
	fmuld	d26, d20, d6
	fconstd	d27, #96
	fmuld	d28, d20, d25
	fmacd	d19, d23, d20
	fldd	d29, .L45+40
	fmacd	d19, d28, d24
	fmuld	d30, d26, d19
	fmscd	d30, d7, d27
	fmscd	d7, d30, d20
	fmacd	d7, d26, d29
	fsubd	d7, d6, d7
	b	.L4
.L8:
	cmp	r4, #0
	fldd	d24, .L45+176
	fldd	d25, .L45+184
	fsubdgt	d24, d7, d24
	fadddle	d24, d7, d24
	fsubdgt	d6, d24, d25
	fadddle	d6, d24, d25
	fsubdgt	d7, d24, d6
	fsubdle	d24, d24, d6
	fsubdgt	d7, d7, d25
	fadddle	d7, d24, d25
.L27:
	fmuld	d31, d6, d6
	fldd	d17, .L45
	fldd	d0, .L45+8
	fldd	d1, .L45+16
	fmscd	d0, d31, d17
	fldd	d18, .L45+24
	fldd	d16, .L45+32
	fmuld	d2, d31, d31
	fmscd	d16, d31, d18
	fmuld	d3, d31, d6
	fconstd	d4, #96
	fmuld	d5, d31, d2
	fmacd	d1, d0, d31
	fldd	d20, .L45+40
	fmacd	d1, d5, d16
	fmuld	d21, d3, d1
	fmscd	d21, d7, d4
	fmscd	d7, d21, d31
	fcpyd	d23, d7
	fmacd	d23, d3, d20
	fsubd	d6, d6, d23
	fnegd	d7, d6
	b	.L4
.L15:
	movw	r0, #8699
	movt	r0, 16409
	cmp	r3, r0
	beq	.L7
	cmp	r4, #0
	fldd	d5, .L45+192
	fldd	d19, .L45+200
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
	cmp	r3, r0
	ble	.L22
	fsubd	d7, d7, d7
	fcpyd	d6, d7
	b	.L28
.L46:
	.align	3
.L45:
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
	.word	1413480448
	.word	1073291771
	.word	442655537
	.word	1037087841
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
.L9:
	faddd	d28, d7, d26
	faddd	d6, d28, d27
	fsubd	d29, d28, d6
	faddd	d7, d29, d27
	b	.L25
.L22:
	mov	lr, r3, asr #20
	sub	r0, lr, #1040
	sub	r2, r0, #6
	fmrs	r0, s14	@ int
	sub	r1, r3, r2, asl #20
	fldd	d16, .L45+208
	fmdrr	d17, r0, r1
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
	.size	sin_kernel, .-sin_kernel
	.ident	"GCC: (GNU) 4.9"
	.section	.note.GNU-stack,"",%progbits
