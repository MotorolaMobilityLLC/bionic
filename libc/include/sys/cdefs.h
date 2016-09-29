/*	$NetBSD: cdefs.h,v 1.58 2004/12/11 05:59:00 christos Exp $	*/

/*
 * Copyright (c) 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Berkeley Software Design, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)cdefs.h	8.8 (Berkeley) 1/9/95
 */

#ifndef	_SYS_CDEFS_H_
#define	_SYS_CDEFS_H_

/*
 * Testing against Clang-specific extensions.
 */
#ifndef __has_extension
#define __has_extension         __has_feature
#endif
#ifndef __has_feature
#define __has_feature(x)        0
#endif
#ifndef __has_include
#define __has_include(x)        0
#endif
#ifndef __has_builtin
#define __has_builtin(x)        0
#endif
#ifndef __has_attribute
#define __has_attribute(x)      0
#endif

#define __strong_alias(alias, sym) \
    __asm__(".global " #alias "\n" \
            #alias " = " #sym);

#if defined(__cplusplus)
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS }
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif

#if defined(__cplusplus)
#define __BIONIC_CAST(_k,_t,_v) (_k<_t>(_v))
#else
#define __BIONIC_CAST(_k,_t,_v) ((_t) (_v))
#endif

/*
 * The __CONCAT macro is used to concatenate parts of symbol names, e.g.
 * with "#define OLD(foo) __CONCAT(old,foo)", OLD(foo) produces oldfoo.
 * The __CONCAT macro is a bit tricky -- make sure you don't put spaces
 * in between its arguments.  __CONCAT can also concatenate double-quoted
 * strings produced by the __STRING macro, but this only works with ANSI C.
 */

#define	___STRING(x)	__STRING(x)
#define	___CONCAT(x,y)	__CONCAT(x,y)

#if defined(__STDC__) || defined(__cplusplus)
#define	__P(protos)	protos		/* full-blown ANSI C */
#define	__CONCAT(x,y)	x ## y
#define	__STRING(x)	#x

#if defined(__cplusplus)
#define	__inline	inline		/* convert to C++ keyword */
#endif /* !__cplusplus */

#else	/* !(__STDC__ || __cplusplus) */
#define	__P(protos)	()		/* traditional C preprocessor */
#define	__CONCAT(x,y)	x/**/y
#define	__STRING(x)	"x"

#endif	/* !(__STDC__ || __cplusplus) */

#define __always_inline __attribute__((__always_inline__))
#define __attribute_const__ __attribute__((__const__))
#define __attribute_pure__ __attribute__((__pure__))
#define __dead __attribute__((__noreturn__))
#define __noreturn __attribute__((__noreturn__))
#define __mallocfunc  __attribute__((__malloc__))
#define __packed __attribute__((__packed__))
#define __unused __attribute__((__unused__))
#define __used __attribute__((__used__))

/*
 * _Nonnull is similar to the nonnull attribute in that it will instruct
 * compilers to warn the user if it can prove that a null argument is being
 * passed. Unlike the nonnull attribute, this annotation indicated that a value
 * *should not* be null, not that it *cannot* be null, or even that the behavior
 * is undefined. The important distinction is that the optimizer will perform
 * surprising optimizations like the following:
 *
 *     void foo(void*) __attribute__(nonnull, 1);
 *
 *     int bar(int* p) {
 *       foo(p);
 *
 *       // The following null check will be elided because nonnull attribute
 *       // means that, since we call foo with p, p can be assumed to not be
 *       // null. Thus this will crash if we are called with a null pointer.
 *       if (p != NULL) {
 *         return *p;
 *       }
 *       return 0;
 *     }
 *
 *     int main() {
 *       return bar(NULL);
 *     }
 *
 * http://clang.llvm.org/docs/AttributeReference.html#nonnull
 */
#if !(defined(__clang__) && __has_feature(nullability))
#define _Nonnull
#define _Nullable
#endif

#define __printflike(x, y) __attribute__((__format__(printf, x, y)))
#define __scanflike(x, y) __attribute__((__format__(scanf, x, y)))

/*
 * GNU C version 2.96 added explicit branch prediction so that
 * the CPU back-end can hint the processor and also so that
 * code blocks can be reordered such that the predicted path
 * sees a more linear flow, thus improving cache behavior, etc.
 *
 * The following two macros provide us with a way to use this
 * compiler feature.  Use __predict_true() if you expect the expression
 * to evaluate to true, and __predict_false() if you expect the
 * expression to evaluate to false.
 *
 * A few notes about usage:
 *
 *	* Generally, __predict_false() error condition checks (unless
 *	  you have some _strong_ reason to do otherwise, in which case
 *	  document it), and/or __predict_true() `no-error' condition
 *	  checks, assuming you want to optimize for the no-error case.
 *
 *	* Other than that, if you don't know the likelihood of a test
 *	  succeeding from empirical or other `hard' evidence, don't
 *	  make predictions.
 *
 *	* These are meant to be used in places that are run `a lot'.
 *	  It is wasteful to make predictions in code that is run
 *	  seldomly (e.g. at subsystem initialization time) as the
 *	  basic block reordering that this affects can often generate
 *	  larger code.
 */
#define	__predict_true(exp)	__builtin_expect((exp) != 0, 1)
#define	__predict_false(exp)	__builtin_expect((exp) != 0, 0)

#define __wur __attribute__((__warn_unused_result__))

#ifdef __clang__
#define __errorattr(msg) __attribute__((unavailable(msg)))
#else
#define __errorattr(msg) __attribute__((__error__(msg)))
#endif

#define __errordecl(name, msg) extern void name(void) __errorattr(msg)

/*
 * Some BSD source needs these macros.
 * Originally they embedded the rcs versions of each source file
 * in the generated binary. We strip strings during build anyway,.
 */
#define __IDSTRING(_prefix,_s) /* nothing */
#define __COPYRIGHT(_s) /* nothing */
#define __FBSDID(_s) /* nothing */
#define __RCSID(_s) /* nothing */
#define __SCCSID(_s) /* nothing */

/*
 * With bionic, you always get all C and POSIX API.
 *
 * If you want BSD and/or GNU extensions, _BSD_SOURCE and/or _GNU_SOURCE are
 * expected to be defined by callers before *any* standard header file is
 * included.
 *
 * In our header files we test against __USE_BSD and __USE_GNU.
 */
#if defined(_GNU_SOURCE)
# define __USE_BSD 1
# define __USE_GNU 1
#endif

#if defined(_BSD_SOURCE)
# define __USE_BSD 1
#endif

/* _FILE_OFFSET_BITS 64 support. */
#if !defined(__LP64__) && defined(_FILE_OFFSET_BITS)
#if _FILE_OFFSET_BITS == 64
#define __USE_FILE_OFFSET64 1
#endif
#endif

#define  __BIONIC__   1
#include <android/api-level.h>

/* glibc compatibility. */
#if defined(__LP64__)
#define __WORDSIZE 64
#else
#define __WORDSIZE 32
#endif

/*
 * When _FORTIFY_SOURCE is defined, automatic bounds checking is
 * added to commonly used libc functions. If a buffer overrun is
 * detected, the program is safely aborted.
 *
 * See
 * http://gcc.gnu.org/onlinedocs/gcc/Object-Size-Checking.html for details.
 */
#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0
#  define __BIONIC_FORTIFY 1
#  if _FORTIFY_SOURCE == 2
#    define __bos(s) __builtin_object_size((s), 1)
#  else
#    define __bos(s) __builtin_object_size((s), 0)
#  endif
#  define __bos0(s) __builtin_object_size((s), 0)
#  if defined(__clang__)
#    define __BIONIC_FORTIFY_INLINE extern __inline__ __always_inline __attribute__((gnu_inline))
#  else
#    define __BIONIC_FORTIFY_INLINE extern __inline__ __always_inline __attribute__((gnu_inline)) __attribute__((__artificial__))
#  endif
#endif
#define __BIONIC_FORTIFY_UNKNOWN_SIZE __BIONIC_CAST(static_cast, size_t, -1)

/* Used to tag non-static symbols that are private and never exposed by the shared library. */
#define __LIBC_HIDDEN__ __attribute__((visibility("hidden")))

/*
 * Used to tag symbols that should be hidden for 64-bit,
 * but visible to preserve binary compatibility for LP32.
 */
#ifdef __LP64__
#define __LIBC32_LEGACY_PUBLIC__ __attribute__((visibility("hidden")))
#else
#define __LIBC32_LEGACY_PUBLIC__ __attribute__((visibility("default")))
#endif

/* Used to rename functions so that the compiler emits a call to 'x' rather than the function this was applied to. */
#define __RENAME(x) __asm__(#x)

#include <android/versioning.h>

#if __has_builtin(__builtin_umul_overflow) || __GNUC__ >= 5
#if defined(__LP64__)
#define __size_mul_overflow(a, b, result) __builtin_umull_overflow(a, b, result)
#else
#define __size_mul_overflow(a, b, result) __builtin_umul_overflow(a, b, result)
#endif
#else
extern __inline__ __always_inline __attribute__((gnu_inline))
int __size_mul_overflow(__SIZE_TYPE__ a, __SIZE_TYPE__ b, __SIZE_TYPE__ *result) {
    *result = a * b;
    static const __SIZE_TYPE__ mul_no_overflow = 1UL << (sizeof(__SIZE_TYPE__) * 4);
    return (a >= mul_no_overflow || b >= mul_no_overflow) && a > 0 && (__SIZE_TYPE__)-1 / a < b;
}
#endif

/*
 * TODO(danalbert): Remove this once we've moved entirely off prebuilts/ndk.
 *
 * The NDK used to have a __NDK_FPABI__ that was defined to empty for most cases
 * but `__attribute__((pcs("aapcs")))` for the now defunct armeabi-v7a-hard ABI.
 *
 * During the transition from prebuilts/ndk to ndk_headers, we'll have some
 * headers that still use __NDK_FPABI__ while the libc headers have stopped
 * defining it. In the interim, just provide an empty definition to keep the
 * build working.
 */
#define __NDK_FPABI__

#endif /* !_SYS_CDEFS_H_ */
