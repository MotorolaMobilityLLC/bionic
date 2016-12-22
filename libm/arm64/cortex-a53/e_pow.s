    .text
    .align	2
    .global	pow
    .type	pow, %function
pow:

    fmov    x0, d0
    ldr     d5, .LDLogDP0
    mov     w5,  #0x988e
    ldr     d4, .LDLogDP
    movk    w5, 0x3, lsl 16
    fmov    d2, 1.0e+0
    ubfx    x4, x0, 32, 20
    fmov    d3, 1.5e+0
    cmp     w4, w5
    mov     w6, #0xb679
    fcsel   d3, d2, d3, ls
    movk    w6, 0xb, lsl 16
    fcsel   d4, d5, d4, ls
    mov     w7, #0x3fe00000
    cmp     w4, w6
    mov     w8, #0x3ff00000
    csel    w7, w7, w8, hi
    mov     x5, x0
    fcsel   d3, d2, d3, hi
    orr     w4, w4, w7
    fcsel   d4, d5, d4, hi
    ubfx    x2, x0, 32, 32
    bfi     x5, x4, 32, 32
    fmov    d6, x5
    sub     w9, w2, w7
    fmov    x1, d1 
    fsub    d2, d6, d3
    fadd    d5, d6, d3
    asr     w9, w9, 20
    mov     w6, #0xc0500000
    ubfx    x3, x1, 32, 32
    nop
    add     w4, w2, w6
    add     w5, w3, w6 
    fdiv    d29, d2, d5
    scvtf   d2, w9
    cmp     w4, #0x00600000
    bhi     .LGotoKernel
    cmp     w5, #0x00600000
    bhi     .LGotoKernel
    cbz     w1, .LSpecialY

.LLog:
    fmov    d6,  3.0e+0
    ldr     d5,  .LDLogCP
    fmul    d4,  d1,  d4
    ldr     d21, .LDLogL1
    fmul    d2,  d1,  d2
    ldr     d22, .LDLogL2
    fmul    d5,  d1,  d5
    ldr     d23, .LDLogL3
    fmul    d21, d1,  d21
    ldr     d24, .LDLogL4
    fmul    d22, d1,  d22
    ldr     d25, .LDLogL5
    fmul    d23, d1,  d23
    fadd    d2,  d2,  d4
    fmul    d24, d1,  d24
    fmul    d6,  d6,  d5
    fmul    d25, d1,  d25
    nop
    fmadd   d2,  d29, d6,  d2
    fmul    d26, d29, d29
    fmul    d5,  d29, d5
    fmul    d24, d29, d24
    fmul    d21, d29, d21
    fmul    d25, d29, d25
    fmul    d22, d29, d22
    fmul    d23, d29, d23
    fmul    d27, d26, d26
    nop
    fmadd   d2,  d26, d5,  d2
    fmul    d24, d26, d24
    fmul    d25, d26, d25
    nop
    fmul    d28, d27, d27
    fmul    d30, d27, d26
    fadd    d23, d23, d24
    nop
    fmadd   d2,  d27, d21, d2
    fmul    d25, d26, d25
    fadd    d23, d23, d25
    nop
    fmadd   d2,  d30, d22, d2
    nop
    fmul    d23, d28, d23
    ldr     d17, .LDln2
    fadd    d16, d2, d23
    fadd    d2,  d2, d23

.LSplitZ:
    fcvtzs  w0,  d2,  #1
    mov     w4,  #0x00000001
    lsl     w1,  w0,  #31
    mvn     w2,  w0
    and     w3,  w1,  w2
    bic     w4,  w0,  w4
    lsr     w3,  w3,  #30
    add     w0,  w3,  w4
    scvtf   d2,  w0,  #1 
    fsub    d16, d16, d2

.LPowerOfTwo:
    ldr     d24, .LDExpE4
    fmov    d20, 1.0e+0
    ldr     d25, .LDExpE5
    fmov    d19, 1.0e+0
    ldr     d28, .LDExpE8
    ldr     d29, .LDExpE9
    fmul    d16, d16, d17
    ldr     d21, .LDExpE12
    ldr     d26, .LDExpE6
    ldr     d30, .LDExpE10
    ldr     d22, .LDExpE2
    fmadd   d24, d16, d25, d24
    fmadd   d28, d16, d29, d28
    fmadd   d20, d16, d19, d20
    fmul    d3,  d16, d16
    fmul    d21, d16, d21
    ldr     d27, .LDExpE7
    ldr     d31, .LDExpE11
    fmadd   d24, d3,  d26, d24
    fmadd   d28, d3,  d30, d28
    fmadd   d20, d3,  d22, d20
    fmul    d4,  d3,  d16
    fmul    d5,  d3,  d3
    ldr     d23, .LDExpE3
    fmadd   d24, d4, d27, d24
    fmadd   d28, d4, d31, d28
    fmadd   d20, d4, d23, d20
    fmul    d6,  d5, d5
    fmul    d21, d4, d21
    nop
    fmadd   d20, d6, d21, d20
    nop
    fmul    d24, d5, d24
    fmul    d28, d6, d28
    fadd    d24, d24, d28
    nop
    fadd    d20, d20, d24

.LScaleBack:
    fmov    x0, d20
    fmov    x1, d20
    ubfx    x1, x1, 32, 32
    fcvtzs  w2, d2
    add     w2, w1, w2, lsl 20
    bfi     x0, x2, 32, 32
    fmov    d0, x0
    ret

.LSpecialY:
    mov     w5, #0x3fd00000
    mov     w6, #0x00100000
    sub     w4, w3, w5
    cbz     w4, .LSpecialY_Y1to4
    sub     w4, w4, w6
    cbz     w4, .LSpecialY_Y1to2
    sub     w4, w4, w6
    cbz     w4, .LSpecialY_Y1
    sub     w4, w4, w6
    cbnz    w4, .LLog
.LSpecialY_Y2:
    fmul    d0, d0, d0
    ret
.LSpecialY_Y1:
    ret
.LSpecialY_Y1to2:
    fsqrt   d0, d0
    ret
.LSpecialY_Y1to4:
    fsqrt   d0, d0
    fsqrt   d0, d0
    ret

.LGotoKernel:
    b       pow_kernel

    .align	3
.LDLogDP0:
    .word   0x00000000
    .word   0x00000000
    .align  3
.LDLogDP:
    .word   0x473F7AD1
    .word   0x3FE2B803
    .align  3
.LDLogCP:
    .word   0xDC3A03FD
    .word   0x3FEEC709
    .align  3
.LDLogL1:
    .word   0x50EF9BD0
    .word   0x3FE2776C
    .align  3
.LDLogL2:
    .word   0x2A7CC0D7
    .word   0x3FDA6176
    .align  3
.LDLogL3:
    .word   0x39DABCF3
    .word   0x3FD484B1
    .align  3
.LDLogL4:
    .word   0xB8820814
    .word   0x3FD0C9AB
    .align  3
.LDLogL5:
    .word   0x234A0E59
    .word   0x3FCC658A
    .align  3
.LDln2:
    .word   0xFEFA39EF
    .word   0x3FE62E42
    .align  3
.LDExpE12:
    .word   0xeff8d898
    .word   0x3e21eed8
    .align  3
.LDExpE11:
    .word   0x67f544e4
    .word   0x3e5ae645
    .align  3
.LDExpE10:
    .word   0xb7789f5c
    .word   0x3e927e4f
    .align  3
.LDExpE9:
    .word   0xa556c734
    .word   0x3ec71de3
    .align  3
.LDExpE8:
    .word   0x1a01a01a
    .word   0x3efa01a0
    .align  3
.LDExpE7:
    .word   0x1a01a01a
    .word   0x3f2a01a0
    .align  3
.LDExpE6:
    .word   0x16c16c17
    .word   0x3f56c16c
    .align  3
.LDExpE5:
    .word   0x11111111
    .word   0x3f811111
    .align  3
.LDExpE4:
    .word   0x55555555
    .word   0x3fa55555
    .align  3
.LDExpE3:
    .word   0x55555555
    .word   0x3fc55555
    .align  3
.LDExpE2:
    .word   0x00000000
    .word   0x3fe00000

    .size     pow, .-pow
