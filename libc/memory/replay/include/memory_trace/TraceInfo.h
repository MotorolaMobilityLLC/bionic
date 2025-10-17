/*
 * Copyright (C) 2025 The Android Open Source Project
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

#include <stack>
#include <string>

namespace memory_trace {

// Forward Declaration
struct Entry;

class TraceInfo {
 public:
  TraceInfo() = default;
  ~TraceInfo() { Clear(); }

  void Init(const std::string& filename);

  void Clear();

  uint64_t RunSingleThread();

  const std::string& filename() { return filename_; }

  Entry* entries() { return entries_; }
  size_t num_entries() { return num_entries_; }

 private:
  size_t GetIndex(std::stack<size_t>& free_indices);

  std::string filename_;
  Entry* entries_ = nullptr;
  size_t num_entries_ = 0;
  void** ptrs_ = nullptr;
  size_t num_ptrs_ = 0;
};

}  // namespace memory_trace
