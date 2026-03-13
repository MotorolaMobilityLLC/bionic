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

static char** lastenv;        /* last value of environ */

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

  size_t offset = 0;
  return __findenv(name, name_length, &offset);
}

static size_t __current_env_size() {
  size_t result = 0;
  if (environ != nullptr) {
    char** p = environ;
    for (; *p != nullptr; ++p) ++result;
  }
  return result;
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

  size_t offset = 0;
  if (__findenv(str, name_length, &offset) != nullptr) {
    environ[offset++] = str;
    return 0;
  }

  /* create new slot for string */
  size_t cnt = __current_env_size();
  char** p = static_cast<char**>(reallocarray(lastenv, cnt + 2, sizeof(char*)));
  if (!p) {
    return -1;
  }
  if (lastenv != environ && environ != nullptr) {
    memcpy(p, environ, cnt * sizeof(char*));
  }
  lastenv = environ = p;
  environ[cnt] = str;
  environ[cnt + 1] = nullptr;
  return 0;
}

int setenv(const char* name, const char* value, int rewrite) {
  size_t name_length;
  if (name == nullptr ||
      (name_length = strchrnul(name, '=') - name) == 0 ||
      name[name_length] == '=') {
    errno = EINVAL;
    return -1;
  }

  size_t offset = 0;
  if (__findenv(name, name_length, &offset) != nullptr) {
    if (!rewrite) return 0;
  } else {          /* create new slot */
    size_t cnt = __current_env_size();
    char** p = static_cast<char**>(reallocarray(lastenv, cnt + 2, sizeof(char*)));
    if (!p) {
      return -1;
    }
    if (lastenv != environ && environ != nullptr) {
      memcpy(p, environ, cnt * sizeof(char*));
    }
    lastenv = environ = p;
    offset = cnt;
    environ[cnt + 1] = nullptr;
  }

  // Turn "name" and "value" into "name=value" for insertion into environ.
  size_t value_length = strlen(value);
  char* str = static_cast<char*>(malloc(name_length + 1 + value_length + 1));
  if (str == nullptr) return -1;
  mempcpy(mempcpy(mempcpy(str, name, name_length), "=", 1), value, value_length + 1);

  environ[offset] = str;
  return 0;
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
  // TODO: this should also set environ itself to null
  // TODO: add missing test
  char** e = environ;
  if (e != nullptr) {
    for (; *e; ++e) {
      *e = nullptr;
    }
  }
  return 0;
}
