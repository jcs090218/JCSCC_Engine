/**
 * $File: JcsNullProperty.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "JcsNullProperty.h"

EXTERN_C_BEGIN

namespace JcsLib
{

	JcsNullProperty::JcsNullProperty(wchar_t* propName /*= nullptr*/)
	{
		SetName(propName);
		SetObjectType(JcsObjectType::PROPERTY);
	}

	JcsNullProperty::~JcsNullProperty()
	{
		Dispose();
	}

	// Override dispose function.
	void JcsNullProperty::Dispose()
	{
		m_name = nullptr;
	}

}

EXTERN_C_END
