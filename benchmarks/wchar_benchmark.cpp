/*
 * Copyright (C) 2025 The Android Open Source Project
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

#include <wchar.h>

#include <benchmark/benchmark.h>
#include <util.h>

// NOTE: While we support wchar functions being passed unaligned pointers for
// compatibility purposes, we intentionally do not benchmark that case, because
// it's expected to be extremely rare. If devs want fast wchar, they can align
// their buffers correctly.

static void BM_wchar_wcslen(benchmark::State& state) {
  const size_t nbytes = state.range(0) * sizeof(wchar_t);
  const size_t alignment = state.range(1);

  std::vector<char> buf;
  char* buf_aligned = GetAlignedPtrFilled(&buf, alignment, nbytes, 'x');

  memset(buf_aligned + nbytes - sizeof(wchar_t), 0, sizeof(wchar_t));
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(wcslen(reinterpret_cast<const wchar_t*>(buf_aligned)));
  }

  state.SetBytesProcessed(uint64_t(state.iterations()) * uint64_t(nbytes));
}
BIONIC_BENCHMARK_WITH_ARG(BM_wchar_wcslen, "AT_ALIGNED_ONEBUF");

static void BM_wchar_wmemchr(benchmark::State& state) {
  const size_t nchars = state.range(0);
  const size_t alignment = state.range(1);

  const size_t nbytes = nchars * sizeof(wchar_t);
  std::vector<char> buf;
  char* buf_aligned = GetAlignedPtrFilled(&buf, alignment, nbytes + 1, 'x');

  wchar_t needle = L'a';
  memcpy(buf_aligned + nbytes - sizeof(wchar_t), &needle, sizeof(needle));
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(
        wmemchr(reinterpret_cast<const wchar_t*>(buf_aligned), needle, nchars));
  }

  state.SetBytesProcessed(uint64_t(state.iterations()) * uint64_t(nbytes));
}
BIONIC_BENCHMARK_WITH_ARG(BM_wchar_wmemchr, "AT_ALIGNED_ONEBUF");

static void WMemSetBenchmark(benchmark::State& state, wchar_t wc) {
  const size_t nchars = state.range(0);
  const size_t alignment = state.range(1);

  const size_t nbytes = nchars * sizeof(wchar_t);
  std::vector<char> buf;
  char* buf_aligned = GetAlignedPtr(&buf, alignment, nbytes + 1);

  while (state.KeepRunning()) {
    wmemset(reinterpret_cast<wchar_t*>(buf_aligned), wc, nchars);
  }

  state.SetBytesProcessed(uint64_t(state.iterations()) * uint64_t(nbytes));
}

static void BM_wchar_wmemset_0(benchmark::State& state) {
  WMemSetBenchmark(state, 0);
}
BIONIC_BENCHMARK_WITH_ARG(BM_wchar_wmemset_0, "AT_ALIGNED_ONEBUF");

static void BM_wchar_wmemset_666(benchmark::State& state) {
  WMemSetBenchmark(state, 666);
}
BIONIC_BENCHMARK_WITH_ARG(BM_wchar_wmemset_666, "AT_ALIGNED_ONEBUF");
