#ifndef __JCSKEY_H__
/**
 * $File: JcsKey.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCSKEY_H__


#include "JcsLib_StdAfx.h"

EXTERN_C_BEGIN

namespace JcsLib
{

	/**
	@class JcsKey
	@brief Key Constant listed here.
	*/
    struct JcsKey
    {
		/** file version key length **/
		DECLSPEC_ACTION static const uint32 jcs_key_file_v01_num = 65535;
		DECLSPEC_ACTION static const uint32 jcs_key_file_v02_num = 26076;

		/** file version key **/
		DECLSPEC_ACTION static byte jcs_key_file_v01[jcs_key_file_v01_num];
		DECLSPEC_ACTION static byte jcs_key_file_v02[jcs_key_file_v02_num];

    };
    
}

EXTERN_C_END

#endif // __JCSKEY_H__
