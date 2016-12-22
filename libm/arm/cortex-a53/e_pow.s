    .text
    .align
    .global         pow
    .type           pow, %function
pow:
    .fnstart

.LFilterRange:
    movw            ip, #0x0000
    movt            ip, #0x4010
    vmov            d1, r2, r3
    cmp             r1, ip
    cmple           r3, ip
    movt            ip, #0x3fb0
    cmple           ip, r1
    cmple           ip, r3
    bgt             .LGotoKernel

.LFilterSpecial:
    cmp             r2, #0
    beq             .LSpecialY

.LNormalize:
    ubfx            r2, r1, #0, #20
    movw            r3, #0xB67A
    movt            r3, #0x000B
    cmp             r2, r3
    bge             .LNormalizeX2
    movw            r3, #0x988E
    movt            r3, #0x0003
    cmp             r2, r3
    movt            ip, #0x3ff0
    mov             r3, r1, asr #20
    orr             r1, r2, ip
    vmov            d0, r0, r1
    fconstdle       d3, #0x70
    fconstdgt       d3, #0x78
    sub             r3, r3, ip, asr #20
    fmsr            s4, r3
    vsub.f64        d31, d0,  d3
    vadd.f64        d30, d0,  d3
    vldrle          d4, .LDLogDP0
    vldrgt          d4, .LDLogDP
    fsitod          d2, s4
    vdiv.f64        d29, d31, d30

.LLog:
    fconstd         d6,  #0x08
    vldr            d5,  .LDLogCP
    vmul.f64        d4,  d1,  d4
    vldr            d21, .LDLogL1
    vmul.f64        d2,  d1,  d2
    vldr            d22, .LDLogL2
    vmul.f64        d5,  d1,  d5
    vldr            d23, .LDLogL3
    vmul.f64        d21, d1,  d21
    vldr            d24, .LDLogL4
    vmul.f64        d22, d1,  d22
    vldr            d25, .LDLogL5
    vmul.f64        d23, d1,  d23
    vadd.f64        d2,  d2,  d4
    vmul.f64        d24, d1,  d24
    vmul.f64        d6,  d6,  d5
    vmul.f64        d25, d1,  d25
    nop
    vmla.f64        d2,  d29, d6
    vmul.f64        d26, d29, d29
    vmul.f64        d5,  d29, d5
    vmul.f64        d24, d29, d24
    vmul.f64        d21, d29, d21
    vmul.f64        d25, d29, d25
    vmul.f64        d22, d29, d22
    vmul.f64        d23, d29, d23
    vmul.f64        d27, d26, d26
    nop
    vmla.f64        d2,  d26, d5
    vmul.f64        d24, d26, d24
    vmul.f64        d25, d26, d25
    nop
    vmul.f64        d28, d27, d27
    vmul.f64        d30, d27, d26
    vadd.f64        d23, d23, d24
    nop
    vmla.f64        d2,  d27, d21
    vmul.f64        d25, d26, d25
    vadd.f64        d23, d23, d25
    nop
    vmla.f64        d2,  d30, d22
    nop
    vmul.f64        d23, d28, d23
    vldr            d17, .LDln2
    vadd.f64        d16, d2, d23
    vadd.f64        d2,  d2, d23
.LSplitZ:
    vcvt.s32.f64    d2,  d2, #1
    vshl.u32        d3,  d2, #31
    vmvn.u32        d4,  d2
    vand.u32        d3,  d3, d4
    vbic.s32        d2,  d2, #1
    vshr.u32        d3,  d3, #30
    vadd.s32        d2,  d2, d3
    vcvt.f64.s32    d2,  d2, #1
    vsub.f64        d16, d16, d2
.LPowerOfTwo:
    vldr            d24, .LDExpE4
    fconstd         d20, #0x70
    vldr            d25, .LDExpE5
    fconstd         d19, #0x70
    vldr            d28, .LDExpE8
    vldr            d29, .LDExpE9
    vmul.f64        d16, d16, d17
    vldr            d21, .LDExpE12
    vldr            d26, .LDExpE6
    vldr            d30, .LDExpE10
    vldr            d22, .LDExpE2
    vmla.f64        d24, d16, d25
    vmla.f64        d28, d16, d29
    vmla.f64        d20, d16, d19
    vmul.f64        d3,  d16, d16
    vmul.f64        d21, d16, d21
    vldr            d27, .LDExpE7
    vldr            d31, .LDExpE11
    vmla.f64        d24, d3,  d26
    vmla.f64        d28, d3,  d30
    vmla.f64        d20, d3,  d22
    vmul.f64        d4,  d3,  d16
    vmul.f64        d5,  d3,  d3
    vldr            d23, .LDExpE3
    vmla.f64        d24, d4, d27
    vmla.f64        d28, d4, d31
    vmla.f64        d20, d4, d23
    vmul.f64        d6,  d5, d5
    vmul.f64        d21, d4, d21
    nop
    vmla.f64        d20, d6, d21
    nop
    vmul.f64        d24, d5, d24
    vmul.f64        d28, d6, d28
    vadd.f64        d24, d24, d28
    nop
    vadd.f64        d20, d20, d24
.LScaleBack:
    ftosid          s4, d2
    fmrs            r2, s4
    vmov            r0, r1, d20
    add             r1, r1, r2, asl #20
    bx              lr

.LNormalizeX2:
    movt            ip, #0x3ff0
    mov             r3, r1, asr #20
    orr             r1, r2, ip
    sub             r3, r3, ip, asr #20
    movt            ip, #0x0010
    sub             r1, r1, ip
    fconstd         d3, #0x70
    vmov            d0, r0, r1
    fmsr            s4, r3
    vsub.f64        d31, d0, d3
    vadd.f64        d30, d0, d3
    fsitod          d2, s4
    vdiv.f64        d29, d31, d30
    vsub.f64        d4, d3, d3
    vadd.f64        d2, d2, d3
    b               .LLog

.LSpecialY:
    vmov            d31, r0, r1
    movt            ip, #0x3FF0
    cmp             r3, #0
    vsqrt.f64       d30, d31
    vmul.f64        d29, d31, d31
    fconstd         d28, #0x70
    beq             .LSpecialY_Y0
    cmp             r3, ip
    movt            ip, #0x4000
    beq             .LSpecialY_Y1
    cmp             r3, ip
    movt            ip, #0x3FD0
    beq             .LSpecialY_Y2
    cmp             r3, ip
    movt            ip, #0x3FE0
    beq             .LSpecialY_Y1to4
    cmp             r3, ip
    bne             .LNormalize
.LSpecialY_Y1to2:
    vmov            r0, r1, d30
    bx              lr
.LSpecialY_Y1to4:
    vsqrt.f64       d31, d30
    vmov            r0, r1, d31
    bx              lr
.LSpecialY_Y0:
    vmov            r0, r1, d28
    bx              lr
.LSpecialY_Y1:
    bx              lr
.LSpecialY_Y2:
    vmov            r0, r1, d29
    bx              lr
.LGotoKernel:
    vmov            r2, r3, d1
    b               pow_kernel(PLT)

    .align  6
.LDLogDP0:
    .word   0x00000000
    .word   0x00000000
.LDLogDP:
    .word   0x473F7AD1
    .word   0x3FE2B803
.LDLogCP:
    .word   0xDC3A03FD
    .word   0x3FEEC709
.LDLogL1:
    .word   0x50EF9BD0
    .word   0x3FE2776C
.LDLogL2:
    .word   0x2A7CC0D7
    .word   0x3FDA6176
.LDLogL3:
    .word   0x39DABCF3
    .word   0x3FD484B1
.LDLogL4:
    .word   0xB8820814
    .word   0x3FD0C9AB
.LDLogL5:
    .word   0x234A0E59
    .word   0x3FCC658A
.LDln2:
    .word   0xFEFA39EF
    .word   0x3FE62E42
.LDExpE12:
    .word   0xeff8d898
    .word   0x3e21eed8
.LDExpE11:
    .word   0x67f544e4
    .word   0x3e5ae645
.LDExpE10:
    .word   0xb7789f5c
    .word   0x3e927e4f
.LDExpE9:
    .word   0xa556c734
    .word   0x3ec71de3
.LDExpE8:
    .word   0x1a01a01a
    .word   0x3efa01a0
.LDExpE7:
    .word   0x1a01a01a
    .word   0x3f2a01a0
.LDExpE6:
    .word   0x16c16c17
    .word   0x3f56c16c
.LDExpE5:
    .word   0x11111111
    .word   0x3f811111
.LDExpE4:
    .word   0x55555555
    .word   0x3fa55555
.LDExpE3:
    .word   0x55555555
    .word   0x3fc55555
.LDExpE2:
    .word   0x00000000
    .word   0x3fe00000

    .fnend
    .size   pow, .-pow
