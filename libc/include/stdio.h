/*	$OpenBSD: stdio.h,v 1.35 2006/01/13 18:10:09 miod Exp $	*/
/*	$NetBSD: stdio.h,v 1.18 1996/04/25 18:29:21 jtc Exp $	*/

/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
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
 *	@(#)stdio.h	5.17 (Berkeley) 6/3/91
 */

#ifndef	_STDIO_H_
#define	_STDIO_H_

#include <sys/cdefs.h>
#include <sys/types.h>

#include <stdarg.h>
#include <stddef.h>

#define __need_NULL
#include <stddef.h>

#include <bits/seek_constants.h>

#if __ANDROID_API__ < __ANDROID_API_N__
#include <bits/struct_file.h>
#endif

__BEGIN_DECLS

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnullability-completeness"
#endif

typedef off_t fpos_t;
typedef off64_t fpos64_t;

struct __sFILE;
typedef struct __sFILE FILE;

#if __ANDROID_API__ >= __ANDROID_API_M__
extern FILE* stdin __INTRODUCED_IN(23);
extern FILE* stdout __INTRODUCED_IN(23);
extern FILE* stderr __INTRODUCED_IN(23);

/* C99 and earlier plus current C++ standards say these must be macros. */
#define stdin stdin
#define stdout stdout
#define stderr stderr
#else
/* Before M the actual symbols for stdin and friends had different names. */
extern FILE __sF[] __REMOVED_IN(23);

#define stdin (&__sF[0])
#define stdout (&__sF[1])
#define stderr (&__sF[2])
#endif

/*
 * The following three definitions are for ANSI C, which took them
 * from System V, which brilliantly took internal interface macros and
 * made them official arguments to setvbuf(), without renaming them.
 * Hence, these ugly _IOxxx names are *supposed* to appear in user code.
 *
 * Although numbered as their counterparts above, the implementation
 * does not rely on this.
 */
#define	_IOFBF	0		/* setvbuf should set fully buffered */
#define	_IOLBF	1		/* setvbuf should set line buffered */
#define	_IONBF	2		/* setvbuf should set unbuffered */

#define	BUFSIZ	1024		/* size of buffer used by setbuf */
#define	EOF	(-1)

/*
 * FOPEN_MAX is a minimum maximum, and is the number of streams that
 * stdio can provide without attempting to allocate further resources
 * (which could fail).  Do not use this for anything.
 */

#define	FOPEN_MAX	20	/* must be <= OPEN_MAX <sys/syslimits.h> */
#define	FILENAME_MAX	1024	/* must be <= PATH_MAX <sys/syslimits.h> */

#define	L_tmpnam	1024	/* XXX must be == PATH_MAX */
#define	TMP_MAX		308915776

/*
 * Functions defined in ANSI C standard.
 */
void	 clearerr(FILE *);
int	 fclose(FILE *);
int	 feof(FILE *);
int	 ferror(FILE *);
int	 fflush(FILE *);
int	 fgetc(FILE *);
char	*fgets(char * __restrict, int, FILE * __restrict) __overloadable
  __RENAME_CLANG(fgets);
int	 fprintf(FILE * __restrict , const char * __restrict _Nonnull, ...) __printflike(2, 3);
int	 fputc(int, FILE *);
int	 fputs(const char * __restrict, FILE * __restrict);
size_t	 fread(void * __restrict, size_t, size_t, FILE * __restrict)
      __overloadable __RENAME_CLANG(fread);
int	 fscanf(FILE * __restrict, const char * __restrict _Nonnull, ...) __scanflike(2, 3);
size_t	 fwrite(const void * __restrict, size_t, size_t, FILE * __restrict)
    __overloadable __RENAME_CLANG(fwrite);
int	 getc(FILE *);
int	 getchar(void);
ssize_t getdelim(char** __restrict, size_t* __restrict, int, FILE* __restrict) __INTRODUCED_IN(18);
ssize_t getline(char** __restrict, size_t* __restrict, FILE* __restrict) __INTRODUCED_IN(18);

void	 perror(const char *);
int	 printf(const char * __restrict _Nonnull, ...) __printflike(1, 2);
int	 putc(int, FILE *);
int	 putchar(int);
int	 puts(const char *);
int	 remove(const char *);
void	 rewind(FILE *);
int	 scanf(const char * __restrict _Nonnull, ...) __scanflike(1, 2);
void	 setbuf(FILE * __restrict, char * __restrict);
int	 setvbuf(FILE * __restrict, char * __restrict, int, size_t);
int	 sscanf(const char * __restrict, const char * __restrict _Nonnull, ...) __scanflike(2, 3);
int	 ungetc(int, FILE *);
int	 vfprintf(FILE * __restrict, const char * __restrict _Nonnull, __va_list) __printflike(2, 0);
int	 vprintf(const char * __restrict _Nonnull, __va_list) __printflike(1, 0);

int dprintf(int, const char* __restrict _Nonnull, ...) __printflike(2, 3) __INTRODUCED_IN(21);
int vdprintf(int, const char* __restrict _Nonnull, __va_list) __printflike(2, 0) __INTRODUCED_IN(21);

#if (defined(__STDC_VERSION__) && __STDC_VERSION__ < 201112L) || \
    (defined(__cplusplus) && __cplusplus <= 201103L)
char* gets(char*) __attribute__((deprecated("gets is unsafe, use fgets instead")));
#endif
int sprintf(char* __restrict, const char* __restrict _Nonnull, ...)
    __printflike(2, 3) __warnattr_strict("sprintf is often misused; please use snprintf")
    __overloadable __RENAME_CLANG(sprintf);
int vsprintf(char* __restrict, const char* __restrict _Nonnull, __va_list)
    __overloadable __printflike(2, 0) __RENAME_CLANG(vsprintf)
    __warnattr_strict("vsprintf is often misused; please use vsnprintf");
char* tmpnam(char*)
    __warnattr("tempnam is unsafe, use mkstemp or tmpfile instead");
#define P_tmpdir "/tmp/" /* deprecated */
char* tempnam(const char*, const char*)
    __warnattr("tempnam is unsafe, use mkstemp or tmpfile instead");

int rename(const char*, const char*);
int renameat(int, const char*, int, const char*);

int fseek(FILE*, long, int);
long ftell(FILE*);

#if defined(__USE_FILE_OFFSET64)
int fgetpos(FILE*, fpos_t*) __RENAME(fgetpos64) __INTRODUCED_IN(24);
int fsetpos(FILE*, const fpos_t*) __RENAME(fsetpos64) __INTRODUCED_IN(24);
int fseeko(FILE*, off_t, int) __RENAME(fseeko64) __INTRODUCED_IN(24);
off_t ftello(FILE*) __RENAME(ftello64) __INTRODUCED_IN(24);
#  if defined(__USE_BSD)
FILE* funopen(const void*,
              int (*)(void*, char*, int),
              int (*)(void*, const char*, int),
              fpos_t (*)(void*, fpos_t, int),
              int (*)(void*)) __RENAME(funopen64) __INTRODUCED_IN(24);
#  endif
#else
int fgetpos(FILE*, fpos_t*);
int fsetpos(FILE*, const fpos_t*);
int fseeko(FILE*, off_t, int);
off_t ftello(FILE*);
#  if defined(__USE_BSD)
FILE* funopen(const void*,
              int (*)(void*, char*, int),
              int (*)(void*, const char*, int),
              fpos_t (*)(void*, fpos_t, int),
              int (*)(void*));
#  endif
#endif
int fgetpos64(FILE*, fpos64_t*) __INTRODUCED_IN(24);
int fsetpos64(FILE*, const fpos64_t*) __INTRODUCED_IN(24);
int fseeko64(FILE*, off64_t, int) __INTRODUCED_IN(24);
off64_t ftello64(FILE*) __INTRODUCED_IN(24);
#if defined(__USE_BSD)
FILE* funopen64(const void*, int (*)(void*, char*, int), int (*)(void*, const char*, int),
                fpos64_t (*)(void*, fpos64_t, int), int (*)(void*)) __INTRODUCED_IN(24);
#endif

FILE* fopen(const char* __restrict, const char* __restrict);
FILE* fopen64(const char* __restrict, const char* __restrict) __INTRODUCED_IN(24);
FILE* freopen(const char* __restrict, const char* __restrict, FILE* __restrict);
FILE* freopen64(const char* __restrict, const char* __restrict, FILE* __restrict)
  __INTRODUCED_IN(24);
FILE* tmpfile(void);
FILE* tmpfile64(void) __INTRODUCED_IN(24);

int snprintf(char* __restrict, size_t, const char* __restrict _Nonnull, ...)
    __printflike(3, 4) __overloadable __RENAME_CLANG(snprintf);
int vfscanf(FILE* __restrict, const char* __restrict _Nonnull, __va_list) __scanflike(2, 0);
int vscanf(const char* _Nonnull , __va_list) __scanflike(1, 0);
int vsnprintf(char* __restrict, size_t, const char* __restrict _Nonnull, __va_list)
    __printflike(3, 0) __overloadable __RENAME_CLANG(vsnprintf);
int vsscanf(const char* __restrict _Nonnull, const char* __restrict _Nonnull, __va_list) __scanflike(2, 0);

#define L_ctermid 1024 /* size for ctermid() */
char* ctermid(char*) __INTRODUCED_IN(26);

FILE* fdopen(int, const char*);
int fileno(FILE*);
int pclose(FILE*);
FILE* popen(const char*, const char*);
void flockfile(FILE*);
int ftrylockfile(FILE*);
void funlockfile(FILE*);
int getc_unlocked(FILE*);
int getchar_unlocked(void);
int putc_unlocked(int, FILE*);
int putchar_unlocked(int);

FILE* fmemopen(void*, size_t, const char*) __INTRODUCED_IN(23);
FILE* open_memstream(char**, size_t*) __INTRODUCED_IN(23);

#if defined(__USE_BSD) || defined(__BIONIC__) /* Historically bionic exposed these. */
int  asprintf(char** __restrict, const char* __restrict _Nonnull, ...) __printflike(2, 3);
char* fgetln(FILE* __restrict, size_t* __restrict);
int fpurge(FILE*);
void setbuffer(FILE*, char*, int);
int setlinebuf(FILE*);
int vasprintf(char** __restrict, const char* __restrict _Nonnull, __va_list) __printflike(2, 0);
void clearerr_unlocked(FILE*) __INTRODUCED_IN(23);
int feof_unlocked(FILE*) __INTRODUCED_IN(23);
int ferror_unlocked(FILE*) __INTRODUCED_IN(23);
int fileno_unlocked(FILE*) __INTRODUCED_IN(24);
#define fropen(cookie, fn) funopen(cookie, fn, 0, 0, 0)
#define fwopen(cookie, fn) funopen(cookie, 0, fn, 0, 0)
#endif /* __USE_BSD */

char* __fgets_chk(char*, int, FILE*, size_t) __INTRODUCED_IN(17);
size_t __fread_chk(void* __restrict, size_t, size_t, FILE* __restrict, size_t)
    __INTRODUCED_IN(24);
size_t __fwrite_chk(const void* __restrict, size_t, size_t, FILE* __restrict, size_t)
    __INTRODUCED_IN(24);

#if defined(__BIONIC_FORTIFY) && !defined(__BIONIC_NO_STDIO_FORTIFY)

#if __ANDROID_API__ >= __ANDROID_API_J_MR1__
__BIONIC_FORTIFY_INLINE __printflike(3, 0)
int vsnprintf(char *const __pass_object_size dest, size_t size,
              const char *_Nonnull format, __va_list ap) __overloadable {
    return __builtin___vsnprintf_chk(dest, size, 0, __bos(dest), format, ap);
}

__BIONIC_FORTIFY_INLINE __printflike(2, 0)
int vsprintf(char *const __pass_object_size dest, const char *_Nonnull format,
             __va_list ap) __overloadable {
    return __builtin___vsprintf_chk(dest, 0, __bos(dest), format, ap);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_J_MR1__ */

#if defined(__clang__)
#if __ANDROID_API__ >= __ANDROID_API_J_MR1__
/*
 * Simple case: `format` can't have format specifiers, so we can just compare
 * its length to the length of `dest`
 */
__BIONIC_ERROR_FUNCTION_VISIBILITY
int snprintf(char *__restrict dest, size_t size, const char *__restrict format)
    __overloadable
    __enable_if(__bos(dest) != __BIONIC_FORTIFY_UNKNOWN_SIZE &&
                __bos(dest) < __builtin_strlen(format),
                "format string will always overflow destination buffer")
    __errorattr("format string will always overflow destination buffer");

__BIONIC_FORTIFY_INLINE
__printflike(3, 4)
int snprintf(char *__restrict const __pass_object_size dest,
             size_t size, const char *__restrict format, ...) __overloadable {
    va_list va;
    va_start(va, format);
    int result = __builtin___vsnprintf_chk(dest, size, 0, __bos(dest), format, va);
    va_end(va);
    return result;
}

__BIONIC_ERROR_FUNCTION_VISIBILITY
int sprintf(char *__restrict dest, const char *__restrict format) __overloadable
    __enable_if(__bos(dest) != __BIONIC_FORTIFY_UNKNOWN_SIZE &&
                __bos(dest) < __builtin_strlen(format),
                "format string will always overflow destination buffer")
    __errorattr("format string will always overflow destination buffer");

__BIONIC_FORTIFY_INLINE
__printflike(2, 3)
int sprintf(char *__restrict const __pass_object_size dest,
        const char *__restrict format, ...) __overloadable {
    va_list va;
    va_start(va, format);
    int result = __builtin___vsprintf_chk(dest, 0, __bos(dest), format, va);
    va_end(va);
    return result;
}
#endif /* __ANDROID_API__ >= __ANDROID_API_J_MR1__ */

#if __ANDROID_API__ >= __ANDROID_API_N__
__BIONIC_FORTIFY_INLINE
size_t fread(void *__restrict buf, size_t size, size_t count,
             FILE *__restrict stream) __overloadable
        __enable_if(__unsafe_check_mul_overflow(size, count), "size * count overflows")
        __errorattr("size * count overflows");

__BIONIC_FORTIFY_INLINE
size_t fread(void *__restrict buf, size_t size, size_t count,
             FILE *__restrict stream) __overloadable
    __enable_if(!__unsafe_check_mul_overflow(size, count), "no overflow")
    __enable_if(__bos(buf) != __BIONIC_FORTIFY_UNKNOWN_SIZE &&
                size * count > __bos(buf), "size * count is too large")
    __errorattr("size * count is too large");

__BIONIC_FORTIFY_INLINE
size_t fread(void *__restrict const __pass_object_size0 buf, size_t size,
             size_t count, FILE *__restrict stream) __overloadable {
    size_t bos = __bos0(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __call_bypassing_fortify(fread)(buf, size, count, stream);
    }

    return __fread_chk(buf, size, count, stream, bos);
}

size_t fwrite(const void * __restrict buf, size_t size,
              size_t count, FILE * __restrict stream) __overloadable
    __enable_if(__unsafe_check_mul_overflow(size, count),
                "size * count overflows")
    __errorattr("size * count overflows");

size_t fwrite(const void * __restrict buf, size_t size,
              size_t count, FILE * __restrict stream) __overloadable
    __enable_if(!__unsafe_check_mul_overflow(size, count), "no overflow")
    __enable_if(__bos(buf) != __BIONIC_FORTIFY_UNKNOWN_SIZE &&
                size * count > __bos(buf), "size * count is too large")
    __errorattr("size * count is too large");

__BIONIC_FORTIFY_INLINE
size_t fwrite(const void * __restrict const __pass_object_size0 buf,
              size_t size, size_t count, FILE * __restrict stream)
        __overloadable {
    size_t bos = __bos0(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __call_bypassing_fortify(fwrite)(buf, size, count, stream);
    }

    return __fwrite_chk(buf, size, count, stream, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_N__ */

#if __ANDROID_API__ >= __ANDROID_API_J_MR1__
__BIONIC_ERROR_FUNCTION_VISIBILITY
char *fgets(char* __restrict dest, int size, FILE* stream) __overloadable
    __enable_if(size < 0, "size is negative")
    __errorattr("size is negative");

__BIONIC_ERROR_FUNCTION_VISIBILITY
char *fgets(char* dest, int size, FILE* stream) __overloadable
    __enable_if(size >= 0 && size > __bos(dest),
                "size is larger than the destination buffer")
    __errorattr("size is larger than the destination buffer");

__BIONIC_FORTIFY_INLINE
char *fgets(char* __restrict const __pass_object_size dest,
        int size, FILE* stream) __overloadable {
    size_t bos = __bos(dest);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __call_bypassing_fortify(fgets)(dest, size, stream);
    }

    return __fgets_chk(dest, size, stream, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_J_MR1__ */

#else /* defined(__clang__) */

size_t __fread_real(void * __restrict, size_t, size_t, FILE * __restrict) __RENAME(fread);
__errordecl(__fread_too_big_error, "fread called with size * count bigger than buffer");
__errordecl(__fread_overflow, "fread called with overflowing size * count");

char* __fgets_real(char*, int, FILE*) __RENAME(fgets);
__errordecl(__fgets_too_big_error, "fgets called with size bigger than buffer");
__errordecl(__fgets_too_small_error, "fgets called with size less than zero");

size_t __fwrite_real(const void * __restrict, size_t, size_t, FILE * __restrict) __RENAME(fwrite);
__errordecl(__fwrite_too_big_error, "fwrite called with size * count bigger than buffer");
__errordecl(__fwrite_overflow, "fwrite called with overflowing size * count");


#if __ANDROID_API__ >= __ANDROID_API_J_MR1__
__BIONIC_FORTIFY_INLINE __printflike(3, 4)
int snprintf(char *__restrict dest, size_t size, const char* _Nonnull format, ...)
{
    return __builtin___snprintf_chk(dest, size, 0, __bos(dest), format,
                                    __builtin_va_arg_pack());
}

__BIONIC_FORTIFY_INLINE __printflike(2, 3)
int sprintf(char *__restrict dest, const char* _Nonnull format, ...) {
    return __builtin___sprintf_chk(dest, 0, __bos(dest), format,
                                   __builtin_va_arg_pack());
}
#endif /* __ANDROID_API__ >= __ANDROID_API_J_MR1__ */

#if __ANDROID_API__ >= __ANDROID_API_N__
__BIONIC_FORTIFY_INLINE
size_t fread(void *__restrict buf, size_t size, size_t count, FILE * __restrict stream) {
    size_t bos = __bos0(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __fread_real(buf, size, count, stream);
    }

    if (__builtin_constant_p(size) && __builtin_constant_p(count)) {
        size_t total;
        if (__size_mul_overflow(size, count, &total)) {
            __fread_overflow();
        }

        if (total > bos) {
            __fread_too_big_error();
        }

        return __fread_real(buf, size, count, stream);
    }

    return __fread_chk(buf, size, count, stream, bos);
}

__BIONIC_FORTIFY_INLINE
size_t fwrite(const void * __restrict buf, size_t size, size_t count, FILE * __restrict stream) {
    size_t bos = __bos0(buf);

    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __fwrite_real(buf, size, count, stream);
    }

    if (__builtin_constant_p(size) && __builtin_constant_p(count)) {
        size_t total;
        if (__size_mul_overflow(size, count, &total)) {
            __fwrite_overflow();
        }

        if (total > bos) {
            __fwrite_too_big_error();
        }

        return __fwrite_real(buf, size, count, stream);
    }

    return __fwrite_chk(buf, size, count, stream, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_N__ */

#if __ANDROID_API__ >= __ANDROID_API_J_MR1__
__BIONIC_FORTIFY_INLINE
char *fgets(char* dest, int size, FILE* stream) {
    size_t bos = __bos(dest);

    // Compiler can prove, at compile time, that the passed in size
    // is always negative. Force a compiler error.
    if (__builtin_constant_p(size) && (size < 0)) {
        __fgets_too_small_error();
    }

    // Compiler doesn't know destination size. Don't call __fgets_chk
    if (bos == __BIONIC_FORTIFY_UNKNOWN_SIZE) {
        return __fgets_real(dest, size, stream);
    }

    // Compiler can prove, at compile time, that the passed in size
    // is always <= the actual object size. Don't call __fgets_chk
    if (__builtin_constant_p(size) && (size <= (int) bos)) {
        return __fgets_real(dest, size, stream);
    }

    // Compiler can prove, at compile time, that the passed in size
    // is always > the actual object size. Force a compiler error.
    if (__builtin_constant_p(size) && (size > (int) bos)) {
        __fgets_too_big_error();
    }

    return __fgets_chk(dest, size, stream, bos);
}
#endif /* __ANDROID_API__ >= __ANDROID_API_J_MR1__ */

#endif /* defined(__clang__) */
#endif /* defined(__BIONIC_FORTIFY) */

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

__END_DECLS

#endif /* _STDIO_H_ */
