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

#pragma once

#include <stdint.h>
#include <time.h>

static __always_inline uint64_t Nanotime() {
  struct timespec t = {};
  clock_gettime(CLOCK_MONOTONIC, &t);
  return static_cast<uint64_t>(t.tv_sec) * 1000000000LL + t.tv_nsec;
}

static __always_inline void MakeAllocationResident(void* ptr, size_t nbytes, int64_t present_bytes,
                                                   int pagesize) {
  if (present_bytes != -1 && static_cast<size_t>(present_bytes) < nbytes) {
    nbytes = present_bytes;
  }

  size_t start = 0;
  uintptr_t page_aligned = (reinterpret_cast<uintptr_t>(ptr) + pagesize - 1) & ~(pagesize - 1);
  uint8_t* data = reinterpret_cast<uint8_t*>(ptr);
  if (page_aligned != reinterpret_cast<uintptr_t>(data)) {
    // Make the partial page data resident.
    data[0] = 1;

    data = reinterpret_cast<uint8_t*>(page_aligned);
    start = page_aligned - reinterpret_cast<uintptr_t>(ptr);
  }
  for (size_t i = start; i < nbytes; i += pagesize) {
    data[i] = 1;
  }
}
