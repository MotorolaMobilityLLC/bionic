/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _ASM_GENERIC_CPUTIME_H
#define _ASM_GENERIC_CPUTIME_H
#include <linux/time.h>
#include <linux/jiffies.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
typedef unsigned long cputime_t;
#define cputime_zero (0UL)
#define cputime_max ((~0UL >> 1) - 1)
#define cputime_add(__a, __b) ((__a) + (__b))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define cputime_sub(__a, __b) ((__a) - (__b))
#define cputime_div(__a, __n) ((__a) / (__n))
#define cputime_halve(__a) ((__a) >> 1)
#define cputime_eq(__a, __b) ((__a) == (__b))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define cputime_gt(__a, __b) ((__a) > (__b))
#define cputime_ge(__a, __b) ((__a) >= (__b))
#define cputime_lt(__a, __b) ((__a) < (__b))
#define cputime_le(__a, __b) ((__a) <= (__b))
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define cputime_to_jiffies(__ct) (__ct)
#define jiffies_to_cputime(__hz) (__hz)
typedef u64 cputime64_t;
#define cputime64_zero (0ULL)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define cputime64_add(__a, __b) ((__a) + (__b))
#define cputime64_sub(__a, __b) ((__a) - (__b))
#define cputime64_to_jiffies64(__ct) (__ct)
#define jiffies64_to_cputime64(__jif) (__jif)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define cputime_to_cputime64(__ct) ((u64) __ct)
#define cputime_to_msecs(__ct) jiffies_to_msecs(__ct)
#define msecs_to_cputime(__msecs) msecs_to_jiffies(__msecs)
#define cputime_to_secs(jif) ((jif) / HZ)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define secs_to_cputime(sec) ((sec) * HZ)
#define timespec_to_cputime(__val) timespec_to_jiffies(__val)
#define cputime_to_timespec(__ct,__val) jiffies_to_timespec(__ct,__val)
#define timeval_to_cputime(__val) timeval_to_jiffies(__val)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#define cputime_to_timeval(__ct,__val) jiffies_to_timeval(__ct,__val)
#define cputime_to_clock_t(__ct) jiffies_to_clock_t(__ct)
#define clock_t_to_cputime(__x) clock_t_to_jiffies(__x)
#define cputime64_to_clock_t(__ct) jiffies_64_to_clock_t(__ct)
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
