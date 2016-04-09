/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "GameObject2D.h"

namespace JCS_D2DEngine
{
    GameObject2D::GameObject2D(Graphics2D& gfx)
		: gDevice2D(gfx)
		, sprite(nullptr)
		, position(nullptr)
		, velocity(nullptr)
		, offsetPivot(nullptr)
		, rotate_shape(false)
		, rotation(1.0f)
		, revolution(1.0f)
	{
        velocity = new JCS_GameInterface::JCS_VECTOR2F;
        position = new JCS_GameInterface::JCS_VECTOR2F;
        offsetPivot = new JCS_GameInterface::JCS_VECTOR2F;
	}


	GameObject2D::~GameObject2D()
	{
		SafeDeleteObject(sprite);
		SafeDeleteObject(position);
		SafeDeleteObject(velocity);
		SafeDeleteObject(offsetPivot);
	}

	void GameObject2D::update(const float32 deltaTime)
	{
		position->x += velocity->x * deltaTime;
		position->y += velocity->y * deltaTime;
	}

	void GameObject2D::resetRotation(const float32 angle)
	{

	}

    void GameObject2D::setPosition(const float32 x, const float32 y)
    {
		if (position->x != x) this->position->x = x;
		if (position->y != y) this->position->y = y;

		resetRotation();
	}

}

