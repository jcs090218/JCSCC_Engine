#ifndef __JCSFILE_H__
/**
 * $File: JcsFile.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCSFILE_H__


#include "JcsLib_StdAfx.h"

#include "IJcsFile.h"
#include "JcsVersion.h"
#include "JcsDirectory.h"
#include "JcsTools.h"

EXTERN_C_BEGIN

namespace JcsLib
{
	class JcsDirectory;

	/**
	@class JcsFile
	@brief File structure of game resources design here.
	*/
	class JcsFile
		: public IJcsFile
	{
	private:
		wchar_t* m_copyright;       // copy right check.
		byte m_fileVersion;         // version of jcs format file.
		uint64 m_fsize;             // file size
		uint32 m_fstart;            // file starting binary
		wchar_t* m_ident;           // file ident
		wchar_t* m_name;            // file name
		wchar_t* m_path;            // file path
		JcsVersion m_type;          // verion type of this file.
		uint16 m_version;           // version number
		int32 m_versionHash;        // version hash number.
		JcsDirectory m_jcsDir;      // jcs file format directory.

	public:
		DECLSPEC_ACTION JcsFile(JcsVersion version);
		DECLSPEC_ACTION JcsFile(wchar_t* filePath, JcsVersion version);
		virtual ~JcsFile();

		/**
			Parse the jcs format file.
		*/
		DECLSPEC_ACTION void ParseJcsFile();
		/**
			Parse the root of jcs format file.
		*/
		DECLSPEC_ACTION void ParseMainJcsDirectory();

		/** setter **/

		/** getter **/

	};

}

typedef JcsLib::JcsFile JcsFile;

EXTERN_C_END

#endif // __JCSFILE_H__

