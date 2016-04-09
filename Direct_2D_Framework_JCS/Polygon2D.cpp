/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Polygon2D.h"

#include "Circle2D.h"
#include "Capsule2D.h"
#include "Hexagon2D.h"
#include "Polygon2D.h"
#include "Triangle2D.h"

namespace JCS_D2DEngine
{
	Polygon2D::Polygon2D(Graphics2D& gfx, bool autoPivot)
		: Shape2D(gfx, autoPivot)
	{
		
	}

	Polygon2D::~Polygon2D()
	{
		
	}

	void Polygon2D::initialize()
	{
		
	}

	void Polygon2D::update(const float32 deltaTime)
	{
		Shape2D::update(deltaTime);
	}

	void Polygon2D::draw()
	{
        
	}

	//////////////////////////////////////////////////////////////////////////////////
	////-- Basic Collision
	//////////////////////////////////////////////////////////////////////////////////
	/**
	*
	*/
	bool Polygon2D::PolygontoPolygon(Polygon2D& obj)
	{
		return false;
	}
	/**
	*
	*/
	bool Polygon2D::PolygontoCircle(Circle2D& obj)
	{
		return false;
	}
	/**
	*
	*/
	bool Polygon2D::PolygontoRectangle(Rectangle2D& obj)
	{
		return false;
	}
	/**
	*
	*/
	bool Polygon2D::PolygontoCapsule(Capsule2D& obj)
	{
		return false;
	}

}// end namespace "JCS_D2DEngine" 

