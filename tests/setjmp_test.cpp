/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>

#include <setjmp.h>
#include <stdlib.h>
#include <sys/auxv.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <android-base/silent_death_test.h>
#include <android-base/test_utils.h>

#include "SignalUtils.h"
#include "sme_utils.h"

using setjmp_DeathTest = SilentDeathTest;

TEST(setjmp, setjmp_smoke) {
  int value;
  jmp_buf jb;
  if ((value = setjmp(jb)) == 0) {
    longjmp(jb, 123);
    FAIL(); // Unreachable.
  } else {
    ASSERT_EQ(123, value);
  }
}

TEST(setjmp, _setjmp_smoke) {
  int value;
  jmp_buf jb;
  if ((value = _setjmp(jb)) == 0) {
    _longjmp(jb, 456);
    FAIL(); // Unreachable.
  } else {
    ASSERT_EQ(456, value);
  }
}

TEST(setjmp, sigsetjmp_0_smoke) {
  int value;
  sigjmp_buf jb;
  if ((value = sigsetjmp(jb, 0)) == 0) {
    siglongjmp(jb, 789);
    FAIL(); // Unreachable.
  } else {
    ASSERT_EQ(789, value);
  }
}

TEST(setjmp, sigsetjmp_1_smoke) {
  int value;
  sigjmp_buf jb;
  if ((value = sigsetjmp(jb, 0)) == 0) {
    siglongjmp(jb, 0xabc);
    FAIL(); // Unreachable.
  } else {
    ASSERT_EQ(0xabc, value);
  }
}

// Two distinct signal sets.
struct SigSets {
  SigSets() : one(MakeSigSet(0)), two(MakeSigSet(1)) {
  }

  static sigset64_t MakeSigSet(int offset) {
    sigset64_t ss;
    sigemptyset64(&ss);
    sigaddset64(&ss, SIGUSR1 + offset);
#if defined(__BIONIC__)
    // TIMER_SIGNAL.
    sigaddset64(&ss, __SIGRTMIN);
#endif
    sigaddset64(&ss, SIGRTMIN + offset);
    return ss;
  }

  sigset64_t one;
  sigset64_t two;
};

void AssertSigmaskEquals(const sigset64_t& expected) {
  sigset64_t actual;
  sigprocmask64(SIG_SETMASK, nullptr, &actual);
  size_t end = sizeof(expected) * 8;
  for (size_t i = 1; i <= end; ++i) {
    EXPECT_EQ(sigismember64(&expected, i), sigismember64(&actual, i)) << i;
  }
}

TEST(setjmp, _setjmp_signal_mask) {
  SignalMaskRestorer smr;

  // _setjmp/_longjmp do not save/restore the signal mask.
  SigSets ss;
  sigprocmask64(SIG_SETMASK, &ss.one, nullptr);
  jmp_buf jb;
  if (_setjmp(jb) == 0) {
    sigprocmask64(SIG_SETMASK, &ss.two, nullptr);
    _longjmp(jb, 1);
    FAIL(); // Unreachable.
  } else {
    AssertSigmaskEquals(ss.two);
  }
}

TEST(setjmp, setjmp_signal_mask) {
  SignalMaskRestorer smr;

  // setjmp/longjmp do save/restore the signal mask on bionic, but not on glibc.
  // This is a BSD versus System V historical accident. POSIX leaves the
  // behavior unspecified, so any code that cares needs to use sigsetjmp.
  SigSets ss;
  sigprocmask64(SIG_SETMASK, &ss.one, nullptr);
  jmp_buf jb;
  if (setjmp(jb) == 0) {
    sigprocmask64(SIG_SETMASK, &ss.two, nullptr);
    longjmp(jb, 1);
    FAIL(); // Unreachable.
  } else {
#if defined(__BIONIC__)
    // bionic behaves like BSD and does save/restore the signal mask.
    AssertSigmaskEquals(ss.one);
#else
    // glibc behaves like System V and doesn't save/restore the signal mask.
    AssertSigmaskEquals(ss.two);
#endif
  }
}

TEST(setjmp, sigsetjmp_0_signal_mask) {
  SignalMaskRestorer smr;

  // sigsetjmp(0)/siglongjmp do not save/restore the signal mask.
  SigSets ss;
  sigprocmask64(SIG_SETMASK, &ss.one, nullptr);
  sigjmp_buf sjb;
  if (sigsetjmp(sjb, 0) == 0) {
    sigprocmask64(SIG_SETMASK, &ss.two, nullptr);
    siglongjmp(sjb, 1);
    FAIL(); // Unreachable.
  } else {
    AssertSigmaskEquals(ss.two);
  }
}

TEST(setjmp, sigsetjmp_1_signal_mask) {
  SignalMaskRestorer smr;

  // sigsetjmp(1)/siglongjmp does save/restore the signal mask.
  SigSets ss;
  sigprocmask64(SIG_SETMASK, &ss.one, nullptr);
  sigjmp_buf sjb;
  if (sigsetjmp(sjb, 1) == 0) {
    sigprocmask64(SIG_SETMASK, &ss.two, nullptr);
    siglongjmp(sjb, 1);
    FAIL(); // Unreachable.
  } else {
    AssertSigmaskEquals(ss.one);
  }
}

#if defined(__arm__)

  // arm callee saves: r4-r11, d8-d15

  // In practice, like x86, we've seen clang clobber the integer callee saves and break this test.
  // Since 32-bit is deprecated (to the extent that we can't run 32-bit code on current devices),
  // we just test the easy floating point callee saves.

  #define SET_REGS() \
    asm volatile( \
      "vmov.f64 d8, #8.0 ; \
       vmov.f64 d9, #9.0 ; \
       vmov.f64 d10, #10.0 ; \
       vmov.f64 d11, #11.0 ; \
       vmov.f64 d12, #12.0 ; \
       vmov.f64 d13, #13.0 ; \
       vmov.f64 d14, #14.0 ; \
       vmov.f64 d15, #15.0 ; \
      " : : : \
      "d8", "d9", "d10", "d11", "d12", "d13", "d14", "d15")
  #define CLEAR_REGS() \
    asm volatile( \
      "vmov.i64 d8, #0 ; \
       vmov.i64 d9, #0 ; \
       vmov.i64 d10, #0 ; \
       vmov.i64 d11, #0 ; \
       vmov.i64 d12, #0 ; \
       vmov.i64 d13, #0 ; \
       vmov.i64 d14, #0 ; \
       vmov.i64 d15, #0 ; \
      " : : : \
      "d8", "d9", "d10", "d11", "d12", "d13", "d14", "d15")
  // clang inline assembler doesn't seem to allow any reasonable way of
  // storing the fp registers directly into the array, but they're unlikely
  // to be corrupted anyway.
  #define GET_FREG(n) ({ double _r; asm volatile("fcpyd %P0, d"#n : "=w"(_r) : :); _r;})
  #define CHECK_REGS() \
    EXPECT_EQ(8.0,  GET_FREG(8));  EXPECT_EQ(9.0,  GET_FREG(9)); \
    EXPECT_EQ(10.0, GET_FREG(10)); EXPECT_EQ(11.0, GET_FREG(11)); \
    EXPECT_EQ(12.0, GET_FREG(12)); EXPECT_EQ(13.0, GET_FREG(13)); \
    EXPECT_EQ(14.0, GET_FREG(14)); EXPECT_EQ(15.0, GET_FREG(15))

#elif defined(__aarch64__)

  // arm64 callee saves: x19-x28, d8-d15

  #define SET_REGS() \
    asm volatile( \
      "mov x19, #19 ; \
       mov x20, #20 ; \
       mov x21, #21 ; \
       mov x22, #22 ; \
       mov x23, #23 ; \
       mov x24, #24 ; \
       mov x25, #25 ; \
       mov x26, #26 ; \
       mov x27, #27 ; \
       mov x28, #28 ; \
       fmov d8, #8.0 ; \
       fmov d9, #9.0 ; \
       fmov d10, #10.0 ; \
       fmov d11, #11.0 ; \
       fmov d12, #12.0 ; \
       fmov d13, #13.0 ; \
       fmov d14, #14.0 ; \
       fmov d15, #15.0 ; \
      " : : : \
      "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", \
      "d8", "d9", "d10", "d11", "d12", "d13", "d14", "d15")
  #define CLEAR_REGS() \
    asm volatile( \
      "mov x19, #0 ; \
       mov x20, #0 ; \
       mov x21, #0 ; \
       mov x22, #0 ; \
       mov x23, #0 ; \
       mov x24, #0 ; \
       mov x25, #0 ; \
       mov x26, #0 ; \
       mov x27, #0 ; \
       mov x28, #0 ; \
       fmov d8, xzr ; \
       fmov d9, xzr ; \
       fmov d10, xzr ; \
       fmov d11, xzr ; \
       fmov d12, xzr ; \
       fmov d13, xzr ; \
       fmov d14, xzr ; \
       fmov d15, xzr ; \
      " : : : \
      "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", \
      "d8", "d9", "d10", "d11", "d12", "d13", "d14", "d15")
  #define CHECK_REGS() \
    asm volatile( \
      "str x19, %0, #8 ; \
       str x20, %0, #8 ; \
       str x21, %0, #8 ; \
       str x22, %0, #8 ; \
       str x23, %0, #8 ; \
       str x24, %0, #8 ; \
       str x25, %0, #8 ; \
       str x26, %0, #8 ; \
       str x27, %0, #8 ; \
       str x28, %0, #8 ; \
       str d8,  %1, #8 ; \
       str d9,  %1, #8 ; \
       str d10, %1, #8 ; \
       str d11, %1, #8 ; \
       str d12, %1, #8 ; \
       str d13, %1, #8 ; \
       str d14, %1, #8 ; \
       str d15, %1, #8 ; \
      " : "=m"(regs), "=m"(fregs) : : \
      "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28"); \
    EXPECT_EQ(19, regs[0]); EXPECT_EQ(20, regs[1]); \
    EXPECT_EQ(21, regs[2]); EXPECT_EQ(22, regs[3]); \
    EXPECT_EQ(23, regs[4]); EXPECT_EQ(24, regs[5]); \
    EXPECT_EQ(25, regs[6]); EXPECT_EQ(26, regs[7]); \
    EXPECT_EQ(27, regs[8]); EXPECT_EQ(28, regs[9]); \
    EXPECT_EQ(8.0,  fregs[0]);  EXPECT_EQ(9.0, fregs[1]); \
    EXPECT_EQ(10.0, fregs[2]); EXPECT_EQ(11.0, fregs[3]); \
    EXPECT_EQ(12.0, fregs[4]); EXPECT_EQ(13.0, fregs[5]); \
    EXPECT_EQ(14.0, fregs[6]); EXPECT_EQ(15.0, fregs[7])

#elif defined(__riscv)

  // riscv64 callee saves: s0-s11, fs0-fs11

  // TODO: use Zfa to get 1.0 rather than the one_p trick.
  #define SET_REGS() \
    double one = 1, *one_p = &one; \
    asm volatile( \
      "li s0, 8 ; \
       li s1, 9 ; \
       li s2, 18 ; \
       li s3, 19 ; \
       li s4, 20 ; \
       li s5, 21 ; \
       li s6, 22 ; \
       li s7, 23 ; \
       li s8, 24 ; \
       li s9, 25 ; \
       li s10, 26 ; \
       li s11, 27 ; \
       fmv.d.x fs0, zero ; \
       fld fs1, (%0) ; \
       fadd.d fs2, fs1, fs1 ; \
       fadd.d fs3, fs2, fs1 ; \
       fadd.d fs4, fs3, fs1 ; \
       fadd.d fs5, fs4, fs1 ; \
       fadd.d fs6, fs5, fs1 ; \
       fadd.d fs7, fs6, fs1 ; \
       fadd.d fs8, fs7, fs1 ; \
       fadd.d fs9, fs8, fs1 ; \
       fadd.d fs10, fs9, fs1 ; \
       fadd.d fs11, fs10, fs1 ; \
      " : : "r"(one_p) : \
      "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", \
      "fs0", "fs1", "fs2", "fs3", "fs4", "fs5", \
      "fs6", "fs7", "fs8", "fs9", "fs10", "fs11")
  #define CLEAR_REGS() \
    asm volatile( \
      "li s0, 0 ; \
       li s1, 0 ; \
       li s2, 0 ; \
       li s3, 0 ; \
       li s4, 0 ; \
       li s5, 0 ; \
       li s6, 0 ; \
       li s7, 0 ; \
       li s8, 0 ; \
       li s9, 0 ; \
       li s10, 0 ; \
       li s11, 0 ; \
       fmv.d.x fs0, zero ; \
       fmv.d.x fs1, zero ; \
       fmv.d.x fs2, zero ; \
       fmv.d.x fs3, zero ; \
       fmv.d.x fs4, zero ; \
       fmv.d.x fs5, zero ; \
       fmv.d.x fs6, zero ; \
       fmv.d.x fs7, zero ; \
       fmv.d.x fs8, zero ; \
       fmv.d.x fs9, zero ; \
       fmv.d.x fs10, zero ; \
       fmv.d.x fs11, zero ; \
      " : : : \
      "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", \
      "fs0", "fs1", "fs2", "fs3", "fs4", "fs5", \
      "fs6", "fs7", "fs8", "fs9", "fs10", "fs11")
  #define CHECK_REGS() \
    asm volatile( \
      "sd s0, (0 * 8)%0 ; \
       sd s1, (1 * 8)%0 ; \
       sd s2, (2 * 8)%0 ; \
       sd s3, (3 * 8)%0 ; \
       sd s4, (4 * 8)%0 ; \
       sd s5, (5 * 8)%0 ; \
       sd s6, (6 * 8)%0 ; \
       sd s7, (7 * 8)%0 ; \
       sd s8, (8 * 8)%0 ; \
       sd s9, (9 * 8)%0 ; \
       sd s10, (10 * 8)%0 ; \
       sd s11, (11 * 8)%0 ; \
       fsd fs0, (0 * 8)%1 ; \
       fsd fs1, (1 * 8)%1 ; \
       fsd fs2, (2 * 8)%1 ; \
       fsd fs3, (3 * 8)%1 ; \
       fsd fs4, (4 * 8)%1 ; \
       fsd fs5, (5 * 8)%1 ; \
       fsd fs6, (6 * 8)%1 ; \
       fsd fs7, (7 * 8)%1 ; \
       fsd fs8, (8 * 8)%1 ; \
       fsd fs9, (9 * 8)%1 ; \
       fsd fs10, (10 * 8)%1 ; \
       fsd fs11, (11 * 8)%1 ; \
      " : "=m"(regs), "=m"(fregs) : : \
      "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11"); \
    EXPECT_EQ( 8, regs[0]);  EXPECT_EQ( 9, regs[1]); \
    EXPECT_EQ(18, regs[2]);  EXPECT_EQ(19, regs[3]); \
    EXPECT_EQ(22, regs[4]);  EXPECT_EQ(23, regs[5]); \
    EXPECT_EQ(24, regs[6]);  EXPECT_EQ(25, regs[7]); \
    EXPECT_EQ(26, regs[8]);  EXPECT_EQ(27, regs[9]); \
    EXPECT_EQ(27, regs[10]); EXPECT_EQ(28, regs[11]); \
    EXPECT_EQ(0.0, fregs[0]); EXPECT_EQ(1.0, fregs[1]); \
    EXPECT_EQ(2.0, fregs[2]); EXPECT_EQ(3.0, fregs[3]); \
    EXPECT_EQ(4.0, fregs[4]); EXPECT_EQ(5.0, fregs[5]); \
    EXPECT_EQ(6.0, fregs[6]); EXPECT_EQ(7.0, fregs[7]); \
    EXPECT_EQ(8.0, fregs[8]); EXPECT_EQ(9.0, fregs[9]); \
    EXPECT_EQ(10.0, fregs[10]); EXPECT_EQ(11.0, fregs[11])

#elif defined(__i386__)

  // x86 callee saves: esi, edi, ebx, ebp

  // x86 has so few registers it's basically impossible to do anything before
  // they get clobbered.
  // (x86 has no floating point callee saves so there's nothing to check there.)
  #define SET_REGS()
  #define CLEAR_REGS()
  #define CHECK_REGS()

#elif defined(__x86_64__)

  // x86-64 callee saves: rbp, rbx, r12, r13, r14, r15

  #define SET_REGS() \
    /* rbp is used by the compiler, so we can't just set a known value. */ \
    long old_rbp; \
    asm volatile( \
      "movq %%rbp, %0 ; \
       movq $2, %%rbx ; \
       movq $3, %%r12 ; \
       movq $4, %%r13 ; \
       movq $5, %%r14 ; \
       movq $6, %%r15 ; \
      " : "=r"(old_rbp) : : "rbx", "r12", "r13", "r14", "r15")
  #define CLEAR_REGS() \
    asm volatile( \
      "movq $0, %%rbx ; \
       movq $0, %%r12 ; \
       movq $0, %%r13 ; \
       movq $0, %%r14 ; \
       movq $0, %%r15 ; \
      " : : : "rbx", "r12", "r13", "r14", "r15")
  #define CHECK_REGS() \
    asm volatile( \
      "movq %%rbp, (1 * 8) + %0 ; \
       movq %%rbx, (2 * 8) + %0 ; \
       movq %%r12, (3 * 8) + %0 ; \
       movq %%r13, (4 * 8) + %0 ; \
       movq %%r14, (5 * 8) + %0 ; \
       movq %%r15, (6 * 8) + %0 ; \
      " : "=m"(regs) : : "rbx", "r12", "r13", "r14", "r15"); \
    EXPECT_EQ(old_rbp, regs[1]); \
    EXPECT_EQ(2, regs[2]); EXPECT_EQ(3, regs[3]); EXPECT_EQ(4, regs[4]); \
    EXPECT_EQ(5, regs[5]); EXPECT_EQ(6, regs[6])

#endif

TEST(setjmp, setjmp_registers) {
  [[maybe_unused]] long regs[32];
  [[maybe_unused]] double fregs[32];
  jmp_buf jb;
  SET_REGS();
  int value = setjmp(jb);
  if (value == 0) {
    // We got here from the original setjmp() call.
    CLEAR_REGS();
    longjmp(jb, 123);
    FAIL(); // Unreachable.
  } else {
    // We got here from the longjmp() call.
    CHECK_REGS();
    ASSERT_EQ(123, value);
  }
}

#if defined(__arm__)
#define JB_SIGFLAG_OFFSET 0
#define JB_CHECKSUM_OFFSET 31
#elif defined(__aarch64__)
#define JB_SIGFLAG_OFFSET 0
#define JB_CHECKSUM_OFFSET 24
#elif defined(__i386__)
#define JB_SIGFLAG_OFFSET 8
#define JB_CHECKSUM_OFFSET 9
#elif defined(__riscv)
#define JB_SIGFLAG_OFFSET 0
#define JB_CHECKSUM_OFFSET 29
#elif defined(__x86_64)
#define JB_SIGFLAG_OFFSET 8
#define JB_CHECKSUM_OFFSET 10
#endif

TEST_F(setjmp_DeathTest, setjmp_cookie) {
#if defined(__BIONIC__)
  jmp_buf jb;
  int value = setjmp(jb);
  ASSERT_EQ(0, value);

#if defined(__aarch64__) || defined(__i386__) || defined(__x86_64__)
  long* raw_words = reinterpret_cast<long*>(jb);

  // Corrupt the cookie.
  raw_words[JB_SIGFLAG_OFFSET] = 0xfeedface;
  // Recompute the checksum.
  // This assumes that the checksum is the last non-reserved word,
  // and that we don't checksum the reserved words,
  // which is true for all our architectures.
  long cs = 0;
  for (size_t i = 0; i < JB_CHECKSUM_OFFSET; i++) {
    cs ^= raw_words[i];
  }
  raw_words[JB_CHECKSUM_OFFSET] = cs;

  EXPECT_EXIT(longjmp(jb, 0), testing::KilledBySignal(SIGABRT), "setjmp cookie mismatch");
#else
  // TODO: we can't make this EXPECT_EXIT() because the implementations are wrong!
  // TODO: we need to fix longjmp() to check the cookie _before_ corrupting sp + pc!
  EXPECT_DEATH(longjmp(jb, 0), "");
#endif
#else
  GTEST_SKIP() << "bionic-only test";
#endif
}

TEST_F(setjmp_DeathTest, setjmp_checksum) {
#if defined(__BIONIC__)
  jmp_buf jb;
  int value = setjmp(jb);
  ASSERT_EQ(0, value);

  // Flip a bit.
  reinterpret_cast<long*>(jb)[1] ^= 1;

  EXPECT_EXIT(longjmp(jb, 1), testing::KilledBySignal(SIGABRT), "setjmp checksum mismatch");
#else
  GTEST_SKIP() << "bionic-only test";
#endif
}

__attribute__((noinline)) void call_longjmp(jmp_buf buf) {
  longjmp(buf, 123);
}

TEST(setjmp, setjmp_stack) {
  jmp_buf buf;
  int value = setjmp(buf);
  if (value == 0) call_longjmp(buf);
  EXPECT_EQ(123, value);
}

TEST(setjmp, bug_152210274) {
  // Ensure that we never have a mangled value in the stack pointer.
#if defined(__BIONIC__)
  struct sigaction sa = {.sa_flags = SA_SIGINFO, .sa_sigaction = [](int, siginfo_t*, void*) {}};
  ASSERT_EQ(0, sigaction(SIGPROF, &sa, 0));

  constexpr size_t kNumThreads = 20;

  // Start a bunch of threads calling setjmp/longjmp.
  auto jumper = [](void* arg) -> void* {
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGPROF);
    pthread_sigmask(SIG_UNBLOCK, &set, nullptr);

    jmp_buf buf;
    for (size_t count = 0; count < 100000; ++count) {
      if (setjmp(buf) != 0) {
        perror("setjmp");
        abort();
      }
      // This will never be true, but the compiler doesn't know that, so the
      // setjmp won't be removed by DCE. With HWASan/MTE this also acts as a
      // kind of enforcement that the threads are done before leaving the test.
      if (*static_cast<size_t*>(arg) != 123) longjmp(buf, 1);
    }
    return nullptr;
  };
  pthread_t threads[kNumThreads];
  pid_t tids[kNumThreads] = {};
  size_t var = 123;
  for (size_t i = 0; i < kNumThreads; ++i) {
    ASSERT_EQ(0, pthread_create(&threads[i], nullptr, jumper, &var));
    tids[i] = pthread_gettid_np(threads[i]);
  }

  // Start the interrupter thread.
  auto interrupter = [](void* arg) -> void* {
    pid_t* tids = static_cast<pid_t*>(arg);
    for (size_t count = 0; count < 1000; ++count) {
      for (size_t i = 0; i < kNumThreads; i++) {
        if (tgkill(getpid(), tids[i], SIGPROF) == -1 && errno != ESRCH) {
          perror("tgkill failed");
          abort();
        }
      }
      usleep(100);
    }
    return nullptr;
  };
  pthread_t t;
  ASSERT_EQ(0, pthread_create(&t, nullptr, interrupter, tids));
  pthread_join(t, nullptr);
  for (size_t i = 0; i < kNumThreads; i++) {
    pthread_join(threads[i], nullptr);
  }
#else
  GTEST_SKIP() << "tests uses functions not in glibc";
#endif
}

#if defined(__aarch64__)
// Call sigsetjmp and verify SME ZA state
static void sigsetjmp_helper() {
  sigjmp_buf jb;
  sigsetjmp(jb, 0);
  bool za_state = sme_is_za_on();
  sme_disable_za();  // Turn ZA off anyway.
  ASSERT_FALSE(za_state);
}

// Call siglongjmp and verify SME ZA state
static void siglongjmp_helper() {
  int value;
  sigjmp_buf jb;
  if ((value = sigsetjmp(jb, 0)) == 0) {
    siglongjmp(jb, 789);
    sme_disable_za();
    FAIL();  // Unreachable.
  } else {
    bool za_state = sme_is_za_on();
    sme_disable_za();  // Turn ZA off anyway.
    ASSERT_EQ(789, value);
    ASSERT_FALSE(za_state);
  }
}

TEST(setjmp, sigsetjmp_sme) {
  if (!sme_is_enabled()) {
    GTEST_SKIP() << "SME is not enabled on device.";
  }
  __arm_za_disable();
  sme_dormant_caller(&sigsetjmp_helper);
}

TEST(setjmp, siglongjmp_sme) {
  if (!sme_is_enabled()) {
    GTEST_SKIP() << "SME is not enabled on device.";
  }
  __arm_za_disable();
  sme_dormant_caller(&siglongjmp_helper);
}
#endif
