/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCSMESSAGEBOX_H__
/**
 * $File: JcsMessageBox.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCSMESSAGEBOX_H__


#include "JayCeS_StdAfx.h"


namespace JayCeS
{

    //====================================================================================
    // Name : JcsMessageBox 
    //
    // Description : Provide cross platform message box.
    //====================================================================================
    class JcsMessageBox
    {
    public:

#ifdef _WIN32
#ifdef _UNICODE
        static int32 JCS_MessageBox(const LPCWSTR title, const LPCWSTR message, uint32 flags);
#else
        static int32 JCS_MessageBox(const LPCSTR title, const LPCSTR message, uint32 flags);
#endif // _UNICODE
#elif _OSX

#else   // Linux
        // Cross OS
        static int32 JCS_MessageBox(const char* title, const char* message, uint32 flags);
#endif 
    };

}

typedef JayCeS::JcsMessageBox JcsMessageBox;

#ifdef _WIN32
#ifdef _UNICODE
inline int32 JCS_MessageBox(const LPCWSTR title, const LPCWSTR message, uint32 flags)
{
    return JcsMessageBox::JCS_MessageBox(title, message, flags);
}
#else
inline int32 JCS_MessageBox(const LPCSTR title, const LPCSTR message, uint32 flags)
{
    return JcsMessageBox::JCS_MessageBox(title, message, flags);
}
#endif // _UNICODE

#elif _OSX

#else

#endif

#endif // __JCSMESSAGEBOX_H__

