/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_BINARYWRITER_H__
#define __JCS_BINARYWRITER_H__


#include "JayCeS_StdAfx.h"

namespace JayCeS
{
    class IJcsObject;

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_BinaryWriter
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_BinaryWriter
    {
    private:
        FILE* m_file = nullptr;
        byte* m_buffer = nullptr;

    public:
        JCS_BinaryWriter();
        ~JCS_BinaryWriter();

#ifdef _WIN32
#ifdef _UNICODE
        /**
            Tutorial & Information: 
                * C++ BINARY FILE I/O (Youtube Video)
                https://www.youtube.com/watch?v=P5_ED_JuGls
                * Get rid of "_CRT_SECURE_NO_WARNINGS"
                http://stackoverflow.com/questions/21873048/getting-an-error-fopen-this-function-or-variable-may-be-unsafe-when-complin
                * MSDN (fopen_s、_wfopen_s):
                https://msdn.microsoft.com/zh-tw/library/z5hh6ee9.aspx
        */
        void Write(const wchar_t* filePath, IJcsObject* dataStruct);
#else
        void Write(const char* filePath, IJcsObject* dataStruct);
#endif
#endif // _WIN32

        void ClearFile();
        void ClearBuffer();

        // setter

        // getter
        FILE* GetFile() const { return this->m_file; }

    };

}

typedef JayCeS::JCS_BinaryWriter JCS_BinaryWriter;

#endif // __JCS_BINARYWRITER_H__

