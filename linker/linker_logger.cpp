/*
 * Copyright (C) 2016 The Android Open Source Project
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

#include <string.h>
#include <sys/prctl.h>
#include <sys/system_properties.h>
#include <unistd.h>

#include <string>
#include <vector>

#include "android-base/strings.h"
#include "linker_logger.h"
#include "private/libc_logging.h"

LinkerLogger g_linker_logger;

static const char* kSystemLdDebugProperty = "debug.ld.all";
static const char* kLdDebugPropertyPrefix = "debug.ld.app.";

static const char* kOptionErrors = "dlerror";
static const char* kOptionDlopen = "dlopen";
static const char* kOptionDlsym = "dlsym";

static std::string property_get(const char* name) {
  char value[PROP_VALUE_MAX] = {};
  __system_property_get(name, value);
  return value;
}

static uint32_t ParseProperty(const std::string& value) {
  if (value.empty()) {
    return 0;
  }

  std::vector<std::string> options = android::base::Split(value, ",");

  uint32_t flags = 0;

  for (const auto& o : options) {
    if (o == kOptionErrors) {
      flags |= kLogErrors;
    } else if (o == kOptionDlopen){
      flags |= kLogDlopen;
    } else if (o == kOptionDlsym){
      flags |= kLogDlsym;
    } else {
      __libc_format_log(ANDROID_LOG_WARN, "linker", "Unknown debug.ld option \"%s\", will ignore.", o.c_str());
    }
  }

  return flags;
}

void LinkerLogger::ResetState() {
  // the most likely scenario app is not debuggable and
  // is running on user build - the logging is disabled.
  if (prctl(PR_GET_DUMPABLE, 0, 0, 0, 0) == 0) {
    return;
  }

  flags_ = 0;
  // check flag applied to all processes first
  std::string value = property_get(kSystemLdDebugProperty);
  flags_ |= ParseProperty(value);

  // get process basename
  std::string process_name = basename(g_argv[0]);

  std::string property_name = std::string(kLdDebugPropertyPrefix) + process_name;

  // Property names are limited to PROP_NAME_MAX.

  if (property_name.size() >= PROP_NAME_MAX) {
    size_t count = PROP_NAME_MAX - 1;
    // remove trailing dots...
    while (property_name[count-1] == '.') {
      --count;
    }

    property_name = property_name.substr(0, count);
  }
  value = property_get(property_name.c_str());
  flags_ |= ParseProperty(value);
}

void LinkerLogger::Log(uint32_t type, const char* format, ...) {
  if ((flags_ & type) == 0) {
    return;
  }

  va_list ap;
  va_start(ap, format);
  __libc_format_log_va_list(ANDROID_LOG_DEBUG, "linker", format, ap);
  va_end(ap);
}

