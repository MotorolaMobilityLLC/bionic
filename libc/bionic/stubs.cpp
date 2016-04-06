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

#include <netdb.h>
#include <unistd.h>

// We don't have an /etc/networks, so all inputs return NULL.
netent* getnetbyname(const char* /*name*/) {
  return NULL;
}

// We don't have an /etc/networks, so all inputs return NULL.
netent* getnetbyaddr(uint32_t /*net*/, int /*type*/) {
  return NULL;
}

// We don't have an /etc/protocols, so all inputs return NULL.
protoent* getprotobyname(const char* /*name*/) {
  return NULL;
}

// We don't have an /etc/protocols, so all inputs return NULL.
protoent* getprotobynumber(int /*proto*/) {
  return NULL;
}

// Portable code should use sysconf(_SC_PAGE_SIZE) directly instead.
int getpagesize() {
  // We dont use sysconf(3) here because that drags in stdio, which makes static binaries fat.
  return PAGE_SIZE;
}
