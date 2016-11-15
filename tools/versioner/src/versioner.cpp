/*
 * Copyright (C) 2016 The Android Open Source Project
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

#include <dirent.h>
#include <err.h>
#include <limits.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <atomic>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include <clang/AST/ASTConsumer.h>
#include <clang/Basic/TargetInfo.h>
#include <clang/Driver/Compilation.h>
#include <clang/Driver/Driver.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/CompilerInvocation.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Frontend/TextDiagnosticPrinter.h>
#include <clang/Frontend/Utils.h>
#include <clang/FrontendTool/Utils.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/ADT/StringRef.h>

#include <android-base/parseint.h>

#include "Arch.h"
#include "DeclarationDatabase.h"
#include "Preprocessor.h"
#include "SymbolDatabase.h"
#include "Utils.h"
#include "versioner.h"

using namespace std::string_literals;
using namespace clang;
using namespace tooling;

bool verbose;
static bool add_include;
static int max_thread_count = 48;

static std::vector<std::string> generateCompileCommand(CompilationType& type,
                                                       const std::string& filename,
                                                       const std::string& header_dir,
                                                       const std::vector<std::string>& include_dirs) {
  std::vector<std::string> cmd = { "versioner" };
  cmd.push_back("-std=c11");

  cmd.push_back("-Wall");
  cmd.push_back("-Wextra");
  cmd.push_back("-Werror");
  cmd.push_back("-Wundef");
  cmd.push_back("-Wno-unused-macros");
  cmd.push_back("-Wno-unused-function");
  cmd.push_back("-Wno-unused-variable");
  cmd.push_back("-Wno-unknown-attributes");
  cmd.push_back("-Wno-pragma-once-outside-header");

  cmd.push_back("-target");
  cmd.push_back(arch_targets[type.arch]);

  cmd.push_back("-DANDROID");
  cmd.push_back("-D__ANDROID_API__="s + std::to_string(type.api_level));
  cmd.push_back("-D_FORTIFY_SOURCE=2");
  cmd.push_back("-D_GNU_SOURCE");
  cmd.push_back("-D_FILE_OFFSET_BITS="s + std::to_string(type.file_offset_bits));

  cmd.push_back("-nostdinc");
  std::string header_path;
  if (add_include) {
    const char* top = getenv("ANDROID_BUILD_TOP");
    header_path = to_string(top) + "/bionic/libc/include/android/versioning.h";
    cmd.push_back("-include");
    cmd.push_back(header_path);
  }

  for (const auto& dir : include_dirs) {
    cmd.push_back("-isystem");
    cmd.push_back(dir);
  }

  cmd.push_back(filename);

  return cmd;
}

class VersionerASTConsumer : public clang::ASTConsumer {
 public:
  HeaderDatabase* header_database;
  CompilationType type;

  VersionerASTConsumer(HeaderDatabase* header_database, CompilationType type)
      : header_database(header_database), type(type) {
  }

  virtual void HandleTranslationUnit(ASTContext& ctx) override {
    header_database->parseAST(type, ctx);
  }
};

class VersionerASTAction : public clang::ASTFrontendAction {
 public:
  HeaderDatabase* header_database;
  CompilationType type;

  VersionerASTAction(HeaderDatabase* header_database, CompilationType type)
      : header_database(header_database), type(type) {
  }

  virtual std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance& Compiler,
                                                         llvm::StringRef InFile) override {
    return std::make_unique<VersionerASTConsumer>(header_database, type);
  }
};

static void compileHeader(HeaderDatabase* header_database, CompilationType type,
                          const std::string& filename, const std::string& header_dir,
                          const std::vector<std::string>& include_dirs) {
  DiagnosticOptions diagnostic_options;
  auto diagnostic_printer = new TextDiagnosticPrinter(llvm::errs(), &diagnostic_options);

  IntrusiveRefCntPtr<DiagnosticIDs> diagnostic_ids(new DiagnosticIDs());
  IntrusiveRefCntPtr<DiagnosticsEngine> diags(
      new DiagnosticsEngine(diagnostic_ids, &diagnostic_options, diagnostic_printer, false));
  driver::Driver Driver("versioner", llvm::sys::getDefaultTargetTriple(), *diags);

  std::vector<std::string> cmd = generateCompileCommand(type, filename, header_dir, include_dirs);
  llvm::SmallVector<const char*, 32> Args;

  for (const std::string& str : cmd) {
    Args.push_back(str.c_str());
  }

  std::unique_ptr<driver::Compilation> Compilation(Driver.BuildCompilation(Args));

  const driver::Command &Cmd = llvm::cast<driver::Command>(*Compilation->getJobs().begin());
  const driver::ArgStringList &CCArgs = Cmd.getArguments();

  auto invocation = std::make_unique<CompilerInvocation>();
  if (!CompilerInvocation::CreateFromArgs(
          *invocation.get(), const_cast<const char**>(CCArgs.data()),
          const_cast<const char**>(CCArgs.data()) + CCArgs.size(), *diags)) {
    errx(1, "failed to create CompilerInvocation");
  }

  clang::CompilerInstance Compiler;
  Compiler.setInvocation(invocation.release());
  Compiler.setDiagnostics(diags.get());

  VersionerASTAction versioner_action(header_database, type);
  if (!Compiler.ExecuteAction(versioner_action)) {
    errx(1, "compilation generated warnings or errors");
  }

  if (diags->getNumWarnings() || diags->hasErrorOccurred()) {
    errx(1, "compilation generated warnings or errors");
  }
}

struct CompilationRequirements {
  std::vector<std::string> headers;
  std::vector<std::string> dependencies;
};

static CompilationRequirements collectRequirements(const Arch& arch, const std::string& header_dir,
                                                   const std::string& dependency_dir) {
  std::vector<std::string> headers = collectFiles(header_dir);

  std::vector<std::string> dependencies = { header_dir };
  if (!dependency_dir.empty()) {
    auto collect_children = [&dependencies](const std::string& dir_path) {
      DIR* dir = opendir(dir_path.c_str());
      if (!dir) {
        err(1, "failed to open dependency directory '%s'", dir_path.c_str());
      }

      struct dirent* dent;
      while ((dent = readdir(dir))) {
        if (dent->d_name[0] == '.') {
          continue;
        }

        // TODO: Resolve symlinks.
        std::string dependency = dir_path + "/" + dent->d_name;

        struct stat st;
        if (stat(dependency.c_str(), &st) != 0) {
          err(1, "failed to stat dependency '%s'", dependency.c_str());
        }

        if (!S_ISDIR(st.st_mode)) {
          errx(1, "'%s' is not a directory", dependency.c_str());
        }

        dependencies.push_back(dependency);
      }

      closedir(dir);
    };

    collect_children(dependency_dir + "/common");
    collect_children(dependency_dir + "/" + to_string(arch));
  }

  auto new_end = std::remove_if(headers.begin(), headers.end(), [&arch](llvm::StringRef header) {
    for (const auto& it : header_blacklist) {
      if (it.second.find(arch) == it.second.end()) {
        continue;
      }

      if (header.endswith("/" + it.first)) {
        return true;
      }
    }
    return false;
  });

  headers.erase(new_end, headers.end());

  CompilationRequirements result = { .headers = headers, .dependencies = dependencies };
  return result;
}

static std::set<CompilationType> generateCompilationTypes(const std::set<Arch> selected_architectures,
                                                          const std::set<int>& selected_levels) {
  std::set<CompilationType> result;
  for (const auto& arch : selected_architectures) {
    int min_api = arch_min_api[arch];
    for (int api_level : selected_levels) {
      if (api_level < min_api) {
        continue;
      }

      for (int file_offset_bits : { 32, 64 }) {
        CompilationType type = {
          .arch = arch, .api_level = api_level, .file_offset_bits = file_offset_bits
        };
        result.insert(type);
      }
    }
  }
  return result;
}

struct Job {
  Job(CompilationType type, const std::string& header, const std::vector<std::string>& dependencies)
      : type(type), header(header), dependencies(dependencies) {
  }
  CompilationType type;
  const std::string& header;
  const std::vector<std::string>& dependencies;
};

static std::unique_ptr<HeaderDatabase> compileHeaders(const std::set<CompilationType>& types,
                                                      const std::string& header_dir,
                                                      const std::string& dependency_dir) {
  if (types.empty()) {
    errx(1, "compileHeaders received no CompilationTypes");
  }

  size_t thread_count = max_thread_count;
  std::vector<std::thread> threads;
  std::vector<Job> jobs;

  std::map<CompilationType, HeaderDatabase> header_databases;
  std::unordered_map<Arch, CompilationRequirements> requirements;

  std::string cwd = getWorkingDir();

  auto result = std::make_unique<HeaderDatabase>();
  auto spawn_threads = [&]() {
    thread_count = std::min(thread_count, jobs.size());
    for (size_t i = 0; i < thread_count; ++i) {
      threads.emplace_back([&jobs, &result, &header_dir, thread_count, i]() {
        size_t index = i;
        while (index < jobs.size()) {
          const auto& job = jobs[index];
          compileHeader(result.get(), job.type, job.header, header_dir, job.dependencies);
          index += thread_count;
        }
      });
    }
  };
  auto reap_threads = [&]() {
    for (auto& thread : threads) {
      thread.join();
    }
    threads.clear();
  };

  for (const auto& type : types) {
    if (requirements.count(type.arch) == 0) {
      requirements[type.arch] = collectRequirements(type.arch, header_dir, dependency_dir);
    }
  }

  for (CompilationType type : types) {
    CompilationRequirements& req = requirements[type.arch];
    for (const std::string& header : req.headers) {
      jobs.emplace_back(type, header, req.dependencies);
    }
  }

  spawn_threads();
  reap_threads();

  return result;
}

static std::set<CompilationType> getCompilationTypes(const Declaration* decl) {
  std::set<CompilationType> result;
  for (const auto& it : decl->availability) {
    result.insert(it.first);
  }
  return result;
}

template<typename T>
static std::vector<T> Intersection(const std::set<T>& a, const std::set<T>& b) {
  std::vector<T> intersection;
  std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(intersection));
  return intersection;
}

// Perform a sanity check on a symbol's declarations, enforcing the following invariants:
//   1. At most one inline definition of the function exists.
//   2. All of the availability declarations for a symbol are compatible.
//      If a function is declared as an inline before a certain version, the inline definition
//      should have no version tag.
//   3. Each availability type must only be present globally or on a per-arch basis.
//      (e.g. __INTRODUCED_IN_ARM(9) __INTRODUCED_IN_X86(10) __DEPRECATED_IN(11) is fine,
//      but not __INTRODUCED_IN(9) __INTRODUCED_IN_X86(10))
static bool checkSymbol(const Symbol& symbol) {
  std::string cwd = getWorkingDir() + "/";

  std::unordered_map<const Declaration*, std::set<CompilationType>> inline_definitions;
  for (const auto& decl_it : symbol.declarations) {
    const Declaration* decl = &decl_it.second;
    if (decl->is_definition) {
      std::set<CompilationType> compilation_types = getCompilationTypes(decl);
      for (const auto& inline_def_it : inline_definitions) {
        auto intersection = Intersection(compilation_types, inline_def_it.second);
        if (!intersection.empty()) {
          fprintf(stderr, "versioner: conflicting inline definitions:\n");
          fprintf(stderr, "  declarations visible in: %s\n", Join(intersection, ", ").c_str());
          decl->dump(cwd, stderr, 4);
          inline_def_it.first->dump(cwd, stderr, 4);
          return false;
        }
      }

      inline_definitions[decl] = std::move(compilation_types);
    }

    DeclarationAvailability availability;
    if (!decl->calculateAvailability(&availability)) {
      fprintf(stderr, "versioner: failed to calculate availability for declaration:\n");
      decl->dump(cwd, stderr, 2);
      return false;
    }

    if (decl->is_definition && !availability.empty()) {
      fprintf(stderr, "versioner: inline definition has non-empty versioning information:\n");
      decl->dump(cwd, stderr, 2);
      return false;
    }
  }

  DeclarationAvailability availability;
  if (!symbol.calculateAvailability(&availability)) {
    fprintf(stderr, "versioner: inconsistent availability for symbol '%s'\n", symbol.name.c_str());
    symbol.dump(cwd);
    return false;
  }

  // TODO: Check invariant #3.
  return true;
}

static bool sanityCheck(const HeaderDatabase* database) {
  bool error = false;
  std::string cwd = getWorkingDir() + "/";

  for (const auto& symbol_it : database->symbols) {
    if (!checkSymbol(symbol_it.second)) {
      error = true;
    }
  }
  return !error;
}

// Check that our symbol availability declarations match the actual NDK
// platform symbol availability.
static bool checkVersions(const std::set<CompilationType>& types,
                          const HeaderDatabase* header_database,
                          const NdkSymbolDatabase& symbol_database) {
  std::string cwd = getWorkingDir() + "/";
  bool failed = false;

  std::map<Arch, std::set<CompilationType>> arch_types;
  for (const CompilationType& type : types) {
    arch_types[type.arch].insert(type);
  }

  std::set<std::string> completely_unavailable;
  std::map<std::string, std::set<CompilationType>> missing_availability;
  std::map<std::string, std::set<CompilationType>> extra_availability;

  for (const auto& symbol_it : header_database->symbols) {
    const auto& symbol_name = symbol_it.first;
    DeclarationAvailability symbol_availability;

    if (!symbol_it.second.calculateAvailability(&symbol_availability)) {
      errx(1, "failed to calculate symbol availability");
    }

    const auto platform_availability_it = symbol_database.find(symbol_name);
    if (platform_availability_it == symbol_database.end()) {
      completely_unavailable.insert(symbol_name);
      continue;
    }

    const auto& platform_availability = platform_availability_it->second;

    for (const CompilationType& type : types) {
      bool should_be_available = true;
      const auto& global_availability = symbol_availability.global_availability;
      const auto& arch_availability = symbol_availability.arch_availability[type.arch];
      if (global_availability.introduced != 0 && global_availability.introduced > type.api_level) {
        should_be_available = false;
      }

      if (arch_availability.introduced != 0 && arch_availability.introduced > type.api_level) {
        should_be_available = false;
      }

      if (global_availability.obsoleted != 0 && global_availability.obsoleted <= type.api_level) {
        should_be_available = false;
      }

      if (arch_availability.obsoleted != 0 && arch_availability.obsoleted <= type.api_level) {
        should_be_available = false;
      }

      if (arch_availability.future) {
        continue;
      }

      // The function declaration might be (validly) missing for the given CompilationType.
      if (!symbol_it.second.hasDeclaration(type)) {
        should_be_available = false;
      }

      bool is_available = platform_availability.count(type);

      if (should_be_available != is_available) {
        if (is_available) {
          extra_availability[symbol_name].insert(type);
        } else {
          missing_availability[symbol_name].insert(type);
        }
      }
    }
  }

  for (const auto& it : symbol_database) {
    const std::string& symbol_name = it.first;

    bool symbol_error = false;
    auto missing_it = missing_availability.find(symbol_name);
    if (missing_it != missing_availability.end()) {
      printf("%s: declaration marked available but symbol missing in [%s]\n", symbol_name.c_str(),
             Join(missing_it->second, ", ").c_str());
      symbol_error = true;
      failed = true;
    }

    if (verbose) {
      auto extra_it = extra_availability.find(symbol_name);
      if (extra_it != extra_availability.end()) {
        printf("%s: declaration marked unavailable but symbol available in [%s]\n",
               symbol_name.c_str(), Join(extra_it->second, ", ").c_str());
        symbol_error = true;
        failed = true;
      }
    }

    if (symbol_error) {
      auto symbol_it = header_database->symbols.find(symbol_name);
      if (symbol_it == header_database->symbols.end()) {
        errx(1, "failed to find symbol in header database");
      }
      symbol_it->second.dump(cwd);
    }
  }

  // TODO: Verify that function/variable declarations are actually function/variable symbols.
  return !failed;
}

static void usage(bool help = false) {
  fprintf(stderr, "Usage: versioner [OPTION]... [HEADER_PATH] [DEPS_PATH]\n");
  if (!help) {
    printf("Try 'versioner -h' for more information.\n");
    exit(1);
  } else {
    fprintf(stderr, "Version headers at HEADER_PATH, with DEPS_PATH/ARCH/* on the include path\n");
    fprintf(stderr, "Autodetects paths if HEADER_PATH and DEPS_PATH are not specified\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "Target specification (defaults to all):\n");
    fprintf(stderr, "  -a API_LEVEL\tbuild with specified API level (can be repeated)\n");
    fprintf(stderr, "    \t\tvalid levels are %s\n", Join(supported_levels).c_str());
    fprintf(stderr, "  -r ARCH\tbuild with specified architecture (can be repeated)\n");
    fprintf(stderr, "    \t\tvalid architectures are %s\n", Join(supported_archs).c_str());
    fprintf(stderr, "\n");
    fprintf(stderr, "Validation:\n");
    fprintf(stderr, "  -p PATH\tcompare against NDK platform at PATH\n");
    fprintf(stderr, "  -v\t\tenable verbose warnings\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "Preprocessing:\n");
    fprintf(stderr, "  -o PATH\tpreprocess header files and emit them at PATH\n");
    fprintf(stderr, "  -f\tpreprocess header files even if validation fails\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "Miscellaneous:\n");
    fprintf(stderr, "  -d\t\tdump function availability\n");
    fprintf(stderr, "  -j THREADS\tmaximum number of threads to use\n");
    fprintf(stderr, "  -h\t\tdisplay this message\n");
    exit(0);
  }
}

int main(int argc, char** argv) {
  std::string cwd = getWorkingDir() + "/";
  bool default_args = true;
  std::string platform_dir;
  std::set<Arch> selected_architectures;
  std::set<int> selected_levels;
  std::string preprocessor_output_path;
  bool force = false;
  bool dump = false;

  int c;
  while ((c = getopt(argc, argv, "a:r:p:vo:fdj:hi")) != -1) {
    default_args = false;
    switch (c) {
      case 'a': {
        char* end;
        int api_level = strtol(optarg, &end, 10);
        if (end == optarg || strlen(end) > 0) {
          usage();
        }

        if (supported_levels.count(api_level) == 0) {
          errx(1, "unsupported API level %d", api_level);
        }

        selected_levels.insert(api_level);
        break;
      }

      case 'r': {
        Arch arch = arch_from_string(optarg);
        selected_architectures.insert(arch);
        break;
      }

      case 'p': {
        if (!platform_dir.empty()) {
          usage();
        }

        platform_dir = optarg;

        if (platform_dir.empty()) {
          usage();
        }

        struct stat st;
        if (stat(platform_dir.c_str(), &st) != 0) {
          err(1, "failed to stat platform directory '%s'", platform_dir.c_str());
        }
        if (!S_ISDIR(st.st_mode)) {
          errx(1, "'%s' is not a directory", optarg);
        }
        break;
      }

      case 'v':
        verbose = true;
        break;

      case 'o':
        if (!preprocessor_output_path.empty()) {
          usage();
        }
        preprocessor_output_path = optarg;
        if (preprocessor_output_path.empty()) {
          usage();
        }
        break;

      case 'f':
        force = true;
        break;

      case 'd':
        dump = true;
        break;

      case 'j':
        if (!android::base::ParseInt<int>(optarg, &max_thread_count, 1)) {
          usage();
        }
        break;

      case 'h':
        usage(true);
        break;

      case 'i':
        // Secret option for tests to -include <android/versioning.h>.
        add_include = true;
        break;

      default:
        usage();
        break;
    }
  }

  if (argc - optind > 2 || optind > argc) {
    usage();
  }

  std::string header_dir;
  std::string dependency_dir;

  const char* top = getenv("ANDROID_BUILD_TOP");
  if (!top && (optind == argc || add_include)) {
    fprintf(stderr, "versioner: failed to autodetect bionic paths. Is ANDROID_BUILD_TOP set?\n");
    usage();
  }

  if (optind == argc) {
    // Neither HEADER_PATH nor DEPS_PATH were specified, so try to figure them out.
    std::string versioner_dir = to_string(top) + "/bionic/tools/versioner";
    header_dir = versioner_dir + "/current";
    dependency_dir = versioner_dir + "/dependencies";
    if (platform_dir.empty()) {
      platform_dir = versioner_dir + "/platforms";
    }
  } else {
    // Intentional leak.
    header_dir = realpath(argv[optind], nullptr);

    if (argc - optind == 2) {
      dependency_dir = argv[optind + 1];
    }
  }

  if (selected_levels.empty()) {
    selected_levels = supported_levels;
  }

  if (selected_architectures.empty()) {
    selected_architectures = supported_archs;
  }


  struct stat st;
  if (stat(header_dir.c_str(), &st) != 0) {
    err(1, "failed to stat '%s'", header_dir.c_str());
  } else if (!S_ISDIR(st.st_mode)) {
    errx(1, "'%s' is not a directory", header_dir.c_str());
  }

  std::set<CompilationType> compilation_types;
  NdkSymbolDatabase symbol_database;

  compilation_types = generateCompilationTypes(selected_architectures, selected_levels);

  // Do this before compiling so that we can early exit if the platforms don't match what we
  // expect.
  if (!platform_dir.empty()) {
    symbol_database = parsePlatforms(compilation_types, platform_dir);
  }

  std::unique_ptr<HeaderDatabase> declaration_database =
      compileHeaders(compilation_types, header_dir, dependency_dir);

  bool failed = false;
  if (dump) {
    declaration_database->dump(header_dir + "/");
  } else {
    if (!sanityCheck(declaration_database.get())) {
      printf("versioner: sanity check failed\n");
      failed = true;
    }

    if (!platform_dir.empty()) {
      if (!checkVersions(compilation_types, declaration_database.get(), symbol_database)) {
        printf("versioner: version check failed\n");
        failed = true;
      }
    }
  }

  if (!preprocessor_output_path.empty() && (force || !failed)) {
    failed = !preprocessHeaders(preprocessor_output_path, header_dir, declaration_database.get());
  }
  return failed;
}
