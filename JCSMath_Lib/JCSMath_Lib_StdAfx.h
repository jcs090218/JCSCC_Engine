#ifndef __JCSMATH_LIB_STDAFX_H__
/**
 * $File: JCSMath_Lib_StdAfx.h $
 * $Date: 2016-12-01 12:52:34 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCSMATH_LIB_STDAFX_H__

 // NOTE(jenchieh): comment this out if importing dll
 // We are exporting to dll file.
#define EXPORTS_DLL

 // Defines import/export dynamic link library.
#ifndef EXPORTS_DLL
 // Import
#if defined (_MSC_VER)
 // Microsoft
#define DECLSPEC_ACTION __declspec(dllimport)
#define JCSCC_DLL __declspec(dllimport)
#elif defined (__GNUC__)
 // GCC
#define DECLSPEC_ACTION __attribute__((visibility(dllimport)))
#define JCSCC_DLL __attribute__((visibility(dllimport)))
#else
 // Default
#define DECLSPEC_ACTION
#define JCSCC_DLL
#endif
#else
 // Export
#if defined (_MSC_VER)
 // Microsoft
#define DECLSPEC_ACTION __declspec(dllexport)
#define JCSCC_DLL __declspec(dllexport)
#elif defined (__GNUC__)
 // GCC
#define DECLSPEC_ACTION __attribute__((visibility(dllexport)))
#define JCSCC_DLL __attribute__((visibility(dllexport)))
#else
 // Default
#define DECLSPEC_ACTION
#define JCSCC_DLL
#endif
#endif


// prevent redefined
#undef EXTERN_C_BEGIN
#undef EXTERN_C_END

// c plus plus define?
#ifdef __cplusplus
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

// Libraries
#include <JayCeS_JCS\JayCeS.h>
#include <GameInterface_JCS\GameInterface_StdAfx.h>


////// LINKER ////////////////

// NOTICE(JenChieh): if u want a static link library
// into ur dynamic link library, include the .lib file
// to ur dll project like here below.
#pragma comment (lib, "JayCeS_JCS.lib")
#pragma comment (lib, "GameInterface_JCS.lib")
#pragma comment (lib, "GameUtility_JCS.lib")

#endif // __JCSMATH_LIB_STDAFX_H__
