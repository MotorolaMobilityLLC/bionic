#
# Copyright (C) 2013 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)

# -----------------------------------------------------------------------------
# Benchmarks library, usable by projects outside this directory.
# -----------------------------------------------------------------------------

include $(CLEAR_VARS)
LOCAL_MODULE := libbenchmark
LOCAL_CFLAGS += -O2 -Wall -Wextra -Werror
LOCAL_SRC_FILES := benchmark_main.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/include
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libbenchmark
LOCAL_CFLAGS += -O2 -Wall -Wextra -Werror
LOCAL_SRC_FILES := benchmark_main.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/include
LOCAL_MULTILIB := both
include $(BUILD_HOST_STATIC_LIBRARY)

# -----------------------------------------------------------------------------
# Benchmarks.
# -----------------------------------------------------------------------------

benchmark_c_flags = \
    -O2 \
    -Wall -Wextra -Wunused \
    -Werror \
    -fno-builtin \
    -std=gnu++11 \

benchmark_src_files = \
    math_benchmark.cpp \
    pthread_benchmark.cpp \
    semaphore_benchmark.cpp \
    stdio_benchmark.cpp \
    string_benchmark.cpp \
    time_benchmark.cpp \
    unistd_benchmark.cpp \

# Build benchmarks for the device (with bionic's .so). Run with:
#   adb shell bionic-benchmarks32
#   adb shell bionic-benchmarks64
include $(CLEAR_VARS)
LOCAL_MODULE := bionic-benchmarks
LOCAL_MODULE_STEM_32 := bionic-benchmarks32
LOCAL_MODULE_STEM_64 := bionic-benchmarks64
LOCAL_MULTILIB := both
LOCAL_CFLAGS += $(benchmark_c_flags)
LOCAL_SRC_FILES := $(benchmark_src_files) property_benchmark.cpp
LOCAL_STATIC_LIBRARIES += libbenchmark
include $(BUILD_EXECUTABLE)

# We don't build a static benchmark executable because it's not usually
# useful. If you're trying to run the current benchmarks on an older
# release, it's (so far at least) always because you want to measure the
# performance of the old release's libc, and a static benchmark isn't
# going to let you do that.

# Build benchmarks for the host (against glibc!). Run with:
include $(CLEAR_VARS)
LOCAL_MODULE := bionic-benchmarks-glibc
LOCAL_MODULE_STEM_32 := bionic-benchmarks-glibc32
LOCAL_MODULE_STEM_64 := bionic-benchmarks-glibc64
LOCAL_MULTILIB := both
LOCAL_CFLAGS += $(benchmark_c_flags)
LOCAL_LDFLAGS += -lrt
LOCAL_SRC_FILES := $(benchmark_src_files)
LOCAL_STATIC_LIBRARIES += libbenchmark
include $(BUILD_HOST_EXECUTABLE)

ifeq ($(HOST_OS)-$(HOST_ARCH),$(filter $(HOST_OS)-$(HOST_ARCH),linux-x86 linux-x86_64))
include $(LOCAL_PATH)/../build/run-on-host.mk

ifeq ($(TARGET_ARCH),$(filter $(TARGET_ARCH),x86 x86_64))
bionic-benchmarks-run-on-host32: bionic-benchmarks bionic-prepare-run-on-host
	ANDROID_DATA=$(TARGET_OUT_DATA) \
	ANDROID_ROOT=$(TARGET_OUT) \
		$(TARGET_OUT_EXECUTABLES)/bionic-benchmarks32 $(BIONIC_BENCHMARKS_FLAGS)
endif

ifeq ($(TARGET_IS_64_BIT),true)
bionic-benchmarks-run-on-host64: bionic-benchmarks bionic-prepare-run-on-host
	ANDROID_DATA=$(TARGET_OUT_DATA) \
	ANDROID_ROOT=$(TARGET_OUT) \
		$(TARGET_OUT_EXECUTABLES)/bionic-benchmarks64 $(BIONIC_BENCHMARKS_FLAGS)
endif

endif
