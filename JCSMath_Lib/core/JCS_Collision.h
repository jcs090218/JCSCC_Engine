#ifndef __JCS_COLLISION_H__
/**
 * $File: JCS_Collision.h $
 * $Date: 2016-12-01 12:56:31 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_COLLISION_H__


#include "../JCSMath_Lib_StdAfx.h"

EXTERN_C_BEGIN

namespace JCSMath_Lib
{
	class JCS_Rect;
	class JCS_Circle;

	/**
	   @class JCS_Collision
	   @brief Do all the collision here.
	*/
	class JCSCC_DLL JCS_Collision
	{
	public:
		/**
		   @brief check 2d collision in rectangel and rectangle.

		   @param rect A shape.
		   @param rect B shape.
		   @return
		   true: intersect
		   false: not intersect
		*/
		static bool RectToRect(const JCS_Rect* rectA, const JCS_Rect* rectB);

		/**
		   @brief check 2d collision in circle and circle.

		   @param circle A shape.
		   @param circle B shape.
		   @return
		   true: intersect
		   false: not intersect
		*/
		static bool CircleToCircle(const JCS_Circle* circA, const JCS_Circle* circB);

		/**
		   @brief check 2d collision in rectangel and circle.

		   @param rect shape.
		   @param circle shape.
		   @return
		   true: intersect
		   false: not intersect
		*/
		static bool RectToCircle(const JCS_Rect* rect, const JCS_Circle* circ);


	};
}


typedef JCSMath_Lib::JCS_Collision JCS_Collsion;

EXTERN_C_END

#endif // __JCS_COLLISION_H__
