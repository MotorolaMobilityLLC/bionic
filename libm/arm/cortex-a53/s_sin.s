    .text
    .align      2
    .global	    sin
    .type	    sin, %function
sin:
    .fnstart
    fmdrr       d0, r0, r1
    bic         r0, r1, #0x80000000
    vldr        d2, .LDInvPiO2
    movw        ip, #0x463B
    movt        ip, #0x401C
    cmp         r0, ip
    ble         .LRange3TO7
    vmul.f64    d2, d0, d2
    vldr        d3, .LD18P52
    movw        ip, #0x21FB
    movt        ip, #0x4139
    cmp         r0, ip
    bge         .LRange0TO1

.LRange2:
    vadd.f64    d2, d2, d3
    vldr        d4, .LDPiO2_1
    mov         r0, r0, asr #20
    vldr        d5, .LDPiO2_1t
    vsub.f64    d2, d2, d3
    nop
    vmul.f64    d4, d2, d4
    vmul.f64    d1, d2, d5
    ftosizd     s10, d2
    nop
    vsub.f64    d0, d0, d4
    fmrs        r3, s10  @ int
    vsub.f64    d6, d0, d1
    nop
    fmrrd       r1, r2, d6
    vmul.f64    d16, d6, d6
    vsub.f64    d3, d0, d6
    nop
    ubfx        r1, r2, #20, #11
    rsb         r1, r1, r0
    cmp         r1, #16
    bgt         .LRange2SecondRound
    tst         r3, #1
    bne         .LRange2FirstRoundCos
.LRange2FirstRoundSin:
    vmul.f64    d17, d16, d16
    vldr        d24, .LDS4
    vmul.f64    d18, d16, d6
    vldr        d26, .LDS6
    vmul.f64    d24, d24, d16
    vldr        d23, .LDS3
    vmul.f64    d26, d26, d16
    vldr        d25, .LDS5
    vsub.f64    d7,  d3,  d1
    vldr        d22, .LDS2
    fconstd     d27, #0x60
    vldr        d21, .LDS1
    vadd.f64    d24, d24, d23
    nop
    vadd.f64    d26, d26, d25
    nop
    vmul.f64    d21, d21, d18
    nop
    vmul.f64    d27, d27, d7
    nop
    vmul.f64    d24, d24, d16
    nop
    vmul.f64    d26, d26, d17
    nop
    vadd.f64    d24, d24, d22
    nop
    vmul.f64    d26, d26, d16
    nop
    vadd.f64    d24, d24, d26
    vmul.f64    d24, d24, d18
    vsub.f64    d24, d27, d24
    vmul.f64    d24, d24, d16
    vsub.f64    d24, d24, d7
    vsub.f64    d24, d24, d21
    vsub.f64    d24, d6,  d24
    tst         r3, #2
    fmrrd       r0, r1, d24
    eorne       r1, r1, #0x80000000
    bx          lr

.LRange2FirstRoundCos:
    vmul.f64    d17, d16, d16
    vldr        d23, .LDC3
    fconstd     d28, #0x60
    vldr        d26, .LDC6
    fconstd     d27, #0x70
    vldr        d22, .LDC2
    vmul.f64    d23, d16, d23
    vldr        d25, .LDC5
    vmul.f64    d26, d16, d26
    vldr        d21, .LDC1
    vsub.f64    d7,  d3,  d1
    vldr        d24, .LDC4
    vadd.f64    d23, d22, d23
    vmul.f64    d18, d16, d28
    vadd.f64    d26, d25, d26
    vmul.f64    d20, d17, d17
    vmul.f64    d23, d16, d23
    vsub.f64    d19, d27, d18
    vmul.f64    d26, d16, d26
    vmul.f64    d29, d6,  d7
    vadd.f64    d23, d21, d23
    vsub.f64    d27, d27, d19
    vadd.f64    d26, d24, d26
    nop
    vmul.f64    d23, d16, d23
    vsub.f64    d27, d27, d18
    vmul.f64    d26, d20, d26
    nop
    vadd.f64    d23, d23, d26
    vmul.f64    d23, d16, d23
    vsub.f64    d23, d23, d29
    vadd.f64    d23, d27, d23
    vadd.f64    d7,  d19, d23
    tst         r3,  #2
    fmrrd       r0,  r1,  d7
    eorne       r1,  r1,  #0x80000000
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
    bne         .LRange2FirstRoundCos
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
    bne         .LRange2FirstRoundCos
    b           .LRange2FirstRoundSin

.LRange0TO1:
    fmrrd       r0, r1, d0
    b           sin_kernel(PLT)

.LRange7:
    vmul.f64    d16,  d0,  d0
    vldr        d24, .LDS4
    movw        ip, #0x0000
    movt        ip, #0x3e50
    cmp         r0, ip
    blt         .LRange7InExact
.LRange7Exact:
    vmul.f64    d17, d16, d16
    vldr        d26, .LDS6
    vmul.f64    d18, d16, d0
    vldr        d23, .LDS3
    vmul.f64    d24, d24, d16
    vldr        d25, .LDS5
    vmul.f64    d26, d26, d16
    vldr        d22, .LDS2
    vldr        d21, .LDS1
    vadd.f64    d24, d24, d23
    nop
    vadd.f64    d26, d26, d25
    nop
    vmul.f64    d24, d24, d16
    nop
    vmul.f64    d26, d26, d17
    nop
    vadd.f64    d24, d24, d22
    nop
    vmul.f64    d26, d26, d16
    nop
    vadd.f64    d24, d24, d26
    vmul.f64    d24, d16, d24
    vadd.f64    d24, d21, d24
    vmul.f64    d24, d18, d24
    vadd.f64    d24, d0,  d24
    fmrrd       r0,  r1,  d24
    bx          lr
.LRange7InExact:
    ftosizd     s15, d0
    fmrs        ip, s15 @ int
    cmp         ip, #0
    bne         .LRange7Exact
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
    .word   0x5ACFD57C
    .word   0x3DE5D93A
.LDS5:
    .word   0x8A2B9CEB
    .word   0xBE5AE5E6
.LDS4:
    .word   0x57B1FE7D
    .word   0x3EC71DE3
.LDS3:
    .word   0x19C161D5
    .word   0xBF2A01A0
.LDS2:
    .word   0x1110F8A6
    .word   0x3F811111
.LDS1:
    .word   0x55555549
    .word   0xBFC55555
.LDC6:
    .word   0xBE8838D4
    .word   0xBDA8FAE9
.LDC5:
    .word   0xBDB4B1C4
    .word   0x3E21EE9E
.LDC4:
    .word   0x809C52AD
    .word   0xBE927E4F
.LDC3:
    .word   0x19CB1590
    .word   0x3EFA01A0
.LDC2:
    .word   0x16C15177
    .word   0xBF56C16C
.LDC1:
    .word   0x5555554C
    .word   0x3FA55555
    
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
    vmul.f64    d2, d0, d2
    vldr        d3, .LD18P52
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
    vmul.f64    d17, d16, d16
    vldr        d23, .LDC3
    fconstd     d28, #0x60
    vldr        d26, .LDC6
    fconstd     d27, #0x70
    vldr        d22, .LDC2
    vmul.f64    d23, d16, d23
    vldr        d25, .LDC5
    vmul.f64    d26, d16, d26
    vldr        d21, .LDC1
    vsub.f64    d7,  d7,  d3
    vldr        d24, .LDC4
    vadd.f64    d23, d22, d23
    vmul.f64    d18, d16, d28
    vadd.f64    d26, d25, d26
    vmul.f64    d20, d17, d17
    vmul.f64    d23, d16, d23
    vsub.f64    d19, d27, d18
    vmul.f64    d26, d16, d26
    vmul.f64    d29, d6,  d7
    vadd.f64    d23, d21, d23
    vsub.f64    d27, d27, d19
    vadd.f64    d26, d24, d26
    nop
    vmul.f64    d23, d16, d23
    vsub.f64    d27, d27, d18
    vmul.f64    d26, d20, d26
    nop
    vadd.f64    d23, d23, d26
    vmul.f64    d23, d16, d23
    vsub.f64    d23, d23, d29
    vadd.f64    d23, d27, d23
    vadd.f64    d7,  d19, d23
    fmrrd       r0,  r1,  d7
    eorle       r1,  r1,  #0x80000000
    bx          lr

.LRange5:
    vmul.f64    d2, d0, d2
    vldr        d3, .LD18P52
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
    vmul.f64    d17, d16, d16
    vldr        d24, .LDS4
    vmul.f64    d18, d16, d6
    vldr        d26, .LDS6
    vmul.f64    d24, d24, d16
    vldr        d23, .LDS3
    vmul.f64    d26, d26, d16
    vldr        d25, .LDS5
    vsub.f64    d7,  d7,  d3
    vldr        d22, .LDS2
    fconstd     d27, #0x60
    vldr        d21, .LDS1
    vadd.f64    d24, d24, d23
    nop
    vadd.f64    d26, d26, d25
    nop
    vmul.f64    d21, d21, d18
    nop
    vmul.f64    d27, d27, d7
    nop
    vmul.f64    d24, d24, d16
    nop
    vmul.f64    d26, d26, d17
    nop
    vadd.f64    d24, d24, d22
    nop
    vmul.f64    d26, d26, d16
    nop
    vadd.f64    d24, d24, d26
    vmul.f64    d24, d24, d18
    vsub.f64    d24, d27, d24
    vmul.f64    d24, d24, d16
    vsub.f64    d24, d24, d7
    vsub.f64    d24, d24, d21
    vsub.f64    d24, d6,  d24
    fmrrd       r0, r1, d24
    eor         r1, r1, #0x80000000
    bx          lr
    
.LRange3TO4:
    movw        ip, #0xFDBC
    movt        ip, #0x4015
    cmp         r0, ip
    bgt         .LRange3
    
.LRange4:
    vmul.f64    d2, d0, d2
    vldr        d3, .LD18P52
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
    vmul.f64    d17, d16, d16
    vldr        d23, .LDC3
    fconstd     d28, #0x60
    vldr        d26, .LDC6
    fconstd     d27, #0x70
    vldr        d22, .LDC2
    vmul.f64    d23, d16, d23
    vldr        d25, .LDC5
    vmul.f64    d26, d16, d26
    vldr        d21, .LDC1
    vsub.f64    d7,  d7,  d3
    vldr        d24, .LDC4
    vadd.f64    d23, d22, d23
    vmul.f64    d18, d16, d28
    vadd.f64    d26, d25, d26
    vmul.f64    d20, d17, d17
    vmul.f64    d23, d16, d23
    vsub.f64    d19, d27, d18
    vmul.f64    d26, d16, d26
    vmul.f64    d29, d6,  d7
    vadd.f64    d23, d21, d23
    vsub.f64    d27, d27, d19
    vadd.f64    d26, d24, d26
    nop
    vmul.f64    d23, d16, d23
    vsub.f64    d27, d27, d18
    vmul.f64    d26, d20, d26
    nop
    vadd.f64    d23, d23, d26
    vmul.f64    d23, d16, d23
    vsub.f64    d23, d23, d29
    vadd.f64    d23, d27, d23
    vadd.f64    d7,  d19, d23
    fmrrd       r0,  r1,  d7
    eorgt       r1,  r1,  #0x80000000
    bx          lr

.LRange3:
    vmul.f64    d2, d0, d2
    vldr        d3, .LD18P52
    movw        ip, #0x21fb
    movt        ip, #0x4019
    cmp         r0, ip
    beq         .LRange2
    cmp         r1, #0
    fconstdgt   d1, #0x10
    fconstdle   d1, #0x90
    vldr        d2, .LDPiO2_1
    vldr        d3, .LDPiO2_1t
    vmls.f64    d0, d1, d2
    vmul.f64    d3, d1, d3
    vsub.f64    d6, d0, d3
    vsub.f64    d7, d0, d6
    vmul.f64    d16, d6, d6
    vmul.f64    d17, d16, d16
    vldr        d24, .LDS4
    vmul.f64    d18, d16, d6
    vldr        d26, .LDS6
    vmul.f64    d24, d24, d16
    vldr        d23, .LDS3
    vmul.f64    d26, d26, d16
    vldr        d25, .LDS5
    vsub.f64    d7,  d7,  d3
    vldr        d22, .LDS2
    fconstd     d27, #0x60
    vldr        d21, .LDS1
    vadd.f64    d24, d24, d23
    nop
    vadd.f64    d26, d26, d25
    nop
    vmul.f64    d21, d21, d18
    nop
    vmul.f64    d27, d27, d7
    nop
    vmul.f64    d24, d24, d16
    nop
    vmul.f64    d26, d26, d17
    nop
    vadd.f64    d24, d24, d22
    nop
    vmul.f64    d26, d26, d16
    nop
    vadd.f64    d24, d24, d26
    vmul.f64    d24, d24, d18
    vsub.f64    d24, d27, d24
    vmul.f64    d24, d24, d16
    vsub.f64    d24, d24, d7
    vsub.f64    d24, d24, d21
    vsub.f64    d24, d6,  d24
    fmrrd       r0, r1, d24
    bx          lr
    .fnend
    .size        sin, .-sin
#if (LDBL_MANT_DIG == 53)
    .weak   sinl
    .equ    sinl, sin
#endif

