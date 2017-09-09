/**
 * $File: JCS_Circle.cpp $
 * $Date: 2016-12-01 13:31:15 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "../../../JCSMath_Lib.h"

EXTERN_C_BEGIN

namespace JCSMath_Lib
{

	JCS_Circle::JCS_Circle()
	{

	}

	JCS_Circle::JCS_Circle(
		const float32 x,
		const float32 y,
		const float32 radius)
		: m_radius(radius)
	{

	}

	JCS_Circle::~JCS_Circle()
	{

	}

}

EXTERN_C_END
