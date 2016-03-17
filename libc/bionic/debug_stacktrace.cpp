/*
 * Copyright (C) 2012 The Android Open Source Project
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

#include "debug_stacktrace.h"

#include <dlfcn.h>
#include <inttypes.h>
#include <malloc.h>
#include <unistd.h>
#include <unwind.h>
#include <sys/types.h>

#include "debug_mapinfo.h"
#include "malloc_debug_disable.h"
#include "private/libc_logging.h"

#if defined(__LP64__)
#define PAD_PTR "016" PRIxPTR
#else
#define PAD_PTR "08" PRIxPTR
#endif

typedef struct _Unwind_Context __unwind_context;

extern "C" char* __cxa_demangle(const char*, char*, size_t*, int*);

static mapinfo_t* g_map_info = NULL;

__LIBC_HIDDEN__ void backtrace_startup() {
  ScopedDisableDebugCalls disable;

  g_map_info = mapinfo_create(getpid());
}

__LIBC_HIDDEN__ void backtrace_shutdown() {
  ScopedDisableDebugCalls disable;

  mapinfo_destroy(g_map_info);
}

// M: add 64bit fp uwnind
#if defined(__LP64__)
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

static size_t malloc_main_thread_stack_start = 0;
static size_t malloc_main_thread_stack_size = 0;
static pid_t malloc_pid = 0;

//return 0: success, -1 fail
__LIBC_HIDDEN__ int malloc_get_main_thread_stack(pid_t pid) {
  char c, line[1024];
  int i = 0, fd = -1;

  snprintf(line, sizeof(line), "/proc/%d/task/%d/maps", pid, pid);
  fd = open(line, O_RDONLY);
  if (fd < 0) {
    return -1;
  }

  while (1) {
    if (!read(fd, &c, 1)) break;
      if (c == '\n') {
        line[i] = '\0';
        if (strncmp((const char *)&line[i-7], "[stack]", 7) == 0) {
          const char* stack_start;
          // 64bit main stack format
          // 7ff1bf1000-7ff1c12000 rw-p 00000000 00:00 0                              [stack]
          line[9] = '0';
          line[10] = 'x';
          line[21] = '\0';  // line[11~20] stack start
          stack_start = (const char*)&line[9];
          malloc_main_thread_stack_start = strtoul(stack_start, (char **)NULL, 16);
          malloc_main_thread_stack_size = 8 * 1024 * 1024;  // 8MB for simple handling
          // __libc_format_log(ANDROID_LOG_INFO, "libc",
          //                  "main_thread_stack_start:0x%zx, main_thread_stack_size:0x%zx\n",
          //                   malloc_main_thread_stack_start, malloc_main_thread_stack_size);

          close(fd);
          return 0;
        }
        else {
          i = 0;
        }
    }
    else {
      line[i++] = c;
    }
  }
  close(fd);
  return -1;
}

//return 0: success, -1 fail
__LIBC_HIDDEN__ int malloc_get_stack(size_t* pthread_stack_start, size_t* pthread_stack_end) {
  pid_t pid = getpid();

  if (gettid() == pid) {
    if (pid != malloc_pid) {
      malloc_pid = pid;
      malloc_main_thread_stack_start = 0;  // reset for new process
      malloc_main_thread_stack_size = 0;
    }

    if (!malloc_main_thread_stack_start) {
      if (malloc_get_main_thread_stack(pid)) {
        return -1;
      }
    }
    *pthread_stack_start = malloc_main_thread_stack_start;
    *pthread_stack_end = malloc_main_thread_stack_start - malloc_main_thread_stack_size;
  }
  else {
    pthread_attr_t attr;
    pthread_getattr_np(pthread_self(), &attr);
    *pthread_stack_start = (size_t)attr.stack_base + attr.stack_size;
    *pthread_stack_end = (size_t)attr.stack_base;
  }
  return 0;
}

__LIBC_HIDDEN__ int get_backtrace(uintptr_t* frames, size_t max_depth) {
  size_t i = 0;
  size_t pthread_stack_start;
  size_t pthread_stack_end;
  int have_skipped_self = 0;
  size_t next_fp = 0;
  size_t fp_tmp = (size_t)__builtin_frame_address(0);

  if (malloc_get_stack(&pthread_stack_start, &pthread_stack_end))
    return 0;

  while (i < max_depth && fp_tmp > pthread_stack_end && fp_tmp < pthread_stack_start) {
    if (fp_tmp & 0xf) break;

    if (!have_skipped_self) {
      have_skipped_self = 1;
      fp_tmp = *(intptr_t *)fp_tmp;
      continue;
    }
    /*
    * -4 here because we care about the PC at time of bl,
    * not where the return will go.
    */
    frames[i++] = *(intptr_t *)(fp_tmp + 8) - 4;
    next_fp = *(intptr_t *)fp_tmp;
    if (next_fp <= fp_tmp)
      break;
    fp_tmp = next_fp;
  }
  return (int)i;
}
#else // M: 64bit default unwind
struct stack_crawl_state_t {
  uintptr_t* frames;
  size_t frame_count;
  size_t max_depth;
  bool have_skipped_self;

  stack_crawl_state_t(uintptr_t* frames, size_t max_depth)
      : frames(frames), frame_count(0), max_depth(max_depth), have_skipped_self(false) {
  }
};

static _Unwind_Reason_Code trace_function(__unwind_context* context, void* arg) {
  stack_crawl_state_t* state = static_cast<stack_crawl_state_t*>(arg);

  uintptr_t ip = _Unwind_GetIP(context);

  // The first stack frame is get_backtrace itself. Skip it.
  if (ip != 0 && !state->have_skipped_self) {
    state->have_skipped_self = true;
    return _URC_NO_REASON;
  }

#if defined(__arm__)
  /*
   * The instruction pointer is pointing at the instruction after the bl(x), and
   * the _Unwind_Backtrace routine already masks the Thumb mode indicator (LSB
   * in PC). So we need to do a quick check here to find out if the previous
   * instruction is a Thumb-mode BLX(2). If so subtract 2 otherwise 4 from PC.
   */
  if (ip != 0) {
    //M: work around for unwind NE, 0x10000000 get from java/native process maps
    if (ip < 0x10000000) {
      return _URC_END_OF_STACK;
    }

    short* ptr = reinterpret_cast<short*>(ip);
    // Thumb BLX(2)
    if ((*(ptr-1) & 0xff80) == 0x4780) {
      ip -= 2;
    } else {
      ip -= 4;
    }
  }
#endif

  state->frames[state->frame_count++] = ip;
  return (state->frame_count >= state->max_depth) ? _URC_END_OF_STACK : _URC_NO_REASON;
}

__LIBC_HIDDEN__ int get_backtrace(uintptr_t* frames, size_t max_depth) {
  ScopedDisableDebugCalls disable;

  stack_crawl_state_t state(frames, max_depth);
  _Unwind_Backtrace(trace_function, &state);
  return state.frame_count;
}
#endif

__LIBC_HIDDEN__ void log_backtrace(uintptr_t* frames, size_t frame_count) {
  ScopedDisableDebugCalls disable;

  uintptr_t self_bt[16];
  if (frames == NULL) {
    frame_count = get_backtrace(self_bt, 16);
    frames = self_bt;
  }

  __libc_format_log(ANDROID_LOG_ERROR, "libc",
                    "*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***\n");

  for (size_t i = 0 ; i < frame_count; ++i) {
    uintptr_t offset = 0;
    const char* symbol = NULL;

    Dl_info info;
    if (dladdr((void*) frames[i], &info) != 0) {
      offset = reinterpret_cast<uintptr_t>(info.dli_saddr);
      symbol = info.dli_sname;
    }

    uintptr_t rel_pc = offset;
    const mapinfo_t* mi = (g_map_info != NULL) ? mapinfo_find(g_map_info, frames[i], &rel_pc) : NULL;
    const char* soname = (mi != NULL) ? mi->name : info.dli_fname;
    if (soname == NULL) {
      soname = "<unknown>";
    }
    if (symbol != NULL) {
      char* demangled_symbol = __cxa_demangle(symbol, NULL, NULL, NULL);
      const char* best_name = (demangled_symbol != NULL) ? demangled_symbol : symbol;

      __libc_format_log(ANDROID_LOG_ERROR, "libc",
                        "          #%02zd  pc %" PAD_PTR "  %s (%s+%" PRIuPTR ")",
                        i, rel_pc, soname, best_name, frames[i] - offset);

      free(demangled_symbol);
    } else {
      __libc_format_log(ANDROID_LOG_ERROR, "libc",
                        "          #%02zd  pc %" PAD_PTR "  %s",
                        i, rel_pc, soname);
    }
  }
}
