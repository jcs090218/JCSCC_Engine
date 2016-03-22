#include "Rectangle2D.h"

#include "Physics2D.h"

#include "Circle2D.h"
#include "Capsule2D.h"
#include "Hexagon2D.h"
#include "Polygon2D.h"
#include "Triangle2D.h"

namespace JCS_D2DEngine
{

	Rectangle2D::Rectangle2D(float32 x, float32 y, float32 width, float32 height,
		Graphics2D& gfx, bool autoPivot)
		: Shape2D(gfx, autoPivot)
        , width(width)
		, height(height)
	{
		this->position->x = x;
		this->position->y = y;

		if (auto_pivot) {		// 自動設置位置到中心點
			this->offsetPivot->x = width / 2.0f;
			this->offsetPivot->y = height / 2.0f;
		}

		resetRotation();
	}

	Rectangle2D::Rectangle2D(float32 width, float32 height, Graphics2D& gfx, bool autoPivot)
		: Shape2D(gfx)
	{
		if (auto_pivot) {		// 自動設置位置到中心點
			this->offsetPivot->x = width / 2.0f;
			this->offsetPivot->y = height / 2.0f;
		}

		resetRotation();
	}

	Rectangle2D::~Rectangle2D()
	{
		
	}

	void Rectangle2D::initialize()
	{
		
	}

	void Rectangle2D::update(const float32 gameTime)
	{
		Shape2D::update(gameTime);

		if (velocity->x != 0.0f) 
		{
			float speedX = velocity->x * gameTime;
			p1.x += speedX;
			p2.x += speedX;
			p3.x += speedX;
			p4.x += speedX;
		}

		if (velocity->y != 0.0f) 
		{
			float speedY = velocity->y * gameTime;
			p1.y += speedY;
			p2.y += speedY;
			p3.y += speedY;
			p4.y += speedY;
		}

	}

	void Rectangle2D::draw()
	{
        gDevice2D.drawRectangleWithLine(p1, p2, p3, p4);
	}

	// 找出右邊邊界
	float32 Rectangle2D::getRightEdge()
	{
		if (this->position->x < this->p3.x)
			return getRenderPosX() + this->width;
		else 
			return getRenderPosX();
	}
	// 找出左邊邊界
	float32 Rectangle2D::getLeftEdge()
	{
		if (this->position->x > this->p3.x)
			return getRenderPosX() + this->width;
		else 
			return getRenderPosX();
	}
	// 找出下面邊界
	float32 Rectangle2D::getBottomEdge()
	{
		if (this->position->y < this->p3.y)
			return getRenderPosY() + this->height;
		else 
			return getRenderPosY();
	}
	// 找出上面邊界
	float32 Rectangle2D::getTopEdge()
	{
		if (this->position->y > this->p3.y)
			return getRenderPosY() + this->height;
		else
			return getRenderPosY();
	}

	void Rectangle2D::resetRotation(const float32 angle)
	{
		// 找出正確的 "X" 和 "Y" 坐標
		p1.x = getRenderPosX();						// 左上
		p1.y = getRenderPosY();

		p2.x = getRenderPosX();						// 左下
		p2.y = getRenderPosY() + height;

		p3.x = getRenderPosX() + width;				// 右下
		p3.y = getRenderPosY() + height;

		p4.x = getRenderPosX() + width;				// 右上
		p4.y = getRenderPosY();
	}

	/**
	 * 旋轉形狀 (自轉 or 旋轉)
	 * Rotation Rotate Shape : https://zh.wikipedia.org/wiki/%E8%87%AA%E8%BD%AC
	 */
	void Rectangle2D::rotation_rotate(float32 angle)
	{
		setRotation(angle);

		if (this->rotation != 0.0f) 
		{
			float32 rotateCos = getRotationCosΘ();
			float32 rotateSin = getRotationSinΘ();

			p1 = IEMath2D::RotatePoint(p1, rotateCos, rotateSin, *position);
			p2 = IEMath2D::RotatePoint(p2, rotateCos, rotateSin, *position);
			p3 = IEMath2D::RotatePoint(p3, rotateCos, rotateSin, *position);
			p4 = IEMath2D::RotatePoint(p4, rotateCos, rotateSin, *position);
		}

	}

	/**
	 * 繞轉形狀 (公轉 or 繞轉)
	 * Revolution Rotate Shape : https://zh.wikipedia.org/wiki/%E5%85%AC%E8%BD%AC
	 */
	void Rectangle2D::revolution_rotate(GameObject2D& target, float32 angle)
	{
		if (&target == nullptr) 
		{
			throw GameError(L"Rectangle2D::(177):: - Target equals to nullptr...");
			return;
		}

		setRevolution(angle);

		if (this->revolution != 0.0f) 
		{
			JCS_VECTOR2F temp = IEMath2D::RotatePoint(*position, getRevolutionCosΘ(), getRevolutionSinΘ(), *target.position);

			// 移動量 = 移動後 - 移動前
			float tempMoveX = temp.x - position->x;
			float tempMoveY = temp.y - position->y;

			if (tempMoveX != 0.0f) 
			{
				p1.x += tempMoveX; p2.x += tempMoveX;
				p3.x += tempMoveX; p4.x += tempMoveX;
			}

			if (tempMoveY != 0.0f) 
			{
				p1.y += tempMoveY; p2.y += tempMoveY;
				p3.y += tempMoveY; p4.y += tempMoveY;
			}

			*position = temp;
		}
	}

	void Rectangle2D::setPosition(const float32 x, const float32 y)
	{
		if (position->x != x) this->position->x = x;
		if (position->y != y) this->position->y = y;

		resetRotation();
	}

	//////////////////////////////////////////////////////////////////////////////////
	////-- Basic Collision
	//////////////////////////////////////////////////////////////////////////////////
	/**
	 * "矩形"和"矩形"的碰撞測試
	 */
	bool Rectangle2D::RectangletoRectangle(Rectangle2D& obj)
	{
		if (obj.getAutoPivot() && this->getAutoPivot()) 
		{
			if (IEMath2D::DistanceOfUnitVector(position->x, obj.position->x) <= this->getWidth() / 2 + obj.getWidth() / 2 &&
				IEMath2D::DistanceOfUnitVector(position->y, obj.position->y) <= this->getHeight() / 2 + obj.getHeight() / 2)
			{
				return true;
			}
		}
		else if (!obj.getAutoPivot() && !this->getAutoPivot())
		{
			JCS_VECTOR2F thisTempOrigin(this->position->x + (this->getWidth() / 2), this->position->y + (this->getHeight() / 2));
			JCS_VECTOR2F tempOrigin(obj.position->x + (obj.getWidth() / 2), obj.position->y + (obj.getHeight() / 2));

			if (IEMath2D::DistanceOfUnitVector(thisTempOrigin.x, tempOrigin.x) <= this->getWidth() / 2 + obj.getWidth() / 2 &&
				IEMath2D::DistanceOfUnitVector(thisTempOrigin.y, tempOrigin.y) <= this->getHeight() / 2 + obj.getHeight() / 2)
			{
				return true;
			}
		}
		else if (!obj.getAutoPivot() && this->getAutoPivot())
		{
			JCS_VECTOR2F tempOrigin(obj.position->x + (obj.getWidth() / 2), obj.position->y + (obj.getHeight() / 2));

			if (IEMath2D::DistanceOfUnitVector(position->x, tempOrigin.x) <= this->getWidth() / 2 + obj.getWidth() / 2 &&
				IEMath2D::DistanceOfUnitVector(position->y, tempOrigin.y) <= this->getHeight() / 2 + obj.getHeight() / 2)
			{
				return true;
			}
		}
		else if (obj.getAutoPivot() && !this->getAutoPivot())
		{
			JCS_VECTOR2F thisTempOrigin(this->position->x + (this->getWidth() / 2), this->position->y + (this->getHeight() / 2));

			if (IEMath2D::DistanceOfUnitVector(thisTempOrigin.x, obj.position->x) <= this->getWidth() / 2 + obj.getWidth() / 2 &&
				IEMath2D::DistanceOfUnitVector(thisTempOrigin.y, obj.position->y) <= this->getHeight() / 2 + obj.getHeight() / 2)
			{
				return true;
			}
		}

		return false;
	}
	/**
	 * "矩形"和"圓形"的碰撞測試
	 */
	bool Rectangle2D::RectangletoCircle(Circle2D& obj)
	{
		if (this->getAutoPivot()) {
			// 算出"對角線"的長度, 並除以二
			float tempRadius = (IEMath2D::DistanceBetweenPoint(p3, p1) / 2);

			if (IEMath2D::DistanceBetweenPoint(*position, *obj.position) <= 
				obj.getRadius() + tempRadius) 
			{

				if (IEMath2D::DistanceOfUnitVector(position->x, obj.position->x) <=
					obj.getRadius() + (this->getWidth() / 2) && 
					IEMath2D::DistanceOfUnitVector(position->y, obj.position->y) <=
					obj.getRadius() + (this->getHeight() / 2)) 
				{
					return true;
				}
				
			}
		}
		// 沒有AutoPivot的情況
		else {
			// 算出"對角線"的長度, 並除以二
			float tempRadius = (IEMath2D::DistanceBetweenPoint(p3, p1) / 2);

			// 找出中心點
			JCS_VECTOR2F tempOrigin(this->position->x + (getWidth() / 2), this->position->y + (getHeight() / 2));

			if (IEMath2D::DistanceBetweenPoint(tempOrigin, *obj.position) <=
				obj.getRadius() + tempRadius) 
			{
				if (IEMath2D::DistanceOfUnitVector(tempOrigin.x, obj.position->x) <=
					obj.getRadius() + (this->getWidth() / 2) && 
					IEMath2D::DistanceOfUnitVector(tempOrigin.y, obj.position->y) <=
					obj.getRadius() + (this->getHeight() / 2))
				{
					return true;
				}
			}
		}

		return false;
	}
	/**
	 * "矩形"和"膠囊狀"的碰撞測試
	 */
	bool Rectangle2D::RectangletoCapsule(Capsule2D& obj)
	{
		if (this->getAutoPivot())
		{
			// 算出"對角線"的長度, 並除以二
			float tempRadius = (IEMath2D::DistanceBetweenPoint(this->p3, this->p1) / 2);

			float tempCollideDistance = obj.getRadius() + tempRadius;
			if (IEMath2D::DistanceBetweenPoint(obj.topCircle, *this->position) <= tempCollideDistance ||
				IEMath2D::DistanceBetweenPoint(obj.botCircle, *this->position) <= tempCollideDistance)
			{

				if (IEMath2D::DistanceOfUnitVector(this->position->x, obj.position->x) <= 
					(obj.getRadius() + (this->getWidth() / 2)) &&
					IEMath2D::DistanceOfUnitVector(this->position->y, obj.position->y) <= 
					(((obj.getHeight() / 2) + obj.getRadius()) + (this->getHeight() / 2)))
				{
					return true;
				}
			}
		}
		// 沒有AutoPivot的情況
		else {
			// 算出"對角線"的長度, 並除以二
			float tempRadius = (IEMath2D::DistanceBetweenPoint(this->p3, this->p1) / 2);

			// 找出中心點, 因為並沒有自行設置中心
			JCS_VECTOR2F tempOrigin(
				this->position->x + (this->getWidth() / 2),
				this->position->y + (this->getHeight() / 2));

			float tempCollideDistance = obj.getRadius() + tempRadius;
			if (IEMath2D::DistanceBetweenPoint(obj.topCircle, tempOrigin) <= tempCollideDistance ||
				IEMath2D::DistanceBetweenPoint(obj.botCircle, tempOrigin) <= tempCollideDistance)
			{

				if (IEMath2D::DistanceOfUnitVector(obj.position->x, tempOrigin.x) <=
					(obj.getRadius() + (this->getWidth() / 2)) &&
					IEMath2D::DistanceOfUnitVector(obj.position->y, tempOrigin.y) <=
					(((obj.getHeight() / 2) + obj.getRadius()) + (this->getHeight() / 2)))
				{
					return true;
				}
			}
		}

		return false;
	}
	/**
	 * 
	 */
	bool Rectangle2D::RectangletoPolygon(Polygon2D& obj)
	{
		return false;
	}

}

