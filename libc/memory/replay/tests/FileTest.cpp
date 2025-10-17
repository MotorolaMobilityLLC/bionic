/*
 * Copyright (C) 2019 The Android Open Source Project
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

#include <malloc.h>
#include <stdint.h>

#include <string>

#include <android-base/file.h>
#include <gtest/gtest.h>

#include <memory_trace/MemoryTrace.h>

#include "File.h"

static std::string GetTestDirectory() {
  return android::base::GetExecutableDirectory() + "/tests";
}

static std::string GetTestZip() {
  return GetTestDirectory() + "/test.zip";
}

TEST(FileTest, zip_get_contents) {
  EXPECT_EQ("12345: malloc 0x1000 16\n12345: free 0x1000\n", ZipGetContents(GetTestZip().c_str()));
}

TEST(FileTest, zip_get_contents_bad_file) {
  EXPECT_EQ("", ZipGetContents("/does/not/exist.zip"));
}

TEST(FileTest, get_unwind_info_from_zip_file) {
  // This will allocate, so do it before getting mallinfo.
  std::string file_name = GetTestZip();

  size_t mallinfo_before = mallinfo().uordblks;
  memory_trace::Entry* entries;
  size_t num_entries;
  GetUnwindInfo(file_name.c_str(), &entries, &num_entries);
  size_t mallinfo_after = mallinfo().uordblks;

  // Verify no memory is allocated.
  EXPECT_EQ(mallinfo_after, mallinfo_before);

  ASSERT_EQ(2U, num_entries);
  EXPECT_EQ(12345, entries[0].tid);
  EXPECT_EQ(memory_trace::MALLOC, entries[0].type);
  EXPECT_EQ(0x1000U, entries[0].ptr);
  EXPECT_EQ(16U, entries[0].size);
  EXPECT_EQ(0U, entries[0].u.old_ptr);

  EXPECT_EQ(12345, entries[1].tid);
  EXPECT_EQ(memory_trace::FREE, entries[1].type);
  EXPECT_EQ(0x1000U, entries[1].ptr);
  EXPECT_EQ(0U, entries[1].size);
  EXPECT_EQ(0U, entries[1].u.old_ptr);

  FreeEntries(entries, num_entries);
}

TEST(FileTest, get_unwind_info_bad_zip_file) {
  memory_trace::Entry* entries;
  size_t num_entries;
  EXPECT_DEATH(GetUnwindInfo("/does/not/exist.zip", &entries, &num_entries), "");
}

TEST(FileTest, get_unwind_info_from_text_file) {
  // This will allocate, so do it before getting mallinfo.
  std::string file_name = GetTestDirectory() + "/test.txt";

  size_t mallinfo_before = mallinfo().uordblks;
  memory_trace::Entry* entries;
  size_t num_entries;
  GetUnwindInfo(file_name.c_str(), &entries, &num_entries);
  size_t mallinfo_after = mallinfo().uordblks;

  // Verify no memory is allocated.
  EXPECT_EQ(mallinfo_after, mallinfo_before);

  ASSERT_EQ(2U, num_entries);
  EXPECT_EQ(98765, entries[0].tid);
  EXPECT_EQ(memory_trace::MEMALIGN, entries[0].type);
  EXPECT_EQ(0xa000U, entries[0].ptr);
  EXPECT_EQ(124U, entries[0].size);
  EXPECT_EQ(16U, entries[0].u.align);

  EXPECT_EQ(98765, entries[1].tid);
  EXPECT_EQ(memory_trace::FREE, entries[1].type);
  EXPECT_EQ(0xa000U, entries[1].ptr);
  EXPECT_EQ(0U, entries[1].size);
  EXPECT_EQ(0U, entries[1].u.old_ptr);

  FreeEntries(entries, num_entries);
}

TEST(FileTest, get_unwind_info_bad_file) {
  memory_trace::Entry* entries;
  size_t num_entries;
  EXPECT_DEATH(GetUnwindInfo("/does/not/exist", &entries, &num_entries), "");
}

TEST(FileTest, present_bytes_updated) {
  TemporaryFile tf;
  ASSERT_NE(-1, tf.fd);
  // Entry 0
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::MALLOC, .ptr = 0x100, .size = 100}));
  // Entry 1
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::MALLOC, .ptr = 0x200, .size = 10}));
  // Entry 2
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{
                 .type = memory_trace::MEMALIGN, .ptr = 0x300, .size = 300, .u.align = 16}));
  // Entry 3
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{
                 .type = memory_trace::CALLOC, .ptr = 0x400, .size = 400, .u.n_elements = 100}));
  // Entry 4
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::FREE, .ptr = 0x400, .present_bytes = 400}));
  // Entry 5
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::FREE, .ptr = 0x100, .present_bytes = 100}));
  // Entry 6
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::MALLOC, .ptr = 0x100, .size = 101}));
  // Entry 7
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::FREE, .ptr = 0x300, .present_bytes = 300}));
  // Entry 8
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::FREE, .ptr = 0x100, .present_bytes = 101}));
  // Entry 9
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::MALLOC, .ptr = 0x700, .size = 1000}));
  // Enrty 10
  ASSERT_TRUE(memory_trace::WriteEntryToFd(tf.fd, memory_trace::Entry{.type = memory_trace::REALLOC,
                                                                      .ptr = 0x800,
                                                                      .size = 800,
                                                                      .u.old_ptr = 0x700,
                                                                      .present_bytes = 700}));
  // Entry 11
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::FREE, .ptr = 0x800, .present_bytes = 800}));
  close(tf.fd);
  tf.fd = -1;

  memory_trace::Entry* entries;
  size_t num_entries;
  GetUnwindInfo(tf.path, &entries, &num_entries);
  EXPECT_EQ(12U, num_entries);

  // Only verify the present bytes values.
  EXPECT_EQ(100, entries[0].present_bytes);
  // No free for this allocation.
  EXPECT_EQ(-1, entries[1].present_bytes);
  EXPECT_EQ(300, entries[2].present_bytes);
  EXPECT_EQ(400, entries[3].present_bytes);
  EXPECT_EQ(400, entries[4].present_bytes);
  EXPECT_EQ(100, entries[5].present_bytes);
  EXPECT_EQ(101, entries[6].present_bytes);
  EXPECT_EQ(300, entries[7].present_bytes);
  EXPECT_EQ(101, entries[8].present_bytes);
  EXPECT_EQ(700, entries[9].present_bytes);
  EXPECT_EQ(800, entries[10].present_bytes);
  EXPECT_EQ(800, entries[11].present_bytes);

  FreeEntries(entries, num_entries);
}

TEST(FileTest, present_bytes_reset_realloc) {
  TemporaryFile tf;
  ASSERT_NE(-1, tf.fd);
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::MALLOC, .ptr = 0x100, .size = 200}));
  ASSERT_TRUE(memory_trace::WriteEntryToFd(tf.fd, memory_trace::Entry{.type = memory_trace::REALLOC,
                                                                      .ptr = 0x200,
                                                                      .size = 400,
                                                                      .u.old_ptr = 0x100,
                                                                      .present_bytes = 200}));

  memory_trace::Entry* entries;
  size_t num_entries;
  GetUnwindInfo(tf.path, &entries, &num_entries);
  EXPECT_EQ(2U, num_entries);

  // Verify that the present bytes is -1 for the actual realloc since it was
  // never freed.
  EXPECT_EQ(200, entries[0].present_bytes);
  EXPECT_EQ(-1, entries[1].present_bytes);

  FreeEntries(entries, num_entries);
}

TEST(FileTest, present_bytes_adjusted) {
  TemporaryFile tf;
  ASSERT_NE(-1, tf.fd);
  // Entry 0
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::MALLOC, .ptr = 0x100, .size = 10}));
  // Entry 1
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::FREE, .ptr = 0x100, .present_bytes = 30}));
  // Entry 2
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::MALLOC, .ptr = 0x200, .size = 100}));
  // Entry 3
  ASSERT_TRUE(memory_trace::WriteEntryToFd(tf.fd, memory_trace::Entry{.type = memory_trace::REALLOC,
                                                                      .ptr = 0x300,
                                                                      .size = 700,
                                                                      .u.old_ptr = 0x200,
                                                                      .present_bytes = 200}));
  // Entry 4
  ASSERT_TRUE(memory_trace::WriteEntryToFd(
      tf.fd, memory_trace::Entry{.type = memory_trace::FREE, .ptr = 0x300, .present_bytes = 1000}));
  close(tf.fd);
  tf.fd = -1;

  memory_trace::Entry* entries;
  size_t num_entries;
  GetUnwindInfo(tf.path, &entries, &num_entries);
  EXPECT_EQ(5U, num_entries);

  // Only verify the present bytes values.
  EXPECT_EQ(10, entries[0].present_bytes);
  EXPECT_EQ(30, entries[1].present_bytes);
  EXPECT_EQ(100, entries[2].present_bytes);
  EXPECT_EQ(700, entries[3].present_bytes);
  EXPECT_EQ(1000, entries[4].present_bytes);

  FreeEntries(entries, num_entries);
}
