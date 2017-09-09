/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JAYCES_GLOBALS_H__
/**
 * $File: JayCeS_Globals.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JAYCES_GLOBALS_H__


#include "JayCeS_StdAfx.h"

/**
    Print out the value by type : 1

    @param value type 1
*/
#define JCS_Print( a )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, a );\
    OutputDebugString( buff );\
}

/**
    Print out the value by type : 2

    @param value type 1
    @param value type 2
*/
#define JCS_Print1( a, b )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, 1024, a, b );\
    OutputDebugString( buff );\
}

/**
    Print out the value by type : 3

    @param value type 1
    @param value type 2
    @param value type 3
*/
#define JCS_Print2( a, b, c )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, 1024, a, b );\
    OutputDebugString( buff );\
}

/**
    Print out the value by type : 4

    @param value type 1
    @param value type 2
    @param value type 3
    @param value type 4
*/
#define JCS_Print3( a, b, c, d )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, 1024, a, b );\
    OutputDebugString( buff );\
}

/**
    Print out the value by type : 5

    @param value type 1
    @param value type 2
    @param value type 3
    @param value type 4
    @param value type 5
*/
#define JCS_Print4( a, b, c, d, e )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, 1024, a, b );\
    OutputDebugString( buff );\
}

/**  
    檢查通訊...
*/
#ifndef CHECKF  
#define CHECKF(x) \
do \
{ \
    if (!(x)) { \
        log_msg("CHECKF", #x, __FILE__, __LINE__); \
        return 0; \
        } \
} while (0)
#endif  

/**
    Useful here and there, allows the user to 'snap' a variable to line
    within the bounds of two inputted vars
*/
template <class T>
static inline void Snap(T &a, T min, T max)
{
    if (a < min)
        a = min;
    if (a > max)
        a = max;
}

inline float RandFloat(float min = 0.f, float max = 1.f)
{
    return min + (max - min)*((float)rand() / RAND_MAX);
}

/**
    swap the value by type, useful function.
*/
template <class T>
inline void  swap(T* obj_01, T* obj_02)
{
    T* temp = obj_01;
    obj_01 = obj_02;
    obj_02 = temp;
    SafeDelete(temp);
}

/**
    Get the new line regular sign. 
*/
inline std::string NewLine()
{
#ifdef _WIN32
    return "\r\n";
#elif  (__APPLE__) && (__MACH__)
    return "\r";
#elif __linux__
    return "\n";
#endif
}

/**
    Get the new line regular sign. (WCHAR)
*/
inline std::wstring NewLineW()
{
#ifdef _WIN32
    return L"\r\n";
#elif (__APPLE__) && (__MACH__)
    return L"\r";
#elif __linux__
    return L"\n";
#endif
}


#endif // __JAYCES_GLOBALS_H__

