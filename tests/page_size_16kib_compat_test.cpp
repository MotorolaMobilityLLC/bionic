/*
 * Copyright (C) 2024 The Android Open Source Project
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

#if __has_include (<android/dlext_private.h>)
#define IS_ANDROID_DL
#endif

#include "page_size_compat_helpers.h"
#include "utils.h"

#include <android-base/parsebool.h>
#include <android-base/properties.h>
#include <android-base/silent_death_test.h>
#include <elfutils/elf-file.h>

#include <memory>
#include <vector>

using PageSize16KiBCompatTest_DeathTest = SilentDeathTest;
using ::android::base::ParseBool;
using ::android::base::ParseBoolResult;
using ::android::elfutils::ElfFile;
using ::android::elfutils::Elf64_File;

#if defined(IS_ANDROID_DL)
#include <android/dlext_private.h>
#endif

static inline std::string CompatMode() {
  return android::base::GetProperty("bionic.linker.16kb.app_compat.enabled", "false");
}

static inline bool CompatModeDisabled(const std::string& compat_mode) {
  return ParseBool(compat_mode) == ParseBoolResult::kFalse;
}

static inline bool CompatModeEnabled(const std::string& compat_mode) {
  return ParseBool(compat_mode) == ParseBoolResult::kTrue;
}

static inline bool CompatModeFatal(const std::string& compat_mode) {
  return compat_mode == "fatal";
}

static inline std::string TestLibPath() {
  return GetTestLibRoot() + "/libtest_elf_max_page_size_4kib.so";
}

TEST(PageSize16KiBCompatTest, ElfAlignment4KiB_LoadElf) {
  if (getpagesize() != 0x4000) {
    GTEST_SKIP() << "This test is only applicable to 16kB page-size devices";
  }

  std::string compat_mode = CompatMode();
  if (CompatModeFatal(compat_mode)) {
    GTEST_SKIP() << "This test is only applicable if dlopen() errors are not fatal";
  }

  std::string lib = TestLibPath();
  void* handle = nullptr;

  OpenTestLibrary(lib, CompatModeDisabled(compat_mode), &handle);

  if (CompatModeEnabled(compat_mode)) CallTestFunction(handle);
}

TEST(PageSize16KiBCompatTest, RWX_MiddlePageProtection) {
  if (getpagesize() != 0x4000) {
    GTEST_SKIP() << "This test is only applicable to 16kB page-size devices";
  }
  std::string compat_mode = CompatMode();
  if (!CompatModeEnabled(compat_mode)) {
    GTEST_SKIP() << "16kb appcompat mode is not enabled";
  }

  std::string lib = GetPrebuiltElfDir() + "/libtest_invalid-rx_rw_rx_padded.so";

  // Parse ELF to know the segments and their expected protections.
  std::unique_ptr<ElfFile> elf = ElfFile::create(lib);
  ASSERT_TRUE(elf != nullptr);
  ASSERT_TRUE(elf->is64Bit());
  ASSERT_TRUE(elf->parseProgramHeaders());

  std::unique_ptr<void, decltype(&dlclose)> handle(
      dlopen(lib.c_str(), RTLD_NOW), dlclose);
  ASSERT_NE(handle, nullptr) << "Failed to dlopen " << lib << ": " << dlerror();

  // Find load bias of the loaded library using dladdr on a known symbol.
  void* sym = dlsym(handle.get(), "loader_test_func");
  ASSERT_NE(sym, nullptr) << "Could not find loader_test_func in " << lib;
  Dl_info info;
  ASSERT_NE(dladdr(sym, &info), 0) << "dladdr failed for " << lib;
  uintptr_t load_bias = reinterpret_cast<uintptr_t>(info.dli_fbase);

  std::vector<map_record> maps;
  ASSERT_TRUE(Maps::parse_maps(&maps));

  auto get_map_for_address = [&](uintptr_t addr) -> const map_record* {
    for (const auto& map : maps) {
      if (addr >= map.addr_start && addr < map.addr_end) return &map;
    }
    return nullptr;
  };

  bool found_protected_middle_page = false;
  // Test success criteria:
  // - All pages that are not crossing segment boundaries should have their
  // - original permissions. Boundary pages should have the union of the
  // - permissions of the two overlapping segments.
  if (elf->is64Bit()) {
    Elf64_File* elf64 = static_cast<Elf64_File*>(elf.get());
    for (const auto& phdr : elf64->getPhdrs()) {
      if (phdr.p_type != PT_LOAD) continue;

      int expected_prot = MapPflagsToProtFlags(phdr.p_flags);

      uintptr_t seg_start = load_bias + phdr.p_vaddr;
      uintptr_t seg_end = seg_start + phdr.p_memsz;
      uintptr_t p_start = __builtin_align_up(seg_start, 0x4000);
      uintptr_t p_end = __builtin_align_down(seg_end, 0x4000);

      for (uintptr_t p = p_start; p < p_end; p += 0x4000) {
        const map_record* map = get_map_for_address(p);
        ASSERT_TRUE(map != nullptr)
            << "Could not find map for page at " << reinterpret_cast<void*>(p);
        EXPECT_EQ(map->perms, expected_prot)
            << "Page at " << reinterpret_cast<void*>(p)
            << " has incorrect perms: expected " << expected_prot
            << ", actual " << map->perms;
        if (map->perms == expected_prot) found_protected_middle_page = true;
      }
    }
  }

  EXPECT_TRUE(found_protected_middle_page)
      << "Failed to find any protected middle pages for " << lib;
}

TEST(PageSize16KiBCompatTest, ElfAlignment4KiB_NonAdajacentWritableSegments_LoadElf) {
  if (getpagesize() != 0x4000) {
    GTEST_SKIP() << "This test is only applicable to 16kB page-size devices";
  }

  std::string lib = GetPrebuiltElfDir() + "/libtest_invalid-rw_rx_rw_load_segments.so";
  std::string compat_mode = CompatMode();
  void* handle = nullptr;

  OpenTestLibrary(lib, CompatModeDisabled(compat_mode), &handle);
}

TEST(PageSize16KiBCompatTest,
     ElfAlignment4KiB_ExecutalbeSegmentsSeparatedByWritableSegment_LoadElf) {
  if (getpagesize() != 0x4000) {
    GTEST_SKIP() << "This test is only applicable to 16kB page-size devices";
  }

  std::string lib = GetPrebuiltElfDir() + "/libtest_invalid-rw_rx_rw_load_segments.so";
  std::string compat_mode = CompatMode();
  void* handle = nullptr;

  OpenTestLibrary(lib, CompatModeDisabled(compat_mode), &handle);
}

TEST(PageSize16KiBCompatTest, ElfAlignment4KiB_LoadElf_perAppOption) {
  if (getpagesize() != 0x4000) {
    GTEST_SKIP() << "This test is only applicable to 16kB page-size devices";
  }

  std::string compat_mode = CompatMode();
  if (CompatModeFatal(compat_mode)) {
    GTEST_SKIP() << "This test is only applicable if dlopen() errors are not fatal";
  }

#if defined(IS_ANDROID_DL)
  android_set_16kb_appcompat_mode(true);
#endif

  std::string lib = TestLibPath();
  void* handle = nullptr;

  OpenTestLibrary(lib, false /*should_fail*/, &handle);
  CallTestFunction(handle);

#if defined(IS_ANDROID_DL)
  android_set_16kb_appcompat_mode(false);
#endif
}

static void FatalDlError() {
  std::string lib = TestLibPath();
  void* handle = nullptr;

  OpenTestLibrary(lib, true /*should_fail*/, &handle);
}

TEST(PageSize16KiBCompatTest_DeathTest, AppDlopenErrIsFatal) {
  if (getpagesize() != 0x4000) {
    GTEST_SKIP() << "This test is only applicable to 16kB page-size devices";
  }

  std::string compat_mode = CompatMode();
  if (!CompatModeFatal(compat_mode)) {
    GTEST_SKIP() << "This test is only applicable if dlopen() errors are fatal";
  }

  ASSERT_EXIT(FatalDlError(), testing::KilledBySignal(SIGABRT),
              ".*program alignment (.*) cannot be smaller than system page size.*");
}

TEST(PageSize16KiBCompatTest, RELRO_Protection) {
  if (getpagesize() != 0x4000) {
    GTEST_SKIP() << "This test is only applicable to 16kB page-size devices";
  }

  std::string compat_mode = CompatMode();
  if (!CompatModeEnabled(compat_mode)) {
    GTEST_SKIP() << "16kb appcompat mode is not enabled (bionic.linker.16kb.app_compat.enabled="
                 << compat_mode << ")";
  }

  std::string lib = TestLibPath();
  void* handle = dlopen(lib.c_str(), RTLD_NOW);
  ASSERT_NE(handle, nullptr) << dlerror();

  // Find the address of the RELRO table
  void* relro_addr = dlsym(handle, "big_relro_table");
  ASSERT_NE(relro_addr, nullptr) << dlerror();

  std::vector<map_record> maps;
  ASSERT_TRUE(Maps::parse_maps(&maps));

  bool found_relro_map = false;
  uintptr_t addr = reinterpret_cast<uintptr_t>(relro_addr);
  for (const auto& map : maps) {
    if (addr >= map.addr_start && addr < map.addr_end) {
      found_relro_map = true;
      EXPECT_FALSE(map.perms & PROT_WRITE)
          << "RELRO area at " << relro_addr << " should not be writable";
      break;
    }
  }

  EXPECT_TRUE(found_relro_map) << "Could not find map for RELRO area";

  dlclose(handle);
}
