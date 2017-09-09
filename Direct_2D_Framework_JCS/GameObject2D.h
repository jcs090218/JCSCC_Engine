#ifndef __GAMEOBJECT_2D_H__
/**
 * $File: GameObject2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __GAMEOBJECT_2D_H__

#include "IEMath2D.h"

#include "Sprite2D.h"

namespace JCS_D2DEngine
{

    //====================================================================================
    // Class Name : GameObject2D
    //
    // Description : GameObject in JCSCC uing Direct 2D.
    //====================================================================================
    class GameObject2D
    {
    protected:
        Graphics2D& gDevice2D;
        Sprite2D* sprite;

        bool rotate_shape;

        /** Return render x-axis position */
        float32 getRenderPosX() { return (this->position->x - this->offsetPivot->x); }
        /** Return render y-axis position */
        float32 getRenderPosY() { return (this->position->y - this->offsetPivot->y); }

    public:
        JCS_GameInterface::JCS_VECTOR2F* position;        // position
        JCS_GameInterface::JCS_VECTOR2F* velocity;        // 速率
        JCS_GameInterface::JCS_VECTOR2F* offsetPivot;    // offset position->xy 導至 position->xy 就是 pivot point
        float32 rotation, revolution;

    public:
        GameObject2D(Graphics2D& gfx);
        virtual ~GameObject2D();

        /**
            Initialize the object itself. (Interface)
        */
        virtual void initialize() { }
        /**
            Update the object itself. (Interface)

            @param Game Time's delta time.
        */
        virtual void update(const float32 deltaTime);
        /**
            Render the object itself. (Interface)
        */
        virtual void draw() { }

        /** setter **/
        /**  */
        virtual void resetRotation(const float32 angle = 0.0f);
        /**  */
        void setDevice(const Graphics2D& gfx) { this->gDevice2D = gfx; }
        /** Set the position for this game object. */
        virtual void setPosition(const float32 x, const float32 y);
        /**  */
        void setRotation(const float32 newAngle) { this->rotation = newAngle; }
        /**  */
        void setRevolution(const float32 newAngle) { this->revolution = newAngle; }
        /**  */
        void setPivotX(float32 pivotX) { this->offsetPivot->x = pivotX; }
        /**  */
        void setPivotY(float32 pivotY) { this->offsetPivot->y = pivotY; }

        /** getter **/
        /**  */
        float32 getX() const { return this->position->x; }
        /**  */
        float32 getY() const { return this->position->y; }
        /**  */
        float32 getRotation() const { return this->rotation; }
        /**  */
        float32 getRevolution() const { return this->revolution; }
        /**  */
        Sprite2D* getSprite() const { return this->sprite; }
        /**  */
        JCS_VECTOR2F* getPivot() const { return this->offsetPivot; }

        /**  */
        float32 getRotationCosΘ() const { return std::cos(this->rotation / 1000); }
        /**  */
        float32 getRotationSinΘ() const { return std::sin(this->rotation / 1000); }
        /**  */
        float32 getRevolutionCosΘ() const { return std::cos(this->revolution / 1000); }
        /**  */
        float32 getRevolutionSinΘ() const { return std::sin(this->revolution / 1000); }

    };
}

#endif    // __GAMEOBJECT_2D_H__

