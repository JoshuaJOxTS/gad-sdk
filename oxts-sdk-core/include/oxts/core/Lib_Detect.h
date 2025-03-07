//============================================================================================================
//!
//! The software is protected by copyright of Oxford Technical Solutions.
//! Copyright (C) 2017 Oxford Technical Solutions - http://www.oxts.com
//!
//! Redistribution and use in source and binary forms, with or without modification, are only permitted with
//! the specific prior written permission of Oxford Technical Solutions.
//!
//! $LastChangedDate: 2018-08-10 14:12:02 +0100 (Fri, 10 Aug 2018) $
//! $LastChangedRevision: 26913 $
//! $LastChangedBy: alambert $
//!
//! \file Lib_Detect.h
//!
//! \brief Macros to detect which compiler and operating system.
//!
//============================================================================================================


#ifndef LIB__DETECT_H
#define LIB__DETECT_H


#define LIB__DETECT_DEV_ID "140229"  //!< Development Identification.


//============================================================================================================
// OXTS_CC: OXTS_CC_MSVC OXTS_CC_MINGW OXTS_CC_CYGWIN OXTS_CC_GCC OXTS_CC_QCC OXTS_CC_BORLAND OXTS_CC_TI

#ifndef OXTS_CC_MSVC
#define OXTS_CC_MSVC 0
#define OXTS_CC_MSVC_CLR 0
#endif
#ifndef OXTS_CC_BORLAND
#define OXTS_CC_BORLAND 0
#endif
#ifndef OXTS_CC_MINGW
#define OXTS_CC_MINGW 0
#endif
#ifndef OXTS_CC_CYGWIN
#define OXTS_CC_CYGWIN 0
#endif
#ifndef OXTS_CC_GCC
#define OXTS_CC_GCC 0
#endif
#ifndef OXTS_CC_QCC
#define OXTS_CC_QCC 0
#endif
#ifndef OXTS_CC_TI
#define OXTS_CC_TI 0
#endif

#if (_MSC_VER)
#if (OXTS_CC_BORLAND || OXTS_CC_MINGW || OXTS_CC_CYGWIN || OXTS_CC_QCC || OXTS_CC_TI || OXTS_CC_GCC)
#error "Detected MSVC but you say something else"
#endif
#undef  OXTS_CC_MSVC
#define OXTS_CC_MSVC 1
#elif __BORLANDC__
#if (OXTS_CC_MSVC || OXTS_CC_MINGW || OXTS_CC_CYGWIN || OXTS_CC_QCC || OXTS_CC_TI || OXTS_CC_GCC)
#error "Detected BORLAND but you say something else"
#endif
#undef  OXTS_CC_BORLAND
#define OXTS_CC_BORLAND 1
#elif (__MINGW32__ || __MINGW64__)
#if (OXTS_CC_MSVC || OXTS_CC_BORLAND || OXTS_CC_CYGWIN || OXTS_CC_QCC || OXTS_CC_TI || OXTS_CC_GCC)
#error "Detected MINGW but you say something else"
#endif
#undef  OXTS_CC_MINGW
#define OXTS_CC_MINGW 1
#elif __CYGWIN32__
#if (OXTS_CC_MSVC || OXTS_CC_BORLAND || OXTS_CC_MINGW || OXTS_CC_QCC || OXTS_CC_TI || OXTS_CC_GCC)
#error "Detected CYGWIN but you say something else"
#endif
#undef  OXTS_CC_CYGWIN
#define OXTS_CC_CYGWIN 1
#elif defined(__QNX__)
#if (OXTS_CC_MSVC || OXTS_CC_BORLAND || OXTS_CC_MINGW || OXTS_CC_CYGWIN || OXTS_CC_TI || OXTS_CC_GCC)
#error "Detected QCC but you say something else"
#endif
#undef  OXTS_CC_QCC
#define OXTS_CC_QCC 1
#elif defined(__TI_COMPILER_VERSION__)
#if (OXTS_CC_MSVC || OXTS_CC_BORLAND || OXTS_CC_MINGW || OXTS_CC_CYGWIN || OXTS_CC_QCC || OXTS_CC_GCC)
#error "Detected TI but you say something else"
#endif
#undef  OXTS_CC_TI
#define OXTS_CC_TI 1
#elif __GNUC__
#if (OXTS_CC_MSVC || OXTS_CC_BORLAND || OXTS_CC_MINGW || OXTS_CC_CYGWIN || OXTS_CC_QCC || OXTS_CC_TI)
#error "Detected GCC but you say something else"
#endif
#undef  OXTS_CC_GCC
#define OXTS_CC_GCC 1
#else
#error "Compiler not understood"
#endif


#if OXTS_CC_MSVC
#ifdef __CLR_VER
#undef  OXTS_CC_MSVC_CLR
#define OXTS_CC_MSVC_CLR 1
#endif
#endif


//============================================================================================================
// OXTS_OS: OXTS_OS_WINDOWS OXTS_OS_QNX OXTS_OS_TI OXTS_OS_LINUX

#ifndef OXTS_OS_WINDOWS
#define OXTS_OS_WINDOWS 0
#endif
#ifndef OXTS_OS_QNX
#define OXTS_OS_QNX 0
#endif
#ifndef OXTS_OS_TI
#define OXTS_OS_TI 0
#endif
#ifndef OXTS_OS_XDEV
#define OXTS_OS_XDEV 0
#endif
#ifndef OXTS_OS_LINUX
#define OXTS_OS_LINUX 0
#endif

#if defined(WIN32) || defined(_WIN32)
		#if (OXTS_OS_QNX || OXTS_OS_TI || OXTS_OS_LINUX || OXTS_OS_XDEV)
		#error "Detected OXTS_OS_WINDOWS but you say something else"
		#endif
	#undef  OXTS_OS_WINDOWS
	#define OXTS_OS_WINDOWS 1
#elif defined(__QNX__)
		#if (OXTS_OS_WINDOWS || OXTS_OS_TI || OXTS_OS_LINUX || OXTS_OS_XDEV)
		#error "Detected OXTS_OS_QNX but you say something else"
		#endif
	#undef  OXTS_OS_QNX
	#define OXTS_OS_QNX 1
#elif defined(__TI_COMPILER_VERSION__)
		#if (OXTS_OS_WINDOWS || OXTS_OS_QNX || OXTS_OS_LINUX || OXTS_OS_XDEV)
		#error "Detected OXTS_OS_TI but you say something else"
		#endif
	#undef  OXTS_OS_TI
	#define OXTS_OS_TI 1
#elif defined(xDev)
		#if (OXTS_OS_WINDOWS || OXTS_OS_QNX || OXTS_OS_LINUX || OXTS_OS_XDEV)
		#error "Detected OXTS_OS_TI but you say something else"
		#endif
	#undef  OXTS_OS_XDEV
	#define OXTS_OS_XDEV 1
#else
#if (OXTS_OS_WINDOWS || OXTS_OS_QNX || OXTS_OS_TI || OXTS_OS_XDEV)
#error "Detected OXTS_OS_LINUX but you say something else"
#endif
#undef  OXTS_OS_LINUX
#define OXTS_OS_LINUX 1
#endif


#endif
