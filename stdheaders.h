/*
  AngelScript test framework

  Purpose: Standard library includes
  Author:  James Haley
*/

#ifndef STDHEADERS_H__
#define STDHEADERS_H__

#if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS
#endif

#if defined(_MSC_VER) && !defined(_CRT_NONSTDC_NO_DEPRECATE)
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

// C++ standard library
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <memory>

#include <errno.h>
#include <stddef.h>
#include <stdint.h>

// Memory handling
#include "zone.h"

// Global macros
#define ecalloc(type, count, size) static_cast<type *>(Z_Calloc(count, size))
#define emalloc(type, size)        static_cast<type *>(Z_Malloc(size))
#define erealloc(type, ptr, size)  static_cast<type *>(Z_Realloc(ptr, size))
#define estructalloc(type, num)    static_cast<type *>(Z_Calloc(num, sizeof(type)))
#define estrdup(str)               Z_Strdup(str)
#define efree(ptr)                 Z_Free(ptr)

// String case comparison
#if defined(_MSC_VER) && !defined(strcasecmp)
#define strcasecmp _stricmp
#endif

#if defined(_MSC_VER) && !defined(strncasecmp)
#define strncasecmp _strnicmp
#endif

// Get the size of a static array
#define earrlen(a) (sizeof(a) / sizeof(*a))

// Define a struct var and ensure it is fully initialized
#define edefstructvar(type, name)  \
   type name;                      \
   std::memset(&name, 0, sizeof(name))

// Empty-or-null testing
#define estrempty(str) ((str) == nullptr || *(str) == '\0')

// Types
typedef uint8_t byte;
typedef int32_t fixed_t;

// Fixed-point defines
#define FRACBITS 16
#define FRACUNIT (1<<FRACBITS)

#define AS_BYTEPTR(x)  reinterpret_cast<byte *>((x))
#define AS_SHORTPTR(x) reinterpret_cast<int16_t *>((x))
#define AS_UINTPTR(x)  reinterpret_cast<uint32_t *>((x))

#endif

// EOF

