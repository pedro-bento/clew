// clew.h - v0.1 - Public Domain - Pedro Bento 2024
// 
// Portions of this file may be subject to the Apache License, Version 2.0, 
// when applicable to content created by The Khronos Group Inc.
//
// Single file openCL Extension Wrangler library.
//
// This file provides both the interface and the implementation.
// To instantiate the implementation,
//      #define CLEW_IMPLEMENTATION
// in *ONE* source file, before #including this file.

#ifndef CLEW_H
#define CLEW_H

// cl_version.h - Created by The Khronos Group Inc.
//
// This content has been modified by Pedro Bento 
// and the changes can be found at: https://github.com/pedro-bento/clew

/*******************************************************************************
 * Copyright (c) 2018-2020 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

/* Detect which version to target */
#if !defined(CL_TARGET_OPENCL_VERSION)
#pragma message("cl_version.h: CL_TARGET_OPENCL_VERSION is not defined. Defaulting to 300 (OpenCL 3.0)")
#define CL_TARGET_OPENCL_VERSION 300
#endif
#if CL_TARGET_OPENCL_VERSION != 100 && \
    CL_TARGET_OPENCL_VERSION != 110 && \
    CL_TARGET_OPENCL_VERSION != 120 && \
    CL_TARGET_OPENCL_VERSION != 200 && \
    CL_TARGET_OPENCL_VERSION != 210 && \
    CL_TARGET_OPENCL_VERSION != 220 && \
    CL_TARGET_OPENCL_VERSION != 300
#pragma message("cl_version: CL_TARGET_OPENCL_VERSION is not a valid value (100, 110, 120, 200, 210, 220, 300). Defaulting to 300 (OpenCL 3.0)")
#undef CL_TARGET_OPENCL_VERSION
#define CL_TARGET_OPENCL_VERSION 300
#endif


/* OpenCL Version */
#if CL_TARGET_OPENCL_VERSION >= 300 && !defined(CL_VERSION_3_0)
#define CL_VERSION_3_0  1
#endif
#if CL_TARGET_OPENCL_VERSION >= 220 && !defined(CL_VERSION_2_2)
#define CL_VERSION_2_2  1
#endif
#if CL_TARGET_OPENCL_VERSION >= 210 && !defined(CL_VERSION_2_1)
#define CL_VERSION_2_1  1
#endif
#if CL_TARGET_OPENCL_VERSION >= 200 && !defined(CL_VERSION_2_0)
#define CL_VERSION_2_0  1
#endif
#if CL_TARGET_OPENCL_VERSION >= 120 && !defined(CL_VERSION_1_2)
#define CL_VERSION_1_2  1
#endif
#if CL_TARGET_OPENCL_VERSION >= 110 && !defined(CL_VERSION_1_1)
#define CL_VERSION_1_1  1
#endif
#if CL_TARGET_OPENCL_VERSION >= 100 && !defined(CL_VERSION_1_0)
#define CL_VERSION_1_0  1
#endif

/* Allow deprecated APIs for older OpenCL versions. */
#if CL_TARGET_OPENCL_VERSION <= 220 && !defined(CL_USE_DEPRECATED_OPENCL_2_2_APIS)
#define CL_USE_DEPRECATED_OPENCL_2_2_APIS
#endif
#if CL_TARGET_OPENCL_VERSION <= 210 && !defined(CL_USE_DEPRECATED_OPENCL_2_1_APIS)
#define CL_USE_DEPRECATED_OPENCL_2_1_APIS
#endif
#if CL_TARGET_OPENCL_VERSION <= 200 && !defined(CL_USE_DEPRECATED_OPENCL_2_0_APIS)
#define CL_USE_DEPRECATED_OPENCL_2_0_APIS
#endif
#if CL_TARGET_OPENCL_VERSION <= 120 && !defined(CL_USE_DEPRECATED_OPENCL_1_2_APIS)
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#endif
#if CL_TARGET_OPENCL_VERSION <= 110 && !defined(CL_USE_DEPRECATED_OPENCL_1_1_APIS)
#define CL_USE_DEPRECATED_OPENCL_1_1_APIS
#endif
#if CL_TARGET_OPENCL_VERSION <= 100 && !defined(CL_USE_DEPRECATED_OPENCL_1_0_APIS)
#define CL_USE_DEPRECATED_OPENCL_1_0_APIS
#endif

// cl_platform.h - Created by The Khronos Group Inc.
//
// This content has been modified by Pedro Bento 
// and the changes can be found at: https://github.com/pedro-bento/clew

/*******************************************************************************
 * Copyright (c) 2008-2020 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
    #if !defined(CL_API_ENTRY)
        #define CL_API_ENTRY
    #endif
    #if !defined(CL_API_CALL)
        #define CL_API_CALL     __stdcall
    #endif
    #if !defined(CL_CALLBACK)
        #define CL_CALLBACK     __stdcall
    #endif
#else
    #if !defined(CL_API_ENTRY)
        #define CL_API_ENTRY
    #endif
    #if !defined(CL_API_CALL)
        #define CL_API_CALL
    #endif
    #if !defined(CL_CALLBACK)
        #define CL_CALLBACK
    #endif
#endif

/*
 * Deprecation flags refer to the last version of the header in which the
 * feature was not deprecated.
 *
 * E.g. VERSION_1_1_DEPRECATED means the feature is present in 1.1 without
 * deprecation but is deprecated in versions later than 1.1.
 */

#ifndef CL_API_SUFFIX_USER
#define CL_API_SUFFIX_USER
#endif

#ifndef CL_API_PREFIX_USER
#define CL_API_PREFIX_USER
#endif

#define CL_API_SUFFIX_COMMON CL_API_SUFFIX_USER
#define CL_API_PREFIX_COMMON CL_API_PREFIX_USER

#define CL_API_SUFFIX__VERSION_1_0 CL_API_SUFFIX_COMMON
#define CL_API_SUFFIX__VERSION_1_1 CL_API_SUFFIX_COMMON
#define CL_API_SUFFIX__VERSION_1_2 CL_API_SUFFIX_COMMON
#define CL_API_SUFFIX__VERSION_2_0 CL_API_SUFFIX_COMMON
#define CL_API_SUFFIX__VERSION_2_1 CL_API_SUFFIX_COMMON
#define CL_API_SUFFIX__VERSION_2_2 CL_API_SUFFIX_COMMON
#define CL_API_SUFFIX__VERSION_3_0 CL_API_SUFFIX_COMMON
#define CL_API_SUFFIX__EXPERIMENTAL CL_API_SUFFIX_COMMON


#ifdef __GNUC__
  #define CL_API_SUFFIX_DEPRECATED __attribute__((deprecated))
  #define CL_API_PREFIX_DEPRECATED
#elif defined(_WIN32)
  #define CL_API_SUFFIX_DEPRECATED
  #define CL_API_PREFIX_DEPRECATED __declspec(deprecated)
#else
  #define CL_API_SUFFIX_DEPRECATED
  #define CL_API_PREFIX_DEPRECATED
#endif

#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
    #define CL_API_SUFFIX__VERSION_1_0_DEPRECATED CL_API_SUFFIX_COMMON
    #define CL_API_PREFIX__VERSION_1_0_DEPRECATED CL_API_PREFIX_COMMON
#else
    #define CL_API_SUFFIX__VERSION_1_0_DEPRECATED CL_API_SUFFIX_COMMON CL_API_SUFFIX_DEPRECATED
    #define CL_API_PREFIX__VERSION_1_0_DEPRECATED CL_API_PREFIX_COMMON CL_API_PREFIX_DEPRECATED
#endif

#ifdef CL_USE_DEPRECATED_OPENCL_1_1_APIS
    #define CL_API_SUFFIX__VERSION_1_1_DEPRECATED CL_API_SUFFIX_COMMON
    #define CL_API_PREFIX__VERSION_1_1_DEPRECATED CL_API_PREFIX_COMMON
#else
    #define CL_API_SUFFIX__VERSION_1_1_DEPRECATED CL_API_SUFFIX_COMMON CL_API_SUFFIX_DEPRECATED
    #define CL_API_PREFIX__VERSION_1_1_DEPRECATED CL_API_PREFIX_COMMON CL_API_PREFIX_DEPRECATED
#endif

#ifdef CL_USE_DEPRECATED_OPENCL_1_2_APIS
    #define CL_API_SUFFIX__VERSION_1_2_DEPRECATED CL_API_SUFFIX_COMMON
    #define CL_API_PREFIX__VERSION_1_2_DEPRECATED CL_API_PREFIX_COMMON
#else
    #define CL_API_SUFFIX__VERSION_1_2_DEPRECATED CL_API_SUFFIX_COMMON CL_API_SUFFIX_DEPRECATED
    #define CL_API_PREFIX__VERSION_1_2_DEPRECATED CL_API_PREFIX_COMMON CL_API_PREFIX_DEPRECATED
 #endif

#ifdef CL_USE_DEPRECATED_OPENCL_2_0_APIS
    #define CL_API_SUFFIX__VERSION_2_0_DEPRECATED CL_API_SUFFIX_COMMON
    #define CL_API_PREFIX__VERSION_2_0_DEPRECATED CL_API_PREFIX_COMMON
#else
    #define CL_API_SUFFIX__VERSION_2_0_DEPRECATED CL_API_SUFFIX_COMMON CL_API_SUFFIX_DEPRECATED
    #define CL_API_PREFIX__VERSION_2_0_DEPRECATED CL_API_PREFIX_COMMON CL_API_PREFIX_DEPRECATED
#endif

#ifdef CL_USE_DEPRECATED_OPENCL_2_1_APIS
    #define CL_API_SUFFIX__VERSION_2_1_DEPRECATED CL_API_SUFFIX_COMMON
    #define CL_API_PREFIX__VERSION_2_1_DEPRECATED CL_API_PREFIX_COMMON
#else
    #define CL_API_SUFFIX__VERSION_2_1_DEPRECATED CL_API_SUFFIX_COMMON CL_API_SUFFIX_DEPRECATED
    #define CL_API_PREFIX__VERSION_2_1_DEPRECATED CL_API_PREFIX_COMMON CL_API_PREFIX_DEPRECATED
#endif

#ifdef CL_USE_DEPRECATED_OPENCL_2_2_APIS
    #define CL_API_SUFFIX__VERSION_2_2_DEPRECATED CL_API_SUFFIX_COMMON
    #define CL_API_PREFIX__VERSION_2_2_DEPRECATED CL_API_PREFIX_COMMON
#else
    #define CL_API_SUFFIX__VERSION_2_2_DEPRECATED CL_API_SUFFIX_COMMON CL_API_SUFFIX_DEPRECATED
    #define CL_API_PREFIX__VERSION_2_2_DEPRECATED CL_API_PREFIX_COMMON CL_API_PREFIX_DEPRECATED
#endif

#if (defined (_WIN32) && defined(_MSC_VER))

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wlanguage-extension-token"
#endif

/* intptr_t is used in cl.h and provided by stddef.h in Visual C++, but not in clang */
/* stdint.h was missing before Visual Studio 2010, include it for later versions and for clang */
#if defined(__clang__) || _MSC_VER >= 1600
    #include <stdint.h>
#endif

/* scalar types  */
typedef signed   __int8         cl_char;
typedef unsigned __int8         cl_uchar;
typedef signed   __int16        cl_short;
typedef unsigned __int16        cl_ushort;
typedef signed   __int32        cl_int;
typedef unsigned __int32        cl_uint;
typedef signed   __int64        cl_long;
typedef unsigned __int64        cl_ulong;

typedef unsigned __int16        cl_half;
typedef float                   cl_float;
typedef double                  cl_double;

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

/* Macro names and corresponding values defined by OpenCL */
#define CL_CHAR_BIT         8
#define CL_SCHAR_MAX        127
#define CL_SCHAR_MIN        (-127-1)
#define CL_CHAR_MAX         CL_SCHAR_MAX
#define CL_CHAR_MIN         CL_SCHAR_MIN
#define CL_UCHAR_MAX        255
#define CL_SHRT_MAX         32767
#define CL_SHRT_MIN         (-32767-1)
#define CL_USHRT_MAX        65535
#define CL_INT_MAX          2147483647
#define CL_INT_MIN          (-2147483647-1)
#define CL_UINT_MAX         0xffffffffU
#define CL_LONG_MAX         ((cl_long) 0x7FFFFFFFFFFFFFFFLL)
#define CL_LONG_MIN         ((cl_long) -0x7FFFFFFFFFFFFFFFLL - 1LL)
#define CL_ULONG_MAX        ((cl_ulong) 0xFFFFFFFFFFFFFFFFULL)

#define CL_FLT_DIG          6
#define CL_FLT_MANT_DIG     24
#define CL_FLT_MAX_10_EXP   +38
#define CL_FLT_MAX_EXP      +128
#define CL_FLT_MIN_10_EXP   -37
#define CL_FLT_MIN_EXP      -125
#define CL_FLT_RADIX        2
#define CL_FLT_MAX          340282346638528859811704183484516925440.0f
#define CL_FLT_MIN          1.175494350822287507969e-38f
#define CL_FLT_EPSILON      1.1920928955078125e-7f

#define CL_HALF_DIG          3
#define CL_HALF_MANT_DIG     11
#define CL_HALF_MAX_10_EXP   +4
#define CL_HALF_MAX_EXP      +16
#define CL_HALF_MIN_10_EXP   -4
#define CL_HALF_MIN_EXP      -13
#define CL_HALF_RADIX        2
#define CL_HALF_MAX          65504.0f
#define CL_HALF_MIN          6.103515625e-05f
#define CL_HALF_EPSILON      9.765625e-04f

#define CL_DBL_DIG          15
#define CL_DBL_MANT_DIG     53
#define CL_DBL_MAX_10_EXP   +308
#define CL_DBL_MAX_EXP      +1024
#define CL_DBL_MIN_10_EXP   -307
#define CL_DBL_MIN_EXP      -1021
#define CL_DBL_RADIX        2
#define CL_DBL_MAX          1.7976931348623158e+308
#define CL_DBL_MIN          2.225073858507201383090e-308
#define CL_DBL_EPSILON      2.220446049250313080847e-16

#define CL_M_E              2.7182818284590452354
#define CL_M_LOG2E          1.4426950408889634074
#define CL_M_LOG10E         0.43429448190325182765
#define CL_M_LN2            0.69314718055994530942
#define CL_M_LN10           2.30258509299404568402
#define CL_M_PI             3.14159265358979323846
#define CL_M_PI_2           1.57079632679489661923
#define CL_M_PI_4           0.78539816339744830962
#define CL_M_1_PI           0.31830988618379067154
#define CL_M_2_PI           0.63661977236758134308
#define CL_M_2_SQRTPI       1.12837916709551257390
#define CL_M_SQRT2          1.41421356237309504880
#define CL_M_SQRT1_2        0.70710678118654752440

#define CL_M_E_F            2.718281828f
#define CL_M_LOG2E_F        1.442695041f
#define CL_M_LOG10E_F       0.434294482f
#define CL_M_LN2_F          0.693147181f
#define CL_M_LN10_F         2.302585093f
#define CL_M_PI_F           3.141592654f
#define CL_M_PI_2_F         1.570796327f
#define CL_M_PI_4_F         0.785398163f
#define CL_M_1_PI_F         0.318309886f
#define CL_M_2_PI_F         0.636619772f
#define CL_M_2_SQRTPI_F     1.128379167f
#define CL_M_SQRT2_F        1.414213562f
#define CL_M_SQRT1_2_F      0.707106781f

#define CL_NAN              (CL_INFINITY - CL_INFINITY)
#define CL_HUGE_VALF        ((cl_float) 1e50)
#define CL_HUGE_VAL         ((cl_double) 1e500)
#define CL_MAXFLOAT         CL_FLT_MAX
#define CL_INFINITY         CL_HUGE_VALF

#else

#include <stdint.h>

/* scalar types  */
typedef int8_t          cl_char;
typedef uint8_t         cl_uchar;
typedef int16_t         cl_short;
typedef uint16_t        cl_ushort;
typedef int32_t         cl_int;
typedef uint32_t        cl_uint;
typedef int64_t         cl_long;
typedef uint64_t        cl_ulong;

typedef uint16_t        cl_half;
typedef float           cl_float;
typedef double          cl_double;

/* Macro names and corresponding values defined by OpenCL */
#define CL_CHAR_BIT         8
#define CL_SCHAR_MAX        127
#define CL_SCHAR_MIN        (-127-1)
#define CL_CHAR_MAX         CL_SCHAR_MAX
#define CL_CHAR_MIN         CL_SCHAR_MIN
#define CL_UCHAR_MAX        255
#define CL_SHRT_MAX         32767
#define CL_SHRT_MIN         (-32767-1)
#define CL_USHRT_MAX        65535
#define CL_INT_MAX          2147483647
#define CL_INT_MIN          (-2147483647-1)
#define CL_UINT_MAX         0xffffffffU
#define CL_LONG_MAX         ((cl_long) 0x7FFFFFFFFFFFFFFFLL)
#define CL_LONG_MIN         ((cl_long) -0x7FFFFFFFFFFFFFFFLL - 1LL)
#define CL_ULONG_MAX        ((cl_ulong) 0xFFFFFFFFFFFFFFFFULL)

#define CL_FLT_DIG          6
#define CL_FLT_MANT_DIG     24
#define CL_FLT_MAX_10_EXP   +38
#define CL_FLT_MAX_EXP      +128
#define CL_FLT_MIN_10_EXP   -37
#define CL_FLT_MIN_EXP      -125
#define CL_FLT_RADIX        2
#define CL_FLT_MAX          340282346638528859811704183484516925440.0f
#define CL_FLT_MIN          1.175494350822287507969e-38f
#define CL_FLT_EPSILON      1.1920928955078125e-7f

#define CL_HALF_DIG          3
#define CL_HALF_MANT_DIG     11
#define CL_HALF_MAX_10_EXP   +4
#define CL_HALF_MAX_EXP      +16
#define CL_HALF_MIN_10_EXP   -4
#define CL_HALF_MIN_EXP      -13
#define CL_HALF_RADIX        2
#define CL_HALF_MAX          65504.0f
#define CL_HALF_MIN          6.103515625e-05f
#define CL_HALF_EPSILON      9.765625e-04f

#define CL_DBL_DIG          15
#define CL_DBL_MANT_DIG     53
#define CL_DBL_MAX_10_EXP   +308
#define CL_DBL_MAX_EXP      +1024
#define CL_DBL_MIN_10_EXP   -307
#define CL_DBL_MIN_EXP      -1021
#define CL_DBL_RADIX        2
#define CL_DBL_MAX          179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
#define CL_DBL_MIN          2.225073858507201383090e-308
#define CL_DBL_EPSILON      2.220446049250313080847e-16

#define CL_M_E              2.7182818284590452354
#define CL_M_LOG2E          1.4426950408889634074
#define CL_M_LOG10E         0.43429448190325182765
#define CL_M_LN2            0.69314718055994530942
#define CL_M_LN10           2.30258509299404568402
#define CL_M_PI             3.14159265358979323846
#define CL_M_PI_2           1.57079632679489661923
#define CL_M_PI_4           0.78539816339744830962
#define CL_M_1_PI           0.31830988618379067154
#define CL_M_2_PI           0.63661977236758134308
#define CL_M_2_SQRTPI       1.12837916709551257390
#define CL_M_SQRT2          1.41421356237309504880
#define CL_M_SQRT1_2        0.70710678118654752440

#define CL_M_E_F            2.718281828f
#define CL_M_LOG2E_F        1.442695041f
#define CL_M_LOG10E_F       0.434294482f
#define CL_M_LN2_F          0.693147181f
#define CL_M_LN10_F         2.302585093f
#define CL_M_PI_F           3.141592654f
#define CL_M_PI_2_F         1.570796327f
#define CL_M_PI_4_F         0.785398163f
#define CL_M_1_PI_F         0.318309886f
#define CL_M_2_PI_F         0.636619772f
#define CL_M_2_SQRTPI_F     1.128379167f
#define CL_M_SQRT2_F        1.414213562f
#define CL_M_SQRT1_2_F      0.707106781f

#if defined( __GNUC__ )
   #define CL_HUGE_VALF     __builtin_huge_valf()
   #define CL_HUGE_VAL      __builtin_huge_val()
   #define CL_NAN           __builtin_nanf( "" )
#else
   #define CL_HUGE_VALF     ((cl_float) 1e50)
   #define CL_HUGE_VAL      ((cl_double) 1e500)
   float nanf( const char * );
   #define CL_NAN           nanf( "" )
#endif
#define CL_MAXFLOAT         CL_FLT_MAX
#define CL_INFINITY         CL_HUGE_VALF

#endif

#include <stddef.h>

/* Mirror types to GL types. Mirror types allow us to avoid deciding which 87s to load based on whether we are using GL or GLES here. */
typedef unsigned int cl_GLuint;
typedef int          cl_GLint;
typedef unsigned int cl_GLenum;

/*
 * Vector types
 *
 *  Note:   OpenCL requires that all types be naturally aligned.
 *          This means that vector types must be naturally aligned.
 *          For example, a vector of four floats must be aligned to
 *          a 16 byte boundary (calculated as 4 * the natural 4-byte
 *          alignment of the float).  The alignment qualifiers here
 *          will only function properly if your compiler supports them
 *          and if you don't actively work to defeat them.  For example,
 *          in order for a cl_float4 to be 16 byte aligned in a struct,
 *          the start of the struct must itself be 16-byte aligned.
 *
 *          Maintaining proper alignment is the user's responsibility.
 */

/* Define basic vector types */
#if defined( __VEC__ )
  #if !defined(__clang__)
     #include <altivec.h>   /* may be omitted depending on compiler. AltiVec spec provides no way to detect whether the header is required. */
  #endif
   typedef __vector unsigned char     __cl_uchar16;
   typedef __vector signed char       __cl_char16;
   typedef __vector unsigned short    __cl_ushort8;
   typedef __vector signed short      __cl_short8;
   typedef __vector unsigned int      __cl_uint4;
   typedef __vector signed int        __cl_int4;
   typedef __vector float             __cl_float4;
   #define  __CL_UCHAR16__  1
   #define  __CL_CHAR16__   1
   #define  __CL_USHORT8__  1
   #define  __CL_SHORT8__   1
   #define  __CL_UINT4__    1
   #define  __CL_INT4__     1
   #define  __CL_FLOAT4__   1
#endif

#if defined( __SSE__ )
    #if defined( __MINGW64__ )
        #include <intrin.h>
    #else
        #include <xmmintrin.h>
    #endif
    #if defined( __GNUC__ )
        typedef float __cl_float4   __attribute__((vector_size(16)));
    #else
        typedef __m128 __cl_float4;
    #endif
    #define __CL_FLOAT4__   1
#endif

#if defined( __SSE2__ )
    #if defined( __MINGW64__ )
        #include <intrin.h>
    #else
        #include <emmintrin.h>
    #endif
    #if defined( __GNUC__ )
        typedef cl_uchar    __cl_uchar16    __attribute__((vector_size(16)));
        typedef cl_char     __cl_char16     __attribute__((vector_size(16)));
        typedef cl_ushort   __cl_ushort8    __attribute__((vector_size(16)));
        typedef cl_short    __cl_short8     __attribute__((vector_size(16)));
        typedef cl_uint     __cl_uint4      __attribute__((vector_size(16)));
        typedef cl_int      __cl_int4       __attribute__((vector_size(16)));
        typedef cl_ulong    __cl_ulong2     __attribute__((vector_size(16)));
        typedef cl_long     __cl_long2      __attribute__((vector_size(16)));
        typedef cl_double   __cl_double2    __attribute__((vector_size(16)));
    #else
        typedef __m128i __cl_uchar16;
        typedef __m128i __cl_char16;
        typedef __m128i __cl_ushort8;
        typedef __m128i __cl_short8;
        typedef __m128i __cl_uint4;
        typedef __m128i __cl_int4;
        typedef __m128i __cl_ulong2;
        typedef __m128i __cl_long2;
        typedef __m128d __cl_double2;
    #endif
    #define __CL_UCHAR16__  1
    #define __CL_CHAR16__   1
    #define __CL_USHORT8__  1
    #define __CL_SHORT8__   1
    #define __CL_INT4__     1
    #define __CL_UINT4__    1
    #define __CL_ULONG2__   1
    #define __CL_LONG2__    1
    #define __CL_DOUBLE2__  1
#endif

#if defined( __MMX__ )
    #include <mmintrin.h>
    #if defined( __GNUC__ )
        typedef cl_uchar    __cl_uchar8     __attribute__((vector_size(8)));
        typedef cl_char     __cl_char8      __attribute__((vector_size(8)));
        typedef cl_ushort   __cl_ushort4    __attribute__((vector_size(8)));
        typedef cl_short    __cl_short4     __attribute__((vector_size(8)));
        typedef cl_uint     __cl_uint2      __attribute__((vector_size(8)));
        typedef cl_int      __cl_int2       __attribute__((vector_size(8)));
        typedef cl_ulong    __cl_ulong1     __attribute__((vector_size(8)));
        typedef cl_long     __cl_long1      __attribute__((vector_size(8)));
        typedef cl_float    __cl_float2     __attribute__((vector_size(8)));
    #else
        typedef __m64       __cl_uchar8;
        typedef __m64       __cl_char8;
        typedef __m64       __cl_ushort4;
        typedef __m64       __cl_short4;
        typedef __m64       __cl_uint2;
        typedef __m64       __cl_int2;
        typedef __m64       __cl_ulong1;
        typedef __m64       __cl_long1;
        typedef __m64       __cl_float2;
    #endif
    #define __CL_UCHAR8__   1
    #define __CL_CHAR8__    1
    #define __CL_USHORT4__  1
    #define __CL_SHORT4__   1
    #define __CL_INT2__     1
    #define __CL_UINT2__    1
    #define __CL_ULONG1__   1
    #define __CL_LONG1__    1
    #define __CL_FLOAT2__   1
#endif

#if defined( __AVX__ )
    #if defined( __MINGW64__ )
        #include <intrin.h>
    #else
        #include <immintrin.h>
    #endif
    #if defined( __GNUC__ )
        typedef cl_float    __cl_float8     __attribute__((vector_size(32)));
        typedef cl_double   __cl_double4    __attribute__((vector_size(32)));
    #else
        typedef __m256      __cl_float8;
        typedef __m256d     __cl_double4;
    #endif
    #define __CL_FLOAT8__   1
    #define __CL_DOUBLE4__  1
#endif

/* Define capabilities for anonymous struct members. */
#if !defined(__cplusplus) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#define  __CL_HAS_ANON_STRUCT__ 1
#define  __CL_ANON_STRUCT__
#elif defined(_WIN32) && defined(_MSC_VER) && !defined(__STDC__)
#define  __CL_HAS_ANON_STRUCT__ 1
#define  __CL_ANON_STRUCT__
#elif defined(__GNUC__) && ! defined(__STRICT_ANSI__)
#define  __CL_HAS_ANON_STRUCT__ 1
#define  __CL_ANON_STRUCT__ __extension__
#elif defined(__clang__)
#define  __CL_HAS_ANON_STRUCT__ 1
#define  __CL_ANON_STRUCT__ __extension__
#else
#define  __CL_HAS_ANON_STRUCT__ 0
#define  __CL_ANON_STRUCT__
#endif

#if defined(_WIN32) && defined(_MSC_VER) && __CL_HAS_ANON_STRUCT__
   /* Disable warning C4201: nonstandard extension used : nameless struct/union */
    #pragma warning( push )
    #pragma warning( disable : 4201 )
#endif

/* Define alignment keys */
#if defined( __GNUC__ ) || defined(__INTEGRITY)
    #define CL_ALIGNED(_x)          __attribute__ ((aligned(_x)))
#elif defined( _WIN32) && (_MSC_VER)
    /* Alignment keys neutered on windows because MSVC can't swallow function arguments with alignment requirements     */
    /* http://msdn.microsoft.com/en-us/library/373ak2y1%28VS.71%29.aspx                                                 */
    /* #include <crtdefs.h>                                                                                             */
    /* #define CL_ALIGNED(_x)          _CRT_ALIGN(_x)                                                                   */
    #define CL_ALIGNED(_x)
#else
   #warning  Need to implement some method to align data here
   #define  CL_ALIGNED(_x)
#endif

/* Indicate whether .xyzw, .s0123 and .hi.lo are supported */
#if __CL_HAS_ANON_STRUCT__
    /* .xyzw and .s0123...{f|F} are supported */
    #define CL_HAS_NAMED_VECTOR_FIELDS 1
    /* .hi and .lo are supported */
    #define CL_HAS_HI_LO_VECTOR_FIELDS 1
#endif

/* Define cl_vector types */

/* ---- cl_charn ---- */
typedef union
{
    cl_char  CL_ALIGNED(2) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_char  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_char  s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_char  lo, hi; };
#endif
#if defined( __CL_CHAR2__)
    __cl_char2     v2;
#endif
}cl_char2;

typedef union
{
    cl_char  CL_ALIGNED(4) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_char  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_char  s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_char2 lo, hi; };
#endif
#if defined( __CL_CHAR2__)
    __cl_char2     v2[2];
#endif
#if defined( __CL_CHAR4__)
    __cl_char4     v4;
#endif
}cl_char4;

/* cl_char3 is identical in size, alignment and behavior to cl_char4. See section 6.1.5. */
typedef  cl_char4  cl_char3;

typedef union
{
    cl_char   CL_ALIGNED(8) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_char  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_char  s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_char4 lo, hi; };
#endif
#if defined( __CL_CHAR2__)
    __cl_char2     v2[4];
#endif
#if defined( __CL_CHAR4__)
    __cl_char4     v4[2];
#endif
#if defined( __CL_CHAR8__ )
    __cl_char8     v8;
#endif
}cl_char8;

typedef union
{
    cl_char  CL_ALIGNED(16) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_char  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_char  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_char8 lo, hi; };
#endif
#if defined( __CL_CHAR2__)
    __cl_char2     v2[8];
#endif
#if defined( __CL_CHAR4__)
    __cl_char4     v4[4];
#endif
#if defined( __CL_CHAR8__ )
    __cl_char8     v8[2];
#endif
#if defined( __CL_CHAR16__ )
    __cl_char16    v16;
#endif
}cl_char16;


/* ---- cl_ucharn ---- */
typedef union
{
    cl_uchar  CL_ALIGNED(2) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_uchar  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_uchar  s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_uchar  lo, hi; };
#endif
#if defined( __cl_uchar2__)
    __cl_uchar2     v2;
#endif
}cl_uchar2;

typedef union
{
    cl_uchar  CL_ALIGNED(4) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_uchar  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_uchar  s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_uchar2 lo, hi; };
#endif
#if defined( __CL_UCHAR2__)
    __cl_uchar2     v2[2];
#endif
#if defined( __CL_UCHAR4__)
    __cl_uchar4     v4;
#endif
}cl_uchar4;

/* cl_uchar3 is identical in size, alignment and behavior to cl_uchar4. See section 6.1.5. */
typedef  cl_uchar4  cl_uchar3;

typedef union
{
    cl_uchar   CL_ALIGNED(8) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_uchar  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_uchar  s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_uchar4 lo, hi; };
#endif
#if defined( __CL_UCHAR2__)
    __cl_uchar2     v2[4];
#endif
#if defined( __CL_UCHAR4__)
    __cl_uchar4     v4[2];
#endif
#if defined( __CL_UCHAR8__ )
    __cl_uchar8     v8;
#endif
}cl_uchar8;

typedef union
{
    cl_uchar  CL_ALIGNED(16) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_uchar  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_uchar  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_uchar8 lo, hi; };
#endif
#if defined( __CL_UCHAR2__)
    __cl_uchar2     v2[8];
#endif
#if defined( __CL_UCHAR4__)
    __cl_uchar4     v4[4];
#endif
#if defined( __CL_UCHAR8__ )
    __cl_uchar8     v8[2];
#endif
#if defined( __CL_UCHAR16__ )
    __cl_uchar16    v16;
#endif
}cl_uchar16;


/* ---- cl_shortn ---- */
typedef union
{
    cl_short  CL_ALIGNED(4) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_short  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_short  s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_short  lo, hi; };
#endif
#if defined( __CL_SHORT2__)
    __cl_short2     v2;
#endif
}cl_short2;

typedef union
{
    cl_short  CL_ALIGNED(8) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_short  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_short  s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_short2 lo, hi; };
#endif
#if defined( __CL_SHORT2__)
    __cl_short2     v2[2];
#endif
#if defined( __CL_SHORT4__)
    __cl_short4     v4;
#endif
}cl_short4;

/* cl_short3 is identical in size, alignment and behavior to cl_short4. See section 6.1.5. */
typedef  cl_short4  cl_short3;

typedef union
{
    cl_short   CL_ALIGNED(16) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_short  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_short  s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_short4 lo, hi; };
#endif
#if defined( __CL_SHORT2__)
    __cl_short2     v2[4];
#endif
#if defined( __CL_SHORT4__)
    __cl_short4     v4[2];
#endif
#if defined( __CL_SHORT8__ )
    __cl_short8     v8;
#endif
}cl_short8;

typedef union
{
    cl_short  CL_ALIGNED(32) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_short  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_short  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_short8 lo, hi; };
#endif
#if defined( __CL_SHORT2__)
    __cl_short2     v2[8];
#endif
#if defined( __CL_SHORT4__)
    __cl_short4     v4[4];
#endif
#if defined( __CL_SHORT8__ )
    __cl_short8     v8[2];
#endif
#if defined( __CL_SHORT16__ )
    __cl_short16    v16;
#endif
}cl_short16;


/* ---- cl_ushortn ---- */
typedef union
{
    cl_ushort  CL_ALIGNED(4) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_ushort  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_ushort  s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_ushort  lo, hi; };
#endif
#if defined( __CL_USHORT2__)
    __cl_ushort2     v2;
#endif
}cl_ushort2;

typedef union
{
    cl_ushort  CL_ALIGNED(8) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_ushort  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_ushort  s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_ushort2 lo, hi; };
#endif
#if defined( __CL_USHORT2__)
    __cl_ushort2     v2[2];
#endif
#if defined( __CL_USHORT4__)
    __cl_ushort4     v4;
#endif
}cl_ushort4;

/* cl_ushort3 is identical in size, alignment and behavior to cl_ushort4. See section 6.1.5. */
typedef  cl_ushort4  cl_ushort3;

typedef union
{
    cl_ushort   CL_ALIGNED(16) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_ushort  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_ushort  s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_ushort4 lo, hi; };
#endif
#if defined( __CL_USHORT2__)
    __cl_ushort2     v2[4];
#endif
#if defined( __CL_USHORT4__)
    __cl_ushort4     v4[2];
#endif
#if defined( __CL_USHORT8__ )
    __cl_ushort8     v8;
#endif
}cl_ushort8;

typedef union
{
    cl_ushort  CL_ALIGNED(32) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_ushort  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_ushort  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_ushort8 lo, hi; };
#endif
#if defined( __CL_USHORT2__)
    __cl_ushort2     v2[8];
#endif
#if defined( __CL_USHORT4__)
    __cl_ushort4     v4[4];
#endif
#if defined( __CL_USHORT8__ )
    __cl_ushort8     v8[2];
#endif
#if defined( __CL_USHORT16__ )
    __cl_ushort16    v16;
#endif
}cl_ushort16;


/* ---- cl_halfn ---- */
typedef union
{
    cl_half  CL_ALIGNED(4) s[2];
#if __CL_HAS_ANON_STRUCT__
    __CL_ANON_STRUCT__ struct{ cl_half  x, y; };
    __CL_ANON_STRUCT__ struct{ cl_half  s0, s1; };
    __CL_ANON_STRUCT__ struct{ cl_half  lo, hi; };
#endif
#if defined( __CL_HALF2__)
    __cl_half2     v2;
#endif
}cl_half2;

typedef union
{
    cl_half  CL_ALIGNED(8) s[4];
#if __CL_HAS_ANON_STRUCT__
    __CL_ANON_STRUCT__ struct{ cl_half  x, y, z, w; };
    __CL_ANON_STRUCT__ struct{ cl_half  s0, s1, s2, s3; };
    __CL_ANON_STRUCT__ struct{ cl_half2 lo, hi; };
#endif
#if defined( __CL_HALF2__)
    __cl_half2     v2[2];
#endif
#if defined( __CL_HALF4__)
    __cl_half4     v4;
#endif
}cl_half4;

/* cl_half3 is identical in size, alignment and behavior to cl_half4. See section 6.1.5. */
typedef  cl_half4  cl_half3;

typedef union
{
    cl_half   CL_ALIGNED(16) s[8];
#if __CL_HAS_ANON_STRUCT__
    __CL_ANON_STRUCT__ struct{ cl_half  x, y, z, w; };
    __CL_ANON_STRUCT__ struct{ cl_half  s0, s1, s2, s3, s4, s5, s6, s7; };
    __CL_ANON_STRUCT__ struct{ cl_half4 lo, hi; };
#endif
#if defined( __CL_HALF2__)
    __cl_half2     v2[4];
#endif
#if defined( __CL_HALF4__)
    __cl_half4     v4[2];
#endif
#if defined( __CL_HALF8__ )
    __cl_half8     v8;
#endif
}cl_half8;

typedef union
{
    cl_half  CL_ALIGNED(32) s[16];
#if __CL_HAS_ANON_STRUCT__
    __CL_ANON_STRUCT__ struct{ cl_half  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
    __CL_ANON_STRUCT__ struct{ cl_half  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
    __CL_ANON_STRUCT__ struct{ cl_half8 lo, hi; };
#endif
#if defined( __CL_HALF2__)
    __cl_half2     v2[8];
#endif
#if defined( __CL_HALF4__)
    __cl_half4     v4[4];
#endif
#if defined( __CL_HALF8__ )
    __cl_half8     v8[2];
#endif
#if defined( __CL_HALF16__ )
    __cl_half16    v16;
#endif
}cl_half16;

/* ---- cl_intn ---- */
typedef union
{
    cl_int  CL_ALIGNED(8) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_int  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_int  s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_int  lo, hi; };
#endif
#if defined( __CL_INT2__)
    __cl_int2     v2;
#endif
}cl_int2;

typedef union
{
    cl_int  CL_ALIGNED(16) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_int  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_int  s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_int2 lo, hi; };
#endif
#if defined( __CL_INT2__)
    __cl_int2     v2[2];
#endif
#if defined( __CL_INT4__)
    __cl_int4     v4;
#endif
}cl_int4;

/* cl_int3 is identical in size, alignment and behavior to cl_int4. See section 6.1.5. */
typedef  cl_int4  cl_int3;

typedef union
{
    cl_int   CL_ALIGNED(32) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_int  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_int  s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_int4 lo, hi; };
#endif
#if defined( __CL_INT2__)
    __cl_int2     v2[4];
#endif
#if defined( __CL_INT4__)
    __cl_int4     v4[2];
#endif
#if defined( __CL_INT8__ )
    __cl_int8     v8;
#endif
}cl_int8;

typedef union
{
    cl_int  CL_ALIGNED(64) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_int  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_int  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_int8 lo, hi; };
#endif
#if defined( __CL_INT2__)
    __cl_int2     v2[8];
#endif
#if defined( __CL_INT4__)
    __cl_int4     v4[4];
#endif
#if defined( __CL_INT8__ )
    __cl_int8     v8[2];
#endif
#if defined( __CL_INT16__ )
    __cl_int16    v16;
#endif
}cl_int16;


/* ---- cl_uintn ---- */
typedef union
{
    cl_uint  CL_ALIGNED(8) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_uint  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_uint  s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_uint  lo, hi; };
#endif
#if defined( __CL_UINT2__)
    __cl_uint2     v2;
#endif
}cl_uint2;

typedef union
{
    cl_uint  CL_ALIGNED(16) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_uint  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_uint  s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_uint2 lo, hi; };
#endif
#if defined( __CL_UINT2__)
    __cl_uint2     v2[2];
#endif
#if defined( __CL_UINT4__)
    __cl_uint4     v4;
#endif
}cl_uint4;

/* cl_uint3 is identical in size, alignment and behavior to cl_uint4. See section 6.1.5. */
typedef  cl_uint4  cl_uint3;

typedef union
{
    cl_uint   CL_ALIGNED(32) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_uint  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_uint  s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_uint4 lo, hi; };
#endif
#if defined( __CL_UINT2__)
    __cl_uint2     v2[4];
#endif
#if defined( __CL_UINT4__)
    __cl_uint4     v4[2];
#endif
#if defined( __CL_UINT8__ )
    __cl_uint8     v8;
#endif
}cl_uint8;

typedef union
{
    cl_uint  CL_ALIGNED(64) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_uint  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_uint  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_uint8 lo, hi; };
#endif
#if defined( __CL_UINT2__)
    __cl_uint2     v2[8];
#endif
#if defined( __CL_UINT4__)
    __cl_uint4     v4[4];
#endif
#if defined( __CL_UINT8__ )
    __cl_uint8     v8[2];
#endif
#if defined( __CL_UINT16__ )
    __cl_uint16    v16;
#endif
}cl_uint16;

/* ---- cl_longn ---- */
typedef union
{
    cl_long  CL_ALIGNED(16) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_long  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_long  s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_long  lo, hi; };
#endif
#if defined( __CL_LONG2__)
    __cl_long2     v2;
#endif
}cl_long2;

typedef union
{
    cl_long  CL_ALIGNED(32) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_long  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_long  s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_long2 lo, hi; };
#endif
#if defined( __CL_LONG2__)
    __cl_long2     v2[2];
#endif
#if defined( __CL_LONG4__)
    __cl_long4     v4;
#endif
}cl_long4;

/* cl_long3 is identical in size, alignment and behavior to cl_long4. See section 6.1.5. */
typedef  cl_long4  cl_long3;

typedef union
{
    cl_long   CL_ALIGNED(64) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_long  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_long  s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_long4 lo, hi; };
#endif
#if defined( __CL_LONG2__)
    __cl_long2     v2[4];
#endif
#if defined( __CL_LONG4__)
    __cl_long4     v4[2];
#endif
#if defined( __CL_LONG8__ )
    __cl_long8     v8;
#endif
}cl_long8;

typedef union
{
    cl_long  CL_ALIGNED(128) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_long  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_long  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_long8 lo, hi; };
#endif
#if defined( __CL_LONG2__)
    __cl_long2     v2[8];
#endif
#if defined( __CL_LONG4__)
    __cl_long4     v4[4];
#endif
#if defined( __CL_LONG8__ )
    __cl_long8     v8[2];
#endif
#if defined( __CL_LONG16__ )
    __cl_long16    v16;
#endif
}cl_long16;


/* ---- cl_ulongn ---- */
typedef union
{
    cl_ulong  CL_ALIGNED(16) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_ulong  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_ulong  s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_ulong  lo, hi; };
#endif
#if defined( __CL_ULONG2__)
    __cl_ulong2     v2;
#endif
}cl_ulong2;

typedef union
{
    cl_ulong  CL_ALIGNED(32) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_ulong  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_ulong  s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_ulong2 lo, hi; };
#endif
#if defined( __CL_ULONG2__)
    __cl_ulong2     v2[2];
#endif
#if defined( __CL_ULONG4__)
    __cl_ulong4     v4;
#endif
}cl_ulong4;

/* cl_ulong3 is identical in size, alignment and behavior to cl_ulong4. See section 6.1.5. */
typedef  cl_ulong4  cl_ulong3;

typedef union
{
    cl_ulong   CL_ALIGNED(64) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_ulong  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_ulong  s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_ulong4 lo, hi; };
#endif
#if defined( __CL_ULONG2__)
    __cl_ulong2     v2[4];
#endif
#if defined( __CL_ULONG4__)
    __cl_ulong4     v4[2];
#endif
#if defined( __CL_ULONG8__ )
    __cl_ulong8     v8;
#endif
}cl_ulong8;

typedef union
{
    cl_ulong  CL_ALIGNED(128) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_ulong  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_ulong  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_ulong8 lo, hi; };
#endif
#if defined( __CL_ULONG2__)
    __cl_ulong2     v2[8];
#endif
#if defined( __CL_ULONG4__)
    __cl_ulong4     v4[4];
#endif
#if defined( __CL_ULONG8__ )
    __cl_ulong8     v8[2];
#endif
#if defined( __CL_ULONG16__ )
    __cl_ulong16    v16;
#endif
}cl_ulong16;


/* --- cl_floatn ---- */

typedef union
{
    cl_float  CL_ALIGNED(8) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_float  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_float  s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_float  lo, hi; };
#endif
#if defined( __CL_FLOAT2__)
    __cl_float2     v2;
#endif
}cl_float2;

typedef union
{
    cl_float  CL_ALIGNED(16) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_float   x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_float   s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_float2  lo, hi; };
#endif
#if defined( __CL_FLOAT2__)
    __cl_float2     v2[2];
#endif
#if defined( __CL_FLOAT4__)
    __cl_float4     v4;
#endif
}cl_float4;

/* cl_float3 is identical in size, alignment and behavior to cl_float4. See section 6.1.5. */
typedef  cl_float4  cl_float3;

typedef union
{
    cl_float   CL_ALIGNED(32) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_float   x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_float   s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_float4  lo, hi; };
#endif
#if defined( __CL_FLOAT2__)
    __cl_float2     v2[4];
#endif
#if defined( __CL_FLOAT4__)
    __cl_float4     v4[2];
#endif
#if defined( __CL_FLOAT8__ )
    __cl_float8     v8;
#endif
}cl_float8;

typedef union
{
    cl_float  CL_ALIGNED(64) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_float  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_float  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_float8 lo, hi; };
#endif
#if defined( __CL_FLOAT2__)
    __cl_float2     v2[8];
#endif
#if defined( __CL_FLOAT4__)
    __cl_float4     v4[4];
#endif
#if defined( __CL_FLOAT8__ )
    __cl_float8     v8[2];
#endif
#if defined( __CL_FLOAT16__ )
    __cl_float16    v16;
#endif
}cl_float16;

/* --- cl_doublen ---- */

typedef union
{
    cl_double  CL_ALIGNED(16) s[2];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_double  x, y; };
   __CL_ANON_STRUCT__ struct{ cl_double s0, s1; };
   __CL_ANON_STRUCT__ struct{ cl_double lo, hi; };
#endif
#if defined( __CL_DOUBLE2__)
    __cl_double2     v2;
#endif
}cl_double2;

typedef union
{
    cl_double  CL_ALIGNED(32) s[4];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_double  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_double  s0, s1, s2, s3; };
   __CL_ANON_STRUCT__ struct{ cl_double2 lo, hi; };
#endif
#if defined( __CL_DOUBLE2__)
    __cl_double2     v2[2];
#endif
#if defined( __CL_DOUBLE4__)
    __cl_double4     v4;
#endif
}cl_double4;

/* cl_double3 is identical in size, alignment and behavior to cl_double4. See section 6.1.5. */
typedef  cl_double4  cl_double3;

typedef union
{
    cl_double   CL_ALIGNED(64) s[8];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_double  x, y, z, w; };
   __CL_ANON_STRUCT__ struct{ cl_double  s0, s1, s2, s3, s4, s5, s6, s7; };
   __CL_ANON_STRUCT__ struct{ cl_double4 lo, hi; };
#endif
#if defined( __CL_DOUBLE2__)
    __cl_double2     v2[4];
#endif
#if defined( __CL_DOUBLE4__)
    __cl_double4     v4[2];
#endif
#if defined( __CL_DOUBLE8__ )
    __cl_double8     v8;
#endif
}cl_double8;

typedef union
{
    cl_double  CL_ALIGNED(128) s[16];
#if __CL_HAS_ANON_STRUCT__
   __CL_ANON_STRUCT__ struct{ cl_double  x, y, z, w, __spacer4, __spacer5, __spacer6, __spacer7, __spacer8, __spacer9, sa, sb, sc, sd, se, sf; };
   __CL_ANON_STRUCT__ struct{ cl_double  s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, sA, sB, sC, sD, sE, sF; };
   __CL_ANON_STRUCT__ struct{ cl_double8 lo, hi; };
#endif
#if defined( __CL_DOUBLE2__)
    __cl_double2     v2[8];
#endif
#if defined( __CL_DOUBLE4__)
    __cl_double4     v4[4];
#endif
#if defined( __CL_DOUBLE8__ )
    __cl_double8     v8[2];
#endif
#if defined( __CL_DOUBLE16__ )
    __cl_double16    v16;
#endif
}cl_double16;

/* Macro to facilitate debugging
 * Usage:
 *   Place CL_PROGRAM_STRING_DEBUG_INFO on the line before the first line of your source.
 *   The first line ends with:   CL_PROGRAM_STRING_DEBUG_INFO \"
 *   Each line thereafter of OpenCL C source must end with: \n\
 *   The last line ends in ";
 *
 *   Example:
 *
 *   const char *my_program = CL_PROGRAM_STRING_DEBUG_INFO "\
 *   kernel void foo( int a, float * b )             \n\
 *   {                                               \n\
 *      // my comment                                \n\
 *      *b[ get_global_id(0)] = a;                   \n\
 *   }                                               \n\
 *   ";
 *
 * This should correctly set up the line, (column) and file information for your source
 * string so you can do source level debugging.
 */
#define  __CL_STRINGIFY( _x )               # _x
#define  _CL_STRINGIFY( _x )                __CL_STRINGIFY( _x )
#define  CL_PROGRAM_STRING_DEBUG_INFO       "#line "  _CL_STRINGIFY(__LINE__) " \"" __FILE__ "\" \n\n"

#ifdef __cplusplus
}
#endif

#if defined(_WIN32) && defined(_MSC_VER) && __CL_HAS_ANON_STRUCT__
    #pragma warning( pop )
#endif

// cl.h - Created by The Khronos Group Inc.
//
// This content has been modified by Pedro Bento 
// and the changes can be found at: https://github.com/pedro-bento/clew

/*******************************************************************************
 * Copyright (c) 2008-2020 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _cl_platform_id *    cl_platform_id;
typedef struct _cl_device_id *      cl_device_id;
typedef struct _cl_context *        cl_context;
typedef struct _cl_command_queue *  cl_command_queue;
typedef struct _cl_mem *            cl_mem;
typedef struct _cl_program *        cl_program;
typedef struct _cl_kernel *         cl_kernel;
typedef struct _cl_event *          cl_event;
typedef struct _cl_sampler *        cl_sampler;

typedef cl_uint             cl_bool;                     /* WARNING!  Unlike cl_ types in cl_platform.h, cl_bool is not guaranteed to be the same size as the bool in kernels. */
typedef cl_ulong            cl_bitfield;
typedef cl_ulong            cl_properties;
typedef cl_bitfield         cl_device_type;
typedef cl_uint             cl_platform_info;
typedef cl_uint             cl_device_info;
typedef cl_bitfield         cl_device_fp_config;
typedef cl_uint             cl_device_mem_cache_type;
typedef cl_uint             cl_device_local_mem_type;
typedef cl_bitfield         cl_device_exec_capabilities;
#ifdef CL_VERSION_2_0
typedef cl_bitfield         cl_device_svm_capabilities;
#endif
typedef cl_bitfield         cl_command_queue_properties;
#ifdef CL_VERSION_1_2
typedef intptr_t            cl_device_partition_property;
typedef cl_bitfield         cl_device_affinity_domain;
#endif

typedef intptr_t            cl_context_properties;
typedef cl_uint             cl_context_info;
#ifdef CL_VERSION_2_0
typedef cl_properties       cl_queue_properties;
#endif
typedef cl_uint             cl_command_queue_info;
typedef cl_uint             cl_channel_order;
typedef cl_uint             cl_channel_type;
typedef cl_bitfield         cl_mem_flags;
#ifdef CL_VERSION_2_0
typedef cl_bitfield         cl_svm_mem_flags;
#endif
typedef cl_uint             cl_mem_object_type;
typedef cl_uint             cl_mem_info;
#ifdef CL_VERSION_1_2
typedef cl_bitfield         cl_mem_migration_flags;
#endif
typedef cl_uint             cl_image_info;
#ifdef CL_VERSION_1_1
typedef cl_uint             cl_buffer_create_type;
#endif
typedef cl_uint             cl_addressing_mode;
typedef cl_uint             cl_filter_mode;
typedef cl_uint             cl_sampler_info;
typedef cl_bitfield         cl_map_flags;
#ifdef CL_VERSION_2_0
typedef intptr_t            cl_pipe_properties;
typedef cl_uint             cl_pipe_info;
#endif
typedef cl_uint             cl_program_info;
typedef cl_uint             cl_program_build_info;
#ifdef CL_VERSION_1_2
typedef cl_uint             cl_program_binary_type;
#endif
typedef cl_int              cl_build_status;
typedef cl_uint             cl_kernel_info;
#ifdef CL_VERSION_1_2
typedef cl_uint             cl_kernel_arg_info;
typedef cl_uint             cl_kernel_arg_address_qualifier;
typedef cl_uint             cl_kernel_arg_access_qualifier;
typedef cl_bitfield         cl_kernel_arg_type_qualifier;
#endif
typedef cl_uint             cl_kernel_work_group_info;
#ifdef CL_VERSION_2_1
typedef cl_uint             cl_kernel_sub_group_info;
#endif
typedef cl_uint             cl_event_info;
typedef cl_uint             cl_command_type;
typedef cl_uint             cl_profiling_info;
#ifdef CL_VERSION_2_0
typedef cl_properties       cl_sampler_properties;
typedef cl_uint             cl_kernel_exec_info;
#endif
#ifdef CL_VERSION_3_0
typedef cl_bitfield         cl_device_atomic_capabilities;
typedef cl_bitfield         cl_device_device_enqueue_capabilities;
typedef cl_uint             cl_khronos_vendor_id;
typedef cl_properties       cl_mem_properties;
typedef cl_uint             cl_version;
#endif

typedef struct _cl_image_format {
    cl_channel_order        image_channel_order;
    cl_channel_type         image_channel_data_type;
} cl_image_format;

#ifdef CL_VERSION_1_2

typedef struct _cl_image_desc {
    cl_mem_object_type      image_type;
    size_t                  image_width;
    size_t                  image_height;
    size_t                  image_depth;
    size_t                  image_array_size;
    size_t                  image_row_pitch;
    size_t                  image_slice_pitch;
    cl_uint                 num_mip_levels;
    cl_uint                 num_samples;
#ifdef CL_VERSION_2_0
#if defined(__GNUC__)
    __extension__                   /* Prevents warnings about anonymous union in -pedantic builds */
#endif
#if defined(_MSC_VER) && !defined(__STDC__)
#pragma warning( push )
#pragma warning( disable : 4201 )   /* Prevents warning about nameless struct/union in /W4 builds */
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc11-extensions" /* Prevents warning about nameless union being C11 extension*/
#endif
#if defined(_MSC_VER) && defined(__STDC__)
    /* Anonymous unions are not supported in /Za builds */
#else
    union {
#endif
#endif
      cl_mem                  buffer;
#ifdef CL_VERSION_2_0
#if defined(_MSC_VER) && defined(__STDC__)
    /* Anonymous unions are not supported in /Za builds */
#else
      cl_mem                  mem_object;
    };
#endif
#if defined(_MSC_VER) && !defined(__STDC__)
#pragma warning( pop )
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif
} cl_image_desc;

#endif

#ifdef CL_VERSION_1_1

typedef struct _cl_buffer_region {
    size_t                  origin;
    size_t                  size;
} cl_buffer_region;

#endif

#ifdef CL_VERSION_3_0

#define CL_NAME_VERSION_MAX_NAME_SIZE 64

typedef struct _cl_name_version {
    cl_version              version;
    char                    name[CL_NAME_VERSION_MAX_NAME_SIZE];
} cl_name_version;

#endif

/******************************************************************************/

/* Error Codes */
#define CL_SUCCESS                                  0
#define CL_DEVICE_NOT_FOUND                         -1
#define CL_DEVICE_NOT_AVAILABLE                     -2
#define CL_COMPILER_NOT_AVAILABLE                   -3
#define CL_MEM_OBJECT_ALLOCATION_FAILURE            -4
#define CL_OUT_OF_RESOURCES                         -5
#define CL_OUT_OF_HOST_MEMORY                       -6
#define CL_PROFILING_INFO_NOT_AVAILABLE             -7
#define CL_MEM_COPY_OVERLAP                         -8
#define CL_IMAGE_FORMAT_MISMATCH                    -9
#define CL_IMAGE_FORMAT_NOT_SUPPORTED               -10
#define CL_BUILD_PROGRAM_FAILURE                    -11
#define CL_MAP_FAILURE                              -12
#ifdef CL_VERSION_1_1
#define CL_MISALIGNED_SUB_BUFFER_OFFSET             -13
#define CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST -14
#endif
#ifdef CL_VERSION_1_2
#define CL_COMPILE_PROGRAM_FAILURE                  -15
#define CL_LINKER_NOT_AVAILABLE                     -16
#define CL_LINK_PROGRAM_FAILURE                     -17
#define CL_DEVICE_PARTITION_FAILED                  -18
#define CL_KERNEL_ARG_INFO_NOT_AVAILABLE            -19
#endif

#define CL_INVALID_VALUE                            -30
#define CL_INVALID_DEVICE_TYPE                      -31
#define CL_INVALID_PLATFORM                         -32
#define CL_INVALID_DEVICE                           -33
#define CL_INVALID_CONTEXT                          -34
#define CL_INVALID_QUEUE_PROPERTIES                 -35
#define CL_INVALID_COMMAND_QUEUE                    -36
#define CL_INVALID_HOST_PTR                         -37
#define CL_INVALID_MEM_OBJECT                       -38
#define CL_INVALID_IMAGE_FORMAT_DESCRIPTOR          -39
#define CL_INVALID_IMAGE_SIZE                       -40
#define CL_INVALID_SAMPLER                          -41
#define CL_INVALID_BINARY                           -42
#define CL_INVALID_BUILD_OPTIONS                    -43
#define CL_INVALID_PROGRAM                          -44
#define CL_INVALID_PROGRAM_EXECUTABLE               -45
#define CL_INVALID_KERNEL_NAME                      -46
#define CL_INVALID_KERNEL_DEFINITION                -47
#define CL_INVALID_KERNEL                           -48
#define CL_INVALID_ARG_INDEX                        -49
#define CL_INVALID_ARG_VALUE                        -50
#define CL_INVALID_ARG_SIZE                         -51
#define CL_INVALID_KERNEL_ARGS                      -52
#define CL_INVALID_WORK_DIMENSION                   -53
#define CL_INVALID_WORK_GROUP_SIZE                  -54
#define CL_INVALID_WORK_ITEM_SIZE                   -55
#define CL_INVALID_GLOBAL_OFFSET                    -56
#define CL_INVALID_EVENT_WAIT_LIST                  -57
#define CL_INVALID_EVENT                            -58
#define CL_INVALID_OPERATION                        -59
#define CL_INVALID_GL_OBJECT                        -60
#define CL_INVALID_BUFFER_SIZE                      -61
#define CL_INVALID_MIP_LEVEL                        -62
#define CL_INVALID_GLOBAL_WORK_SIZE                 -63
#ifdef CL_VERSION_1_1
#define CL_INVALID_PROPERTY                         -64
#endif
#ifdef CL_VERSION_1_2
#define CL_INVALID_IMAGE_DESCRIPTOR                 -65
#define CL_INVALID_COMPILER_OPTIONS                 -66
#define CL_INVALID_LINKER_OPTIONS                   -67
#define CL_INVALID_DEVICE_PARTITION_COUNT           -68
#endif
#ifdef CL_VERSION_2_0
#define CL_INVALID_PIPE_SIZE                        -69
#define CL_INVALID_DEVICE_QUEUE                     -70
#endif
#ifdef CL_VERSION_2_2
#define CL_INVALID_SPEC_ID                          -71
#define CL_MAX_SIZE_RESTRICTION_EXCEEDED            -72
#endif


/* cl_bool */
#define CL_FALSE                                    0
#define CL_TRUE                                     1
#ifdef CL_VERSION_1_2
#define CL_BLOCKING                                 CL_TRUE
#define CL_NON_BLOCKING                             CL_FALSE
#endif

/* cl_platform_info */
#define CL_PLATFORM_PROFILE                         0x0900
#define CL_PLATFORM_VERSION                         0x0901
#define CL_PLATFORM_NAME                            0x0902
#define CL_PLATFORM_VENDOR                          0x0903
#define CL_PLATFORM_EXTENSIONS                      0x0904
#ifdef CL_VERSION_2_1
#define CL_PLATFORM_HOST_TIMER_RESOLUTION           0x0905
#endif
#ifdef CL_VERSION_3_0
#define CL_PLATFORM_NUMERIC_VERSION                 0x0906
#define CL_PLATFORM_EXTENSIONS_WITH_VERSION         0x0907
#endif

/* cl_device_type - bitfield */
#define CL_DEVICE_TYPE_DEFAULT                      (1 << 0)
#define CL_DEVICE_TYPE_CPU                          (1 << 1)
#define CL_DEVICE_TYPE_GPU                          (1 << 2)
#define CL_DEVICE_TYPE_ACCELERATOR                  (1 << 3)
#ifdef CL_VERSION_1_2
#define CL_DEVICE_TYPE_CUSTOM                       (1 << 4)
#endif
#define CL_DEVICE_TYPE_ALL                          0xFFFFFFFF

/* cl_device_info */
#define CL_DEVICE_TYPE                                   0x1000
#define CL_DEVICE_VENDOR_ID                              0x1001
#define CL_DEVICE_MAX_COMPUTE_UNITS                      0x1002
#define CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS               0x1003
#define CL_DEVICE_MAX_WORK_GROUP_SIZE                    0x1004
#define CL_DEVICE_MAX_WORK_ITEM_SIZES                    0x1005
#define CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR            0x1006
#define CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT           0x1007
#define CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT             0x1008
#define CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG            0x1009
#define CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT           0x100A
#define CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE          0x100B
#define CL_DEVICE_MAX_CLOCK_FREQUENCY                    0x100C
#define CL_DEVICE_ADDRESS_BITS                           0x100D
#define CL_DEVICE_MAX_READ_IMAGE_ARGS                    0x100E
#define CL_DEVICE_MAX_WRITE_IMAGE_ARGS                   0x100F
#define CL_DEVICE_MAX_MEM_ALLOC_SIZE                     0x1010
#define CL_DEVICE_IMAGE2D_MAX_WIDTH                      0x1011
#define CL_DEVICE_IMAGE2D_MAX_HEIGHT                     0x1012
#define CL_DEVICE_IMAGE3D_MAX_WIDTH                      0x1013
#define CL_DEVICE_IMAGE3D_MAX_HEIGHT                     0x1014
#define CL_DEVICE_IMAGE3D_MAX_DEPTH                      0x1015
#define CL_DEVICE_IMAGE_SUPPORT                          0x1016
#define CL_DEVICE_MAX_PARAMETER_SIZE                     0x1017
#define CL_DEVICE_MAX_SAMPLERS                           0x1018
#define CL_DEVICE_MEM_BASE_ADDR_ALIGN                    0x1019
#define CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE               0x101A
#define CL_DEVICE_SINGLE_FP_CONFIG                       0x101B
#define CL_DEVICE_GLOBAL_MEM_CACHE_TYPE                  0x101C
#define CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE              0x101D
#define CL_DEVICE_GLOBAL_MEM_CACHE_SIZE                  0x101E
#define CL_DEVICE_GLOBAL_MEM_SIZE                        0x101F
#define CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE               0x1020
#define CL_DEVICE_MAX_CONSTANT_ARGS                      0x1021
#define CL_DEVICE_LOCAL_MEM_TYPE                         0x1022
#define CL_DEVICE_LOCAL_MEM_SIZE                         0x1023
#define CL_DEVICE_ERROR_CORRECTION_SUPPORT               0x1024
#define CL_DEVICE_PROFILING_TIMER_RESOLUTION             0x1025
#define CL_DEVICE_ENDIAN_LITTLE                          0x1026
#define CL_DEVICE_AVAILABLE                              0x1027
#define CL_DEVICE_COMPILER_AVAILABLE                     0x1028
#define CL_DEVICE_EXECUTION_CAPABILITIES                 0x1029
#define CL_DEVICE_QUEUE_PROPERTIES                       0x102A    /* deprecated */
#ifdef CL_VERSION_2_0
#define CL_DEVICE_QUEUE_ON_HOST_PROPERTIES               0x102A
#endif
#define CL_DEVICE_NAME                                   0x102B
#define CL_DEVICE_VENDOR                                 0x102C
#define CL_DRIVER_VERSION                                0x102D
#define CL_DEVICE_PROFILE                                0x102E
#define CL_DEVICE_VERSION                                0x102F
#define CL_DEVICE_EXTENSIONS                             0x1030
#define CL_DEVICE_PLATFORM                               0x1031
#ifdef CL_VERSION_1_2
#define CL_DEVICE_DOUBLE_FP_CONFIG                       0x1032
#endif
/* 0x1033 reserved for CL_DEVICE_HALF_FP_CONFIG which is already defined in "cl_ext.h" */
#ifdef CL_VERSION_1_1
#define CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF            0x1034
#define CL_DEVICE_HOST_UNIFIED_MEMORY                    0x1035   /* deprecated */
#define CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR               0x1036
#define CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT              0x1037
#define CL_DEVICE_NATIVE_VECTOR_WIDTH_INT                0x1038
#define CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG               0x1039
#define CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT              0x103A
#define CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE             0x103B
#define CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF               0x103C
#define CL_DEVICE_OPENCL_C_VERSION                       0x103D
#endif
#ifdef CL_VERSION_1_2
#define CL_DEVICE_LINKER_AVAILABLE                       0x103E
#define CL_DEVICE_BUILT_IN_KERNELS                       0x103F
#define CL_DEVICE_IMAGE_MAX_BUFFER_SIZE                  0x1040
#define CL_DEVICE_IMAGE_MAX_ARRAY_SIZE                   0x1041
#define CL_DEVICE_PARENT_DEVICE                          0x1042
#define CL_DEVICE_PARTITION_MAX_SUB_DEVICES              0x1043
#define CL_DEVICE_PARTITION_PROPERTIES                   0x1044
#define CL_DEVICE_PARTITION_AFFINITY_DOMAIN              0x1045
#define CL_DEVICE_PARTITION_TYPE                         0x1046
#define CL_DEVICE_REFERENCE_COUNT                        0x1047
#define CL_DEVICE_PREFERRED_INTEROP_USER_SYNC            0x1048
#define CL_DEVICE_PRINTF_BUFFER_SIZE                     0x1049
#endif
#ifdef CL_VERSION_2_0
#define CL_DEVICE_IMAGE_PITCH_ALIGNMENT                  0x104A
#define CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT           0x104B
#define CL_DEVICE_MAX_READ_WRITE_IMAGE_ARGS              0x104C
#define CL_DEVICE_MAX_GLOBAL_VARIABLE_SIZE               0x104D
#define CL_DEVICE_QUEUE_ON_DEVICE_PROPERTIES             0x104E
#define CL_DEVICE_QUEUE_ON_DEVICE_PREFERRED_SIZE         0x104F
#define CL_DEVICE_QUEUE_ON_DEVICE_MAX_SIZE               0x1050
#define CL_DEVICE_MAX_ON_DEVICE_QUEUES                   0x1051
#define CL_DEVICE_MAX_ON_DEVICE_EVENTS                   0x1052
#define CL_DEVICE_SVM_CAPABILITIES                       0x1053
#define CL_DEVICE_GLOBAL_VARIABLE_PREFERRED_TOTAL_SIZE   0x1054
#define CL_DEVICE_MAX_PIPE_ARGS                          0x1055
#define CL_DEVICE_PIPE_MAX_ACTIVE_RESERVATIONS           0x1056
#define CL_DEVICE_PIPE_MAX_PACKET_SIZE                   0x1057
#define CL_DEVICE_PREFERRED_PLATFORM_ATOMIC_ALIGNMENT    0x1058
#define CL_DEVICE_PREFERRED_GLOBAL_ATOMIC_ALIGNMENT      0x1059
#define CL_DEVICE_PREFERRED_LOCAL_ATOMIC_ALIGNMENT       0x105A
#endif
#ifdef CL_VERSION_2_1
#define CL_DEVICE_IL_VERSION                             0x105B
#define CL_DEVICE_MAX_NUM_SUB_GROUPS                     0x105C
#define CL_DEVICE_SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS 0x105D
#endif
#ifdef CL_VERSION_3_0
#define CL_DEVICE_NUMERIC_VERSION                        0x105E
#define CL_DEVICE_EXTENSIONS_WITH_VERSION                0x1060
#define CL_DEVICE_ILS_WITH_VERSION                       0x1061
#define CL_DEVICE_BUILT_IN_KERNELS_WITH_VERSION          0x1062
#define CL_DEVICE_ATOMIC_MEMORY_CAPABILITIES             0x1063
#define CL_DEVICE_ATOMIC_FENCE_CAPABILITIES              0x1064
#define CL_DEVICE_NON_UNIFORM_WORK_GROUP_SUPPORT         0x1065
#define CL_DEVICE_OPENCL_C_ALL_VERSIONS                  0x1066
#define CL_DEVICE_PREFERRED_WORK_GROUP_SIZE_MULTIPLE     0x1067
#define CL_DEVICE_WORK_GROUP_COLLECTIVE_FUNCTIONS_SUPPORT 0x1068
#define CL_DEVICE_GENERIC_ADDRESS_SPACE_SUPPORT          0x1069
/* 0x106A to 0x106E - Reserved for upcoming KHR extension */
#define CL_DEVICE_OPENCL_C_FEATURES                      0x106F
#define CL_DEVICE_DEVICE_ENQUEUE_CAPABILITIES            0x1070
#define CL_DEVICE_PIPE_SUPPORT                           0x1071
#define CL_DEVICE_LATEST_CONFORMANCE_VERSION_PASSED      0x1072
#endif

/* cl_device_fp_config - bitfield */
#define CL_FP_DENORM                                (1 << 0)
#define CL_FP_INF_NAN                               (1 << 1)
#define CL_FP_ROUND_TO_NEAREST                      (1 << 2)
#define CL_FP_ROUND_TO_ZERO                         (1 << 3)
#define CL_FP_ROUND_TO_INF                          (1 << 4)
#define CL_FP_FMA                                   (1 << 5)
#ifdef CL_VERSION_1_1
#define CL_FP_SOFT_FLOAT                            (1 << 6)
#endif
#ifdef CL_VERSION_1_2
#define CL_FP_CORRECTLY_ROUNDED_DIVIDE_SQRT         (1 << 7)
#endif

/* cl_device_mem_cache_type */
#define CL_NONE                                     0x0
#define CL_READ_ONLY_CACHE                          0x1
#define CL_READ_WRITE_CACHE                         0x2

/* cl_device_local_mem_type */
#define CL_LOCAL                                    0x1
#define CL_GLOBAL                                   0x2

/* cl_device_exec_capabilities - bitfield */
#define CL_EXEC_KERNEL                              (1 << 0)
#define CL_EXEC_NATIVE_KERNEL                       (1 << 1)

/* cl_command_queue_properties - bitfield */
#define CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE      (1 << 0)
#define CL_QUEUE_PROFILING_ENABLE                   (1 << 1)
#ifdef CL_VERSION_2_0
#define CL_QUEUE_ON_DEVICE                          (1 << 2)
#define CL_QUEUE_ON_DEVICE_DEFAULT                  (1 << 3)
#endif

/* cl_context_info */
#define CL_CONTEXT_REFERENCE_COUNT                  0x1080
#define CL_CONTEXT_DEVICES                          0x1081
#define CL_CONTEXT_PROPERTIES                       0x1082
#ifdef CL_VERSION_1_1
#define CL_CONTEXT_NUM_DEVICES                      0x1083
#endif

/* cl_context_properties */
#define CL_CONTEXT_PLATFORM                         0x1084
#ifdef CL_VERSION_1_2
#define CL_CONTEXT_INTEROP_USER_SYNC                0x1085
#endif

#ifdef CL_VERSION_1_2

/* cl_device_partition_property */
#define CL_DEVICE_PARTITION_EQUALLY                 0x1086
#define CL_DEVICE_PARTITION_BY_COUNTS               0x1087
#define CL_DEVICE_PARTITION_BY_COUNTS_LIST_END      0x0
#define CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN      0x1088

#endif

#ifdef CL_VERSION_1_2

/* cl_device_affinity_domain */
#define CL_DEVICE_AFFINITY_DOMAIN_NUMA               (1 << 0)
#define CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE           (1 << 1)
#define CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE           (1 << 2)
#define CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE           (1 << 3)
#define CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE           (1 << 4)
#define CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE (1 << 5)

#endif

#ifdef CL_VERSION_2_0

/* cl_device_svm_capabilities */
#define CL_DEVICE_SVM_COARSE_GRAIN_BUFFER           (1 << 0)
#define CL_DEVICE_SVM_FINE_GRAIN_BUFFER             (1 << 1)
#define CL_DEVICE_SVM_FINE_GRAIN_SYSTEM             (1 << 2)
#define CL_DEVICE_SVM_ATOMICS                       (1 << 3)

#endif

/* cl_command_queue_info */
#define CL_QUEUE_CONTEXT                            0x1090
#define CL_QUEUE_DEVICE                             0x1091
#define CL_QUEUE_REFERENCE_COUNT                    0x1092
#define CL_QUEUE_PROPERTIES                         0x1093
#ifdef CL_VERSION_2_0
#define CL_QUEUE_SIZE                               0x1094
#endif
#ifdef CL_VERSION_2_1
#define CL_QUEUE_DEVICE_DEFAULT                     0x1095
#endif
#ifdef CL_VERSION_3_0
#define CL_QUEUE_PROPERTIES_ARRAY                   0x1098
#endif

/* cl_mem_flags and cl_svm_mem_flags - bitfield */
#define CL_MEM_READ_WRITE                           (1 << 0)
#define CL_MEM_WRITE_ONLY                           (1 << 1)
#define CL_MEM_READ_ONLY                            (1 << 2)
#define CL_MEM_USE_HOST_PTR                         (1 << 3)
#define CL_MEM_ALLOC_HOST_PTR                       (1 << 4)
#define CL_MEM_COPY_HOST_PTR                        (1 << 5)
/* reserved                                         (1 << 6)    */
#ifdef CL_VERSION_1_2
#define CL_MEM_HOST_WRITE_ONLY                      (1 << 7)
#define CL_MEM_HOST_READ_ONLY                       (1 << 8)
#define CL_MEM_HOST_NO_ACCESS                       (1 << 9)
#endif
#ifdef CL_VERSION_2_0
#define CL_MEM_SVM_FINE_GRAIN_BUFFER                (1 << 10)   /* used by cl_svm_mem_flags only */
#define CL_MEM_SVM_ATOMICS                          (1 << 11)   /* used by cl_svm_mem_flags only */
#define CL_MEM_KERNEL_READ_AND_WRITE                (1 << 12)
#endif

#ifdef CL_VERSION_1_2

/* cl_mem_migration_flags - bitfield */
#define CL_MIGRATE_MEM_OBJECT_HOST                  (1 << 0)
#define CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED     (1 << 1)

#endif

/* cl_channel_order */
#define CL_R                                        0x10B0
#define CL_A                                        0x10B1
#define CL_RG                                       0x10B2
#define CL_RA                                       0x10B3
#define CL_RGB                                      0x10B4
#define CL_RGBA                                     0x10B5
#define CL_BGRA                                     0x10B6
#define CL_ARGB                                     0x10B7
#define CL_INTENSITY                                0x10B8
#define CL_LUMINANCE                                0x10B9
#ifdef CL_VERSION_1_1
#define CL_Rx                                       0x10BA
#define CL_RGx                                      0x10BB
#define CL_RGBx                                     0x10BC
#endif
#ifdef CL_VERSION_2_0
#define CL_DEPTH                                    0x10BD
#define CL_sRGB                                     0x10BF
#define CL_sRGBx                                    0x10C0
#define CL_sRGBA                                    0x10C1
#define CL_sBGRA                                    0x10C2
#define CL_ABGR                                     0x10C3
#endif

/* cl_channel_type */
#define CL_SNORM_INT8                               0x10D0
#define CL_SNORM_INT16                              0x10D1
#define CL_UNORM_INT8                               0x10D2
#define CL_UNORM_INT16                              0x10D3
#define CL_UNORM_SHORT_565                          0x10D4
#define CL_UNORM_SHORT_555                          0x10D5
#define CL_UNORM_INT_101010                         0x10D6
#define CL_SIGNED_INT8                              0x10D7
#define CL_SIGNED_INT16                             0x10D8
#define CL_SIGNED_INT32                             0x10D9
#define CL_UNSIGNED_INT8                            0x10DA
#define CL_UNSIGNED_INT16                           0x10DB
#define CL_UNSIGNED_INT32                           0x10DC
#define CL_HALF_FLOAT                               0x10DD
#define CL_FLOAT                                    0x10DE
#ifdef CL_VERSION_2_1
#define CL_UNORM_INT_101010_2                       0x10E0
#endif

/* cl_mem_object_type */
#define CL_MEM_OBJECT_BUFFER                        0x10F0
#define CL_MEM_OBJECT_IMAGE2D                       0x10F1
#define CL_MEM_OBJECT_IMAGE3D                       0x10F2
#ifdef CL_VERSION_1_2
#define CL_MEM_OBJECT_IMAGE2D_ARRAY                 0x10F3
#define CL_MEM_OBJECT_IMAGE1D                       0x10F4
#define CL_MEM_OBJECT_IMAGE1D_ARRAY                 0x10F5
#define CL_MEM_OBJECT_IMAGE1D_BUFFER                0x10F6
#endif
#ifdef CL_VERSION_2_0
#define CL_MEM_OBJECT_PIPE                          0x10F7
#endif

/* cl_mem_info */
#define CL_MEM_TYPE                                 0x1100
#define CL_MEM_FLAGS                                0x1101
#define CL_MEM_SIZE                                 0x1102
#define CL_MEM_HOST_PTR                             0x1103
#define CL_MEM_MAP_COUNT                            0x1104
#define CL_MEM_REFERENCE_COUNT                      0x1105
#define CL_MEM_CONTEXT                              0x1106
#ifdef CL_VERSION_1_1
#define CL_MEM_ASSOCIATED_MEMOBJECT                 0x1107
#define CL_MEM_OFFSET                               0x1108
#endif
#ifdef CL_VERSION_2_0
#define CL_MEM_USES_SVM_POINTER                     0x1109
#endif
#ifdef CL_VERSION_3_0
#define CL_MEM_PROPERTIES                           0x110A
#endif

/* cl_image_info */
#define CL_IMAGE_FORMAT                             0x1110
#define CL_IMAGE_ELEMENT_SIZE                       0x1111
#define CL_IMAGE_ROW_PITCH                          0x1112
#define CL_IMAGE_SLICE_PITCH                        0x1113
#define CL_IMAGE_WIDTH                              0x1114
#define CL_IMAGE_HEIGHT                             0x1115
#define CL_IMAGE_DEPTH                              0x1116
#ifdef CL_VERSION_1_2
#define CL_IMAGE_ARRAY_SIZE                         0x1117
#define CL_IMAGE_BUFFER                             0x1118
#define CL_IMAGE_NUM_MIP_LEVELS                     0x1119
#define CL_IMAGE_NUM_SAMPLES                        0x111A
#endif


/* cl_pipe_info */
#ifdef CL_VERSION_2_0
#define CL_PIPE_PACKET_SIZE                         0x1120
#define CL_PIPE_MAX_PACKETS                         0x1121
#endif
#ifdef CL_VERSION_3_0
#define CL_PIPE_PROPERTIES                          0x1122
#endif

/* cl_addressing_mode */
#define CL_ADDRESS_NONE                             0x1130
#define CL_ADDRESS_CLAMP_TO_EDGE                    0x1131
#define CL_ADDRESS_CLAMP                            0x1132
#define CL_ADDRESS_REPEAT                           0x1133
#ifdef CL_VERSION_1_1
#define CL_ADDRESS_MIRRORED_REPEAT                  0x1134
#endif

/* cl_filter_mode */
#define CL_FILTER_NEAREST                           0x1140
#define CL_FILTER_LINEAR                            0x1141

/* cl_sampler_info */
#define CL_SAMPLER_REFERENCE_COUNT                  0x1150
#define CL_SAMPLER_CONTEXT                          0x1151
#define CL_SAMPLER_NORMALIZED_COORDS                0x1152
#define CL_SAMPLER_ADDRESSING_MODE                  0x1153
#define CL_SAMPLER_FILTER_MODE                      0x1154
#ifdef CL_VERSION_2_0
/* These enumerants are for the cl_khr_mipmap_image extension.
   They have since been added to cl_ext.h with an appropriate
   KHR suffix, but are left here for backwards compatibility. */
#define CL_SAMPLER_MIP_FILTER_MODE                  0x1155
#define CL_SAMPLER_LOD_MIN                          0x1156
#define CL_SAMPLER_LOD_MAX                          0x1157
#endif
#ifdef CL_VERSION_3_0
#define CL_SAMPLER_PROPERTIES                       0x1158
#endif

/* cl_map_flags - bitfield */
#define CL_MAP_READ                                 (1 << 0)
#define CL_MAP_WRITE                                (1 << 1)
#ifdef CL_VERSION_1_2
#define CL_MAP_WRITE_INVALIDATE_REGION              (1 << 2)
#endif

/* cl_program_info */
#define CL_PROGRAM_REFERENCE_COUNT                  0x1160
#define CL_PROGRAM_CONTEXT                          0x1161
#define CL_PROGRAM_NUM_DEVICES                      0x1162
#define CL_PROGRAM_DEVICES                          0x1163
#define CL_PROGRAM_SOURCE                           0x1164
#define CL_PROGRAM_BINARY_SIZES                     0x1165
#define CL_PROGRAM_BINARIES                         0x1166
#ifdef CL_VERSION_1_2
#define CL_PROGRAM_NUM_KERNELS                      0x1167
#define CL_PROGRAM_KERNEL_NAMES                     0x1168
#endif
#ifdef CL_VERSION_2_1
#define CL_PROGRAM_IL                               0x1169
#endif
#ifdef CL_VERSION_2_2
#define CL_PROGRAM_SCOPE_GLOBAL_CTORS_PRESENT       0x116A
#define CL_PROGRAM_SCOPE_GLOBAL_DTORS_PRESENT       0x116B
#endif

/* cl_program_build_info */
#define CL_PROGRAM_BUILD_STATUS                     0x1181
#define CL_PROGRAM_BUILD_OPTIONS                    0x1182
#define CL_PROGRAM_BUILD_LOG                        0x1183
#ifdef CL_VERSION_1_2
#define CL_PROGRAM_BINARY_TYPE                      0x1184
#endif
#ifdef CL_VERSION_2_0
#define CL_PROGRAM_BUILD_GLOBAL_VARIABLE_TOTAL_SIZE 0x1185
#endif

#ifdef CL_VERSION_1_2

/* cl_program_binary_type */
#define CL_PROGRAM_BINARY_TYPE_NONE                 0x0
#define CL_PROGRAM_BINARY_TYPE_COMPILED_OBJECT      0x1
#define CL_PROGRAM_BINARY_TYPE_LIBRARY              0x2
#define CL_PROGRAM_BINARY_TYPE_EXECUTABLE           0x4

#endif

/* cl_build_status */
#define CL_BUILD_SUCCESS                            0
#define CL_BUILD_NONE                               -1
#define CL_BUILD_ERROR                              -2
#define CL_BUILD_IN_PROGRESS                        -3

/* cl_kernel_info */
#define CL_KERNEL_FUNCTION_NAME                     0x1190
#define CL_KERNEL_NUM_ARGS                          0x1191
#define CL_KERNEL_REFERENCE_COUNT                   0x1192
#define CL_KERNEL_CONTEXT                           0x1193
#define CL_KERNEL_PROGRAM                           0x1194
#ifdef CL_VERSION_1_2
#define CL_KERNEL_ATTRIBUTES                        0x1195
#endif

#ifdef CL_VERSION_1_2

/* cl_kernel_arg_info */
#define CL_KERNEL_ARG_ADDRESS_QUALIFIER             0x1196
#define CL_KERNEL_ARG_ACCESS_QUALIFIER              0x1197
#define CL_KERNEL_ARG_TYPE_NAME                     0x1198
#define CL_KERNEL_ARG_TYPE_QUALIFIER                0x1199
#define CL_KERNEL_ARG_NAME                          0x119A

#endif

#ifdef CL_VERSION_1_2

/* cl_kernel_arg_address_qualifier */
#define CL_KERNEL_ARG_ADDRESS_GLOBAL                0x119B
#define CL_KERNEL_ARG_ADDRESS_LOCAL                 0x119C
#define CL_KERNEL_ARG_ADDRESS_CONSTANT              0x119D
#define CL_KERNEL_ARG_ADDRESS_PRIVATE               0x119E

#endif

#ifdef CL_VERSION_1_2

/* cl_kernel_arg_access_qualifier */
#define CL_KERNEL_ARG_ACCESS_READ_ONLY              0x11A0
#define CL_KERNEL_ARG_ACCESS_WRITE_ONLY             0x11A1
#define CL_KERNEL_ARG_ACCESS_READ_WRITE             0x11A2
#define CL_KERNEL_ARG_ACCESS_NONE                   0x11A3

#endif

#ifdef CL_VERSION_1_2

/* cl_kernel_arg_type_qualifier */
#define CL_KERNEL_ARG_TYPE_NONE                     0
#define CL_KERNEL_ARG_TYPE_CONST                    (1 << 0)
#define CL_KERNEL_ARG_TYPE_RESTRICT                 (1 << 1)
#define CL_KERNEL_ARG_TYPE_VOLATILE                 (1 << 2)
#ifdef CL_VERSION_2_0
#define CL_KERNEL_ARG_TYPE_PIPE                     (1 << 3)
#endif

#endif

/* cl_kernel_work_group_info */
#define CL_KERNEL_WORK_GROUP_SIZE                   0x11B0
#define CL_KERNEL_COMPILE_WORK_GROUP_SIZE           0x11B1
#define CL_KERNEL_LOCAL_MEM_SIZE                    0x11B2
#define CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE 0x11B3
#define CL_KERNEL_PRIVATE_MEM_SIZE                  0x11B4
#ifdef CL_VERSION_1_2
#define CL_KERNEL_GLOBAL_WORK_SIZE                  0x11B5
#endif

#ifdef CL_VERSION_2_1

/* cl_kernel_sub_group_info */
#define CL_KERNEL_MAX_SUB_GROUP_SIZE_FOR_NDRANGE    0x2033
#define CL_KERNEL_SUB_GROUP_COUNT_FOR_NDRANGE       0x2034
#define CL_KERNEL_LOCAL_SIZE_FOR_SUB_GROUP_COUNT    0x11B8
#define CL_KERNEL_MAX_NUM_SUB_GROUPS                0x11B9
#define CL_KERNEL_COMPILE_NUM_SUB_GROUPS            0x11BA

#endif

#ifdef CL_VERSION_2_0

/* cl_kernel_exec_info */
#define CL_KERNEL_EXEC_INFO_SVM_PTRS                0x11B6
#define CL_KERNEL_EXEC_INFO_SVM_FINE_GRAIN_SYSTEM   0x11B7

#endif

/* cl_event_info */
#define CL_EVENT_COMMAND_QUEUE                      0x11D0
#define CL_EVENT_COMMAND_TYPE                       0x11D1
#define CL_EVENT_REFERENCE_COUNT                    0x11D2
#define CL_EVENT_COMMAND_EXECUTION_STATUS           0x11D3
#ifdef CL_VERSION_1_1
#define CL_EVENT_CONTEXT                            0x11D4
#endif

/* cl_command_type */
#define CL_COMMAND_NDRANGE_KERNEL                   0x11F0
#define CL_COMMAND_TASK                             0x11F1
#define CL_COMMAND_NATIVE_KERNEL                    0x11F2
#define CL_COMMAND_READ_BUFFER                      0x11F3
#define CL_COMMAND_WRITE_BUFFER                     0x11F4
#define CL_COMMAND_COPY_BUFFER                      0x11F5
#define CL_COMMAND_READ_IMAGE                       0x11F6
#define CL_COMMAND_WRITE_IMAGE                      0x11F7
#define CL_COMMAND_COPY_IMAGE                       0x11F8
#define CL_COMMAND_COPY_IMAGE_TO_BUFFER             0x11F9
#define CL_COMMAND_COPY_BUFFER_TO_IMAGE             0x11FA
#define CL_COMMAND_MAP_BUFFER                       0x11FB
#define CL_COMMAND_MAP_IMAGE                        0x11FC
#define CL_COMMAND_UNMAP_MEM_OBJECT                 0x11FD
#define CL_COMMAND_MARKER                           0x11FE
#define CL_COMMAND_ACQUIRE_GL_OBJECTS               0x11FF
#define CL_COMMAND_RELEASE_GL_OBJECTS               0x1200
#ifdef CL_VERSION_1_1
#define CL_COMMAND_READ_BUFFER_RECT                 0x1201
#define CL_COMMAND_WRITE_BUFFER_RECT                0x1202
#define CL_COMMAND_COPY_BUFFER_RECT                 0x1203
#define CL_COMMAND_USER                             0x1204
#endif
#ifdef CL_VERSION_1_2
#define CL_COMMAND_BARRIER                          0x1205
#define CL_COMMAND_MIGRATE_MEM_OBJECTS              0x1206
#define CL_COMMAND_FILL_BUFFER                      0x1207
#define CL_COMMAND_FILL_IMAGE                       0x1208
#endif
#ifdef CL_VERSION_2_0
#define CL_COMMAND_SVM_FREE                         0x1209
#define CL_COMMAND_SVM_MEMCPY                       0x120A
#define CL_COMMAND_SVM_MEMFILL                      0x120B
#define CL_COMMAND_SVM_MAP                          0x120C
#define CL_COMMAND_SVM_UNMAP                        0x120D
#endif
#ifdef CL_VERSION_3_0
#define CL_COMMAND_SVM_MIGRATE_MEM                  0x120E
#endif

/* command execution status */
#define CL_COMPLETE                                 0x0
#define CL_RUNNING                                  0x1
#define CL_SUBMITTED                                0x2
#define CL_QUEUED                                   0x3

/* cl_buffer_create_type */
#ifdef CL_VERSION_1_1
#define CL_BUFFER_CREATE_TYPE_REGION                0x1220
#endif

/* cl_profiling_info */
#define CL_PROFILING_COMMAND_QUEUED                 0x1280
#define CL_PROFILING_COMMAND_SUBMIT                 0x1281
#define CL_PROFILING_COMMAND_START                  0x1282
#define CL_PROFILING_COMMAND_END                    0x1283
#ifdef CL_VERSION_2_0
#define CL_PROFILING_COMMAND_COMPLETE               0x1284
#endif

/* cl_device_atomic_capabilities - bitfield */
#ifdef CL_VERSION_3_0
#define CL_DEVICE_ATOMIC_ORDER_RELAXED          (1 << 0)
#define CL_DEVICE_ATOMIC_ORDER_ACQ_REL          (1 << 1)
#define CL_DEVICE_ATOMIC_ORDER_SEQ_CST          (1 << 2)
#define CL_DEVICE_ATOMIC_SCOPE_WORK_ITEM        (1 << 3)
#define CL_DEVICE_ATOMIC_SCOPE_WORK_GROUP       (1 << 4)
#define CL_DEVICE_ATOMIC_SCOPE_DEVICE           (1 << 5)
#define CL_DEVICE_ATOMIC_SCOPE_ALL_DEVICES      (1 << 6)
#endif

/* cl_device_device_enqueue_capabilities - bitfield */
#ifdef CL_VERSION_3_0
#define CL_DEVICE_QUEUE_SUPPORTED               (1 << 0)
#define CL_DEVICE_QUEUE_REPLACEABLE_DEFAULT     (1 << 1)
#endif

/* cl_khronos_vendor_id */
#define CL_KHRONOS_VENDOR_ID_CODEPLAY               0x10004

#ifdef CL_VERSION_3_0

/* cl_version */
#define CL_VERSION_MAJOR_BITS (10)
#define CL_VERSION_MINOR_BITS (10)
#define CL_VERSION_PATCH_BITS (12)

#define CL_VERSION_MAJOR_MASK ((1 << CL_VERSION_MAJOR_BITS) - 1)
#define CL_VERSION_MINOR_MASK ((1 << CL_VERSION_MINOR_BITS) - 1)
#define CL_VERSION_PATCH_MASK ((1 << CL_VERSION_PATCH_BITS) - 1)

#define CL_VERSION_MAJOR(version) \
  ((version) >> (CL_VERSION_MINOR_BITS + CL_VERSION_PATCH_BITS))

#define CL_VERSION_MINOR(version) \
  (((version) >> CL_VERSION_PATCH_BITS) & CL_VERSION_MINOR_MASK)

#define CL_VERSION_PATCH(version) ((version) & CL_VERSION_PATCH_MASK)

#define CL_MAKE_VERSION(major, minor, patch)                      \
  ((((major) & CL_VERSION_MAJOR_MASK)                             \
       << (CL_VERSION_MINOR_BITS + CL_VERSION_PATCH_BITS)) |      \
   (((minor) & CL_VERSION_MINOR_MASK) << CL_VERSION_PATCH_BITS) | \
   ((patch) & CL_VERSION_PATCH_MASK))

#endif

/********************************************************************************************************/

/* CL_NO_PROTOTYPES implies CL_NO_CORE_PROTOTYPES: */
#if defined(CL_NO_PROTOTYPES) && !defined(CL_NO_CORE_PROTOTYPES)
#define CL_NO_CORE_PROTOTYPES
#endif

#if !defined(CL_NO_CORE_PROTOTYPES)

/* Platform API */
typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetPlatformIDs_t)(cl_uint          num_entries,
                 cl_platform_id * platforms,
                 cl_uint *        num_platforms) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetPlatformInfo_t)(cl_platform_id   platform,
                  cl_platform_info param_name,
                  size_t           param_value_size,
                  void *           param_value,
                  size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Device APIs */
typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetDeviceIDs_t)(cl_platform_id   platform,
               cl_device_type   device_type,
               cl_uint          num_entries,
               cl_device_id *   devices,
               cl_uint *        num_devices) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetDeviceInfo_t)(cl_device_id    device,
                cl_device_info  param_name,
                size_t          param_value_size,
                void *          param_value,
                size_t *        param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clCreateSubDevices_t)(cl_device_id                         in_device,
                   const cl_device_partition_property * properties,
                   cl_uint                              num_devices,
                   cl_device_id *                       out_devices,
                   cl_uint *                            num_devices_ret) CL_API_SUFFIX__VERSION_1_2;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clRetainDevice_t)(cl_device_id device) CL_API_SUFFIX__VERSION_1_2;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clReleaseDevice_t)(cl_device_id device) CL_API_SUFFIX__VERSION_1_2;

#endif

#ifdef CL_VERSION_2_1

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clSetDefaultDeviceCommandQueue_t)(cl_context           context,
                               cl_device_id         device,
                               cl_command_queue     command_queue) CL_API_SUFFIX__VERSION_2_1;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetDeviceAndHostTimer_t)(cl_device_id    device,
                        cl_ulong*       device_timestamp,
                        cl_ulong*       host_timestamp) CL_API_SUFFIX__VERSION_2_1;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetHostTimer_t)(cl_device_id device,
               cl_ulong *   host_timestamp) CL_API_SUFFIX__VERSION_2_1;

#endif

/* Context APIs */
typedef CL_API_ENTRY cl_context (CL_API_CALL *
clCreateContext_t)(const cl_context_properties * properties,
                cl_uint              num_devices,
                const cl_device_id * devices,
                void (CL_CALLBACK * pfn_notify)(const char * errinfo,
                                                const void * private_info,
                                                size_t       cb,
                                                void *       user_data),
                void *               user_data,
                cl_int *             errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_context (CL_API_CALL *
clCreateContextFromType_t)(const cl_context_properties * properties,
                        cl_device_type      device_type,
                        void (CL_CALLBACK * pfn_notify)(const char * errinfo,
                                                        const void * private_info,
                                                        size_t       cb,
                                                        void *       user_data),
                        void *              user_data,
                        cl_int *            errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clRetainContext_t)(cl_context context) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clReleaseContext_t)(cl_context context) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetContextInfo_t)(cl_context         context,
                 cl_context_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_3_0

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clSetContextDestructorCallback_t)(cl_context         context,
                               void (CL_CALLBACK* pfn_notify)(cl_context context,
                                                              void* user_data),
                               void*              user_data) CL_API_SUFFIX__VERSION_3_0;

#endif

/* Command Queue APIs */

#ifdef CL_VERSION_2_0

typedef CL_API_ENTRY cl_command_queue (CL_API_CALL *
clCreateCommandQueueWithProperties_t)(cl_context               context,
                                   cl_device_id             device,
                                   const cl_queue_properties *    properties,
                                   cl_int *                 errcode_ret) CL_API_SUFFIX__VERSION_2_0;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clRetainCommandQueue_t)(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clReleaseCommandQueue_t)(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetCommandQueueInfo_t)(cl_command_queue      command_queue,
                      cl_command_queue_info param_name,
                      size_t                param_value_size,
                      void *                param_value,
                      size_t *              param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Memory Object APIs */
typedef CL_API_ENTRY cl_mem (CL_API_CALL *
clCreateBuffer_t)(cl_context   context,
               cl_mem_flags flags,
               size_t       size,
               void *       host_ptr,
               cl_int *     errcode_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

typedef CL_API_ENTRY cl_mem (CL_API_CALL *
clCreateSubBuffer_t)(cl_mem                   buffer,
                  cl_mem_flags             flags,
                  cl_buffer_create_type    buffer_create_type,
                  const void *             buffer_create_info,
                  cl_int *                 errcode_ret) CL_API_SUFFIX__VERSION_1_1;

#endif

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_mem (CL_API_CALL *
clCreateImage_t)(cl_context              context,
              cl_mem_flags            flags,
              const cl_image_format * image_format,
              const cl_image_desc *   image_desc,
              void *                  host_ptr,
              cl_int *                errcode_ret) CL_API_SUFFIX__VERSION_1_2;

#endif

#ifdef CL_VERSION_2_0

typedef CL_API_ENTRY cl_mem (CL_API_CALL *
clCreatePipe_t)(cl_context                 context,
             cl_mem_flags               flags,
             cl_uint                    pipe_packet_size,
             cl_uint                    pipe_max_packets,
             const cl_pipe_properties * properties,
             cl_int *                   errcode_ret) CL_API_SUFFIX__VERSION_2_0;

#endif

#ifdef CL_VERSION_3_0

typedef CL_API_ENTRY cl_mem (CL_API_CALL *
clCreateBufferWithProperties_t)(cl_context                context,
                             const cl_mem_properties * properties,
                             cl_mem_flags              flags,
                             size_t                    size,
                             void *                    host_ptr,
                             cl_int *                  errcode_ret) CL_API_SUFFIX__VERSION_3_0;

typedef CL_API_ENTRY cl_mem (CL_API_CALL *
clCreateImageWithProperties_t)(cl_context                context,
                            const cl_mem_properties * properties,
                            cl_mem_flags              flags,
                            const cl_image_format *   image_format,
                            const cl_image_desc *     image_desc,
                            void *                    host_ptr,
                            cl_int *                  errcode_ret) CL_API_SUFFIX__VERSION_3_0;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clRetainMemObject_t)(cl_mem memobj) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clReleaseMemObject_t)(cl_mem memobj) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetSupportedImageFormats_t)(cl_context           context,
                           cl_mem_flags         flags,
                           cl_mem_object_type   image_type,
                           cl_uint              num_entries,
                           cl_image_format *    image_formats,
                           cl_uint *            num_image_formats) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetMemObjectInfo_t)(cl_mem           memobj,
                   cl_mem_info      param_name,
                   size_t           param_value_size,
                   void *           param_value,
                   size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetImageInfo_t)(cl_mem           image,
               cl_image_info    param_name,
               size_t           param_value_size,
               void *           param_value,
               size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_0

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetPipeInfo_t)(cl_mem           pipe,
              cl_pipe_info     param_name,
              size_t           param_value_size,
              void *           param_value,
              size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_2_0;

#endif

#ifdef CL_VERSION_1_1

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clSetMemObjectDestructorCallback_t)(cl_mem memobj,
                                 void (CL_CALLBACK * pfn_notify)(cl_mem memobj,
                                                                 void * user_data),
                                 void * user_data) CL_API_SUFFIX__VERSION_1_1;

#endif

/* SVM Allocation APIs */

#ifdef CL_VERSION_2_0

typedef CL_API_ENTRY void * (CL_API_CALL *
clSVMAlloc_t)(cl_context       context,
           cl_svm_mem_flags flags,
           size_t           size,
           cl_uint          alignment) CL_API_SUFFIX__VERSION_2_0;

typedef CL_API_ENTRY void (CL_API_CALL *
clSVMFree_t)(cl_context        context,
          void *            svm_pointer) CL_API_SUFFIX__VERSION_2_0;

#endif

/* Sampler APIs */

#ifdef CL_VERSION_2_0

typedef CL_API_ENTRY cl_sampler (CL_API_CALL *
clCreateSamplerWithProperties_t)(cl_context                     context,
                              const cl_sampler_properties *  sampler_properties,
                              cl_int *                       errcode_ret) CL_API_SUFFIX__VERSION_2_0;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clRetainSampler_t)(cl_sampler sampler) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clReleaseSampler_t)(cl_sampler sampler) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetSamplerInfo_t)(cl_sampler         sampler,
                 cl_sampler_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Program Object APIs */
typedef CL_API_ENTRY cl_program (CL_API_CALL *
clCreateProgramWithSource_t)(cl_context        context,
                          cl_uint           count,
                          const char **     strings,
                          const size_t *    lengths,
                          cl_int *          errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_program (CL_API_CALL *
clCreateProgramWithBinary_t)(cl_context                     context,
                          cl_uint                        num_devices,
                          const cl_device_id *           device_list,
                          const size_t *                 lengths,
                          const unsigned char **         binaries,
                          cl_int *                       binary_status,
                          cl_int *                       errcode_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_program (CL_API_CALL *
clCreateProgramWithBuiltInKernels_t)(cl_context            context,
                                  cl_uint               num_devices,
                                  const cl_device_id *  device_list,
                                  const char *          kernel_names,
                                  cl_int *              errcode_ret) CL_API_SUFFIX__VERSION_1_2;

#endif

#ifdef CL_VERSION_2_1

typedef CL_API_ENTRY cl_program (CL_API_CALL *
clCreateProgramWithIL_t)(cl_context    context,
                     const void*    il,
                     size_t         length,
                     cl_int*        errcode_ret) CL_API_SUFFIX__VERSION_2_1;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clRetainProgram_t)(cl_program program) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clReleaseProgram_t)(cl_program program) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clBuildProgram_t)(cl_program           program,
               cl_uint              num_devices,
               const cl_device_id * device_list,
               const char *         options,
               void (CL_CALLBACK *  pfn_notify)(cl_program program,
                                                void * user_data),
               void *               user_data) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clCompileProgram_t)(cl_program           program,
                 cl_uint              num_devices,
                 const cl_device_id * device_list,
                 const char *         options,
                 cl_uint              num_input_headers,
                 const cl_program *   input_headers,
                 const char **        header_include_names,
                 void (CL_CALLBACK *  pfn_notify)(cl_program program,
                                                  void * user_data),
                 void *               user_data) CL_API_SUFFIX__VERSION_1_2;

typedef CL_API_ENTRY cl_program (CL_API_CALL *
clLinkProgram_t)(cl_context           context,
              cl_uint              num_devices,
              const cl_device_id * device_list,
              const char *         options,
              cl_uint              num_input_programs,
              const cl_program *   input_programs,
              void (CL_CALLBACK *  pfn_notify)(cl_program program,
                                               void * user_data),
              void *               user_data,
              cl_int *             errcode_ret) CL_API_SUFFIX__VERSION_1_2;

#endif

#ifdef CL_VERSION_2_2

typedef CL_API_ENTRY CL_API_PREFIX__VERSION_2_2_DEPRECATED cl_int (CL_API_CALL *
clSetProgramReleaseCallback_t)(cl_program          program,
                            void (CL_CALLBACK * pfn_notify)(cl_program program,
                                                            void * user_data),
                            void *              user_data) CL_API_SUFFIX__VERSION_2_2_DEPRECATED;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clSetProgramSpecializationConstant_t)(cl_program  program,
                                   cl_uint     spec_id,
                                   size_t      spec_size,
                                   const void* spec_value) CL_API_SUFFIX__VERSION_2_2;

#endif

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clUnloadPlatformCompiler_t)(cl_platform_id platform) CL_API_SUFFIX__VERSION_1_2;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetProgramInfo_t)(cl_program         program,
                 cl_program_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetProgramBuildInfo_t)(cl_program            program,
                      cl_device_id          device,
                      cl_program_build_info param_name,
                      size_t                param_value_size,
                      void *                param_value,
                      size_t *              param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Kernel Object APIs */
typedef CL_API_ENTRY cl_kernel (CL_API_CALL *
clCreateKernel_t)(cl_program      program,
               const char *    kernel_name,
               cl_int *        errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clCreateKernelsInProgram_t)(cl_program     program,
                         cl_uint        num_kernels,
                         cl_kernel *    kernels,
                         cl_uint *      num_kernels_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_1

typedef CL_API_ENTRY cl_kernel (CL_API_CALL *
clCloneKernel_t)(cl_kernel     source_kernel,
              cl_int*       errcode_ret) CL_API_SUFFIX__VERSION_2_1;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clRetainKernel_t)(cl_kernel    kernel) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clReleaseKernel_t)(cl_kernel   kernel) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clSetKernelArg_t)(cl_kernel    kernel,
               cl_uint      arg_index,
               size_t       arg_size,
               const void * arg_value) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_0

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clSetKernelArgSVMPointer_t)(cl_kernel    kernel,
                         cl_uint      arg_index,
                         const void * arg_value) CL_API_SUFFIX__VERSION_2_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clSetKernelExecInfo_t)(cl_kernel            kernel,
                    cl_kernel_exec_info  param_name,
                    size_t               param_value_size,
                    const void *         param_value) CL_API_SUFFIX__VERSION_2_0;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetKernelInfo_t)(cl_kernel       kernel,
                cl_kernel_info  param_name,
                size_t          param_value_size,
                void *          param_value,
                size_t *        param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetKernelArgInfo_t)(cl_kernel       kernel,
                   cl_uint         arg_indx,
                   cl_kernel_arg_info  param_name,
                   size_t          param_value_size,
                   void *          param_value,
                   size_t *        param_value_size_ret) CL_API_SUFFIX__VERSION_1_2;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetKernelWorkGroupInfo_t)(cl_kernel                  kernel,
                         cl_device_id               device,
                         cl_kernel_work_group_info  param_name,
                         size_t                     param_value_size,
                         void *                     param_value,
                         size_t *                   param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_1

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetKernelSubGroupInfo_t)(cl_kernel                   kernel,
                        cl_device_id                device,
                        cl_kernel_sub_group_info    param_name,
                        size_t                      input_value_size,
                        const void*                 input_value,
                        size_t                      param_value_size,
                        void*                       param_value,
                        size_t*                     param_value_size_ret) CL_API_SUFFIX__VERSION_2_1;

#endif

/* Event Object APIs */
typedef CL_API_ENTRY cl_int (CL_API_CALL *
clWaitForEvents_t)(cl_uint             num_events,
                const cl_event *    event_list) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetEventInfo_t)(cl_event         event,
               cl_event_info    param_name,
               size_t           param_value_size,
               void *           param_value,
               size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

typedef CL_API_ENTRY cl_event (CL_API_CALL *
clCreateUserEvent_t)(cl_context    context,
                  cl_int *      errcode_ret) CL_API_SUFFIX__VERSION_1_1;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clRetainEvent_t)(cl_event event) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clReleaseEvent_t)(cl_event event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clSetUserEventStatus_t)(cl_event   event,
                     cl_int     execution_status) CL_API_SUFFIX__VERSION_1_1;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clSetEventCallback_t)(cl_event    event,
                   cl_int      command_exec_callback_type,
                   void (CL_CALLBACK * pfn_notify)(cl_event event,
                                                   cl_int   event_command_status,
                                                   void *   user_data),
                   void *      user_data) CL_API_SUFFIX__VERSION_1_1;

#endif

/* Profiling APIs */
typedef CL_API_ENTRY cl_int (CL_API_CALL *
clGetEventProfilingInfo_t)(cl_event            event,
                        cl_profiling_info   param_name,
                        size_t              param_value_size,
                        void *              param_value,
                        size_t *            param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Flush and Finish APIs */
typedef CL_API_ENTRY cl_int (CL_API_CALL *
clFlush_t)(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clFinish_t)(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;

/* Enqueued Commands APIs */
typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueReadBuffer_t)(cl_command_queue    command_queue,
                    cl_mem              buffer,
                    cl_bool             blocking_read,
                    size_t              offset,
                    size_t              size,
                    void *              ptr,
                    cl_uint             num_events_in_wait_list,
                    const cl_event *    event_wait_list,
                    cl_event *          event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueReadBufferRect_t)(cl_command_queue    command_queue,
                        cl_mem              buffer,
                        cl_bool             blocking_read,
                        const size_t *      buffer_origin,
                        const size_t *      host_origin,
                        const size_t *      region,
                        size_t              buffer_row_pitch,
                        size_t              buffer_slice_pitch,
                        size_t              host_row_pitch,
                        size_t              host_slice_pitch,
                        void *              ptr,
                        cl_uint             num_events_in_wait_list,
                        const cl_event *    event_wait_list,
                        cl_event *          event) CL_API_SUFFIX__VERSION_1_1;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueWriteBuffer_t)(cl_command_queue   command_queue,
                     cl_mem             buffer,
                     cl_bool            blocking_write,
                     size_t             offset,
                     size_t             size,
                     const void *       ptr,
                     cl_uint            num_events_in_wait_list,
                     const cl_event *   event_wait_list,
                     cl_event *         event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueWriteBufferRect_t)(cl_command_queue    command_queue,
                         cl_mem              buffer,
                         cl_bool             blocking_write,
                         const size_t *      buffer_origin,
                         const size_t *      host_origin,
                         const size_t *      region,
                         size_t              buffer_row_pitch,
                         size_t              buffer_slice_pitch,
                         size_t              host_row_pitch,
                         size_t              host_slice_pitch,
                         const void *        ptr,
                         cl_uint             num_events_in_wait_list,
                         const cl_event *    event_wait_list,
                         cl_event *          event) CL_API_SUFFIX__VERSION_1_1;

#endif

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueFillBuffer_t)(cl_command_queue   command_queue,
                    cl_mem             buffer,
                    const void *       pattern,
                    size_t             pattern_size,
                    size_t             offset,
                    size_t             size,
                    cl_uint            num_events_in_wait_list,
                    const cl_event *   event_wait_list,
                    cl_event *         event) CL_API_SUFFIX__VERSION_1_2;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueCopyBuffer_t)(cl_command_queue    command_queue,
                    cl_mem              src_buffer,
                    cl_mem              dst_buffer,
                    size_t              src_offset,
                    size_t              dst_offset,
                    size_t              size,
                    cl_uint             num_events_in_wait_list,
                    const cl_event *    event_wait_list,
                    cl_event *          event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueCopyBufferRect_t)(cl_command_queue    command_queue,
                        cl_mem              src_buffer,
                        cl_mem              dst_buffer,
                        const size_t *      src_origin,
                        const size_t *      dst_origin,
                        const size_t *      region,
                        size_t              src_row_pitch,
                        size_t              src_slice_pitch,
                        size_t              dst_row_pitch,
                        size_t              dst_slice_pitch,
                        cl_uint             num_events_in_wait_list,
                        const cl_event *    event_wait_list,
                        cl_event *          event) CL_API_SUFFIX__VERSION_1_1;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueReadImage_t)(cl_command_queue     command_queue,
                   cl_mem               image,
                   cl_bool              blocking_read,
                   const size_t *       origin,
                   const size_t *       region,
                   size_t               row_pitch,
                   size_t               slice_pitch,
                   void *               ptr,
                   cl_uint              num_events_in_wait_list,
                   const cl_event *     event_wait_list,
                   cl_event *           event) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueWriteImage_t)(cl_command_queue    command_queue,
                    cl_mem              image,
                    cl_bool             blocking_write,
                    const size_t *      origin,
                    const size_t *      region,
                    size_t              input_row_pitch,
                    size_t              input_slice_pitch,
                    const void *        ptr,
                    cl_uint             num_events_in_wait_list,
                    const cl_event *    event_wait_list,
                    cl_event *          event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueFillImage_t)(cl_command_queue   command_queue,
                   cl_mem             image,
                   const void *       fill_color,
                   const size_t *     origin,
                   const size_t *     region,
                   cl_uint            num_events_in_wait_list,
                   const cl_event *   event_wait_list,
                   cl_event *         event) CL_API_SUFFIX__VERSION_1_2;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueCopyImage_t)(cl_command_queue     command_queue,
                   cl_mem               src_image,
                   cl_mem               dst_image,
                   const size_t *       src_origin,
                   const size_t *       dst_origin,
                   const size_t *       region,
                   cl_uint              num_events_in_wait_list,
                   const cl_event *     event_wait_list,
                   cl_event *           event) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueCopyImageToBuffer_t)(cl_command_queue command_queue,
                           cl_mem           src_image,
                           cl_mem           dst_buffer,
                           const size_t *   src_origin,
                           const size_t *   region,
                           size_t           dst_offset,
                           cl_uint          num_events_in_wait_list,
                           const cl_event * event_wait_list,
                           cl_event *       event) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueCopyBufferToImage_t)(cl_command_queue command_queue,
                           cl_mem           src_buffer,
                           cl_mem           dst_image,
                           size_t           src_offset,
                           const size_t *   dst_origin,
                           const size_t *   region,
                           cl_uint          num_events_in_wait_list,
                           const cl_event * event_wait_list,
                           cl_event *       event) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY void * (CL_API_CALL *
clEnqueueMapBuffer_t)(cl_command_queue command_queue,
                   cl_mem           buffer,
                   cl_bool          blocking_map,
                   cl_map_flags     map_flags,
                   size_t           offset,
                   size_t           size,
                   cl_uint          num_events_in_wait_list,
                   const cl_event * event_wait_list,
                   cl_event *       event,
                   cl_int *         errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY void * (CL_API_CALL *
clEnqueueMapImage_t)(cl_command_queue  command_queue,
                  cl_mem            image,
                  cl_bool           blocking_map,
                  cl_map_flags      map_flags,
                  const size_t *    origin,
                  const size_t *    region,
                  size_t *          image_row_pitch,
                  size_t *          image_slice_pitch,
                  cl_uint           num_events_in_wait_list,
                  const cl_event *  event_wait_list,
                  cl_event *        event,
                  cl_int *          errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueUnmapMemObject_t)(cl_command_queue command_queue,
                        cl_mem           memobj,
                        void *           mapped_ptr,
                        cl_uint          num_events_in_wait_list,
                        const cl_event * event_wait_list,
                        cl_event *       event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueMigrateMemObjects_t)(cl_command_queue       command_queue,
                           cl_uint                num_mem_objects,
                           const cl_mem *         mem_objects,
                           cl_mem_migration_flags flags,
                           cl_uint                num_events_in_wait_list,
                           const cl_event *       event_wait_list,
                           cl_event *             event) CL_API_SUFFIX__VERSION_1_2;

#endif

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueNDRangeKernel_t)(cl_command_queue command_queue,
                       cl_kernel        kernel,
                       cl_uint          work_dim,
                       const size_t *   global_work_offset,
                       const size_t *   global_work_size,
                       const size_t *   local_work_size,
                       cl_uint          num_events_in_wait_list,
                       const cl_event * event_wait_list,
                       cl_event *       event) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueNativeKernel_t)(cl_command_queue  command_queue,
                      void (CL_CALLBACK * user_func)(void *),
                      void *            args,
                      size_t            cb_args,
                      cl_uint           num_mem_objects,
                      const cl_mem *    mem_list,
                      const void **     args_mem_loc,
                      cl_uint           num_events_in_wait_list,
                      const cl_event *  event_wait_list,
                      cl_event *        event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueMarkerWithWaitList_t)(cl_command_queue  command_queue,
                            cl_uint           num_events_in_wait_list,
                            const cl_event *  event_wait_list,
                            cl_event *        event) CL_API_SUFFIX__VERSION_1_2;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueBarrierWithWaitList_t)(cl_command_queue  command_queue,
                             cl_uint           num_events_in_wait_list,
                             const cl_event *  event_wait_list,
                             cl_event *        event) CL_API_SUFFIX__VERSION_1_2;

#endif

#ifdef CL_VERSION_2_0

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueSVMFree_t)(cl_command_queue  command_queue,
                 cl_uint           num_svm_pointers,
                 void *            svm_pointers[],
                 void (CL_CALLBACK * pfn_free_func)(cl_command_queue queue,
                                                    cl_uint          num_svm_pointers,
                                                    void *           svm_pointers[],
                                                    void *           user_data),
                 void *            user_data,
                 cl_uint           num_events_in_wait_list,
                 const cl_event *  event_wait_list,
                 cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueSVMMemcpy_t)(cl_command_queue  command_queue,
                   cl_bool           blocking_copy,
                   void *            dst_ptr,
                   const void *      src_ptr,
                   size_t            size,
                   cl_uint           num_events_in_wait_list,
                   const cl_event *  event_wait_list,
                   cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueSVMMemFill_t)(cl_command_queue  command_queue,
                    void *            svm_ptr,
                    const void *      pattern,
                    size_t            pattern_size,
                    size_t            size,
                    cl_uint           num_events_in_wait_list,
                    const cl_event *  event_wait_list,
                    cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueSVMMap_t)(cl_command_queue  command_queue,
                cl_bool           blocking_map,
                cl_map_flags      flags,
                void *            svm_ptr,
                size_t            size,
                cl_uint           num_events_in_wait_list,
                const cl_event *  event_wait_list,
                cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueSVMUnmap_t)(cl_command_queue  command_queue,
                  void *            svm_ptr,
                  cl_uint           num_events_in_wait_list,
                  const cl_event *  event_wait_list,
                  cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

#endif

#ifdef CL_VERSION_2_1

typedef CL_API_ENTRY cl_int (CL_API_CALL *
clEnqueueSVMMigrateMem_t)(cl_command_queue         command_queue,
                       cl_uint                  num_svm_pointers,
                       const void **            svm_pointers,
                       const size_t *           sizes,
                       cl_mem_migration_flags   flags,
                       cl_uint                  num_events_in_wait_list,
                       const cl_event *         event_wait_list,
                       cl_event *               event) CL_API_SUFFIX__VERSION_2_1;

#endif

#ifdef CL_VERSION_1_2

/* Extension function access
 *
 * Returns the extension function address for the given function name,
 * or NULL if a valid function can not be found.  The client must
 * check to make sure the address is not NULL, before using or
 * calling the returned function address.
 */
typedef CL_API_ENTRY void * (CL_API_CALL *
clGetExtensionFunctionAddressForPlatform_t)(cl_platform_id platform,
                                         const char *   func_name) CL_API_SUFFIX__VERSION_1_2;

#endif

#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
    /*
     *  WARNING:
     *     This API introduces mutable state into the OpenCL implementation. It has been REMOVED
     *  to better facilitate thread safety.  The 1.0 API is not thread safe. It is not tested by the
     *  OpenCL 1.1 conformance test, and consequently may not work or may not work dependably.
     *  It is likely to be non-performant. Use of this API is not advised. Use at your own risk.
     *
     *  Software developers previously relying on this API are instructed to set the command queue
     *  properties when creating the queue, instead.
     */
    typedef CL_API_ENTRY cl_int (CL_API_CALL *
    clSetCommandQueueProperty_t)(cl_command_queue              command_queue,
                              cl_command_queue_properties   properties,
                              cl_bool                       enable,
                              cl_command_queue_properties * old_properties) CL_API_SUFFIX__VERSION_1_0_DEPRECATED;
#endif /* CL_USE_DEPRECATED_OPENCL_1_0_APIS */

/* Deprecated OpenCL 1.1 APIs */
typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem (CL_API_CALL *
clCreateImage2D_t)(cl_context              context,
                cl_mem_flags            flags,
                const cl_image_format * image_format,
                size_t                  image_width,
                size_t                  image_height,
                size_t                  image_row_pitch,
                void *                  host_ptr,
                cl_int *                errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem (CL_API_CALL *
clCreateImage3D_t)(cl_context              context,
                cl_mem_flags            flags,
                const cl_image_format * image_format,
                size_t                  image_width,
                size_t                  image_height,
                size_t                  image_depth,
                size_t                  image_row_pitch,
                size_t                  image_slice_pitch,
                void *                  host_ptr,
                cl_int *                errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int (CL_API_CALL *
clEnqueueMarker_t)(cl_command_queue    command_queue,
                cl_event *          event) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int (CL_API_CALL *
clEnqueueWaitForEvents_t)(cl_command_queue  command_queue,
                        cl_uint          num_events,
                        const cl_event * event_list) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int (CL_API_CALL *
clEnqueueBarrier_t)(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int (CL_API_CALL *
clUnloadCompiler_t)(void) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED void * (CL_API_CALL *
clGetExtensionFunctionAddress_t)(const char * func_name) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

/* Deprecated OpenCL 2.0 APIs */
typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_command_queue (CL_API_CALL *
clCreateCommandQueue_t)(cl_context                     context,
                     cl_device_id                   device,
                     cl_command_queue_properties    properties,
                     cl_int *                       errcode_ret) CL_API_SUFFIX__VERSION_1_2_DEPRECATED;

typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_sampler (CL_API_CALL *
clCreateSampler_t)(cl_context          context,
                cl_bool             normalized_coords,
                cl_addressing_mode  addressing_mode,
                cl_filter_mode      filter_mode,
                cl_int *            errcode_ret) CL_API_SUFFIX__VERSION_1_2_DEPRECATED;

typedef CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_int (CL_API_CALL *
clEnqueueTask_t)(cl_command_queue  command_queue,
              cl_kernel         kernel,
              cl_uint           num_events_in_wait_list,
              const cl_event *  event_wait_list,
              cl_event *        event) CL_API_SUFFIX__VERSION_1_2_DEPRECATED;

#endif /* !defined(CL_NO_CORE_PROTOTYPES) */

// Created by Pedro Bento 2024
//
// This content has been created by Pedro Bento 
// and the additions can be found at: https://github.com/pedro-bento/clew

clGetPlatformIDs_t clGetPlatformIDs;
clGetPlatformInfo_t clGetPlatformInfo;
clGetDeviceIDs_t clGetDeviceIDs;
clGetDeviceInfo_t clGetDeviceInfo;
#ifdef CL_VERSION_1_2
clCreateSubDevices_t clCreateSubDevices;
clRetainDevice_t clRetainDevice;
clReleaseDevice_t clReleaseDevice;
#endif
#ifdef CL_VERSION_2_1
clSetDefaultDeviceCommandQueue_t clSetDefaultDeviceCommandQueue;
clGetDeviceAndHostTimer_t clGetDeviceAndHostTimer;
clGetHostTimer_t clGetHostTimer;
#endif
clCreateContext_t clCreateContext;
clCreateContextFromType_t clCreateContextFromType;
clRetainContext_t clRetainContext;
clReleaseContext_t clReleaseContext;
clGetContextInfo_t clGetContextInfo;
#ifdef CL_VERSION_3_0
clSetContextDestructorCallback_t clSetContextDestructorCallback;
#endif
#ifdef CL_VERSION_2_0
clCreateCommandQueueWithProperties_t clCreateCommandQueueWithProperties;
#endif
clRetainCommandQueue_t clRetainCommandQueue;
clReleaseCommandQueue_t clReleaseCommandQueue;
clGetCommandQueueInfo_t clGetCommandQueueInfo;
clCreateBuffer_t clCreateBuffer;
#ifdef CL_VERSION_1_1
clCreateSubBuffer_t clCreateSubBuffer;
#endif
#ifdef CL_VERSION_1_2
clCreateImage_t clCreateImage;
#endif
#ifdef CL_VERSION_2_0
clCreatePipe_t clCreatePipe;
#endif
#ifdef CL_VERSION_3_0
clCreateBufferWithProperties_t clCreateBufferWithProperties;
clCreateImageWithProperties_t clCreateImageWithProperties;
#endif
clRetainMemObject_t clRetainMemObject;
clReleaseMemObject_t clReleaseMemObject;
clGetSupportedImageFormats_t clGetSupportedImageFormats;
clGetMemObjectInfo_t clGetMemObjectInfo;
clGetImageInfo_t clGetImageInfo;
#ifdef CL_VERSION_2_0
clGetPipeInfo_t clGetPipeInfo;
#endif
#ifdef CL_VERSION_1_1
clSetMemObjectDestructorCallback_t clSetMemObjectDestructorCallback;
#endif
#ifdef CL_VERSION_2_0
clSVMAlloc_t clSVMAlloc;
clSVMFree_t clSVMFree;
#endif
#ifdef CL_VERSION_2_0
clCreateSamplerWithProperties_t clCreateSamplerWithProperties;
#endif
clRetainSampler_t clRetainSampler;
clReleaseSampler_t clReleaseSampler;
clGetSamplerInfo_t clGetSamplerInfo;
clCreateProgramWithSource_t clCreateProgramWithSource;
clCreateProgramWithBinary_t clCreateProgramWithBinary;
#ifdef CL_VERSION_1_2
clCreateProgramWithBuiltInKernels_t clCreateProgramWithBuiltInKernels;
#endif
#ifdef CL_VERSION_2_1
clCreateProgramWithIL_t clCreateProgramWithIL;
#endif
clRetainProgram_t clRetainProgram;
clReleaseProgram_t clReleaseProgram;
clBuildProgram_t clBuildProgram;
#ifdef CL_VERSION_1_2
clCompileProgram_t clCompileProgram;
clLinkProgram_t clLinkProgram;
#endif
#ifdef CL_VERSION_2_2
clSetProgramReleaseCallback_t clSetProgramReleaseCallback;
clSetProgramSpecializationConstant_t clSetProgramSpecializationConstant;
#endif
#ifdef CL_VERSION_1_2
clUnloadPlatformCompiler_t clUnloadPlatformCompiler;
#endif
clGetProgramInfo_t clGetProgramInfo;
clGetProgramBuildInfo_t clGetProgramBuildInfo;
clCreateKernel_t clCreateKernel;
clCreateKernelsInProgram_t clCreateKernelsInProgram;
#ifdef CL_VERSION_2_1
clCloneKernel_t clCloneKernel;
#endif
clRetainKernel_t clRetainKernel;
clReleaseKernel_t clReleaseKernel;
clSetKernelArg_t clSetKernelArg;
#ifdef CL_VERSION_2_0
clSetKernelArgSVMPointer_t clSetKernelArgSVMPointer;
clSetKernelExecInfo_t clSetKernelExecInfo;
#endif
clGetKernelInfo_t clGetKernelInfo;
#ifdef CL_VERSION_1_2
clGetKernelArgInfo_t clGetKernelArgInfo;
#endif
clGetKernelWorkGroupInfo_t clGetKernelWorkGroupInfo;
#ifdef CL_VERSION_2_1
clGetKernelSubGroupInfo_t clGetKernelSubGroupInfo;
#endif
clWaitForEvents_t clWaitForEvents;
clGetEventInfo_t clGetEventInfo;
#ifdef CL_VERSION_1_1
clCreateUserEvent_t clCreateUserEvent;
#endif
clRetainEvent_t clRetainEvent;
clReleaseEvent_t clReleaseEvent;
#ifdef CL_VERSION_1_1
clSetUserEventStatus_t clSetUserEventStatus;
clSetEventCallback_t clSetEventCallback;
#endif
clGetEventProfilingInfo_t clGetEventProfilingInfo;
clFlush_t clFlush;
clFinish_t clFinish;
clEnqueueReadBuffer_t clEnqueueReadBuffer;
#ifdef CL_VERSION_1_1
clEnqueueReadBufferRect_t clEnqueueReadBufferRect;
#endif
clEnqueueWriteBuffer_t clEnqueueWriteBuffer;
#ifdef CL_VERSION_1_1
clEnqueueWriteBufferRect_t clEnqueueWriteBufferRect;
#endif
#ifdef CL_VERSION_1_2
clEnqueueFillBuffer_t clEnqueueFillBuffer;
#endif
clEnqueueCopyBuffer_t clEnqueueCopyBuffer;
#ifdef CL_VERSION_1_1
clEnqueueCopyBufferRect_t clEnqueueCopyBufferRect;
#endif
clEnqueueReadImage_t clEnqueueReadImage;
clEnqueueWriteImage_t clEnqueueWriteImage;
#ifdef CL_VERSION_1_2
clEnqueueFillImage_t clEnqueueFillImage;
#endif
clEnqueueCopyImage_t clEnqueueCopyImage;
clEnqueueCopyImageToBuffer_t clEnqueueCopyImageToBuffer;
clEnqueueCopyBufferToImage_t clEnqueueCopyBufferToImage;
clEnqueueMapBuffer_t clEnqueueMapBuffer;
clEnqueueMapImage_t clEnqueueMapImage;
clEnqueueUnmapMemObject_t clEnqueueUnmapMemObject;
#ifdef CL_VERSION_1_2
clEnqueueMigrateMemObjects_t clEnqueueMigrateMemObjects;
#endif
clEnqueueNDRangeKernel_t clEnqueueNDRangeKernel;
clEnqueueNativeKernel_t clEnqueueNativeKernel;
#ifdef CL_VERSION_1_2
clEnqueueMarkerWithWaitList_t clEnqueueMarkerWithWaitList;
clEnqueueBarrierWithWaitList_t clEnqueueBarrierWithWaitList;
#endif
#ifdef CL_VERSION_2_0
clEnqueueSVMFree_t clEnqueueSVMFree;
clEnqueueSVMMemcpy_t clEnqueueSVMMemcpy;
clEnqueueSVMMemFill_t clEnqueueSVMMemFill;
clEnqueueSVMMap_t clEnqueueSVMMap;
clEnqueueSVMUnmap_t clEnqueueSVMUnmap;
#endif
#ifdef CL_VERSION_2_1
clEnqueueSVMMigrateMem_t clEnqueueSVMMigrateMem;
#endif
#ifdef CL_VERSION_1_2
clGetExtensionFunctionAddressForPlatform_t clGetExtensionFunctionAddressForPlatform;
#endif
#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
clSetCommandQueueProperty_t clSetCommandQueueProperty;
#endif
clCreateImage2D_t clCreateImage2D;
clCreateImage3D_t clCreateImage3D;
clEnqueueMarker_t clEnqueueMarker;
clEnqueueWaitForEvents_t clEnqueueWaitForEvents;
clEnqueueBarrier_t clEnqueueBarrier;
clUnloadCompiler_t clUnloadCompiler;
clGetExtensionFunctionAddress_t clGetExtensionFunctionAddress;
clCreateCommandQueue_t clCreateCommandQueue;
clCreateSampler_t clCreateSampler;
clEnqueueTask_t clEnqueueTask;

#ifdef __cplusplus
}
#endif

const char* clew_init();
void clew_quit();

#endif /* CLEW_H */

#ifdef CLEW_IMPLEMENTATION

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #define VC_EXTRALEAN
    #include <windows.h>

    typedef HMODULE clew_handle_t;

    #define clew_dlopen LoadLibrary
    #define clew_dlclose FreeLibrary
    #define clew_psearch GetProcAddress
    #define clew_pdefined(proc) ((proc) != NULL)
#else
    #include <dlfcn.h>

    typedef void* clew_handle_t;

    #define clew_dlopen(path) dlopen((path), RTLD_LAZY)
    #define clew_dlclose dlclose
    #define clew_psearch dlsym
    #define clew_pdefined(proc) ((error = dlerror()) != NULL)
#endif

static clew_handle_t clew_handle = NULL;

const char* clew_init()
{
#ifdef _WIN32
    const char* paths[] = { "OpenCL.dll" };
#elif defined(__APPLE__)
    const char* paths[] = { "/Library/Frameworks/OpenCL.framework/OpenCL" };
#else
    const char* paths[] = { "libOpenCL.so", "libOpenCL.so.0", "libOpenCL.so.1", "libOpenCL.so.2" };
#endif

    const size_t paths_count = sizeof(paths) / sizeof(*paths);

    for (size_t i = 0; i < paths_count; i++) {
        clew_handle = clew_dlopen(paths[i]);
        if (clew_handle != NULL) break;
    }
    if (clew_handle == NULL) return "could not find OpenCL in system, make sure it is installed";

    clGetPlatformIDs = (clGetPlatformIDs_t)clew_psearch(clew_handle, "clGetPlatformIDs");
    if (!clew_pdefined(clGetPlatformIDs)) return "could not find `clGetPlatformIDs` in handle";
    clGetPlatformInfo = (clGetPlatformInfo_t)clew_psearch(clew_handle, "clGetPlatformInfo");
    if (!clew_pdefined(clGetPlatformInfo)) return "could not find `clGetPlatformInfo` in handle";
    clGetDeviceIDs = (clGetDeviceIDs_t)clew_psearch(clew_handle, "clGetDeviceIDs");
    if (!clew_pdefined(clGetDeviceIDs)) return "could not find `clGetDeviceIDs` in handle";
    clGetDeviceInfo = (clGetDeviceInfo_t)clew_psearch(clew_handle, "clGetDeviceInfo");
    if (!clew_pdefined(clGetDeviceInfo)) return "could not find `clGetDeviceInfo` in handle";
#ifdef CL_VERSION_1_2
    clCreateSubDevices = (clCreateSubDevices_t)clew_psearch(clew_handle, "clCreateSubDevices");
    if (!clew_pdefined(clCreateSubDevices)) return "could not find `clCreateSubDevices` in handle";
    clRetainDevice = (clRetainDevice_t)clew_psearch(clew_handle, "clRetainDevice");
    if (!clew_pdefined(clRetainDevice)) return "could not find `clRetainDevice` in handle";
    clReleaseDevice = (clReleaseDevice_t)clew_psearch(clew_handle, "clReleaseDevice");
    if (!clew_pdefined(clReleaseDevice)) return "could not find `clReleaseDevice` in handle";
#endif
#ifdef CL_VERSION_2_1
    clSetDefaultDeviceCommandQueue = (clSetDefaultDeviceCommandQueue_t)clew_psearch(clew_handle, "clSetDefaultDeviceCommandQueue");
    if (!clew_pdefined(clSetDefaultDeviceCommandQueue)) return "could not find `clSetDefaultDeviceCommandQueue` in handle";
    clGetDeviceAndHostTimer = (clGetDeviceAndHostTimer_t)clew_psearch(clew_handle, "clGetDeviceAndHostTimer");
    if (!clew_pdefined(clGetDeviceAndHostTimer)) return "could not find `clGetDeviceAndHostTimer` in handle";
    clGetHostTimer = (clGetHostTimer_t)clew_psearch(clew_handle, "clGetHostTimer");
    if (!clew_pdefined(clGetHostTimer)) return "could not find `clGetHostTimer` in handle";
#endif
    clCreateContext = (clCreateContext_t)clew_psearch(clew_handle, "clCreateContext");
    if (!clew_pdefined(clCreateContext)) return "could not find `clCreateContext` in handle";
    clCreateContextFromType = (clCreateContextFromType_t)clew_psearch(clew_handle, "clCreateContextFromType");
    if (!clew_pdefined(clCreateContextFromType)) return "could not find `clCreateContextFromType` in handle";
    clRetainContext = (clRetainContext_t)clew_psearch(clew_handle, "clRetainContext");
    if (!clew_pdefined(clRetainContext)) return "could not find `clRetainContext` in handle";
    clReleaseContext = (clReleaseContext_t)clew_psearch(clew_handle, "clReleaseContext");
    if (!clew_pdefined(clReleaseContext)) return "could not find `clReleaseContext` in handle";
    clGetContextInfo = (clGetContextInfo_t)clew_psearch(clew_handle, "clGetContextInfo");
    if (!clew_pdefined(clGetContextInfo)) return "could not find `clGetContextInfo` in handle";
#ifdef CL_VERSION_3_0
    clSetContextDestructorCallback = (clSetContextDestructorCallback_t)clew_psearch(clew_handle, "clSetContextDestructorCallback");
    if (!clew_pdefined(clSetContextDestructorCallback)) return "could not find `clSetContextDestructorCallback` in handle";
#endif
#ifdef CL_VERSION_2_0
    clCreateCommandQueueWithProperties = (clCreateCommandQueueWithProperties_t)clew_psearch(clew_handle, "clCreateCommandQueueWithProperties");
    if (!clew_pdefined(clCreateCommandQueueWithProperties)) return "could not find `clCreateCommandQueueWithProperties` in handle";
#endif
    clRetainCommandQueue = (clRetainCommandQueue_t)clew_psearch(clew_handle, "clRetainCommandQueue");
    if (!clew_pdefined(clRetainCommandQueue)) return "could not find `clRetainCommandQueue` in handle";
    clReleaseCommandQueue = (clReleaseCommandQueue_t)clew_psearch(clew_handle, "clReleaseCommandQueue");
    if (!clew_pdefined(clReleaseCommandQueue)) return "could not find `clReleaseCommandQueue` in handle";
    clGetCommandQueueInfo = (clGetCommandQueueInfo_t)clew_psearch(clew_handle, "clGetCommandQueueInfo");
    if (!clew_pdefined(clGetCommandQueueInfo)) return "could not find `clGetCommandQueueInfo` in handle";
    clCreateBuffer = (clCreateBuffer_t)clew_psearch(clew_handle, "clCreateBuffer");
    if (!clew_pdefined(clCreateBuffer)) return "could not find `clCreateBuffer` in handle";
#ifdef CL_VERSION_1_1
    clCreateSubBuffer = (clCreateSubBuffer_t)clew_psearch(clew_handle, "clCreateSubBuffer");
    if (!clew_pdefined(clCreateSubBuffer)) return "could not find `clCreateSubBuffer` in handle";
#endif
#ifdef CL_VERSION_1_2
    clCreateImage = (clCreateImage_t)clew_psearch(clew_handle, "clCreateImage");
    if (!clew_pdefined(clCreateImage)) return "could not find `clCreateImage` in handle";
#endif
#ifdef CL_VERSION_2_0
    clCreatePipe = (clCreatePipe_t)clew_psearch(clew_handle, "clCreatePipe");
    if (!clew_pdefined(clCreatePipe)) return "could not find `clCreatePipe` in handle";
#endif
#ifdef CL_VERSION_3_0
    clCreateBufferWithProperties = (clCreateBufferWithProperties_t)clew_psearch(clew_handle, "clCreateBufferWithProperties");
    if (!clew_pdefined(clCreateBufferWithProperties)) return "could not find `clCreateBufferWithProperties` in handle";
    clCreateImageWithProperties = (clCreateImageWithProperties_t)clew_psearch(clew_handle, "clCreateImageWithProperties");
    if (!clew_pdefined(clCreateImageWithProperties)) return "could not find `clCreateImageWithProperties` in handle";
#endif
    clRetainMemObject = (clRetainMemObject_t)clew_psearch(clew_handle, "clRetainMemObject");
    if (!clew_pdefined(clRetainMemObject)) return "could not find `clRetainMemObject` in handle";
    clReleaseMemObject = (clReleaseMemObject_t)clew_psearch(clew_handle, "clReleaseMemObject");
    if (!clew_pdefined(clReleaseMemObject)) return "could not find `clReleaseMemObject` in handle";
    clGetSupportedImageFormats = (clGetSupportedImageFormats_t)clew_psearch(clew_handle, "clGetSupportedImageFormats");
    if (!clew_pdefined(clGetSupportedImageFormats)) return "could not find `clGetSupportedImageFormats` in handle";
    clGetMemObjectInfo = (clGetMemObjectInfo_t)clew_psearch(clew_handle, "clGetMemObjectInfo");
    if (!clew_pdefined(clGetMemObjectInfo)) return "could not find `clGetMemObjectInfo` in handle";
    clGetImageInfo = (clGetImageInfo_t)clew_psearch(clew_handle, "clGetImageInfo");
    if (!clew_pdefined(clGetImageInfo)) return "could not find `clGetImageInfo` in handle";
#ifdef CL_VERSION_2_0
    clGetPipeInfo = (clGetPipeInfo_t)clew_psearch(clew_handle, "clGetPipeInfo");
    if (!clew_pdefined(clGetPipeInfo)) return "could not find `clGetPipeInfo` in handle";
#endif
#ifdef CL_VERSION_1_1
    clSetMemObjectDestructorCallback = (clSetMemObjectDestructorCallback_t)clew_psearch(clew_handle, "clSetMemObjectDestructorCallback");
    if (!clew_pdefined(clSetMemObjectDestructorCallback)) return "could not find `clSetMemObjectDestructorCallback` in handle";
#endif
#ifdef CL_VERSION_2_0
    clSVMAlloc = (clSVMAlloc_t)clew_psearch(clew_handle, "clSVMAlloc");
    if (!clew_pdefined(clSVMAlloc)) return "could not find `clSVMAlloc` in handle";
    clSVMFree = (clSVMFree_t)clew_psearch(clew_handle, "clSVMFree");
    if (!clew_pdefined(clSVMFree)) return "could not find `clSVMFree` in handle";
#endif
#ifdef CL_VERSION_2_0
    clCreateSamplerWithProperties = (clCreateSamplerWithProperties_t)clew_psearch(clew_handle, "clCreateSamplerWithProperties");
    if (!clew_pdefined(clCreateSamplerWithProperties)) return "could not find `clCreateSamplerWithProperties` in handle";
#endif
    clRetainSampler = (clRetainSampler_t)clew_psearch(clew_handle, "clRetainSampler");
    if (!clew_pdefined(clRetainSampler)) return "could not find `clRetainSampler` in handle";
    clReleaseSampler = (clReleaseSampler_t)clew_psearch(clew_handle, "clReleaseSampler");
    if (!clew_pdefined(clReleaseSampler)) return "could not find `clReleaseSampler` in handle";
    clGetSamplerInfo = (clGetSamplerInfo_t)clew_psearch(clew_handle, "clGetSamplerInfo");
    if (!clew_pdefined(clGetSamplerInfo)) return "could not find `clGetSamplerInfo` in handle";
    clCreateProgramWithSource = (clCreateProgramWithSource_t)clew_psearch(clew_handle, "clCreateProgramWithSource");
    if (!clew_pdefined(clCreateProgramWithSource)) return "could not find `clCreateProgramWithSource` in handle";
    clCreateProgramWithBinary = (clCreateProgramWithBinary_t)clew_psearch(clew_handle, "clCreateProgramWithBinary");
    if (!clew_pdefined(clCreateProgramWithBinary)) return "could not find `clCreateProgramWithBinary` in handle";
#ifdef CL_VERSION_1_2
    clCreateProgramWithBuiltInKernels = (clCreateProgramWithBuiltInKernels_t)clew_psearch(clew_handle, "clCreateProgramWithBuiltInKernels");
    if (!clew_pdefined(clCreateProgramWithBuiltInKernels)) return "could not find `clCreateProgramWithBuiltInKernels` in handle";
#endif
#ifdef CL_VERSION_2_1
    clCreateProgramWithIL = (clCreateProgramWithIL_t)clew_psearch(clew_handle, "clCreateProgramWithIL");
    if (!clew_pdefined(clCreateProgramWithIL)) return "could not find `clCreateProgramWithIL` in handle";
#endif
    clRetainProgram = (clRetainProgram_t)clew_psearch(clew_handle, "clRetainProgram");
    if (!clew_pdefined(clRetainProgram)) return "could not find `clRetainProgram` in handle";
    clReleaseProgram = (clReleaseProgram_t)clew_psearch(clew_handle, "clReleaseProgram");
    if (!clew_pdefined(clReleaseProgram)) return "could not find `clReleaseProgram` in handle";
    clBuildProgram = (clBuildProgram_t)clew_psearch(clew_handle, "clBuildProgram");
    if (!clew_pdefined(clBuildProgram)) return "could not find `clBuildProgram` in handle";
#ifdef CL_VERSION_1_2
    clCompileProgram = (clCompileProgram_t)clew_psearch(clew_handle, "clCompileProgram");
    if (!clew_pdefined(clCompileProgram)) return "could not find `clCompileProgram` in handle";
    clLinkProgram = (clLinkProgram_t)clew_psearch(clew_handle, "clLinkProgram");
    if (!clew_pdefined(clLinkProgram)) return "could not find `clLinkProgram` in handle";
#endif
#ifdef CL_VERSION_2_2
    clSetProgramReleaseCallback = (clSetProgramReleaseCallback_t)clew_psearch(clew_handle, "clSetProgramReleaseCallback");
    if (!clew_pdefined(clSetProgramReleaseCallback)) return "could not find `clSetProgramReleaseCallback` in handle";
    clSetProgramSpecializationConstant = (clSetProgramSpecializationConstant_t)clew_psearch(clew_handle, "clSetProgramSpecializationConstant");
    if (!clew_pdefined(clSetProgramSpecializationConstant)) return "could not find `clSetProgramSpecializationConstant` in handle";
#endif
#ifdef CL_VERSION_1_2
    clUnloadPlatformCompiler = (clUnloadPlatformCompiler_t)clew_psearch(clew_handle, "clUnloadPlatformCompiler");
    if (!clew_pdefined(clUnloadPlatformCompiler)) return "could not find `clUnloadPlatformCompiler` in handle";
#endif
    clGetProgramInfo = (clGetProgramInfo_t)clew_psearch(clew_handle, "clGetProgramInfo");
    if (!clew_pdefined(clGetProgramInfo)) return "could not find `clGetProgramInfo` in handle";
    clGetProgramBuildInfo = (clGetProgramBuildInfo_t)clew_psearch(clew_handle, "clGetProgramBuildInfo");
    if (!clew_pdefined(clGetProgramBuildInfo)) return "could not find `clGetProgramBuildInfo` in handle";
    clCreateKernel = (clCreateKernel_t)clew_psearch(clew_handle, "clCreateKernel");
    if (!clew_pdefined(clCreateKernel)) return "could not find `clCreateKernel` in handle";
    clCreateKernelsInProgram = (clCreateKernelsInProgram_t)clew_psearch(clew_handle, "clCreateKernelsInProgram");
    if (!clew_pdefined(clCreateKernelsInProgram)) return "could not find `clCreateKernelsInProgram` in handle";
#ifdef CL_VERSION_2_1
    clCloneKernel = (clCloneKernel_t)clew_psearch(clew_handle, "clCloneKernel");
    if (!clew_pdefined(clCloneKernel)) return "could not find `clCloneKernel` in handle";
#endif
    clRetainKernel = (clRetainKernel_t)clew_psearch(clew_handle, "clRetainKernel");
    if (!clew_pdefined(clRetainKernel)) return "could not find `clRetainKernel` in handle";
    clReleaseKernel = (clReleaseKernel_t)clew_psearch(clew_handle, "clReleaseKernel");
    if (!clew_pdefined(clReleaseKernel)) return "could not find `clReleaseKernel` in handle";
    clSetKernelArg = (clSetKernelArg_t)clew_psearch(clew_handle, "clSetKernelArg");
    if (!clew_pdefined(clSetKernelArg)) return "could not find `clSetKernelArg` in handle";
#ifdef CL_VERSION_2_0
    clSetKernelArgSVMPointer = (clSetKernelArgSVMPointer_t)clew_psearch(clew_handle, "clSetKernelArgSVMPointer");
    if (!clew_pdefined(clSetKernelArgSVMPointer)) return "could not find `clSetKernelArgSVMPointer` in handle";
    clSetKernelExecInfo = (clSetKernelExecInfo_t)clew_psearch(clew_handle, "clSetKernelExecInfo");
    if (!clew_pdefined(clSetKernelExecInfo)) return "could not find `clSetKernelExecInfo` in handle";
#endif
    clGetKernelInfo = (clGetKernelInfo_t)clew_psearch(clew_handle, "clGetKernelInfo");
    if (!clew_pdefined(clGetKernelInfo)) return "could not find `clGetKernelInfo` in handle";
#ifdef CL_VERSION_1_2
    clGetKernelArgInfo = (clGetKernelArgInfo_t)clew_psearch(clew_handle, "clGetKernelArgInfo");
    if (!clew_pdefined(clGetKernelArgInfo)) return "could not find `clGetKernelArgInfo` in handle";
#endif
    clGetKernelWorkGroupInfo = (clGetKernelWorkGroupInfo_t)clew_psearch(clew_handle, "clGetKernelWorkGroupInfo");
    if (!clew_pdefined(clGetKernelWorkGroupInfo)) return "could not find `clGetKernelWorkGroupInfo` in handle";
#ifdef CL_VERSION_2_1
    clGetKernelSubGroupInfo = (clGetKernelSubGroupInfo_t)clew_psearch(clew_handle, "clGetKernelSubGroupInfo");
    if (!clew_pdefined(clGetKernelSubGroupInfo)) return "could not find `clGetKernelSubGroupInfo` in handle";
#endif
    clWaitForEvents = (clWaitForEvents_t)clew_psearch(clew_handle, "clWaitForEvents");
    if (!clew_pdefined(clWaitForEvents)) return "could not find `clWaitForEvents` in handle";
    clGetEventInfo = (clGetEventInfo_t)clew_psearch(clew_handle, "clGetEventInfo");
    if (!clew_pdefined(clGetEventInfo)) return "could not find `clGetEventInfo` in handle";
#ifdef CL_VERSION_1_1
    clCreateUserEvent = (clCreateUserEvent_t)clew_psearch(clew_handle, "clCreateUserEvent");
    if (!clew_pdefined(clCreateUserEvent)) return "could not find `clCreateUserEvent` in handle";
#endif
    clRetainEvent = (clRetainEvent_t)clew_psearch(clew_handle, "clRetainEvent");
    if (!clew_pdefined(clRetainEvent)) return "could not find `clRetainEvent` in handle";
    clReleaseEvent = (clReleaseEvent_t)clew_psearch(clew_handle, "clReleaseEvent");
    if (!clew_pdefined(clReleaseEvent)) return "could not find `clReleaseEvent` in handle";
#ifdef CL_VERSION_1_1
    clSetUserEventStatus = (clSetUserEventStatus_t)clew_psearch(clew_handle, "clSetUserEventStatus");
    if (!clew_pdefined(clSetUserEventStatus)) return "could not find `clSetUserEventStatus` in handle";
    clSetEventCallback = (clSetEventCallback_t)clew_psearch(clew_handle, "clSetEventCallback");
    if (!clew_pdefined(clSetEventCallback)) return "could not find `clSetEventCallback` in handle";
#endif
    clGetEventProfilingInfo = (clGetEventProfilingInfo_t)clew_psearch(clew_handle, "clGetEventProfilingInfo");
    if (!clew_pdefined(clGetEventProfilingInfo)) return "could not find `clGetEventProfilingInfo` in handle";
    clFlush = (clFlush_t)clew_psearch(clew_handle, "clFlush");
    if (!clew_pdefined(clFlush)) return "could not find `clFlush` in handle";
    clFinish = (clFinish_t)clew_psearch(clew_handle, "clFinish");
    if (!clew_pdefined(clFinish)) return "could not find `clFinish` in handle";
    clEnqueueReadBuffer = (clEnqueueReadBuffer_t)clew_psearch(clew_handle, "clEnqueueReadBuffer");
    if (!clew_pdefined(clEnqueueReadBuffer)) return "could not find `clEnqueueReadBuffer` in handle";
#ifdef CL_VERSION_1_1
    clEnqueueReadBufferRect = (clEnqueueReadBufferRect_t)clew_psearch(clew_handle, "clEnqueueReadBufferRect");
    if (!clew_pdefined(clEnqueueReadBufferRect)) return "could not find `clEnqueueReadBufferRect` in handle";
#endif
    clEnqueueWriteBuffer = (clEnqueueWriteBuffer_t)clew_psearch(clew_handle, "clEnqueueWriteBuffer");
    if (!clew_pdefined(clEnqueueWriteBuffer)) return "could not find `clEnqueueWriteBuffer` in handle";
#ifdef CL_VERSION_1_1
    clEnqueueWriteBufferRect = (clEnqueueWriteBufferRect_t)clew_psearch(clew_handle, "clEnqueueWriteBufferRect");
    if (!clew_pdefined(clEnqueueWriteBufferRect)) return "could not find `clEnqueueWriteBufferRect` in handle";
#endif
#ifdef CL_VERSION_1_2
    clEnqueueFillBuffer = (clEnqueueFillBuffer_t)clew_psearch(clew_handle, "clEnqueueFillBuffer");
    if (!clew_pdefined(clEnqueueFillBuffer)) return "could not find `clEnqueueFillBuffer` in handle";
#endif
    clEnqueueCopyBuffer = (clEnqueueCopyBuffer_t)clew_psearch(clew_handle, "clEnqueueCopyBuffer");
    if (!clew_pdefined(clEnqueueCopyBuffer)) return "could not find `clEnqueueCopyBuffer` in handle";
#ifdef CL_VERSION_1_1
    clEnqueueCopyBufferRect = (clEnqueueCopyBufferRect_t)clew_psearch(clew_handle, "clEnqueueCopyBufferRect");
    if (!clew_pdefined(clEnqueueCopyBufferRect)) return "could not find `clEnqueueCopyBufferRect` in handle";
#endif
    clEnqueueReadImage = (clEnqueueReadImage_t)clew_psearch(clew_handle, "clEnqueueReadImage");
    if (!clew_pdefined(clEnqueueReadImage)) return "could not find `clEnqueueReadImage` in handle";
    clEnqueueWriteImage = (clEnqueueWriteImage_t)clew_psearch(clew_handle, "clEnqueueWriteImage");
    if (!clew_pdefined(clEnqueueWriteImage)) return "could not find `clEnqueueWriteImage` in handle";
#ifdef CL_VERSION_1_2
    clEnqueueFillImage = (clEnqueueFillImage_t)clew_psearch(clew_handle, "clEnqueueFillImage");
    if (!clew_pdefined(clEnqueueFillImage)) return "could not find `clEnqueueFillImage` in handle";
#endif
    clEnqueueCopyImage = (clEnqueueCopyImage_t)clew_psearch(clew_handle, "clEnqueueCopyImage");
    if (!clew_pdefined(clEnqueueCopyImage)) return "could not find `clEnqueueCopyImage` in handle";
    clEnqueueCopyImageToBuffer = (clEnqueueCopyImageToBuffer_t)clew_psearch(clew_handle, "clEnqueueCopyImageToBuffer");
    if (!clew_pdefined(clEnqueueCopyImageToBuffer)) return "could not find `clEnqueueCopyImageToBuffer` in handle";
    clEnqueueCopyBufferToImage = (clEnqueueCopyBufferToImage_t)clew_psearch(clew_handle, "clEnqueueCopyBufferToImage");
    if (!clew_pdefined(clEnqueueCopyBufferToImage)) return "could not find `clEnqueueCopyBufferToImage` in handle";
    clEnqueueMapBuffer = (clEnqueueMapBuffer_t)clew_psearch(clew_handle, "clEnqueueMapBuffer");
    if (!clew_pdefined(clEnqueueMapBuffer)) return "could not find `clEnqueueMapBuffer` in handle";
    clEnqueueMapImage = (clEnqueueMapImage_t)clew_psearch(clew_handle, "clEnqueueMapImage");
    if (!clew_pdefined(clEnqueueMapImage)) return "could not find `clEnqueueMapImage` in handle";
    clEnqueueUnmapMemObject = (clEnqueueUnmapMemObject_t)clew_psearch(clew_handle, "clEnqueueUnmapMemObject");
    if (!clew_pdefined(clEnqueueUnmapMemObject)) return "could not find `clEnqueueUnmapMemObject` in handle";
#ifdef CL_VERSION_1_2
    clEnqueueMigrateMemObjects = (clEnqueueMigrateMemObjects_t)clew_psearch(clew_handle, "clEnqueueMigrateMemObjects");
    if (!clew_pdefined(clEnqueueMigrateMemObjects)) return "could not find `clEnqueueMigrateMemObjects` in handle";
#endif
    clEnqueueNDRangeKernel = (clEnqueueNDRangeKernel_t)clew_psearch(clew_handle, "clEnqueueNDRangeKernel");
    if (!clew_pdefined(clEnqueueNDRangeKernel)) return "could not find `clEnqueueNDRangeKernel` in handle";
    clEnqueueNativeKernel = (clEnqueueNativeKernel_t)clew_psearch(clew_handle, "clEnqueueNativeKernel");
    if (!clew_pdefined(clEnqueueNativeKernel)) return "could not find `clEnqueueNativeKernel` in handle";
#ifdef CL_VERSION_1_2
    clEnqueueMarkerWithWaitList = (clEnqueueMarkerWithWaitList_t)clew_psearch(clew_handle, "clEnqueueMarkerWithWaitList");
    if (!clew_pdefined(clEnqueueMarkerWithWaitList)) return "could not find `clEnqueueMarkerWithWaitList` in handle";
    clEnqueueBarrierWithWaitList = (clEnqueueBarrierWithWaitList_t)clew_psearch(clew_handle, "clEnqueueBarrierWithWaitList");
    if (!clew_pdefined(clEnqueueBarrierWithWaitList)) return "could not find `clEnqueueBarrierWithWaitList` in handle";
#endif
#ifdef CL_VERSION_2_0
    clEnqueueSVMFree = (clEnqueueSVMFree_t)clew_psearch(clew_handle, "clEnqueueSVMFree");
    if (!clew_pdefined(clEnqueueSVMFree)) return "could not find `clEnqueueSVMFree` in handle";
    clEnqueueSVMMemcpy = (clEnqueueSVMMemcpy_t)clew_psearch(clew_handle, "clEnqueueSVMMemcpy");
    if (!clew_pdefined(clEnqueueSVMMemcpy)) return "could not find `clEnqueueSVMMemcpy` in handle";
    clEnqueueSVMMemFill = (clEnqueueSVMMemFill_t)clew_psearch(clew_handle, "clEnqueueSVMMemFill");
    if (!clew_pdefined(clEnqueueSVMMemFill)) return "could not find `clEnqueueSVMMemFill` in handle";
    clEnqueueSVMMap = (clEnqueueSVMMap_t)clew_psearch(clew_handle, "clEnqueueSVMMap");
    if (!clew_pdefined(clEnqueueSVMMap)) return "could not find `clEnqueueSVMMap` in handle";
    clEnqueueSVMUnmap = (clEnqueueSVMUnmap_t)clew_psearch(clew_handle, "clEnqueueSVMUnmap");
    if (!clew_pdefined(clEnqueueSVMUnmap)) return "could not find `clEnqueueSVMUnmap` in handle";
#endif
#ifdef CL_VERSION_2_1
    clEnqueueSVMMigrateMem = (clEnqueueSVMMigrateMem_t)clew_psearch(clew_handle, "clEnqueueSVMMigrateMem");
    if (!clew_pdefined(clEnqueueSVMMigrateMem)) return "could not find `clEnqueueSVMMigrateMem` in handle";
#endif
#ifdef CL_VERSION_1_2
    clGetExtensionFunctionAddressForPlatform = (clGetExtensionFunctionAddressForPlatform_t)clew_psearch(clew_handle, "clGetExtensionFunctionAddressForPlatform");
    if (!clew_pdefined(clGetExtensionFunctionAddressForPlatform)) return "could not find `clGetExtensionFunctionAddressForPlatform` in ";
#endif
#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
    clSetCommandQueueProperty = (clSetCommandQueueProperty_t)clew_psearch(clew_handle, "clSetCommandQueueProperty");
    if (!clew_pdefined(clSetCommandQueueProperty)) return "could not find `clSetCommandQueueProperty` in handle";
#endif
    clCreateImage2D = (clCreateImage2D_t)clew_psearch(clew_handle, "clCreateImage2D");
    if (!clew_pdefined(clCreateImage2D)) return "could not find `clCreateImage2D` in handle";
    clCreateImage3D = (clCreateImage3D_t)clew_psearch(clew_handle, "clCreateImage3D");
    if (!clew_pdefined(clCreateImage3D)) return "could not find `clCreateImage3D` in handle";
    clEnqueueMarker = (clEnqueueMarker_t)clew_psearch(clew_handle, "clEnqueueMarker");
    if (!clew_pdefined(clEnqueueMarker)) return "could not find `clEnqueueMarker` in handle";
    clEnqueueWaitForEvents = (clEnqueueWaitForEvents_t)clew_psearch(clew_handle, "clEnqueueWaitForEvents");
    if (!clew_pdefined(clEnqueueWaitForEvents)) return "could not find `clEnqueueWaitForEvents` in handle";
    clEnqueueBarrier = (clEnqueueBarrier_t)clew_psearch(clew_handle, "clEnqueueBarrier");
    if (!clew_pdefined(clEnqueueBarrier)) return "could not find `clEnqueueBarrier` in handle";
    clUnloadCompiler = (clUnloadCompiler_t)clew_psearch(clew_handle, "clUnloadCompiler");
    if (!clew_pdefined(clUnloadCompiler)) return "could not find `clUnloadCompiler` in handle";
    clGetExtensionFunctionAddress = (clGetExtensionFunctionAddress_t)clew_psearch(clew_handle, "clGetExtensionFunctionAddress");
    if (!clew_pdefined(clGetExtensionFunctionAddress)) return "could not find `clGetExtensionFunctionAddress` in handle";
    clCreateCommandQueue = (clCreateCommandQueue_t)clew_psearch(clew_handle, "clCreateCommandQueue");
    if (!clew_pdefined(clCreateCommandQueue)) return "could not find `clCreateCommandQueue` in handle";
    clCreateSampler = (clCreateSampler_t)clew_psearch(clew_handle, "clCreateSampler");
    if (!clew_pdefined(clCreateSampler)) return "could not find `clCreateSampler` in handle";
    clEnqueueTask = (clEnqueueTask_t)clew_psearch(clew_handle, "clEnqueueTask");
    if (!clew_pdefined(clEnqueueTask)) return "could not find `clEnqueueTask` in handle";

    return NULL;
}

void clew_quit() {
    if (clew_handle != NULL) clew_dlclose(clew_handle);
    clew_handle = NULL;
}

#endif /* clew_IMPLEMENTATION */
