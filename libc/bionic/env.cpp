/*
 * Copyright (c) 1987, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "private/ScopedRWLock.h"

static pthread_rwlock_t g_environ_lock = PTHREAD_RWLOCK_INITIALIZER;

// Returns a pointer to the value associated with name,
// or nullptr if not found.
// Starts searching environ from *offset,
// and sets *offset to the index at which the variable was found.
static char* __findenv(const char* name, size_t name_length, size_t* offset) {
  if (environ != nullptr) {
    for (char** p = environ + *offset; *p != nullptr; ++p) {
      if (!strncmp(name, *p, name_length) && (*p)[name_length] == '=') {
        *offset = p - environ;
        return *p + name_length + 1;
      }
    }
  }
  return nullptr;
}

char* getenv(const char* name) {
  size_t name_length;
  if (name == nullptr ||
      (name_length = strchrnul(name, '=') - name) == 0 ||
      name[name_length] == '=') {
    errno = EINVAL;
    return nullptr;
  }

  ScopedReadLock locker(&g_environ_lock);
  size_t offset = 0;
  return __findenv(name, name_length, &offset);
}

static bool __add_new_environ_slot(size_t* offset) {
  size_t old_size = 0;
  if (environ != nullptr) {
    char** p = environ;
    for (; *p != nullptr; ++p) ++old_size;
  }

  // Keep track of the most recent environ allocation we did.
  // We can't just pass environ to reallocarray() because that might
  // have been replaced with non-heap-allocated memory. Supporting that
  // is probably a mistake, but it's our (and everyone else's) historical
  // behavior.
  static char** old_env = nullptr;

  char** new_env = static_cast<char**>(reallocarray(old_env, old_size + 2, sizeof(char*)));
  if (!new_env) return false;
  if (old_env != environ && environ != nullptr) {
    memcpy(new_env, environ, old_size * sizeof(char*));
  }
  environ = old_env = new_env;
  environ[old_size] = environ[old_size + 1] = nullptr;
  *offset = old_size;
  return true;
}

template <typename F>
static int __update_environ(const char* name, size_t name_length, bool overwrite, F string_maker) {
  size_t offset = 0;
  if (__findenv(name, name_length, &offset) != nullptr) {
    if (!overwrite) return 0;
  } else {
    if (!__add_new_environ_slot(&offset)) return -1;
  }

  char* str = string_maker();
  environ[offset] = str;
  return str ? 0 : -1;
}

int putenv(char* str) {
  // Unlike the other functions where the input MUST NOT contain '=',
  // here the input MUST contain '='.
  size_t name_length;
  if (str == nullptr ||
      (name_length = strchrnul(str, '=') - str) == 0 ||
      str[name_length] != '=') {
    errno = EINVAL;
    return -1;
  }

  ScopedWriteLock locker(&g_environ_lock);
  return __update_environ(str, name_length, true, [str]() { return str; });
}

int setenv(const char* name, const char* value, int overwrite) {
  size_t name_length;
  if (name == nullptr ||
      (name_length = strchrnul(name, '=') - name) == 0 ||
      name[name_length] == '=') {
    errno = EINVAL;
    return -1;
  }

  ScopedWriteLock locker(&g_environ_lock);
  auto string_maker = [name, name_length, value]() {
    // Turn "name" and "value" into "name=value" for insertion into environ.
    size_t value_length = strlen(value);
    char* str = static_cast<char*>(malloc(name_length + 1 + value_length + 1));
    if (str != nullptr) {
      mempcpy(mempcpy(mempcpy(str, name, name_length), "=", 1), value, value_length + 1);
    }
    return str;
  };
  return __update_environ(name, name_length, overwrite, string_maker);
}

int unsetenv(const char* name) {
  size_t name_length;
  if (name == nullptr ||
      (name_length = strchrnul(name, '=') - name) == 0 ||
      name[name_length] == '=') {
    errno = EINVAL;
    return -1;
  }

  // While setenv()/putenv() will always ensure there's at most one assignment to any given name,
  // callers could replace environ with a malformed array.
  // getenv() wouldn't care because it will always stop at the first match,
  // but unsetenv() needs to make sure that _all_ assignments are removed.
  // POSIX says "If more than one string in an environment of a process has the same name,
  // the consequences are undefined" so this isn't _required_ to be a loop,
  // but it matches what other implementations do.
  ScopedWriteLock locker(&g_environ_lock);
  size_t offset = 0;
  while (__findenv(name, name_length, &offset)) {
    for (char** p = &environ[offset];; ++p) {
      if (!(*p = *(p + 1))) {
        break;
      }
    }
  }
  return 0;
}

int clearenv() {
  ScopedWriteLock locker(&g_environ_lock);
  char** old_environ = environ;
  environ = nullptr;
  if (old_environ != nullptr) {
    for (; *old_environ; ++old_environ) {
      *old_environ = nullptr;
    }
  }
  return 0;
}
