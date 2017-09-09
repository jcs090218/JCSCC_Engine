#ifndef __JCS_DIRECTORY_H__
/**
 * $File: JcsDirectory.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_DIRECTORY_H__


#include "IJcsObject.h"
#include "JcsImage.h"

EXTERN_C_BEGIN

namespace JcsLib
{

	/**
	@class JcsDirectory
	@brief 
	*/
	class JcsDirectory
	{
	private:
		uint32 m_blockStartOffset;
		int32 m_checksum;
		int32 m_hash;
		uint32 m_headerOffsetOffset;
		std::list<JcsImage> m_images;
		std::string m_name;
		uint32 m_offset;
		int32 m_offsetSize;
		IJcsObject m_parent;
		std::list<JcsDirectory> m_subDirs;
		//BinaryReader m_jcsReader;

	public:
		JcsDirectory();
		virtual ~JcsDirectory();


		/** setter **/

		/** getter **/

	};

}

EXTERN_C_END

#endif // __JCS_DIRECTORY_H__
