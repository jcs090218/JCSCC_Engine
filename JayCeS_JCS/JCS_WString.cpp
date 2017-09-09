/**
* $File: JCS_WString.cpp $
* $Date: 2017-03-13 23:46:02 $
* $Revision: $
* $Creator: Jen-Chieh Shen $
* $Notice: See LICENSE.txt for modification and distribution information
*                   Copyright (c) 2017 by Shen, Jen-Chieh $
*/

#include "JayCeS.h"



namespace JayCeS
{

	JCS_WString::JCS_WString()
	{

	}

	JCS_WString::~JCS_WString()
	{

	}

	// Concatenate two wide char array.
	void JCS_WString::WCharArrayCat(wchar_t src[], wchar_t dest[], uint32 size)
	{
		wcscat_s(dest, size, src);
	}

	// Convert wide char pointer to wide char array by copying memory.
	void JCS_WString::WString_To_WCharArray(std::wstring& src, wchar_t (&dest)[JCS_MAX_STRING_LENGTH])
	{
		wcsncpy_s(dest, src.c_str(), sizeof(src));
	}

	// Convert wide string to wide char pointer.
	wchar_t* JCS_WString::WString_To_WCharPtr(std::wstring& src)
	{
		return const_cast<wchar_t*>(src.c_str());
	}

	// Convert wide char pointer to wide string.
	void JCS_WString::WCharPtr_To_WString(wchar_t* wPtr, std::wstring& wStr)
	{
		// simple conversion.
		wStr = wPtr;
	}

}
