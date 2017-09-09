/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

/**
 * $File: JCS_BinaryWriter.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "JCS_BinaryWriter.h"


#include <JcsLib\IJcsObject.h>

namespace JayCeS
{

    JCS_BinaryWriter::JCS_BinaryWriter()
    {

    }

    JCS_BinaryWriter::~JCS_BinaryWriter()
    {
        SafeFreeObject(m_buffer);
    }

#ifdef _WIN32
#ifdef _UNICODE
    void JCS_BinaryWriter::Write(const wchar_t* filePath, IJcsObject* dataStruct)
    {
        if (!dataStruct)
        {
            throw JCS_Error(L"Data Struct we trying to read are unreadable memory...");
            return;
        }

        // Open a file with "wb" (WRITE BINARY)
        m_file = _wfopen(filePath, L"wb");

        // Write Binary File
        fwrite(dataStruct, sizeof(dataStruct), 1, m_file);

        // Close the file
        fclose(m_file);
    }
#else
    void JCS_BinaryWriter::Write(const char* filePath, IJcsObject* dataStruct)
    {
        if (!dataStruct)
        {
            throw JCS_Error(L"Data Struct we trying to read are unreadable memory...");
            return;
        }

        // Open a file with "wb" (WRITE BINARY)
        m_file = fopen(filePath, "wb");

        // Write Binary File
        fwrite(dataStruct, sizeof(dataStruct), 1, m_file);

        // Close the file
        fclose(m_file);
    }
#endif 
#endif // _WIN32

    void JCS_BinaryWriter::ClearFile()
    {
        if (m_file)
            fclose(m_file);
    }
    void JCS_BinaryWriter::ClearBuffer()
    {
        if (m_buffer)
            free(m_buffer);
    }

}

