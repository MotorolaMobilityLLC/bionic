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

#undef _FORTIFY_SOURCE
#define _FORTIFY_SOURCE 1

#include <gtest/gtest.h>
#include <string.h>

#if __BIONIC__
// We have to say "DeathTest" here so gtest knows to run this test (which exits)
// in its own process.

// multibyte target where we over fill (should fail)
TEST(Fortify1_Clang_DeathTest, strcpy_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[10];
  char *orig = strdup("0123456789");
  ASSERT_EXIT(strcpy(buf, orig), testing::KilledBySignal(SIGABRT), "");
  free(orig);
}

// zero sized target with "\0" source (should fail)
TEST(Fortify1_Clang_DeathTest, strcpy2_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[0];
  char *orig = strdup("");
  ASSERT_EXIT(strcpy(buf, orig), testing::KilledBySignal(SIGABRT), "");
  free(orig);
}

// zero sized target with longer source (should fail)
TEST(Fortify1_Clang_DeathTest, strcpy3_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[0];
  char *orig = strdup("1");
  ASSERT_EXIT(strcpy(buf, orig), testing::KilledBySignal(SIGABRT), "");
  free(orig);
}

// one byte target with longer source (should fail)
TEST(Fortify1_Clang_DeathTest, strcpy4_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[1];
  char *orig = strdup("12");
  ASSERT_EXIT(strcpy(buf, orig), testing::KilledBySignal(SIGABRT), "");
  free(orig);
}

TEST(Fortify1_Clang_DeathTest, strlen_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[10];
  memcpy(buf, "0123456789", sizeof(buf));
  ASSERT_EXIT(printf("%d", strlen(buf)), testing::KilledBySignal(SIGABRT), "");
}

TEST(Fortify1_Clang_DeathTest, strchr_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[10];
  memcpy(buf, "0123456789", sizeof(buf));
  ASSERT_EXIT(printf("%s", strchr(buf, 'a')), testing::KilledBySignal(SIGABRT), "");
}

TEST(Fortify1_Clang_DeathTest, strrchr_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[10];
  memcpy(buf, "0123456789", sizeof(buf));
  ASSERT_EXIT(printf("%s", strrchr(buf, 'a')), testing::KilledBySignal(SIGABRT), "");
}
#endif

TEST(Fortify1_Clang_DeathTest, strncat_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[10];
  size_t n = atoi("10"); // avoid compiler optimizations
  strncpy(buf, "012345678", n);
  ASSERT_EXIT(strncat(buf, "9", n), testing::KilledBySignal(SIGABRT), "");
}

TEST(Fortify1_Clang_DeathTest, strncat2_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[10];
  buf[0] = '\0';
  size_t n = atoi("10"); // avoid compiler optimizations
  ASSERT_EXIT(strncat(buf, "0123456789", n), testing::KilledBySignal(SIGABRT), "");
}

TEST(Fortify1_Clang_DeathTest, strcat_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char src[11];
  strcpy(src, "0123456789");
  char buf[10];
  buf[0] = '\0';
  ASSERT_EXIT(strcat(buf, src), testing::KilledBySignal(SIGABRT), "");
}

TEST(Fortify1_Clang_DeathTest, memmove_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char buf[20];
  strcpy(buf, "0123456789");
  size_t n = atoi("10");
  ASSERT_EXIT(memmove(buf + 11, buf, n), testing::KilledBySignal(SIGABRT), "");
}

TEST(Fortify1_Clang_DeathTest, memcpy_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char bufa[10];
  char bufb[10];
  strcpy(bufa, "012345678");
  size_t n = atoi("11");
  ASSERT_EXIT(memcpy(bufb, bufa, n), testing::KilledBySignal(SIGABRT), "");
}

TEST(Fortify1_Clang_DeathTest, strncpy_fortified) {
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  char bufa[15];
  char bufb[10];
  strcpy(bufa, "01234567890123");
  size_t n = strlen(bufa);
  ASSERT_EXIT(strncpy(bufb, bufa, n), testing::KilledBySignal(SIGABRT), "");
}

extern "C" char* __strncat_chk(char*, const char*, size_t, size_t);
extern "C" char* __strcat_chk(char*, const char*, size_t);

TEST(Fortify1_Clang, strncat) {
  char buf[10];
  memset(buf, 'A', sizeof(buf));
  buf[0] = 'a';
  buf[1] = '\0';
  char* res = __strncat_chk(buf, "01234", sizeof(buf) - strlen(buf) - 1, sizeof(buf));
  ASSERT_EQ(buf, res);
  ASSERT_EQ('a',  buf[0]);
  ASSERT_EQ('0',  buf[1]);
  ASSERT_EQ('1',  buf[2]);
  ASSERT_EQ('2',  buf[3]);
  ASSERT_EQ('3',  buf[4]);
  ASSERT_EQ('4',  buf[5]);
  ASSERT_EQ('\0', buf[6]);
  ASSERT_EQ('A',  buf[7]);
  ASSERT_EQ('A',  buf[8]);
  ASSERT_EQ('A',  buf[9]);
}

TEST(Fortify1_Clang, strncat2) {
  char buf[10];
  memset(buf, 'A', sizeof(buf));
  buf[0] = 'a';
  buf[1] = '\0';
  char* res = __strncat_chk(buf, "0123456789", 5, sizeof(buf));
  ASSERT_EQ(buf, res);
  ASSERT_EQ('a',  buf[0]);
  ASSERT_EQ('0',  buf[1]);
  ASSERT_EQ('1',  buf[2]);
  ASSERT_EQ('2',  buf[3]);
  ASSERT_EQ('3',  buf[4]);
  ASSERT_EQ('4',  buf[5]);
  ASSERT_EQ('\0', buf[6]);
  ASSERT_EQ('A',  buf[7]);
  ASSERT_EQ('A',  buf[8]);
  ASSERT_EQ('A',  buf[9]);
}

TEST(Fortify1_Clang, strncat3) {
  char buf[10];
  memset(buf, 'A', sizeof(buf));
  buf[0] = '\0';
  char* res = __strncat_chk(buf, "0123456789", 5, sizeof(buf));
  ASSERT_EQ(buf, res);
  ASSERT_EQ('0',  buf[0]);
  ASSERT_EQ('1',  buf[1]);
  ASSERT_EQ('2',  buf[2]);
  ASSERT_EQ('3',  buf[3]);
  ASSERT_EQ('4',  buf[4]);
  ASSERT_EQ('\0', buf[5]);
  ASSERT_EQ('A',  buf[6]);
  ASSERT_EQ('A',  buf[7]);
  ASSERT_EQ('A',  buf[8]);
  ASSERT_EQ('A',  buf[9]);
}

TEST(Fortify1_Clang, strncat4) {
  char buf[10];
  memset(buf, 'A', sizeof(buf));
  buf[9] = '\0';
  char* res = __strncat_chk(buf, "", 5, sizeof(buf));
  ASSERT_EQ(buf, res);
  ASSERT_EQ('A',  buf[0]);
  ASSERT_EQ('A',  buf[1]);
  ASSERT_EQ('A',  buf[2]);
  ASSERT_EQ('A',  buf[3]);
  ASSERT_EQ('A',  buf[4]);
  ASSERT_EQ('A',  buf[5]);
  ASSERT_EQ('A',  buf[6]);
  ASSERT_EQ('A',  buf[7]);
  ASSERT_EQ('A',  buf[8]);
  ASSERT_EQ('\0', buf[9]);
}

TEST(Fortify1_Clang, strncat5) {
  char buf[10];
  memset(buf, 'A', sizeof(buf));
  buf[0] = 'a';
  buf[1] = '\0';
  char* res = __strncat_chk(buf, "01234567", 8, sizeof(buf));
  ASSERT_EQ(buf, res);
  ASSERT_EQ('a',  buf[0]);
  ASSERT_EQ('0',  buf[1]);
  ASSERT_EQ('1',  buf[2]);
  ASSERT_EQ('2',  buf[3]);
  ASSERT_EQ('3',  buf[4]);
  ASSERT_EQ('4',  buf[5]);
  ASSERT_EQ('5', buf[6]);
  ASSERT_EQ('6',  buf[7]);
  ASSERT_EQ('7',  buf[8]);
  ASSERT_EQ('\0',  buf[9]);
}

TEST(Fortify1_Clang, strncat6) {
  char buf[10];
  memset(buf, 'A', sizeof(buf));
  buf[0] = 'a';
  buf[1] = '\0';
  char* res = __strncat_chk(buf, "01234567", 9, sizeof(buf));
  ASSERT_EQ(buf, res);
  ASSERT_EQ('a',  buf[0]);
  ASSERT_EQ('0',  buf[1]);
  ASSERT_EQ('1',  buf[2]);
  ASSERT_EQ('2',  buf[3]);
  ASSERT_EQ('3',  buf[4]);
  ASSERT_EQ('4',  buf[5]);
  ASSERT_EQ('5', buf[6]);
  ASSERT_EQ('6',  buf[7]);
  ASSERT_EQ('7',  buf[8]);
  ASSERT_EQ('\0',  buf[9]);
}


TEST(Fortify1_Clang, strcat) {
  char buf[10];
  memset(buf, 'A', sizeof(buf));
  buf[0] = 'a';
  buf[1] = '\0';
  char* res = __strcat_chk(buf, "01234", sizeof(buf));
  ASSERT_EQ(buf, res);
  ASSERT_EQ('a',  buf[0]);
  ASSERT_EQ('0',  buf[1]);
  ASSERT_EQ('1',  buf[2]);
  ASSERT_EQ('2',  buf[3]);
  ASSERT_EQ('3',  buf[4]);
  ASSERT_EQ('4',  buf[5]);
  ASSERT_EQ('\0', buf[6]);
  ASSERT_EQ('A',  buf[7]);
  ASSERT_EQ('A',  buf[8]);
  ASSERT_EQ('A',  buf[9]);
}

TEST(Fortify1_Clang, strcat2) {
  char buf[10];
  memset(buf, 'A', sizeof(buf));
  buf[0] = 'a';
  buf[1] = '\0';
  char* res = __strcat_chk(buf, "01234567", sizeof(buf));
  ASSERT_EQ(buf, res);
  ASSERT_EQ('a',  buf[0]);
  ASSERT_EQ('0',  buf[1]);
  ASSERT_EQ('1',  buf[2]);
  ASSERT_EQ('2',  buf[3]);
  ASSERT_EQ('3',  buf[4]);
  ASSERT_EQ('4',  buf[5]);
  ASSERT_EQ('5', buf[6]);
  ASSERT_EQ('6',  buf[7]);
  ASSERT_EQ('7',  buf[8]);
  ASSERT_EQ('\0',  buf[9]);
}

__BIONIC_FORTIFY_INLINE
size_t test_fortify_inline(char* buf) {
    return __bos(buf);
}

TEST(Fortify1_Clang, fortify_inline) {
  char buf[1024];
  ASSERT_EQ(test_fortify_inline(buf), sizeof(buf));
}
