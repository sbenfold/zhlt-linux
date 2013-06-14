#ifndef CONFIG_H
#define CONFIG_H

#ifdef SYSTEM_POSIX

// TODO: These are now unsafe
#define strcpy_s strcpy
#define sprintf_s sprintf
#define fscanf_s fscanf 
#define sscanf_s sscanf 

#define _strlwr strlwr
#define _strupr strupr
#define _strdup strdup 
#define _open open
#define _close close
#define _read read
#define _unlink unlink 

//#include <unistd.h>
#endif // SYSTEM_POSIX

#if _WIN32 || _WIN64
	#if _WIN64
		#define ENV64BIT
	#else
		#define ENV32BIT
	#endif
#endif

#if __GNUC__
	#if __x86_64__ || __ppc64__
		#define ENV64BIT
	#else
		#define ENV32BIT
	#endif
#endif

#if defined(ENV32BIT)
	#define SIZEOF_CHARP 4
#elif defined(ENV64BIT)
	#define SIZEOF_CHARP 8
#else
	#error "Failed to identify architecture"
#endif

#endif // CONFIG_H
