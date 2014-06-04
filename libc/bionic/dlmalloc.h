/*
 * Copyright (C) 2012 The Android Open Source Project
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

#ifndef LIBC_BIONIC_DLMALLOC_H_
#define LIBC_BIONIC_DLMALLOC_H_

#include <sys/cdefs.h>
#include <stddef.h>

/* Configure dlmalloc. */
#define HAVE_GETPAGESIZE 1
#define MALLOC_INSPECT_ALL 1
#define MSPACES 0
#define REALLOC_ZERO_BYTES_FREES 1
#define USE_DL_PREFIX 1
#define USE_LOCKS 1
#define LOCK_AT_FORK 1
#define USE_RECURSIVE_LOCK 0
#define USE_SPIN_LOCKS 0
#define DEFAULT_MMAP_THRESHOLD (64U * 1024U)

__BEGIN_DECLS

/* Export two symbols used by the VM. */
int dlmalloc_trim(size_t) __LIBC_ABI_PUBLIC__;
void dlmalloc_inspect_all(void (*handler)(void*, void*, size_t, void*), void*) __LIBC_ABI_PUBLIC__;

/* NVIDIA's libglcore.so has a reference to dlmalloc_usable_size. TODO: remove this. */
size_t dlmalloc_usable_size(const void*) __LIBC_ABI_PUBLIC__;

__END_DECLS

/* Include the proper definitions. */
#include "../upstream-dlmalloc/malloc.h"

#endif  // LIBC_BIONIC_DLMALLOC_H_
