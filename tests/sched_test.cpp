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
#include <sys/types.h>
#include <sys/wait.h>

#ifdef __BIONIC__
static int child_fn(void* i_ptr) {
  *reinterpret_cast<int*>(i_ptr) = 42;
  return 123;
}

TEST(sched, clone) {
  void* child_stack[1024];

  int i = 0;
  pid_t tid = clone(child_fn, &child_stack[1024], CLONE_VM, &i);

  int status;
  ASSERT_EQ(tid, TEMP_FAILURE_RETRY(waitpid(tid, &status, __WCLONE)));

  ASSERT_EQ(42, i);

  ASSERT_TRUE(WIFEXITED(status));
  ASSERT_EQ(123, WEXITSTATUS(status));
}
#else
// For glibc, any call to clone with CLONE_VM set will cause later pthread
// calls in the same process to misbehave.
// See https://sourceware.org/bugzilla/show_bug.cgi?id=10311 for more details.
TEST(sched, clone) {
  // In order to enumerate all possible tests for CTS, create an empty test.
  GTEST_LOG_(INFO) << "This test does nothing.\n";
}
#endif

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
