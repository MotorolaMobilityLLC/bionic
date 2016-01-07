    .text
    .align
    .global     atan
    .type       atan, %function
atan:
    .fnstart
    fmdrr       d0,  r0,  r1
    bic         r2,  r1,  #0x80000000
    movw        ip,  #0x0000
    movt        ip,  #0x3ff3
    vabs.f64    d1,  d0

.LRange3:
    cmp         r2,  ip
    blt         .LRange4
    fconstd     d2,  #0x70
    fconstd     d3,  #0x78
    vmla.f64    d2,  d1,  d3
    vsub.f64    d6,  d1,  d3
    movw        ip,  #0x8000
    movt        ip,  #0x4003
    cmp         r2,  ip
    bge         .LRange2
    vdiv.f64    d6,  d6,  d2
    vldr        d31, .LDAT10
    vldr        d30, .LDAT9
    vldr        d29, .LDAT8
    vldr        d28, .LDAT7
    vldr        d27, .LDAT6
    vldr        d26, .LDAT5
    vldr        d25, .LDAT4
    vmul.f64    d16, d6,  d6
    vldr        d24, .LDAT3
    vldr        d23, .LDAT2
    vldr        d22, .LDAT1
    vmul.f64    d17, d16, d16
    vldr        d21, .LDAT0
    vldr        d19, .LDAtanLo_2
    vldr        d18, .LDAtanHi_2
    vmla.f64    d29, d17, d31
    vmla.f64    d28, d17, d30
    vmla.f64    d27, d17, d29
    vmla.f64    d26, d17, d28
    vmla.f64    d25, d17, d27
    vmla.f64    d24, d17, d26
    vmla.f64    d23, d17, d25
    vmla.f64    d22, d17, d24
    vmla.f64    d21, d17, d23
    vmul.f64    d20, d17, d22
    vmla.f64    d20, d16, d21
    vmla.f64    d19, d6,  d20
    vsub.f64    d19, d19, d6
    vsub.f64    d18, d18, d19
    cmp         r1,  #0
    fmrrd       r0,  r1,  d18
    blt         .LNegResult
    bx          lr

.LRange2:
    fconstd     d2,  #0xF0
    movw        ip,  #0x0000
    movt        ip,  #0x4410
    cmp         r2,  ip
    bge         .LRange1
    vdiv.f64    d6,  d2,  d1
    vldr        d31, .LDAT10
    vldr        d30, .LDAT9
    vldr        d29, .LDAT8
    vldr        d28, .LDAT7
    vldr        d27, .LDAT6
    vldr        d26, .LDAT5
    vldr        d25, .LDAT4
    vmul.f64    d16, d6,  d6
    vldr        d24, .LDAT3
    vldr        d23, .LDAT2
    vldr        d22, .LDAT1
    vmul.f64    d17, d16, d16
    vldr        d21, .LDAT0
    vldr        d19, .LDAtanLo_3
    vldr        d18, .LDAtanHi_3
    vmla.f64    d29, d17, d31
    vmla.f64    d28, d17, d30
    vmla.f64    d27, d17, d29
    vmla.f64    d26, d17, d28
    vmla.f64    d25, d17, d27
    vmla.f64    d24, d17, d26
    vmla.f64    d23, d17, d25
    vmla.f64    d22, d17, d24
    vmla.f64    d21, d17, d23
    vmul.f64    d20, d17, d22
    vmla.f64    d20, d16, d21
    vmla.f64    d19, d6,  d20
    vsub.f64    d19, d19, d6
    vsub.f64    d18, d18, d19
    cmp         r1,  #0
    fmrrd       r0,  r1,  d18
    blt         .LNegResult
    bx          lr

.LRange1:
    movt        ip,  #0x7ff0
    cmp         r2,  ip
    bgt         .LRange1Nan
    bne         .LRange1Normal
    cmp         r0,  #0
    beq         .LRange1Normal
.LRange1Nan:
    vadd.f64    d18, d0,  d0
    fmrrd       r0,  r1,  d18
    bx          lr
.LRange1Normal:
    vldr        d16, .LDAtanHi_3
    vldr        d17, .LDAtanLo_3
    cmp         r1,  #0
    vsubgt.f64  d18, d16, d17
    vsuble.f64  d18, d17, d16
    fmrrd       r0,  r1,  d18
    bx          lr

    .align      8
.LDAT0:
    .word       0x5555550D
    .word       0x3FD55555
.LDAT1:
    .word       0x9998EBC4
    .word       0xBFC99999
.LDAT2:
    .word       0x920083FF
    .word       0x3FC24924
.LDAT3:
    .word       0xFE231671
    .word       0xBFBC71C6
.LDAT4:
    .word       0xC54C206E
    .word       0x3FB745CD
.LDAT5:
    .word       0xAF749A6D
    .word       0xBFB3B0F2
.LDAT6:
    .word       0xA0D03D51
    .word       0x3FB10D66
.LDAT7:
    .word       0x52DEFD9A
    .word       0xBFADDE2D
.LDAT8:
    .word       0x24760DEB
    .word       0x3FA97B4B
.LDAT9:
    .word       0x2C6A6C2F
    .word       0xBFA2B444
.LDAT10:
    .word       0xE322DA11
    .word       0x3F90AD3A
.LDAtanHi_0:
    .word       0x0561BB4F
    .word       0x3FDDAC67
.LDAtanHi_1:
    .word       0x54442D18
    .word       0x3FE921FB
.LDAtanHi_2:
    .word       0xD281F69B
    .word       0x3FEF730B
.LDAtanHi_3:
    .word       0x54442D18
    .word       0x3FF921FB
.LDAtanLo_0:
    .word       0x222F65E2
    .word       0xBC7A2B7F
.LDAtanLo_1:
    .word       0x33145C07
    .word       0xBC81A626
.LDAtanLo_2:
    .word       0x7AF0CBBD
    .word       0xBC700788
.LDAtanLo_3:
    .word       0x33145C07
    .word       0xBC91A626
.LDHuge:
    .word       0x8800759C
    .word       0x7E37E43C

.LNegResult:
    vneg.f64    d18, d18
    fmrrd       r0,  r1,  d18
.LRet:
    bx          lr

.LRange4:
    fconstd     d2,  #0x70
    vsub.f64    d4,  d1,  d2
    vadd.f64    d5,  d1,  d2
    movt        ip,  #0x3fe6
    cmp         r2,  ip
    blt         .LRange5
    vdiv.f64    d4,  d4,  d5
    vldr        d31, .LDAT10
    vldr        d30, .LDAT9
    vldr        d29, .LDAT8
    vldr        d28, .LDAT7
    vldr        d27, .LDAT6
    vldr        d26, .LDAT5
    vldr        d25, .LDAT4
    vmul.f64    d16, d4,  d4
    vldr        d24, .LDAT3
    vldr        d23, .LDAT2
    vldr        d22, .LDAT1
    vmul.f64    d17, d16, d16
    vldr        d21, .LDAT0
    vldr        d19, .LDAtanLo_1
    vldr        d18, .LDAtanHi_1
    vmla.f64    d29, d17, d31
    vmla.f64    d28, d17, d30
    vmla.f64    d27, d17, d29
    vmla.f64    d26, d17, d28
    vmla.f64    d25, d17, d27
    vmla.f64    d24, d17, d26
    vmla.f64    d23, d17, d25
    vmla.f64    d22, d17, d24
    vmla.f64    d21, d17, d23
    vmul.f64    d20, d17, d22
    vmla.f64    d20, d16, d21
    vmla.f64    d19, d4,  d20
    vsub.f64    d19, d19, d4
    vsub.f64    d18, d18, d19
    cmp         r1,  #0
    fmrrd       r0,  r1,  d18
    blt         .LNegResult
    bx          lr

.LRange5:
    fconstd     d2,  #0xF0
    fconstd     d3,  #0x00
    vmla.f64    d2,  d1,  d3
    vadd.f64    d4,  d3,  d1
    movt        ip,  #0x3fdc
    cmp         r2,  ip
    blt         .LRange6
    vdiv.f64    d4,  d2,  d4
    vldr        d31, .LDAT10
    vldr        d30, .LDAT9
    vldr        d29, .LDAT8
    vldr        d28, .LDAT7
    vldr        d27, .LDAT6
    vldr        d26, .LDAT5
    vldr        d25, .LDAT4
    vmul.f64    d16, d4,  d4
    vldr        d24, .LDAT3
    vldr        d23, .LDAT2
    vldr        d22, .LDAT1
    vmul.f64    d17, d16, d16
    vldr        d21, .LDAT0
    vldr        d19, .LDAtanLo_0
    vldr        d18, .LDAtanHi_0
    vmla.f64    d29, d17, d31
    vmla.f64    d28, d17, d30
    vmla.f64    d27, d17, d29
    vmla.f64    d26, d17, d28
    vmla.f64    d25, d17, d27
    vmla.f64    d24, d17, d26
    vmla.f64    d23, d17, d25
    vmla.f64    d22, d17, d24
    vmla.f64    d21, d17, d23
    vmul.f64    d20, d17, d22
    vmla.f64    d20, d16, d21
    vmla.f64    d19, d4,  d20
    vsub.f64    d19, d19, d4
    vsub.f64    d18, d18, d19
    cmp         r1,  #0
    fmrrd       r0,  r1,  d18
    blt         .LNegResult
    bx          lr

.LRange6:
    cmp         r2,  #0x3E400000
    bge         .LRange6Normal
    vldr        d2, .LDHuge
    vadd.f64    d2,  d2,  d0
    fconstd     d3,  #0x70
    fcmped      d2,  d3
    fmstat
    bgt         .LRet
.LRange6Normal:
    vmul.f64    d16, d0,  d0
    vldr        d31, .LDAT10
    vldr        d30, .LDAT9
    vldr        d29, .LDAT8
    vmul.f64    d17, d16, d16
    vldr        d28, .LDAT7
    vldr        d27, .LDAT6
    vldr        d26, .LDAT5
    vmla.f64    d29, d17, d31
    vmla.f64    d28, d17, d30
    vldr        d25, .LDAT4
    vldr        d24, .LDAT3
    vmla.f64    d27, d17, d29
    vmla.f64    d26, d17, d28
    vldr        d23, .LDAT2
    vldr        d22, .LDAT1
    vmla.f64    d25, d17, d27
    vmla.f64    d24, d17, d26
    vldr        d21, .LDAT0
    vmla.f64    d23, d17, d25
    vmla.f64    d22, d17, d24
    vmla.f64    d21, d17, d23
    vmul.f64    d20, d17, d22
    vmla.f64    d20, d16, d21
    vmul.f64    d20, d0,  d20
    vsub.f64    d18, d0,  d20
    fmrrd       r0,  r1,  d18
    bx          lr
    .fnend
    .size       atan, .-atan
#if (LDBL_MANT_DIG == 53)
    .weak   atanl
    .equ    atanl, atan
#endif

