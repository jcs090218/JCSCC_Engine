#ifndef __JCSTOOLS_H__
/**
 * $File: JcsTools.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCSTOOLS_H__


#include "JcsLib_StdAfx.h"

EXTERN_C_BEGIN

namespace JcsLib
{
	enum class JcsVersion;

	/**
	@class JcsTools
	@brief Common tools to use in JcsLib/JCSCC.
	*/
	class JcsTools
	{
	public:
		static const int32 CHECK_KEYS = 256;    // key lengh check.
		static uint32 s_checksumXorTable[CHECK_KEYS];   // 
		static byte* s_pJcsKey;         // common key for game resources check
		static char* s_pJcsUniKey;      // unique key for game resources check
		static uint32 s_keyLength;      // length of the key

	private:
		static JCS_StringBuilder s_stringBuilder;       // string builder

	public:
		DECLSPEC_ACTION JcsTools();
		DECLSPEC_ACTION ~JcsTools();

		/**
			Create the key to encrypt/decrypt game resources.

			@param version of this game resource.
		*/
		DECLSPEC_ACTION static void CreateJcsKey(const JcsVersion gameVersion);
		/**

		*/
		DECLSPEC_ACTION static wchar_t* DecryptNonUnicodeString(wchar_t stringToDecrypt[]);
		/**

		*/
		DECLSPEC_ACTION static wchar_t* DecryptString(wchar_t stringToDecrypt[]);
		/**

		*/
		DECLSPEC_ACTION static void DelDir(wchar_t* path);
		/**

		*/
		DECLSPEC_ACTION static uint32 GetChecksum(JCS_BinaryReader rdr, int32 length, uint32 start);

#ifdef _UNICODE
		/**
			Return the binary into string until the string is null.

			@param Binary going to analysis into wide char.
		*/
		DECLSPEC_ACTION static wchar_t* ReadNullTerminatedString(JCS_BinaryReader& reader);
		/**

		*/
		DECLSPEC_ACTION static int32 GetCompressedIntLength(int32 i);
		/**

		*/
		DECLSPEC_ACTION static int32 GetEncodedStringLength(wchar_t* ws);
		/**

		*/
		DECLSPEC_ACTION static int32 ReadCompressedInt(JCS_BinaryReader& reader);
		/**

		*/
		DECLSPEC_ACTION static wchar_t* ReadDecodedString(JCS_BinaryReader& reader);
		/**

		*/
		DECLSPEC_ACTION static wchar_t* ReadDecodedStringAtOffset(JCS_BinaryReader& reader, long32 offset);
		/**

		*/
		DECLSPEC_ACTION static wchar_t* ReadDecodedStringAtOffsetAndReset(JCS_BinaryReader& reader, long32 offset);
		/**

		*/
		DECLSPEC_ACTION static wchar_t* ReadDecodedStringAtOffsetAndReset(JCS_BinaryReader& reader, long32 offset, bool flag);
#else
		/**
			Return the binary into string until the string is null.

			@param Binary going to analysis into char.
		*/
		DECLSPEC_ACTION static char* ReadNullTerminatedString(JCS_BinaryReader& reader);
		/**

		*/
		DECLSPEC_ACTION static int32 GetCompressedIntLength(int32 i);
		/**

		*/
		DECLSPEC_ACTION static int32 GetEncodedStringLength(char* ws);
		/**

		*/
		DECLSPEC_ACTION static int32 ReadCompressedInt(JCS_BinaryReader& reader);
		/**

		*/
		DECLSPEC_ACTION static char* ReadDecodedString(JCS_BinaryReader& reader);
		/**

		*/
		DECLSPEC_ACTION static char* ReadDecodedStringAtOffset(JCS_BinaryReader& reader, long32 offset);
		/**

		*/
		DECLSPEC_ACTION static char* ReadDecodedStringAtOffsetAndReset(JCS_BinaryReader& reader, long32 offset);
		/**

		*/
		DECLSPEC_ACTION static char* ReadDecodedStringAtOffsetAndReset(JCS_BinaryReader& reader, long32 offset, bool flag);

#endif // _UNICODE

		/**

		*/
		DECLSPEC_ACTION static void WriteCompressedInt();
		/**

		*/
		DECLSPEC_ACTION static void WriteEncodedString(JCS_BinaryWriter& writer);
		/**

		*/
		DECLSPEC_ACTION static void WriteNullTerminatedString(JCS_BinaryWriter& writer);


		/** setter **/

		/** getter **/
	};

}

typedef JcsLib::JcsTools JcsTools;

EXTERN_C_END

#endif // __JCSTOOLS_H__
