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

#include <inttypes.h>

#include <errno.h>
#include <gtest/gtest.h>
#include <stdio.h>

TEST(inttypes, misc) {
  char buf[512];

  intptr_t i = 0;
  uintptr_t u = 0;

  snprintf(buf, sizeof(buf), "%08" PRIdPTR, i);
  snprintf(buf, sizeof(buf), "%08" PRIiPTR, i);
  snprintf(buf, sizeof(buf), "%08" PRIoPTR, i);
  snprintf(buf, sizeof(buf), "%08" PRIuPTR, u);
  snprintf(buf, sizeof(buf), "%08" PRIxPTR, u);
  snprintf(buf, sizeof(buf), "%08" PRIXPTR, u);

  sscanf(buf, "%08" SCNdPTR, &i);
  sscanf(buf, "%08" SCNiPTR, &i);
  sscanf(buf, "%08" SCNoPTR, &u);
  sscanf(buf, "%08" SCNuPTR, &u);
  sscanf(buf, "%08" SCNxPTR, &u);
}

TEST(inttypes, wcstoimax) {
  ASSERT_EQ(123, wcstoimax(L"123", NULL, 10));
}

TEST(inttypes, wcstoumax) {
  ASSERT_EQ(123U, wcstoumax(L"123", NULL, 10));
}

TEST(inttypes, strtoimax_EINVAL) {
  errno = 0;
  strtoimax("123", NULL, -1);
  ASSERT_EQ(EINVAL, errno);
  errno = 0;
  strtoimax("123", NULL, 1);
  ASSERT_EQ(EINVAL, errno);
  errno = 0;
  strtoimax("123", NULL, 37);
  ASSERT_EQ(EINVAL, errno);
}

TEST(inttypes, strtoumax_EINVAL) {
  errno = 0;
  strtoumax("123", NULL, -1);
  ASSERT_EQ(EINVAL, errno);
  errno = 0;
  strtoumax("123", NULL, 1);
  ASSERT_EQ(EINVAL, errno);
  errno = 0;
  strtoumax("123", NULL, 37);
  ASSERT_EQ(EINVAL, errno);
}

TEST(inttypes, wcstoimax_EINVAL) {
  errno = 0;
  wcstoimax(L"123", NULL, -1);
  ASSERT_EQ(EINVAL, errno);
  errno = 0;
  wcstoimax(L"123", NULL, 1);
  ASSERT_EQ(EINVAL, errno);
  errno = 0;
  wcstoimax(L"123", NULL, 37);
  ASSERT_EQ(EINVAL, errno);
}

TEST(inttypes, wcstoumax_EINVAL) {
  errno = 0;
  wcstoumax(L"123", NULL, -1);
  ASSERT_EQ(EINVAL, errno);
  errno = 0;
  wcstoumax(L"123", NULL, 1);
  ASSERT_EQ(EINVAL, errno);
  errno = 0;
  wcstoumax(L"123", NULL, 37);
  ASSERT_EQ(EINVAL, errno);
}
