#ifndef __RECTANGLE2D_H__
#define __RECTANGLE2D_H__

#include "D2D_StdAfx.h"

#include "Shape2D.h"

namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Rectangle2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
	class Rectangle2D 
        : public Shape2D
	{
	private:
        JCS_VECTOR2F p1, p2, p3, p4;		// 矩形的4個頂點
        float32 width, height;

	public:
		Rectangle2D(float32 x, float32 y, float32 width, float32 height,
			Graphics2D& gfx, bool autoPivot = true);
		Rectangle2D(float32 width, float32 height, 
            Graphics2D& gfx, bool autoPivot = false);
		virtual ~Rectangle2D();

		virtual void initialize() override;
		virtual void update(const float32 gameTime) override;
		virtual void draw() override;

		virtual void rotation_rotate(float32 angle = 1.0f) override;
		virtual void revolution_rotate(GameObject2D& target, float32 angle = 1.0f) override;

		// -- Basic Collision
		bool RectangletoRectangle(Rectangle2D& obj);
		bool RectangletoCircle(Circle2D& obj);
		bool RectangletoCapsule(Capsule2D& obj);
		bool RectangletoPolygon(Polygon2D& obj);

		// setter
		void setPosition(const float32 x, const float32 y);
		void resetRotation(const float32 angle = 0.0f);
		void setWidth(float32 newWidth) { this->width = newWidth; }
		void setHeight(float32 newHeight) { this->height = newHeight; }
		void setRightEdge(float32 num);
		void setLeftEdge(float32 num);
		void setBottomEdge(float32 num);
		void setTopEdge(float32 num);

		// getter
		float32 getWidth() { return this->width; }
		float32 getHeight() { return this->height; }
		float32 getRightEdge();
		float32 getLeftEdge();
		float32 getBottomEdge();
		float32 getTopEdge();
        JCS_VECTOR2F getP1() { return this->p1; }
        JCS_VECTOR2F getP2() { return this->p2; }
        JCS_VECTOR2F getP3() { return this->p3; }
        JCS_VECTOR2F getP4() { return this->p4; }

	};
}

#endif // __RECTANGLE2D_H__

