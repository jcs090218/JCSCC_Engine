#ifndef __D2D_SHAPE2D_H__
/**
 * $File: Shape2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __D2D_SHAPE2D_H__

#include "D2D_StdAfx.h"

#include "GameObject2D.h"


namespace JCS_D2DEngine
{
    // List of all the colliding shap.
    class Rectangle2D;
    class Circle2D;
    class Hexagon2D;
    class Polygon2D;
    class Capsule2D;
    class Triangle2D;

    //====================================================================================
    // Class Name : Shape2D
    //
    // Description : Collider shap in this JCSCC 2D.
    //====================================================================================
    class Shape2D 
        : public GameObject2D
    {
    protected:
        bool auto_pivot;    // trigger of auto pivot the shape or not.

    public:
        Shape2D(Graphics2D& gfx, bool autoPivot = true);
        virtual ~Shape2D();
        
        /**
            Do rotation movement and math calculation.

            @param angle to move.
        */
        virtual void rotation_rotate(float32 angle = 1.0f) = 0;    // 旋轉形狀
        /**
            Do Revolution movement and math calculation.

            @param target to revolute.
            @param angle to move.
        */
        virtual void revolution_rotate(GameObject2D& target, float32 angle = 1.0f) = 0;

        /** setter **/
        /** Trigger auto pivot effect? */
        void setAutoPivot(bool active) { if (auto_pivot != active) this->auto_pivot = active; }

        /** getter **/
        /** Boolean that pivot is trigger? */
        bool getAutoPivot() { return this->auto_pivot; }

    };
}

#endif // __D2D_SHAPE2D_H__
