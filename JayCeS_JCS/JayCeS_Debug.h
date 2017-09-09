/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JAYCES_DEBUG_H__
/**
 * $File: JCS_Debug.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JAYCES_DEBUG_H__


#include "JayCeS_StdAfx.h"
#include <string>

namespace JayCeS
{

    //====================================================================================
    // Class Name : JCS_Debug 
    //
    // Description : Debug relate function put here.
    //====================================================================================
    class JCS_Debug
    {
    private:
        std::wstring m_errorText;

    public:

        /**
            Print out the debug error in Output window.
        */
        JCS_Debug(const TCHAR* errorText)
        {
            JCS_Print1(L"***\n*** [Debug] Debug thrown! text: [%s]\n***\n", errorText);
            m_errorText = std::wstring(errorText);
        }

        /**
            Get the text to TCHAR*
        */
        const TCHAR* getText()
        {
            return m_errorText.c_str();
        }
    };

}


typedef JayCeS::JCS_Debug JCS_Debug;

#endif // __JAYCES_DEBUG_H__
