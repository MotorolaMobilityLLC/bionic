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
#include <errno.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <string>
#include <unordered_map>

#include <android-base/file.h>
#include <android-base/strings.h>
#include <ziparchive/zip_archive.h>

#include <memory_trace/MemoryTrace.h>

#include "File.h"

std::string ZipGetContents(const char* filename) {
  ZipArchiveHandle archive;
  if (OpenArchive(filename, &archive) != 0) {
    return "";
  }

  // It is assumed that the archive contains only a single entry.
  void* cookie;
  std::string contents;
  if (StartIteration(archive, &cookie) == 0) {
    ZipEntry entry;
    std::string name;
    if (Next(cookie, &entry, &name) == 0) {
      contents.resize(entry.uncompressed_length);
      if (ExtractToMemory(archive, &entry, reinterpret_cast<uint8_t*>(contents.data()),
                          entry.uncompressed_length) != 0) {
        contents = "";
      }
    }
  }

  CloseArchive(archive);
  return contents;
}

static void WaitPid(pid_t pid) {
  int wstatus;
  pid_t wait_pid = TEMP_FAILURE_RETRY(waitpid(pid, &wstatus, 0));
  if (wait_pid != pid) {
    if (wait_pid == -1) {
      err(1, "waitpid() failed");
    } else {
      errx(1, "Unexpected pid from waitpid(): expected %d, returned %d", pid, wait_pid);
    }
  }
  if (!WIFEXITED(wstatus)) {
    errx(1, "Forked process did not terminate with exit() call");
  }
  if (WEXITSTATUS(wstatus) != 0) {
    errx(1, "Bad exit value from forked process: returned %d", WEXITSTATUS(wstatus));
  }
}

static void UpdatePresentBytes(std::unordered_map<uint64_t, memory_trace::Entry*>& entries_by_ptr,
                               memory_trace::Entry* entry) {
  switch (entry->type) {
    case memory_trace::FREE:
      if (entry->present_bytes != -1) {
        // Need to find the pointer for this free and update the present bytes
        // on the original pointer.
        auto iter = entries_by_ptr.find(entry->ptr);
        if (iter != entries_by_ptr.end()) {
          // Present bytes can be larger than the recorded size when the
          // real size returned by malloc_usable_size is greater than that.
          // Therefore, always choose the smaller of the two.
          iter->second->present_bytes =
              MIN(entry->present_bytes, static_cast<int64_t>(iter->second->size));
          entries_by_ptr.erase(entry->ptr);
        }
      }
      break;
    case memory_trace::CALLOC:
    case memory_trace::MALLOC:
    case memory_trace::MEMALIGN:
      entries_by_ptr[entry->ptr] = entry;
      break;

    case memory_trace::REALLOC:
      if (entry->ptr != 0) {
        entries_by_ptr[entry->ptr] = entry;
      }
      if (entry->u.old_ptr != 0 && entry->present_bytes != -1) {
        // The old pointer got freed, so add it that way.
        auto iter = entries_by_ptr.find(entry->u.old_ptr);
        if (iter != entries_by_ptr.end()) {
          // Present bytes can be larger than the recorded size when the
          // real size returned by malloc_usable_size is greater than that.
          // Therefore, always choose the smaller of the two.
          iter->second->present_bytes =
              MIN(entry->present_bytes, static_cast<int64_t>(iter->second->size));
          entries_by_ptr.erase(entry->u.old_ptr);
          entry->present_bytes = -1;
        }
      }
      break;
    default:
      break;
  }
}

// This function should not do any memory allocations in the main function.
// Any true allocation should happen in fork'd code.
void GetUnwindInfo(const char* filename, memory_trace::Entry** entries, size_t* num_entries) {
  void* mem =
      mmap(nullptr, sizeof(size_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
  if (mem == MAP_FAILED) {
    err(1, "Unable to allocate a shared map of size %zu", sizeof(size_t));
  }
  *reinterpret_cast<size_t*>(mem) = 0;

  pid_t pid;
  if ((pid = fork()) == 0) {
    // First get the number of lines in the trace file. It is assumed
    // that there are no blank lines, and every line contains a valid
    // allocation operation.
    std::string contents;
    if (android::base::EndsWith(filename, ".zip")) {
      contents = ZipGetContents(filename);
    } else if (!android::base::ReadFileToString(filename, &contents)) {
      errx(1, "Unable to get contents of %s", filename);
    }
    if (contents.empty()) {
      errx(1, "Unable to get contents of %s", filename);
    }

    size_t lines = 0;
    size_t index = 0;
    while (true) {
      index = contents.find('\n', index);
      if (index == std::string::npos) {
        break;
      }
      index++;
      lines++;
    }
    if (contents[contents.size() - 1] != '\n') {
      // Add one since the last line doesn't end in '\n'.
      lines++;
    }
    *reinterpret_cast<size_t*>(mem) = lines;
    _exit(0);
  } else if (pid == -1) {
    err(1, "fork() call failed");
  }
  WaitPid(pid);
  *num_entries = *reinterpret_cast<size_t*>(mem);
  munmap(mem, sizeof(size_t));

  mem = mmap(nullptr, *num_entries * sizeof(memory_trace::Entry), PROT_READ | PROT_WRITE,
             MAP_ANONYMOUS | MAP_SHARED, -1, 0);
  if (mem == MAP_FAILED) {
    err(1, "Unable to allocate a shared map of size %zu",
        *num_entries * sizeof(memory_trace::Entry));
  }
  *entries = reinterpret_cast<memory_trace::Entry*>(mem);

  if ((pid = fork()) == 0) {
    std::string contents;
    if (android::base::EndsWith(filename, ".zip")) {
      contents = ZipGetContents(filename);
    } else if (!android::base::ReadFileToString(filename, &contents)) {
      errx(1, "Unable to get contents of %s", filename);
    }
    if (contents.empty()) {
      errx(1, "Contents of zip file %s is empty.", filename);
    }

    std::unordered_map<uint64_t, memory_trace::Entry*> entries_by_ptr;
    size_t entry_idx = 0;
    size_t start_str = 0;
    size_t end_str = 0;
    while (true) {
      end_str = contents.find('\n', start_str);
      if (end_str == std::string::npos) {
        break;
      }
      if (entry_idx == *num_entries) {
        errx(1, "Too many entries, stopped at entry %zu", entry_idx);
      }
      contents[end_str] = '\0';

      std::string error;
      memory_trace::Entry* entry = &(*entries)[entry_idx++];
      if (!memory_trace::FillInEntryFromString(&contents[start_str], *entry, error)) {
        errx(1, "%s", error.c_str());
      }
      start_str = end_str + 1;

      // If this operation does a free, set the present_bytes on the original
      // allocation.
      UpdatePresentBytes(entries_by_ptr, entry);
    }
    if (entry_idx != *num_entries) {
      errx(1, "Mismatched number of entries found: expected %zu, found %zu", *num_entries,
           entry_idx);
    }
    _exit(0);
  } else if (pid == -1) {
    err(1, "fork() call failed");
  }
  WaitPid(pid);
}

void FreeEntries(memory_trace::Entry* entries, size_t num_entries) {
  munmap(entries, num_entries * sizeof(memory_trace::Entry));
}
