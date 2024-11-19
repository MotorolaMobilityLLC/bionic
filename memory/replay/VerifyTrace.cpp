/*
 * Copyright (C) 2024 The Android Open Source Project
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

#include <fcntl.h>
#include <getopt.h>
#include <inttypes.h>
#include <stdio.h>

#include <string>
#include <unordered_map>
#include <utility>

#include <android-base/file.h>

#include <memory_trace/MemoryTrace.h>

#include "File.h"

static void Usage() {
  fprintf(stderr, "Usage: %s [--attempt_recovery] TRACE_FILE1 TRACE_FILE2 ...\n",
          android::base::Basename(android::base::GetExecutablePath()).c_str());
  fprintf(stderr, "  --attempt_recovery\n");
  fprintf(stderr, "    If a trace file has some errors, try to fix it. The new\n");
  fprintf(stderr, "    file will be named TRACE_FILE.repair\n");
  fprintf(stderr, "  TRACE_FILE1 TRACE_FILE2 ...\n");
  fprintf(stderr, "      The trace files to verify\n");
  fprintf(stderr, "\n  Print a trace to stdout.\n");
  exit(1);
}

static bool WriteRepairEntries(const char* trace_file, memory_trace::Entry* entries,
                               size_t num_entries) {
  printf("Attempting to reapir trace_file %s\n", trace_file);
  std::string repair_file(std::string(trace_file) + ".repair");
  int fd = open(repair_file.c_str(), O_WRONLY | O_CREAT | O_CLOEXEC, 0644);
  if (fd == -1) {
    printf("Failed to create repair file %s: %s\n", repair_file.c_str(), strerror(errno));
    return false;
  }
  for (size_t i = 0; i < num_entries; i++) {
    if (!memory_trace::WriteEntryToFd(fd, entries[i])) {
      printf("Failed to write entry to file:\n");
      close(fd);
      return false;
    }
  }
  close(fd);
  printf("Attempt to repair trace has succeeded, new trace %s\n", repair_file.c_str());
  return true;
}

static void VerifyTrace(const char* trace_file, bool attempt_repair) {
  printf("Checking %s\n", trace_file);

  memory_trace::Entry* entries;
  size_t num_entries;
  GetUnwindInfo(trace_file, &entries, &num_entries);

  bool found_error = false;
  bool error_repaired = false;
  std::unordered_map<uint64_t, std::pair<memory_trace::Entry*, size_t>> live_ptrs;
  for (size_t i = 0; i < num_entries; i++) {
    memory_trace::Entry* entry = &entries[i];

    uint64_t ptr = 0;
    switch (entry->type) {
      case memory_trace::MALLOC:
      case memory_trace::MEMALIGN:
        ptr = entry->ptr;
        break;
      case memory_trace::CALLOC:
        ptr = entry->ptr;
        break;
      case memory_trace::REALLOC:
        if (entry->ptr != 0) {
          ptr = entry->ptr;
        }
        if (entry->u.old_ptr != 0) {
          // Verify old pointer
          auto old_entry = live_ptrs.find(entry->u.old_ptr);
          if (old_entry == live_ptrs.end()) {
            printf("  Line %zu: freeing of unknown ptr 0x%" PRIx64 "\n", i + 1, entry->u.old_ptr);
            printf("    %s\n", memory_trace::CreateStringFromEntry(*entry).c_str());
            found_error = true;
            if (attempt_repair) {
              printf("  Unable to repair this failure.\n");
            }
          } else {
            live_ptrs.erase(old_entry);
          }
        }
        break;
      case memory_trace::FREE:
        if (entry->ptr != 0) {
          // Verify pointer is present.
          auto old_entry = live_ptrs.find(entry->ptr);
          if (old_entry == live_ptrs.end()) {
            printf("  Line %zu: freeing of unknown ptr 0x%" PRIx64 "\n", i + 1, entry->ptr);
            printf("    %s\n", memory_trace::CreateStringFromEntry(*entry).c_str());
            found_error = true;
            if (attempt_repair) {
              printf("  Unable to repair this failure.\n");
            }
          } else {
            live_ptrs.erase(old_entry);
          }
        }
        break;
      case memory_trace::THREAD_DONE:
        break;
    }

    if (ptr != 0) {
      auto old_entry = live_ptrs.find(ptr);
      if (old_entry != live_ptrs.end()) {
        printf("  Line %zu: duplicate ptr 0x%" PRIx64 " previously found at line %" PRId64 "\n",
               i + 1, ptr, old_entry->second.second);
        printf("    Original entry:\n");
        printf("      %s\n", memory_trace::CreateStringFromEntry(*entry).c_str());
        printf("    Duplicate pointer entry:\n");
        printf("      %s\n", memory_trace::CreateStringFromEntry(*old_entry->second.first).c_str());
        found_error = true;
        if (attempt_repair) {
          // There is a small chance of a race where the same pointer is returned
          // in two different threads before the free is recorded. If this occurs,
          // the way to repair is to search forward for the free of the pointer and
          // swap the two entries.
          error_repaired = false;
          for (size_t j = i + 1; j < num_entries; j++) {
            if (entries[j].type == memory_trace::FREE && entries[j].ptr == ptr) {
              memory_trace::Entry alloc_entry = *entry;
              *entry = entries[j];
              entries[j] = alloc_entry;
              error_repaired = true;

              live_ptrs.erase(old_entry);
              break;
            }
          }
        }
      } else {
        live_ptrs[ptr] = std::make_pair(entry, i + 1);
      }
    }
  }

  if (found_error) {
    printf("Trace %s is not valid.\n", trace_file);
    if (attempt_repair) {
      if (error_repaired) {
        // Save the repaired data out to a file.
        if (!WriteRepairEntries(trace_file, entries, num_entries)) {
          printf("Failed to write repaired entries to a file.\n");
        }
      } else {
        printf("Attempt to repair trace has failed.\n");
      }
    }
  } else {
    printf("Trace %s is valid.\n", trace_file);
  }

  FreeEntries(entries, num_entries);
}

int main(int argc, char** argv) {
  option options[] = {
      {"attempt_repair", no_argument, nullptr, 'a'},
      {nullptr, 0, nullptr, 0},
  };
  int option_index = 0;
  int opt = getopt_long(argc, argv, "", options, &option_index);
  bool attempt_repair = false;
  if (opt == 'a') {
    attempt_repair = true;
  } else if (opt != -1) {
    Usage();
  } else if (optind == argc) {
    fprintf(stderr, "Requires at least one TRACE_FILE\n");
    Usage();
  }

  for (int i = optind; i < argc; i++) {
    VerifyTrace(argv[i], attempt_repair);
  }

  return 0;
}
