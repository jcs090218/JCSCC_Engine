/**
 * $File: JCS_Mathf.cpp $
 * $Date: 2016-12-01 13:25:36 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "../JCSMath_Lib.h"

EXTERN_C_BEGIN

namespace JCSMath_Lib
{

	/**
	* 找出 x 或 y 的距離
	*
	* 數學: 找出 垂直三角形 "兩短邊長" 其中一邊
	* 物理: 找出 "垂直分量" 或 "水平分量";
	*       分量(component)
	*/
	float32 JCS_Mathf::DistanceOfUnitVector(float32 x1, float32 x2)
	{
		float32 distance = x2 - x1;

		if (distance < 0)
			distance = -distance;

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
	float32 JCS_Mathf::DistanceBetweenPoint(float32 p1, float32 p2)
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
	float32 JCS_Mathf::DistanceBetweenPoint(JCS_VECTOR2F& p1, JCS_VECTOR2F& p2)
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
	JCS_VECTOR2F JCS_Mathf::RotatePoint(
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
	float32 JCS_Mathf::DotProduct(const JCS_VECTOR2F& vectorA, const JCS_VECTOR2F& vectorB)
	{
		return ((vectorA.x * vectorB.x) + (vectorA.y * vectorB.y));
	}
	/**
	* 外積(Vector Product or Cross Product)
	*
	* 來源: https://zh.wikipedia.org/wiki/%E5%A4%96%E7%A7%AF
	*/
	float32 JCS_Mathf::CrossProduct(const JCS_VECTOR2F& vectorA, const JCS_VECTOR2F& vectorB)
	{
		return ((vectorA.x * vectorB.y) - (vectorA.y * vectorB.x));
	}
	JCS_VECTOR2F JCS_Mathf::CrossProduct(float32 a, const JCS_VECTOR2F& vector)
	{
		return JCS_VECTOR2F(a * vector.y, -a * vector.x);
	}

	float32 JCS_Mathf::Abs(const float32 val)
	{
		return abs(val);
	}

	float32 JCS_Mathf::Sqr(const float32 val)
	{
		return val * val;
	}

	int32 JCS_Mathf::Sqr(const int32 val)
	{
		return val * val;
	}

	float32 JCS_Mathf::Sqrt(const float32 val)
	{
		return sqrtf(val);
	}

	ld64 JCS_Mathf::Sqrt(const ld64 val)
	{
		return sqrtl(val);
	}

	float64 JCS_Mathf::Sqrt(const float64 val)
	{
		return sqrt(val);
	}

	float32 JCS_Mathf::Max(const float32 a, const float32 b)
	{
		return max(a, b);
	}
	float32 JCS_Mathf::Max(const float32 a, const float32 b, const float32 c)
	{
		float32 tempMax = max(a, b);

		return max(tempMax, c);
	}
	float32 JCS_Mathf::Max(const float32 a, const float32 b, const float32 c, const float32 d)
	{
		float32 tempMax = max(a, b);
		float32 tempMax2 = max(tempMax, c);

		return max(tempMax2, d);
	}
	float32 JCS_Mathf::Max(const float32 a, const float32 b, const float32 c, const float32 d, const float32 e)
	{
		float32 tempMax = max(a, b);
		float32 tempMax2 = max(tempMax, c);
		float32 tempMax3 = max(tempMax2, d);

		return max(tempMax3, e);
	}

	float32 JCS_Mathf::Min(const float32 a, const float32 b)
	{
		return min(a, b);
	}
	float32 JCS_Mathf::Min(const float32 a, const float32 b, const float32 c)
	{
		float32 tempMin = min(a, b);

		return min(tempMin, c);
	}
	float32 JCS_Mathf::Min(const float32 a, const float32 b, const float32 c, const float32 d)
	{
		float32 tempMin = min(a, b);
		float32 tempMin1 = min(tempMin, c);

		return min(tempMin1, d);
	}
	float32 JCS_Mathf::Min(const float32 a, const float32 b, const float32 c, const float32 d, const float32 e)
	{
		float32 tempMin = min(a, b);
		float32 tempMin1 = min(tempMin, c);
		float32 tempMin2 = min(tempMin1, d);

		return min(tempMin2, e);
	}

	// Is the value positive?
    bool JCS_Mathf::IsPositiive(const float32 val)
    {
        return (val > 0) ? true : false;
    }

	// Is the value negative?
    bool JCS_Mathf::IsNegative(const float32 val)
    {
        return (val < 0) ? true : false;
    }

	// Is the value infinity value?
    bool JCS_Mathf::IsInfinity(const float32 val)
    {
        return (val == PositiveInfinity() || val == NegativeInfinity());
    }

	// true : success, false : vice versa
    bool JCS_Mathf::IsPossible(const float32 val)
    {
        float32 chance = JCS_GameUtil::random(0.0f, 100.0f);

        return (val > chance) ? true : false;
    }
}

EXTERN_C_END
