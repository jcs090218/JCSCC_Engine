/**
 * $File: JCS_Collision.cpp $
 * $Date: 2016-12-01 12:56:33 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "../JCSMath_Lib.h"

EXTERN_C_BEGIN

namespace JCSMath_Lib
{

    bool JCS_Collision::RectToRect(const JCS_Rect* rectA, const JCS_Rect* rectB)
    {
		// check null references
		if (!rectA || !rectB)
		{
			JCS_Debug(L"Unable to do collision with null references...");
			return false;
		}

		// do AABB check.
		if (rectA->GetX() + rectA->GetWidth() > rectB->GetX() &&
			rectA->GetX() < rectB->GetX() + rectB->GetWidth() &&
			rectA->GetY() + rectA->GetHeight() > rectB->GetY() &&
			rectA->GetY() < rectB->GetY() + rectB->GetHeight())
		{
			return true;
		}

        return false;
    }

    bool JCS_Collision::CircleToCircle(const JCS_Circle* circA, const JCS_Circle* circB)
    {
		// check null references
		if (!circA || !circB)
		{
			JCS_Debug(L"Unable to do collision with null references...");
			return false;
		}

		// get the distance between two circle origin.
		float32 distance = JCSMath_Lib::JCS_Mathf::DistanceBetweenPoint(circA->GetPosition(), circB->GetPosition());

		// compare distance and two circle's radius sum
		if (distance <= circA->GetRadius() + circB->GetRadius())
		{
			return true;
		}

        return false;
    }

    bool JCS_Collision::RectToCircle(const JCS_Rect* rect, const JCS_Circle* circ)
    {
		// check null references
		if (!rect || !circ)
		{
			JCS_Debug(L"Unable to do collision with null references...");
			return false;
		}

		JCS_VECTOR2F c = JCS_VECTOR2F(
			rect->GetX() + rect->GetWidth() / 2,
			rect->GetY() + rect->GetHeight() / 2);

		JCS_VECTOR2F p = JCS_VECTOR2F(circ->GetX(), circ->GetY());

		JCS_VECTOR2F v = JCS_VECTOR2F(
			JCS_Mathf::DistanceOfUnitVector(c.x, p.x), 
			JCS_Mathf::DistanceOfUnitVector(c.y, p.y));

		float32 side1 = JCS_Mathf::Abs(rect->GetX() - (rect->GetX() + rect->GetWidth()));
		float32 side2 = JCS_Mathf::Abs(rect->GetY() - (rect->GetY() + rect->GetHeight()));

		// h为矩形半長
		JCS_VECTOR2F h = JCS_VECTOR2F(side1 / 2.0f, side2 / 2.0f);

		JCS_VECTOR2F u = JCS_VECTOR2F(
			JCS_Mathf::Max(v.x - h.x, 0), 
			JCS_Mathf::Max(v.y - h.y, 0));

        return JCS_Mathf::DotProduct(u, u) <= JCS_Mathf::Sqr(circ->GetRadius());
    }
}

EXTERN_C_END
