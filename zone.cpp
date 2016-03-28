/*
  AngelScript test framework

  Purpose: Memory allocation
  Author:  James Haley
*/

#include "stdheaders.h"
#include "hal/platform.h"

void *Z_Malloc(size_t size)
{
   void *ret;

   if(!(ret = std::malloc(size)))
      gPlatform->fatalError("Z_Malloc: failed on allocation of %lu bytes", size);

   return ret;
}

void *Z_Calloc(size_t count, size_t size)
{
   void *ret;

   if(!(ret = std::calloc(count, size)))
      gPlatform->fatalError("Z_Calloc: failed on allocation of %lu bytes", count*size);

   return ret;
}

void *Z_Realloc(void *ptr, size_t size)
{
   void *ret;

   if(!(ret = std::realloc(ptr, size)))
      gPlatform->fatalError("Z_Realloc: failed on allocation of %lu bytes", size);

   return ret;
}

char *Z_Strdup(const char *str)
{
   char *ret;

   if(!(ret = strdup(str)))
      gPlatform->fatalError("Z_Strdup: could not duplicate string");

   return ret;
}

void Z_Free(void *ptr)
{
   if(!ptr)
      gPlatform->fatalError("Z_Free: attempt to free NULL pointer");

   std::free(ptr);
}

// EOF

