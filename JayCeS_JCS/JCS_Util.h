#ifndef __JCS_UTIL_H__
/**
* $File: JCS_Util.h $
* $Date: 2016-11-09 23:15:16 $
* $Revision: $
* $Creator: Jen-Chieh Shen $
* $Notice: See LICENSE.txt for modification and distribution information
*                   Copyright (c) 2016 by Shen, Jen-Chieh $
*/
#define __JCS_UTIL_H__

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <amp.h>

namespace JayCeS
{

    /**
    Add two char* together.
    */
    inline const char* AddCharPtr(
        char*& a,
        char*& b)
    {
        std::string tmpStr = a;
        tmpStr += b;

        return (tmpStr.c_str());
    }

    /**
    Add three char* together.
    */
    inline const char* AddCharPtr(
        char*& a,
        char*& b,
        char*& c)
    {
        std::string tmpStr = a;
        tmpStr += b;
        tmpStr += c;

        return (tmpStr.c_str());
    }

    /**
    Add four char* together.
    */
    inline const char* AddCharPtr(
        char*& a,
        char*& b,
        char*& c,
        char*& d)
    {
        std::string tmpStr = a;
        tmpStr += b;
        tmpStr += c;
        tmpStr += d;

        return (tmpStr.c_str());
    }

    /**
    Add two wchar_t* together.
    */
    inline const wchar_t* AddWCharPtr(
        wchar_t*& a,
        wchar_t*& b)
    {
        std::wstring tmpStr = a;
        tmpStr += b;

        return (tmpStr.c_str());
    }

    /**
    Add three wchar_t* together.
    */
    inline const wchar_t* AddWCharPtr(
        wchar_t*& a,
        wchar_t*& b,
        wchar_t*& c)
    {
        std::wstring tmpStr = a;
        tmpStr += b;
        tmpStr += c;

        return (tmpStr.c_str());
    }

    /**
    Add four wchar_t* together.
    */
    inline const wchar_t* AddWCharPtr(
        wchar_t*& a,
        wchar_t*& b,
        wchar_t*& c,
        wchar_t*& d)
    {
        std::wstring tmpStr = a;
        tmpStr += b;
        tmpStr += c;
        tmpStr += d;

        return (tmpStr.c_str());
    }

    /** 
    Clamp a value between from and to.
    */
    inline float Clampf(
        float32 value, 
        float32 min_inclusive, 
        float32 max_inclusive)
    {
        if (min_inclusive > max_inclusive) 
        {
            std::swap(min_inclusive, max_inclusive);
        }

        return value < min_inclusive ? min_inclusive : value < max_inclusive ? value : max_inclusive;
    }

}

#endif // __JCS_UTIL_H__
