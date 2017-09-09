#ifndef __JCS_WSTRING_H__
/**
* $File: JCS_WString.h $
* $Date: 2017-03-13 23:46:00 $
* $Revision: $
* $Creator: Jen-Chieh Shen $
* $Notice: See LICENSE.txt for modification and distribution information
*                   Copyright (c) 2017 by Shen, Jen-Chieh $
*/
#define __JCS_WSTRING_H__

#include <sstream>


namespace JayCeS
{

	/**
	 * @class JCS_WString
	 * @brief Wide string, wide char array, wide char pointer 
	 */
	class JCS_WString
	{
	public:
		JCS_WString();
		virtual ~JCS_WString();

		/**
		 * @func CharArrayCat
		 * @brief Concatenate two wide char array.
		 * @param src : source of you want to add ontop of dest.
		 * @param dest : final result you want.
		 * @param size : size of the target buffer.
		 */
		static void WCharArrayCat(wchar_t src[], wchar_t dest[], uint32 size);

		/**
		 * @func TypeNameToWString
		 * @brief Convert wide char pointer to wide char array
		 * by copying memory.
		 * @param src : source to
		 */
		static void WString_To_WCharArray(std::wstring& src, wchar_t (&dest)[JCS_MAX_STRING_LENGTH]);

		/**
		 * @func WString_To_WCharPointer
		 * @brief Convert wide string to wide char pointer.
		 * @param std::wstring& : wide string you want to convert with.
		 * @return wchar_t* : result.
		 */
		static wchar_t* WString_To_WCharPtr(std::wstring& src);

		/**
		 * @func WCharPtr_To_WString
		 * @brief Convert wide char pointer to wide string.
		 * @param wchar_t* : wide char pointer
		 * @param std::wstring& : reference of the wide string class (C-Standard).
		 */
		static void WCharPtr_To_WString(wchar_t* wPtr, std::wstring& wStr);

		/**
		 * @func TypeNameToWString
		 * @brief Type name to wide string.
		 * @param val : type name.
		 * @return std::wstring : wide string.
		 */
		template<typename T>
		static std::wstring TypeNameToWString(const T& val)
		{
			std::wstringstream ss;
			ss << val;
			return ss.str();
		}

		/**
		 * @func TypeNameToWCharPtr
		 * @brief Type name to wide char pointer.
		 * @param val : type name.
		 * @return wchar_t* : wide char pointer.
		 */
		template<typename T>
		static wchar_t* TypeNameToWCharPtr(const T& val)
		{
			std::wstringstream ss;
			ss << val;

			std::wstring wideString = ss.str();

			// convert 'const wchar_t*' to 'wchar_t*'
			wchar_t* wideCharPtr = const_cast<wchar_t*>(wideString.c_str());

			return wideCharPtr;
		}

		/* setter */

		/* getter */

	};
}

typedef JayCeS::JCS_WString JCS_WString;

#endif /* __JCS_WSTRING_H__ */
