/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D2D_CIRCLE2D_H__
#define __D2D_CIRCLE2D_H__

#include "Shape2D.h"


namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Circle2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
	class Circle2D 
        : public Shape2D
	{
	private:
        float32 radius;

#ifdef _JCS_DEBUG_2D
		JCS_GameTool::JCS_VECTOR2F orient_point;
#endif

	public:
		Circle2D(float32 radius, Graphics2D& gfx, bool autoPivot = true);
		virtual ~Circle2D();

		virtual void initialize() override;
		virtual void update(const float32 deltaTime) override;
		virtual void draw() override;

		void ComputeMass(float32 density = 1.0f);
		void SetOrient(float32 radians);

		void rotation_rotate(float32 angle = 1.0f);
		void revolution_rotate(GameObject2D& target, float32 angle = 1.0f);

		// -- Basic Collision
		bool CircletoCircle(Circle2D& obj);
		bool CircletoRectangle(Rectangle2D& obj);
		bool CircletoCapsule(Capsule2D& obj);
		bool CircletoPolygon(Polygon2D& obj);

		// setter 
		void resetRotation(const float32 angle = 0.0f);
		void setPosition(const float32 x, const float32 y);
		void setRadius(float32 newRadius) { this->radius = newRadius; }

		// getter
		float32 getRadius() { return this->radius; }

	};

}

#endif // __D2D_CIRCLE2D_H__

