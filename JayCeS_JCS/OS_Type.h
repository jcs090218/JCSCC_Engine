/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __OS_TYPE_H__
/**
 * $File: OS_Type.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __OS_TYPE_H__


namespace JayCeS
{

    //====================================================================================
    // Enum Name : Operating System Type 
    // 
    // Description : List of all operating system JCSCC can do. 
    //====================================================================================
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

