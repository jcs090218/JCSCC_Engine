/**
 * $File: IEMath2D.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "IEMath2D.h"

namespace JCS_D2DEngine
{
    IEMath2D::IEMath2D()
    {
    }


    IEMath2D::~IEMath2D()
    {
    }

    /**
     * 找出 x 或 y 的距離
     * 
     * 數學: 找出 垂直三角形 "兩短邊長" 其中一邊
     * 物理: 找出 "垂直分量" 或 "水平分量";
     *       分量(component)
     */
    float32 IEMath2D::DistanceOfUnitVector(float32 x1, float32 x2)
    {
        float32 distance = x2 - x1;
        if (distance < 0) distance = -distance;
        return distance;
    }
    /**
     * 數學: 代入兩邊邊長
     * 物理: 代入 "垂直分量" 和 "水平分量"
     * 公式: c^2 = a^2 + b^2
     * 
     * 數學: 找出垂直三角形"最長邊長"長度
     * 物理: 找出 "合量(resultant)" 
     *       "合量" 是 "垂直分量" 加 "水平分量" 的和
     *       "合量" 同時也是 "向量", "分量" 同時也是 "向量" 
     */
    float32 IEMath2D::DistanceBetweenPoint(float32 p1, float32 p2)
    {
        return sqrt(JCS_GameInterface::Sqr(p1) + JCS_GameInterface::Sqr(p2));
    }
    /**
     * 代入兩個點
     * 公式: d^2 = (x2 - x1)^2 + (y2 - y1)^2
     * 
     * 數學: 找出垂直三角形"最長邊長"長度
     * 物理: 找出 "合量(resultant)" 
     *       "合量" 是 "垂直分量" 加 "水平分量" 的和
     *       "合量" 同時也是 "向量", "分量" 同時也是 "向量" 
     */
    float32 IEMath2D::DistanceBetweenPoint(JCS_VECTOR2F& p1, JCS_VECTOR2F& p2)
    {
        return sqrt(JCS_GameInterface::Sqr(p2.x - p1.x) + JCS_GameInterface::Sqr(p2.y - p1.y));
    }
    /**
     * 計算旋轉的點 (JCS_VECTOR2F)
     *
     * JCS_GameTool::JCS_VECTOR2F point :        我們要計算的"點"
      * float cosΘ :                                Cos 的角度 "Cos(angle)"
      * float sinΘ :                                Sin 的角度 "Sin(angle)"
     * JCS_GameTool::JCS_VECTOR2F origin :        以這個"點"為中心旋轉
     * http://stackoverflow.com/questions/12161277/how-to-rotate-a-vertex-around-a-certain-point
     */
    JCS_VECTOR2F IEMath2D::RotatePoint(
        JCS_VECTOR2F& point, float32 cosΘ, float32 sinΘ,
        JCS_VECTOR2F& origin)
    {
        return JCS_VECTOR2F(
            origin.x + ((point.x - origin.x) * cosΘ) - ((point.y - origin.y) * sinΘ), 
            origin.y + ((point.x - origin.x) * sinΘ) + ((point.y - origin.y) * cosΘ));
    }
    /**
     * 點乘積, 內積(Dot Product or Scalar Product): 
     *        - 純量與向量的乘積 
     *        - 點乘積為一純量, 其值為正, 負或零
     * 
     * 來源: https://zh.wikipedia.org/wiki/%E6%95%B0%E9%87%8F%E7%A7%AF
     * PDF: http://csm00.csu.edu.tw/0227/lyhEng-Math992/Week13/Week13Notes/Week13Notes.pdf
     **
     * 物理:
     *     內積剛好用來找投射的點
     *
     * const JCS_GameTool::JCS_VECTOR2F& : 代入點我們要投射用的邊
     * const JCS_GameTool::JCS_VECTOR2F& : 代入點我們要計算投影大小的
     */
    float32 IEMath2D::DotProduct(const JCS_VECTOR2F& vectorA, const JCS_VECTOR2F& vectorB)
    {
        return ((vectorA.x * vectorB.x) + (vectorA.y * vectorB.y));
    }
    /**
     * 外積(Vector Product or Cross Product)
     * 
     * 來源: https://zh.wikipedia.org/wiki/%E5%A4%96%E7%A7%AF
     */
    float32 IEMath2D::CrossProduct(const JCS_VECTOR2F& vectorA, const JCS_VECTOR2F& vectorB)
    {
        return ((vectorA.x * vectorB.y) - (vectorA.y * vectorB.x));
    }
    JCS_VECTOR2F IEMath2D::CrossProduct(float32 a, const JCS_VECTOR2F& vector)
    {
        return JCS_VECTOR2F(a * vector.y, -a * vector.x);
    }


}// end namespace "JCS_D2DEngine"

