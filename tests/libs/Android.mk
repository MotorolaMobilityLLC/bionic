#
# Copyright (C) 2012 The Android Open Source Project
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
TEST_PATH := $(LOCAL_PATH)/..

common_cppflags += -std=gnu++11
# -----------------------------------------------------------------------------
# Library used by dlfcn tests.
# -----------------------------------------------------------------------------
ifneq ($(TARGET_ARCH),$(filter $(TARGET_ARCH),mips mips64))
no-elf-hash-table-library_src_files := \
    empty.cpp \

no-elf-hash-table-library_ldflags := \
    -Wl,--hash-style=gnu \

module := no-elf-hash-table-library
module_tag := optional
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk
endif

# -----------------------------------------------------------------------------
# Library used by dlext tests - with GNU RELRO program header
# -----------------------------------------------------------------------------
libdlext_test_src_files := \
    dlext_test_library.cpp \

libdlext_test_ldflags := \
    -Wl,-z,relro \

module := libdlext_test
module_tag := optional
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# create symlink to libdlext_test.so for symlink test
# -----------------------------------------------------------------------------
# Use = instead of := to defer the evaluation of $@
$(LOCAL_INSTALLED_MODULE): PRIVATE_POST_INSTALL_CMD = \
    $(hide) cd $(dir $@) && ln -sf $(notdir $@) libdlext_test_v2.so

ifneq ($(TARGET_2ND_ARCH),)
# link 64 bit .so
$(TARGET_OUT)/lib64/libdlext_test.so: PRIVATE_POST_INSTALL_CMD = \
    $(hide) cd $(dir $@) && ln -sf $(notdir $@) libdlext_test_v2.so
endif

# -----------------------------------------------------------------------------
# Library used by dlext tests - without GNU RELRO program header
# -----------------------------------------------------------------------------
libdlext_test_norelro_src_files := \
    dlext_test_library.cpp \

libdlext_test_norelro_ldflags := \
    -Wl,-z,norelro \

module := libdlext_test_norelro
module_tag := optional
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# Library used by dlext tests - different name non-default location
# -----------------------------------------------------------------------------
libdlext_test_fd_src_files := \
    dlext_test_library.cpp \

libdlext_test_fd_install_to_out_data := true
module := libdlext_test_fd
module_tag := optional
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# Library used by dlfcn tests
# -----------------------------------------------------------------------------
libtest_simple_src_files := \
    dlopen_testlib_simple.cpp

module := libtest_simple
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# Libraries used by dlfcn tests to verify correct load order:
# libtest_check_order_2_right.so
# -----------------------------------------------------------------------------
libtest_check_order_2_right_src_files := \
    dlopen_testlib_answer.cpp

libtest_check_order_2_right_cflags := -D__ANSWER=42
module := libtest_check_order_2_right
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_check_order_a.so
# -----------------------------------------------------------------------------
libtest_check_order_a_src_files := \
    dlopen_testlib_answer.cpp

libtest_check_order_a_cflags := -D__ANSWER=1
module := libtest_check_order_a
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_check_order_b.so
# -----------------------------------------------------------------------------
libtest_check_order_b_src_files := \
    dlopen_testlib_answer.cpp

libtest_check_order_b_cflags := -D__ANSWER=2 -D__ANSWER2=43
module := libtest_check_order_b
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_check_order_c.so
# -----------------------------------------------------------------------------
libtest_check_order_3_c_src_files := \
    dlopen_testlib_answer.cpp

libtest_check_order_3_c_cflags := -D__ANSWER=3
module := libtest_check_order_3_c
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_check_order_d.so
# -----------------------------------------------------------------------------
libtest_check_order_d_src_files := \
   dlopen_testlib_answer.cpp

libtest_check_order_d_shared_libraries := libtest_check_order_b
libtest_check_order_d_cflags := -D__ANSWER=4 -D__ANSWER2=4
module := libtest_check_order_d
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_check_order_left.so
# -----------------------------------------------------------------------------
libtest_check_order_1_left_src_files := \
    empty.cpp

libtest_check_order_1_left_shared_libraries := libtest_check_order_a libtest_check_order_b

module := libtest_check_order_1_left
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_check_order.so
# -----------------------------------------------------------------------------
libtest_check_order_src_files := \
    empty.cpp

libtest_check_order_shared_libraries := libtest_check_order_1_left \
  libtest_check_order_2_right libtest_check_order_3_c

module := libtest_check_order
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# Library with dependency loop used by dlfcn tests
#
# libtest_with_dependency_loop -> a -> b -> c -> a
# -----------------------------------------------------------------------------
libtest_with_dependency_loop_src_files := empty.cpp

libtest_with_dependency_loop_shared_libraries := \
    libtest_with_dependency_loop_a

module := libtest_with_dependency_loop
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_with_dependency_loop_a.so
# -----------------------------------------------------------------------------
libtest_with_dependency_loop_a_src_files := empty.cpp

libtest_with_dependency_loop_a_shared_libraries := \
    libtest_with_dependency_loop_b_tmp

module := libtest_with_dependency_loop_a
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_with_dependency_loop_b.so
#
# this is temporary placeholder - will be removed
# -----------------------------------------------------------------------------
libtest_with_dependency_loop_b_tmp_src_files := empty.cpp
libtest_with_dependency_loop_b_tmp_ldflags := -Wl,-soname=libtest_with_dependency_loop_b.so

module := libtest_with_dependency_loop_b_tmp
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_with_dependency_loop_b.so
# -----------------------------------------------------------------------------
libtest_with_dependency_loop_b_src_files := empty.cpp
libtest_with_dependency_loop_b_shared_libraries := libtest_with_dependency_loop_c

module := libtest_with_dependency_loop_b
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_with_dependency_loop_c.so
# -----------------------------------------------------------------------------
libtest_with_dependency_loop_c_src_files := empty.cpp

libtest_with_dependency_loop_c_shared_libraries := \
    libtest_with_dependency_loop_a

module := libtest_with_dependency_loop_c
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# libtest_relo_check_dt_needed_order.so
# |
# +-> libtest_relo_check_dt_needed_order_1.so
# |
# +-> libtest_relo_check_dt_needed_order_2.so
# -----------------------------------------------------------------------------
libtest_relo_check_dt_needed_order_shared_libraries := \
    libtest_relo_check_dt_needed_order_1 libtest_relo_check_dt_needed_order_2

libtest_relo_check_dt_needed_order_src_files := dlopen_testlib_relo_check_dt_needed_order.cpp
libtest_relo_check_dt_needed_order_1_src_files := dlopen_testlib_relo_check_dt_needed_order_1.cpp
libtest_relo_check_dt_needed_order_2_src_files := dlopen_testlib_relo_check_dt_needed_order_2.cpp
build_type := target
build_target := SHARED_LIBRARY

module := libtest_relo_check_dt_needed_order
include $(TEST_PATH)/Android.build.mk
module := libtest_relo_check_dt_needed_order_1
include $(TEST_PATH)/Android.build.mk
module := libtest_relo_check_dt_needed_order_2
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# Library with dependency used by dlfcn tests
# -----------------------------------------------------------------------------
libtest_with_dependency_src_files := \
    dlopen_testlib_simple.cpp

libtest_with_dependency_shared_libraries := libdlext_test

module := libtest_with_dependency
build_type := target
build_target := SHARED_LIBRARY
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# Library used by ifunc tests
# -----------------------------------------------------------------------------
ifeq ($(TARGET_ARCH),$(filter $(TARGET_ARCH),x86 x86_64))
    libtest_ifunc_src_files := \
        dlopen_testlib_ifunc.c

    LOCAL_SDK_VERSION := current
    module := libtest_ifunc
    build_type := target
    build_target := SHARED_LIBRARY
    include $(TEST_PATH)/Android.build.mk
endif

# -----------------------------------------------------------------------------
# Library used by atexit tests
# -----------------------------------------------------------------------------

libtest_atexit_src_files := \
    atexit_testlib.cpp

module := libtest_atexit
build_target := SHARED_LIBRARY
build_type := target
include $(TEST_PATH)/Android.build.mk
build_type := host
include $(TEST_PATH)/Android.build.mk

# -----------------------------------------------------------------------------
# Library with weak function
# -----------------------------------------------------------------------------
libtest_dlsym_weak_func_src_files := \
    dlsym_weak_function.cpp

module := libtest_dlsym_weak_func
build_target := SHARED_LIBRARY
build_type := target
include $(TEST_PATH)/Android.build.mk
build_type := host
include $(TEST_PATH)/Android.build.mk
