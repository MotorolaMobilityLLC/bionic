/*
 * Copyright (C) 2014 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/sysinfo.h>

#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "platform/bionic/page.h"
#include "private/ScopedReaddir.h"
#include "private/get_cpu_count_from_string.h"

// The __get_cpu_count function needs a 4096 byte buffer to match a page size
// to avoid malloc/free when reading from a file.
#pragma clang diagnostic ignored "-Wframe-larger-than="

int __get_cpu_count(const char* sys_file) {
  int cpu_count = 1;
  int fd = open(sys_file, O_RDONLY | O_CLOEXEC);
  if (fd >= 0) {
    // DEVICE_ATTR sysfs attributes are limited to a single page in size.
    // Setting this buffer at 4096 bytes handles systems with hundreds
    // of cores and meets the page size.
    char buf[4096] __attribute__((__uninitialized__));
    ssize_t rc = read(fd, buf, sizeof(buf));
    if (rc > 0) {
      cpu_count = GetCpuCountFromString(buf);
    }
    close(fd);
  }
  return cpu_count;
}

int get_nprocs_conf() {
  // It's unclear to me whether this is intended to be "possible" or "present",
  // but on mobile they're unlikely to differ.
  return __get_cpu_count("/sys/devices/system/cpu/possible");
}

int get_nprocs() {
  return __get_cpu_count("/sys/devices/system/cpu/online");
}

long get_phys_pages() {
  struct sysinfo si;
  sysinfo(&si);
  return (static_cast<int64_t>(si.totalram) * si.mem_unit) / page_size();
}

long get_avphys_pages() {
  struct sysinfo si;
  sysinfo(&si);
  return ((static_cast<int64_t>(si.freeram) + si.bufferram) * si.mem_unit) / page_size();
}
