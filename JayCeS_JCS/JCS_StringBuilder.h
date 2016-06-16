/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_STRINGBUILDER_H__
#define __JCS_STRINGBUILDER_H__


#include "JayCeS_StdAfx.h"

namespace JayCeS
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_StringBuilder
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_StringBuilder
    {
    private:
#ifdef _UNICODE
        std::wstringstream m_bufferstream;
        wchar_t* m_pBuffer = nullptr;
        std::wstring m_bufferString;
#else
        std::stringstream m_bufferstream;
        char* m_pBuffer = nullptr;
        std::string m_bufferString;
#endif // _UNICODE

    public:
        JCS_StringBuilder();
        ~JCS_StringBuilder();

        void Append(byte buf);
        void Peek();
        void Clear();

#ifdef _UNICODE
        wchar_t* ToString();
#else
        char* ToString();
#endif // _UNICODE
    };

}

typedef JayCeS::JCS_StringBuilder JCS_StringBuilder;

#endif // __JCS_STRINGBUILDER_H__

