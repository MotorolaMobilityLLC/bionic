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

#ifndef _DIRENT_H_
#define _DIRENT_H_

#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

#ifndef DT_UNKNOWN
#define DT_UNKNOWN 0
#define DT_FIFO 1
#define DT_CHR 2
#define DT_DIR 4
#define DT_BLK 6
#define DT_REG 8
#define DT_LNK 10
#define DT_SOCK 12
#define DT_WHT 14
#endif

#if defined(__LP64__)
#define __DIRENT64_INO_T ino_t
#else
#define __DIRENT64_INO_T uint64_t /* Historical accident. */
#endif

#define __DIRENT64_BODY \
    __DIRENT64_INO_T d_ino; \
    off64_t d_off; \
    unsigned short d_reclen; \
    unsigned char d_type; \
    char d_name[256]; \

struct dirent { __DIRENT64_BODY };
struct dirent64 { __DIRENT64_BODY };

#undef __DIRENT64_BODY
#undef __DIRENT64_INO_T

/* glibc compatibility. */
#undef _DIRENT_HAVE_D_NAMLEN /* Linux doesn't have a d_namlen field. */
#define _DIRENT_HAVE_D_RECLEN
#define _DIRENT_HAVE_D_OFF
#define _DIRENT_HAVE_D_TYPE

#define d_fileno d_ino

typedef struct DIR DIR;

DIR* opendir(const char*);
DIR* fdopendir(int);
struct dirent* readdir(DIR*);
struct dirent64* readdir64(DIR*) __INTRODUCED_IN(21);
int readdir_r(DIR*, struct dirent*, struct dirent**);
int readdir64_r(DIR*, struct dirent64*, struct dirent64**) __INTRODUCED_IN(21);
int closedir(DIR*);
void rewinddir(DIR*);
void seekdir(DIR*, long) __INTRODUCED_IN(23);
long telldir(DIR*) __INTRODUCED_IN(23);
int dirfd(DIR*);
int alphasort(const struct dirent**, const struct dirent**);
int alphasort64(const struct dirent64**, const struct dirent64**) __INTRODUCED_IN(21);
int scandir64(const char*, struct dirent64***, int (*)(const struct dirent64*),
              int (*)(const struct dirent64**, const struct dirent64**)) __INTRODUCED_IN(21);
int scandir(const char*, struct dirent***, int (*)(const struct dirent*), int (*)(const struct dirent**, const struct dirent**));

#if defined(__USE_GNU)
int scandirat64(int, const char*, struct dirent64***, int (*)(const struct dirent64*),
                int (*)(const struct dirent64**, const struct dirent64**)) __INTRODUCED_IN(24);
int scandirat(int, const char*, struct dirent***, int (*)(const struct dirent*),
              int (*)(const struct dirent**, const struct dirent**)) __INTRODUCED_IN(24);
#endif

__END_DECLS

#endif /* _DIRENT_H_ */
