#ifndef __JCSNULLPROPERTY_H__
/**
 * $File: JcsNullProperty.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCSNULLPROPERTY_H__


#include "IJcsImageProperty.h"
#include "JcsObjectType.h"

EXTERN_C_BEGIN

namespace JcsLib
{

	/**
	@class JcsNullProperty
	@brief Property that are null node in Tree System.
	*/
	class JcsNullProperty
		: public IJcsImageProperty
	{
	public:
		DECLSPEC_ACTION JcsNullProperty(wchar_t* propName = nullptr);
		DECLSPEC_ACTION virtual ~JcsNullProperty();

		/**
			Override Dispose function.
		*/
		DECLSPEC_ACTION virtual void Dispose() override;
	};

}

EXTERN_C_END

#endif // __JCSNULLPROPERTY_H__
