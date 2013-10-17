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

#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#include <errno.h>
#include <sys/cdefs.h>
#include <limits.h>		/* For LONG_BIT */
#include <string.h>		/* For memset() */
#include <sys/types.h>

#if defined(__LP64__)
/* For 64-bit, the kernel's struct sigaction doesn't match the POSIX one,
 * so we need to expose our own and translate behind the scenes. */
#  define sigaction __kernel_sigaction
#  include <asm/signal.h>
#  undef sigaction
#else
/* For 32-bit, we're stuck with the definitions we already shipped,
 * even though they contain a sigset_t that's too small. */
#  include <asm/signal.h>
#endif

#define __ARCH_SI_UID_T __kernel_uid32_t
#include <asm/siginfo.h>
#undef __ARCH_SI_UID_T

__BEGIN_DECLS

typedef int sig_atomic_t;

/* _NSIG is used by the SIGRTMAX definition under <asm/signal.h>, however
 * its definition is part of a #if __KERNEL__ .. #endif block in the original
 * kernel headers and is thus not part of our cleaned-up versions.
 *
 * Looking at the current kernel sources, it is defined as 64 for all
 * architectures except for the 'mips' one which set it to 128.
 */
#ifndef _NSIG
#  define _NSIG  64
#endif

extern const char* const sys_siglist[];
extern const char* const sys_signame[];

typedef __sighandler_t sig_t; /* BSD compatibility. */
typedef __sighandler_t sighandler_t; /* glibc compatibility. */

#if __LP64__

struct sigaction {
  unsigned int sa_flags;
  union {
    sighandler_t sa_handler;
    void (*sa_sigaction)(int, struct siginfo*, void*);
  };
  sigset_t sa_mask;
  void (*sa_restorer)(void);
};

#endif

extern int sigaction(int, const struct sigaction*, struct sigaction*);

extern sighandler_t signal(int, sighandler_t);
extern sighandler_t bsd_signal(int, sighandler_t);
extern sighandler_t sysv_signal(int, sighandler_t);

extern int siginterrupt(int, int);

extern int sigaddset(sigset_t*, int);
extern int sigdelset(sigset_t*, int);
extern int sigemptyset(sigset_t*);
extern int sigfillset(sigset_t*);
extern int sigismember(const sigset_t*, int);

extern int sigpending(sigset_t*) __nonnull((1));
extern int sigprocmask(int, const sigset_t*, sigset_t*);
extern int sigsuspend(const sigset_t*) __nonnull((1));
extern int sigwait(const sigset_t*, int*) __nonnull((1, 2));

extern int raise(int);
extern int kill(pid_t, int);
extern int killpg(int, int);

extern int sigaltstack(const stack_t*, stack_t*);

extern void psiginfo(const siginfo_t*, const char*);
extern void psignal(int, const char*);

__END_DECLS

#endif /* _SIGNAL_H_ */
