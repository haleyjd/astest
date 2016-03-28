/*
  AngelScript test framework

  Purpose: HAL platform class
  Author:  James Haley
*/

#ifndef HAL_PLATFORM_H__
#define HAL_PLATFORM_H__

//
// Abstract class which forms the base of platform-specific interface
// implementations.
//
class HALPlatform
{
public:
   enum filemode_e
   {
      FILE_READ,
      FILE_WRITE,
      FILE_EXISTS
   };

   // Error handling and debugging
   virtual void debugMsg(const char *msg, ...)    const = 0;
   virtual void exitWithMsg(const char *msg, ...) const = 0;
   virtual void fatalError(const char *msg, ...)  const = 0;

   // Directory utils
   virtual bool createDirectory(const char *name) const = 0;
   virtual const char *getWriteDirectory()        const = 0;
   
   // File utils
   virtual bool checkFileAccess(const char *name, filemode_e mode) const = 0;
};

extern const HALPlatform *gPlatform;

#endif

// EOF

