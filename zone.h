/*
  AngelScript test framework

  Purpose: Memory allocation
  Author:  James Haley
*/

void *Z_Malloc(size_t size);
void *Z_Calloc(size_t count, size_t size);
void *Z_Realloc(void *ptr, size_t size);
char *Z_Strdup(const char *str);
void  Z_Free(void *ptr);

// EOF

