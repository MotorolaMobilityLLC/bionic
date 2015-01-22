/*
 * Copyright (C) 2008 The Android Open Source Project
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

#include "libc_init_common.h"

#include <elf.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/auxv.h>
#include <sys/time.h>
#include <unistd.h>

#include "private/bionic_auxv.h"
#include "private/bionic_ssp.h"
#include "private/bionic_tls.h"
#include "private/KernelArgumentBlock.h"
#include "pthread_internal.h"

extern "C" abort_msg_t** __abort_message_ptr;
extern "C" int __system_properties_init(void);
extern "C" int __set_tls(void* ptr);
extern "C" int __set_tid_address(int* tid_address);

__LIBC_HIDDEN__ void __libc_init_vdso();

// Not public, but well-known in the BSDs.
const char* __progname;

// Declared in <unistd.h>.
char** environ;

// Declared in "private/bionic_ssp.h".
uintptr_t __stack_chk_guard = 0;

/* Init TLS for the initial thread. Called by the linker _before_ libc is mapped
 * in memory. Beware: all writes to libc globals from this function will
 * apply to linker-private copies and will not be visible from libc later on.
 *
 * Note: this function creates a pthread_internal_t for the initial thread and
 * stores the pointer in TLS, but does not add it to pthread's thread list. This
 * has to be done later from libc itself (see __libc_init_common).
 *
 * This function also stores a pointer to the kernel argument block in a TLS slot to be
 * picked up by the libc constructor.
 */
void __libc_init_tls(KernelArgumentBlock& args) {
  __libc_auxv = args.auxv;

  static pthread_internal_t main_thread;

  // Tell the kernel to clear our tid field when we exit, so we're like any other pthread.
  // As a side-effect, this tells us our pid (which is the same as the main thread's tid).
  main_thread.tid = __set_tid_address(&main_thread.tid);
  main_thread.set_cached_pid(main_thread.tid);

  // We don't want to free the main thread's stack even when the main thread exits
  // because things like environment variables with global scope live on it.
  // We also can't free the pthread_internal_t itself, since that lives on the main
  // thread's stack rather than on the heap.
  // The main thread has no mmap allocated space for stack or pthread_internal_t.
  main_thread.mmap_size = 0;
  pthread_attr_init(&main_thread.attr);
  main_thread.attr.flags = PTHREAD_ATTR_FLAG_MAIN_THREAD;
  main_thread.attr.guard_size = 0; // The main thread has no guard page.
  main_thread.attr.stack_size = 0; // User code should never see this; we'll compute it when asked.
  // TODO: the main thread's sched_policy and sched_priority need to be queried.

  __init_thread(&main_thread, false);
  __init_tls(&main_thread);
  __set_tls(main_thread.tls);
  main_thread.tls[TLS_SLOT_BIONIC_PREINIT] = &args;

  __init_alternate_signal_stack(&main_thread);
}

void __libc_init_common(KernelArgumentBlock& args) {
  // Initialize various globals.
  environ = args.envp;
  errno = 0;
  __libc_auxv = args.auxv;
  __progname = args.argv[0] ? args.argv[0] : "<unknown>";
  __abort_message_ptr = args.abort_message_ptr;

  // AT_RANDOM is a pointer to 16 bytes of randomness on the stack.
  __stack_chk_guard = *reinterpret_cast<uintptr_t*>(getauxval(AT_RANDOM));

  // Get the main thread from TLS and add it to the thread list.
  pthread_internal_t* main_thread = __get_thread();
  _pthread_internal_add(main_thread);

  __system_properties_init(); // Requires 'environ'.

  __libc_init_vdso();
}

/* This function will be called during normal program termination
 * to run the destructors that are listed in the .fini_array section
 * of the executable, if any.
 *
 * 'fini_array' points to a list of function addresses. The first
 * entry in the list has value -1, the last one has value 0.
 */
void __libc_fini(void* array) {
  typedef void (*Dtor)();
  Dtor* fini_array = reinterpret_cast<Dtor*>(array);
  const Dtor minus1 = reinterpret_cast<Dtor>(static_cast<uintptr_t>(-1));

  // Sanity check - first entry must be -1.
  if (array == NULL || fini_array[0] != minus1) {
    return;
  }

  // Skip over it.
  fini_array += 1;

  // Count the number of destructors.
  int count = 0;
  while (fini_array[count] != NULL) {
    ++count;
  }

  // Now call each destructor in reverse order.
  while (count > 0) {
    Dtor dtor = fini_array[--count];

    // Sanity check, any -1 in the list is ignored.
    if (dtor == minus1) {
      continue;
    }

    dtor();
  }

#ifndef LIBC_STATIC
  {
    extern void __libc_postfini(void) __attribute__((weak));
    if (__libc_postfini) {
      __libc_postfini();
    }
  }
#endif
}
