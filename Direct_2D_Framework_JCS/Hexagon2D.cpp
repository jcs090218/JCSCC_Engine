#include "Hexagon2D.h"

#include "Capsule2D.h"
#include "Circle2D.h"
#include "Rectangle2D.h"
#include "Polygon2D.h"
#include "Triangle2D.h"

namespace JCS_D2DEngine
{
	Hexagon2D::Hexagon2D(float32 size, Graphics2D& gfx, bool type, bool autoPivot)
		: Shape2D(gfx, autoPivot)
		, m_size(size)
		, m_type(type)
	{

	}


	Hexagon2D::~Hexagon2D()
	{
		
	}

	void Hexagon2D::initialize()
	{
		// Calculate angle and set point to the correct position
		m_p0 = hex_corner(m_size, 0);
		m_p1 = hex_corner(m_size, 1);
		m_p2 = hex_corner(m_size, 2);
		m_p3 = hex_corner(m_size, 3);
		m_p4 = hex_corner(m_size, 4);
		m_p5 = hex_corner(m_size, 5);
	}

	void Hexagon2D::update(const float32 gameTime)
	{
		Shape2D::update(gameTime);

		if (velocity->x != 0.0f)
		{
			float speedX = velocity->x * gameTime;
			m_p0.x += speedX; m_p1.x += speedX;
			m_p2.x += speedX; m_p3.x += speedX;
			m_p4.x += speedX; m_p5.x += speedX;
		}

		if (velocity->y != 0.0f)
		{
			float speedY = velocity->y * gameTime;
			m_p0.y += speedY; m_p1.y += speedY;
			m_p2.y += speedY; m_p3.y += speedY;
			m_p4.y += speedY; m_p5.y += speedY;
		}
	}

	void Hexagon2D::draw()
	{
        gDevice2D.drawHexagon(m_p0, m_p1, m_p2, m_p3, m_p4, m_p5);
	}

	void Hexagon2D::rotation_rotate(float32 angle)
	{
		setRotation(angle);

		if (this->rotation != 0)
		{
			float32 rotateCos = getRotationCosΘ();
			float32 rotateSin = getRotationSinΘ();

			m_p0 = IEMath2D::RotatePoint(m_p0, rotateCos, rotateSin, *position);
			m_p1 = IEMath2D::RotatePoint(m_p1, rotateCos, rotateSin, *position);
			m_p2 = IEMath2D::RotatePoint(m_p2, rotateCos, rotateSin, *position);
			m_p3 = IEMath2D::RotatePoint(m_p3, rotateCos, rotateSin, *position);
			m_p4 = IEMath2D::RotatePoint(m_p4, rotateCos, rotateSin, *position);
			m_p5 = IEMath2D::RotatePoint(m_p5, rotateCos, rotateSin, *position);
		}
	}

	void Hexagon2D::revolution_rotate(GameObject2D& target, float32 angle)
	{
		if (&target == nullptr) 
		{
			throw GameError(L"Hexagon2D::(88):: - Target equals to nullptr...");
			return;
		}

		setRevolution(angle);

		if (this->revolution != 0)
		{
			JCS_VECTOR2F temp = IEMath2D::RotatePoint(*position, getRevolutionCosΘ(), getRevolutionSinΘ(), *target.position);

			// 移動量 = 移動後 - 移動前
			float tempMoveX = temp.x - position->x;
			float tempMoveY = temp.y - position->y;

			if (tempMoveX != 0.0f)
			{
				m_p0.x += tempMoveX;
				m_p1.x += tempMoveX; 
				m_p2.x += tempMoveX;
				m_p3.x += tempMoveX; 
				m_p4.x += tempMoveX;
				m_p5.x += tempMoveX;
			}

			if (tempMoveY != 0.0f)
			{
				m_p0.y += tempMoveY;
				m_p1.y += tempMoveY; 
				m_p2.y += tempMoveY; 
				m_p3.y += tempMoveY; 
				m_p4.y += tempMoveY; 
				m_p5.y += tempMoveY;
			}

			*position = temp;
		}
	
	}

	/**
	 * Soruce: http://www.redblobgames.com/grids/hexagons/
	 */
	JCS_VECTOR2F Hexagon2D::hex_corner(float32 size, int orderOfPoint)
	{
		float32 angle_degree = 60.0f * orderOfPoint;

		// Change angle for "horizontal hexagon"
		if (!m_type)
			angle_degree += 30.0f;

		float32 angle_radian = PI / 180.0f * angle_degree;

		return JCS_VECTOR2F(position->x + size * std::cos(angle_radian), position->y + size * std::sin(angle_radian));
	}

	// setter
	void Hexagon2D::setM_type(bool value)
	{ 
		if (m_type != value)
		{
			m_type = value;

			// refind the point
			initialize();
		}
	}
	void Hexagon2D::setM_size(float32 value)
	{ 
		if (m_size != value)
		{
			m_size = value;

			// refind the point
			initialize();
		}
	}

}

