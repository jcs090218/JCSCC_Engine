/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

/**
 * $File: JCS_StringBuilder.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "JCS_StringBuilder.h"


namespace JayCeS
{
    JCS_StringBuilder::JCS_StringBuilder()
    {

    }

    JCS_StringBuilder::~JCS_StringBuilder()
    {

    }

    void JCS_StringBuilder::Append(byte buf)
    {
        m_bufferstream << (char)buf;
    }

    void JCS_StringBuilder::Peek()
    {
#ifdef _UNICODE
        std::wstring var = m_bufferstream.str();
        std::wcout << var 
#else
        std::string var = m_bufferstream.str();
        std::cout << var 
#endif
        << std::endl;
    }

    void JCS_StringBuilder::Clear()
    {
#ifdef _UNICODE
        m_bufferstream.str(L"");
#else
        m_bufferstream.str("");
#endif 
        m_bufferstream.clear();
    }

#ifdef _UNICODE
    wchar_t* JCS_StringBuilder::ToString()
    {
        m_bufferString = m_bufferstream.str();
        m_pBuffer = const_cast<wchar_t*>(m_bufferString.c_str());
        return m_pBuffer;
    }
#else
    char* JCS_StringBuilder::ToString()
    {
        m_bufferString = m_bufferstream.str();
        m_pBuffer = const_cast<wchar_t*>(m_bufferString.c_str());
        return m_pBuffer;
    }
#endif // _UNICODE

}

