#ifndef IPC_DEFINES_H
#define IPC_DEFINES_H

//////////////////////////////////////////////////////////////////////
// First definition: choose OS
//////////////////////////////////////////////////////////////////////
#ifdef WIN32
  #ifndef IPC_WIN32
    #define IPC_WIN32
  #endif // IPC_WIN32
#endif // WIN32

#ifdef UNIX
  #ifndef IPC_UNIX
    #define IPC_UNIX
  #endif // IPC_UNIX
#endif // UNIX

#ifdef LINUX
  #ifndef IPC_LINUX
    #define IPC_LINUX
  #endif // IPC_LINUX
  #ifndef IPC_UNIX
    #define IPC_UNIX
  #endif // IPC_UNIX
#endif // LINUX

//////////////////////////////////////////////////////////////////////////
//definition
//////////////////////////////////////////////////////////////////////////
#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef MAX
#define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b)            (((a) < (b)) ? (a) : (b))
#endif

typedef long IPCResult;

//////////////////////////////////////////////////////////////////////
// OS API definition
//////////////////////////////////////////////////////////////////////
#ifdef IPC_WIN32
//  #ifndef NOMINMAX
//    #define NOMINMAX
//  #endif // NOMINMAX

  // supports Windows NT 4.0 and later, not support Windows 95.
  // mainly for using winsock2 functions
  #ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0400
  #endif // _WIN32_WINNT

  #if defined (_MSC_VER) && (_MSC_VER <= 1200)
    #include <windows.h>
  #endif
  #include <winsock2.h>

  //// The ordering of the fields in this struct is important. 
  //// It has to match those in WSABUF.
  //struct iovec
  //{
  //  u_long iov_len; // byte count to read/write
  //  char *iov_base; // data to be read/written
  //};

#endif // IPC_WIN32

#ifdef IPC_WIN32
  typedef HANDLE IPC_HANDLE;
  typedef SOCKET IPC_SOCKET;
  #define IPC_INVALID_HANDLE INVALID_HANDLE_VALUE
  #define IPC_SD_RECEIVE SD_RECEIVE
  #define IPC_SD_SEND SD_SEND
  #define IPC_SD_BOTH SD_BOTH

  typedef unsigned char uint8_t;
  typedef signed char int8_t;
  typedef unsigned short uint16_t;
  typedef short int16_t;
  typedef unsigned int uint32_t;
  typedef int int32_t;
  typedef __int64 int64_t;
  typedef unsigned __int64 uint64_t;
	typedef const BYTE* LPCBYTE ;

#else // !IPC_WIN32
  typedef int IPC_HANDLE;
  typedef IPC_HANDLE IPC_SOCKET;
  #define IPC_INVALID_HANDLE -1
  #define IPC_SD_RECEIVE 0
  #define IPC_SD_SEND 1
  #define IPC_SD_BOTH 2
#endif // IPC_WIN32


#ifdef IPC_UNIX 
  typedef long long           LONGLONG;
  typedef unsigned long       DWORD;
  typedef long                LONG;
  typedef int                 BOOL;
  typedef unsigned char       BYTE;
  typedef unsigned short        WORD;
  typedef float                 FLOAT;
  typedef int                   INT;
  typedef unsigned int          UINT;
  typedef FLOAT                *PFLOAT;
  typedef BOOL                 *LPBOOL;
  typedef int                  *LPINT;
  typedef WORD                 *LPWORD;
  typedef long                 *LPLONG;
  typedef DWORD                *LPDWORD;
  typedef unsigned int         *LPUINT;
  typedef void                 *LPVOID;
  typedef const void           *LPCVOID;
  typedef char                  CHAR;
  typedef char                  TCHAR;
  typedef unsigned short        WCHAR;
  typedef const char           *LPCSTR;
  typedef char                 *LPSTR;
  typedef const unsigned short *LPCWSTR;
  typedef unsigned short       *LPWSTR;
  typedef BYTE                 *LPBYTE;
  typedef const BYTE           *LPCBYTE;
  typedef double											DOUBLE;

  #ifndef FALSE
    #define FALSE 0
  #endif // FALSE
  #ifndef TRUE
    #define TRUE 1
  #endif // TRUE
#endif // !IPC_UNIX

#ifdef _MSC_VER
    typedef double											DOUBLE;
  #ifndef _MT
    #error Error: please use multithread version of C runtime library.
  #endif // _MT

  #pragma warning(disable: 4786) // identifier was truncated to '255' characters in the browser information(mainly brought by stl)
  #pragma warning(disable: 4355) // disable 'this' used in base member initializer list
  #pragma warning(disable: 4275) // deriving exported class from non-exported
  #pragma warning(disable: 4251) // using non-exported as public in exported
#endif // _MSC_VER

#ifdef IPC_WIN32
  #if defined (_LIB) || (IPC_OS_BUILD_LIB) 
    #define IPC_OS_EXPORT
  #else 
    #if defined (_USRDLL) || (IPC_OS_BUILD_DLL)
      #define IPC_OS_EXPORT __declspec(dllexport)
    #else 
      #define IPC_OS_EXPORT __declspec(dllimport)
    #endif // _USRDLL || IPC_OS_BUILD_DLL
  #endif // _LIB || IPC_OS_BUILD_LIB
#else
  #define IPC_OS_EXPORT 
#endif // !IPC_WIN32

#if defined (IPC_WIN32)
  #define IPC_OS_SEPARATE '\\'
#elif defined (IPC_UNIX) || defined(IPC_MACOS)
  #define IPC_OS_SEPARATE '/'
#endif

#define IPC_BIT_ENABLED(dword, bit) (((dword) & (bit)) != 0)
#define IPC_BIT_DISABLED(dword, bit) (((dword) & (bit)) == 0)
#define IPC_BIT_CMP_MASK(dword, bit, mask) (((dword) & (bit)) == mask)
#define IPC_SET_BITS(dword, bits) (dword |= (bits))
#define IPC_CLR_BITS(dword, bits) (dword &= ~(bits))


//////////////////////////////////////////////////////////////////////
// C definition
//////////////////////////////////////////////////////////////////////

#ifdef IPC_WIN32
  #include <string.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <limits.h>
  #include <stddef.h>
  #include <stdarg.h>
  #include <signal.h>
  #include <errno.h>
  #include <wchar.h>

  #include <crtdbg.h>
  #include <process.h>
  #define getpid _getpid
  #define snprintf _snprintf
  #define strcaseIPCp _striIPCp
  #define strncaseIPCp _strniIPCp
  #define vsnprintf _vsnprintf
#endif // IPC_WIN32

#ifdef IPC_UNIX
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <errno.h>
  #include <limits.h>
  #include <stdarg.h>
  #include <time.h>
  #include <signal.h>
  #include <sys/stat.h>
  #include <sys/fcntl.h>
  #include <pthread.h>
  #include <fcntl.h>
  #include <sys/types.h>
  #include <sys/ioctl.h>
  #include <sys/socket.h>
  #include <sys/time.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <netdb.h>
  #include <ctype.h>

  #define EWOULDBLOCK EAGAIN
 
  #include <assert.h>

  #include <netinet/tcp.h>
  #include <semaphore.h>
#endif // IPC_UNIX


#ifdef IPC_WIN32
#define IPC_IOV_MAX 64
#else
// This is defined by XOPEN to be a minimum of 16.  POSIX.1g
// also defines this value.  platform-specific config.h can
// override this if need be.
#if !defined (IOV_MAX)
#define IOV_MAX 16
#endif // !IOV_MAX
#define IPC_IOV_MAX IOV_MAX
#endif // IPC_WIN32

#ifdef IPC_WIN32
	typedef DWORD IPC_THREAD_ID;
	typedef HANDLE IPC_THREAD_HANDLE;
	typedef HANDLE IPC_SEMAPHORE_T;
	typedef CRITICAL_SECTION IPC_THREAD_MUTEX_T;
#else // !IPC_WIN32
	typedef pthread_t IPC_THREAD_ID;
	typedef IPC_THREAD_ID IPC_THREAD_HANDLE;
	typedef sem_t IPC_SEMAPHORE_T;
	typedef pthread_mutex_t IPC_THREAD_MUTEX_T;
#endif // IPC_WIN32

 
//////////////////////////////////////////////////////////////////////
// Assert
//////////////////////////////////////////////////////////////////////

#ifdef IPC_WIN32
  #include <crtdbg.h>
  #ifdef _DEBUG
    #define IPC_DEBUG
  #endif // _DEBUG

  #if defined (IPC_DEBUG)
    #define IPC_ASSERTE _ASSERTE
  #endif // IPC_DEBUG
#endif // IPC_WIN32

#ifdef IPC_UNIX
  #include <assert.h>
  #if defined (IPC_DEBUG) && !defined (IPC_DISABLE_ASSERTE)
    #define IPC_ASSERTE assert
  #endif // IPC_DEBUG
#endif // IPC_UNIX

#ifdef IPC_DISABLE_ASSERTE
#include "IPCDebug.h"
  #ifdef IPC_ASSERTE
	#undef IPC_ASSERTE
  #endif

#ifndef IPC_WIN32
  #define IPC_ASSERTE(expr) \
	do { \
		if (!(expr)) { \
			IPC_ERROR_TRACE(__FILE__ << ":" << __LINE__ << " Assert failed: " << #expr); \
		} \
	} while (0)

#else
  #define IPC_ASSERTE(expr) \
	do { \
		if (!(expr)) { \
		} \
	} while (0)
#endif // !IPC_WIN32
#endif // IPC_DISABLE_ASSERTE

#ifndef IPC_ASSERTE
  #define IPC_ASSERTE(expr) 
#endif // IPC_ASSERTE

//#define IPC_ASSERTE_THROW IPC_ASSERTE

#ifdef IPC_DISABLE_ASSERTE
#ifdef IPC_WIN32
  #define IPC_ASSERTE_RETURN(expr, rv) \
	do { \
		if (!(expr)) { \
			return rv; \
		} \
	} while (0)

  #define IPC_ASSERTE_RETURN_VOID(expr) \
	do { \
		if (!(expr)) { \
			return; \
		} \
	} while (0)
#else
  #define IPC_ASSERTE_RETURN(expr, rv) \
	do { \
		if (!(expr)) { \
			IPC_ERROR_TRACE(__FILE__ << ":" << __LINE__ << " Assert failed: " << #expr); \
			return rv; \
		} \
	} while (0)

  #define IPC_ASSERTE_RETURN_VOID(expr) \
	do { \
		if (!(expr)) { \
			IPC_ERROR_TRACE(__FILE__ << ":" << __LINE__ << " Assert failed: " << #expr); \
			return; \
		} \
	} while (0)

#endif //IPC_WIN32
#else
#ifdef IPC_WIN32
  #define IPC_ASSERTE_RETURN(expr, rv) \
	do { \
		IPC_ASSERTE((expr)); \
		if (!(expr)) { \
			IPC_ERROR_TRACE(__FILE__ << ":" << __LINE__ << " Assert failed: " << #expr); \
			return rv; \
		} \
	} while (0)

  #define IPC_ASSERTE_RETURN_VOID(expr) \
	do { \
		IPC_ASSERTE((expr)); \
		if (!(expr)) { \
			IPC_ERROR_TRACE(__FILE__ << ":" << __LINE__ << " Assert failed: " << #expr); \
			return; \
		} \
	} while (0)
#else
  #define IPC_ASSERTE_RETURN(expr, rv) \
	do { \
		IPC_ASSERTE((expr)); \
		if (!(expr)) { \
			IPC_ERROR_TRACE(__FILE__ << ":" << __LINE__ << " Assert failed: " << #expr); \
			return rv; \
		} \
	} while (0)

  #define IPC_ASSERTE_RETURN_VOID(expr) \
	do { \
		IPC_ASSERTE((expr)); \
		if (!(expr)) { \
			IPC_ERROR_TRACE(__FILE__ << ":" << __LINE__ << " Assert failed: " << #expr); \
			return; \
		} \
	} while (0)


#endif//IPC_WIN32
#endif // IPC_DISABLE_ASSERTE

#endif // !IPC_DEFINES_H
