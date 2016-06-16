/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __SAFEPOINTER_H__
#define __SAFEPOINTER_H__

#include <memory.h>

#ifdef WINDOWS
#define SP_SHOWMSG(msg) MessageBox(nullptr, (msg), ,"ERROR", MB_OK)
#else
#define SP_SHOWMSG(msg) fprintf(stderr, "%s\n", (msg))
#endif

/// 讓物件記憶體配置後檢查是否配置成功。
#define SAFE_NEW(p,t) try { \
if(((p) = new t) == nullptr) \
{ \
SP_SHOWMSG("Virtual memory exhausted! Program Exit!"); \
} \
} catch (Exception &e) { \
SP_SHOWMSG(e.Message.c_str()); \
p = nullptr ; \
}


/**
* This class takes care of the annoying gruntwork
* of having to zero-out and set the size parameter
* of our Windows and DirectX structures.
*/
template <class T>
struct sAutoZero : public T
{
    sAutoZero()
    {
        memset(this, 0, sizeof(T));
        dwSize = sizeof(T);
    }
};

/**
* The Right Way to release our COM interfaces.
* If they're still valid, release them, then
* invalidate them and null them.
*/
template <class T>
inline void SafeReleaseCOM(T& ptr)
{
    if (ptr)
    {
        ptr->Release();
        ptr = nullptr;
    }
}

/**
* The Right Way to delete our COM object.
* If they're still valid, delete them, then
* invalidate them and null them.
*
* 讓物件被delete後，將其值設為nullptr。並且在delet物件之前，先確定該指標不為nullptr。
*/
template <class T>
inline void SafeDeleteObject(T& ptr)
{
    if (ptr)
    {
        delete ptr;
        ptr = nullptr;        // could also set to 0
    }
}

/**
* 讓物件Array被delete後，將其值設為nullptr。並且在delet物件之前，先確定該指標不為nullptr。
*/
template <class T>
inline void SafeDeleteArrayObject(T& ptr)
{
    if (ptr)
    {
        delete[] ptr;
        ptr = nullptr;
    }
}

/**
*  
*/
template <class T>
inline void SafeFreeObject(T& ptr)
{
    if (ptr)
    {
        free(ptr);
        ptr = nullptr;
    }
}

/**
*
*/
template <class T>
inline void SafeCloseFile(T& ptr)
{
    if (ptr)
    {
        fclose(ptr);
        ptr = nullptr;
    }
}


#endif // __SAFEPOINTER_H__

