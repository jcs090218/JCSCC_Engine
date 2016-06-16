#include "Physics2D.h"

#include "Capsule2D.h"
#include "Circle2D.h"
#include "Polygon2D.h"
#include "Rectangle2D.h"

namespace JCS_D2DEngine
{
    Physics2D::Physics2D()
    {
    }


    Physics2D::~Physics2D()
    {
    }

    /**
     * 偵測兩個矩形 是否相撞
     */
    bool Physics2D::PointVSPoint(JCS_GameInterface::JCS_RECT* a, JCS_GameInterface::JCS_RECT* b)
    {
        // Eixt with no intersection if found separated along an axis
        if (a->bottomRight.x < b->topLeft.x || a->topLeft.x > b->bottomRight.x) return false;
        if (a->bottomRight.y < b->topLeft.y || a->topLeft.y > b->bottomRight.y) return false;

        // No separating axis found, therefor there is at least one over
        return true;
    }
    /**
     * 用來計算圓與圓的距離
     */
    float Physics2D::Distance(JCS_GameInterface::JCS_VECTOR2F* a, JCS_GameInterface::JCS_VECTOR2F* b)
    {
        return std::sqrt(std::pow((a->x - b->x), 2) + std::pow((a->y - b->y), 2));
    }
    /**
     * 偵測看圓與圓是否相撞 (非優化過的代碼)
     * Unoptimized Code
     */
    bool Physics2D::CirclevsCircleUnoptimized(Circle2D* a, Circle2D* b)
    {
        float r = a->getRadius() + b->getRadius();
        return (r < Distance(a->position, b->position));
    }
    /**
     * 偵測看圓與圓是否相撞 (優化過的代碼)
     * Optimized code
     */
    bool Physics2D::CirclevsCircleOptimized(Circle2D* a, Circle2D* b)
    {
        float r = a->getRadius() + b->getRadius();
        r *= r;
        return (r < (std::pow((a->position->x + b->position->x), 2) + std::pow((a->position->y + b->position->y), 2)));
    }
    /**
     * 利用牛頓三大定律
     *
     * http://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-basics-and-impulse-resolution--gamedev-6331
     *
     * 公式: (V^B − V^A) ⋅ n + j ∗ (j ∗ nmass^A + j ∗ nmass^B) ∗ n + e ∗ (V^B − V^A) ⋅ n = 0
     * ∴ 
     * (1 + e)((V^B − V^A) ⋅ n) + j ∗ (j ∗ n mass^A + j ∗ nmass^B) ∗ n = 0
     * ∴ 
     * ----------------------------------------------------------------------------------
     *        "j = −(1 + e)((V^B − V^A) ⋅ n) / 1mass^A + 1mass^B"    (這行最後公式的樣子)
     * ----------------------------------------------------------------------------------
     */
    void Physics2D::ResolveCollision(Shape2D* A, Shape2D* B)
    {
        //// Calculate relative velocity (相對速度)
        //JCS_GameInterface::JCS_VECTOR2F rv = calculateRelativeVelocity(A->velocity, B->velocity);

        //// Calculate relative velocity in terms of the normal direction
        //float normal = 0;
        //float velAlongNormal = DotProduct(rv, normal);

        //// Do not resolve if velocities are separating
        //if (velAlongNormal > 0)
        //    return;

        //// Calculate restitution
        //float e = std::min(A->restitution, B->restitution);

        //// Calculate impulse scalar
        //float j = -(1 + e) * velAlongNormal;
        //j /= ((1 / A->mass) + (1 / B->mass));

        //// Apply impulse
        //JCS_GameInterface::JCS_VECTOR2F impulse = j * normal;
        ////A->velocity -= 1 / A->mass * impulse;
        ////B->velocity += 1 / B->mass * impulse;

    }
    /**
     * 內積 (兩點)
     * 
     * 維基百科: https://zh.wikipedia.org/wiki/%E6%95%B0%E9%87%8F%E7%A7%AF
     */
    float32 Physics2D::DotProduct(JCS_GameInterface::JCS_VECTOR2F vec2, float normal)
    {
        return (0);
    }
    /**
     * Calculate relative velocity (相對速度)
     * 
     * 公式: " (V) ^ AB = (V) ^ B - (V) ^ A "
     * 維基百科: https://zh.wikipedia.org/wiki/%E7%9B%B8%E5%B0%8D%E9%80%9F%E5%BA%A6
     */
    JCS_GameInterface::JCS_VECTOR2F Physics2D::calculateRelativeVelocity(
        JCS_GameInterface::JCS_VECTOR2F* vel_01, JCS_GameInterface::JCS_VECTOR2F* vel_02)
    { 
        return JCS_GameInterface::JCS_VECTOR2F(vel_02->x - vel_01->y, vel_02->y - vel_01->y);
    }
    /**
     * 密度 = 質量 / 體積
     */
    float32 Physics2D::density(float mass, float volume) 
    { 
        return (mass / volume); 
    }
    /**
     * 質量 = 體積 * 密度
     */
    float32 Physics2D::mass(float density, float volume) 
    { 
        return (density * volume); 
    }
    /**
     * 體積 = 質量 / 密度
     */
    float32 Physics2D::volume(float density, float mass) 
    {
        return (mass / density); 
    }

    /**
     * 向量+向量
     */
    JCS_GameInterface::JCS_VECTOR2F Physics2D::VectorAddVector(JCS_GameInterface::JCS_VECTOR2F& vector1, JCS_GameInterface::JCS_VECTOR2F& vector2)
    {
        return JCS_GameInterface::JCS_VECTOR2F(vector1.x + vector2.x, vector1.y + vector2.y);
    }

}

