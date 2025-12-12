/*
 * Copyright (C) 2019 The Android Open Source Project
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

#include <inttypes.h>
#include <stdint.h>

#include <array>
#include <functional>
#include <mutex>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

#include <android/fdsan.h>
#include <android/set_abort_message.h>
#include <bionic/fdtrack.h>

#include <android-base/no_destructor.h>
#include <android-base/thread_annotations.h>
#include <async_safe/log.h>
#include <bionic/reserved_signals.h>

#include <unwindstack/AndroidUnwinder.h>

struct FdEntry {
  std::mutex mutex;
  std::vector<unwindstack::FrameData> backtrace GUARDED_BY(mutex);
};

// Only unwind up to 32 frames outside of libfdtrack.so.
static constexpr size_t kStackDepth = 32;

struct CallbackData {
  const char* function_names[kStackDepth];
  uint64_t function_offsets[kStackDepth];
  unwindstack::FrameData* frames[kStackDepth];
  size_t size;
};

extern "C" void fdtrack_dump();
extern "C" void fdtrack_dump_fatal();

using fdtrack_callback_t = bool (*)(int fd, const char* const* function_names,
                                    const uint64_t* function_offsets, size_t count, void* arg);

extern "C" void fdtrack_iterate(fdtrack_callback_t callback, void* arg);

static void fd_hook(android_fdtrack_event* event);

// Backtraces for the first 4k file descriptors ought to be enough to diagnose an fd leak.
static constexpr size_t kFdTableSize = 4096;

static bool installed = false;
static std::array<FdEntry, kFdTableSize> stack_traces [[clang::no_destroy]];
static unwindstack::AndroidLocalUnwinder& Unwinder() {
  // Skip any initial frames from libfdtrack.so.
  // Also ignore frames from ART (http://b/236197847) because we'd rather spend
  // our precious few frames on the actual Java calling code rather than the
  // implementation of JNI!
  static android::base::NoDestructor<unwindstack::AndroidLocalUnwinder> unwinder(
      std::vector<std::string>{"libfdtrack.so", "libart.so"});
  return *unwinder.get();
}

__attribute__((constructor)) static void ctor() {
  for (auto& entry : stack_traces) {
    entry.backtrace.reserve(kStackDepth);
  }

  struct sigaction sa = {};
  sa.sa_sigaction = [](int, siginfo_t* siginfo, void*) {
    if (siginfo->si_code == SI_QUEUE && siginfo->si_int == 1) {
      fdtrack_dump_fatal();
    } else {
      fdtrack_dump();
    }
  };
  sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
  sigaction(BIONIC_SIGNAL_FDTRACK, &sa, nullptr);

  unwindstack::ErrorData error;
  if (Unwinder().Initialize(error)) {
    android_fdtrack_hook_t expected = nullptr;
    installed = android_fdtrack_compare_exchange_hook(&expected, &fd_hook);
  }

  android_fdtrack_set_globally_enabled(true);
}

__attribute__((destructor)) static void dtor() {
  if (installed) {
    android_fdtrack_hook_t expected = &fd_hook;
    android_fdtrack_compare_exchange_hook(&expected, nullptr);
  }
}

FdEntry* GetFdEntry(int fd) {
  if (fd >= 0 && fd < static_cast<int>(kFdTableSize)) {
    return &stack_traces[fd];
  }
  return nullptr;
}

static void fd_hook(android_fdtrack_event* event) {
  if (event->type == ANDROID_FDTRACK_EVENT_TYPE_CREATE) {
    if (FdEntry* entry = GetFdEntry(event->fd); entry) {
      std::lock_guard<std::mutex> lock(entry->mutex);
      entry->backtrace.clear();

      unwindstack::AndroidUnwinderData data(kStackDepth);
      if (Unwinder().Unwind(data)) {
        data.DemangleFunctionNames();
        entry->backtrace = std::move(data.frames);
      }
    }
  } else if (event->type == ANDROID_FDTRACK_EVENT_TYPE_CLOSE) {
    if (FdEntry* entry = GetFdEntry(event->fd); entry) {
      std::lock_guard<std::mutex> lock(entry->mutex);
      entry->backtrace.clear();
    }
  }
}

static void iterate_internal(std::function<bool(int fd, const CallbackData*, void*)> callback,
                             void* arg) {
  bool prev = android_fdtrack_set_enabled(false);

  for (int fd = 0; fd < static_cast<int>(stack_traces.size()); ++fd) {
    FdEntry* entry = GetFdEntry(fd);
    if (!entry) {
      continue;
    }

    std::unique_lock<std::mutex> lock(entry->mutex, std::defer_lock);
    if (!lock.try_lock()) {
      async_safe_format_log(ANDROID_LOG_WARN, "fdtrack", "fd %d locked, skipping", fd);
      continue;
    }

    if (entry->backtrace.empty()) {
      continue;
    } else if (entry->backtrace.size() < 2) {
      async_safe_format_log(ANDROID_LOG_WARN, "fdtrack", "fd %d missing frames: size = %zu", fd,
                            entry->backtrace.size());
      continue;
    }

    CallbackData data = {.size = entry->backtrace.size()};
    for (size_t i = 0; i < data.size; ++i) {
      data.function_names[i] = entry->backtrace[i].function_name.c_str();
      data.function_offsets[i] = entry->backtrace[i].function_offset;
      data.frames[i] = &entry->backtrace[i];
    }

    if (!callback(fd, &data, arg)) {
      break;
    }
  }

  android_fdtrack_set_enabled(prev);
}

void fdtrack_iterate(fdtrack_callback_t callback, void* arg) {
  return iterate_internal(
      [&callback](int fd, const CallbackData* data, void* arg) {
        return callback(fd, data->function_names, data->function_offsets, data->size, arg);
      },
      arg);
}

static size_t hash_stack(const char* const* function_names, const uint64_t* function_offsets,
                         size_t stack_depth) {
  size_t hash = 0;
  for (size_t i = 0; i < stack_depth; ++i) {
    // To future maintainers: if a libc++ update ever makes this invalid, replace this with +.
    hash = std::__hash_combine(hash, std::hash<std::string_view>()(function_names[i]));
    hash = std::__hash_combine(hash, std::hash<uint64_t>()(function_offsets[i]));
  }
  return hash;
}

static void fdtrack_dump_impl(bool fatal) {
  if (!installed) {
    async_safe_format_log(ANDROID_LOG_INFO, "fdtrack", "fdtrack not installed");
  } else {
    async_safe_format_log(ANDROID_LOG_INFO, "fdtrack", "fdtrack dumping...");
  }

  // If we're aborting, identify the most common stack in the hopes that it's the culprit,
  // and emit that in the abort message so crash reporting can separate different fd leaks out.
  // This is horrible and quadratic, but we need to avoid allocation since this can happen in
  // response to a signal generated asynchronously. We're only going to dump 1k fds by default,
  // and we're about to blow up the entire system, so this isn't too expensive.
  struct StackInfo {
    size_t hash = 0;
    size_t count = 0;

    size_t size = 0;
    unwindstack::FrameData* frames[kStackDepth];
  };
  struct StackList {
    size_t count = 0;
    std::array<StackInfo, 128> data;
  };

  static StackList stacks = {};

  iterate_internal(
      [fatal](int fd, const CallbackData* data, void*) {
        uint64_t fdsan_owner = android_fdsan_get_owner_tag(fd);
        if (fdsan_owner != 0) {
          async_safe_format_log(ANDROID_LOG_INFO, "fdtrack", "fd %d: (owner = 0x%" PRIx64 ")", fd,
                                fdsan_owner);
        } else {
          async_safe_format_log(ANDROID_LOG_INFO, "fdtrack", "fd %d: (unowned)", fd);
        }

        for (size_t i = 0; i < data->size; ++i) {
          if (data->frames[i]->map_info.get() == nullptr) {
            async_safe_format_log(ANDROID_LOG_INFO, "fdtrack",
                                  "  %zu: %s+%" PRIx64 " pc 0x%" PRIx64 " <unknown>", i,
                                  data->frames[i]->function_name.c_str(),
                                  data->frames[i]->function_offset, data->frames[i]->rel_pc);
          } else {
            async_safe_format_log(
                ANDROID_LOG_INFO, "fdtrack", "  %zu: %s+%" PRIx64 " pc 0x%" PRIx64 " %s", i,
                data->frames[i]->function_name.c_str(), data->frames[i]->function_offset,
                data->frames[i]->rel_pc, data->frames[i]->map_info->name().c_str());
          }
        }

        if (!fatal) {
          return true;
        }

        size_t hash = hash_stack(data->function_names, data->function_offsets, data->size);
        bool found_stack = false;
        for (size_t i = 0; i < stacks.count; ++i) {
          if (stacks.data[i].hash == hash) {
            ++stacks.data[i].count;
            found_stack = true;
            break;
          }
        }

        if (!found_stack) {
          if (stacks.count < stacks.data.size()) {
            auto& stack = stacks.data[stacks.count++];
            stack.hash = hash;
            stack.count = 1;
            stack.size = data->size;
            for (size_t i = 0; i < data->size; ++i) {
              stack.frames[i] = data->frames[i];
            }
          }
        }

        return true;
      },
      nullptr);

  if (!fatal) {
    return;
  }

  // Find the most common stack.
  size_t max = 0;
  size_t total = 0;
  StackInfo* stack = nullptr;
  for (size_t i = 0; i < stacks.count; ++i) {
    total += stacks.data[i].count;
    if (stacks.data[i].count > max) {
      stack = &stacks.data[i];
      max = stack->count;
    }
  }

  static char buf[1024];
  if (!stack) {
    async_safe_format_buffer(buf, sizeof(buf),
                             "aborting due to fd leak: see \"open files\" in the tombstone; "
                             "no stacks?!");
  } else {
    char* p = buf;
    p += async_safe_format_buffer(buf, sizeof(buf),
                                  "aborting due to fd leak: see \"open files\" in the tombstone; "
                                  "most common stack (%zu/%zu) is\n",
                                  max, total);

    for (size_t i = 0; i < stack->size; ++i) {
      ssize_t bytes_left = buf + sizeof(buf) - p;
      if (bytes_left > 0) {
        p += async_safe_format_buffer(p, buf + sizeof(buf) - p, "  %zu: %s+%" PRIu64 "\n", i,
                                      stack->frames[i]->function_name.c_str(),
                                      stack->frames[i]->function_offset);
      }
    }
  }

  android_set_abort_message(buf);

  // Abort on a different thread to avoid ART dumping runtime stacks.
  std::thread([]() { abort(); }).join();
}

void fdtrack_dump() {
  fdtrack_dump_impl(false);
}

void fdtrack_dump_fatal() {
  // Make sure that only one fatal is occurring at a time since static global
  // buffers are used in the fatal path.
  static std::mutex fatal_lock;
  std::lock_guard<std::mutex> guard(fatal_lock);
  fdtrack_dump_impl(true);
}
