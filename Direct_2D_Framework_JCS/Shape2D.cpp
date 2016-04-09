/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Shape2D.h"


namespace JCS_D2DEngine
{
	Shape2D::Shape2D(Graphics2D& gfx, bool autoPivot)
		: GameObject2D(gfx)
        , auto_pivot(autoPivot)
	{
		
	}

	Shape2D::~Shape2D()
	{
		
	}

	void Shape2D::initialize()
	{
		GameObject2D::initialize();
	}

	void Shape2D::update(const float32 deltaTime)
	{
		GameObject2D::update(deltaTime);
	}

}

