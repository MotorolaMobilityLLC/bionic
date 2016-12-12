/*
 * Copyright (C) 2007 The Android Open Source Project
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

#include "linker.h"
#include "linker_globals.h"
#include "linker_dlwarning.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <android/api-level.h>

#include <bionic/pthread_internal.h>
#include "private/bionic_tls.h"
#include "private/ScopedPthreadMutexLocker.h"
#include "private/ThreadLocalBuffer.h"

/* This file hijacks the symbols stubbed out in libdl.so. */

static pthread_mutex_t g_dl_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

static char* __bionic_set_dlerror(char* new_value) {
  char** dlerror_slot = &reinterpret_cast<char**>(__get_tls())[TLS_SLOT_DLERROR];

  char* old_value = *dlerror_slot;
  *dlerror_slot = new_value;
  return old_value;
}

static void __bionic_format_dlerror(const char* msg, const char* detail) {
  char* buffer = __get_thread()->dlerror_buffer;
  strlcpy(buffer, msg, __BIONIC_DLERROR_BUFFER_SIZE);
  if (detail != nullptr) {
    strlcat(buffer, ": ", __BIONIC_DLERROR_BUFFER_SIZE);
    strlcat(buffer, detail, __BIONIC_DLERROR_BUFFER_SIZE);
  }

  __bionic_set_dlerror(buffer);
}

char* __dlerror() {
  char* old_value = __bionic_set_dlerror(nullptr);
  return old_value;
}

void __android_get_LD_LIBRARY_PATH(char* buffer, size_t buffer_size) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  do_android_get_LD_LIBRARY_PATH(buffer, buffer_size);
}

void __android_update_LD_LIBRARY_PATH(const char* ld_library_path) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  do_android_update_LD_LIBRARY_PATH(ld_library_path);
}

static void* dlopen_ext(const char* filename,
                        int flags,
                        const android_dlextinfo* extinfo,
                        const void* caller_addr) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  g_linker_logger.ResetState();
  void* result = do_dlopen(filename, flags, extinfo, caller_addr);
  if (result == nullptr) {
    __bionic_format_dlerror("dlopen failed", linker_get_error_buffer());
    return nullptr;
  }
  return result;
}

void* __android_dlopen_ext(const char* filename,
                           int flags,
                           const android_dlextinfo* extinfo,
                           const void* caller_addr) {
  return dlopen_ext(filename, flags, extinfo, caller_addr);
}

void* __dlopen(const char* filename, int flags, const void* caller_addr) {
  return dlopen_ext(filename, flags, nullptr, caller_addr);
}

void* dlsym_impl(void* handle, const char* symbol, const char* version, const void* caller_addr) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  g_linker_logger.ResetState();
  void* result;
  if (!do_dlsym(handle, symbol, version, caller_addr, &result)) {
    __bionic_format_dlerror(linker_get_error_buffer(), nullptr);
    return nullptr;
  }

  return result;
}

void* __dlsym(void* handle, const char* symbol, const void* caller_addr) {
  return dlsym_impl(handle, symbol, nullptr, caller_addr);
}

void* __dlvsym(void* handle, const char* symbol, const char* version, const void* caller_addr) {
  return dlsym_impl(handle, symbol, version, caller_addr);
}

int __dladdr(const void* addr, Dl_info* info) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  return do_dladdr(addr, info);
}

int __dlclose(void* handle) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  int result = do_dlclose(handle);
  if (result != 0) {
    __bionic_format_dlerror("dlclose failed", linker_get_error_buffer());
  }
  return result;
}

// This function is needed by libgcc.a (this is why there is no prefix for this one)
int dl_iterate_phdr(int (*cb)(dl_phdr_info* info, size_t size, void* data), void* data) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  return do_dl_iterate_phdr(cb, data);
}

#if defined(__arm__)
_Unwind_Ptr __dl_unwind_find_exidx(_Unwind_Ptr pc, int* pcount) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  return do_dl_unwind_find_exidx(pc, pcount);
}
#endif

void __android_set_application_target_sdk_version(uint32_t target) {
  // lock to avoid modification in the middle of dlopen.
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  set_application_target_sdk_version(target);
}

uint32_t __android_get_application_target_sdk_version() {
  return get_application_target_sdk_version();
}

void __android_dlwarning(void* obj, void (*f)(void*, const char*)) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  get_dlwarning(obj, f);
}

bool __android_init_namespaces(const char* public_ns_sonames,
                             const char* anon_ns_library_path) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);
  bool success = init_namespaces(public_ns_sonames, anon_ns_library_path);
  if (!success) {
    __bionic_format_dlerror("android_init_namespaces failed", linker_get_error_buffer());
  }

  return success;
}

android_namespace_t* __android_create_namespace(const char* name,
                                                const char* ld_library_path,
                                                const char* default_library_path,
                                                uint64_t type,
                                                const char* permitted_when_isolated_path,
                                                android_namespace_t* parent_namespace,
                                                const void* caller_addr) {
  ScopedPthreadMutexLocker locker(&g_dl_mutex);

  android_namespace_t* result = create_namespace(caller_addr,
                                                 name,
                                                 ld_library_path,
                                                 default_library_path,
                                                 type,
                                                 permitted_when_isolated_path,
                                                 parent_namespace);

  if (result == nullptr) {
    __bionic_format_dlerror("android_create_namespace failed", linker_get_error_buffer());
  }

  return result;
}

// name_offset: starting index of the name in libdl_info.strtab
#define ELF32_SYM_INITIALIZER(name_offset, value, shndx) \
    { name_offset, \
      reinterpret_cast<Elf32_Addr>(value), \
      /* st_size */ 0, \
      ((shndx) == 0) ? 0 : (STB_GLOBAL << 4), \
      /* st_other */ 0, \
      shndx, \
    }

#define ELF64_SYM_INITIALIZER(name_offset, value, shndx) \
    { name_offset, \
      ((shndx) == 0) ? 0 : (STB_GLOBAL << 4), \
      /* st_other */ 0, \
      shndx, \
      reinterpret_cast<Elf64_Addr>(value), \
      /* st_size */ 0, \
    }

static const char ANDROID_LIBDL_STRTAB[] =
  // 0000000000111111 11112222222222333 333333344444444 44555555555566666 6666677777777778 8888888889999999999
  // 0123456789012345 67890123456789012 345678901234567 89012345678901234 5678901234567890 1234567890123456789
    "__loader_dlopen\0__loader_dlclose\0__loader_dlsym\0__loader_dlerror\0__loader_dladdr\0__loader_android_up"
  // 1*
  // 000000000011111111112 2222222223333333333444444444455555555 5566666666667777777777888 88888889999999999
  // 012345678901234567890 1234567890123456789012345678901234567 8901234567890123456789012 34567890123456789
    "date_LD_LIBRARY_PATH\0__loader_android_get_LD_LIBRARY_PATH\0__loader_dl_iterate_phdr\0__loader_android_"
  // 2*
  // 00000000001 1111111112222222222333333333344444444445555555555666 6666666777777777788888888889999999999
  // 01234567890 1234567890123456789012345678901234567890123456789012 3456789012345678901234567890123456789
    "dlopen_ext\0__loader_android_set_application_target_sdk_version\0__loader_android_get_application_targ"
  // 3*
  // 000000000011111 111112222222222333333333344444444 4455555555556666666666777777777788 8888888899999999 99
  // 012345678901234 567890123456789012345678901234567 8901234567890123456789012345678901 2345678901234567 89
    "et_sdk_version\0__loader_android_init_namespaces\0__loader_android_create_namespace\0__loader_dlvsym\0__"
  // 4*
  // 0000000000111111111122222 2222233333333334444444 4445555555555666666666677777777778 8888888889999999 999
  // 0123456789012345678901234 5678901234567890123456 7890123456789012345678901234567890 1234567890123456 789
    "loader_android_dlwarning\0"
#if defined(__arm__)
  // 425
    "__loader_dl_unwind_find_exidx\0"
#endif
    ;

static ElfW(Sym) g_libdl_symtab[] = {
  // Total length of libdl_info.strtab, including trailing 0.
  // This is actually the STH_UNDEF entry. Technically, it's
  // supposed to have st_name == 0, but instead, it points to an index
  // in the strtab with a \0 to make iterating through the symtab easier.
  ELFW(SYM_INITIALIZER)(sizeof(ANDROID_LIBDL_STRTAB) - 1, nullptr, 0),
  ELFW(SYM_INITIALIZER)(  0, &__dlopen, 1),
  ELFW(SYM_INITIALIZER)( 16, &__dlclose, 1),
  ELFW(SYM_INITIALIZER)( 33, &__dlsym, 1),
  ELFW(SYM_INITIALIZER)( 48, &__dlerror, 1),
  ELFW(SYM_INITIALIZER)( 65, &__dladdr, 1),
  ELFW(SYM_INITIALIZER)( 81, &__android_update_LD_LIBRARY_PATH, 1),
  ELFW(SYM_INITIALIZER)(121, &__android_get_LD_LIBRARY_PATH, 1),
  ELFW(SYM_INITIALIZER)(158, &dl_iterate_phdr, 1),
  ELFW(SYM_INITIALIZER)(183, &__android_dlopen_ext, 1),
  ELFW(SYM_INITIALIZER)(211, &__android_set_application_target_sdk_version, 1),
  ELFW(SYM_INITIALIZER)(263, &__android_get_application_target_sdk_version, 1),
  ELFW(SYM_INITIALIZER)(315, &__android_init_namespaces, 1),
  ELFW(SYM_INITIALIZER)(348, &__android_create_namespace, 1),
  ELFW(SYM_INITIALIZER)(382, &__dlvsym, 1),
  ELFW(SYM_INITIALIZER)(398, &__android_dlwarning, 1),
#if defined(__arm__)
  ELFW(SYM_INITIALIZER)(425, &__dl_unwind_find_exidx, 1),
#endif
};

// Fake out a hash table with a single bucket.
//
// A search of the hash table will look through g_libdl_symtab starting with index 1, then
// use g_libdl_chains to find the next index to look at. g_libdl_chains should be set up to
// walk through every element in g_libdl_symtab, and then end with 0 (sentinel value).
//
// That is, g_libdl_chains should look like { 0, 2, 3, ... N, 0 } where N is the number
// of actual symbols, or nelems(g_libdl_symtab)-1 (since the first element of g_libdl_symtab is not
// a real symbol). (See soinfo_elf_lookup().)
//
// Note that adding any new symbols here requires stubbing them out in libdl.
static unsigned g_libdl_buckets[1] = { 1 };
#if defined(__arm__)
static unsigned g_libdl_chains[] = { 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0 };
#else
static unsigned g_libdl_chains[] = { 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0 };
#endif

static uint8_t __libdl_info_buf[sizeof(soinfo)] __attribute__((aligned(8)));
static soinfo* __libdl_info = nullptr;

// This is used by the dynamic linker. Every process gets these symbols for free.
soinfo* get_libdl_info(const char* linker_path) {
  if (__libdl_info == nullptr) {
    __libdl_info = new (__libdl_info_buf) soinfo(&g_default_namespace, linker_path, nullptr, 0, 0);
    __libdl_info->flags_ |= FLAG_LINKED;
    __libdl_info->strtab_ = ANDROID_LIBDL_STRTAB;
    __libdl_info->symtab_ = g_libdl_symtab;
    __libdl_info->nbucket_ = sizeof(g_libdl_buckets)/sizeof(unsigned);
    __libdl_info->nchain_ = sizeof(g_libdl_chains)/sizeof(unsigned);
    __libdl_info->bucket_ = g_libdl_buckets;
    __libdl_info->chain_ = g_libdl_chains;
    __libdl_info->ref_count_ = 1;
    __libdl_info->strtab_size_ = sizeof(ANDROID_LIBDL_STRTAB);
    __libdl_info->local_group_root_ = __libdl_info;
    __libdl_info->soname_ = "ld-android.so";
    __libdl_info->target_sdk_version_ = __ANDROID_API__;
    __libdl_info->generate_handle();
#if defined(__work_around_b_24465209__)
    strlcpy(__libdl_info->old_name_, __libdl_info->soname_, sizeof(__libdl_info->old_name_));
#endif
  }

  return __libdl_info;
}
