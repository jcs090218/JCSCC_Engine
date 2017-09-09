#ifndef __JCS_MATHF_H__
/**
 * $File: JCS_Mathf.h $
 * $Date: 2016-12-01 13:25:32 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_MATHF_H__


#include "../JCSMath_Lib_StdAfx.h"

EXTERN_C_BEGIN

namespace JCSMath_Lib
{

    /**
     * @class JCS_Mathf
     * @brief all math function should listed here.
     */
    class JCSCC_DLL JCS_Mathf
    {
    public:
		/**
		 * @func DistanceOfUnitVector
		 * @brief Return the distance of unit vector.
		 * @param x1 : vector value 1
		 * @param x2 : vector value 2
		 * @return float32 : return the unit vector.
		 */
		static float32 DistanceOfUnitVector(float32 x1, float32 x2);

		/**
		 * @brief Return the distance between two point.
		 * @param p1 : point 1 to find out the distance.
		 * @param p2 : point 2 to find out the distance.
		 * @return float32 : Distance between the point.
		 */
		static float32 DistanceBetweenPoint(float32 p1, float32 p2);

		/**
		 * @func DistanceBetweenPoint
		 * @brief Return the distance between two point.
		 * @param p1 : point 1 to find out the distance.
		 * @param p2 : point 2 to find out the distance.
		 * @return float32 : Distance between the point.
		 */
		static float32 DistanceBetweenPoint(
			JCS_GameInterface::JCS_VECTOR2F& p1, 
			JCS_GameInterface::JCS_VECTOR2F& p2);

		/**
		 * @func RotatePoint
		 * @brief Return the calcuate movement be rotating.
		 * @param point
		 * @param cosine angle
		 * @param sine angle
		 * @param origin point
		 * @return JCS_VECTOR2F : rotated point value.
		 */
		static JCS_GameInterface::JCS_VECTOR2F RotatePoint(
			JCS_GameInterface::JCS_VECTOR2F& point, 
			float32 cosΘ, 
			float32 sinΘ,
			JCS_GameInterface::JCS_VECTOR2F& origin);

		/**
		 * @brief Do dot product.
		 * @param vectorA : vector A to do dot product.
		 * @param vectorB : vector B to do dot product.
		 * @return float32 : result.
		 */
		static float32 DotProduct(
			const JCS_GameInterface::JCS_VECTOR2F& vectorA, 
			const JCS_GameInterface::JCS_VECTOR2F& vectorB);
		/**
		 * @func CrossProduct
		 * @brief Do cross product for vector.
		 * @param vectorA : vector A to do cross product.
		 * @param vectorB : vector B to do cross product.
		 * @return float32 : result.
		 */
		static float32 CrossProduct(
			const JCS_GameInterface::JCS_VECTOR2F& vectorA, 
			const JCS_GameInterface::JCS_VECTOR2F& vectorB);
		/**
		 * @func Sqrt
		 * @brief Do cross product.
		 * @param a
		 * @param vector2
		 */
		static JCS_VECTOR2F CrossProduct(
			float32 a, const JCS_GameInterface::JCS_VECTOR2F& vector);

		/**
		 * @func Sqrt
		 * @breif do absolute value.
		 * @return result value.
		 */
		static float32 Abs(const float32 val);

		/**
		 * @func Sqrt
		 * @breif do square value. (float)
		 * @return result value. (float)
		 */
		static float32 Sqr(const float32 val);
		/**
		 * @func Sqrt
		 * @breif do square value. (integer)
		 * @return result value. (integer)
		 */
		static int32 Sqr(const int32 val);

		/**
		 * @func Sqrt
		 * @breif do square root value. (float)
		 * @return result value. (float)
		 */
		static float32 Sqrt(const float32 val);

		/**
		 * @func Sqrt
		 * @breif do square root value. (long)
		 * @return result value. (long)
		 */
		static ld64 Sqrt(const ld64 val);

		/**
		 * @func Sqrt
		 * @breif do square root value. (double)
		 * @return result value. (double)
		 */
		static float64 Sqrt(const float64 val);

		/**
		 * @func Max
		 * @brief find larger value by compare.
		 * @param val : value to compare with.
		 * @return larger value
		 */
		static float32 Max(const float32 a, const float32 b);
		static float32 Max(const float32 a, const float32 b, const float32 c);
		static float32 Max(const float32 a, const float32 b, const float32 c, const float32 d);
		static float32 Max(const float32 a, const float32 b, const float32 c, const float32 d, const float32 e);
		/**
		 * @func Min
		 * @brief find smaller value by compare.
		 * @param val : value to compare with.
		 * @return smaller value
		 */
		static float32 Min(const float32 a, const float32 b);
		static float32 Min(const float32 a, const float32 b, const float32 c);
		static float32 Min(const float32 a, const float32 b, const float32 c, const float32 d);
		static float32 Min(const float32 a, const float32 b, const float32 c, const float32 d, const float32 e);


        /**
		 * @func IsPositive
         * @brief Is the value positive?
		 * @param float32 : value to check.
         * @return true: is positive
         *         false: is not positive
         */
        static bool IsPositiive(const float32 val);

        /**
		 * @func IsNegative
         * @brief Is the value positive?
		 * @param float32 : value to check.
         * @return true: is negative
         *         false: is not negative
         */
        static bool IsNegative(const float32 val);

        /** @brief Get Positive Infinity number. */
        static float PositiveInfinity() { return std::numeric_limits<float32>::infinity(); }
        /** @brief Get Negative Infinity number. */
        static float NegativeInfinity() { return -std::numeric_limits<float32>::infinity(); }

        /* Check if the number infinity? */
        static bool IsInfinity(const float32 val);

        /**
		 * @func IsPossible
         * @brief Pass in percentage 0 ~ 100 and return the possiblity.
		 * @param val : possibility to do stuff.
         * @return true: go through
         *         false: does not go through
         */
        static bool IsPossible(const float32 val);
    };
}

typedef JCSMath_Lib::JCS_Mathf JCS_Mathf;

EXTERN_C_END

#endif // __JCS_MATHF_H__
