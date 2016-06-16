/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JAYCES_ERROR_H__
#define __JAYCES_ERROR_H__

#include "JayCeS_StdAfx.h"
#include <string>

namespace JayCeS
{
    //------------------------------------------------------------------------------------
    // Name : JCS_Error 
    //
    // Desc : This code is slow, using dynamic memory, but since we only use them
    //        when something Really Bad happens, the user won't notice that their
    //        application exits abmornally a few nanoseconds slower than usual
    //------------------------------------------------------------------------------------
    class JCS_Error
    {
    private:
        std::wstring m_errorText;

    public:
        JCS_Error(const TCHAR* errorText)
        {
            JCS_Print1(L"***\n*** [ERROR] GameError thrown! text: [%s]\n***\n", errorText);
            m_errorText = std::wstring(errorText);
        }

        const TCHAR* getText()
        {
            return m_errorText.c_str();
        }
    };

    //==========--------------------------  

    enum eResult
    {
        resAllGood = 0,                 // function passed with flying colors
        resFalse = 1,                   // function worked and returns value 'false'
        resFailed = -1,                 // function failed miserably
        resNotImpl = -2,                // function has not been implemented
        resForceDWord = 0x7FFFFFFF
    };

    inline bool Succeeded(eResult in)
    {
        if (in >= 0)
            return true;
        return false;
    }

    inline bool Failed(eResult in)
    {
        if (in < 0)
            return true;
        return false;
    }
}

typedef JayCeS::JCS_Error JCS_Error;

#endif // __JAYCES_ERROR_H__

