/**
 * $File: JcsImage.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "JcsImage.h"

#include "IJcsImageProperty.h"

EXTERN_C_BEGIN

namespace JcsLib
{

	JcsImage::JcsImage()
		: m_checksum(0)
		, m_headerOffset(0)
		, m_offset(0)
		, m_parsed(false)
		, m_properties()
		, m_size(-1)
	{

	}

	JcsImage::JcsImage(wchar_t* name)
		: m_checksum(0)
		, m_headerOffset(0)
		, m_offset(0)
		, m_parsed(false)
		, m_properties()
		, m_size(-1)
	{
		// m_name is at "IJcsObject"
		m_name = name;
	}

	JcsImage::~JcsImage()
	{

	}

	// Clone property.
	JcsImage* JcsImage::Clone()
	{
		return nullptr;
	}

	// Add property to current property value.
	void JcsImage::AddProperty(IJcsImageProperty prop)
	{

	}

	// Dispose property.
	void JcsImage::Dispose()
	{

	}

	// Dump the whole block.
	std::wstring JcsImage::DumpBlock()
	{
		return L"";
	}

	// Parse the image file into readable/showable style.
	void JcsImage::ParseImage()
	{

	}

	// Remove the property form current node system.
	void JcsImage::RemoveProperty(wchar_t* name)
	{

	}

	// Save image function design here.
	void JcsImage::SaveImage(/*BinaryWriter jcsWriter*/)
	{

	}

}

EXTERN_C_END
