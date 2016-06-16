/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JAYCES_DEBUG_H__
#define __JAYCES_DEBUG_H__


#include "JayCeS_StdAfx.h"
#include <string>

namespace JayCeS
{

    //------------------------------------------------------------------------------------
    // Name : JCS_Debug 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class JCS_Debug
    {
    private:
        std::wstring m_errorText;

    public:
        JCS_Debug(const TCHAR* errorText)
        {
            JCS_Print1(L"***\n*** [Debug] Debug thrown! text: [%s]\n***\n", errorText);
            m_errorText = std::wstring(errorText);
        }

        const TCHAR* getText()
        {
            return m_errorText.c_str();
        }
    };

}


typedef JayCeS::JCS_Debug JCS_Debug;

#endif // __JAYCES_DEBUG_H__

