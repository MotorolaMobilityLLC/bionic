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

#include <stdint.h>

#include <gtest/gtest.h>

#include <limits>

#if !defined(__WINT_UNSIGNED__)
#error wint_t is unsigned on Android
#endif

TEST(stdint, wint_sign) {
  EXPECT_FALSE(std::numeric_limits<wint_t>::is_signed);
}

TEST(stdint, fast_type_sizes) {
  EXPECT_EQ(1U, sizeof(int_fast8_t));
  EXPECT_EQ(8U, sizeof(int_fast64_t));
  EXPECT_EQ(1U, sizeof(uint_fast8_t));
  EXPECT_EQ(8U, sizeof(uint_fast64_t));
#if defined(__LP64__)
  EXPECT_EQ(8U, sizeof(int_fast16_t));
  EXPECT_EQ(8U, sizeof(int_fast32_t));
  EXPECT_EQ(8U, sizeof(uint_fast16_t));
  EXPECT_EQ(8U, sizeof(uint_fast32_t));
#else
  EXPECT_EQ(4U, sizeof(int_fast16_t));
  EXPECT_EQ(4U, sizeof(int_fast32_t));
  EXPECT_EQ(4U, sizeof(uint_fast16_t));
  EXPECT_EQ(4U, sizeof(uint_fast32_t));
#endif
}

TEST(stdint, least_type_sizes) {
  EXPECT_EQ(1U, sizeof(int_least8_t));
  EXPECT_EQ(1U, sizeof(uint_least8_t));
  EXPECT_EQ(2U, sizeof(int_least16_t));
  EXPECT_EQ(2U, sizeof(uint_least16_t));
  EXPECT_EQ(4U, sizeof(int_least32_t));
  EXPECT_EQ(4U, sizeof(uint_least32_t));
  EXPECT_EQ(8U, sizeof(int_least64_t));
  EXPECT_EQ(8U, sizeof(uint_least64_t));
}
