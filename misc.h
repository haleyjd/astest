/*
  AngelScript test framework
  
  Purpose: Miscellaneous utilities
  Author:  James Haley
*/

#ifndef MISC_H__
#define MISC_H__

#include "stdheaders.h"

//
// Portable snprintf functions
//

int pvsnprintf(char *buf, size_t buf_len, const char *s, va_list args);
int psnprintf(char *buf, size_t buf_len, const char *s, ...);

//
// File IO Utils
//

bool    M_WriteFile(const char *filename, const void *source, size_t length);
long    M_FileLength(FILE *f);
size_t  M_ReadFile(const char *name, byte **buffer);
char   *M_LoadStringFromFile(const char *filename);

//
// C library polyfills
//

char *M_Strupr(char *string);
char *M_Strlwr(char *string);
char *M_Itoa(int value, char *string, int radix);

//
// Filename and Path Utils
//

void M_NormalizeSlashes(char *str);

#endif

// EOF

