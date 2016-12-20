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
	.file	"e_rem_pio2.c"
	.section	.text.__ieee754_rem_pio2,"ax",%progbits
	.align	2
	.global	__ieee754_rem_pio2
	.type	__ieee754_rem_pio2, %function
__ieee754_rem_pio2:
	.fnstart
	@ args = 0, pretend = 0, frame = 40
	@ frame_needed = 0, uses_anonymous_args = 0
	fmdrr	d7, r0, r1
	movw	r1, #27258
	stmfd	sp!, {r4, r5, r6, r7, lr}
	.save {r4, r5, r6, r7, lr}
	movt	r1, 16399
	mov	r4, r2
	fmrs	r5, s15	@ int
	.pad #52
	sub	sp, sp, #52
	bic	r3, r5, #-2147483648
	cmp	r3, r1
	bgt	.L2
	movw	r6, #8699
	ubfx	r1, r5, #0, #20
	movt	r6, 9
	cmp	r1, r6
	beq	.L3
	movw	r2, #55676
	movt	r2, 16386
	cmp	r3, r2
	ble	.L24
	cmp	r5, #0
	ble	.L7
	fldd	d23, .L27
	mov	r0, #2
	fldd	d24, .L27+8
.L21:
	fsubd	d29, d7, d23
	fsubd	d30, d29, d24
	fsubd	d31, d29, d30
	fstd	d30, [r4]
	fsubd	d16, d31, d24
	fstd	d16, [r4, #8]
	add	sp, sp, #52
	@ sp needed
	ldmfd	sp!, {r4, r5, r6, r7, pc}
.L2:
	movw	r2, #17979
	movt	r2, 16412
	cmp	r3, r2
	bgt	.L8
	movw	r0, #64956
	movt	r0, 16405
	cmp	r3, r0
	bgt	.L9
	movw	ip, #55676
	movt	ip, 16402
	cmp	r3, ip
	beq	.L3
	cmp	r5, #0
	ble	.L10
	fldd	d23, .L27+16
	mov	r0, #3
	fldd	d24, .L27+24
	b	.L21
.L8:
	movw	r0, #8698
	movt	r0, 16697
	cmp	r3, r0
	ble	.L3
	movw	r6, #65535
	movt	r6, 32751
	cmp	r3, r6
	bgt	.L25
	mov	r7, r3, asr #20
	sub	ip, r7, #1040
	sub	r2, ip, #6
	fmrs	r6, s14	@ int
	sub	r7, r3, r2, asl #20
	fldd	d16, .L27+32
	fmdrr	d17, r6, r7
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
	bne	.L15
	fcmpzd	d2
	fmstat
	moveq	r3, #1
	movne	r3, #2
.L15:
	mov	r1, #1
	add	r0, sp, #24
	str	r1, [sp]
	add	r1, sp, #8
	bl	__kernel_rem_pio2(PLT)
	cmp	r5, #0
	blt	.L26
	ldrd	r6, [sp, #8]
	ldrd	r2, [sp, #16]
	strd	r6, [r4]
	strd	r2, [r4, #8]
	b	.L6
.L3:
	fldd	d1, .L27+40
	mov	r3, r3, asr #20
	fldd	d0, .L27+48
	fcpyd	d17, d1
	fldd	d18, .L27+56
	fldd	d2, .L27+64
	fmacd	d17, d7, d0
	fsubd	d3, d17, d1
	fnmacd	d7, d3, d18
	ftosizd	s13, d3
	fmuld	d21, d3, d2
	fmrs	r0, s13	@ int
	fsubd	d6, d7, d21
	fmrs	r5, s13	@ int
	fstd	d6, [r4]
	ubfx	r7, r5, #20, #11
	rsb	ip, r7, r3
	cmp	ip, #16
	ble	.L13
	fldd	d4, .L27+72
	fldd	d5, .L27+80
	fmuld	d19, d3, d4
	fsubd	d20, d7, d19
	fsubd	d6, d7, d20
	fsubd	d21, d6, d19
	fmscd	d21, d3, d5
	fsubd	d6, d20, d21
	fmrs	r6, s13	@ int
	fstd	d6, [r4]
	ubfx	r1, r6, #20, #11
	rsb	r2, r1, r3
	cmp	r2, #49
	flddgt	d5, .L27+88
	flddgt	d19, .L27+96
	fmuldgt	d5, d3, d5
	fcpydle	d7, d20
	fsubdgt	d7, d20, d5
	fsubdgt	d21, d20, d7
	fsubdgt	d21, d21, d5
	fmscdgt	d21, d3, d19
	fsubdgt	d6, d7, d21
	fstdgt	d6, [r4]
.L13:
	fsubd	d7, d7, d6
	fsubd	d22, d7, d21
	fstd	d22, [r4, #8]
.L6:
	add	sp, sp, #52
	@ sp needed
	ldmfd	sp!, {r4, r5, r6, r7, pc}
.L24:
	cmp	r5, #0
	ble	.L5
	fldd	d23, .L27+56
	mov	r0, #1
	fldd	d24, .L27+64
	b	.L21
.L9:
	movw	r7, #8699
	movt	r7, 16409
	cmp	r3, r7
	beq	.L3
	cmp	r5, #0
	ble	.L11
	fldd	d23, .L27+104
	mov	r0, #4
	fldd	d24, .L27+112
	b	.L21
.L25:
	fsubd	d20, d7, d7
	mov	r0, #0
	fstd	d20, [r4, #8]
	fstd	d20, [r4]
	b	.L6
.L26:
	fldd	d5, [sp, #8]
	rsb	r0, r0, #0
	fldd	d6, [sp, #16]
	fnegd	d7, d5
	fnegd	d19, d6
	fstd	d7, [r4]
	fstd	d19, [r4, #8]
	b	.L6
.L5:
	fldd	d21, .L27+56
	mvn	r0, #0
	fldd	d22, .L27+64
.L22:
	faddd	d25, d7, d21
	faddd	d26, d25, d22
	fsubd	d27, d25, d26
	fstd	d26, [r4]
	faddd	d28, d27, d22
	fstd	d28, [r4, #8]
	b	.L6
.L7:
	fldd	d21, .L27
	mvn	r0, #1
	fldd	d22, .L27+8
	b	.L22
.L11:
	fldd	d21, .L27+104
	mvn	r0, #3
	fldd	d22, .L27+112
	b	.L22
.L10:
	fldd	d21, .L27+16
	mvn	r0, #2
	fldd	d22, .L27+24
	b	.L22
.L28:
	.align	3
.L27:
	.word	1413480448
	.word	1074340347
	.word	442655537
	.word	1038136417
	.word	2133852160
	.word	1074977148
	.word	2811466954
	.word	1038683793
	.word	0
	.word	1097859072
	.word	0
	.word	1127743488
	.word	1841940611
	.word	1071931184
	.word	1413480448
	.word	1073291771
	.word	442655537
	.word	1037087841
	.word	442499072
	.word	1037087841
	.word	771977331
	.word	1000544650
	.word	771751936
	.word	1000544650
	.word	622873025
	.word	964395930
	.word	1413480448
	.word	1075388923
	.word	442655537
	.word	1039184993
	.fnend
	.size	__ieee754_rem_pio2, .-__ieee754_rem_pio2
	.ident	"GCC: (GNU) 4.9"
	.section	.note.GNU-stack,"",%progbits
