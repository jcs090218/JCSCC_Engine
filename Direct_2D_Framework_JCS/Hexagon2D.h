/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D2D_HEXAGON2D_H__
#define __D2D_HEXAGON2D_H__

#include "Shape2D.h"

namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Hexagon2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
	class Hexagon2D 
        : public Shape2D
	{
	private:
		// type false for "Horizontal Hexagon" true for "Vertical Hexagon"
		bool m_type;
		float32 m_size;
		JCS_VECTOR2F m_p0, m_p1, m_p2, m_p3, m_p4, m_p5;

	public:
		Hexagon2D(float32 size, Graphics2D& gfx, bool type = false, bool autoPivot = true);
		virtual ~Hexagon2D();

		virtual void initialize() override;
		virtual void update(const float32 deltaTime) override;
		virtual void draw() override;

		virtual void rotation_rotate(float32 float32 = 1.0f) override;
		virtual void revolution_rotate(GameObject2D& target, float32 angle = 1.0f) override;

		// setter
		void setM_type(bool value);
		void setM_size(float32 value);

		// getter
		bool getM_type() { return this->m_type; }
		float32 getM_size() { return this->m_size; }


	private:
		JCS_VECTOR2F hex_corner(float32 size, int orderOfPoint);

	};

}

#endif // __D2D_HEXAGON2D_H__

