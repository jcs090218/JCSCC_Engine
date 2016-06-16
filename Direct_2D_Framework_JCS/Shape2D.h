/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D2D_SHAPE2D_H__
#define __D2D_SHAPE2D_H__

#include "D2D_StdAfx.h"

#include "GameObject2D.h"

namespace JCS_D2DEngine
{

    class Rectangle2D;
    class Circle2D;
    class Hexagon2D;
    class Polygon2D;
    class Capsule2D;
    class Triangle2D;

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Shape2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class Shape2D 
        : public GameObject2D
    {
    protected:
        bool auto_pivot;

    public:
        Shape2D(Graphics2D& gfx, bool autoPivot = true);
        virtual ~Shape2D();

        virtual void initialize() override;
        virtual void update(const float32 deltaTime) override;            // 處理邏輯
        virtual void draw() override { }                        // 畫出來
        
        virtual void rotation_rotate(float32 angle = 1.0f) = 0;    // 旋轉形狀
        virtual void revolution_rotate(GameObject2D& target, float32 angle = 1.0f) = 0;

        // setter
        void setAutoPivot(bool active) { if (auto_pivot != active) this->auto_pivot = active; }

        // getter
        bool getAutoPivot() { return this->auto_pivot; }

    };
}

#endif // __D2D_SHAPE2D_H__

