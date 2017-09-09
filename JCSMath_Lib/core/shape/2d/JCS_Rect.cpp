/**
 * $File: JCS_Rect.cpp $
 * $Date: 2016-12-01 13:43:02 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "../../../JCSMath_Lib.h"

EXTERN_C_BEGIN

namespace JCSMath_Lib
{

    JCS_Rect::JCS_Rect()
    {

    }

	JCS_Rect::JCS_Rect(
		const float32 x, 
		const float32 y, 
		const float32 width, 
		const float32 height)
		: m_width(width)
		, m_height(height)
	{

	}

    JCS_Rect::~JCS_Rect()
    {

    }

}

EXTERN_C_END
