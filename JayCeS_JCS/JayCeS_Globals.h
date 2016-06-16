/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JAYCES_GLOBALS_H__
#define __JAYCES_GLOBALS_H__


#include "JayCeS_StdAfx.h"


#define JCS_Print( a )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, a );\
    OutputDebugString( buff );\
}

#define JCS_Print1( a, b )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, 1024, a, b );\
    OutputDebugString( buff );\
}

#define JCS_Print2( a, b, c )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, 1024, a, b );\
    OutputDebugString( buff );\
}

#define JCS_Print3( a, b, c, d )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, 1024, a, b );\
    OutputDebugString( buff );\
}

#define JCS_Print4( a, b, c, d, e )\
{\
    TCHAR buff[1024];\
    swprintf_s( buff, 1024, a, b );\
    OutputDebugString( buff );\
}

// 檢查通訊...
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
* useful here and there, allows the user to 'snap' a variable to lie
* within the bounds of two inputted vars
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

template <class T>
static inline void  swap(T* obj_01, T* obj_02)
{
    T* temp = obj_01;
    obj_01 = obj_02;
    obj_02 = temp;
    SafeDelete(temp);
}


#endif // __JAYCES_GLOBALS_H__

