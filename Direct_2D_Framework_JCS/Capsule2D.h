/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D2D_CAPSULE2D_H__
#define __D2D_CAPSULE2D_H__

#include "Shape2D.h"

namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Capsule2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class Capsule2D 
        : public Shape2D
    {
    private:

    public:
        Capsule2D(float32 radius, float32 bodyHeight, 
            Graphics2D& gfx, bool autoPivot = true);
        virtual ~Capsule2D();

        float32 radius, height;
        JCS_VECTOR2F p1, p2, p3, p4;
        JCS_VECTOR2F topCircle, botCircle;

        virtual void initialize() override;
        virtual void update(const float32 deltaTime) override;
        virtual void draw() override;

        virtual void rotation_rotate(float32 float32 = 1.0f) override;
        virtual void revolution_rotate(GameObject2D& target, float32 angle = 1.0f) override;

        // -- Basic Collision
        bool CapsuletoCapsule(Capsule2D& obj);
        bool CapsuletoCircle(Circle2D& obj);
        bool CapsuletoRectangle(Rectangle2D& obj);
        bool CapsuletoPolygon(Polygon2D& obj);

        // setter
        virtual void resetRotation(const float32 angle = 0.0f) override;
        virtual void setPosition(const float32 x, const float32 y) override;
        void setRadius(const float32 newRadius) { this->radius = newRadius; }

        // getter
        float32 getRadius() { return this->radius; }
        float32 getHeight() { return this->height; }
    };

}

#endif // __D2D_CAPSULE2D_H__

