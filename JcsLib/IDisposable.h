#ifndef __IDISPOSABLE_H__
/**
 * $File: IDisposable.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __IDISPOSABLE_H__

#include "JcsLib_StdAfx.h"

EXTERN_C_BEGIN

namespace JcsLib
{

	/**
	@class IDisposable (Interface) 
	@brif Performs application - defined tasks 
	associated with freeing, releasing, or 
	resetting unmanaged resources.
	*/
	struct IDisposable
	{
		DECLSPEC_ACTION virtual ~IDisposable() { }

		// must override function
		DECLSPEC_ACTION virtual void Dispose() = 0;
	};

}

typedef JcsLib::IDisposable IDisposable;

EXTERN_C_END

#endif // __IDISPOSABLE_H__
