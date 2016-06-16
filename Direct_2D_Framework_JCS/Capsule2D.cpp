/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Capsule2D.h"

#include "Physics2D.h"

#include "Circle2D.h"
#include "Hexagon2D.h"
#include "Rectangle2D.h"
#include "Polygon2D.h"
#include "Triangle2D.h"

namespace JCS_D2DEngine
{
    Capsule2D::Capsule2D(float32 radius, float32 bodyHeight, Graphics2D& gfx, bool autoPivot)
        : Shape2D(gfx, autoPivot)
        , radius(radius)
        , height(bodyHeight)
    {

        if (auto_pivot) // 自動設置位置到中心點
        {
            this->offsetPivot->x = radius;
            this->offsetPivot->y = height / 2.0f;
        }

        resetRotation();
    }


    Capsule2D::~Capsule2D()
    {
        
    }

    void Capsule2D::initialize()
    {
        
    }

    void Capsule2D::update(const float32 deltaTime)
    {
        Shape2D::update(deltaTime);

        if (velocity->x != 0.0f) {
            float speedX = velocity->x * deltaTime;

            p1.x += speedX; p2.x += speedX;
            p3.x += speedX; p4.x += speedX;
            topCircle.x += speedX;
            botCircle.x += speedX;
        }

        if (velocity->y != 0.0f) {
            float speedY = velocity->y * deltaTime;

            p1.y += speedY; p2.y += speedY;
            p3.y += speedY; p4.y += speedY;
            topCircle.y += speedY;
            botCircle.y += speedY;
        }

    }

    void Capsule2D::draw()
    {
        //// 上面的圓
        gDevice2D.drawCircle(topCircle.x, topCircle.y, radius);

        // 左邊
        gDevice2D.drawLine(
            JCS_VECTOR2F(p1.x, p1.y),
            JCS_VECTOR2F(p4.x, p4.y));
        // 右邊
        gDevice2D.drawLine(
            JCS_VECTOR2F(p2.x, p2.y),
            JCS_VECTOR2F(p3.x, p3.y));

        // 下面的圓
        gDevice2D.drawCircle(botCircle.x, botCircle.y, radius);
    }

    /**
     * 旋轉形狀 (自轉 or 旋轉)
     * Rotation Rotate Shape
     */
    void Capsule2D::rotation_rotate(float32 angle)
    {
        setRotation(angle);

        if (this->rotation != 0.0f) 
        {
            float32 rotateCos = getRotationCosΘ();
            float32 rotateSin = getRotationSinΘ();

            p1 = IEMath2D::RotatePoint(p1, rotateCos, rotateSin, *position);
            p2 = IEMath2D::RotatePoint(p2, rotateCos, rotateSin, *position);
            p3 = IEMath2D::RotatePoint(p3, rotateCos, rotateSin, *position);
            p4 = IEMath2D::RotatePoint(p4, rotateCos, rotateSin, *position);

            topCircle = IEMath2D::RotatePoint(topCircle, rotateCos, rotateSin, *position);
            botCircle = IEMath2D::RotatePoint(botCircle, rotateCos, rotateSin, *position);
        }
    }

    /**
     * 繞轉形狀 (公轉 or 繞轉)
     * Revolution Rotate Shape
     */
    void Capsule2D::revolution_rotate(GameObject2D& target, float32 angle)
    {
        if (&target == nullptr) 
        {
            throw GameError(L"Capsule2D::(127):: - Target equals to nullptr...");
            return;
        }

        setRevolution(angle);

        if (this->revolution != 0.0f) 
        {
            JCS_VECTOR2F temp = IEMath2D::RotatePoint(*position, getRevolutionCosΘ(), getRevolutionSinΘ(), *target.position);

            // 移動量 = 移動後 - 移動前
            float tempMoveX = temp.x - position->x;
            float tempMoveY = temp.y - position->y;

            if (tempMoveX != 0.0f) 
            {
                p1.x += tempMoveX; 
                p2.x += tempMoveX;
                p3.x += tempMoveX; 
                p4.x += tempMoveX;
                topCircle.x += tempMoveX;
                botCircle.x += tempMoveX;
            }

            if (tempMoveY != 0.0f) 
            {
                p1.y += tempMoveY; 
                p2.y += tempMoveY;
                p3.y += tempMoveY; 
                p4.y += tempMoveY;
                topCircle.y += tempMoveY;
                botCircle.y += tempMoveY;
            }

            *position = temp;
        }
    }

    void Capsule2D::resetRotation(const float32 angle)
    {
        // Offset 目前沒有用...
        p1.x = position->x - radius;            // top left
        p1.y = position->y - height / 2;
        p2.x = position->x + radius;            // top right
        p2.y = position->y - height / 2;
        p3.x = position->x + radius;            // bottom right
        p3.y = position->y + height / 2;
        p4.x = position->x - radius;            // bottom left
        p4.y = position->y + height / 2;

        topCircle.x = position->x;
        topCircle.y = position->y - height / 2;
        botCircle.x = position->x;
        botCircle.y = position->y + height / 2;
    }

    void Capsule2D::setPosition(const float32 x, const float32 y)
    {
        if (position->x != x) position->x = x;
        if (position->y != y) position->y = y;

        resetRotation();
    }

    //////////////////////////////////////////////////////////////////////////////////
    ////-- Basic Collision
    //////////////////////////////////////////////////////////////////////////////////
    /**
     * "膠囊狀"和"膠囊狀"的碰撞測試
     */
    bool Capsule2D::CapsuletoCapsule(Capsule2D& obj)
    {
        float tempX = this->position->x - obj.position->x;
        if (tempX < 0) tempX = -tempX;                        // 絕對值

        if (tempX <= this->getRadius() + obj.getRadius()) 
        {
            // 上面兩個圓的碰撞測試
            float tempY = (obj.position->y - (obj.getHeight() / 2)) - (this->position->y - (this->getHeight() / 2));
            if (IEMath2D::DistanceBetweenPoint(tempX, tempY) <= this->getRadius() + obj.getRadius()) {
                return true;
            }

            // 下面兩個圓的碰撞測試
            tempY = (obj.position->y + (obj.getHeight() / 2) - (this->position->y + (this->getHeight() / 2)));
            if (IEMath2D::DistanceBetweenPoint(tempX, tempY) <= this->getRadius() + obj.getRadius()) {
                return true;
            }

            // 上下兩個圓的碰撞測試
            tempY = (obj.position->y - (obj.getHeight() / 2) - (this->position->y + (this->getHeight() / 2)));
            if (IEMath2D::DistanceBetweenPoint(tempX, tempY) <= this->getRadius() + obj.getRadius()) {
                return true;
            }

            // 下上兩個圓的碰撞測試
            tempY = (obj.position->y + (obj.getHeight() / 2) - (this->position->y - (this->getHeight() / 2)));
            if (IEMath2D::DistanceBetweenPoint(tempX, tempY) <= this->getRadius() + obj.getRadius()) {
                return true;
            }

        }

        return false;
    }
    /**
     * "膠囊狀"和"圓形"的碰撞測試
     */
    bool Capsule2D::CapsuletoCircle(Circle2D& obj)
    {
        float tempX = this->position->x - obj.position->x;
        if (tempX < 0) tempX = -tempX;

        if (tempX <= this->getRadius() + obj.getRadius()) 
        {
            float tempY = obj.position->y - (this->position->y - (this->getHeight() / 2));
            if (IEMath2D::DistanceBetweenPoint(tempX, tempY) <= this->getRadius() + obj.getRadius()) {
                return true;
            }

            tempY = obj.position->y - (this->position->y + (this->getHeight() / 2));
            if (IEMath2D::DistanceBetweenPoint(tempX, tempY) <= this->getRadius() + obj.getRadius()) {
                return true;
            }
        }

        return false;
    }
    /**
     * "膠囊狀"和"矩形"的碰撞測試
     */
    bool Capsule2D::CapsuletoRectangle(Rectangle2D& obj)
    {
        if (obj.getAutoPivot())
        {
            // 算出"對角線"的長度, 並除以二
            float tempRadius = (IEMath2D::DistanceBetweenPoint(obj.getP3(), obj.getP1()) / 2);

            float tempCollideDistance = this->getRadius() + tempRadius;
            if (IEMath2D::DistanceBetweenPoint(topCircle, *obj.position) <= tempCollideDistance ||
                IEMath2D::DistanceBetweenPoint(botCircle, *obj.position) <= tempCollideDistance)
            {

                if (IEMath2D::DistanceOfUnitVector(this->position->x, obj.position->x) <= 
                    (this->getRadius() + (obj.getWidth() / 2)) &&
                    IEMath2D::DistanceOfUnitVector(this->position->y, obj.position->y) <= 
                    (((this->getHeight() / 2) + this->getRadius()) + (obj.getHeight() / 2)))
                {
                    return true;
                }
            }

        }
        // 沒有AutoPivot的情況
        else {
            // 算出"對角線"的長度, 並除以二
            float tempRadius = (IEMath2D::DistanceBetweenPoint(obj.getP3(), obj.getP1()) / 2);

            // 找出中心點, 因為並沒有自行設置中心
            JCS_VECTOR2F tempOrigin(
                obj.position->x + (obj.getWidth() / 2), 
                obj.position->y + (obj.getHeight() / 2));

            float tempCollideDistance = this->getRadius() + tempRadius;
            if (IEMath2D::DistanceBetweenPoint(topCircle, tempOrigin) <= tempCollideDistance ||
                IEMath2D::DistanceBetweenPoint(botCircle, tempOrigin) <= tempCollideDistance)
            {

                if (IEMath2D::DistanceOfUnitVector(this->position->x, tempOrigin.x) <= 
                    (this->getRadius() + (obj.getWidth() / 2)) &&
                    IEMath2D::DistanceOfUnitVector(this->position->y, tempOrigin.y) <= 
                    (((this->getHeight() / 2) + this->getRadius()) + (obj.getHeight() / 2)))
                {
                    return true;
                }
            }
        }

        return false;
    }
    /**
    *
    */
    bool Capsule2D::CapsuletoPolygon(Polygon2D& obj)
    {
        return false;
    }

}

