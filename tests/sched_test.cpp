/*
 * Copyright (C) 2013 The Android Open Source Project
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

#include <errno.h>
#include <sched.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "utils.h"

// Used to test clone/clone3 when setting CLONE_VM
static int child_fn_CLONE_VM(void* i_ptr) {
  *reinterpret_cast<int*>(i_ptr) = 42;
  return 123;
}

#if defined(__BIONIC__)
static void align_clone3_stack(clone_args& cl_args) {
  // Ensure that both the top and bottom of the child stack are 16-byte
  // aligned.  The `clone3` system call expects that the provided pointer
  // refers to the lowest byte in the stack area.
  uint64_t stack_ptr_misalignment = cl_args.stack & 0xf;
  if (stack_ptr_misalignment != 0) {
    uint64_t alignment_offset = 16 - stack_ptr_misalignment;
    cl_args.stack += alignment_offset;
    cl_args.stack_size -= alignment_offset;
    cl_args.stack_size &= ~0xf;
  }
}

// Used to test clone/clone3 when not setting CLONE_VM.  Useful for testing the
// argument juggling code independent of virtual memory shenanigans.
static int child_fn_no_CLONE_VM(void* arg) {
  if (reinterpret_cast<uintptr_t>(arg) == 42) {
    return 130;
  } else {
    return 140;
  }
}
#endif

TEST(sched, clone) {
#if defined(__BIONIC__)
  void* child_stack[1024];

  int i = 0;
  pid_t tid = clone(child_fn_CLONE_VM, &child_stack[1024], CLONE_VM, &i);

  int status;
  ASSERT_EQ(tid, TEMP_FAILURE_RETRY(waitpid(tid, &status, __WCLONE)));

  ASSERT_EQ(42, i);

  ASSERT_TRUE(WIFEXITED(status));
  ASSERT_EQ(123, WEXITSTATUS(status));
#else
  // For glibc, any call to clone with CLONE_VM set will cause later pthread
  // calls in the same process to misbehave.
  // See https://sourceware.org/bugzilla/show_bug.cgi?id=10311 for more details.
  GTEST_SKIP() << "glibc is broken";
#endif
}

TEST(sched, clone_errno) {
  // Check that our hand-written clone assembler sets errno correctly on failure.
  uintptr_t fake_child_stack[16];
  // If CLONE_THREAD is set, CLONE_SIGHAND must be set too.
  ASSERT_ERRNO_FAILURE(EINVAL, -1,
                       clone(child_fn_CLONE_VM, &fake_child_stack[16], CLONE_THREAD, nullptr));
}

TEST(sched, clone_null_child_stack) {
  int i = 0;
  ASSERT_ERRNO_FAILURE(EINVAL, -1, clone(child_fn_CLONE_VM, nullptr, CLONE_VM, &i));
}

TEST(sched, clone3) {
#if defined(__BIONIC__)
  void* child_stack[1024];

  clone_args cl_args = {};
  cl_args.stack = reinterpret_cast<uint64_t>(&child_stack);
  cl_args.stack_size = sizeof(child_stack);
  cl_args.flags = CLONE_VM;
  cl_args.exit_signal = SIGCHLD;
  align_clone3_stack(cl_args);

  int i = 0;
  pid_t tid = clone3(&cl_args, sizeof(struct clone_args), child_fn_CLONE_VM, &i);

  ASSERT_NE(-1, tid);

  int status;
  ASSERT_EQ(tid, TEMP_FAILURE_RETRY(waitpid(tid, &status, __WALL)));

  ASSERT_TRUE(WIFEXITED(status));
  ASSERT_EQ(123, WEXITSTATUS(status));

  ASSERT_EQ(42, i);
#else
  GTEST_SKIP() << "glibc does not export a clone3 wrapper";
#endif
}

TEST(sched, clone3_without_fn) {
#if defined(__BIONIC__)
  clone_args cl_args = {.exit_signal = SIGCHLD};

  pid_t tid = clone3(&cl_args, sizeof(struct clone_args), nullptr, nullptr);
  ASSERT_NE(-1, tid);

  if (tid == 0) {
    exit(42);

  } else {
    AssertChildExited(tid, 42);
  }
#else
  GTEST_SKIP() << "glibc does not export a clone3 wrapper";
#endif
}

TEST(sched, clone3_with_stack) {
#if defined(__BIONIC__)
  void* child_stack[1024];

  clone_args cl_args = {};
  cl_args.exit_signal = SIGCHLD;
  cl_args.stack = reinterpret_cast<uint64_t>(&child_stack);
  cl_args.stack_size = sizeof(child_stack);
  align_clone3_stack(cl_args);

  pid_t tid = clone3(&cl_args, sizeof(struct clone_args), child_fn_no_CLONE_VM,
                     reinterpret_cast<void*>(42));

  ASSERT_NE(-1, tid);
  AssertChildExited(tid, 130);
#else
  GTEST_SKIP() << "glibc does not export a clone3 wrapper";
#endif
}

TEST(sched, clone3_errno) {
#if defined(__BIONIC__)
  clone_args cl_args = {};
  cl_args.flags = CLONE_THREAD;

  errno = 0;
  // If CLONE_THREAD is set, CLONE_SIGHAND must be set too.
  ASSERT_ERRNO_FAILURE(EINVAL, -1, clone3(&cl_args, sizeof(struct clone_args), nullptr, nullptr));
#else
  GTEST_SKIP() << "glibc does not export a clone3 wrapper";
#endif
}

TEST(sched, clone3_null_child_stack) {
#if defined(__BIONIC__)
  clone_args cl_args = {};
  errno = 0;
  ASSERT_ERRNO_FAILURE(EINVAL, -1,
                       clone3(&cl_args, sizeof(struct clone_args), child_fn_no_CLONE_VM, nullptr));
#else
  GTEST_SKIP() << "glibc does not export a clone3 wrapper";
#endif
}

TEST(sched, clone3_vm_without_fn) {
#if defined(__BIONIC__)
  clone_args cl_args = {};
  cl_args.flags = CLONE_VM;
  errno = 0;
  ASSERT_ERRNO_FAILURE(EINVAL, -1, clone3(&cl_args, sizeof(struct clone_args), nullptr, nullptr));
#else
  GTEST_SKIP() << "glibc does not export a clone3 wrapper";
#endif
}

TEST(sched, cpu_set) {
  cpu_set_t set;

  CPU_ZERO(&set);
  CPU_SET(0, &set);
  CPU_SET(17, &set);
  for (int i = 0; i < CPU_SETSIZE; i++) {
    ASSERT_EQ(i == 0 || i == 17, CPU_ISSET(i, &set));
  }

  // We should fail silently if we try to set/test outside the range.
  CPU_SET(CPU_SETSIZE, &set);
  ASSERT_FALSE(CPU_ISSET(CPU_SETSIZE, &set));
}

TEST(sched, cpu_count) {
  cpu_set_t set;

  CPU_ZERO(&set);
  ASSERT_EQ(0, CPU_COUNT(&set));
  CPU_SET(2, &set);
  CPU_SET(10, &set);
  ASSERT_EQ(2, CPU_COUNT(&set));
  CPU_CLR(10, &set);
  ASSERT_EQ(1, CPU_COUNT(&set));
}

TEST(sched, cpu_zero) {
  cpu_set_t set;

  CPU_ZERO(&set);
  ASSERT_EQ(0, CPU_COUNT(&set));
  for (int i = 0; i < CPU_SETSIZE; i++) {
    ASSERT_FALSE(CPU_ISSET(i, &set));
  }
}

TEST(sched, cpu_clr) {
  cpu_set_t set;

  CPU_ZERO(&set);
  CPU_SET(0, &set);
  CPU_SET(1, &set);
  for (int i = 0; i < CPU_SETSIZE; i++) {
    ASSERT_EQ(i == 0 || i == 1, CPU_ISSET(i, &set));
  }
  CPU_CLR(1, &set);
  for (int i = 0; i < CPU_SETSIZE; i++) {
    ASSERT_EQ(i == 0, CPU_ISSET(i, &set));
  }

  // We should fail silently if we try to clear/test outside the range.
  CPU_CLR(CPU_SETSIZE, &set);
  ASSERT_FALSE(CPU_ISSET(CPU_SETSIZE, &set));
}

TEST(sched, cpu_equal) {
  cpu_set_t set1;
  cpu_set_t set2;

  CPU_ZERO(&set1);
  CPU_ZERO(&set2);
  CPU_SET(1, &set1);
  ASSERT_FALSE(CPU_EQUAL(&set1, &set2));
  CPU_SET(1, &set2);
  ASSERT_TRUE(CPU_EQUAL(&set1, &set2));
}

TEST(sched, cpu_op) {
  cpu_set_t set1;
  cpu_set_t set2;
  cpu_set_t set3;

  CPU_ZERO(&set1);
  CPU_ZERO(&set2);
  CPU_ZERO(&set3);
  CPU_SET(0, &set1);
  CPU_SET(0, &set2);
  CPU_SET(1, &set2);

  CPU_AND(&set3, &set1, &set2);
  for (int i = 0; i < CPU_SETSIZE; i++) {
    ASSERT_EQ(i == 0, CPU_ISSET(i, &set3));
  }

  CPU_XOR(&set3, &set1, &set2);
  for (int i = 0; i < CPU_SETSIZE; i++) {
    ASSERT_EQ(i == 1, CPU_ISSET(i, &set3));
  }

  CPU_OR(&set3, &set1, &set2);
  for (int i = 0; i < CPU_SETSIZE; i++) {
    ASSERT_EQ(i == 0 || i == 1, CPU_ISSET(i, &set3));
  }
}

TEST(sched, cpu_alloc_small) {
  cpu_set_t* set = CPU_ALLOC(17);
  size_t size = CPU_ALLOC_SIZE(17);

  CPU_ZERO_S(size, set);
  ASSERT_EQ(0, CPU_COUNT_S(size, set));
  CPU_SET_S(16, size, set);
  ASSERT_TRUE(CPU_ISSET_S(16, size, set));

  CPU_FREE(set);
}

TEST(sched, cpu_alloc_big) {
  cpu_set_t* set = CPU_ALLOC(10 * CPU_SETSIZE);
  size_t size = CPU_ALLOC_SIZE(10 * CPU_SETSIZE);

  CPU_ZERO_S(size, set);
  ASSERT_EQ(0, CPU_COUNT_S(size, set));
  CPU_SET_S(CPU_SETSIZE, size, set);
  ASSERT_TRUE(CPU_ISSET_S(CPU_SETSIZE, size, set));

  CPU_FREE(set);
}

TEST(sched, cpu_s_macros) {
  int set_size = 64;
  size_t size = CPU_ALLOC_SIZE(set_size);
  cpu_set_t* set = CPU_ALLOC(set_size);

  CPU_ZERO_S(size, set);
  for (int i = 0; i < set_size; i++) {
    ASSERT_FALSE(CPU_ISSET_S(i, size, set));
    CPU_SET_S(i, size, set);
    ASSERT_TRUE(CPU_ISSET_S(i, size, set));
    ASSERT_EQ(i + 1, CPU_COUNT_S(size, set));
  }

  for (int i = 0; i < set_size; i++) {
    CPU_CLR_S(i, size, set);
    ASSERT_FALSE(CPU_ISSET_S(i, size, set));
    ASSERT_EQ(set_size - i - 1, CPU_COUNT_S(size, set));
  }

  CPU_FREE(set);
}

TEST(sched, cpu_op_s_macros) {
  int set_size1 = 64;
  int set_size2 = set_size1 * 2;
  int set_size3 = set_size1 * 3;
  size_t size1 = CPU_ALLOC_SIZE(set_size1);
  size_t size2 = CPU_ALLOC_SIZE(set_size2);
  size_t size3 = CPU_ALLOC_SIZE(set_size3);

  cpu_set_t* set1 = CPU_ALLOC(set_size1);
  cpu_set_t* set2 = CPU_ALLOC(set_size2);
  cpu_set_t* set3 = CPU_ALLOC(set_size3);
  CPU_ZERO_S(size1, set1);
  CPU_ZERO_S(size2, set2);
  CPU_ZERO_S(size3, set3);

  CPU_SET_S(0, size1, set1);
  CPU_SET_S(0, size2, set2);
  CPU_SET_S(1, size3, set2);

  CPU_AND_S(size1, set3, set1, set2);
  for (int i = 0; i < set_size3; i++) {
    ASSERT_EQ(i == 0, CPU_ISSET_S(i, size3, set3));
  }

  CPU_OR_S(size1, set3, set1, set2);
  for (int i = 0; i < set_size3; i++) {
    ASSERT_EQ(i == 0 || i == 1, CPU_ISSET_S(i, size3, set3));
  }

  CPU_XOR_S(size1, set3, set1, set2);
  for (int i = 0; i < set_size3; i++) {
    ASSERT_EQ(i == 1, CPU_ISSET_S(i, size3, set3));
  }

  CPU_FREE(set1);
  CPU_FREE(set2);
  CPU_FREE(set3);
}

TEST(sched, cpu_equal_s) {
  int set_size1 = 64;
  int set_size2 = set_size1 * 2;
  size_t size1 = CPU_ALLOC_SIZE(set_size1);
  size_t size2 = CPU_ALLOC_SIZE(set_size2);

  cpu_set_t* set1 = CPU_ALLOC(set_size1);
  cpu_set_t* set2 = CPU_ALLOC(set_size2);

  CPU_ZERO_S(size1, set1);
  CPU_ZERO_S(size2, set2);

  CPU_SET_S(0, size1, set1);
  ASSERT_TRUE(CPU_EQUAL_S(size1, set1, set1));
  ASSERT_FALSE(CPU_EQUAL_S(size1, set1, set2));
  CPU_SET_S(0, size2, set2);
  ASSERT_TRUE(CPU_EQUAL_S(size1, set1, set2));

  CPU_FREE(set1);
  CPU_FREE(set2);
}

TEST(sched, sched_get_priority_min_sched_get_priority_max) {
  EXPECT_LE(sched_get_priority_min(SCHED_BATCH), sched_get_priority_max(SCHED_BATCH));
  EXPECT_LE(sched_get_priority_min(SCHED_FIFO), sched_get_priority_max(SCHED_FIFO));
  EXPECT_LE(sched_get_priority_min(SCHED_IDLE), sched_get_priority_max(SCHED_IDLE));
  EXPECT_LE(sched_get_priority_min(SCHED_OTHER), sched_get_priority_max(SCHED_OTHER));
  EXPECT_LE(sched_get_priority_min(SCHED_RR), sched_get_priority_max(SCHED_RR));
}

TEST(sched, sched_getscheduler_sched_setscheduler) {
  // POSIX: "If pid is zero, the scheduling policy shall be returned for the
  // calling process".
  ASSERT_EQ(sched_getscheduler(getpid()), sched_getscheduler(0));

  const int original_policy = sched_getscheduler(getpid());
  sched_param p = {};
  p.sched_priority = sched_get_priority_min(original_policy);
  ASSERT_ERRNO_FAILURE(EINVAL, -1, sched_setscheduler(getpid(), INT_MAX, &p));

  ASSERT_EQ(0, sched_getparam(getpid(), &p));
  ASSERT_EQ(original_policy, sched_setscheduler(getpid(), SCHED_BATCH, &p));
  // POSIX says this should return the previous policy (here SCHED_BATCH),
  // but the Linux system call doesn't, and the glibc wrapper doesn't correct
  // this (the "returns 0" behavior is even documented on the man page in
  // the BUGS section). This was our historical behavior too, so in the
  // absence of reasons to break compatibility with ourselves and glibc, we
  // don't behave as POSIX specifies. http://b/26203902.
  ASSERT_EQ(0, sched_setscheduler(getpid(), original_policy, &p));
}

TEST(sched, sched_getaffinity_failure) {
  // Trivial test of the errno-preserving/returning behavior.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnonnull"
  ASSERT_ERRNO_FAILURE(EINVAL, -1, sched_getaffinity(getpid(), 0, nullptr));
#pragma clang diagnostic pop
}

TEST(sched, sched_getaffinity) {
  cpu_set_t set;
  CPU_ZERO(&set);
  ASSERT_EQ(0, sched_getaffinity(getpid(), sizeof(set), &set));
  ASSERT_GT(CPU_COUNT(&set), 0);
}

TEST(sched, sched_setaffinity_failure) {
  // Trivial test of the errno-preserving/returning behavior.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnonnull"
  ASSERT_ERRNO_FAILURE(EINVAL, -1, sched_setaffinity(getpid(), 0, nullptr));
#pragma clang diagnostic pop
}

TEST(sched, sched_setaffinity) {
  cpu_set_t set;
  CPU_ZERO(&set);
  ASSERT_EQ(0, sched_getaffinity(getpid(), sizeof(set), &set));
  // It's hard to make any more general claim than this,
  // but it ought to be safe to ask for the same affinity you already have.
  ASSERT_EQ(0, sched_setaffinity(getpid(), sizeof(set), &set));
}

TEST(sched, sched_getattr) {
#if defined(__BIONIC__)
  struct sched_attr sa;
  ASSERT_EQ(0, sched_getattr(getpid(), &sa, sizeof(sa), 0));
#else
  GTEST_SKIP() << "our glibc is too old";
#endif
}

TEST(sched, sched_setattr_failure) {
#if defined(__BIONIC__)
  // Trivial test of the errno-preserving/returning behavior.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnonnull"
  ASSERT_ERRNO_FAILURE(EINVAL, -1, sched_setattr(getpid(), nullptr, 0));
#pragma clang diagnostic pop
#else
  GTEST_SKIP() << "our glibc is too old";
#endif
}
