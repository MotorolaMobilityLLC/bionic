/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _SFP_MACHINE_H
#define _SFP_MACHINE_H

#define _FP_W_TYPE_SIZE 32
#define _FP_W_TYPE unsigned long
#define _FP_WS_TYPE signed long
#define _FP_I_TYPE long

#define _FP_MUL_MEAT_S(R,X,Y)   _FP_MUL_MEAT_1_wide(_FP_WFRACBITS_S,R,X,Y,umul_ppmm)
#define _FP_MUL_MEAT_D(R,X,Y)   _FP_MUL_MEAT_2_wide(_FP_WFRACBITS_D,R,X,Y,umul_ppmm)
#define _FP_MUL_MEAT_Q(R,X,Y)   _FP_MUL_MEAT_4_wide(_FP_WFRACBITS_Q,R,X,Y,umul_ppmm)

#define _FP_DIV_MEAT_S(R,X,Y) _FP_DIV_MEAT_1_udiv(S,R,X,Y)
#define _FP_DIV_MEAT_D(R,X,Y) _FP_DIV_MEAT_2_udiv(D,R,X,Y)
#define _FP_DIV_MEAT_Q(R,X,Y) _FP_DIV_MEAT_4_udiv(Q,R,X,Y)

#define _FP_NANFRAC_S ((_FP_QNANBIT_S << 1) - 1)
#define _FP_NANFRAC_D ((_FP_QNANBIT_D << 1) - 1), -1
#define _FP_NANFRAC_Q ((_FP_QNANBIT_Q << 1) - 1), -1, -1, -1
#define _FP_NANSIGN_S 0
#define _FP_NANSIGN_D 0
#define _FP_NANSIGN_Q 0

#define _FP_KEEPNANFRACP 1

#define _FP_CHOOSENAN(fs, wc, R, X, Y, OP)   do {   if ((_FP_FRAC_HIGH_RAW_##fs(X) & _FP_QNANBIT_##fs)   && !(_FP_FRAC_HIGH_RAW_##fs(Y) & _FP_QNANBIT_##fs))   {   R##_s = Y##_s;   _FP_FRAC_COPY_##wc(R,Y);   }   else   {   R##_s = X##_s;   _FP_FRAC_COPY_##wc(R,X);   }   R##_c = FP_CLS_NAN;   } while (0)

#define FP_DENORM_ZERO 1 

#define FP_EX_INVALID (1<<4)
#define FP_EX_DIVZERO (1<<3)
#define FP_EX_OVERFLOW (1<<2)
#define FP_EX_UNDERFLOW (1<<1)
#define FP_EX_INEXACT (1<<0)

#endif

