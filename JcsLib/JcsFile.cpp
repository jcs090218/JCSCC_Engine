/**
 * $File: JcsFile.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "JcsFile.h"


#include <JayCeS_JCS\JayCeS.h>

#ifdef __cplusplus
extern "C"
{
#endif

    namespace JcsLib
    {

        JcsFile::JcsFile(JcsVersion version)
            : m_type(version)
        {
            this->m_name = L"";
            this->m_ident = L"PKG1";
            this->m_copyright = L"Package file v1.0 Copyright 2016 JayCeS, JCS";
        }

        JcsFile::JcsFile(wchar_t* filePath, JcsVersion version)
            : m_type(version)
            , m_path(filePath)
        {
            this->m_name = L"";
            this->m_ident = L"PKG1";
            this->m_copyright = L"Package file v1.0 Copyright 2016 JayCeS, JCS";
        }

        JcsFile::~JcsFile()
        {

        }

        // Parse the jcs format file.
        void JcsFile::ParseJcsFile()
        {
            JcsTools::CreateJcsKey(this->m_type);
            this->ParseMainJcsDirectory();
        }

        // Parse the root of jcs format file.
        void JcsFile::ParseMainJcsDirectory()
        {
            JcsDirectory directory;

            if (!m_path)
                return;

            this->m_ident = L"";

            // Generate Binary File Reader.
            JCS_BinaryReader fileReader;

            // Read file to binary
            fileReader.Read(m_path);

            for (int i = 0; i < 4; ++i)
            {
                this->m_ident = this->m_ident + ((char)(fileReader.ReadByte8()));
            }

            this->m_fsize = fileReader.ReadUInt64();
            this->m_fstart = fileReader.ReadUInt32();
            this->m_copyright = JcsTools::ReadNullTerminatedString(fileReader);
            this->m_version = fileReader.ReadShort16();

            // Information Print.
            {
                JCS_Print1(L"File Size: %llu\n", m_fsize);
                JCS_Print1(L"File Start: %lu\n", m_fstart);
                JCS_Print1(L"Copy Right: %ws\n", m_copyright);
                JCS_Print1(L"Version: %hu\n", m_version);
            }

            for (int j = 0; j < 0xff; ++j)
            {

            }
        }

    }

#ifdef __cplusplus
}
#endif
