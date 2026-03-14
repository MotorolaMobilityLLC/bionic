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

#include <sys/vfs.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <string>

#include <meminfo/kernel_page_size.h>
#include "utils.h"

template <typename StatFsT> void Check(StatFsT& sb) {
  // On x86_64 based 16kb page size targets, the page size in userspace is simulated
  // to 16kb but the underlying filesystem block size would remain the same as the
  // underlying kernel page size. On all other targets the kernel page size is the
  // same as the userspace page size.
  // For more info:
  // https://source.android.com/docs/core/architecture/16kb-page-size/getting-started-cf-x86-64-pgagnostic
  EXPECT_EQ(::android::meminfo::kernel_page_size(), static_cast<int>(sb.f_bsize));
  EXPECT_EQ(0U, sb.f_bfree);
  EXPECT_EQ(0U, sb.f_ffree);
  EXPECT_EQ(255, static_cast<int>(sb.f_namelen));

  // Linux 6.7 requires that all filesystems have a non-zero fsid.
  if (sb.f_fsid.__val[0] != 0U) {
    // fs/libfs.c reuses the filesystem's device number.
    struct stat proc_sb;
    ASSERT_EQ(0, stat("/proc", &proc_sb));
    EXPECT_EQ(static_cast<int>(proc_sb.st_dev), sb.f_fsid.__val[0]);
    EXPECT_EQ(0, sb.f_fsid.__val[1]);
  } else {
    // Prior to that, the fsid for /proc was just 0.
    EXPECT_EQ(0, sb.f_fsid.__val[0]);
    EXPECT_EQ(0, sb.f_fsid.__val[1]);
  }

  // The kernel sets a private bit to indicate that f_flags is valid.
  // This flag is not supposed to be exposed to libc clients.
  static const uint32_t ST_VALID = 0x0020;
  EXPECT_TRUE((sb.f_flags & ST_VALID) == 0) << sb.f_flags;
}

TEST(sys_vfs, statfs) {
  struct statfs sb;
  ASSERT_EQ(0, statfs("/proc", &sb));
  Check(sb);
}

TEST(sys_vfs, statfs_failure) {
  struct statfs sb;
  ASSERT_ERRNO_FAILURE(ENOENT, -1, statfs("/does-not-exist", &sb));
}

TEST(sys_vfs, statfs64_smoke) {
  struct statfs64 sb;
  ASSERT_EQ(0, statfs64("/proc", &sb));
  Check(sb);
}

TEST(sys_vfs, statfs64_failure) {
  struct statfs64 sb;
  ASSERT_ERRNO_FAILURE(ENOENT, -1, statfs64("/does-not-exist", &sb));
}

TEST(sys_vfs, fstatfs) {
  struct statfs sb;
  int fd = open("/proc", O_RDONLY);
  ASSERT_EQ(0, fstatfs(fd, &sb));
  close(fd);
  Check(sb);
}

TEST(sys_vfs, fstatfs_failure) {
  struct statfs sb;
  ASSERT_ERRNO_FAILURE(EBADF, -1, fstatfs(-1, &sb));
}

TEST(sys_vfs, fstatfs64_smoke) {
  struct statfs64 sb;
  int fd = open("/proc", O_RDONLY);
  ASSERT_EQ(0, fstatfs64(fd, &sb));
  close(fd);
  Check(sb);
}

TEST(sys_vfs, fstatfs64_failure) {
  struct statfs sb;
  ASSERT_ERRNO_FAILURE(EBADF, -1, fstatfs(-1, &sb));
}
