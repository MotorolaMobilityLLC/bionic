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

#include <errno.h>
#include <limits.h>
#include <locale.h>
#include <stdint.h>
#include <wchar.h>

TEST(wchar, sizeof_wchar_t) {
  EXPECT_EQ(4U, sizeof(wchar_t));
  EXPECT_EQ(4U, sizeof(wint_t));
}

TEST(wchar, mbrlen) {
  char bytes[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
  EXPECT_EQ(0U, mbrlen(&bytes[0], 0, NULL));
  EXPECT_EQ(1U, mbrlen(&bytes[0], 1, NULL));

  EXPECT_EQ(1U, mbrlen(&bytes[4], 1, NULL));
  EXPECT_EQ(0U, mbrlen(&bytes[5], 1, NULL));
}

TEST(wchar, wctomb_wcrtomb) {
  // wctomb and wcrtomb behave differently when s == NULL.
  EXPECT_EQ(0, wctomb(NULL, L'h'));
  EXPECT_EQ(0, wctomb(NULL, L'\0'));
  EXPECT_EQ(1U, wcrtomb(NULL, L'\0', NULL));
  EXPECT_EQ(1U, wcrtomb(NULL, L'h', NULL));

  char bytes[MB_LEN_MAX];

  // wctomb and wcrtomb behave similarly for the null wide character.
  EXPECT_EQ(1, wctomb(bytes, L'\0'));
  EXPECT_EQ(1U, wcrtomb(bytes, L'\0', NULL));

  // ...and for regular characters.
  memset(bytes, 0, sizeof(bytes));
  EXPECT_EQ(1, wctomb(bytes, L'h'));
  EXPECT_EQ('h', bytes[0]);
  memset(bytes, 0, sizeof(bytes));
  EXPECT_EQ(1U, wcrtomb(bytes, L'h', NULL));
  EXPECT_EQ('h', bytes[0]);

  ASSERT_STREQ("C.UTF-8", setlocale(LC_CTYPE, "C.UTF-8"));
  uselocale(LC_GLOBAL_LOCALE);

  // 1-byte UTF-8.
  memset(bytes, 0, sizeof(bytes));
  EXPECT_EQ(1U, wcrtomb(bytes, L'h', NULL));
  EXPECT_EQ('h', bytes[0]);
  // 2-byte UTF-8.
  memset(bytes, 0, sizeof(bytes));
  EXPECT_EQ(2U, wcrtomb(bytes, 0x00a2, NULL));
  EXPECT_EQ('\xc2', bytes[0]);
  EXPECT_EQ('\xa2', bytes[1]);
  // 3-byte UTF-8.
  memset(bytes, 0, sizeof(bytes));
  EXPECT_EQ(3U, wcrtomb(bytes, 0x20ac, NULL));
  EXPECT_EQ('\xe2', bytes[0]);
  EXPECT_EQ('\x82', bytes[1]);
  EXPECT_EQ('\xac', bytes[2]);
  // 4-byte UTF-8.
  memset(bytes, 0, sizeof(bytes));
  EXPECT_EQ(4U, wcrtomb(bytes, 0x24b62, NULL));
  EXPECT_EQ('\xf0', bytes[0]);
  EXPECT_EQ('\xa4', bytes[1]);
  EXPECT_EQ('\xad', bytes[2]);
  EXPECT_EQ('\xa2', bytes[3]);
  // Invalid code point.
  EXPECT_EQ(static_cast<size_t>(-1), wcrtomb(bytes, 0xffffffff, NULL));
  EXPECT_EQ(EILSEQ, errno);
}

TEST(wchar, wcstombs_wcrtombs) {
  const wchar_t chars[] = { L'h', L'e', L'l', L'l', L'o', 0 };
  const wchar_t bad_chars[] = { L'h', L'i', 0xffffffff, 0 };
  const wchar_t* src;
  char bytes[BUFSIZ];

  // Given a NULL destination, these functions count valid characters.
  EXPECT_EQ(5U, wcstombs(NULL, chars, 0));
  EXPECT_EQ(5U, wcstombs(NULL, chars, 4));
  EXPECT_EQ(5U, wcstombs(NULL, chars, 256));
  src = chars;
  EXPECT_EQ(5U, wcsrtombs(NULL, &src, 0, NULL));
  EXPECT_EQ(&chars[0], src);
  src = chars;
  EXPECT_EQ(5U, wcsrtombs(NULL, &src, 4, NULL));
  EXPECT_EQ(&chars[0], src);
  src = chars;
  EXPECT_EQ(5U, wcsrtombs(NULL, &src, 256, NULL));
  EXPECT_EQ(&chars[0], src);

  // An unrepresentable char just returns an error from wcstombs...
  errno = 0;
  EXPECT_EQ(static_cast<size_t>(-1), wcstombs(NULL, bad_chars, 0));
  EXPECT_EQ(EILSEQ, errno);
  errno = 0;
  EXPECT_EQ(static_cast<size_t>(-1), wcstombs(NULL, bad_chars, 256));
  EXPECT_EQ(EILSEQ, errno);

  // And wcsrtombs doesn't tell us where it got stuck because we didn't ask it
  // to actually convert anything...
  errno = 0;
  src = bad_chars;
  EXPECT_EQ(static_cast<size_t>(-1), wcsrtombs(NULL, &src, 0, NULL));
  EXPECT_EQ(&bad_chars[0], src);
  EXPECT_EQ(EILSEQ, errno);
  errno = 0;
  src = bad_chars;
  EXPECT_EQ(static_cast<size_t>(-1), wcsrtombs(NULL, &src, 256, NULL));
  EXPECT_EQ(&bad_chars[0], src);
  EXPECT_EQ(EILSEQ, errno);

  // Okay, now let's test actually converting something...
  memset(bytes, 'x', sizeof(bytes));
  EXPECT_EQ(0U, wcstombs(bytes, chars, 0));
  memset(bytes, 'x', sizeof(bytes));
  EXPECT_EQ(4U, wcstombs(bytes, chars, 4));
  bytes[5] = 0;
  EXPECT_STREQ("hellx", bytes);
  memset(bytes, 'x', sizeof(bytes));
  EXPECT_EQ(5U, wcstombs(bytes, chars, 256));
  EXPECT_STREQ("hello", bytes);
  memset(bytes, 'x', sizeof(bytes));
  EXPECT_EQ(5U, wcstombs(bytes, chars, 6));
  EXPECT_STREQ("hello", bytes);
  errno = 0;
  memset(bytes, 'x', sizeof(bytes));
  EXPECT_EQ(static_cast<size_t>(-1), wcstombs(bytes, bad_chars, 256));
  EXPECT_EQ(EILSEQ, errno);
  bytes[3] = 0;
  EXPECT_STREQ("hix", bytes);

  // wcsrtombs is a bit more informative...
  memset(bytes, 'x', sizeof(bytes));
  src = chars;
  EXPECT_EQ(0U, wcsrtombs(bytes, &src, 0, NULL));
  EXPECT_EQ(&chars[0], src); // No input consumed.
  EXPECT_EQ(EILSEQ, errno);

  memset(bytes, 'x', sizeof(bytes));
  src = chars;
  EXPECT_EQ(4U, wcsrtombs(bytes, &src, 4, NULL));
  EXPECT_EQ(&chars[4], src); // Some input consumed.
  EXPECT_EQ(EILSEQ, errno);
  bytes[5] = 0;
  EXPECT_STREQ("hellx", bytes);

  memset(bytes, 'x', sizeof(bytes));
  src = chars;
  EXPECT_EQ(5U, wcsrtombs(bytes, &src, 256, NULL));
  EXPECT_EQ(NULL, src); // All input consumed!
  EXPECT_EQ(EILSEQ, errno);
  EXPECT_STREQ("hello", bytes);

  memset(bytes, 'x', sizeof(bytes));
  src = chars;
  EXPECT_EQ(5U, wcsrtombs(bytes, &src, 6, NULL));
  EXPECT_EQ(NULL, src); // All input consumed.
  EXPECT_EQ(EILSEQ, errno);
  EXPECT_STREQ("hello", bytes);

  memset(bytes, 'x', sizeof(bytes));
  src = bad_chars;
  EXPECT_EQ(static_cast<size_t>(-1), wcsrtombs(bytes, &src, 256, NULL));
  EXPECT_EQ(&bad_chars[2], src);
  EXPECT_EQ(EILSEQ, errno);
  bytes[3] = 0;
  EXPECT_STREQ("hix", bytes);
}

TEST(wchar, limits) {
  ASSERT_LT(WCHAR_MIN, WCHAR_MAX);
}

TEST(wchar, wcsstr_wcswcs) {
  const wchar_t* haystack = L"matches hello world, not the second hello world";
  const wchar_t* empty_needle = L"";
  const wchar_t* good_needle = L"ll";
  const wchar_t* bad_needle = L"wort";

  ASSERT_EQ(haystack, wcsstr(haystack, empty_needle));
  ASSERT_EQ(&haystack[10], wcsstr(haystack, good_needle));
  ASSERT_EQ(NULL, wcsstr(haystack, bad_needle));

  ASSERT_EQ(haystack, wcswcs(haystack, empty_needle));
  ASSERT_EQ(&haystack[10], wcswcs(haystack, good_needle));
  ASSERT_EQ(NULL, wcswcs(haystack, bad_needle));
}

TEST(wchar, mbtowc) {
  wchar_t out[8];

  out[0] = 'x';
  ASSERT_EQ(0, mbtowc(out, "hello", 0));
  ASSERT_EQ('x', out[0]);

  ASSERT_EQ(0, mbtowc(out, "hello", 0));
  ASSERT_EQ(0, mbtowc(out, "", 0));
  ASSERT_EQ(1, mbtowc(out, "hello", 1));
  ASSERT_EQ(L'h', out[0]);

  ASSERT_EQ(0, mbtowc(NULL, "hello", 0));
  ASSERT_EQ(0, mbtowc(NULL, "", 0));
  ASSERT_EQ(1, mbtowc(NULL, "hello", 1));

  ASSERT_EQ(0, mbtowc(NULL, NULL, 0));
}

TEST(wchar, mbrtowc) {
  wchar_t out[8];

  out[0] = 'x';
  ASSERT_EQ(0U, mbrtowc(out, "hello", 0, NULL));
  ASSERT_EQ('x', out[0]);

  ASSERT_EQ(0U, mbrtowc(out, "hello", 0, NULL));
  ASSERT_EQ(0U, mbrtowc(out, "", 0, NULL));
  ASSERT_EQ(1U, mbrtowc(out, "hello", 1, NULL));
  ASSERT_EQ(L'h', out[0]);

  ASSERT_EQ(0U, mbrtowc(NULL, "hello", 0, NULL));
  ASSERT_EQ(0U, mbrtowc(NULL, "", 0, NULL));
  ASSERT_EQ(1U, mbrtowc(NULL, "hello", 1, NULL));

  ASSERT_EQ(0U, mbrtowc(NULL, NULL, 0, NULL));

  ASSERT_STREQ("C.UTF-8", setlocale(LC_CTYPE, "C.UTF-8"));
  uselocale(LC_GLOBAL_LOCALE);

  // 1-byte UTF-8.
  ASSERT_EQ(1U, mbrtowc(out, "abcdef", 6, NULL));
  ASSERT_EQ(L'a', out[0]);
  // 2-byte UTF-8.
  ASSERT_EQ(2U, mbrtowc(out, "\xc2\xa2" "cdef", 6, NULL));
  ASSERT_EQ(0x00a2, out[0]);
  // 3-byte UTF-8.
  ASSERT_EQ(3U, mbrtowc(out, "\xe2\x82\xac" "def", 6, NULL));
  ASSERT_EQ(0x20ac, out[0]);
  // 4-byte UTF-8.
  ASSERT_EQ(4U, mbrtowc(out, "\xf0\xa4\xad\xa2" "ef", 6, NULL));
  ASSERT_EQ(0x24b62, out[0]);
#if __BIONIC__ // glibc allows this.
  // Illegal 5-byte UTF-8.
  ASSERT_EQ(static_cast<size_t>(-1), mbrtowc(out, "\xf8\xa1\xa2\xa3\xa4" "f", 6, NULL));
  ASSERT_EQ(EILSEQ, errno);
#endif
  // Illegal over-long sequence.
  ASSERT_EQ(static_cast<size_t>(-1), mbrtowc(out, "\xf0\x82\x82\xac" "ef", 6, NULL));
  ASSERT_EQ(EILSEQ, errno);
}

TEST(wchar, wcstod) {
  ASSERT_DOUBLE_EQ(1.23, wcstod(L"1.23", NULL));
}

TEST(wchar, wcstof) {
  ASSERT_FLOAT_EQ(1.23f, wcstof(L"1.23", NULL));
}

TEST(wchar, wcstol) {
  ASSERT_EQ(123L, wcstol(L"123", NULL, 0));
}

TEST(wchar, wcstoll) {
  ASSERT_EQ(123LL, wcstol(L"123", NULL, 0));
}

TEST(wchar, wcstold) {
  ASSERT_DOUBLE_EQ(1.23L, wcstold(L"1.23", NULL));
}

TEST(wchar, wcstoul) {
  ASSERT_EQ(123UL, wcstoul(L"123", NULL, 0));
}

TEST(wchar, wcstoull) {
  ASSERT_EQ(123ULL, wcstoul(L"123", NULL, 0));
}

TEST(wchar, mbsnrtowcs) {
  wchar_t dst[128];
  const char* s = "hello, world!";
  const char* src;

  memset(dst, 0, sizeof(dst));
  src = s;
  ASSERT_EQ(0U, mbsnrtowcs(dst, &src, 0, 0, NULL));

  memset(dst, 0, sizeof(dst));
  src = s;
  ASSERT_EQ(2U, mbsnrtowcs(dst, &src, 2, 123, NULL)); // glibc chokes on SIZE_MAX here.
  ASSERT_EQ(L'h', dst[0]);
  ASSERT_EQ(L'e', dst[1]);
  ASSERT_EQ(&s[2], src);

  memset(dst, 0, sizeof(dst));
  src = s;
  ASSERT_EQ(3U, mbsnrtowcs(dst, &src, SIZE_MAX, 3, NULL));
  ASSERT_EQ(L'h', dst[0]);
  ASSERT_EQ(L'e', dst[1]);
  ASSERT_EQ(L'l', dst[2]);
  ASSERT_EQ(&s[3], src);
}
