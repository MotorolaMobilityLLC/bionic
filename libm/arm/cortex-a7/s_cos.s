    .text
	.align	2
	.global	cos
	.type	cos, %function
cos:
	.fnstart
    fmdrr       d0, r0, r1
    bic         r0, r1, #0x80000000
    movw        ip, #0x463B
    movt        ip, #0x401C
    cmp         r0, ip
    ble         .LRange3TO7
    movw        ip, #0x21FB
    movt        ip, #0x4139
    cmp         r0, ip
    bge         .LRange0TO1

.LRange2:
    vldr        d4, .LDInvPiO2
    vldr        d3, .LD18P52
    vmla.f64    d3, d0, d4
    vldr        d2, .LD18P52
    vsub.f64    d2, d3, d2
    vldr        d5, .LDPiO2_1
    vmls.f64    d0, d2, d5
    vldr        d1, .LDPiO2_1t
    vmul.f64    d1, d2, d1
    mov         r0, r0, asr #20
    vsub.f64    d6, d0, d1
    ftosizd     s8, d2
    fmrs        r3, s8  @ int
    fmrrd       r1, r2, d6
    vmul.f64    d16, d6, d6
    vsub.f64    d3, d0, d6
    ubfx        r1, r2, #20, #11
    rsb         r1, r1, r0
    cmp         r1, #16
    bgt         .LRange2SecondRound
    tst         r3, #1
    beq         .LRange2FirstRoundCos
.LRange2FirstRoundSin:
    vldr        d31, .LDS6
    vldr        d29, .LDS5
    vmla.f64    d29, d16, d31
    vldr        d30, .LDS4
    vldr        d28, .LDS3
    vmla.f64    d28, d16, d30
    vldr        d26, .LDS2
    fconstd     d19, #0x60
    vmul.f64    d17, d16, d16
    vmla.f64    d26, d16, d28
    vmul.f64    d29, d17, d29
    vsub.f64    d7, d3, d1
    vldr        d27, .LDS1
    vmul.f64    d19, d19, d7
    vmul.f64    d18, d16, d6
    vmla.f64    d26, d16, d29
    vmls.f64    d19, d18, d26
    vnmls.f64   d7, d16, d19
    vmls.f64    d7, d18, d27
    vsub.f64    d7, d6, d7
    tst         r3, #2
    fmrrd       r0, r1, d7
    eoreq       r1, r1, #0x80000000
    bx          lr
    
.LRange2FirstRoundCos:
    vldr        d24, .LDC3
    vldr        d22, .LDC2
    vmla.f64    d22, d16, d24
    vldr        d25, .LDC6
    vldr        d23, .LDC5
    vmla.f64    d23, d16, d25
    vldr        d20, .LDC1
    vldr        d21, .LDC4
    vmla.f64    d20, d16, d22
    vmla.f64    d21, d16, d23
    vmul.f64    d17, d16, d16
    vsub.f64    d7, d3, d1
    fconstd     d18, #0x60
    fconstd     d3, #0x70
    vmul.f64    d18, d18, d16
    vmul.f64    d20, d16, d20
    vmul.f64    d17, d17, d17
    vmul.f64    d7, d6, d7
    vsub.f64    d19, d3, d18
    vmla.f64    d20, d17, d21
    vsub.f64    d3, d3, d19
    vnmls.f64   d7, d16, d20
    vsub.f64    d18, d3, d18
    vadd.f64    d18, d18, d7
    vadd.f64    d7, d19, d18
    tst         r3, #2
    fmrrd       r0, r1, d7
    eorne       r1, r1, #0x80000000
    bx          lr

.LRange2SecondRound:
    vldr        d3, .LDPiO2_2
    vmul.f64    d3, d2, d3
    vldr        d4, .LDPiO2_2t
    vmul.f64    d4, d2, d4
    vsub.f64    d5, d0, d3
    vsub.f64    d0, d0, d5
    vsub.f64    d0, d0, d3
    vsub.f64    d1, d4, d0
    vsub.f64    d6, d5, d1
    fmrrd       r1, r2, d6
    vmul.f64    d16, d6, d6
    ubfx        r1, r2, #20, #11
    rsb         r1, r1, r0
    cmp         r1, #49
    bgt         .LRange2ThirdRound
    vsub.f64    d3, d5, d6
    tst         r3, #1
    beq         .LRange2FirstRoundCos
    b           .LRange2FirstRoundSin

.LRange2ThirdRound:
    vldr        d3, .LDPiO2_3
    vmul.f64    d3, d2, d3
    vldr        d4, .LDPiO2_3t
    vmul.f64    d4, d2, d4
    vsub.f64    d0, d5, d3
    vsub.f64    d5, d5, d0
    vsub.f64    d3, d5, d3
    vsub.f64    d1, d4, d3
    vsub.f64    d6, d0, d1
    vsub.f64    d3, d0, d6
    vmul.f64    d16, d6, d6
    tst         r3, #1
    beq         .LRange2FirstRoundCos
    b           .LRange2FirstRoundSin

.LRange0TO1:
    fmrrd       r0, r1, d0
    b	        cos_kernel(PLT)

.LRange7:
    movw        ip, #0xa09e
    movt        ip, #0x3e46
    cmp         r0, ip
    blt         .LRange7InExact
.LRange7Exact:
    vmul.f64    d16, d0, d0
    vldr        d24, .LDC3
    vldr        d22, .LDC2
    vmla.f64    d22, d16, d24
    vldr        d25, .LDC6
    vldr        d23, .LDC5
    vmla.f64    d23, d16, d25
    vldr        d20, .LDC1
    vldr        d21, .LDC4
    vmla.f64    d20, d16, d22
    vmla.f64    d21, d16, d23
    vmul.f64    d17, d16, d16
    vldr        d7, .LDZero
    fconstd     d18, #0x60
    fconstd     d3, #0x70
    vmul.f64    d18, d18, d16
    vmul.f64    d20, d16, d20
    vmul.f64    d17, d17, d17
    vmul.f64    d7, d0, d7
    vsub.f64    d19, d3, d18
    vmla.f64    d20, d17, d21
    vsub.f64    d3, d3, d19
    vnmls.f64   d7, d16, d20
    vsub.f64    d18, d3, d18
    vadd.f64    d18, d18, d7
    vadd.f64    d7, d19, d18 
    fmrrd       r0, r1, d7
    bx          lr
.LRange7InExact:
    ftosizd     s15, d0
    fmrs        ip, s15 @ int
    cmp         ip, #0
    bne         .LRange7Exact
    fconstd     d0, #0x70
    fmrrd       r0, r1, d0
    bx          lr
    
    .align  5
.LD18P52:
    .word   0x00000000
    .word   0x43380000
.LDInvPiO2:
    .word   0x6DC9C883
    .word   0x3FE45F30
.LDPiO2_1:
    .word   0x54400000
    .word   0x3FF921FB
.LDPiO2_1t:
    .word   0x1A626331
    .word   0x3DD0B461
.LDPiO2_2:
    .word   0x1A600000
    .word   0x3DD0B461
.LDPiO2_2t:
    .word   0x2E037073
    .word   0x3BA3198A
.LDPiO2_3:
    .word   0x2E000000
    .word   0x3BA3198A
.LDPiO2_3t:
    .word   0x252049C1
    .word   0x397B839A
.LDS6:
	.word	0x5ACFD57C
	.word	0x3DE5D93A
.LDS5:
	.word	0x8A2B9CEB
	.word	0xBE5AE5E6
.LDS4:
    .word	0x57B1FE7D
	.word	0x3EC71DE3
.LDS3:
	.word	0x19C161D5
	.word	0xBF2A01A0
.LDS2:
	.word	0x1110F8A6
	.word	0x3F811111
.LDS1:
	.word	0x55555549
	.word	0xBFC55555
.LDC6:
	.word	0xBE8838D4
	.word	0xBDA8FAE9
.LDC5:
	.word	0xBDB4B1C4
	.word	0x3E21EE9E
.LDC4:
	.word	0x809C52AD
	.word	0xBE927E4F
.LDC3:
	.word	0x19CB1590
	.word	0x3EFA01A0
.LDC2:
	.word	0x16C15177
	.word	0xBF56C16C
.LDC1:
	.word	0x5555554C
	.word	0x3FA55555
.LDZero:
    .word   0x00000000
    .word   0x00000000
    
.LRange3TO7:
    @ if (ix <= 0x3fe921fb)
    movw        ip, #0x21FB
    movt        ip, #0x3FE9
    cmp         r0, ip
    ble         .LRange7
    
.LRange3TO6:
    @ if (ix > 0x400f6a7a)
    movw        ip, #0x6a7a
    movt        ip, #0x400f
    cmp         r0, ip
    bgt         .LRange3TO4
    
.LRange5TO6:
    @ if (ix > 0x4002d97c)
    movw        ip, #0xd97c
    movt        ip, #0x4002
    cmp         r0, ip
    bgt         .LRange5
    
.LRange6:
    movw        ip, #0x21fb
    movt        ip, #0x3ff9
    cmp         r0, ip
    beq         .LRange2
    cmp         r1, #0
    fconstdgt   d1, #0x70
    fconstdle   d1, #0xf0
    vldr        d2,  .LDPiO2_1
    vldr        d3,  .LDPiO2_1t
    vmls.f64    d0,  d1,  d2
    vmul.f64    d3,  d1,  d3
    vsub.f64    d6,  d0,  d3
    vsub.f64    d7,  d0,  d6
    vmul.f64    d16, d6,  d6

    vmul.f64    d16, d6, d6
    vldr        d31, .LDS6
    vldr        d29, .LDS5
    vmla.f64    d29, d16, d31
    vldr        d30, .LDS4
    vldr        d28, .LDS3
    vmla.f64    d28, d16, d30
    vldr        d26, .LDS2
    fconstd     d19, #0x60
    vmul.f64    d17, d16, d16
    vmla.f64    d26, d16, d28
    vmul.f64    d29, d17, d29
    vsub.f64    d7, d7, d3
    vldr        d27, .LDS1
    vmul.f64    d19, d19, d7
    vmul.f64    d18, d16, d6
    vmla.f64    d26, d16, d29
    vmls.f64    d19, d18, d26
    vnmls.f64   d7, d16, d19
    vmls.f64    d7, d18, d27
    vsub.f64    d7, d6, d7
    fmrrd       r0, r1, d7
    eorgt       r1, r1, #0x80000000
    bx          lr

.LRange5:
    movw        ip, #0x21fb
    movt        ip, #0x4009
    cmp         r0, ip
    beq         .LRange2
    cmp         r1, #0
    fconstdgt   d1, #0x00
    fconstdle   d1, #0x80
    vldr        d2,  .LDPiO2_1
    vldr        d3,  .LDPiO2_1t
    vmls.f64    d0,  d1,  d2
    vmul.f64    d3,  d1,  d3
    vsub.f64    d6,  d0,  d3
    vsub.f64    d7,  d0,  d6
    vmul.f64    d16, d6, d6
    vldr        d24, .LDC3
    vldr        d22, .LDC2
    vmla.f64    d22, d16, d24
    vldr        d25, .LDC6
    vldr        d23, .LDC5
    vmla.f64    d23, d16, d25
    vldr        d20, .LDC1
    vldr        d21, .LDC4
    vmla.f64    d20, d16, d22
    vmla.f64    d21, d16, d23
    vmul.f64    d17, d16, d16
    vsub.f64    d7,  d7,  d3
    fconstd     d18, #0x60
    fconstd     d3, #0x70
    vmul.f64    d18, d18, d16
    vmul.f64    d20, d16, d20
    vmul.f64    d17, d17, d17
    vmul.f64    d7, d6, d7
    vsub.f64    d19, d3, d18
    vmla.f64    d20, d17, d21
    vsub.f64    d3, d3, d19
    vnmls.f64   d7, d16, d20
    vsub.f64    d18, d3, d18
    vadd.f64    d18, d18, d7
    vadd.f64    d7, d19, d18
    fmrrd       r0, r1, d7
    eor         r1, r1, #0x80000000
    bx          lr

.LRange3TO4:
    movw        ip, #0xFDBC
    movt        ip, #0x4015
    cmp         r0, ip
    bgt         .LRange3
    
.LRange4:
    movw        ip, #0xd97c
    movt        ip, #0x4012
    cmp         r0, ip
    beq         .LRange2
    cmp         r1, #0
    fconstdgt   d1, #0x08
    fconstdle   d1, #0x88
    vldr        d2,  .LDPiO2_1
    vldr        d3,  .LDPiO2_1t
    vmls.f64    d0,  d1,  d2
    vmul.f64    d3,  d1,  d3
    vsub.f64    d6,  d0,  d3
    vsub.f64    d7,  d0,  d6
    vmul.f64    d16, d6, d6
    vldr        d31, .LDS6
    vldr        d29, .LDS5
    vmla.f64    d29, d16, d31
    vldr        d30, .LDS4
    vldr        d28, .LDS3
    vmla.f64    d28, d16, d30
    vldr        d26, .LDS2
    fconstd     d19, #0x60
    vmul.f64    d17, d16, d16
    vmla.f64    d26, d16, d28
    vmul.f64    d29, d17, d29
    vsub.f64    d7,  d7,  d3
    vldr        d27, .LDS1
    vmul.f64    d19, d19, d7
    vmul.f64    d18, d16, d6
    vmla.f64    d26, d16, d29
    vmls.f64    d19, d18, d26
    vnmls.f64   d7, d16, d19
    vmls.f64    d7, d18, d27
    vsub.f64    d7, d6, d7
    fmrrd       r0, r1, d7
    eorle       r1, r1, #0x80000000
    bx          lr

.LRange3:
    movw        ip, #0x21fb
    movt        ip, #0x4019
    cmp         r0, ip
    beq         .LRange2
    cmp         r1, #0
    fconstdgt   d1, #0x10
    fconstdle   d1, #0x90
    vldr        d2,  .LDPiO2_1
    vldr        d3,  .LDPiO2_1t
    vmls.f64    d0,  d1,  d2
    vmul.f64    d3,  d1,  d3
    vsub.f64    d6,  d0,  d3
    vsub.f64    d7,  d0,  d6
    vmul.f64    d16, d6, d6
    vldr        d24, .LDC3
    vldr        d22, .LDC2
    vmla.f64    d22, d16, d24
    vldr        d25, .LDC6
    vldr        d23, .LDC5
    vmla.f64    d23, d16, d25
    vldr        d20, .LDC1
    vldr        d21, .LDC4
    vmla.f64    d20, d16, d22
    vmla.f64    d21, d16, d23
    vmul.f64    d17, d16, d16
    vsub.f64    d7,  d7,  d3
    fconstd     d18, #0x60
    fconstd     d3, #0x70
    vmul.f64    d18, d18, d16
    vmul.f64    d20, d16, d20
    vmul.f64    d17, d17, d17
    vmul.f64    d7, d6, d7
    vsub.f64    d19, d3, d18
    vmla.f64    d20, d17, d21
    vsub.f64    d3, d3, d19
    vnmls.f64   d7, d16, d20
    vsub.f64    d18, d3, d18
    vadd.f64    d18, d18, d7
    vadd.f64    d7, d19, d18
    fmrrd       r0, r1, d7
    bx          lr
	.fnend
	.size	cos, .-cos
#if (LDBL_MANT_DIG == 53)
    .weak   cosl
    .equ    cosl, cos
#endif

