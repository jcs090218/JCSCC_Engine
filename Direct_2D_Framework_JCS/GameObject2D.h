#ifndef __GAMEOBJECT_2D_H__
#define __GAMEOBJECT_2D_H__

#include "IEMath2D.h"

#include "Sprite2D.h"

namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : GameObject2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
	class GameObject2D
	{
	protected:
		Graphics2D& gDevice2D;
		Sprite2D* sprite;

		bool rotate_shape;

		float32 getRenderPosX() { return (this->position->x - this->offsetPivot->x); }
		float32 getRenderPosY() { return (this->position->y - this->offsetPivot->y); }

	public:
        JCS_GameInterface::JCS_VECTOR2F* position;		// position
        JCS_GameInterface::JCS_VECTOR2F* velocity;		// 速率
        JCS_GameInterface::JCS_VECTOR2F* offsetPivot;	// offset position->xy 導至 position->xy 就是 pivot point
		float32 rotation, revolution;

	public:
		GameObject2D(Graphics2D& gfx);
		virtual ~GameObject2D();

        virtual void initialize() { }
		virtual void update(const float32 deltaTime);
        virtual void draw() { }

		// setter
		virtual void resetRotation(const float32 angle = 0.0f);
		void setDevice(const Graphics2D& gfx) { this->gDevice2D = gfx; }
		virtual void setPosition(const float x, const float y);
		void setRotation(const float32 newAngle) { this->rotation = newAngle; }
		void setRevolution(const float32 newAngle) { this->revolution = newAngle; }
		void setPivotX(float32 pivotX) { this->offsetPivot->x = pivotX; }
		void setPivotY(float32 pivotY) { this->offsetPivot->y = pivotY; }

		// getter
		float32 getX() const { return this->position->x; }
		float32 getY() const { return this->position->y; }
		float32 getRotation() const { return this->rotation; }
		float32 getRevolution() const { return this->revolution; }
		Sprite2D* getSprite() const { return this->sprite; }
		JCS_VECTOR2F* getPivot() const { return this->offsetPivot; }

		float32 getRotationCosΘ() const { return std::cos(this->rotation / 1000); }
		float32 getRotationSinΘ() const { return std::sin(this->rotation / 1000); }
		float32 getRevolutionCosΘ() const { return std::cos(this->revolution / 1000); }
		float32 getRevolutionSinΘ() const { return std::sin(this->revolution / 1000); }


	};
}

#endif	// __GAMEOBJECT_2D_H__

