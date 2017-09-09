#ifndef __TRIANGLE_2D__
/**
 * $File: Triangle2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __TRIANGLE_2D__

#include "Shape2D.h"


namespace JCS_D2DEngine
{

    //====================================================================================
    // Class Name : Triangle2D
    //
    // Description : Triangle shape render using Direct 2D device.
    //====================================================================================
    class Triangle2D 
        : public Shape2D
    {
    private:
        JCS_VECTOR2F p0, p1, p2;

    public:
        Triangle2D(JCS_VECTOR2F p0, JCS_VECTOR2F p1, JCS_VECTOR2F p2, 
            Graphics2D& gfx, bool autoPivot = true);
        virtual ~Triangle2D();

        virtual void initialize() override;
        virtual void update(const float32 deltaTime) override;
        virtual void draw() override;

        virtual void rotation_rotate(float32 angle = 1.0f) override;
        virtual void revolution_rotate(GameObject2D& target, float32 angle = 1.0f) override;
    };
}

#endif // __TRIANGLE_2D__

