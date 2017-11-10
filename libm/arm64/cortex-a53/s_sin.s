    .cpu cortex-a53+fp+simd
    .text
    .align	2
    .global	sin
    .type	sin, %function
sin:
    fmov    x0, d0
    ldr     d24, .LDS4
    fmul    d16,  d0,  d0
    mov     w2, 0x21fb
    movk    w2, 0x3fe9, lsl 16
    mov     w3, 0x0000
    movk    w3, 0x3e50, lsl 16
    ubfx    x1, x0, 32, 31
    cmp     w1, w2
    bgt     .LRange0TO6
.LRange7:
    fmul    d17, d16, d16
    ldr     d26, .LDS6
    fmul    d18, d16, d0
    ldr     d23, .LDS3
    ldr     d25, .LDS5
    fmul    d24, d16, d24
    fmul    d26, d16, d26
    ldr     d22, .LDS2
    ldr     d21, .LDS1
    fadd    d24, d23, d24
    fadd    d26, d25, d26
    cmp     w1, w3
    blt     .LRange7InExact
.LRange7Exact:
    fmul    d24, d16, d24
    fmul    d26, d17, d26
    fadd    d24, d22, d24
    fmul    d26, d16, d26
    fadd    d24, d24, d26
    fmul    d24, d16, d24
    fadd    d24, d21, d24
    fmul    d24, d18, d24
    fadd    d0,  d0,  d24
    ret
.LRange7InExact:
    fcvtzs  w3, d0
    cbnz    w3, .LRange7Exact
    ret

.LRange0TO6:
    mov     w2, 0x463b
    movk    w2, 0x401c, lsl 16
    cmp     w1, w2
    ble     .LRange3TO6
    mov     w2, 0x21fb
    movk    w2, 0x4139, lsl 16
    cmp     w1, w2
    bge     .LRange0TO1
.LRange2:
    ldr     d6,  .LDInvPiO2
    ldr     d7,  .LD18P52
    fmul    d3,  d0,  d6
    ldr     d30, .LDPiO2_1
    ldr     d31, .LDPiO2_1t
    fadd    d3,  d3,  d7
    fsub    d3,  d3,  d7
    fmul    d4,  d3, d30
    fmul    d5,  d3, d31
    fsub    d4,  d0,  d4
    fcvtzs  w3,  d3
    fsub    d6,  d4,  d5
    fmov    x6,  d6
    fsub    d7,  d4,  d6
    fmul    d16, d6,  d6
    ubfx    x7,  x6,  52,  11
    ubfx    x5,  x0,  52,  11
    sub     w4,  w5,  w7
    cmp     w4,  16
    bgt     .LRange2SecondRound
    fsub    d7,  d7,  d5
    tst     w3,  1
    bne     .LRange2RoundCos
.LRange2RoundSin:
    fmul    d17, d16, d16
    ldr     d24, .LDS4
    fmul    d18, d16, d6
    ldr     d26, .LDS6
    fmul    d24, d24, d16
    ldr     d23, .LDS3
    fmul    d26, d26, d16
    ldr     d25, .LDS5
    ldr     d22, .LDS2
    fmov    d27, 5.0e-1
    ldr     d21, .LDS1
    fadd    d24, d24, d23
    nop
    fadd    d26, d26, d25
    nop
    fmul    d21, d21, d18
    nop
    fmul    d27, d27, d7
    nop
    fmul    d24, d24, d16
    nop
    fmul    d26, d26, d17
    nop
    fadd    d24, d24, d22
    nop
    fmul    d26, d26, d16
    nop
    fadd    d24, d24, d26
    fmul    d24, d24, d18
    fsub    d24, d27, d24
    fmul    d24, d24, d16
    fsub    d24, d24, d7
    fsub    d24, d24, d21
    fsub    d0,  d6,  d24
    fsub    d1,  d24, d6
    tst     w3,  2
    fcsel   d0,  d1,  d0,  ne
    ret
.LRange2RoundCos:
    fmul    d17, d16, d16
    ldr     d23, .LDC3
    fmov    d28, 5.0e-1
    ldr     d26, .LDC6
    fmov    d27, 1.0e+0
    ldr     d22, .LDC2
    fmul    d23, d16, d23
    ldr     d25, .LDC5
    fmul    d26, d16, d26
    ldr     d21, .LDC1
    ldr     d24, .LDC4
    fadd    d23, d22, d23
    fmul    d18, d16, d28
    fadd    d26, d25, d26
    fmul    d20, d17, d17
    fmul    d23, d16, d23
    fsub    d19, d27, d18
    fmul    d26, d16, d26
    fmul    d29, d6,  d7
    fadd    d23, d21, d23
    fsub    d27, d27, d19
    fadd    d26, d24, d26
    nop
    fmul    d23, d16, d23
    fsub    d27, d27, d18
    fmul    d26, d20, d26
    nop
    fadd    d23, d23, d26
    fmul    d23, d16, d23
    fsub    d23, d23, d29
    fadd    d23, d27, d23
    fadd    d0,  d19, d23
    tst     w3,  2
    fneg    d1,  d0
    fcsel   d0,  d1,  d0,  ne
    ret
.LRange2SecondRound:
    fmov    d2, d4
    ldr     d30, .LDPiO2_2
    ldr     d31, .LDPiO2_2t
    fmul    d30, d30, d3
    fmul    d31, d31, d3
    fsub    d4,  d2,  d30
    fsub    d5,  d2,  d4
    fsub    d5,  d5,  d30
    fsub    d5,  d31, d5
    fsub    d6,  d4,  d5
    fmov    x6, d6
    ubfx    x7, x6, 52, 11
    sub     w4, w5, w7
    cmp     w4, 49
    bgt     .LRange2ThirdRound
    fsub    d7,  d4,  d6
    fmul    d16, d6,  d6
    fsub    d7,  d7,  d5
    tst     w3,  1
    bne     .LRange2RoundCos
    b       .LRange2RoundSin
.LRange2ThirdRound:
    fmov    d2, d4
    ldr     d30, .LDPiO2_3
    ldr     d31, .LDPiO2_3t
    fmul    d30, d30, d3
    fmul    d31, d31, d3
    fsub    d4,  d2,  d30
    fsub    d5,  d2,  d4
    fsub    d5,  d5,  d30
    fsub    d5,  d31, d5
    fsub    d6,  d4,  d5
    fsub    d7,  d4,  d6
    fmul    d16, d6,  d6
    fsub    d7,  d7,  d5
    tst     w3,  1
    bne     .LRange2RoundCos
    b       .LRange2RoundSin

.LRange3TO6:
    mov     w2, 0x6a7a
    movk    w2, 0x400f, lsl 16
    cmp     w1, w2
    bgt     .LRange3TO4
.LRange5TO6:
    mov     w2, 0xd97c
    movk    w2, 0x4002, lsl 16
    cmp     w1, w2
    bgt     .LRange5IsV
.LRange6IsV:
    mov     w2, 0x21fb
    movk    w2, 0x3ff9, lsl 16
    cmp     w1, w2
    beq     .LRange2
.LRange6:
    ubfx    x1,  x0,  32,  32
    cmp     w1,  wzr
    fmov    d1,  1.0e+0
    fmov    d4,  -1.0e+0
    fcsel   d1,  d1,  d4,  gt
    ldr     d2,  .LDPiO2_1
    ldr     d3,  .LDPiO2_1t
    fmul    d2,  d1,  d2
    fsub    d0,  d0,  d2
    fmul    d3,  d1,  d3
    fsub    d6,  d0,  d3
    fsub    d7,  d0,  d6
    fmul    d16, d6,  d6
    fmul    d17, d16, d16
    ldr     d23, .LDC3
    fmov    d28, 5.0e-1
    ldr     d26, .LDC6
    fmov    d27, 1.0e+0
    ldr     d22, .LDC2
    fmul    d23, d16, d23
    ldr     d25, .LDC5
    fmul    d26, d16, d26
    ldr     d21, .LDC1
    fsub    d7,  d7,  d3
    ldr     d24, .LDC4
    fadd    d23, d22, d23
    fmul    d18, d16, d28
    fadd    d26, d25, d26
    fmul    d20, d17, d17
    fmul    d23, d16, d23
    fsub    d19, d27, d18
    fmul    d26, d16, d26
    fmul    d29, d6,  d7
    fadd    d23, d21, d23
    fsub    d27, d27, d19
    fadd    d26, d24, d26
    nop
    fmul    d23, d16, d23
    fsub    d27, d27, d18
    fmul    d26, d20, d26
    nop
    fadd    d23, d23, d26
    fmul    d23, d16, d23
    fsub    d23, d23, d29
    fadd    d23, d27, d23
    fadd    d0,  d19, d23
    fneg    d1,  d0
    fcsel   d0,  d1,  d0,  le
    ret

.LRange5IsV:
    mov     w2, 0x21fb
    movk    w2, 0x4009, lsl 16
    cmp     w1, w2
    beq     .LRange2
.LRange5:
    ubfx    x1,  x0,  32,  32
    cmp     w1,  wzr
    fmov    d1,  2.0e+0
    fmov    d4,  -2.0e+0
    fcsel   d1,  d1,  d4,  gt
    ldr     d2,  .LDPiO2_1
    ldr     d3,  .LDPiO2_1t
    fmul    d2,  d1,  d2
    fsub    d0,  d0,  d2
    fmul    d3,  d1,  d3
    fsub    d6,  d0,  d3
    fsub    d7,  d0,  d6
    fmul    d16, d6, d6
    fmul    d17, d16, d16
    ldr     d24, .LDS4
    fmul    d18, d16, d6
    ldr     d26, .LDS6
    fmul    d24, d24, d16
    ldr     d23, .LDS3
    fmul    d26, d26, d16
    ldr     d25, .LDS5
    fsub    d7,  d7,  d3
    ldr     d22, .LDS2
    fmov    d27, 5.0e-1
    ldr     d21, .LDS1
    fadd    d24, d24, d23
    nop
    fadd    d26, d26, d25
    nop
    fmul    d21, d21, d18
    nop
    fmul    d27, d27, d7
    nop
    fmul    d24, d24, d16
    nop
    fmul    d26, d26, d17
    nop
    fadd    d24, d24, d22
    nop
    fmul    d26, d26, d16
    nop
    fadd    d24, d24, d26
    fmul    d24, d24, d18
    fsub    d24, d27, d24
    fmul    d24, d24, d16
    fsub    d24, d24, d7
    fsub    d24, d24, d21
    fsub    d0,  d6,  d24
    fneg    d0,  d0
    ret

.LRange3TO4:
    mov     w2, 0xfdbc
    movk    w2, 0x4015, lsl 16
    cmp     w1, w2
    bgt     .LRange3IsV
.LRange4IsV:
    mov     w2, 0xd97c
    movk    w2, 0x4012, lsl 16
    cmp     w1, w2
    beq     .LRange2
.LRange4:
    ubfx    x1,  x0,  32,  32
    cmp     w1,  wzr
    fmov    d1,  3.0e+0
    fmov    d4,  -3.0e+0
    fcsel   d1,  d1,  d4,  gt
    ldr     d2,  .LDPiO2_1
    ldr     d3,  .LDPiO2_1t
    fmul    d2,  d1,  d2
    fsub    d0,  d0,  d2
    fmul    d3,  d1,  d3
    fsub    d6,  d0,  d3
    fsub    d7,  d0,  d6
    fmul    d16, d6, d6
    fmul    d17, d16, d16
    ldr     d23, .LDC3
    fmov    d28, 5.0e-1
    ldr     d26, .LDC6
    fmov    d27, 1.0e+0
    ldr     d22, .LDC2
    fmul    d23, d16, d23
    ldr     d25, .LDC5
    fmul    d26, d16, d26
    ldr     d21, .LDC1
    fsub    d7,  d7,  d3
    ldr     d24, .LDC4
    fadd    d23, d22, d23
    fmul    d18, d16, d28
    fadd    d26, d25, d26
    fmul    d20, d17, d17
    fmul    d23, d16, d23
    fsub    d19, d27, d18
    fmul    d26, d16, d26
    fmul    d29, d6,  d7
    fadd    d23, d21, d23
    fsub    d27, d27, d19
    fadd    d26, d24, d26
    nop
    fmul    d23, d16, d23
    fsub    d27, d27, d18
    fmul    d26, d20, d26
    nop
    fadd    d23, d23, d26
    fmul    d23, d16, d23
    fsub    d23, d23, d29
    fadd    d23, d27, d23
    fadd    d0,  d19, d23
    fneg    d1,  d0
    fcsel   d0,  d1,  d0,  gt
    ret

.LRange3IsV:
    mov     w2, 0x21fb
    movk    w2, 0x4019, lsl 16
    cmp     w1, w2
    beq     .LRange2
.LRange3:
    ubfx    x1,  x0,  32,  32
    cmp     w1,  wzr
    fmov    d1,  4.0e+0
    fmov    d4,  -4.0e+0
    fcsel   d1,  d1,  d4,  gt
    ldr     d2, .LDPiO2_1
    ldr     d3, .LDPiO2_1t
    fmul    d2,  d1,  d2
    fsub    d0,  d0,  d2
    fmul    d3, d1, d3
    fsub    d6, d0, d3
    fsub    d7, d0, d6
    fmul    d16, d6, d6
    fmul    d17, d16, d16
    ldr     d24, .LDS4
    fmul    d18, d16, d6
    ldr     d26, .LDS6
    fmul    d24, d24, d16
    ldr     d23, .LDS3
    fmul    d26, d26, d16
    ldr     d25, .LDS5
    fsub    d7,  d7,  d3
    ldr     d22, .LDS2
    fmov    d27, 5.0e-1
    ldr     d21, .LDS1
    fadd    d24, d24, d23
    nop
    fadd    d26, d26, d25
    nop
    fmul    d21, d21, d18
    nop
    fmul    d27, d27, d7
    nop
    fmul    d24, d24, d16
    nop
    fmul    d26, d26, d17
    nop
    fadd    d24, d24, d22
    nop
    fmul    d26, d26, d16
    nop
    fadd    d24, d24, d26
    fmul    d24, d24, d18
    fsub    d24, d27, d24
    fmul    d24, d24, d16
    fsub    d24, d24, d7
    fsub    d24, d24, d21
    fsub    d0,  d6,  d24
    ret

.LRange0TO1:
    b       sin_kernel

    .align  3
.LD18P52:
    .word   0x00000000
    .word   0x43380000
    .align  3
.LDInvPiO2:
    .word   0x6DC9C883
    .word   0x3FE45F30
    .align  3
.LDPiO2_1:
    .word   0x54400000
    .word   0x3FF921FB
    .align  3
.LDPiO2_1t:
    .word   0x1A626331
    .word   0x3DD0B461
    .align  3
.LDPiO2_2:
    .word   0x1A600000
    .word   0x3DD0B461
    .align  3
.LDPiO2_2t:
    .word   0x2E037073
    .word   0x3BA3198A
    .align  3
.LDPiO2_3:
    .word   0x2E000000
    .word   0x3BA3198A
    .align  3
.LDPiO2_3t:
    .word   0x252049C1
    .word   0x397B839A
    .align  3
.LDS6:
    .word   0x5ACFD57C
    .word   0x3DE5D93A
    .align  3
.LDS5:
    .word   0x8A2B9CEB
    .word   0xBE5AE5E6
    .align  3
.LDS4:
    .word   0x57B1FE7D
    .word   0x3EC71DE3
    .align  3
.LDS3:
    .word   0x19C161D5
    .word   0xBF2A01A0
    .align  3
.LDS2:
    .word   0x1110F8A6
    .word   0x3F811111
    .align  3
.LDS1:
    .word   0x55555549
    .word   0xBFC55555
    .align  3
.LDC6:
    .word   0xBE8838D4
    .word   0xBDA8FAE9
    .align  3
.LDC5:
    .word   0xBDB4B1C4
    .word   0x3E21EE9E
    .align  3
.LDC4:
    .word   0x809C52AD
    .word   0xBE927E4F
    .align  3
.LDC3:
    .word   0x19CB1590
    .word   0x3EFA01A0
    .align  3
.LDC2:
    .word   0x16C15177
    .word   0xBF56C16C
    .align  3
.LDC1:
    .word   0x5555554C
    .word   0x3FA55555
    .align  3
    .size	sin, .-sin
#if (LDBL_MANT_DIG == 53)
    .weak   sinl
    .equ    sinl, sin
#endif

