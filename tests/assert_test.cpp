/*
 * Copyright (C) 2016 The Android Open Source Project
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
#include "gtest/gtest.h"

#undef NDEBUG
#include <assert.h>

#include <android-base/silent_death_test.h>

using assert_DeathTest = SilentDeathTest;

TEST(assert, assert_true) {
  assert(true);
}

TEST_F(assert_DeathTest, assert_false) {
  EXPECT_EXIT(assert(false),
              testing::KilledBySignal(SIGABRT),
              "bionic/tests/assert_test.cpp:.*: "
              "virtual void assert_DeathTest_assert_false_Test::TestBody\\(\\): "
              "assertion \"false\" failed");
}

TEST(assert, n2829) {
#if defined(__BIONIC__)
  // https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2829.htm
  assert((int[2]){1,2}[0]);
  struct A {int x,y;};
  assert((struct A){1,2}.x);
#else
  GTEST_SKIP() << "our glibc is too old";
#endif
}

// Re-include <assert.h> with assertions disabled.
#define NDEBUG
#include <assert.h>

TEST(assert, assert_true_NDEBUG) {
  assert(true);
}

TEST(assert, assert_false_NDEBUG) {
  assert(false);
}

TEST(assert, n2829_NDEBUG) {
#if defined(__BIONIC__)
  // https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2829.htm
  assert((int[2]){1,2}[0]);
  struct A {int x,y;};
  assert((struct A){1,2}.x);
#else
  GTEST_SKIP() << "our glibc is too old";
#endif
}
