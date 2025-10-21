# portable-simd

Implementations of functions that are intended to be portable to at least a few
different vector types/architectures.

The general idea of this project is to implement SIMD algorithms generically.
That is, they're implemented as templates on an interface called
`VectorTraits`, and they only use the `VectorTraits` interface to do their job
with SIMD.

This allows for us to, say, implement an AVX512 `strlen` with reasonable
performance by simply reusing the logic for our AVX2 and SSE `strlen`
implementations, rather than building the AVX512 implementation from scratch.

## Why?

Ease of creation and maintenance lowers barriers.

Handwritten assembly will always be _at least_ as efficient as C++, and is
likely to be better when carefully tuned. This repo's goal is not to make
implementations that are competitive with the best-of-the-best handwritten
assembly. It's to get 80%+ of the benefit of carefully-written assembly with a
fraction of the effort.

## Project structure

- Functions made available to Bionic are listed in `portable_simd_exports.h`.
- All SIMD intrinsic usage should be in `VectorTraits*` structs, located in
  `portable_simd_detail.h`.
- `.cpp` files contain implementations of functions listed in
  `portable_simd_exports.h`. These function implementations should generally
  boil down to an instantiation of a `template <typename VectorTraits>`
  function.

## Interactions with Bionic

The files here are intended to be built once _per vector type_ that they
support. This means that `strlen.cpp` will be built once for SSE, once for
AVX2, etc.

The correct implementation for the current chip gets selected by an `ifunc`.
