	.cpu cortex-a53+fp+simd
	.section	.text.unlikely,"ax",%progbits
	.align	2
	.global	__kernel_rem_pio2
	.type	__kernel_rem_pio2, %function
__kernel_rem_pio2:
	mov	w8, 24
	sub	w5, w2, #3
	sub	sp, sp, #608
	sdiv	w9, w5, w8
	adrp	x7, .LANCHOR0
	stp	x29, x30, [sp, -112]!
	add	x6, x7, :lo12:.LANCHOR0
	cmp	w9, wzr
	add	x29, sp, 0
	csel	w5, w9, wzr, ge
	stp	x21, x22, [sp,32]
	mvn	w21, w5
	stp	x27, x28, [sp,80]
	ldr	w27, [x6,w4,sxtw 2]
	stp	x25, x26, [sp,64]
	madd	w21, w21, w8, w2
	mov	w25, w4
	sub	w4, w3, #1
	stp	x23, x24, [sp,48]
	stp	x19, x20, [sp,16]
	mov	x23, x1
	str	x0, [x29,152]
	sub	w11, w5, w4
	add	w10, w4, w27
	mov	x1, 0
	add	x6, x6, 16
	add	x28, x29, 400
	stp	d8, d9, [sp,96]
.L2:
	cmp	w10, w1
	add	w0, w11, w1
	blt	.L86
	tbnz	w0, #31, .L69
	ldr	w12, [x6,w0,sxtw 2]
	scvtf	d7, w12
	b	.L3
.L69:
	fmov	d7, xzr
.L3:
	str	d7, [x28,x1,lsl 3]
	add	x1, x1, 1
	b	.L2
.L86:
	mov	x2, 0
	add	x22, x29, 400
.L5:
	cmp	w27, w2
	blt	.L7
	fmov	d0, xzr
	add	w19, w3, w2
	mov	x20, 0
.L8:
	cmp	w4, w20
	sub	w19, w19, #1
	blt	.L87
	ldr	x9, [x29,152]
	ldr	d5, [x22,w19,sxtw 3]
	ldr	d9, [x9,x20,lsl 3]
	add	x20, x20, 1
	fmul	d6, d9, d5
	fadd	d0, d0, d6
	b	.L8
.L87:
	add	x24, x29, 560
	str	d0, [x24,x2,lsl 3]
	add	x2, x2, 1
	b	.L5
.L7:
	mov	w26, 24
	sub	w1, w26, w21
	mov	w19, w27
	add	x24, x29, 560
	add	x20, x29, 160
	str	w1, [x29,148]
.L9:
	sxtw	x26, w19
	ldr	d31, .LC0
	ldr	d0, [x24,x26,lsl 3]
	ldr	d30, .LC1
	mov	w18, w19
	mov	x7, 0
.L10:
	cmp	w18, wzr
	ble	.L88
	fmul	d8, d0, d31
	sub	w18, w18, #1
	ldr	d3, [x24,w18,sxtw 3]
	fcvtzs	w30, d8
	scvtf	d1, w30
	fmul	d2, d1, d30
	fsub	d4, d0, d2
	fadd	d0, d1, d3
	fcvtzs	w8, d4
	str	w8, [x20,x7]
	add	x7, x7, 4
	b	.L10
.L88:
	mov	w0, w21
	str	x3, [x29,120]
	str	x4, [x29,136]
	str	x5, [x29,128]
	bl	scalbn
	fmov	d9, d0
	fmov	d0, 1.25e-1
	fmul	d0, d9, d0
	bl	floor
	fmov	d8, 8.0e+0
	cmp	w21, wzr
	fmul	d1, d0, d8
	ldr	x3, [x29,120]
	ldr	x4, [x29,136]
	ldr	x5, [x29,128]
	fsub	d2, d9, d1
	fcvtzs	w28, d2
	scvtf	d3, w28
	fsub	d9, d2, d3
	ble	.L12
	sub	w10, w19, #1
	sbfiz	x11, x10, 2, 32
	ldrb	w15, [x29,148]
	mov	w12, 23
	ldr	w14, [x20,x11]
	sub	w13, w12, w21
	asr	w16, w14, w15
	lsl	w17, w16, w15
	sub	w18, w14, w17
	add	w28, w28, w16
	str	w18, [x20,x11]
	asr	w22, w18, w13
	b	.L13
.L12:
	bne	.L14
	sub	w2, w19, #1
	ldr	w22, [x20,w2,sxtw 2]
	asr	w22, w22, 23
	b	.L13
.L14:
	fmov	d4, 5.0e-1
	mov	w22, 0
	fcmpe	d9, d4
	blt	.L16
	mov	w22, 2
	b	.L15
.L13:
	cmp	w22, wzr
	ble	.L16
.L15:
	mov	x17, 0
	add	w28, w28, 1
	mov	w16, w17
	mov	w0, w17
	mov	w12, 16777215
	mov	w11, 16777216
.L17:
	cmp	w16, w19
	bge	.L89
	ldr	w13, [x20,x17]
	cbnz	w0, .L18
	cbz	w13, .L19
	sub	w15, w11, w13
	mov	w0, 1
	str	w15, [x20,x17]
	b	.L19
.L18:
	sub	w14, w12, w13
	mov	w0, 1
	str	w14, [x20,x17]
.L19:
	add	w16, w16, 1
	add	x17, x17, 4
	b	.L17
.L89:
	cmp	w21, wzr
	ble	.L21
	cmp	w21, 1
	beq	.L22
	cmp	w21, 2
	bne	.L21
	sub	w30, w19, #1
	sbfiz	x8, x30, 2, 32
	ldr	w7, [x20,x8]
	and	w9, w7, 4194303
	str	w9, [x20,x8]
	b	.L21
.L22:
	sub	w6, w19, #1
	sbfiz	x1, x6, 2, 32
	ldr	w2, [x20,x1]
	and	w10, w2, 8388607
	str	w10, [x20,x1]
.L21:
	cmp	w22, 2
	bne	.L16
	fmov	d0, 1.0e+0
	fsub	d9, d0, d9
	cbz	w0, .L16
	mov	w0, w21
	str	x3, [x29,120]
	str	x4, [x29,136]
	str	x5, [x29,128]
	bl	scalbn
	fsub	d9, d9, d0
	ldr	x5, [x29,128]
	ldr	x4, [x29,136]
	ldr	x3, [x29,120]
.L16:
	fcmp	d9, #0.0
	bne	.L24
	sub	w2, w19, #1
	mov	w10, w2
	mov	w1, 0
.L25:
	cmp	w10, w27
	blt	.L90
	ldr	w6, [x20,w10,sxtw 2]
	sub	w10, w10, #1
	orr	w1, w1, w6
	b	.L25
.L90:
	cbnz	w1, .L27
	mov	w9, 1
.L28:
	sub	w28, w27, w9
	ldr	w11, [x20,w28,sxtw 2]
	cbnz	w11, .L91
	add	w9, w9, 1
	b	.L28
.L91:
	adrp	x12, .LANCHOR0
	add	x13, x12, :lo12:.LANCHOR0
	add	w16, w19, 1
	add	w15, w3, w19
	add	x17, x29, 400
	add	w19, w19, w9
	add	x18, x13, 16
.L30:
	cmp	w19, w16
	blt	.L9
	add	w22, w16, w5
	fmov	d29, xzr
	mov	x7, 0
	ldr	w14, [x18,w22,sxtw 2]
	scvtf	d25, w14
	str	d25, [x17,w15,sxtw 3]
.L31:
	cmp	w4, w7
	blt	.L92
	ldr	x8, [x29,152]
	sub	w30, w15, w7
	ldr	d26, [x8,x7,lsl 3]
	ldr	d27, [x17,w30,sxtw 3]
	add	x7, x7, 1
	fmul	d28, d26, d27
	fadd	d29, d29, d28
	b	.L31
.L92:
	str	d29, [x24,w16,sxtw 3]
	add	w15, w15, 1
	add	w16, w16, 1
	b	.L30
.L24:
	fmov	d0, d9
	neg	w0, w21
	bl	scalbn
	ldr	d5, .LC1
	fcmpe	d0, d5
	blt	.L93
	ldr	d6, .LC0
	add	w19, w19, 1
	fmul	d7, d0, d6
	add	w21, w21, 24
	fcvtzs	w4, d7
	scvtf	d16, w4
	fmul	d17, d16, d5
	fsub	d18, d0, d17
	fcvtzs	w5, d18
	str	w5, [x20,x26,lsl 2]
	str	w4, [x20,w19,sxtw 2]
	b	.L35
.L93:
	fcvtzs	w3, d0
	str	w3, [x20,x26,lsl 2]
.L35:
	mov	w0, w21
	fmov	d0, 1.0e+0
	bl	scalbn
	ldr	d22, .LC0
	mov	w0, w19
.L36:
	tbnz	w0, #31, .L94
	sxtw	x21, w0
	sub	w0, w0, #1
	ldr	w26, [x20,x21,lsl 2]
	scvtf	d23, w26
	fmul	d24, d23, d0
	fmul	d0, d0, d22
	str	d24, [x24,x21,lsl 3]
	b	.L36
.L94:
	adrp	x20, .LANCHOR0
	mov	x1, 0
	add	x4, x20, :lo12:.LANCHOR0
	add	x10, x29, 240
.L38:
	subs	w26, w19, w1
	bmi	.L43
	fmov	d18, xzr
	mov	x2, 0
.L44:
	cmp	w2, w27
	bgt	.L40
	cmp	w2, w1
	bgt	.L40
	add	w3, w26, w2
	add	x5, x4, 2784
	ldr	d19, [x24,w3,sxtw 3]
	ldr	d20, [x5,x2,lsl 3]
	add	x2, x2, 1
	fmul	d21, d20, d19
	fadd	d18, d18, d21
	b	.L44
.L40:
	str	d18, [x10,x1,lsl 3]
	add	x1, x1, 1
	b	.L38
.L43:
	cmp	w25, 3
	bhi	.L45
	adrp	x24, .L47
	add	x27, x24, :lo12:.L47
	ldrb	w6, [x27,w25,uxtw]
	adr	x7, .Lrtx47
	add	x6, x7, w6, sxtb #2
	br	x6
.Lrtx47:
	.section	.rodata
	.align	0
	.align	2
.L47:
	.byte	(.L46 - .Lrtx47) / 4
	.byte	(.L48 - .Lrtx47) / 4
	.byte	(.L48 - .Lrtx47) / 4
	.byte	(.L49 - .Lrtx47) / 4
	.section	.text.unlikely
.L49:
	mov	w6, w19
	add	x15, x29, 240
	b	.L50
.L48:
	mov	w12, w19
	fmov	d24, xzr
	add	x11, x29, 240
	b	.L51
.L46:
	fmov	d25, xzr
	add	x13, x29, 240
.L52:
	tbnz	w19, #31, .L95
	ldr	d26, [x13,w19,sxtw 3]
	sub	w19, w19, #1
	fadd	d25, d25, d26
	b	.L52
.L95:
	cbz	w22, .L54
	fneg	d25, d25
.L54:
	str	d25, [x23]
	b	.L45
.L51:
	tbnz	w12, #31, .L96
	ldr	d23, [x11,w12,sxtw 3]
	sub	w12, w12, #1
	fadd	d24, d24, d23
	b	.L51
.L96:
	fmov	d19, d24
	cbz	w22, .L56
	fneg	d19, d24
.L56:
	ldr	d20, [x11]
	mov	x25, 0
	fsub	d21, d20, d24
	str	d19, [x23]
.L57:
	add	x25, x25, 1
	cmp	w19, w25
	blt	.L97
	ldr	d22, [x11,x25,lsl 3]
	fadd	d21, d21, d22
	b	.L57
.L97:
	cbz	w22, .L59
	fneg	d21, d21
.L59:
	str	d21, [x23,8]
	b	.L45
.L50:
	cmp	w6, wzr
	ble	.L98
	sub	w8, w6, #1
	sbfiz	x7, x6, 3, 32
	sbfiz	x9, x8, 3, 32
	ldr	d5, [x15,x7]
	ldr	d6, [x15,x9]
	mov	w6, w8
	fadd	d7, d6, d5
	fsub	d16, d6, d7
	fadd	d17, d5, d16
	str	d17, [x15,x7]
	str	d7, [x15,x9]
	b	.L50
.L98:
	mov	w30, w19
.L61:
	cmp	w30, 1
	ble	.L99
	sub	w16, w30, #1
	sbfiz	x17, x30, 3, 32
	sbfiz	x18, x16, 3, 32
	ldr	d3, [x15,x17]
	ldr	d1, [x15,x18]
	mov	w30, w16
	fadd	d2, d1, d3
	fsub	d4, d1, d2
	fadd	d9, d3, d4
	str	d9, [x15,x17]
	str	d2, [x15,x18]
	b	.L61
.L99:
	fmov	d0, xzr
.L63:
	cmp	w19, 1
	ble	.L100
	ldr	d8, [x15,w19,sxtw 3]
	sub	w19, w19, #1
	fadd	d0, d0, d8
	b	.L63
.L100:
	cbnz	w22, .L65
	ldr	x22, [x15]
	ldr	x14, [x15,8]
	str	d0, [x23,16]
	str	x22, [x23]
	str	x14, [x23,8]
	b	.L45
.L65:
	ldr	d27, [x15]
	ldr	d28, [x15,8]
	fneg	d29, d27
	fneg	d30, d28
	fneg	d31, d0
	str	d29, [x23]
	str	d30, [x23,8]
	str	d31, [x23,16]
.L45:
	and	w0, w28, 7
	ldp	x19, x20, [sp,16]
	ldp	x21, x22, [sp,32]
	ldp	x23, x24, [sp,48]
	ldp	x25, x26, [sp,64]
	ldp	x27, x28, [sp,80]
	ldp	d8, d9, [sp,96]
	ldp	x29, x30, [sp], 112
	add	sp, sp, 608
	ret
.L27:
	sub	w21, w21, #24
	mov	w19, w2
.L68:
	ldr	w0, [x20,w19,sxtw 2]
	cbnz	w0, .L35
	sub	w19, w19, #1
	sub	w21, w21, #24
	b	.L68
	.size	__kernel_rem_pio2, .-__kernel_rem_pio2
	.align	3
.LC0:
	.word	0
	.word	1047527424
	.align	3
.LC1:
	.word	0
	.word	1097859072
	.section	.rodata
	.align	4
.LANCHOR0 = . + 0
	.type	init_jk, %object
	.size	init_jk, 16
init_jk:
	.word	3
	.word	4
	.word	4
	.word	6
	.type	ipio2, %object
	.size	ipio2, 2760
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
	.word	4703257
	.word	12806093
	.word	14477321
	.word	2786137
	.word	12875403
	.word	9837734
	.word	14528324
	.word	13719321
	.word	343717
	.word	16713477
	.word	4161075
	.word	15217346
	.word	14569368
	.word	3308987
	.word	12795174
	.word	15690526
	.word	6224031
	.word	3809077
	.word	13300351
	.word	1935345
	.word	2199676
	.word	8135786
	.word	16412373
	.word	7810352
	.word	4406037
	.word	12981429
	.word	10295747
	.word	12764333
	.word	4279596
	.word	6094860
	.word	4619654
	.word	2978275
	.word	10143387
	.word	25139
	.word	8180404
	.word	9938868
	.word	13980983
	.word	16137943
	.word	1577123
	.word	16545357
	.word	2792804
	.word	11261808
	.word	16284771
	.word	5746810
	.word	15144215
	.word	5654976
	.word	14276155
	.word	3703975
	.word	13312804
	.word	7834326
	.word	2315354
	.word	12132096
	.word	1772273
	.word	14667289
	.word	16724383
	.word	6954598
	.word	6379417
	.word	4717484
	.word	14188414
	.word	12018978
	.word	9037874
	.word	6340582
	.word	13485295
	.word	603756
	.word	13909853
	.word	14147094
	.word	14564184
	.word	9608158
	.word	2630354
	.word	15238696
	.word	5069026
	.word	3328710
	.word	1499912
	.word	13336032
	.word	5292055
	.word	10952179
	.word	6021144
	.word	3412782
	.word	6427267
	.word	84099
	.word	6000373
	.word	8368301
	.word	15919390
	.word	4409928
	.word	13854480
	.word	14212522
	.word	4349870
	.word	13525354
	.word	10758154
	.word	11835859
	.word	15902214
	.word	8353628
	.word	8635043
	.word	8928353
	.word	7893898
	.word	5934255
	.word	12441455
	.word	6530605
	.word	13352948
	.word	15696269
	.word	6799654
	.word	4573781
	.word	3594698
	.word	13805608
	.word	9265602
	.word	7850258
	.word	1320452
	.word	10176018
	.word	12868036
	.word	4507080
	.word	9548365
	.word	15931136
	.word	11355092
	.word	15026473
	.word	1103357
	.word	16563712
	.word	13407262
	.word	15650416
	.word	16072211
	.word	8450540
	.word	12838835
	.word	2685127
	.word	9700755
	.word	4092353
	.word	11733294
	.word	15942923
	.word	10228360
	.word	8069291
	.word	10466606
	.word	12751431
	.word	3093115
	.word	7165196
	.word	9480050
	.word	2090859
	.word	9882417
	.word	4855417
	.word	14842177
	.word	9035764
	.word	9934056
	.word	8709858
	.word	9908633
	.word	7073160
	.word	3563359
	.word	982459
	.word	11835976
	.word	7119975
	.word	4354673
	.word	3300749
	.word	12064159
	.word	648636
	.word	2437517
	.word	3765495
	.word	1836336
	.word	68621
	.word	6817867
	.word	5828140
	.word	9480775
	.word	190324
	.word	2414269
	.word	10911223
	.word	7489646
	.word	15668895
	.word	10917006
	.word	16159156
	.word	5329873
	.word	15862479
	.word	3381280
	.word	8276981
	.word	6841266
	.word	6242013
	.word	220480
	.word	8358277
	.word	2708053
	.word	12608567
	.word	1103981
	.word	3295282
	.word	7687259
	.word	13922638
	.word	7230533
	.word	12650763
	.word	6944042
	.word	13985300
	.word	10290983
	.word	5243997
	.word	14367668
	.word	12941034
	.word	1571207
	.word	8219465
	.word	12199709
	.word	2714006
	.word	11324614
	.word	5510317
	.word	7004816
	.word	9034120
	.word	5272108
	.word	12493828
	.word	9701239
	.word	7352563
	.word	2620416
	.word	11039210
	.word	4833894
	.word	4055140
	.word	8641943
	.word	9912227
	.word	16618563
	.word	9209357
	.word	14565681
	.word	10303890
	.word	9203933
	.word	15185687
	.word	3923720
	.word	2832149
	.word	10518620
	.word	9666650
	.word	9572624
	.word	14215183
	.word	11501676
	.word	4980699
	.word	1019960
	.word	7739481
	.word	1418594
	.word	12307297
	.word	12159431
	.word	12402704
	.word	324306
	.word	2585929
	.word	16168683
	.word	12264155
	.word	11146250
	.word	3090057
	.word	7766884
	.word	3357449
	.word	1741838
	.word	11156049
	.word	12755741
	.word	11464111
	.word	1189468
	.word	5096045
	.word	10254893
	.word	9918144
	.word	8601347
	.word	16183305
	.word	9191467
	.word	10039661
	.word	504889
	.word	1384460
	.word	6013912
	.word	12882677
	.word	4959686
	.word	10865230
	.word	13449127
	.word	3582438
	.word	9736875
	.word	6832861
	.word	14574361
	.word	15699062
	.word	5409640
	.word	3660796
	.word	11248046
	.word	3216863
	.word	10595840
	.word	14351116
	.word	6704484
	.word	11994605
	.word	3171625
	.word	12539479
	.word	3866439
	.word	12188010
	.word	15974005
	.word	14652200
	.word	3178667
	.word	16157798
	.word	1428228
	.word	402170
	.word	1959129
	.word	10793789
	.word	9378647
	.word	642358
	.word	15286862
	.word	10796563
	.word	11871027
	.word	1747696
	.word	11035983
	.word	10863058
	.word	999179
	.word	13465691
	.word	7797027
	.word	297851
	.word	7477129
	.word	5482182
	.word	14839407
	.word	60399
	.word	5786267
	.word	12049092
	.word	12215978
	.word	13619062
	.word	1901265
	.word	3010993
	.word	12687756
	.word	7843267
	.word	14305414
	.word	10509815
	.word	16023750
	.word	3141804
	.word	10153181
	.word	12344383
	.word	7200464
	.word	2082704
	.word	11983658
	.word	3810723
	.word	10137344
	.word	9655213
	.word	284598
	.word	11808041
	.word	8290379
	.word	10946522
	.word	961142
	.word	10574203
	.word	2757142
	.word	2996188
	.word	16639482
	.word	16702345
	.word	16629385
	.word	7108324
	.word	16558342
	.word	7372862
	.word	1404549
	.word	16746493
	.word	474664
	.word	3368801
	.word	8788010
	.word	15383885
	.word	11528115
	.word	7237007
	.word	3762069
	.word	6012721
	.word	4773764
	.word	1498928
	.word	4402631
	.word	3498277
	.word	13529289
	.word	12110640
	.word	16608447
	.word	10616996
	.word	14969861
	.word	10542426
	.word	4681505
	.word	13767266
	.word	8674489
	.word	4809072
	.word	14702187
	.word	86681
	.word	3626320
	.word	12047646
	.word	12906803
	.word	6254099
	.word	14954589
	.word	11087493
	.word	12825117
	.word	3551905
	.word	10794760
	.word	13939178
	.word	2225942
	.word	14969231
	.word	7864103
	.word	8389388
	.word	2965645
	.word	10538319
	.word	10069280
	.word	13869747
	.word	679215
	.word	4389300
	.word	13359633
	.word	13680253
	.word	12704667
	.word	12392363
	.word	8495818
	.word	6056456
	.word	1529134
	.word	5570599
	.word	15733887
	.word	8783841
	.word	6556436
	.word	9257366
	.word	14597767
	.word	2817498
	.word	11937131
	.word	3443067
	.word	16708357
	.word	10403769
	.word	5204584
	.word	11020874
	.word	5948495
	.word	12384301
	.word	9984727
	.word	9816052
	.word	9260301
	.word	10893856
	.word	6248356
	.word	11616020
	.word	9779328
	.word	73932
	.word	8838513
	.word	11984585
	.word	16081087
	.word	1140045
	.word	7014145
	.word	11317388
	.word	13680818
	.word	4740433
	.word	981790
	.word	12808853
	.word	3868323
	.word	3489984
	.word	8117254
	.word	13387232
	.word	16394574
	.word	13159126
	.word	4322280
	.word	14574716
	.word	14181531
	.word	3260121
	.word	12818340
	.word	13916279
	.word	12968809
	.word	1301232
	.word	3947194
	.word	4593734
	.word	6255957
	.word	16104914
	.word	13013614
	.word	6106796
	.word	15549454
	.word	4341276
	.word	8897633
	.word	15334697
	.word	15980263
	.word	13270050
	.word	3510639
	.word	12967944
	.word	9295871
	.word	14838382
	.word	13041072
	.word	12650643
	.word	7626108
	.word	11709803
	.word	10317517
	.word	8090174
	.word	6951366
	.word	11128823
	.word	14644009
	.word	12241333
	.word	5308599
	.word	897762
	.word	2407028
	.word	6323685
	.word	9099380
	.word	2888973
	.word	792705
	.word	9725566
	.word	1452289
	.word	7764639
	.word	12516861
	.word	15680854
	.word	3571417
	.word	1300972
	.word	12171915
	.word	16553924
	.word	2598961
	.word	12807921
	.word	3589524
	.word	5679320
	.word	11905204
	.word	969935
	.word	2984210
	.word	3430255
	.word	9000492
	.word	14929561
	.word	12132566
	.word	11165291
	.word	10234430
	.word	13393681
	.word	4852733
	.word	16512225
	.word	7158670
	.word	2918114
	.word	8705257
	.word	11121916
	.word	13758191
	.word	13186350
	.word	6371631
	.word	4464952
	.word	13162779
	.word	720001
	.word	6966011
	.word	14162991
	.word	8696915
	.word	9214286
	.word	13378132
	.word	14439722
	.word	14075584
	.word	9836811
	.word	12087322
	.word	6591849
	.word	6314534
	.word	15618623
	.word	987519
	.word	1160692
	.word	16108540
	.word	2997300
	.word	15645748
	.word	13393384
	.word	6315741
	.word	10194535
	.word	15676306
	.word	12064713
	.word	10180705
	.word	12343265
	.word	13009745
	.word	1064664
	.word	4747741
	.word	14490669
	.word	10557615
	.word	4598817
	.word	14152537
	.word	9992921
	.word	12604574
	.word	16418383
	.word	16516694
	.word	11434469
	.word	3547785
	.word	2272568
	.word	14455655
	.word	11200597
	.word	3679874
	.word	10217418
	.word	10751313
	.word	11613081
	.word	972713
	.word	4719977
	.word	15774309
	.word	10979455
	.word	9915528
	.word	3592697
	.word	11768353
	.word	4883067
	.word	2215832
	.word	14458688
	.word	5588956
	.word	3831009
	.word	4385639
	.word	14654974
	.word	6280286
	.word	10774395
	.word	8039610
	.word	10679893
	.word	2328619
	.word	5618241
	.word	552537
	.word	8792609
	.word	8603449
	.word	15131529
	.word	13934309
	.word	4258633
	.word	15292159
	.word	13242140
	.word	9066949
	.word	2882196
	.word	12960211
	.word	13616399
	.word	11426523
	.word	8832327
	.word	6439813
	.word	3900961
	.word	9730348
	.word	8872208
	.word	8080426
	.word	1715328
	.word	1228611
	.word	9447048
	.word	8993912
	.word	14992552
	.word	8117221
	.word	12729028
	.word	15397926
	.word	9070583
	.word	12554765
	.word	2859877
	.word	11637565
	.word	752829
	.word	14438820
	.word	6544679
	.word	14541161
	.word	1676442
	.word	9775528
	.word	2674280
	.word	11857161
	.word	2137924
	.word	13277262
	.word	6521456
	.word	2325630
	.word	3324175
	.word	9368999
	.word	15160852
	.word	586017
	.word	2792885
	.word	5078639
	.word	5314981
	.word	11270581
	.word	14081922
	.word	6413718
	.word	144918
	.word	10435268
	.word	10592899
	.word	7204210
	.word	8031545
	.word	11122818
	.word	6042219
	.word	5973830
	.word	15545344
	.word	7798994
	.word	5633276
	.word	5069057
	.word	8417760
	.zero	8
	.type	PIo2, %object
	.size	PIo2, 64
PIo2:
	.word	1073741824
	.word	1073291771
	.word	0
	.word	1047807021
	.word	-2147483648
	.word	1022903960
	.word	1610612736
	.word	997772369
	.word	-2147483648
	.word	972036995
	.word	1073741824
	.word	947528992
	.word	-2147483648
	.word	920879650
	.word	0
	.word	896135965
	.ident	"GCC: (crosstool-NG linaro-1.13.1-4.8-2014.04 - Linaro GCC 4.8-2014.04) 4.8.3 20140401 (prerelease)"
