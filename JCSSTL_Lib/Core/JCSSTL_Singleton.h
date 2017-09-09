#ifndef __JCSSTL_SINGLETON_H__
/**
 * $File: JCSSTL_Singleton.h $
 * $Date: 2016-11-22 22:04:31 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCSSTL_SINGLETON_H__


#include "../JCSSTL_Lib_StdAfx.h"

namespace JCSSTL
{

	//====================================================================================
	// Name : JCSSTL_Singleton 
	//
	// Description : Singleton JCS Template class.
	//====================================================================================
	template <class T>
	class JCSSTL_Singleton
	{
	protected:
		// singleton instance pointer
		static T* s_pSingleton;

	public:
		/**
		@brief Override destructor.
		*/
		virtual ~JCSSTL_Singleton() { }

		/**
		@brief Get the instance memory.

		@return Return instance memory.
		*/
		static T* GetInstance()
		{
			if (!s_pSingleton)
				s_pSingleton = new T;
			return s_pSingleton;
		}

		/**
		@brief Destroy instance memory.
		*/
		static void DestroyInstance()
		{
			// safe delete the object.
			SafeDeleteObject(s_pSingleton);
		}

	private:
		T& operator=(const JCSSTL_Singleton& right) = delete;

	};

	template <class T>
	T* JCSSTL_Singleton<T>::s_pSingleton = nullptr;
}

#endif // __JCSSTL_SINGLETON_H__
