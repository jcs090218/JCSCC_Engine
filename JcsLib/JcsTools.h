/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCSTOOLS_H__
#define __JCSTOOLS_H__


#include "JcsLib_StdAfx.h"

namespace JcsLib
{
    enum class JcsVersion;

    //------------------------------------------------------------------------------------
    // Name : JcsTools
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class JcsTools
    {
    public:
        static const int32 CHECK_KEYS = 256;
        static uint32 s_checksumXorTable[CHECK_KEYS];
        static byte* s_pJcsKey;
        static char* s_pJcsUniKey;
        static uint32 s_keyLength;

    private:
        static JCS_StringBuilder s_stringBuilder;

    public:
        JcsTools();
        ~JcsTools();

        static void CreateJcsKey(const JcsVersion gameVersion);
        static wchar_t* DecryptNonUnicodeString(wchar_t stringToDecrypt[]);
        static wchar_t* DecryptString(wchar_t stringToDecrypt[]);
        static void DelDir(wchar_t* path);
        static uint32 GetChecksum(JCS_BinaryReader rdr, int32 length, uint32 start);

#ifdef _UNICODE
        static wchar_t* ReadNullTerminatedString(JCS_BinaryReader& reader);
        static int32 GetCompressedIntLength(int32 i);
        static int32 GetEncodedStringLength(wchar_t* ws);
        static int32 ReadCompressedInt(JCS_BinaryReader& reader);
        static wchar_t* ReadDecodedString(JCS_BinaryReader& reader);
        static wchar_t* ReadDecodedStringAtOffset(JCS_BinaryReader& reader, long32 offset);
        static wchar_t* ReadDecodedStringAtOffsetAndReset(JCS_BinaryReader& reader, long32 offset);
        static wchar_t* ReadDecodedStringAtOffsetAndReset(JCS_BinaryReader& reader, long32 offset, bool flag);
#else
        static char* ReadNullTerminatedString(JCS_BinaryReader& reader);
        static int32 GetCompressedIntLength(int32 i);
        static int32 GetEncodedStringLength(char* ws);
        static int32 ReadCompressedInt(JCS_BinaryReader& reader);
        static char* ReadDecodedString(JCS_BinaryReader& reader);
        static char* ReadDecodedStringAtOffset(JCS_BinaryReader& reader, long32 offset);
        static char* ReadDecodedStringAtOffsetAndReset(JCS_BinaryReader& reader, long32 offset);
        static char* ReadDecodedStringAtOffsetAndReset(JCS_BinaryReader& reader, long32 offset, bool flag);
#endif // _UNICODE

        static void WriteCompressedInt();
        static void WriteEncodedString(JCS_BinaryWriter& writer);
        static void WriteNullTerminatedString(JCS_BinaryWriter& writer);


        // setter

        // getter
    };

}

typedef JcsLib::JcsTools JcsTools;

#endif // __JCSTOOLS_H__

