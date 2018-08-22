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

#include <android/api-level.h>
#include <elf.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/auxv.h>
#include <sys/mman.h>

#include "libc_init_common.h"
#include "pthread_internal.h"

#include "private/bionic_globals.h"
#include "private/bionic_macros.h"
#include "private/bionic_page.h"
#include "private/bionic_tls.h"
#include "private/KernelArgumentBlock.h"

#if __has_feature(hwaddress_sanitizer)
#include <sanitizer/hwasan_interface.h>
#endif

// Leave the variable uninitialized for the sake of the dynamic loader, which
// links in this file. The loader will initialize this variable before
// relocating itself.
#if defined(__i386__)
__LIBC_HIDDEN__ void* __libc_sysinfo;
#endif

extern "C" int __cxa_atexit(void (*)(void *), void *, void *);

static void call_array(void(**list)()) {
  // First element is -1, list is null-terminated
  while (*++list) {
    (*list)();
  }
}

static void apply_gnu_relro() {
  ElfW(Phdr)* phdr_start = reinterpret_cast<ElfW(Phdr)*>(getauxval(AT_PHDR));
  unsigned long int phdr_ct = getauxval(AT_PHNUM);

  for (ElfW(Phdr)* phdr = phdr_start; phdr < (phdr_start + phdr_ct); phdr++) {
    if (phdr->p_type != PT_GNU_RELRO) {
      continue;
    }

    ElfW(Addr) seg_page_start = PAGE_START(phdr->p_vaddr);
    ElfW(Addr) seg_page_end = PAGE_END(phdr->p_vaddr + phdr->p_memsz);

    // Check return value here? What do we do if we fail?
    mprotect(reinterpret_cast<void*>(seg_page_start), seg_page_end - seg_page_start, PROT_READ);
  }
}

// The program startup function __libc_init() defined here is
// used for static executables only (i.e. those that don't depend
// on shared libraries). It is called from arch-$ARCH/bionic/crtbegin_static.S
// which is directly invoked by the kernel when the program is launched.
//
// The 'structors' parameter contains pointers to various initializer
// arrays that must be run before the program's 'main' routine is launched.
__noreturn static void __real_libc_init(void *raw_args,
                                        void (*onexit)(void) __unused,
                                        int (*slingshot)(int, char**, char**),
                                        structors_array_t const * const structors) {
  BIONIC_STOP_UNWIND;

  KernelArgumentBlock args(raw_args);

  // Initializing the globals requires TLS to be available for errno.
  __libc_init_main_thread(args);

  static libc_shared_globals shared_globals;
  __libc_shared_globals = &shared_globals;
  __libc_init_shared_globals(&shared_globals);

  __libc_init_globals(args);

  __libc_init_AT_SECURE(args);
  __libc_init_common(args);

  apply_gnu_relro();

  // Several Linux ABIs don't pass the onexit pointer, and the ones that
  // do never use it.  Therefore, we ignore it.

  call_array(structors->preinit_array);
  call_array(structors->init_array);

  // The executable may have its own destructors listed in its .fini_array
  // so we need to ensure that these are called when the program exits
  // normally.
  if (structors->fini_array != nullptr) {
    __cxa_atexit(__libc_fini,structors->fini_array,nullptr);
  }

  exit(slingshot(args.argc, args.argv, args.envp));
}

#if __has_feature(hwaddress_sanitizer)
__attribute__((no_sanitize("hwaddress")))
#endif
__noreturn void __libc_init(void* raw_args,
                            void (*onexit)(void) __unused,
                            int (*slingshot)(int, char**, char**),
                            structors_array_t const * const structors) {
#if __has_feature(hwaddress_sanitizer)
  __hwasan_shadow_init();
#endif
  __real_libc_init(raw_args, onexit, slingshot, structors);
}


static uint32_t g_target_sdk_version{__ANDROID_API__};

extern "C" uint32_t android_get_application_target_sdk_version() {
  return g_target_sdk_version;
}

uint32_t bionic_get_application_target_sdk_version() {
  return android_get_application_target_sdk_version();
}

extern "C" void android_set_application_target_sdk_version(uint32_t target) {
  g_target_sdk_version = target;
}
