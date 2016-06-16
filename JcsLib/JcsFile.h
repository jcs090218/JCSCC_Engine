/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCSFILE_H__
#define __JCSFILE_H__


#include "JcsLib_StdAfx.h"

#include "IJcsFile.h"
#include "JcsVersion.h"
#include "JcsDirectory.h"
#include "JcsTools.h"

namespace JcsLib
{
    class JcsDirectory;

    //------------------------------------------------------------------------------------
    // Name : JcsFile 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class JcsFile 
        : public IJcsFile
    {
    private:
        wchar_t* m_copyright;
        byte m_fileVersion;
        uint64 m_fsize;
        uint32 m_fstart;
        wchar_t* m_ident;
        wchar_t* m_name;
        wchar_t* m_path;
        JcsVersion m_type;
        uint16 m_version;
        int32 m_versionHash;
        JcsDirectory m_jcsDir;

    public:
        JcsFile(JcsVersion version);
        JcsFile(wchar_t* filePath, JcsVersion version);
        virtual ~JcsFile();

        void ParseJcsFile();
        void ParseMainJcsDirectory();

        // setter

        // getter

    };

}

typedef JcsLib::JcsFile JcsFile;

#endif // __JCSFILE_H__

