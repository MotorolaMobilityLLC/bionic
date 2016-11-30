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

#ifndef _SYS_RESOURCE_H_
#define _SYS_RESOURCE_H_

#include <sys/cdefs.h>
#include <sys/types.h>

#include <linux/resource.h>

__BEGIN_DECLS

/* The kernel header doesn't have these, but POSIX does. */
#define RLIM_SAVED_CUR RLIM_INFINITY
#define RLIM_SAVED_MAX RLIM_INFINITY

typedef unsigned long rlim_t;

int getrlimit(int, struct rlimit*);
int setrlimit(int, const struct rlimit*);

int getrlimit64(int, struct rlimit64*) __INTRODUCED_IN(21);
int setrlimit64(int, const struct rlimit64*) __INTRODUCED_IN(21);

int getpriority(int, id_t);
int setpriority(int, id_t, int);

int getrusage(int, struct rusage*);

int prlimit(pid_t, int, const struct rlimit*, struct rlimit*) __INTRODUCED_IN_32(24)
  __INTRODUCED_IN_64(21);
int prlimit64(pid_t, int, const struct rlimit64*, struct rlimit64*) __INTRODUCED_IN(21);

__END_DECLS

#endif /* _SYS_RESOURCE_H_ */
