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

#include <pthread.h>

#include "pthread_internal.h"

#include "private/bionic_tls.h"

// This trampoline is called from the assembly _pthread_clone function.
// Our 'tls' and __pthread_clone's 'child_stack' are one and the same, just growing in
// opposite directions.
extern "C" void __thread_entry(void* (*func)(void*), void* arg, void** tls) {
  // Wait for our creating thread to release us. This lets it have time to
  // notify gdb about this thread before we start doing anything.
  // This also provides the memory barrier needed to ensure that all memory
  // accesses previously made by the creating thread are visible to us.
  pthread_mutex_t* start_mutex = (pthread_mutex_t*) &tls[TLS_SLOT_SELF];
  pthread_mutex_lock(start_mutex);
  pthread_mutex_destroy(start_mutex);

  pthread_internal_t* thread = (pthread_internal_t*) tls[TLS_SLOT_THREAD_ID];
  thread->tls = tls;
  __init_tls(thread);

  if ((thread->internal_flags & PTHREAD_INTERNAL_FLAG_THREAD_INIT_FAILED) != 0) {
    pthread_exit(NULL);
  }

  void* result = func(arg);
  pthread_exit(result);
}
