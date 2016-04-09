/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __OS_TYPE_H__
#define __OS_TYPE_H__


namespace JayCeS
{
    enum class OperatingSystemType
    {
        //*** Microsoft ***//
        WINDOWS_7,
        WINDOWS_8,
        WINDOWS_10,
        WINDOWS_STORE,
        WINDOWS_PHONE_8,

        //*** Macintosh ***//
        OSX,            // Mac 
        IOS,            // Mobile

        //*** Linux ***//
        LINUX,

        //*** Android ***//
        ANDROID
    };
}

#endif // __OS_TYPE_H__

