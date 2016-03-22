#include "Triangle2D.h"

#include "Circle2D.h"
#include "Capsule2D.h"
#include "Hexagon2D.h"
#include "Polygon2D.h"
#include "Rectangle2D.h"

namespace JCS_D2DEngine
{
	Triangle2D::Triangle2D(JCS_VECTOR2F p0, 
		JCS_VECTOR2F p1, 
		JCS_VECTOR2F p2, 
		Graphics2D& gfx, bool autoPivot)
		: Shape2D(gfx, autoPivot)
		, p0(p0)
		, p1(p1)
		, p2(p2)
	{

	}


	Triangle2D::~Triangle2D()
	{
		
	}

	void Triangle2D::initialize()
	{

	}

	void Triangle2D::update(const float32 gameTime)
	{
		Shape2D::update(gameTime);
	}

	void Triangle2D::draw()
	{
	    gDevice2D.drawTriangle(p0, p1, p2);
	}

}

