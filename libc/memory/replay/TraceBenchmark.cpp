/*
 * Copyright (C) 2019 The Android Open Source Project
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

#include <err.h>
#include <inttypes.h>
#include <malloc.h>
#include <sched.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include <android-base/file.h>
#include <android-base/strings.h>
#include <benchmark/benchmark.h>

#include <memory_trace/MemoryTrace.h>
#include <memory_trace/TraceInfo.h>

#include "File.h"

// Run a trace as if all of the allocations occurred in a single thread.
// This is not completely realistic, but it is a possible worst case that
// could happen in an app.
static void BenchmarkTrace(benchmark::State& state, const char* filename,
                           [[maybe_unused]] bool enable_decay_time) {
#if defined(__BIONIC__)
  if (enable_decay_time) {
    mallopt(M_DECAY_TIME, 1);
  } else {
    mallopt(M_DECAY_TIME, 0);
  }
#endif
  std::string full_filename(android::base::GetExecutableDirectory() + "/traces/" + filename);

  static memory_trace::TraceInfo trace;
  if (full_filename != trace.filename()) {
    trace.Clear();
    trace.Init(full_filename);
  }

  for (auto _ : state) {
    uint64_t total_ns = trace.RunSingleThread();
    state.SetIterationTime(total_ns / double(1000000000.0));
  }

  // Don't free the trace_data, it is cached. The last set of trace data
  // will be leaked away.
}

#define BENCH_OPTIONS                 \
  UseManualTime()                     \
      ->Unit(benchmark::kMicrosecond) \
      ->MinTime(15.0)                 \
      ->Repetitions(4)                \
      ->ReportAggregatesOnly(true)

static void BM_angry_birds2_default(benchmark::State& state) {
  BenchmarkTrace(state, "angry_birds2.zip", true);
}
BENCHMARK(BM_angry_birds2_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
static void BM_angry_birds2_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "angry_birds2.zip", false);
}
BENCHMARK(BM_angry_birds2_no_decay)->BENCH_OPTIONS;
#endif

static void BM_camera_default(benchmark::State& state) {
  BenchmarkTrace(state, "camera.zip", true);
}
BENCHMARK(BM_camera_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
static void BM_camera_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "camera.zip", false);
}
BENCHMARK(BM_camera_no_decay)->BENCH_OPTIONS;
#endif

static void BM_candy_crush_saga_default(benchmark::State& state) {
  BenchmarkTrace(state, "candy_crush_saga.zip", true);
}
BENCHMARK(BM_candy_crush_saga_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
static void BM_candy_crush_saga_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "candy_crush_saga.zip", false);
}
BENCHMARK(BM_candy_crush_saga_no_decay)->BENCH_OPTIONS;
#endif

void BM_gmail_default(benchmark::State& state) {
  BenchmarkTrace(state, "gmail.zip", true);
}
BENCHMARK(BM_gmail_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
void BM_gmail_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "gmail.zip", false);
}
BENCHMARK(BM_gmail_no_decay)->BENCH_OPTIONS;
#endif

void BM_maps_default(benchmark::State& state) {
  BenchmarkTrace(state, "maps.zip", true);
}
BENCHMARK(BM_maps_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
void BM_maps_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "maps.zip", false);
}
BENCHMARK(BM_maps_no_decay)->BENCH_OPTIONS;
#endif

void BM_photos_default(benchmark::State& state) {
  BenchmarkTrace(state, "photos.zip", true);
}
BENCHMARK(BM_photos_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
void BM_photos_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "photos.zip", false);
}
BENCHMARK(BM_photos_no_decay)->BENCH_OPTIONS;
#endif

void BM_pubg_default(benchmark::State& state) {
  BenchmarkTrace(state, "pubg.zip", true);
}
BENCHMARK(BM_pubg_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
void BM_pubg_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "pubg.zip", false);
}
BENCHMARK(BM_pubg_no_decay)->BENCH_OPTIONS;
#endif

void BM_surfaceflinger_default(benchmark::State& state) {
  BenchmarkTrace(state, "surfaceflinger.zip", true);
}
BENCHMARK(BM_surfaceflinger_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
void BM_surfaceflinger_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "surfaceflinger.zip", false);
}
BENCHMARK(BM_surfaceflinger_no_decay)->BENCH_OPTIONS;
#endif

void BM_system_server_default(benchmark::State& state) {
  BenchmarkTrace(state, "system_server.zip", true);
}
BENCHMARK(BM_system_server_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
void BM_system_server_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "system_server.zip", false);
}
BENCHMARK(BM_system_server_no_decay)->BENCH_OPTIONS;
#endif

void BM_systemui_default(benchmark::State& state) {
  BenchmarkTrace(state, "systemui.zip", true);
}
BENCHMARK(BM_systemui_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
void BM_systemui_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "systemui.zip", false);
}
BENCHMARK(BM_systemui_no_decay)->BENCH_OPTIONS;
#endif

void BM_youtube_default(benchmark::State& state) {
  BenchmarkTrace(state, "youtube.zip", true);
}
BENCHMARK(BM_youtube_default)->BENCH_OPTIONS;

#if defined(__BIONIC__)
void BM_youtube_no_decay(benchmark::State& state) {
  BenchmarkTrace(state, "youtube.zip", false);
}
BENCHMARK(BM_youtube_no_decay)->BENCH_OPTIONS;
#endif

int main(int argc, char** argv) {
  std::vector<char*> args;
  args.push_back(argv[0]);

  // Look for the --cpu=XX option.
  for (int i = 1; i < argc; i++) {
    if (strncmp(argv[i], "--cpu=", 6) == 0) {
      char* endptr;
      int cpu = strtol(&argv[i][6], &endptr, 10);
      if (argv[i][0] == '\0' || endptr == nullptr || *endptr != '\0') {
        printf("Invalid format of --cpu option, '%s' must be an integer value.\n", argv[i] + 6);
        return 1;
      }
      cpu_set_t cpuset;
      CPU_ZERO(&cpuset);
      CPU_SET(cpu, &cpuset);
      if (sched_setaffinity(0, sizeof(cpuset), &cpuset) != 0) {
        if (errno == EINVAL) {
          printf("Invalid cpu %d\n", cpu);
          return 1;
        }
        perror("sched_setaffinity failed");
        return 1;
      }
      printf("Locking to cpu %d\n", cpu);
    } else {
      args.push_back(argv[i]);
    }
  }

  argc = args.size();
  ::benchmark::Initialize(&argc, args.data());
  if (::benchmark::ReportUnrecognizedArguments(argc, args.data())) return 1;
  ::benchmark::RunSpecifiedBenchmarks();
}
