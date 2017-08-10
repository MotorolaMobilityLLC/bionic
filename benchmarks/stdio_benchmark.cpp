/*
 * Copyright (C) 2014 The Android Open Source Project
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

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include <benchmark/benchmark.h>
#include "util.h"

template <typename Fn>
void ReadWriteTest(benchmark::State& state, Fn f, bool buffered) {
  size_t chunk_size = state.range(0);

  FILE* fp = fopen("/dev/zero", "rw");
  __fsetlocking(fp, FSETLOCKING_BYCALLER);
  char* buf = new char[chunk_size];

  if (!buffered) {
    setvbuf(fp, 0, _IONBF, 0);
  }

  while (state.KeepRunning()) {
    f(buf, chunk_size, 1, fp);
  }

  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(chunk_size));
  delete[] buf;
  fclose(fp);
}

void BM_stdio_fread(benchmark::State& state) {
  ReadWriteTest(state, fread, true);
}
BIONIC_BENCHMARK(BM_stdio_fread);

void BM_stdio_fwrite(benchmark::State& state) {
  ReadWriteTest(state, fwrite, true);
}
BIONIC_BENCHMARK(BM_stdio_fwrite);

void BM_stdio_fread_unbuffered(benchmark::State& state) {
  ReadWriteTest(state, fread, false);
}
BIONIC_BENCHMARK(BM_stdio_fread_unbuffered);

void BM_stdio_fwrite_unbuffered(benchmark::State& state) {
  ReadWriteTest(state, fwrite, false);
}
BIONIC_BENCHMARK(BM_stdio_fwrite_unbuffered);

static void FopenFgetsFclose(benchmark::State& state, bool no_locking) {
  size_t nbytes = state.range(0);
  char buf[nbytes];
  while (state.KeepRunning()) {
    FILE* fp = fopen("/dev/zero", "re");
    if (no_locking) __fsetlocking(fp, FSETLOCKING_BYCALLER);
    if (fgets(buf, sizeof(buf), fp) == nullptr) abort();
    fclose(fp);
  }
}

static void BM_stdio_fopen_fgets_fclose_locking(benchmark::State& state) {
  FopenFgetsFclose(state, false);
}
BIONIC_BENCHMARK(BM_stdio_fopen_fgets_fclose_locking);

void BM_stdio_fopen_fgets_fclose_no_locking(benchmark::State& state) {
  FopenFgetsFclose(state, true);
}
BIONIC_BENCHMARK(BM_stdio_fopen_fgets_fclose_no_locking);

static void FopenFgetcFclose(benchmark::State& state, bool no_locking) {
  size_t nbytes = state.range(0);
  while (state.KeepRunning()) {
    FILE* fp = fopen("/dev/zero", "re");
    if (no_locking) __fsetlocking(fp, FSETLOCKING_BYCALLER);
    volatile int c __attribute__((unused));
    for (size_t i = 0; i < nbytes; ++i) {
      c = fgetc(fp);
    }
    fclose(fp);
  }
}

static void BM_stdio_fopen_fgetc_fclose_locking(benchmark::State& state) {
  FopenFgetcFclose(state, false);
}
BIONIC_BENCHMARK(BM_stdio_fopen_fgetc_fclose_locking);

void BM_stdio_fopen_fgetc_fclose_no_locking(benchmark::State& state) {
  FopenFgetcFclose(state, true);
}
BIONIC_BENCHMARK(BM_stdio_fopen_fgetc_fclose_no_locking);

