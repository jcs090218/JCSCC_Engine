#ifndef __JCS_CIRCLE_H__
/**
 * $File: JCS_Circle.h $
 * $Date: 2016-12-01 13:31:10 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_CIRCLE_H__

#include "../../../JCSMath_Lib_StdAfx.h"

EXTERN_C_BEGIN

namespace JCSMath_Lib
{

    /**
       @class JCS_Circle
       @brief Circle struct
    */
    class JCS_Circle
    {
    private:
		JCS_VECTOR2F m_position = JCS_VECTOR2F::ZERO;
		float32 m_radius = 0;

    public:
        JCS_Circle();
		JCS_Circle(
			const float32 x,
			const float32 y, 
			const float32 radius);
        virtual ~JCS_Circle();

        /** setter **/
		void SetPosition(const JCS_VECTOR2F val) { this->m_position = val; }
		void SetX(const float32 val) { this->m_position.x = val; }
		void SetY(const float32 val) { this->m_position.y = val; }
		void SetRadius(const float32 val) { this->m_radius = val; }

        /** getter **/
		JCS_VECTOR2F GetPosition() const { return this->m_position; }
		float32 GetX() const { return this->m_position.x; }
		float32 GetY() const { return this->m_position.y; }
		float32 GetRadius() const { return this->m_radius; }

    };
}

EXTERN_C_END

#endif // __JCS_CIRCLE_H__
