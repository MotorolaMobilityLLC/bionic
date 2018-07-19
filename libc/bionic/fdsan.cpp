/*
 * Copyright (C) 2018 The Android Open Source Project
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

#include <android/fdsan.h>

#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <string.h>
#include <sys/cdefs.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <async_safe/log.h>
#include <sys/system_properties.h>

#include "private/bionic_globals.h"
#include "pthread_internal.h"

extern "C" int ___close(int fd);
pid_t __get_cached_pid();

static constexpr const char* kFdsanPropertyName = "debug.fdsan";

void __libc_init_fdsan() {
  const prop_info* pi = __system_property_find(kFdsanPropertyName);
  if (!pi) {
    android_fdsan_set_error_level(ANDROID_FDSAN_ERROR_LEVEL_DISABLED);
    return;
  }
  __system_property_read_callback(
      pi,
      [](void*, const char*, const char* value, uint32_t) {
        if (strcasecmp(value, "1") == 0 || strcasecmp(value, "fatal") == 0) {
          android_fdsan_set_error_level(ANDROID_FDSAN_ERROR_LEVEL_FATAL);
        } else if (strcasecmp(value, "warn") == 0) {
          android_fdsan_set_error_level(ANDROID_FDSAN_ERROR_LEVEL_WARN_ALWAYS);
        } else if (strcasecmp(value, "warn_once") == 0) {
          android_fdsan_set_error_level(ANDROID_FDSAN_ERROR_LEVEL_WARN_ONCE);
        } else {
          if (strlen(value) != 0 && strcasecmp(value, "0") != 0) {
            async_safe_format_log(ANDROID_LOG_ERROR, "libc",
                                  "debug.fdsan set to unknown value '%s', disabling", value);
          }
          android_fdsan_set_error_level(ANDROID_FDSAN_ERROR_LEVEL_DISABLED);
        }
      },
      nullptr);
}

static FdTable<128>* GetFdTable() {
  if (!__libc_shared_globals) {
    return nullptr;
  }

  return &__libc_shared_globals->fd_table;
}

static FdEntry* GetFdEntry(int fd) {
  if (fd < 0) {
    return nullptr;
  }

  auto* fd_table = GetFdTable();
  if (!fd_table) {
    return nullptr;
  }

  return fd_table->at(fd);
}

__printflike(1, 0) static void fdsan_error(const char* fmt, ...) {
  auto* fd_table = GetFdTable();
  if (!fd_table) {
    return;
  }

  auto error_level = atomic_load(&fd_table->error_level);
  if (error_level == ANDROID_FDSAN_ERROR_LEVEL_DISABLED) {
    return;
  }

  // Lots of code will (sensibly) fork, blindly call close on all of their fds,
  // and then exec. Compare our cached pid value against the real one to detect
  // this scenario and permit it.
  pid_t cached_pid = __get_cached_pid();
  if (cached_pid == 0 || cached_pid != syscall(__NR_getpid)) {
    return;
  }

  va_list va;
  va_start(va, fmt);
  async_safe_fatal_va_list("fdsan", fmt, va);
  va_end(va);

  switch (error_level) {
    case ANDROID_FDSAN_ERROR_LEVEL_WARN_ONCE:
      atomic_compare_exchange_strong(&fd_table->error_level, &error_level,
                                     ANDROID_FDSAN_ERROR_LEVEL_DISABLED);
      break;

    case ANDROID_FDSAN_ERROR_LEVEL_FATAL:
      abort();

    case ANDROID_FDSAN_ERROR_LEVEL_DISABLED:
    case ANDROID_FDSAN_ERROR_LEVEL_WARN_ALWAYS:
      break;
  }
}

uint64_t android_fdsan_create_owner_tag(android_fdsan_owner_type type, uint64_t tag) {
  if (tag == 0) {
    return 0;
  }

  if (__predict_false((type & 0xff) != type)) {
    async_safe_fatal("invalid android_fdsan_owner_type value: %x", type);
  }

  uint64_t result = static_cast<uint64_t>(type) << 56;
  uint64_t mask = (static_cast<uint64_t>(1) << 56) - 1;
  result |= tag & mask;
  return result;
}

static const char* __tag_to_type(uint64_t tag) {
  uint64_t type = tag >> 56;
  switch (type) {
    case ANDROID_FDSAN_OWNER_TYPE_FILE:
      return "FILE*";
    case ANDROID_FDSAN_OWNER_TYPE_DIR:
      return "DIR*";
    case ANDROID_FDSAN_OWNER_TYPE_UNIQUE_FD:
      return "unique_fd";
    case ANDROID_FDSAN_OWNER_TYPE_FILEINPUTSTREAM:
      return "FileInputStream";
    case ANDROID_FDSAN_OWNER_TYPE_FILEOUTPUTSTREAM:
      return "FileOutputStream";
    case ANDROID_FDSAN_OWNER_TYPE_RANDOMACCESSFILE:
      return "RandomAccessFile";
    case ANDROID_FDSAN_OWNER_TYPE_PARCELFILEDESCRIPTOR:
      return "ParcelFileDescriptor";

    case ANDROID_FDSAN_OWNER_TYPE_GENERIC_00:
    default:
      return "native object of unknown type";

    case ANDROID_FDSAN_OWNER_TYPE_GENERIC_FF:
      // If bits 48 to 56 are set, this is a sign-extended generic native pointer
      uint64_t high_bits = tag >> 48;
      if (high_bits == (1 << 16) - 1) {
        return "native object of unknown type";
      }

      return "Java object of unknown type";
  }
}

static uint64_t __tag_to_owner(uint64_t tag) {
  return tag;
}

int android_fdsan_close_with_tag(int fd, uint64_t expected_tag) {
  FdEntry* fde = GetFdEntry(fd);
  if (!fde) {
    return ___close(fd);
  }

  uint64_t tag = expected_tag;
  if (!atomic_compare_exchange_strong(&fde->close_tag, &tag, 0)) {
    const char* expected_type = __tag_to_type(expected_tag);
    uint64_t expected_owner = __tag_to_owner(expected_tag);
    const char* actual_type = __tag_to_type(tag);
    uint64_t actual_owner = __tag_to_owner(tag);
    if (expected_tag && tag) {
      fdsan_error("attempted to close file descriptor %d, expected to be owned by %s 0x%" PRIx64
                  ", actually owned by %s 0x%" PRIx64,
                  fd, expected_type, expected_owner, actual_type, actual_owner);
    } else if (expected_tag && !tag) {
      fdsan_error("attempted to close file descriptor %d, expected to be owned by %s 0x%" PRIx64
                  ", actually unowned",
                  fd, expected_type, expected_owner);
    } else if (!expected_tag && tag) {
      fdsan_error(
          "attempted to close file descriptor %d, expected to be unowned, actually owned by %s "
          "0x%" PRIx64,
          fd, actual_type, actual_owner);
    } else if (!expected_tag && !tag) {
      // This should never happen: our CAS failed, but expected == actual?
      async_safe_fatal("fdsan atomic_compare_exchange_strong failed unexpectedly");
    }
  }

  int rc = ___close(fd);
  // If we were expecting to close with a tag, abort on EBADF.
  if (expected_tag && rc == -1 && errno == EBADF) {
    fdsan_error("double-close of file descriptor %d detected", fd);
  }
  return rc;
}

void android_fdsan_exchange_owner_tag(int fd, uint64_t expected_tag, uint64_t new_tag) {
  FdEntry* fde = GetFdEntry(fd);
  if (!fde) {
    return;
  }

  uint64_t tag = expected_tag;
  if (!atomic_compare_exchange_strong(&fde->close_tag, &tag, new_tag)) {
    if (expected_tag == 0) {
      fdsan_error(
          "failed to take ownership of already-owned file descriptor: fd %d is owned by %s "
          "%" PRIx64,
          fd, __tag_to_type(tag), __tag_to_owner(tag));
    } else {
      fdsan_error(
          "failed to exchange ownership of unowned file descriptor: expected fd %d to be owned "
          "by %s %" PRIx64,
          fd, __tag_to_type(expected_tag), __tag_to_owner(expected_tag));
    }
  }
}

android_fdsan_error_level android_fdsan_get_error_level() {
  auto* fd_table = GetFdTable();
  if (!fd_table) {
    async_safe_fatal("attempted to get fdsan error level before libc initialization?");
  }

  return fd_table->error_level;
}

android_fdsan_error_level android_fdsan_set_error_level(android_fdsan_error_level new_level) {
  auto* fd_table = GetFdTable();
  if (!fd_table) {
    async_safe_fatal("attempted to get fdsan error level before libc initialization?");
  }

  return atomic_exchange(&fd_table->error_level, new_level);
}

int close(int fd) {
  int rc = android_fdsan_close_with_tag(fd, 0);
  if (rc == -1 && errno == EINTR) {
    return 0;
  }
  return rc;
}
