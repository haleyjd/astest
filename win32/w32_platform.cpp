/*
  AngelScript test framework
*/

#include "../stdheaders.h"
#include <direct.h>
#include <io.h>
#include <Windows.h>

#include "../hal/platform.h"
#include "../misc.h"

class Win32Platform : public HALPlatform
{
public:
   Win32Platform() : HALPlatform()
   {
      gPlatform = this;
   }

   virtual void debugMsg(const char *msg, ...) const
   {
#ifdef _DEBUG
      va_list args;
      va_start(args, msg);
      vprintf(msg, args);
      va_end(args);
#endif
   }
   
   virtual void exitWithMsg(const char *msg, ...) const
   {
      va_list args;
      va_start(args, msg);
      vprintf(msg, args);
      va_end(args);

      putc('\n', stdout);

      exit(0);
   }

   virtual void fatalError(const char *msg, ...) const
   {
      va_list args;
      va_start(args, msg);
      vprintf(msg, args);
      va_end(args);

      putc('\n', stdout);

      exit(-1);
   }

   // Directory utils
   virtual bool createDirectory(const char *name) const
   {
      return !mkdir(name);
   }

   virtual const char *getWriteDirectory() const
   {
      return ".";
   }
   
   // File utils
   virtual bool checkFileAccess(const char *name, filemode_e mode) const
   {
      int accessMode;

      switch(mode)
      {
      case FILE_READ:
         accessMode = 4;
         break;
      case FILE_WRITE:
         accessMode = 2;
         break;
      case FILE_EXISTS:
      default:
         accessMode = 0;
         break;
      }

      return !access(name, accessMode);
   }
};

// Global singleton
static Win32Platform gsWin32Platform;

// EOF

