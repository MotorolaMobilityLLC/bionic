/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#ifndef _STRING_H_
#define _STRING_H_

#include <sys/cdefs.h>
#include <stddef.h>
#include <malloc.h>

__BEGIN_DECLS

extern void*  memccpy(void *, const void *, int, size_t);
extern void*  memchr(const void *, int, size_t) __purefunc;
extern void*  memrchr(const void *, int, size_t) __purefunc;
extern int    memcmp(const void *, const void *, size_t) __purefunc;
extern void*  memcpy(void *, const void *, size_t);
extern void*  memmove(void *, const void *, size_t);
extern void*  memset(void *, int, size_t);
extern void*  memmem(const void *, size_t, const void *, size_t) __purefunc;
extern void   memswap(void *, void *, size_t);

extern char*  index(const char *, int) __purefunc;
extern char*  rindex(const char *, int) __purefunc;
extern char*  strchr(const char *, int) __purefunc;
extern char*  strrchr(const char *, int) __purefunc;

extern size_t strlen(const char *) __purefunc;
extern int    strcmp(const char *, const char *) __purefunc;
extern char*  strcpy(char *, const char *);
extern char*  strcat(char *, const char *);

extern int    strcasecmp(const char *, const char *) __purefunc;
extern int    strncasecmp(const char *, const char *, size_t) __purefunc;
extern char*  strdup(const char *);

extern char*  strstr(const char *, const char *) __purefunc;
extern char*  strcasestr(const char *haystack, const char *needle) __purefunc;
extern char*  strtok(char *, const char *);
extern char*  strtok_r(char *, const char *, char**);

extern char*  strerror(int);
extern int    strerror_r(int errnum, char *buf, size_t n);

extern size_t strnlen(const char *, size_t) __purefunc;
extern char*  strncat(char *, const char *, size_t);
extern char*  strndup(const char *, size_t);
extern int    strncmp(const char *, const char *, size_t) __purefunc;
extern char*  strncpy(char *, const char *, size_t);

extern size_t strlcat(char *, const char *, size_t);
extern size_t strlcpy(char *, const char *, size_t);

extern size_t strcspn(const char *, const char *) __purefunc;
extern char*  strpbrk(const char *, const char *) __purefunc;
extern char*  strsep(char **, const char *);
extern size_t strspn(const char *, const char *);

extern char*  strsignal(int  sig);

extern int    strcoll(const char *, const char *) __purefunc;
extern size_t strxfrm(char *, const char *, size_t);

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#define __BIONIC_FORTIFY_INLINE \
    extern inline \
    __attribute__ ((always_inline)) \
    __attribute__ ((gnu_inline)) \
    __attribute__ ((artificial))

__BIONIC_FORTIFY_INLINE
void *memcpy (void *dest, const void *src, size_t len) {
    return __builtin___memcpy_chk (dest, src, len, __builtin_object_size (dest, 0));
}

__BIONIC_FORTIFY_INLINE
void *memmove (void *dest, const void *src, size_t len) {
    return __builtin___memmove_chk (dest, src, len, __builtin_object_size (dest, 0));
}

__BIONIC_FORTIFY_INLINE
char *strcpy(char *dest, const char *src) {
    return __builtin___strcpy_chk (dest, src, __builtin_object_size (dest, 0));
}

__BIONIC_FORTIFY_INLINE
char *strncpy(char *dest, const char *src, size_t n) {
    return __builtin___strncpy_chk(dest, src, n, __builtin_object_size (dest, 0));
}

__BIONIC_FORTIFY_INLINE
char *strcat(char *dest, const char *src) {
    return __builtin___strcat_chk (dest, src, __builtin_object_size (dest, 0));
}

__BIONIC_FORTIFY_INLINE
char *strncat(char *dest, const char *src, size_t n) {
    return __builtin___strncat_chk(dest, src, n, __builtin_object_size (dest, 0));
}

#undef __BIONIC_FORTIFY_INLINE
#endif

__END_DECLS

#endif /* _STRING_H_ */
