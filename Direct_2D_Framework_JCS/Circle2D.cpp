/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Circle2D.h"

#include "Capsule2D.h"
#include "Hexagon2D.h"
#include "Rectangle2D.h"
#include "Polygon2D.h"
#include "Triangle2D.h"

namespace JCS_D2DEngine
{
	Circle2D::Circle2D(float32 radius, Graphics2D& gfx, bool autoPivot)
		: radius(radius)
		, Shape2D(gfx, autoPivot)
	{
		if (auto_pivot) // 自動設置位置到中心點
        {
			this->offsetPivot->x = radius;
			this->offsetPivot->y = radius;
		}

		resetRotation();
	}


	Circle2D::~Circle2D()
	{
		
	}

	void Circle2D::initialize()
	{
		
	}

	void Circle2D::update(const float32 deltaTime)
	{
		Shape2D::update(deltaTime);

#ifdef _JCS_DEBUG_2D
		if (velocity->x != 0.0f) 
		{
			float speedX = velocity->x * deltaTime;
			orient_point.x += speedX;
		}
		if (velocity->y != 0.0f) 
		{
			float speedY = velocity->y * deltaTime;
			orient_point.y += speedY;
		}
#endif
	}

	void Circle2D::draw()
	{
	    gDevice2D.drawCircle(position->x, position->y, radius);

#ifdef _JCS_DEBUG_2D
		// Draw Orient Line
		gDevice2D.drawLine(*position, orient_point);
#endif
	}

	void Circle2D::SetOrient(float32 radians)
	{  
		
	}

	/**
	* 旋轉形狀 (自轉 or 旋轉)
	* Rotation Rotate Shape
	*/
	void Circle2D::rotation_rotate(float32 angle)
	{
		setRotation(angle);

#ifdef _JCS_DEBUG_2D
		if (this->rotation != 0.0f) {
			orient_point = IEMath2D::RotatePoint(orient_point, getRotationCosΘ(), getRotationSinΘ(), *position);
		}
#endif
	}

	/**
	* 繞轉形狀 (公轉 or 繞轉)
	* Revolution Rotate Shape
	*/
	void Circle2D::revolution_rotate(GameObject2D& target, float32 angle)
	{
		if (&target == nullptr) 
		{
			throw GameError(L"Circle2D::revolution_rotate() - Target equals to nullptr...");
			return;
		}

		setRevolution(angle);

		if (this->revolution != 0.0f) {
			*position = IEMath2D::RotatePoint(*position, getRevolutionCosΘ(), getRevolutionSinΘ(), *target.position);
		}
	}

	void Circle2D::resetRotation(const float32 angle)
	{
#ifdef _JCS_DEBUG_2D
		orient_point.x = position->x + radius;
		orient_point.y = position->y;
#endif
	}

	void Circle2D::setPosition(const float32 x, const float32 y)
	{
		if (position->x != x) this->position->x = x;
		if (position->y != y) this->position->y = y;

		resetRotation();
	}

	//////////////////////////////////////////////////////////////////////////////////
	////-- Basic Collision
	//////////////////////////////////////////////////////////////////////////////////
	/**
	 * "圓圈"和"圓圈"的碰撞測試
	 */
	bool Circle2D::CircletoCircle(Circle2D& obj)
	{
		return (IEMath2D::DistanceBetweenPoint(*position, *obj.position) <=
			this->getRadius() + obj.getRadius());
	}
	/**
	 * "圓圈"和"矩形"的碰撞測試
	 */
	bool Circle2D::CircletoRectangle(Rectangle2D& obj)
	{
		if (obj.getAutoPivot()) {
			// 算出"對角線"的長度, 並除以二
			float tempRadius = (IEMath2D::DistanceBetweenPoint(obj.getP3(), obj.getP1()) / 2);
			
			// 測試是否碰撞"矩形的圓"(非自己)
			if (IEMath2D::DistanceBetweenPoint(*position, *obj.position) <= 
				this->getRadius() + tempRadius) 
			{
				// 如果圓內有碰撞, 就偵測矩形是否有碰撞
				if (IEMath2D::DistanceOfUnitVector(this->position->x, obj.position->x) <=
					this->getRadius() + (obj.getWidth() / 2) &&
					IEMath2D::DistanceOfUnitVector(this->position->y, obj.position->y) <=
					this->getRadius() + (obj.getHeight() / 2))
				{
					return true;
				}
			}

		}
		// 沒有AutoPivot的情況
		else {
			// 算出"對角線"的長度, 並除以二
            float tempRadius = (IEMath2D::DistanceBetweenPoint(obj.getP3(), obj.getP1()) / 2);

			// 找出中心點
			float halfOfRectWidth = obj.getWidth() / 2;
			float halfOfRectHeight = obj.getHeight() / 2;
			JCS_VECTOR2F tempDistance(
				obj.position->x + halfOfRectWidth,
				obj.position->y + halfOfRectHeight);

			// 用算出來對角線長度除以二當作半徑畫出一個圓, 並偵測看是否有碰撞
			if (IEMath2D::DistanceBetweenPoint(*position, tempDistance) <=
				this->getRadius() + tempRadius)
			{
				// 如果圓內有碰撞, 就偵測矩形是否有碰撞
				if (IEMath2D::DistanceOfUnitVector(this->position->x, tempDistance.x) <=
					this->getRadius() + halfOfRectWidth &&
					IEMath2D::DistanceOfUnitVector(this->position->y, tempDistance.y) <=
					this->getRadius() + halfOfRectHeight) {
					return true;
				}
			}
		}

		return false;
	}
	/**
	 * "圓圈"和"膠囊狀"的碰撞測試
	 */
	bool Circle2D::CircletoCapsule(Capsule2D& obj)
	{
		float tempX = IEMath2D::DistanceOfUnitVector(this->position->x, obj.position->x);

		if (tempX <= this->getRadius() + obj.getRadius()) 
		{
			float tempY = this->position->y - (obj.position->y - (obj.getHeight() / 2));
			if (IEMath2D::DistanceBetweenPoint(tempX, tempY) <= this->getRadius() + obj.getRadius()) {
				return true;
			}

			tempY = this->position->y - (obj.position->y + (obj.getHeight() / 2));
			if (IEMath2D::DistanceBetweenPoint(tempX, tempY) <= this->getRadius() + obj.getRadius()) {
				return true;
			}
		}

		return false;
	}
	/**
	 * "圓圈"和"矩形"的測試
	 */
	bool Circle2D::CircletoPolygon(Polygon2D& obj)
	{
		return false;
	}

}

