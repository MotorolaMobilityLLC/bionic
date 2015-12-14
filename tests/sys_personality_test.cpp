/*
 * Copyright (C) 2015 The Android Open Source Project
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

#include <sys/personality.h>

TEST(sys_personality, current_persona) {
  int persona = personality(0xffffffff) & PER_MASK;
#if defined(__BIONIC__)
// When personality syscall is executed on mips64, for a 32bit process
// sys_32_personality() is called, which converts PER_LINUX32 -> PER_LINUX
#if defined(__LP64__) || (__mips==32 && __mips_isa_rev>2)
  ASSERT_EQ(PER_LINUX, persona);
#else
  ASSERT_EQ(PER_LINUX32, persona);
#endif
#else
  // GLIBC does not set persona prior process startup - it is always PER_LINUX;
  ASSERT_EQ(PER_LINUX, persona);
#endif
}
