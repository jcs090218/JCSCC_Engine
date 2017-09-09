#ifndef __JCS_RECT_H__
/**
 * $File: JCS_Rect.h $
 * $Date: 2016-12-01 13:43:00 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_RECT_H__


#include "../../../JCSMath_Lib_StdAfx.h"

EXTERN_C_BEGIN

namespace JCSMath_Lib
{

	/**
	@class JCS_Rect
	@brief rect struct
	*/
    class JCS_Rect
    {
    private:
		JCS_VECTOR2F m_position = JCS_VECTOR2F::ZERO;
        float32 m_width = 0;
		float32 m_height = 0;

    public:
        JCS_Rect();
		JCS_Rect(
			const float32 x, 
			const float32 y, 
			const float32 width, 
			const float32 height);
        virtual ~JCS_Rect();

        /** setter **/
		void SetPosition(const JCS_VECTOR2F val) { this->m_position = val; }
		void SetX(const float32 val) { this->m_position.x = val; }
		void SetY(const float32 val) { this->m_position.y = val; }
		void SetWidth(const float32 val) { this->m_width = val; }
		void SetHeight(const float32 val) { this->m_height = val; }

        /** getter **/
		JCS_VECTOR2F GetPosition() const { return this->m_position; }
		float32 GetX() const { return this->m_position.x; }
		float32 GetY() const { return this->m_position.y; }
		float32 GetWidth() const { return this->m_width; }
		float32 GetHeight() const { return this->m_height; }
    };
}

typedef JCSMath_Lib::JCS_Rect JCS_Rect;

EXTERN_C_END

#endif // __JCS_RECT_H__
