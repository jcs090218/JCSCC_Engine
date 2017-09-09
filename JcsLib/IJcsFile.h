#ifndef __IJCSFILE_H__
/**
 * $File: IJcsFile.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __IJCSFILE_H__

#include "IJcsObject.h"
#include "IDisposable.h"

EXTERN_C_BEGIN

namespace JcsLib
{

	/**
	@class IJcsFile (Interface)
	@brief
	*/
	struct IJcsFile
		: public IJcsObject
	{
		DECLSPEC_ACTION virtual ~IJcsFile() { }
	};
}

typedef JcsLib::IJcsFile IJcsFile;

EXTERN_C_END

#endif // __IJCSFILE_H__
