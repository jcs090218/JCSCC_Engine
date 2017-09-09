#ifndef __JCSIMAGE_H__
/**
 * $File: JcsImage.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCSIMAGE_H__


#include "JcsLib_StdAfx.h"

#include "IJcsObject.h"

EXTERN_C_BEGIN

namespace JcsLib
{
	class IJcsImageProperty;

	/**
	@class JcsImage (Data Type)
	@briefImage Data type.
	*/
	class JcsImage
		: public IJcsObject
	{
	private:
		int32 m_checksum;   // sum of the image property.
		uint32 m_headerOffset;  // offset of the header.
		uint32 m_offset;    // normal image offset.
		bool m_parsed;  // trigger prase the property or not.
		// list of the property in current node.
		std::list<IJcsImageProperty*> m_properties;
		int32 m_size;       // size of the property node.

	public:
		DECLSPEC_ACTION JcsImage();
		DECLSPEC_ACTION JcsImage(wchar_t* name);
		DECLSPEC_ACTION virtual  ~JcsImage();

		/**
			Clone property.
		*/
		DECLSPEC_ACTION JcsImage* Clone();
		/**
			Add property to current property value.

			@param property to add.
		*/
		DECLSPEC_ACTION void AddProperty(IJcsImageProperty prop);
		/**
			Dispose property.
		*/
		DECLSPEC_ACTION void Dispose();
		/**
			Dump the whole block.
		*/
		DECLSPEC_ACTION std::wstring DumpBlock();
		/**
			Prase the image file into readable/showable style.
		*/
		DECLSPEC_ACTION void ParseImage();
		/**
			Remove the property form current node system.

			@param name of the property to remove.
		*/
		DECLSPEC_ACTION void RemoveProperty(wchar_t* name);
		/**
			Save image function design here.

			@param binary writer to do the parsing part of job.
		*/
		DECLSPEC_ACTION void SaveImage(/*BinaryWriter jcsWriter*/);


		/** setter **/
		/** set the size of this property. */
		DECLSPEC_ACTION void SetSize(const int32 size) { this->m_size = size; }
		/** set the sum of this property. */
		DECLSPEC_ACTION void SetChecksum(const int32 checksum) { this->m_checksum = checksum; }

		/** getter **/
		/** get the size of the Image. */
		DECLSPEC_ACTION int32 GetSize() const { return this->m_size; }
		/** check the style and format. */
		DECLSPEC_ACTION int32 GetChecksum() const { return this->m_checksum; }

	};

}

EXTERN_C_END

#endif // __JCSIMAGE_H__
