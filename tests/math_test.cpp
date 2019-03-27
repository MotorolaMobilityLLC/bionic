/*
 * Copyright (C) 2013 The Android Open Source Project
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

#define _GNU_SOURCE 1
#include <math.h>

// This include (and the associated definition of __test_capture_signbit)
// must be placed before any files that include <cmath> (gtest.h in this case).
//
// <math.h> is required to define generic macros signbit, isfinite and
// several other such functions.
//
// <cmath> is required to undef declarations of these macros in the global
// namespace and make equivalent functions available in namespace std. Our
// stlport implementation does this only for signbit, isfinite, isinf and
// isnan.
//
// NOTE: We don't write our test using std::signbit because we want to be
// sure that we're testing the bionic version of signbit. The C++ libraries
// are free to reimplement signbit or delegate to compiler builtins if they
// please.

namespace {
template<typename T> inline int test_capture_signbit(const T in) {
  return signbit(in);
}
template<typename T> inline int test_capture_isfinite(const T in) {
  return isfinite(in);
}
template<typename T> inline int test_capture_isnan(const T in) {
  return isnan(in);
}
template<typename T> inline int test_capture_isinf(const T in) {
  return isinf(in);
}
}

#if defined(__BIONIC_LP32_USE_LONG_DOUBLE)
#define MATH_TEST math_h_force_long_double
#else
#define MATH_TEST math_h
#endif

#include "math_data_test.h"

#include <gtest/gtest.h>

#include <fenv.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>

#include <android-base/scopeguard.h>

static float float_subnormal() {
  union {
    float f;
    uint32_t i;
  } u;
  u.i = 0x007fffff;
  return u.f;
}

static double double_subnormal() {
  union {
    double d;
    uint64_t i;
  } u;
  u.i = 0x000fffffffffffffLL;
  return u.d;
}

static long double ldouble_subnormal() {
  union {
    long double e;
    unsigned char c[sizeof(long double)];
  } u;

  // Subnormals must have a zero exponent and non zero significand.
  // On all supported representation the 17 bit (counting from either sides)
  // is part of the significand so it should be enough to set that.
  // It also applies for the case sizeof(double) = sizeof(long double)
  for (unsigned int i = 0; i < sizeof(long double); i++) {
    u.c[i] = 0x00;
  }
  u.c[sizeof(long double) - 3] = 0x80;
  u.c[2] = 0x80;

  return u.e;
}

TEST(MATH_TEST, fpclassify) {
  ASSERT_EQ(FP_INFINITE, fpclassify(INFINITY));
  ASSERT_EQ(FP_INFINITE, fpclassify(HUGE_VALF));
  ASSERT_EQ(FP_INFINITE, fpclassify(-HUGE_VALF));
  ASSERT_EQ(FP_INFINITE, fpclassify(HUGE_VAL));
  ASSERT_EQ(FP_INFINITE, fpclassify(-HUGE_VAL));
  ASSERT_EQ(FP_INFINITE, fpclassify(HUGE_VALL));
  ASSERT_EQ(FP_INFINITE, fpclassify(-HUGE_VALL));

  ASSERT_EQ(FP_NAN, fpclassify(nanf("")));
  ASSERT_EQ(FP_NAN, fpclassify(nan("")));
  ASSERT_EQ(FP_NAN, fpclassify(nanl("")));

  ASSERT_EQ(FP_NORMAL, fpclassify(1.0f));
  ASSERT_EQ(FP_NORMAL, fpclassify(1.0));
  ASSERT_EQ(FP_NORMAL, fpclassify(1.0L));

  ASSERT_EQ(FP_SUBNORMAL, fpclassify(float_subnormal()));
  ASSERT_EQ(FP_SUBNORMAL, fpclassify(double_subnormal()));
  ASSERT_EQ(FP_SUBNORMAL, fpclassify(ldouble_subnormal()));

  ASSERT_EQ(FP_ZERO, fpclassify(0.0f));
  ASSERT_EQ(FP_ZERO, fpclassify(0.0));
  ASSERT_EQ(FP_ZERO, fpclassify(0.0L));
}

TEST(MATH_TEST, isfinite) {
  ASSERT_TRUE(test_capture_isfinite(123.0f));
  ASSERT_TRUE(test_capture_isfinite(123.0));
  ASSERT_TRUE(test_capture_isfinite(123.0L));
  ASSERT_FALSE(test_capture_isfinite(HUGE_VALF));
  ASSERT_FALSE(test_capture_isfinite(-HUGE_VALF));
  ASSERT_FALSE(test_capture_isfinite(HUGE_VAL));
  ASSERT_FALSE(test_capture_isfinite(-HUGE_VAL));
  ASSERT_FALSE(test_capture_isfinite(HUGE_VALL));
  ASSERT_FALSE(test_capture_isfinite(-HUGE_VALL));
}

TEST(MATH_TEST, isinf) {
  ASSERT_FALSE(test_capture_isinf(123.0f));
  ASSERT_FALSE(test_capture_isinf(123.0));
  ASSERT_FALSE(test_capture_isinf(123.0L));
  ASSERT_TRUE(test_capture_isinf(HUGE_VALF));
  ASSERT_TRUE(test_capture_isinf(-HUGE_VALF));
  ASSERT_TRUE(test_capture_isinf(HUGE_VAL));
  ASSERT_TRUE(test_capture_isinf(-HUGE_VAL));
  ASSERT_TRUE(test_capture_isinf(HUGE_VALL));
  ASSERT_TRUE(test_capture_isinf(-HUGE_VALL));
}

TEST(MATH_TEST, isnan) {
  ASSERT_FALSE(test_capture_isnan(123.0f));
  ASSERT_FALSE(test_capture_isnan(123.0));
  ASSERT_FALSE(test_capture_isnan(123.0L));
  ASSERT_TRUE(test_capture_isnan(nanf("")));
  ASSERT_TRUE(test_capture_isnan(nan("")));
  ASSERT_TRUE(test_capture_isnan(nanl("")));
}

TEST(MATH_TEST, isnormal) {
  ASSERT_TRUE(isnormal(123.0f));
  ASSERT_TRUE(isnormal(123.0));
  ASSERT_TRUE(isnormal(123.0L));
  ASSERT_FALSE(isnormal(float_subnormal()));
  ASSERT_FALSE(isnormal(double_subnormal()));
  ASSERT_FALSE(isnormal(ldouble_subnormal()));
}

// TODO: isgreater, isgreaterequals, isless, islessequal, islessgreater, isunordered
TEST(MATH_TEST, signbit) {
  ASSERT_EQ(0, test_capture_signbit(0.0f));
  ASSERT_EQ(0, test_capture_signbit(0.0));
  ASSERT_EQ(0, test_capture_signbit(0.0L));

  ASSERT_EQ(0, test_capture_signbit(1.0f));
  ASSERT_EQ(0, test_capture_signbit(1.0));
  ASSERT_EQ(0, test_capture_signbit(1.0L));

  ASSERT_NE(0, test_capture_signbit(-1.0f));
  ASSERT_NE(0, test_capture_signbit(-1.0));
  ASSERT_NE(0, test_capture_signbit(-1.0L));
}

// Historical BSD cruft that isn't exposed in <math.h> any more.
extern "C" int __fpclassify(double);
extern "C" int __fpclassifyd(double);
extern "C" int __fpclassifyf(float);
extern "C" int __fpclassifyl(long double);

TEST(MATH_TEST, __fpclassify) {
  ASSERT_EQ(FP_INFINITE, __fpclassify(HUGE_VAL));
  ASSERT_EQ(FP_INFINITE, __fpclassify(-HUGE_VAL));
  ASSERT_EQ(FP_NAN, __fpclassify(nan("")));
  ASSERT_EQ(FP_NORMAL, __fpclassify(1.0));
  ASSERT_EQ(FP_SUBNORMAL, __fpclassify(double_subnormal()));
  ASSERT_EQ(FP_ZERO, __fpclassify(0.0));
}

TEST(MATH_TEST, __fpclassifyd) {
#if defined(__GLIBC__)
#define __fpclassifyd __fpclassify
#endif
  ASSERT_EQ(FP_INFINITE, __fpclassifyd(HUGE_VAL));
  ASSERT_EQ(FP_INFINITE, __fpclassifyd(-HUGE_VAL));
  ASSERT_EQ(FP_NAN, __fpclassifyd(nan("")));
  ASSERT_EQ(FP_NORMAL, __fpclassifyd(1.0));
  ASSERT_EQ(FP_SUBNORMAL, __fpclassifyd(double_subnormal()));
  ASSERT_EQ(FP_ZERO, __fpclassifyd(0.0));
}

TEST(MATH_TEST, __fpclassifyf) {
  ASSERT_EQ(FP_INFINITE, __fpclassifyf(HUGE_VALF));
  ASSERT_EQ(FP_INFINITE, __fpclassifyf(-HUGE_VALF));
  ASSERT_EQ(FP_NAN, __fpclassifyf(nanf("")));
  ASSERT_EQ(FP_NORMAL, __fpclassifyf(1.0f));
  ASSERT_EQ(FP_SUBNORMAL, __fpclassifyf(float_subnormal()));
  ASSERT_EQ(FP_ZERO, __fpclassifyf(0.0f));
}

TEST(MATH_TEST, __fpclassifyl) {
  EXPECT_EQ(FP_INFINITE, __fpclassifyl(HUGE_VALL));
  EXPECT_EQ(FP_INFINITE, __fpclassifyl(-HUGE_VALL));
  EXPECT_EQ(FP_NAN, __fpclassifyl(nanl("")));
  EXPECT_EQ(FP_NORMAL, __fpclassifyl(1.0L));
  EXPECT_EQ(FP_SUBNORMAL, __fpclassifyl(ldouble_subnormal()));
  EXPECT_EQ(FP_ZERO, __fpclassifyl(0.0L));
}

TEST(MATH_TEST, finitef) {
  ASSERT_TRUE(finitef(123.0f));
  ASSERT_FALSE(finitef(HUGE_VALF));
  ASSERT_FALSE(finitef(-HUGE_VALF));
}

// Historical BSD cruft that isn't exposed in <math.h> any more.
extern "C" int __isfinite(double);
extern "C" int __isfinitef(float);
extern "C" int isfinitef(float);
extern "C" int __isfinitel(long double);
extern "C" int isfinitel(long double);

TEST(MATH_TEST, __isfinite) {
#if defined(__GLIBC__)
#define __isfinite __finite
#endif
  ASSERT_TRUE(__isfinite(123.0));
  ASSERT_FALSE(__isfinite(HUGE_VAL));
  ASSERT_FALSE(__isfinite(-HUGE_VAL));
}

TEST(MATH_TEST, __isfinitef) {
#if defined(__GLIBC__)
#define __isfinitef __finitef
#endif
  ASSERT_TRUE(__isfinitef(123.0f));
  ASSERT_FALSE(__isfinitef(HUGE_VALF));
  ASSERT_FALSE(__isfinitef(-HUGE_VALF));
}

TEST(MATH_TEST, isfinitef) {
#if defined(__GLIBC__)
#define isfinitef __finitef
#endif
  ASSERT_TRUE(isfinitef(123.0f));
  ASSERT_FALSE(isfinitef(HUGE_VALF));
  ASSERT_FALSE(isfinitef(-HUGE_VALF));
}

TEST(MATH_TEST, __isfinitel) {
#if defined(__GLIBC__)
#define __isfinitel __finitel
#endif
  ASSERT_TRUE(__isfinitel(123.0L));
  ASSERT_FALSE(__isfinitel(HUGE_VALL));
  ASSERT_FALSE(__isfinitel(-HUGE_VALL));
}

TEST(MATH_TEST, isfinitel) {
#if defined(__GLIBC__)
#define isfinitel __finitel
#endif
  ASSERT_TRUE(isfinitel(123.0L));
  ASSERT_FALSE(isfinitel(HUGE_VALL));
  ASSERT_FALSE(isfinitel(-HUGE_VALL));
}

TEST(MATH_TEST, finite) {
  ASSERT_TRUE(finite(123.0));
  ASSERT_FALSE(finite(HUGE_VAL));
  ASSERT_FALSE(finite(-HUGE_VAL));
}

TEST(MATH_TEST, isinf_function) {
  // The isinf macro deals with all three types; the isinf function is for doubles.
  ASSERT_FALSE((isinf)(123.0));
  ASSERT_TRUE((isinf)(HUGE_VAL));
  ASSERT_TRUE((isinf)(-HUGE_VAL));
}

// Historical BSD cruft that isn't exposed in <math.h> any more.
extern "C" int __isinf(double);
extern "C" int __isinff(float);
extern "C" int isinff(float);
extern "C" int __isinfl(long double);
extern "C" int isinfl(long double);

TEST(MATH_TEST, __isinf) {
  ASSERT_FALSE(__isinf(123.0));
  ASSERT_TRUE(__isinf(HUGE_VAL));
  ASSERT_TRUE(__isinf(-HUGE_VAL));
}

TEST(MATH_TEST, __isinff) {
  ASSERT_FALSE(__isinff(123.0f));
  ASSERT_TRUE(__isinff(HUGE_VALF));
  ASSERT_TRUE(__isinff(-HUGE_VALF));
}

TEST(MATH_TEST, isinff) {
  ASSERT_FALSE(isinff(123.0f));
  ASSERT_TRUE(isinff(HUGE_VALF));
  ASSERT_TRUE(isinff(-HUGE_VALF));
}

TEST(MATH_TEST, __isinfl) {
  ASSERT_FALSE(__isinfl(123.0L));
  ASSERT_TRUE(__isinfl(HUGE_VALL));
  ASSERT_TRUE(__isinfl(-HUGE_VALL));
}

TEST(MATH_TEST, isinfl) {
  ASSERT_FALSE(isinfl(123.0L));
  ASSERT_TRUE(isinfl(HUGE_VALL));
  ASSERT_TRUE(isinfl(-HUGE_VALL));
}

TEST(MATH_TEST, isnan_function) {
  // The isnan macro deals with all three types; the isnan function is for doubles.
  ASSERT_FALSE((isnan)(123.0));
  ASSERT_TRUE((isnan)(nan("")));
}

// Historical BSD cruft that isn't exposed in <math.h> any more.
extern "C" int __isnan(double);
extern "C" int __isnanf(float);
extern "C" int isnanf(float);
extern "C" int __isnanl(long double);
extern "C" int isnanl(long double);

TEST(MATH_TEST, __isnan) {
  ASSERT_FALSE(__isnan(123.0));
  ASSERT_TRUE(__isnan(nan("")));
}

TEST(MATH_TEST, __isnanf) {
  ASSERT_FALSE(__isnanf(123.0f));
  ASSERT_TRUE(__isnanf(nanf("")));
}

TEST(MATH_TEST, isnanf) {
  ASSERT_FALSE(isnanf(123.0f));
  ASSERT_TRUE(isnanf(nanf("")));
}

TEST(MATH_TEST, __isnanl) {
  ASSERT_FALSE(__isnanl(123.0L));
  ASSERT_TRUE(__isnanl(nanl("")));
}

TEST(MATH_TEST, isnanl) {
  ASSERT_FALSE(isnanl(123.0L));
  ASSERT_TRUE(isnanl(nanl("")));
}

// Historical BSD cruft that isn't exposed in <math.h> any more.
extern "C" int __isnormal(double);
extern "C" int __isnormalf(float);
extern "C" int isnormalf(float);
extern "C" int __isnormall(long double);
extern "C" int isnormall(long double);

TEST(MATH_TEST, __isnormal) {
#if defined(__BIONIC__)
  ASSERT_TRUE(__isnormal(123.0));
  ASSERT_FALSE(__isnormal(double_subnormal()));
#else // __BIONIC__
  GTEST_SKIP() << "glibc doesn't have __isnormal";
#endif // __BIONIC__
}

TEST(MATH_TEST, __isnormalf) {
#if defined(__BIONIC__)
  ASSERT_TRUE(__isnormalf(123.0f));
  ASSERT_FALSE(__isnormalf(float_subnormal()));
#else // __BIONIC__
  GTEST_SKIP() << "glibc doesn't have __isnormalf";
#endif // __BIONIC__
}

TEST(MATH_TEST, isnormalf) {
#if defined(__BIONIC__)
  ASSERT_TRUE(isnormalf(123.0f));
  ASSERT_FALSE(isnormalf(float_subnormal()));
#else // __BIONIC__
  GTEST_SKIP() << "glibc doesn't have isnormalf";
#endif // __BIONIC__
}

TEST(MATH_TEST, __isnormall) {
#if defined(__BIONIC__)
  ASSERT_TRUE(__isnormall(123.0L));
  ASSERT_FALSE(__isnormall(ldouble_subnormal()));
#else // __BIONIC__
  GTEST_SKIP() << "glibc doesn't have __isnormall";
#endif // __BIONIC__
}

TEST(MATH_TEST, isnormall) {
#if defined(__BIONIC__)
  ASSERT_TRUE(isnormall(123.0L));
  ASSERT_FALSE(isnormall(ldouble_subnormal()));
#else // __BIONIC__
  GTEST_SKIP() << "glibc doesn't have isnormall";
#endif // __BIONIC__
}

// Historical BSD cruft that isn't exposed in <math.h> any more.
extern "C" int __signbit(double);
extern "C" int __signbitf(float);
extern "C" int __signbitl(long double);

TEST(MATH_TEST, __signbit) {
  ASSERT_EQ(0, __signbit(0.0));
  ASSERT_EQ(0, __signbit(1.0));
  ASSERT_NE(0, __signbit(-1.0));
}

TEST(MATH_TEST, __signbitf) {
  ASSERT_EQ(0, __signbitf(0.0f));
  ASSERT_EQ(0, __signbitf(1.0f));
  ASSERT_NE(0, __signbitf(-1.0f));
}

TEST(MATH_TEST, __signbitl) {
  ASSERT_EQ(0L, __signbitl(0.0L));
  ASSERT_EQ(0L, __signbitl(1.0L));
  ASSERT_NE(0L, __signbitl(-1.0L));
}

TEST(MATH_TEST, acos) {
  ASSERT_DOUBLE_EQ(M_PI/2.0, acos(0.0));
}

TEST(MATH_TEST, acosf) {
  ASSERT_FLOAT_EQ(static_cast<float>(M_PI)/2.0f, acosf(0.0f));
}

TEST(MATH_TEST, acosl) {
  ASSERT_DOUBLE_EQ(M_PI/2.0L, acosl(0.0L));
}

TEST(MATH_TEST, asin) {
  ASSERT_DOUBLE_EQ(0.0, asin(0.0));
}

TEST(MATH_TEST, asinf) {
  ASSERT_FLOAT_EQ(0.0f, asinf(0.0f));
}

TEST(MATH_TEST, asinl) {
  ASSERT_DOUBLE_EQ(0.0L, asinl(0.0L));
}

TEST(MATH_TEST, atan) {
  ASSERT_DOUBLE_EQ(0.0, atan(0.0));
}

TEST(MATH_TEST, atanf) {
  ASSERT_FLOAT_EQ(0.0f, atanf(0.0f));
}

TEST(MATH_TEST, atanl) {
  ASSERT_DOUBLE_EQ(0.0L, atanl(0.0L));
}

TEST(MATH_TEST, atan2) {
  ASSERT_DOUBLE_EQ(0.0, atan2(0.0, 0.0));
}

TEST(MATH_TEST, atan2f) {
  ASSERT_FLOAT_EQ(0.0f, atan2f(0.0f, 0.0f));
}

TEST(MATH_TEST, atan2l) {
  ASSERT_DOUBLE_EQ(0.0L, atan2l(0.0L, 0.0L));
}

TEST(MATH_TEST, cos) {
  ASSERT_DOUBLE_EQ(1.0, cos(0.0));
}

TEST(MATH_TEST, cosf) {
  ASSERT_FLOAT_EQ(1.0f, cosf(0.0f));
}

TEST(MATH_TEST, cosl) {
  ASSERT_DOUBLE_EQ(1.0L, cosl(0.0L));
}

TEST(MATH_TEST, sin) {
  ASSERT_DOUBLE_EQ(0.0, sin(0.0));
}

TEST(MATH_TEST, sinf) {
  ASSERT_FLOAT_EQ(0.0f, sinf(0.0f));
}

TEST(MATH_TEST, sinl) {
  ASSERT_DOUBLE_EQ(0.0L, sinl(0.0L));
}

TEST(MATH_TEST, sincos) {
  double s, c;
  sincos(0.0, &s, &c);
  ASSERT_DOUBLE_EQ(0.0, s);
  ASSERT_DOUBLE_EQ(1.0, c);
}

TEST(MATH_TEST, sincosf) {
  float s, c;
  sincosf(0.0f, &s, &c);
  ASSERT_FLOAT_EQ(0.0f, s);
  ASSERT_FLOAT_EQ(1.0f, c);
}

TEST(MATH_TEST, sincosl) {
  long double s, c;
  sincosl(0.0L, &s, &c);
  ASSERT_DOUBLE_EQ(0.0L, s);
  ASSERT_DOUBLE_EQ(1.0L, c);
}

TEST(MATH_TEST, tan) {
  ASSERT_DOUBLE_EQ(0.0, tan(0.0));
}

TEST(MATH_TEST, tanf) {
  ASSERT_FLOAT_EQ(0.0f, tanf(0.0f));
}

TEST(MATH_TEST, tanl) {
  ASSERT_DOUBLE_EQ(0.0L, tanl(0.0L));
}

TEST(MATH_TEST, acosh) {
  ASSERT_DOUBLE_EQ(0.0, acosh(1.0));
}

TEST(MATH_TEST, acoshf) {
  ASSERT_FLOAT_EQ(0.0f, acoshf(1.0f));
}

TEST(MATH_TEST, acoshl) {
  ASSERT_DOUBLE_EQ(0.0L, acoshl(1.0L));
}

TEST(MATH_TEST, asinh) {
  ASSERT_DOUBLE_EQ(0.0, asinh(0.0));
}

TEST(MATH_TEST, asinhf) {
  ASSERT_FLOAT_EQ(0.0f, asinhf(0.0f));
}

TEST(MATH_TEST, asinhl) {
  ASSERT_DOUBLE_EQ(0.0L, asinhl(0.0L));
}

TEST(MATH_TEST, atanh) {
  ASSERT_DOUBLE_EQ(0.0, atanh(0.0));
}

TEST(MATH_TEST, atanhf) {
  ASSERT_FLOAT_EQ(0.0f, atanhf(0.0f));
}

TEST(MATH_TEST, atanhl) {
  ASSERT_DOUBLE_EQ(0.0L, atanhl(0.0L));
}

TEST(MATH_TEST, cosh) {
  ASSERT_DOUBLE_EQ(1.0, cosh(0.0));
}

TEST(MATH_TEST, coshf) {
  ASSERT_FLOAT_EQ(1.0f, coshf(0.0f));
}

TEST(MATH_TEST, coshl) {
  ASSERT_DOUBLE_EQ(1.0L, coshl(0.0L));
}

TEST(MATH_TEST, sinh) {
  ASSERT_DOUBLE_EQ(0.0, sinh(0.0));
}

TEST(MATH_TEST, sinhf) {
  ASSERT_FLOAT_EQ(0.0f, sinhf(0.0f));
}

TEST(MATH_TEST, sinhl) {
  ASSERT_DOUBLE_EQ(0.0L, sinhl(0.0L));
}

TEST(MATH_TEST, tanh) {
  ASSERT_DOUBLE_EQ(0.0, tanh(0.0));
}

TEST(MATH_TEST, tanhf) {
  ASSERT_FLOAT_EQ(0.0f, tanhf(0.0f));
}

TEST(MATH_TEST, tanhl) {
  ASSERT_DOUBLE_EQ(0.0L, tanhl(0.0L));
}

TEST(MATH_TEST, log) {
  ASSERT_DOUBLE_EQ(1.0, log(M_E));
}

TEST(MATH_TEST, logf) {
  ASSERT_FLOAT_EQ(1.0f, logf(static_cast<float>(M_E)));
}

TEST(MATH_TEST, logl) {
  ASSERT_DOUBLE_EQ(1.0L, logl(M_E));
}

TEST(MATH_TEST, log2) {
  ASSERT_DOUBLE_EQ(12.0, log2(4096.0));
}

TEST(MATH_TEST, log2f) {
  ASSERT_FLOAT_EQ(12.0f, log2f(4096.0f));
}

TEST(MATH_TEST, log2l) {
  ASSERT_DOUBLE_EQ(12.0L, log2l(4096.0L));
}

TEST(MATH_TEST, log10) {
  ASSERT_DOUBLE_EQ(3.0, log10(1000.0));
}

TEST(MATH_TEST, log10f) {
  ASSERT_FLOAT_EQ(3.0f, log10f(1000.0f));
}

TEST(MATH_TEST, log10l) {
  ASSERT_DOUBLE_EQ(3.0L, log10l(1000.0L));
}

TEST(MATH_TEST, cbrt) {
  ASSERT_DOUBLE_EQ(3.0, cbrt(27.0));
}

TEST(MATH_TEST, cbrtf) {
  ASSERT_FLOAT_EQ(3.0f, cbrtf(27.0f));
}

TEST(MATH_TEST, cbrtl) {
  ASSERT_DOUBLE_EQ(3.0L, cbrtl(27.0L));
}

TEST(MATH_TEST, sqrt) {
  ASSERT_DOUBLE_EQ(2.0, sqrt(4.0));
}

TEST(MATH_TEST, sqrtf) {
  ASSERT_FLOAT_EQ(2.0f, sqrtf(4.0f));
}

TEST(MATH_TEST, sqrtl) {
  ASSERT_DOUBLE_EQ(2.0L, sqrtl(4.0L));
}

TEST(MATH_TEST, exp) {
  ASSERT_DOUBLE_EQ(1.0, exp(0.0));
  ASSERT_DOUBLE_EQ(M_E, exp(1.0));
}

TEST(MATH_TEST, expf) {
  ASSERT_FLOAT_EQ(1.0f, expf(0.0f));
  ASSERT_FLOAT_EQ(static_cast<float>(M_E), expf(1.0f));
}

TEST(MATH_TEST, expl) {
  ASSERT_DOUBLE_EQ(1.0L, expl(0.0L));
  ASSERT_DOUBLE_EQ(M_E, expl(1.0L));
}

TEST(MATH_TEST, exp2) {
  ASSERT_DOUBLE_EQ(8.0, exp2(3.0));
}

TEST(MATH_TEST, exp2f) {
  ASSERT_FLOAT_EQ(8.0f, exp2f(3.0f));
}

TEST(MATH_TEST, exp2l) {
  ASSERT_DOUBLE_EQ(8.0L, exp2l(3.0L));
}

TEST(MATH_TEST, expm1) {
  ASSERT_DOUBLE_EQ(M_E - 1.0, expm1(1.0));
}

TEST(MATH_TEST, expm1f) {
  ASSERT_FLOAT_EQ(static_cast<float>(M_E) - 1.0f, expm1f(1.0f));
}

TEST(MATH_TEST, expm1l) {
  ASSERT_DOUBLE_EQ(M_E - 1.0L, expm1l(1.0L));
}

TEST(MATH_TEST, pow) {
  ASSERT_TRUE(isnan(pow(nan(""), 3.0)));
  ASSERT_DOUBLE_EQ(1.0, (pow(1.0, nan(""))));
  ASSERT_TRUE(isnan(pow(2.0, nan(""))));
  ASSERT_DOUBLE_EQ(8.0, pow(2.0, 3.0));
}

TEST(MATH_TEST, powf) {
  ASSERT_TRUE(isnanf(powf(nanf(""), 3.0f)));
  ASSERT_FLOAT_EQ(1.0f, (powf(1.0f, nanf(""))));
  ASSERT_TRUE(isnanf(powf(2.0f, nanf(""))));
  ASSERT_FLOAT_EQ(8.0f, powf(2.0f, 3.0f));
}

TEST(MATH_TEST, powl) {
  ASSERT_TRUE(__isnanl(powl(nanl(""), 3.0L)));
  ASSERT_DOUBLE_EQ(1.0L, (powl(1.0L, nanl(""))));
  ASSERT_TRUE(__isnanl(powl(2.0L, nanl(""))));
  ASSERT_DOUBLE_EQ(8.0L, powl(2.0L, 3.0L));
}

TEST(MATH_TEST, ceil) {
  ASSERT_DOUBLE_EQ(1.0, ceil(0.9));
}

TEST(MATH_TEST, ceilf) {
  ASSERT_FLOAT_EQ(1.0f, ceilf(0.9f));
}

TEST(MATH_TEST, ceill) {
  ASSERT_DOUBLE_EQ(1.0L, ceill(0.9L));
}

TEST(MATH_TEST, floor) {
  ASSERT_DOUBLE_EQ(1.0, floor(1.1));
}

TEST(MATH_TEST, floorf) {
  ASSERT_FLOAT_EQ(1.0f, floorf(1.1f));
}

TEST(MATH_TEST, floorl) {
  ASSERT_DOUBLE_EQ(1.0L, floorl(1.1L));
}

TEST(MATH_TEST, fabs) {
  ASSERT_DOUBLE_EQ(1.0, fabs(-1.0));
}

TEST(MATH_TEST, fabsf) {
  ASSERT_FLOAT_EQ(1.0f, fabsf(-1.0f));
}

TEST(MATH_TEST, fabsl) {
  ASSERT_DOUBLE_EQ(1.0L, fabsl(-1.0L));
}

TEST(MATH_TEST, ldexp) {
  ASSERT_DOUBLE_EQ(16.0, ldexp(2.0, 3.0));
}

TEST(MATH_TEST, ldexpf) {
  ASSERT_FLOAT_EQ(16.0f, ldexpf(2.0f, 3.0f));
}

TEST(MATH_TEST, ldexpl) {
  ASSERT_DOUBLE_EQ(16.0L, ldexpl(2.0L, 3.0));
}

TEST(MATH_TEST, fmod) {
  ASSERT_DOUBLE_EQ(2.0, fmod(12.0, 10.0));

  // If x is an infinity, NaN is returned.
  ASSERT_TRUE(isnan(fmod(HUGE_VAL, 10.0f)));
  ASSERT_TRUE(isnan(fmod(-HUGE_VAL, 10.0f)));

  // If x or y is a NaN, NaN is returned.
  ASSERT_TRUE(isnan(fmod(nan(""), 10.0)));
  ASSERT_TRUE(isnan(fmod(12.0, nan(""))));

  // If y is 0, NaN is returned.
  ASSERT_TRUE(isnan(fmod(3.0, 0.0)));
}

TEST(MATH_TEST, fmodf) {
  ASSERT_FLOAT_EQ(2.0f, fmodf(12.0f, 10.0f));

  // If x is an infinity, NaN is returned.
  ASSERT_TRUE(isnanf(fmodf(HUGE_VALF, 10.0f)));
  ASSERT_TRUE(isnanf(fmodf(-HUGE_VALF, 10.0f)));

  // If x or y is a NaN, NaN is returned.
  ASSERT_TRUE(isnanf(fmodf(nanf(""), 10.0f)));
  ASSERT_TRUE(isnanf(fmodf(12.0f, nan(""))));

  // If y is 0, NaN is returned.
  ASSERT_TRUE(isnanf(fmodf(3.0f, 0.0f)));
}

TEST(MATH_TEST, fmodl) {
  ASSERT_DOUBLE_EQ(2.0L, fmodl(12.0L, 10.0L));

  // If x is an infinity, NaN is returned.
  ASSERT_TRUE(isnanl(fmodl(HUGE_VALL, 10.0L)));
  ASSERT_TRUE(isnanl(fmodl(-HUGE_VALL, 10.0L)));

  // If x or y is a NaN, NaN is returned.
  ASSERT_TRUE(isnanl(fmodl(nanl(""), 10.0L)));
  ASSERT_TRUE(isnanl(fmodl(12.0L, nanl(""))));

  // If y is 0, NaN is returned.
  ASSERT_TRUE(isnanl(fmodl(3.0L, 0.0L)));
}

TEST(MATH_TEST, remainder) {
  ASSERT_DOUBLE_EQ(2.0, remainder(12.0, 10.0));

  // If x or y is a NaN, NaN is returned.
  ASSERT_TRUE(isnan(remainder(nan(""), 10.0)));
  ASSERT_TRUE(isnan(remainder(12.0, nan(""))));

  // If x is an infinity, NaN is returned.
  ASSERT_TRUE(isnan(remainder(HUGE_VAL, 10.0)));
  ASSERT_TRUE(isnan(remainder(-HUGE_VAL, 10.0)));

  // If y is 0, NaN is returned.
  ASSERT_TRUE(isnan(remainder(12.0, 0.0)));
}

TEST(MATH_TEST, remainderf) {
  ASSERT_FLOAT_EQ(2.0f, remainderf(12.0f, 10.0f));

  // If x or y is a NaN, NaN is returned.
  ASSERT_TRUE(isnanf(remainderf(nanf(""), 10.0f)));
  ASSERT_TRUE(isnanf(remainderf(12.0f, nanf(""))));

  // If x is an infinity, NaN is returned.
  ASSERT_TRUE(isnanf(remainderf(HUGE_VALF, 10.0f)));
  ASSERT_TRUE(isnanf(remainderf(-HUGE_VALF, 10.0f)));

  // If y is 0, NaN is returned.
  ASSERT_TRUE(isnanf(remainderf(12.0f, 0.0f)));
}

TEST(MATH_TEST, remainderl) {
  ASSERT_DOUBLE_EQ(2.0L, remainderl(12.0L, 10.0L));

  // If x or y is a NaN, NaN is returned.
  ASSERT_TRUE(isnanl(remainderl(nanl(""), 10.0L)));
  ASSERT_TRUE(isnanl(remainderl(12.0L, nanl(""))));

  // If x is an infinity, NaN is returned.
  ASSERT_TRUE(isnanl(remainderl(HUGE_VALL, 10.0L)));
  ASSERT_TRUE(isnanl(remainderl(-HUGE_VALL, 10.0L)));

  // If y is 0, NaN is returned.
  ASSERT_TRUE(isnanl(remainderl(12.0L, 0.0L)));
}

TEST(MATH_TEST, drem) {
  ASSERT_DOUBLE_EQ(2.0, drem(12.0, 10.0));
}

TEST(MATH_TEST, dremf) {
  ASSERT_FLOAT_EQ(2.0f, dremf(12.0f, 10.0f));
}

TEST(MATH_TEST, fmax) {
  ASSERT_DOUBLE_EQ(12.0, fmax(12.0, 10.0));
  ASSERT_DOUBLE_EQ(12.0, fmax(12.0, nan("")));
  ASSERT_DOUBLE_EQ(12.0, fmax(nan(""), 12.0));
}

TEST(MATH_TEST, fmaxf) {
  ASSERT_FLOAT_EQ(12.0f, fmaxf(12.0f, 10.0f));
  ASSERT_FLOAT_EQ(12.0f, fmaxf(12.0f, nanf("")));
  ASSERT_FLOAT_EQ(12.0f, fmaxf(nanf(""), 12.0f));
}

TEST(MATH_TEST, fmaxl) {
  ASSERT_DOUBLE_EQ(12.0L, fmaxl(12.0L, 10.0L));
  ASSERT_DOUBLE_EQ(12.0L, fmaxl(12.0L, nanl("")));
  ASSERT_DOUBLE_EQ(12.0L, fmaxl(nanl(""), 12.0L));
}

TEST(MATH_TEST, fmin) {
  ASSERT_DOUBLE_EQ(10.0, fmin(12.0, 10.0));
  ASSERT_DOUBLE_EQ(12.0, fmin(12.0, nan("")));
  ASSERT_DOUBLE_EQ(12.0, fmin(nan(""), 12.0));
}

TEST(MATH_TEST, fminf) {
  ASSERT_FLOAT_EQ(10.0f, fminf(12.0f, 10.0f));
  ASSERT_FLOAT_EQ(12.0f, fminf(12.0f, nanf("")));
  ASSERT_FLOAT_EQ(12.0f, fminf(nanf(""), 12.0f));
}

TEST(MATH_TEST, fminl) {
  ASSERT_DOUBLE_EQ(10.0L, fminl(12.0L, 10.0L));
  ASSERT_DOUBLE_EQ(12.0L, fminl(12.0L, nanl("")));
  ASSERT_DOUBLE_EQ(12.0L, fminl(nanl(""), 12.0L));
}

TEST(MATH_TEST, fma) {
  ASSERT_DOUBLE_EQ(10.0, fma(2.0, 3.0, 4.0));
}

TEST(MATH_TEST, fmaf) {
  ASSERT_FLOAT_EQ(10.0f, fmaf(2.0f, 3.0f, 4.0f));
}

TEST(MATH_TEST, fmal) {
  ASSERT_DOUBLE_EQ(10.0L, fmal(2.0L, 3.0L, 4.0L));
}

TEST(MATH_TEST, hypot) {
  ASSERT_DOUBLE_EQ(5.0, hypot(3.0, 4.0));

  // If x or y is an infinity, returns positive infinity.
  ASSERT_EQ(HUGE_VAL, hypot(3.0, HUGE_VAL));
  ASSERT_EQ(HUGE_VAL, hypot(3.0, -HUGE_VAL));
  ASSERT_EQ(HUGE_VAL, hypot(HUGE_VAL, 4.0));
  ASSERT_EQ(HUGE_VAL, hypot(-HUGE_VAL, 4.0));

  // If x or y is a NaN, returns NaN.
  ASSERT_TRUE(isnan(hypot(3.0, nan(""))));
  ASSERT_TRUE(isnan(hypot(nan(""), 4.0)));
}

TEST(MATH_TEST, hypotf) {
  ASSERT_FLOAT_EQ(5.0f, hypotf(3.0f, 4.0f));

  // If x or y is an infinity, returns positive infinity.
  ASSERT_EQ(HUGE_VALF, hypotf(3.0f, HUGE_VALF));
  ASSERT_EQ(HUGE_VALF, hypotf(3.0f, -HUGE_VALF));
  ASSERT_EQ(HUGE_VALF, hypotf(HUGE_VALF, 4.0f));
  ASSERT_EQ(HUGE_VALF, hypotf(-HUGE_VALF, 4.0f));

  // If x or y is a NaN, returns NaN.
  ASSERT_TRUE(isnanf(hypotf(3.0f, nanf(""))));
  ASSERT_TRUE(isnanf(hypotf(nanf(""), 4.0f)));
}

TEST(MATH_TEST, hypotl) {
  ASSERT_DOUBLE_EQ(5.0L, hypotl(3.0L, 4.0L));

  // If x or y is an infinity, returns positive infinity.
  ASSERT_EQ(HUGE_VALL, hypotl(3.0L, HUGE_VALL));
  ASSERT_EQ(HUGE_VALL, hypotl(3.0L, -HUGE_VALL));
  ASSERT_EQ(HUGE_VALL, hypotl(HUGE_VALL, 4.0L));
  ASSERT_EQ(HUGE_VALL, hypotl(-HUGE_VALL, 4.0L));

  // If x or y is a NaN, returns NaN.
  ASSERT_TRUE(isnanl(hypotl(3.0L, nanl(""))));
  ASSERT_TRUE(isnanl(hypotl(nanl(""), 4.0L)));
}

TEST(MATH_TEST, erf) {
  ASSERT_DOUBLE_EQ(0.84270079294971489, erf(1.0));
}

TEST(MATH_TEST, erff) {
  ASSERT_FLOAT_EQ(0.84270078f, erff(1.0f));
}

TEST(MATH_TEST, erfl) {
  ASSERT_DOUBLE_EQ(0.84270079294971489L, erfl(1.0L));
}

TEST(MATH_TEST, erfc) {
  ASSERT_DOUBLE_EQ(0.15729920705028513, erfc(1.0));
}

TEST(MATH_TEST, erfcf) {
  ASSERT_FLOAT_EQ(0.15729921f, erfcf(1.0f));
}

TEST(MATH_TEST, erfcl) {
  ASSERT_DOUBLE_EQ(0.15729920705028513L, erfcl(1.0L));
}

TEST(MATH_TEST, lrint) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });

  fesetround(FE_UPWARD); // lrint/lrintf/lrintl obey the rounding mode.
  ASSERT_EQ(1235, lrint(1234.01));
  ASSERT_EQ(1235, lrintf(1234.01f));
  ASSERT_EQ(1235, lrintl(1234.01L));
  fesetround(FE_TOWARDZERO); // lrint/lrintf/lrintl obey the rounding mode.
  ASSERT_EQ(1234, lrint(1234.01));
  ASSERT_EQ(1234, lrintf(1234.01f));
  ASSERT_EQ(1234, lrintl(1234.01L));

  fesetround(FE_UPWARD); // llrint/llrintf/llrintl obey the rounding mode.
  ASSERT_EQ(1235L, llrint(1234.01));
  ASSERT_EQ(1235L, llrintf(1234.01f));
  ASSERT_EQ(1235L, llrintl(1234.01L));
  fesetround(FE_TOWARDZERO); // llrint/llrintf/llrintl obey the rounding mode.
  ASSERT_EQ(1234L, llrint(1234.01));
  ASSERT_EQ(1234L, llrintf(1234.01f));
  ASSERT_EQ(1234L, llrintl(1234.01L));
}

TEST(MATH_TEST, rint) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });

  fesetround(FE_UPWARD); // rint/rintf/rintl obey the rounding mode.
  feclearexcept(FE_ALL_EXCEPT); // rint/rintf/rintl do set the FE_INEXACT flag.
  ASSERT_EQ(1234.0, rint(1234.0));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) == 0);
  ASSERT_EQ(1235.0, rint(1234.01));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) != 0);

  feclearexcept(FE_ALL_EXCEPT); // rint/rintf/rintl do set the FE_INEXACT flag.
  ASSERT_EQ(1234.0f, rintf(1234.0f));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) == 0);
  ASSERT_EQ(1235.0f, rintf(1234.01f));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) != 0);

  feclearexcept(FE_ALL_EXCEPT); // rint/rintf/rintl do set the FE_INEXACT flag.
  ASSERT_EQ(1234.0, rintl(1234.0L));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) == 0);
  ASSERT_EQ(1235.0, rintl(1234.01L));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) != 0);

  fesetround(FE_TOWARDZERO); // rint/rintf obey the rounding mode.
  ASSERT_EQ(1234.0, rint(1234.01));
  ASSERT_EQ(1234.0f, rintf(1234.01f));
  ASSERT_EQ(1234.0, rintl(1234.01L));
}

TEST(MATH_TEST, nearbyint) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });
  fesetround(FE_UPWARD); // nearbyint/nearbyintf/nearbyintl obey the rounding mode.
  feclearexcept(FE_ALL_EXCEPT); // nearbyint/nearbyintf/nearbyintl don't set the FE_INEXACT flag.
  ASSERT_EQ(1234.0, nearbyint(1234.0));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) == 0);
  ASSERT_EQ(1235.0, nearbyint(1234.01));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) == 0);

  feclearexcept(FE_ALL_EXCEPT);
  ASSERT_EQ(1234.0f, nearbyintf(1234.0f));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) == 0);
  ASSERT_EQ(1235.0f, nearbyintf(1234.01f));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) == 0);

  feclearexcept(FE_ALL_EXCEPT); // nearbyint/nearbyintf/nearbyintl don't set the FE_INEXACT flag.
  ASSERT_EQ(1234.0, nearbyintl(1234.0L));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) == 0);
  ASSERT_EQ(1235.0, nearbyintl(1234.01L));
  ASSERT_TRUE((fetestexcept(FE_ALL_EXCEPT) & FE_INEXACT) == 0);

  fesetround(FE_TOWARDZERO); // nearbyint/nearbyintf/nearbyintl obey the rounding mode.
  ASSERT_EQ(1234.0, nearbyint(1234.01));
  ASSERT_EQ(1234.0f, nearbyintf(1234.01f));
  ASSERT_EQ(1234.0, nearbyintl(1234.01L));
}

TEST(MATH_TEST, lround) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });
  fesetround(FE_UPWARD); // lround ignores the rounding mode.
  ASSERT_EQ(1234, lround(1234.01));
  ASSERT_EQ(1234, lroundf(1234.01f));
  ASSERT_EQ(1234, lroundl(1234.01L));
}

TEST(MATH_TEST, llround) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });
  fesetround(FE_UPWARD); // llround ignores the rounding mode.
  ASSERT_EQ(1234L, llround(1234.01));
  ASSERT_EQ(1234L, llroundf(1234.01f));
  ASSERT_EQ(1234L, llroundl(1234.01L));
}

TEST(MATH_TEST, ilogb) {
  ASSERT_EQ(FP_ILOGB0, ilogb(0.0));
  ASSERT_EQ(FP_ILOGBNAN, ilogb(nan("")));
  ASSERT_EQ(INT_MAX, ilogb(HUGE_VAL));
  ASSERT_EQ(INT_MAX, ilogb(-HUGE_VAL));
  ASSERT_EQ(0, ilogb(1.0));
  ASSERT_EQ(3, ilogb(10.0));
}

TEST(MATH_TEST, ilogbf) {
  ASSERT_EQ(FP_ILOGB0, ilogbf(0.0f));
  ASSERT_EQ(FP_ILOGBNAN, ilogbf(nanf("")));
  ASSERT_EQ(INT_MAX, ilogbf(HUGE_VALF));
  ASSERT_EQ(INT_MAX, ilogbf(-HUGE_VALF));
  ASSERT_EQ(0, ilogbf(1.0f));
  ASSERT_EQ(3, ilogbf(10.0f));
}

TEST(MATH_TEST, ilogbl) {
  ASSERT_EQ(FP_ILOGB0, ilogbl(0.0L));
  ASSERT_EQ(FP_ILOGBNAN, ilogbl(nanl("")));
  ASSERT_EQ(INT_MAX, ilogbl(HUGE_VALL));
  ASSERT_EQ(INT_MAX, ilogbl(-HUGE_VALL));
  ASSERT_EQ(0L, ilogbl(1.0L));
  ASSERT_EQ(3L, ilogbl(10.0L));
}

TEST(MATH_TEST, logb) {
  ASSERT_EQ(-HUGE_VAL, logb(0.0));
  ASSERT_TRUE(isnan(logb(nan(""))));
  ASSERT_TRUE(isinf(logb(HUGE_VAL)));
  ASSERT_TRUE(isinf(logb(-HUGE_VAL)));
  ASSERT_EQ(0.0, logb(1.0));
  ASSERT_EQ(3.0, logb(10.0));
}

TEST(MATH_TEST, logbf) {
  ASSERT_EQ(-HUGE_VALF, logbf(0.0f));
  ASSERT_TRUE(isnanf(logbf(nanf(""))));
  ASSERT_TRUE(isinff(logbf(HUGE_VALF)));
  ASSERT_TRUE(isinff(logbf(-HUGE_VALF)));
  ASSERT_EQ(0.0f, logbf(1.0f));
  ASSERT_EQ(3.0f, logbf(10.0f));
}

TEST(MATH_TEST, logbl) {
  ASSERT_EQ(-HUGE_VAL, logbl(0.0L));
  ASSERT_TRUE(isnan(logbl(nanl(""))));
  ASSERT_TRUE(isinf(logbl(HUGE_VALL)));
  ASSERT_TRUE(isinf(logbl(-HUGE_VALL)));
  ASSERT_EQ(0.0L, logbl(1.0L));
  ASSERT_EQ(3.0L, logbl(10.0L));
}

TEST(MATH_TEST, log1p) {
  ASSERT_EQ(-HUGE_VAL, log1p(-1.0));
  ASSERT_TRUE(isnan(log1p(nan(""))));
  ASSERT_TRUE(isinf(log1p(HUGE_VAL)));
  ASSERT_TRUE(isnan(log1p(-HUGE_VAL)));
  ASSERT_DOUBLE_EQ(1.0, log1p(M_E - 1.0));
}

TEST(MATH_TEST, log1pf) {
  ASSERT_EQ(-HUGE_VALF, log1pf(-1.0f));
  ASSERT_TRUE(isnanf(log1pf(nanf(""))));
  ASSERT_TRUE(isinff(log1pf(HUGE_VALF)));
  ASSERT_TRUE(isnanf(log1pf(-HUGE_VALF)));
  ASSERT_FLOAT_EQ(1.0f, log1pf(static_cast<float>(M_E) - 1.0f));
}

TEST(MATH_TEST, log1pl) {
  ASSERT_EQ(-HUGE_VALL, log1pl(-1.0L));
  ASSERT_TRUE(isnanl(log1pl(nanl(""))));
  ASSERT_TRUE(isinfl(log1pl(HUGE_VALL)));
  ASSERT_TRUE(isnanl(log1pl(-HUGE_VALL)));
  ASSERT_DOUBLE_EQ(1.0L, log1pl(M_E - 1.0L));
}

TEST(MATH_TEST, fdim) {
  ASSERT_DOUBLE_EQ(0.0, fdim(1.0, 1.0));
  ASSERT_DOUBLE_EQ(1.0, fdim(2.0, 1.0));
  ASSERT_DOUBLE_EQ(0.0, fdim(1.0, 2.0));
}

TEST(MATH_TEST, fdimf) {
  ASSERT_FLOAT_EQ(0.0f, fdimf(1.0f, 1.0f));
  ASSERT_FLOAT_EQ(1.0f, fdimf(2.0f, 1.0f));
  ASSERT_FLOAT_EQ(0.0f, fdimf(1.0f, 2.0f));
}

TEST(MATH_TEST, fdiml) {
  ASSERT_DOUBLE_EQ(0.0L, fdiml(1.0L, 1.0L));
  ASSERT_DOUBLE_EQ(1.0L, fdiml(2.0L, 1.0L));
  ASSERT_DOUBLE_EQ(0.0L, fdiml(1.0L, 2.0L));
}

TEST(MATH_TEST, round) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });
  fesetround(FE_TOWARDZERO); // round ignores the rounding mode and always rounds away from zero.
  ASSERT_DOUBLE_EQ(1.0, round(0.5));
  ASSERT_DOUBLE_EQ(-1.0, round(-0.5));
  ASSERT_DOUBLE_EQ(0.0, round(0.0));
  ASSERT_DOUBLE_EQ(-0.0, round(-0.0));
  ASSERT_TRUE(isnan(round(nan(""))));
  ASSERT_DOUBLE_EQ(HUGE_VAL, round(HUGE_VAL));
  ASSERT_DOUBLE_EQ(-HUGE_VAL, round(-HUGE_VAL));
}

TEST(MATH_TEST, roundf) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });
  fesetround(FE_TOWARDZERO); // roundf ignores the rounding mode and always rounds away from zero.
  ASSERT_FLOAT_EQ(1.0f, roundf(0.5f));
  ASSERT_FLOAT_EQ(-1.0f, roundf(-0.5f));
  ASSERT_FLOAT_EQ(0.0f, roundf(0.0f));
  ASSERT_FLOAT_EQ(-0.0f, roundf(-0.0f));
  ASSERT_TRUE(isnanf(roundf(nanf(""))));
  ASSERT_FLOAT_EQ(HUGE_VALF, roundf(HUGE_VALF));
  ASSERT_FLOAT_EQ(-HUGE_VALF, roundf(-HUGE_VALF));
}

TEST(MATH_TEST, roundl) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });
  fesetround(FE_TOWARDZERO); // roundl ignores the rounding mode and always rounds away from zero.
  ASSERT_DOUBLE_EQ(1.0L, roundl(0.5L));
  ASSERT_DOUBLE_EQ(-1.0L, roundl(-0.5L));
  ASSERT_DOUBLE_EQ(0.0L, roundl(0.0L));
  ASSERT_DOUBLE_EQ(-0.0L, roundl(-0.0L));
  ASSERT_TRUE(isnan(roundl(nanl(""))));
  ASSERT_DOUBLE_EQ(HUGE_VALL, roundl(HUGE_VALL));
  ASSERT_DOUBLE_EQ(-HUGE_VALL, roundl(-HUGE_VALL));
}

TEST(MATH_TEST, trunc) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });
  fesetround(FE_UPWARD); // trunc ignores the rounding mode and always rounds toward zero.
  ASSERT_DOUBLE_EQ(1.0, trunc(1.5));
  ASSERT_DOUBLE_EQ(-1.0, trunc(-1.5));
  ASSERT_DOUBLE_EQ(0.0, trunc(0.0));
  ASSERT_DOUBLE_EQ(-0.0, trunc(-0.0));
  ASSERT_TRUE(isnan(trunc(nan(""))));
  ASSERT_DOUBLE_EQ(HUGE_VAL, trunc(HUGE_VAL));
  ASSERT_DOUBLE_EQ(-HUGE_VAL, trunc(-HUGE_VAL));
}

TEST(MATH_TEST, truncf) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });
  fesetround(FE_UPWARD); // truncf ignores the rounding mode and always rounds toward zero.
  ASSERT_FLOAT_EQ(1.0f, truncf(1.5f));
  ASSERT_FLOAT_EQ(-1.0f, truncf(-1.5f));
  ASSERT_FLOAT_EQ(0.0f, truncf(0.0f));
  ASSERT_FLOAT_EQ(-0.0f, truncf(-0.0f));
  ASSERT_TRUE(isnan(truncf(nanf(""))));
  ASSERT_FLOAT_EQ(HUGE_VALF, truncf(HUGE_VALF));
  ASSERT_FLOAT_EQ(-HUGE_VALF, truncf(-HUGE_VALF));
}

TEST(MATH_TEST, truncl) {
  auto guard = android::base::make_scope_guard([]() { fesetenv(FE_DFL_ENV); });
  fesetround(FE_UPWARD); // truncl ignores the rounding mode and always rounds toward zero.
  ASSERT_DOUBLE_EQ(1.0L, truncl(1.5L));
  ASSERT_DOUBLE_EQ(-1.0L, truncl(-1.5L));
  ASSERT_DOUBLE_EQ(0.0L, truncl(0.0L));
  ASSERT_DOUBLE_EQ(-0.0L, truncl(-0.0L));
  ASSERT_TRUE(isnan(truncl(nan(""))));
  ASSERT_DOUBLE_EQ(HUGE_VALL, truncl(HUGE_VALL));
  ASSERT_DOUBLE_EQ(-HUGE_VALL, truncl(-HUGE_VALL));
}

TEST(MATH_TEST, nextafter) {
  ASSERT_DOUBLE_EQ(0.0, nextafter(0.0, 0.0));
  ASSERT_DOUBLE_EQ(4.9406564584124654e-324, nextafter(0.0, 1.0));
  ASSERT_DOUBLE_EQ(-4.9406564584124654e-324, nextafter(0.0, -1.0));
}

TEST(MATH_TEST, nextafterf) {
  ASSERT_FLOAT_EQ(0.0f, nextafterf(0.0f, 0.0f));
  ASSERT_FLOAT_EQ(1.4012985e-45f, nextafterf(0.0f, 1.0f));
  ASSERT_FLOAT_EQ(-1.4012985e-45f, nextafterf(0.0f, -1.0f));
}

TEST(MATH_TEST, nextafterl) {
  ASSERT_DOUBLE_EQ(0.0L, nextafterl(0.0L, 0.0L));
  // Use a runtime value to accomodate the case when
  // sizeof(double) == sizeof(long double)
  long double smallest_positive = ldexpl(1.0L, LDBL_MIN_EXP - LDBL_MANT_DIG);
  ASSERT_DOUBLE_EQ(smallest_positive, nextafterl(0.0L, 1.0L));
  ASSERT_DOUBLE_EQ(-smallest_positive, nextafterl(0.0L, -1.0L));
}

TEST(MATH_TEST, nexttoward) {
  ASSERT_DOUBLE_EQ(0.0, nexttoward(0.0, 0.0L));
  ASSERT_DOUBLE_EQ(4.9406564584124654e-324, nexttoward(0.0, 1.0L));
  ASSERT_DOUBLE_EQ(-4.9406564584124654e-324, nexttoward(0.0, -1.0L));
}

TEST(MATH_TEST, nexttowardf) {
  ASSERT_FLOAT_EQ(0.0f, nexttowardf(0.0f, 0.0L));
  ASSERT_FLOAT_EQ(1.4012985e-45f, nexttowardf(0.0f, 1.0L));
  ASSERT_FLOAT_EQ(-1.4012985e-45f, nexttowardf(0.0f, -1.0L));
}

TEST(MATH_TEST, nexttowardl) {
  ASSERT_DOUBLE_EQ(0.0L, nexttowardl(0.0L, 0.0L));
  // Use a runtime value to accomodate the case when
  // sizeof(double) == sizeof(long double)
  long double smallest_positive = ldexpl(1.0L, LDBL_MIN_EXP - LDBL_MANT_DIG);
  ASSERT_DOUBLE_EQ(smallest_positive, nexttowardl(0.0L, 1.0L));
  ASSERT_DOUBLE_EQ(-smallest_positive, nexttowardl(0.0L, -1.0L));
}

TEST(MATH_TEST, copysign) {
  ASSERT_DOUBLE_EQ(0.0, copysign(0.0, 1.0));
  ASSERT_DOUBLE_EQ(-0.0, copysign(0.0, -1.0));
  ASSERT_DOUBLE_EQ(2.0, copysign(2.0, 1.0));
  ASSERT_DOUBLE_EQ(-2.0, copysign(2.0, -1.0));
}

TEST(MATH_TEST, copysignf) {
  ASSERT_FLOAT_EQ(0.0f, copysignf(0.0f, 1.0f));
  ASSERT_FLOAT_EQ(-0.0f, copysignf(0.0f, -1.0f));
  ASSERT_FLOAT_EQ(2.0f, copysignf(2.0f, 1.0f));
  ASSERT_FLOAT_EQ(-2.0f, copysignf(2.0f, -1.0f));
}

TEST(MATH_TEST, copysignl) {
  ASSERT_DOUBLE_EQ(0.0L, copysignl(0.0L, 1.0L));
  ASSERT_DOUBLE_EQ(-0.0L, copysignl(0.0L, -1.0L));
  ASSERT_DOUBLE_EQ(2.0L, copysignl(2.0L, 1.0L));
  ASSERT_DOUBLE_EQ(-2.0L, copysignl(2.0L, -1.0L));
}

TEST(MATH_TEST, significand) {
  ASSERT_DOUBLE_EQ(0.0, significand(0.0));
  ASSERT_DOUBLE_EQ(1.2, significand(1.2));
  ASSERT_DOUBLE_EQ(1.53125, significand(12.25));
}

TEST(MATH_TEST, significandf) {
  ASSERT_FLOAT_EQ(0.0f, significandf(0.0f));
  ASSERT_FLOAT_EQ(1.2f, significandf(1.2f));
  ASSERT_FLOAT_EQ(1.53125f, significandf(12.25f));
}

TEST(MATH_TEST, significandl) {
  ASSERT_DOUBLE_EQ(0.0L, significandl(0.0L));
  ASSERT_DOUBLE_EQ(1.2L, significandl(1.2L));
  ASSERT_DOUBLE_EQ(1.53125L, significandl(12.25L));
}

TEST(MATH_TEST, scalb) {
  ASSERT_DOUBLE_EQ(12.0, scalb(3.0, 2.0));
}

TEST(MATH_TEST, scalbf) {
  ASSERT_FLOAT_EQ(12.0f, scalbf(3.0f, 2.0f));
}

TEST(MATH_TEST, scalbln) {
  ASSERT_DOUBLE_EQ(12.0, scalbln(3.0, 2L));
}

TEST(MATH_TEST, scalblnf) {
  ASSERT_FLOAT_EQ(12.0f, scalblnf(3.0f, 2L));
}

TEST(MATH_TEST, scalblnl) {
  ASSERT_DOUBLE_EQ(12.0L, scalblnl(3.0L, 2L));
}

TEST(MATH_TEST, scalbn) {
  ASSERT_DOUBLE_EQ(12.0, scalbn(3.0, 2));
}

TEST(MATH_TEST, scalbnf) {
  ASSERT_FLOAT_EQ(12.0f, scalbnf(3.0f, 2));
}

TEST(MATH_TEST, scalbnl) {
  ASSERT_DOUBLE_EQ(12.0L, scalbnl(3.0L, 2));
}

TEST(MATH_TEST, gamma) {
  ASSERT_DOUBLE_EQ(log(24.0), gamma(5.0));
}

TEST(MATH_TEST, gammaf) {
  ASSERT_FLOAT_EQ(logf(24.0f), gammaf(5.0f));
}

TEST(MATH_TEST, gamma_r) {
#if defined(__BIONIC__)
  int sign;
  ASSERT_DOUBLE_EQ(log(24.0), gamma_r(5.0, &sign));
  ASSERT_EQ(1, sign);
#else // __BIONIC__
  GTEST_SKIP() << "glibc doesn't have gamma_r";
#endif // __BIONIC__
}

TEST(MATH_TEST, gammaf_r) {
#if defined(__BIONIC__)
  int sign;
  ASSERT_FLOAT_EQ(logf(24.0f), gammaf_r(5.0f, &sign));
  ASSERT_EQ(1, sign);
#else // __BIONIC__
  GTEST_SKIP() << "glibc doesn't have gammaf_r";
#endif // __BIONIC__
}

TEST(MATH_TEST, lgamma) {
  ASSERT_DOUBLE_EQ(log(24.0), lgamma(5.0));
}

TEST(MATH_TEST, lgammaf) {
  ASSERT_FLOAT_EQ(logf(24.0f), lgammaf(5.0f));
}

TEST(MATH_TEST, lgammal) {
  ASSERT_DOUBLE_EQ(logl(24.0L), lgammal(5.0L));
}

TEST(MATH_TEST, lgamma_r) {
  int sign;
  ASSERT_DOUBLE_EQ(log(24.0), lgamma_r(5.0, &sign));
  ASSERT_EQ(1, sign);
}

TEST(MATH_TEST, lgamma_r_17471883) {
  int sign;

  sign = 0;
  ASSERT_DOUBLE_EQ(HUGE_VAL, lgamma_r(0.0, &sign));
  ASSERT_EQ(1, sign);
  sign = 0;
  ASSERT_DOUBLE_EQ(HUGE_VAL, lgamma_r(-0.0, &sign));
  ASSERT_EQ(-1, sign);
}

TEST(MATH_TEST, lgammaf_r) {
  int sign;
  ASSERT_FLOAT_EQ(logf(24.0f), lgammaf_r(5.0f, &sign));
  ASSERT_EQ(1, sign);
}

TEST(MATH_TEST, lgammaf_r_17471883) {
  int sign;

  sign = 0;
  ASSERT_FLOAT_EQ(HUGE_VALF, lgammaf_r(0.0f, &sign));
  ASSERT_EQ(1, sign);
  sign = 0;
  ASSERT_FLOAT_EQ(HUGE_VALF, lgammaf_r(-0.0f, &sign));
  ASSERT_EQ(-1, sign);
}

TEST(MATH_TEST, lgammal_r) {
  int sign;
  ASSERT_DOUBLE_EQ(log(24.0L), lgamma_r(5.0L, &sign));
  ASSERT_EQ(1, sign);
}

TEST(MATH_TEST, lgammal_r_17471883) {
  int sign;

  sign = 0;
  ASSERT_DOUBLE_EQ(HUGE_VAL, lgammal_r(0.0L, &sign));
  ASSERT_EQ(1, sign);
  sign = 0;
  ASSERT_DOUBLE_EQ(HUGE_VAL, lgammal_r(-0.0L, &sign));
  ASSERT_EQ(-1, sign);
}

TEST(MATH_TEST, tgamma) {
  ASSERT_DOUBLE_EQ(24.0, tgamma(5.0));
}

TEST(MATH_TEST, tgammaf) {
  ASSERT_FLOAT_EQ(24.0f, tgammaf(5.0f));
}

TEST(MATH_TEST, tgammal) {
  ASSERT_DOUBLE_EQ(24.0L, tgammal(5.0L));
}

TEST(MATH_TEST, j0) {
  ASSERT_DOUBLE_EQ(1.0, j0(0.0));
  ASSERT_DOUBLE_EQ(0.76519768655796661, j0(1.0));
}

TEST(MATH_TEST, j0f) {
  ASSERT_FLOAT_EQ(1.0f, j0f(0.0f));
  ASSERT_FLOAT_EQ(0.76519769f, j0f(1.0f));
}

TEST(MATH_TEST, j1) {
  ASSERT_DOUBLE_EQ(0.0, j1(0.0));
  ASSERT_DOUBLE_EQ(0.44005058574493355, j1(1.0));
}

TEST(MATH_TEST, j1f) {
  ASSERT_FLOAT_EQ(0.0f, j1f(0.0f));
  ASSERT_FLOAT_EQ(0.44005057f, j1f(1.0f));
}

TEST(MATH_TEST, jn) {
  ASSERT_DOUBLE_EQ(0.0, jn(4, 0.0));
  ASSERT_DOUBLE_EQ(0.0024766389641099553, jn(4, 1.0));
}

TEST(MATH_TEST, jnf) {
  ASSERT_FLOAT_EQ(0.0f, jnf(4, 0.0f));
  ASSERT_FLOAT_EQ(0.0024766389f, jnf(4, 1.0f));
}

TEST(MATH_TEST, y0) {
  ASSERT_DOUBLE_EQ(-HUGE_VAL, y0(0.0));
  ASSERT_DOUBLE_EQ(0.08825696421567697, y0(1.0));
}

TEST(MATH_TEST, y0f) {
  ASSERT_FLOAT_EQ(-HUGE_VALF, y0f(0.0f));
  ASSERT_FLOAT_EQ(0.088256963f, y0f(1.0f));
}

TEST(MATH_TEST, y1) {
  ASSERT_DOUBLE_EQ(-HUGE_VAL, y1(0.0));
  ASSERT_DOUBLE_EQ(-0.78121282130028868, y1(1.0));
}

TEST(MATH_TEST, y1f) {
  ASSERT_FLOAT_EQ(-HUGE_VALF, y1f(0.0f));
  ASSERT_FLOAT_EQ(-0.78121281f, y1f(1.0f));
}

TEST(MATH_TEST, yn) {
  ASSERT_DOUBLE_EQ(-HUGE_VAL, yn(4, 0.0));
  ASSERT_DOUBLE_EQ(-33.278423028972114, yn(4, 1.0));
}

TEST(MATH_TEST, ynf) {
  ASSERT_FLOAT_EQ(-HUGE_VALF, ynf(4, 0.0f));
  ASSERT_FLOAT_EQ(-33.278423f, ynf(4, 1.0f));
}

TEST(MATH_TEST, frexp) {
  int exp;
  double dr = frexp(1024.0, &exp);
  ASSERT_DOUBLE_EQ(1024.0, scalbn(dr, exp));
}

TEST(MATH_TEST, frexpf) {
  int exp;
  float fr = frexpf(1024.0f, &exp);
  ASSERT_FLOAT_EQ(1024.0f, scalbnf(fr, exp));
}

TEST(MATH_TEST, frexpl) {
  int exp;
  long double ldr = frexpl(1024.0L, &exp);
  ASSERT_DOUBLE_EQ(1024.0L, scalbnl(ldr, exp));
}

TEST(MATH_TEST, modf) {
  double di;
  double df = modf(123.75, &di);
  ASSERT_DOUBLE_EQ(123.0, di);
  ASSERT_DOUBLE_EQ(0.75, df);
}

TEST(MATH_TEST, modff) {
  float fi;
  float ff = modff(123.75f, &fi);
  ASSERT_FLOAT_EQ(123.0f, fi);
  ASSERT_FLOAT_EQ(0.75f, ff);
}

TEST(MATH_TEST, modfl) {
  long double ldi;
  long double ldf = modfl(123.75L, &ldi);
  ASSERT_DOUBLE_EQ(123.0L, ldi);
  ASSERT_DOUBLE_EQ(0.75L, ldf);
}

TEST(MATH_TEST, remquo) {
  int q;
  double d = remquo(13.0, 4.0, &q);
  ASSERT_EQ(3, q);
  ASSERT_DOUBLE_EQ(1.0, d);

  // If x or y is a NaN, NaN is returned.
  ASSERT_TRUE(isnan(remquo(nan(""), 10.0, &q)));
  ASSERT_TRUE(isnan(remquo(12.0, nan(""), &q)));

  // If x is an infinity, NaN is returned.
  ASSERT_TRUE(isnan(remquo(HUGE_VAL, 10.0, &q)));
  ASSERT_TRUE(isnan(remquo(-HUGE_VAL, 10.0, &q)));

  // If y is 0, NaN is returned.
  ASSERT_TRUE(isnan(remquo(12.0, 0.0, &q)));
}

TEST(MATH_TEST, remquof) {
  int q;
  float f = remquof(13.0f, 4.0f, &q);
  ASSERT_EQ(3, q);
  ASSERT_FLOAT_EQ(1.0, f);

  // If x or y is a NaN, NaN is returned.
  ASSERT_TRUE(isnanf(remquof(nanf(""), 10.0f, &q)));
  ASSERT_TRUE(isnanf(remquof(12.0f, nanf(""), &q)));

  // If x is an infinity, NaN is returned.
  ASSERT_TRUE(isnanf(remquof(HUGE_VALF, 10.0f, &q)));
  ASSERT_TRUE(isnanf(remquof(-HUGE_VALF, 10.0f, &q)));

  // If y is 0, NaN is returned.
  ASSERT_TRUE(isnanf(remquof(12.0f, 0.0f, &q)));
}

TEST(MATH_TEST, remquol) {
  int q;
  long double ld = remquol(13.0L, 4.0L, &q);
  ASSERT_DOUBLE_EQ(3L, q);
  ASSERT_DOUBLE_EQ(1.0L, ld);

  // If x or y is a NaN, NaN is returned.
  ASSERT_TRUE(isnanl(remquol(nanl(""), 10.0L, &q)));
  ASSERT_TRUE(isnanl(remquol(12.0L, nanl(""), &q)));

  // If x is an infinity, NaN is returned.
  ASSERT_TRUE(isnanl(remquol(HUGE_VALL, 10.0L, &q)));
  ASSERT_TRUE(isnanl(remquol(-HUGE_VALL, 10.0L, &q)));

  // If y is 0, NaN is returned.
  ASSERT_TRUE(isnanl(remquol(12.0L, 0.0L, &q)));
}

// https://code.google.com/p/android/issues/detail?id=6697
TEST(MATH_TEST, frexpf_public_bug_6697) {
  int exp;
  float fr = frexpf(14.1f, &exp);
  ASSERT_FLOAT_EQ(14.1f, scalbnf(fr, exp));
}

TEST(MATH_TEST, exp2_STRICT_ALIGN_OpenBSD_bug) {
  // OpenBSD/x86's libm had a bug here, but it was already fixed in FreeBSD:
  // http://svnweb.FreeBSD.org/base/head/lib/msun/src/math_private.h?revision=240827&view=markup
  ASSERT_DOUBLE_EQ(5.0, exp2(log2(5)));
  ASSERT_FLOAT_EQ(5.0f, exp2f(log2f(5)));
  ASSERT_DOUBLE_EQ(5.0L, exp2l(log2l(5)));
}

TEST(MATH_TEST, nextafterl_OpenBSD_bug) {
  // OpenBSD/x86's libm had a bug here.
  ASSERT_TRUE(nextafter(1.0, 0.0) - 1.0 < 0.0);
  ASSERT_TRUE(nextafterf(1.0f, 0.0f) - 1.0f < 0.0f);
  ASSERT_TRUE(nextafterl(1.0L, 0.0L) - 1.0L < 0.0L);
}

#include "math_data/acos_intel_data.h"
TEST(MATH_TEST, acos_intel) {
  DoMathDataTest<1>(g_acos_intel_data, acos);
}

#include "math_data/acosf_intel_data.h"
TEST(MATH_TEST, acosf_intel) {
  DoMathDataTest<1>(g_acosf_intel_data, acosf);
}

#include "math_data/acosh_intel_data.h"
TEST(MATH_TEST, acosh_intel) {
  DoMathDataTest<2>(g_acosh_intel_data, acosh);
}

#include "math_data/acoshf_intel_data.h"
TEST(MATH_TEST, acoshf_intel) {
  DoMathDataTest<2>(g_acoshf_intel_data, acoshf);
}

#include "math_data/asin_intel_data.h"
TEST(MATH_TEST, asin_intel) {
  DoMathDataTest<1>(g_asin_intel_data, asin);
}

#include "math_data/asinf_intel_data.h"
TEST(MATH_TEST, asinf_intel) {
  DoMathDataTest<1>(g_asinf_intel_data, asinf);
}

#include "math_data/asinh_intel_data.h"
TEST(MATH_TEST, asinh_intel) {
  DoMathDataTest<2>(g_asinh_intel_data, asinh);
}

#include "math_data/asinhf_intel_data.h"
TEST(MATH_TEST, asinhf_intel) {
  DoMathDataTest<2>(g_asinhf_intel_data, asinhf);
}

#include "math_data/atan2_intel_data.h"
TEST(MATH_TEST, atan2_intel) {
  DoMathDataTest<2>(g_atan2_intel_data, atan2);
}

#include "math_data/atan2f_intel_data.h"
TEST(MATH_TEST, atan2f_intel) {
  DoMathDataTest<2>(g_atan2f_intel_data, atan2f);
}

#include "math_data/atan_intel_data.h"
TEST(MATH_TEST, atan_intel) {
  DoMathDataTest<1>(g_atan_intel_data, atan);
}

#include "math_data/atanf_intel_data.h"
TEST(MATH_TEST, atanf_intel) {
  DoMathDataTest<1>(g_atanf_intel_data, atanf);
}

#include "math_data/atanh_intel_data.h"
TEST(MATH_TEST, atanh_intel) {
  DoMathDataTest<2>(g_atanh_intel_data, atanh);
}

#include "math_data/atanhf_intel_data.h"
TEST(MATH_TEST, atanhf_intel) {
  DoMathDataTest<2>(g_atanhf_intel_data, atanhf);
}

#include "math_data/cbrt_intel_data.h"
TEST(MATH_TEST, cbrt_intel) {
  DoMathDataTest<1>(g_cbrt_intel_data, cbrt);
}

#include "math_data/cbrtf_intel_data.h"
TEST(MATH_TEST, cbrtf_intel) {
  DoMathDataTest<1>(g_cbrtf_intel_data, cbrtf);
}

#include "math_data/ceil_intel_data.h"
TEST(MATH_TEST, ceil_intel) {
  DoMathDataTest<1>(g_ceil_intel_data, ceil);
}

#include "math_data/ceilf_intel_data.h"
TEST(MATH_TEST, ceilf_intel) {
  DoMathDataTest<1>(g_ceilf_intel_data, ceilf);
}

#include "math_data/copysign_intel_data.h"
TEST(MATH_TEST, copysign_intel) {
  DoMathDataTest<1>(g_copysign_intel_data, copysign);
}

#include "math_data/copysignf_intel_data.h"
TEST(MATH_TEST, copysignf_intel) {
  DoMathDataTest<1>(g_copysignf_intel_data, copysignf);
}

#include "math_data/cos_intel_data.h"
TEST(MATH_TEST, cos_intel) {
  DoMathDataTest<1>(g_cos_intel_data, cos);
}

#include "math_data/cosf_intel_data.h"
TEST(MATH_TEST, cosf_intel) {
  DoMathDataTest<1>(g_cosf_intel_data, cosf);
}

#include "math_data/cosh_intel_data.h"
TEST(MATH_TEST, cosh_intel) {
  DoMathDataTest<2>(g_cosh_intel_data, cosh);
}

#include "math_data/coshf_intel_data.h"
TEST(MATH_TEST, coshf_intel) {
  DoMathDataTest<2>(g_coshf_intel_data, coshf);
}

#include "math_data/exp_intel_data.h"
TEST(MATH_TEST, exp_intel) {
  DoMathDataTest<1>(g_exp_intel_data, exp);
}

#include "math_data/expf_intel_data.h"
TEST(MATH_TEST, expf_intel) {
  DoMathDataTest<1>(g_expf_intel_data, expf);
}

#include "math_data/exp2_intel_data.h"
TEST(MATH_TEST, exp2_intel) {
  DoMathDataTest<1>(g_exp2_intel_data, exp2);
}

#include "math_data/exp2f_intel_data.h"
TEST(MATH_TEST, exp2f_intel) {
  DoMathDataTest<1>(g_exp2f_intel_data, exp2f);
}

#include "math_data/expm1_intel_data.h"
TEST(MATH_TEST, expm1_intel) {
  DoMathDataTest<1>(g_expm1_intel_data, expm1);
}

#include "math_data/expm1f_intel_data.h"
TEST(MATH_TEST, expm1f_intel) {
  DoMathDataTest<1>(g_expm1f_intel_data, expm1f);
}

#include "math_data/fabs_intel_data.h"
TEST(MATH_TEST, fabs_intel) {
  DoMathDataTest<1>(g_fabs_intel_data, fabs);
}

#include "math_data/fabsf_intel_data.h"
TEST(MATH_TEST, fabsf_intel) {
  DoMathDataTest<1>(g_fabsf_intel_data, fabsf);
}

#include "math_data/fdim_intel_data.h"
TEST(MATH_TEST, fdim_intel) {
  DoMathDataTest<1>(g_fdim_intel_data, fdim);
}

#include "math_data/fdimf_intel_data.h"
TEST(MATH_TEST, fdimf_intel) {
  DoMathDataTest<1>(g_fdimf_intel_data, fdimf);
}

#include "math_data/floor_intel_data.h"
TEST(MATH_TEST, floor_intel) {
  DoMathDataTest<1>(g_floor_intel_data, floor);
}

#include "math_data/floorf_intel_data.h"
TEST(MATH_TEST, floorf_intel) {
  DoMathDataTest<1>(g_floorf_intel_data, floorf);
}

#include "math_data/fma_intel_data.h"
TEST(MATH_TEST, fma_intel) {
  DoMathDataTest<1>(g_fma_intel_data, fma);
}

#include "math_data/fmaf_intel_data.h"
TEST(MATH_TEST, fmaf_intel) {
  DoMathDataTest<1>(g_fmaf_intel_data, fmaf);
}

#include "math_data/fmax_intel_data.h"
TEST(MATH_TEST, fmax_intel) {
  DoMathDataTest<1>(g_fmax_intel_data, fmax);
}

#include "math_data/fmaxf_intel_data.h"
TEST(MATH_TEST, fmaxf_intel) {
  DoMathDataTest<1>(g_fmaxf_intel_data, fmaxf);
}

#include "math_data/fmin_intel_data.h"
TEST(MATH_TEST, fmin_intel) {
  DoMathDataTest<1>(g_fmin_intel_data, fmin);
}

#include "math_data/fminf_intel_data.h"
TEST(MATH_TEST, fminf_intel) {
  DoMathDataTest<1>(g_fminf_intel_data, fminf);
}

#include "math_data/fmod_intel_data.h"
TEST(MATH_TEST, fmod_intel) {
  DoMathDataTest<1>(g_fmod_intel_data, fmod);
}

#include "math_data/fmodf_intel_data.h"
TEST(MATH_TEST, fmodf_intel) {
  DoMathDataTest<1>(g_fmodf_intel_data, fmodf);
}

#include "math_data/frexp_intel_data.h"
TEST(MATH_TEST, frexp_intel) {
  DoMathDataTest<1>(g_frexp_intel_data, frexp);
}

#include "math_data/frexpf_intel_data.h"
TEST(MATH_TEST, frexpf_intel) {
  DoMathDataTest<1>(g_frexpf_intel_data, frexpf);
}

#include "math_data/hypot_intel_data.h"
TEST(MATH_TEST, hypot_intel) {
  DoMathDataTest<1>(g_hypot_intel_data, hypot);
}

#include "math_data/hypotf_intel_data.h"
TEST(MATH_TEST, hypotf_intel) {
  DoMathDataTest<1>(g_hypotf_intel_data, hypotf);
}

#include "math_data/ilogb_intel_data.h"
TEST(MATH_TEST, ilogb_intel) {
  DoMathDataTest<1>(g_ilogb_intel_data, ilogb);
}

#include "math_data/ilogbf_intel_data.h"
TEST(MATH_TEST, ilogbf_intel) {
  DoMathDataTest<1>(g_ilogbf_intel_data, ilogbf);
}

#include "math_data/ldexp_intel_data.h"
TEST(MATH_TEST, ldexp_intel) {
  DoMathDataTest<1>(g_ldexp_intel_data, ldexp);
}

#include "math_data/ldexpf_intel_data.h"
TEST(MATH_TEST, ldexpf_intel) {
  DoMathDataTest<1>(g_ldexpf_intel_data, ldexpf);
}

#include "math_data/llrint_intel_data.h"
TEST(MATH_TEST, llrint_intel) {
  DoMathDataTest<1>(g_llrint_intel_data, llrint);
}

#include "math_data/llrintf_intel_data.h"
TEST(MATH_TEST, llrintf_intel) {
  DoMathDataTest<1>(g_llrintf_intel_data, llrintf);
}

#include "math_data/log_intel_data.h"
TEST(MATH_TEST, log_intel) {
  DoMathDataTest<1>(g_log_intel_data, log);
}

#include "math_data/logf_intel_data.h"
TEST(MATH_TEST, logf_intel) {
  DoMathDataTest<1>(g_logf_intel_data, logf);
}

#include "math_data/log10_intel_data.h"
TEST(MATH_TEST, log10_intel) {
  DoMathDataTest<1>(g_log10_intel_data, log10);
}

#include "math_data/log10f_intel_data.h"
TEST(MATH_TEST, log10f_intel) {
  DoMathDataTest<1>(g_log10f_intel_data, log10f);
}

#include "math_data/log1p_intel_data.h"
TEST(MATH_TEST, log1p_intel) {
  DoMathDataTest<1>(g_log1p_intel_data, log1p);
}

#include "math_data/log1pf_intel_data.h"
TEST(MATH_TEST, log1pf_intel) {
  DoMathDataTest<1>(g_log1pf_intel_data, log1pf);
}

#include "math_data/log2_intel_data.h"
TEST(MATH_TEST, log2_intel) {
  DoMathDataTest<1>(g_log2_intel_data, log2);
}

#include "math_data/log2f_intel_data.h"
TEST(MATH_TEST, log2f_intel) {
  DoMathDataTest<1>(g_log2f_intel_data, log2f);
}

#include "math_data/logb_intel_data.h"
TEST(MATH_TEST, logb_intel) {
  DoMathDataTest<1>(g_logb_intel_data, logb);
}

#include "math_data/logbf_intel_data.h"
TEST(MATH_TEST, logbf_intel) {
  DoMathDataTest<1>(g_logbf_intel_data, logbf);
}

#include "math_data/lrint_intel_data.h"
TEST(MATH_TEST, lrint_intel) {
  DoMathDataTest<1>(g_lrint_intel_data, lrint);
}

#include "math_data/lrintf_intel_data.h"
TEST(MATH_TEST, lrintf_intel) {
  DoMathDataTest<1>(g_lrintf_intel_data, lrintf);
}

#include "math_data/modf_intel_data.h"
TEST(MATH_TEST, modf_intel) {
  DoMathDataTest<1>(g_modf_intel_data, modf);
}

#include "math_data/modff_intel_data.h"
TEST(MATH_TEST, modff_intel) {
  DoMathDataTest<1>(g_modff_intel_data, modff);
}

#include "math_data/nearbyint_intel_data.h"
TEST(MATH_TEST, nearbyint_intel) {
  DoMathDataTest<1>(g_nearbyint_intel_data, nearbyint);
}

#include "math_data/nearbyintf_intel_data.h"
TEST(MATH_TEST, nearbyintf_intel) {
  DoMathDataTest<1>(g_nearbyintf_intel_data, nearbyintf);
}

#include "math_data/nextafter_intel_data.h"
TEST(MATH_TEST, nextafter_intel) {
  DoMathDataTest<1>(g_nextafter_intel_data, nextafter);
}

#include "math_data/nextafterf_intel_data.h"
TEST(MATH_TEST, nextafterf_intel) {
  DoMathDataTest<1>(g_nextafterf_intel_data, nextafterf);
}

#include "math_data/pow_intel_data.h"
TEST(MATH_TEST, pow_intel) {
  DoMathDataTest<1>(g_pow_intel_data, pow);
}

#include "math_data/powf_intel_data.h"
TEST(MATH_TEST, powf_intel) {
  DoMathDataTest<1>(g_powf_intel_data, powf);
}

#include "math_data/remainder_intel_data.h"
TEST(MATH_TEST, remainder_intel) {
  DoMathDataTest<1>(g_remainder_intel_data, remainder);
}

#include "math_data/remainderf_intel_data.h"
TEST(MATH_TEST, remainderf_intel) {
  DoMathDataTest<1>(g_remainderf_intel_data, remainderf);
}

#include "math_data/remquo_intel_data.h"
TEST(MATH_TEST, remquo_intel) {
  DoMathDataTest<1>(g_remquo_intel_data, remquo);
}

#include "math_data/remquof_intel_data.h"
TEST(MATH_TEST, remquof_intel) {
  DoMathDataTest<1>(g_remquof_intel_data, remquof);
}

#include "math_data/rint_intel_data.h"
TEST(MATH_TEST, rint_intel) {
  DoMathDataTest<1>(g_rint_intel_data, rint);
}

#include "math_data/rintf_intel_data.h"
TEST(MATH_TEST, rintf_intel) {
  DoMathDataTest<1>(g_rintf_intel_data, rintf);
}

#include "math_data/round_intel_data.h"
TEST(MATH_TEST, round_intel) {
  DoMathDataTest<1>(g_round_intel_data, round);
}

#include "math_data/roundf_intel_data.h"
TEST(MATH_TEST, roundf_intel) {
  DoMathDataTest<1>(g_roundf_intel_data, roundf);
}

#include "math_data/scalb_intel_data.h"
TEST(MATH_TEST, scalb_intel) {
  DoMathDataTest<1>(g_scalb_intel_data, scalb);
}

#include "math_data/scalbf_intel_data.h"
TEST(MATH_TEST, scalbf_intel) {
  DoMathDataTest<1>(g_scalbf_intel_data, scalbf);
}

#include "math_data/scalbn_intel_data.h"
TEST(MATH_TEST, scalbn_intel) {
  DoMathDataTest<1>(g_scalbn_intel_data, scalbn);
}

#include "math_data/scalbnf_intel_data.h"
TEST(MATH_TEST, scalbnf_intel) {
  DoMathDataTest<1>(g_scalbnf_intel_data, scalbnf);
}

#include "math_data/significand_intel_data.h"
TEST(MATH_TEST, significand_intel) {
  DoMathDataTest<1>(g_significand_intel_data, significand);
}

#include "math_data/significandf_intel_data.h"
TEST(MATH_TEST, significandf_intel) {
  DoMathDataTest<1>(g_significandf_intel_data, significandf);
}

#include "math_data/sin_intel_data.h"
TEST(MATH_TEST, sin_intel) {
  DoMathDataTest<1>(g_sin_intel_data, sin);
}

#include "math_data/sinf_intel_data.h"
TEST(MATH_TEST, sinf_intel) {
  DoMathDataTest<1>(g_sinf_intel_data, sinf);
}

#include "math_data/sinh_intel_data.h"
TEST(MATH_TEST, sinh_intel) {
  DoMathDataTest<2>(g_sinh_intel_data, sinh);
}

#include "math_data/sinhf_intel_data.h"
TEST(MATH_TEST, sinhf_intel) {
  DoMathDataTest<2>(g_sinhf_intel_data, sinhf);
}

#include "math_data/sincos_intel_data.h"
TEST(MATH_TEST, sincos_intel) {
  DoMathDataTest<1>(g_sincos_intel_data, sincos);
}

#include "math_data/sincosf_intel_data.h"
TEST(MATH_TEST, sincosf_intel) {
  DoMathDataTest<1>(g_sincosf_intel_data, sincosf);
}

#include "math_data/sqrt_intel_data.h"
TEST(MATH_TEST, sqrt_intel) {
  DoMathDataTest<1>(g_sqrt_intel_data, sqrt);
}

#include "math_data/sqrtf_intel_data.h"
TEST(MATH_TEST, sqrtf_intel) {
  DoMathDataTest<1>(g_sqrtf_intel_data, sqrtf);
}

#include "math_data/tan_intel_data.h"
TEST(MATH_TEST, tan_intel) {
  DoMathDataTest<1>(g_tan_intel_data, tan);
}

#include "math_data/tanf_intel_data.h"
TEST(MATH_TEST, tanf_intel) {
  DoMathDataTest<1>(g_tanf_intel_data, tanf);
}

#include "math_data/tanh_intel_data.h"
TEST(MATH_TEST, tanh_intel) {
  DoMathDataTest<2>(g_tanh_intel_data, tanh);
}

#include "math_data/tanhf_intel_data.h"
TEST(MATH_TEST, tanhf_intel) {
  DoMathDataTest<2>(g_tanhf_intel_data, tanhf);
}

#include "math_data/trunc_intel_data.h"
TEST(MATH_TEST, trunc_intel) {
  DoMathDataTest<1>(g_trunc_intel_data, trunc);
}

#include "math_data/truncf_intel_data.h"
TEST(MATH_TEST, truncf_intel) {
  DoMathDataTest<1>(g_truncf_intel_data, truncf);
}
