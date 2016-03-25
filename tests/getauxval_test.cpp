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

#include <errno.h>
#include <sys/cdefs.h>
#include <gtest/gtest.h>

// getauxval() was only added as of glibc version 2.16.
// See: http://lwn.net/Articles/519085/
// Don't try to compile this code on older glibc versions.

#if defined(__BIONIC__)
  #define GETAUXVAL_CAN_COMPILE 1
#elif defined(__GLIBC_PREREQ)
  #if __GLIBC_PREREQ(2, 16)
    #define GETAUXVAL_CAN_COMPILE 1
  #endif
#endif

#if defined(GETAUXVAL_CAN_COMPILE)
#include <sys/auxv.h>
#endif

TEST(getauxval, expected_values) {
#if defined(GETAUXVAL_CAN_COMPILE)
  ASSERT_EQ(0UL, getauxval(AT_SECURE));
  ASSERT_EQ(getuid(), getauxval(AT_UID));
  ASSERT_EQ(geteuid(), getauxval(AT_EUID));
  ASSERT_EQ(getgid(), getauxval(AT_GID));
  ASSERT_EQ(getegid(), getauxval(AT_EGID));
  ASSERT_EQ(static_cast<unsigned long>(getpagesize()), getauxval(AT_PAGESZ));

  ASSERT_NE(0UL, getauxval(AT_PHDR));
  ASSERT_NE(0UL, getauxval(AT_PHNUM));
  ASSERT_NE(0UL, getauxval(AT_ENTRY));
  ASSERT_NE(0UL, getauxval(AT_PAGESZ));
#else
  GTEST_LOG_(INFO) << "This test requires a C library with getauxval.\n";
#endif
}

TEST(getauxval, unexpected_values) {
#if defined(GETAUXVAL_CAN_COMPILE)
  errno = 0;
  ASSERT_EQ(0UL, getauxval(0xdeadbeef));
  ASSERT_EQ(ENOENT, errno);
#else
  GTEST_LOG_(INFO) << "This test requires a C library with getauxval.\n";
#endif
}

TEST(getauxval, arm_has_AT_HWCAP2) {
#if defined(__arm__)
  // If this test fails, apps that use getauxval to decide at runtime whether crypto hardware is
  // available will incorrectly assume that it isn't, and will have really bad performance.
  // If this test fails, ensure that you've enabled COMPAT_BINFMT_ELF in your kernel configuration.
  // Note that 0 ("I don't support any of these things") is a legitimate response --- we need
  // to check errno to see whether we got a "true" 0 or a "not found" 0.
  errno = 0;
  getauxval(AT_HWCAP2);
  ASSERT_EQ(0, errno) << "kernel not reporting AT_HWCAP2 to 32-bit ARM process";
#else
  GTEST_LOG_(INFO) << "This test is only meaningful for 32-bit ARM code.\n";
#endif
}
