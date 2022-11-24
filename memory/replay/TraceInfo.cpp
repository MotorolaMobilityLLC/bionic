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

#include <err.h>
#include <inttypes.h>
#include <malloc.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#include <stack>
#include <string>
#include <unordered_map>

#include <memory_trace/MemoryTrace.h>
#include <memory_trace/TraceInfo.h>

#include "File.h"
#include "Utils.h"

namespace memory_trace {

size_t TraceInfo::GetIndex(std::stack<size_t>& free_indices) {
  if (free_indices.empty()) {
    return num_ptrs_++;
  }
  size_t index = free_indices.top();
  free_indices.pop();
  return index;
}

void TraceInfo::Init(const std::string& filename) {
  filename_ = filename;
  GetUnwindInfo(filename_.c_str(), &entries_, &num_entries_);

  // This loop will convert the ptr field into an index into the ptrs array.
  // Creating this index allows the trace run to quickly store or retrieve the
  // allocation.
  // For free, the ptr field will be index + one, where a zero represents
  // a free(nullptr) call.
  // For realloc, the old_pointer field will be index + one, where a zero
  // represents a realloc(nullptr, XX).
  num_ptrs_ = 0;
  std::stack<size_t> free_indices;
  std::unordered_map<uint64_t, size_t> ptr_to_index;
  for (size_t i = 0; i < num_entries_; i++) {
    memory_trace::Entry* entry = &entries_[i];
    switch (entry->type) {
      case memory_trace::MALLOC:
      case memory_trace::CALLOC:
      case memory_trace::MEMALIGN: {
        size_t idx = GetIndex(free_indices);
        ptr_to_index[entry->ptr] = idx;
        entry->ptr = idx;
        break;
      }
      case memory_trace::REALLOC: {
        if (entry->u.old_ptr != 0) {
          auto idx_entry = ptr_to_index.find(entry->u.old_ptr);
          if (idx_entry == ptr_to_index.end()) {
            errx(1, "File Error: Failed to find realloc pointer %" PRIx64, entry->u.old_ptr);
          }
          size_t old_pointer_idx = idx_entry->second;
          free_indices.push(old_pointer_idx);
          ptr_to_index.erase(idx_entry);
          entry->u.old_ptr = old_pointer_idx + 1;
        }
        size_t idx = GetIndex(free_indices);
        ptr_to_index[entry->ptr] = idx;
        entry->ptr = idx;
        break;
      }
      case memory_trace::FREE:
        if (entry->ptr != 0) {
          auto idx_entry = ptr_to_index.find(entry->ptr);
          if (idx_entry == ptr_to_index.end()) {
            errx(1, "File Error: Unable to find free pointer %" PRIx64, entry->ptr);
          }
          free_indices.push(idx_entry->second);
          entry->ptr = idx_entry->second + 1;
          ptr_to_index.erase(idx_entry);
        }
        break;
      case memory_trace::THREAD_DONE:
      case memory_trace::UNKNOWN:
        break;
    }
  }
  void* map = mmap(nullptr, sizeof(void*) * num_ptrs_, PROT_READ | PROT_WRITE,
                   MAP_ANON | MAP_PRIVATE, -1, 0);
  if (map == MAP_FAILED) {
    err(1, "mmap failed");
  }
  ptrs_ = reinterpret_cast<void**>(map);
}

void TraceInfo::Clear() {
  if (ptrs_ != nullptr) {
    munmap(ptrs_, sizeof(void*) * num_ptrs_);
  }
  if (entries_ != nullptr) {
    FreeEntries(entries_, num_entries_);
  }
}

uint64_t TraceInfo::RunSingleThread() {
  int pagesize = getpagesize();
  uint64_t total_ns = 0;
  for (size_t i = 0; i < num_entries_; i++) {
    void* ptr;
    const memory_trace::Entry& entry = entries_[i];
    uint64_t start_ns;
    switch (entry.type) {
      case memory_trace::MALLOC:
        start_ns = Nanotime();
        ptr = malloc(entry.size);
        if (ptr == nullptr) {
          errx(1, "malloc returned nullptr");
        }
        MakeAllocationResident(ptr, entry.size, entry.present_bytes, pagesize);
        total_ns += Nanotime() - start_ns;

        if (ptrs_[entry.ptr] != nullptr) {
          errx(1, "Internal Error: malloc pointer being replaced is not nullptr");
        }
        ptrs_[entry.ptr] = ptr;
        break;

      case memory_trace::CALLOC:
        start_ns = Nanotime();
        ptr = calloc(entry.u.n_elements, entry.size);
        if (ptr == nullptr) {
          errx(1, "calloc returned nullptr");
        }
        MakeAllocationResident(ptr, entry.size, entry.present_bytes, pagesize);
        total_ns += Nanotime() - start_ns;

        if (ptrs_[entry.ptr] != nullptr) {
          errx(1, "Internal Error: calloc pointer being replaced is not nullptr");
        }
        ptrs_[entry.ptr] = ptr;
        break;

      case memory_trace::MEMALIGN:
        start_ns = Nanotime();
        ptr = memalign(entry.u.align, entry.size);
        if (ptr == nullptr) {
          errx(1, "memalign returned nullptr");
        }
        MakeAllocationResident(ptr, entry.size, entry.present_bytes, pagesize);
        total_ns += Nanotime() - start_ns;

        if (ptrs_[entry.ptr] != nullptr) {
          errx(1, "Internal Error: memalign pointer being replaced is not nullptr");
        }
        ptrs_[entry.ptr] = ptr;
        break;

      case memory_trace::REALLOC:
        start_ns = Nanotime();
        if (entry.u.old_ptr == 0) {
          ptr = realloc(nullptr, entry.size);
        } else {
          ptr = realloc(ptrs_[entry.u.old_ptr - 1], entry.size);
          ptrs_[entry.u.old_ptr - 1] = nullptr;
        }
        if (entry.size > 0) {
          if (ptr == nullptr) {
            errx(1, "realloc returned nullptr");
          }
          MakeAllocationResident(ptr, entry.size, entry.present_bytes, pagesize);
        }
        total_ns += Nanotime() - start_ns;

        if (ptrs_[entry.ptr] != nullptr) {
          errx(1, "Internal Error: realloc pointer being replaced is not nullptr");
        }
        ptrs_[entry.ptr] = ptr;
        break;

      case memory_trace::FREE:
        if (entry.ptr != 0) {
          ptr = ptrs_[entry.ptr - 1];
          ptrs_[entry.ptr - 1] = nullptr;
        } else {
          ptr = nullptr;
        }
        start_ns = Nanotime();
        free(ptr);
        total_ns += Nanotime() - start_ns;
        break;

      case memory_trace::THREAD_DONE:
      case memory_trace::UNKNOWN:
        break;
    }
  }

  for (size_t i = 0; i < num_ptrs_; i++) {
    void* ptr = ptrs_[i];
    if (ptr != nullptr) {
      free(ptr);
      ptrs_[i] = nullptr;
    }
  }

  return total_ns;
}

}  // namespace memory_trace
