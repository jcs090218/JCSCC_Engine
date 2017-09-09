#ifndef __SAFEPOINTER_H__
/**
 * $File: SafePointer.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
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
struct AutoZero : public T
{
    AutoZero()
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
* Delete ptr array object.
*
* ex: BaseClass* m_pBaseObject[size];
*
*   // delete the object.
*	SafeDeletePtrArrayObject(m_pBaseObject, size);
*/
template <class T>
inline void SafeDeletePtrArrayObject(T& ptrArr, int32 size)
{
    for (int32 index = 0;
        index < size;
        ++index)
    {
        // loop through and delete each pointer in the 
        // pointer array.
        SafeDeleteObject(ptrArr[index]);
    }
}

/**
* Delete double array object.
*
* ex: BaseClass** m_pBaseObject = nullptr;
* 
*   // delete the object.
*	SafeDeleteDoublePtrObject(m_pBaseObject, size);
*/
template <class T>
inline void SafeDeleteDoublePtrObject(T& ptrArr, int32 size)
{
	for (int32 index = 0;
		index < size;
		++index)
	{
		// loop through and delete each pointer in the 
		// pointer array.
		SafeDeleteObject(ptrArr[index]);
	}

	// finally destroy the array pointer.
	SafeDeleteArrayObject(ptrArr);
}

/**
* Safe Delete the container object.
*
* How to use this?
*	T: the container type.
*	U: the base type in container.
*	ptrArr: is the container object itself.
*
* Examples:
*     SafeDeleteContainerPtrObject<std::vector<Base*>, Base>(baseArr);
*/
template <class T, class U>
inline void SafeDeleteContainerPtrObject(T& ptrArr)
{
	for (U* obj : ptrArr)
	{
		// loop through and delete each pointer in the 
		// pointer array.
		SafeDeleteObject(obj);
	}
}

/**
* Safe Delete the double container object.
*
* How to use this?
*	T: the container type.
*	U: the base type in container.
*	ptrArr: is the container object itself.
*
* Examples:
*     SafeDeleteDoubleContainerPtrObject<std::vector<Base*>*, Base>(baseArr);
*/
template <class T, class U>
inline void SafeDeleteDoubleContainerPtrObject(T& ptrArr)
{
	for (U* obj : *ptrArr)
	{
		// loop through and delete each pointer in the 
		// pointer array.
		SafeDeleteObject(obj);
	}

	// finally destroy the container object
	SafeDeleteObject(ptrArr);
}

/**
*  Safe way to free the freeable object.
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
* Safe way to close the file.
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

