/*
  AngelScript test framework
*/

#include "../stdheaders.h"
#include <sys/stat.h>
#include <unistd.h>

#include "../hal/platform.h"
#include "../misc.h"

class PosixPlatform : public HALPlatform
{
public:
   PosixPlatform() : HALPlatform()
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

      exit(EXIT_SUCCESS);
   }

   virtual void fatalError(const char *msg, ...) const
   {
      va_list args;
      va_start(args, msg);
      vprintf(msg, args);
      va_end(args);

      putc('\n', stdout);

      exit(EXIT_FAILURE);
   }

   // Directory utils
   virtual bool createDirectory(const char *name) const
   {
      return !mkdir(name, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
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
         accessMode = R_OK;
         break;
      case FILE_WRITE:
         accessMode = W_OK;
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
static PosixPlatform gsPosixPlatform;

// EOF

