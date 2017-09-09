#ifndef __JCS_IEMATH_H__
/**
 * $File: JCS_IEMath.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_IEMATH_H__

#include "GameInterface_StdAfx.h"


const float32 PI = 3.141592741f;        // PI
const float32 EPSILON = 0.0001f;        // EPSILON 是浮點數容許值

namespace JCS_GameInterface
{

    //====================================================================================
    // Struct Name: _JCS_IEMATH_VECTOR2F
    // 
    // Description : JCSCC Vector 2 functions struct.
    //====================================================================================
    typedef struct _JCS_IEMATH_VECTOR2F
    {
        union
        {
            float32 m[1][1];
            float32 v[2];

            struct
            {
                float32 x;
                float32 y;
            };
        };

        _JCS_IEMATH_VECTOR2F() {}
        _JCS_IEMATH_VECTOR2F(float32 x_, float32 y_)
            :
            x(x_),
            y(y_)
        {
        }

        /**
            Set the x, y value method.
        */
        void Set(float32 x_, float32 y_)
        {
            x = x_;
            y = y_;
        }

        /**
            Implemented Operator Minus.
        */
        _JCS_IEMATH_VECTOR2F operator-(void) const
        {
            return _JCS_IEMATH_VECTOR2F(-x, -y);
        }
        /**
            Implemented Operator Multiply.
        */
        _JCS_IEMATH_VECTOR2F operator*(float32 s) const
        {
            return _JCS_IEMATH_VECTOR2F(x * s, y * s);
        }
        /**
            Implemented Operator Divide.
        */
        _JCS_IEMATH_VECTOR2F operator/(float32 s) const
        {
            return _JCS_IEMATH_VECTOR2F(x / s, y / s);
        }

        /**
            Implemented Operator Multiply.
        */
        void operator*=(float32 s)
        {
            x *= s;
            y *= s;
        }

        /**
            Implemented Operator Plus.
        */
        _JCS_IEMATH_VECTOR2F operator+(const _JCS_IEMATH_VECTOR2F& rhs) const
        {
            return _JCS_IEMATH_VECTOR2F(x + rhs.x, y + rhs.y);
        }

        /**
            Implemented Operator Plus.
        */
        _JCS_IEMATH_VECTOR2F operator+(float32 s) const
        {
            return _JCS_IEMATH_VECTOR2F(x + s, y + s);
        }

        /**
            
        */
        void operator+=(const _JCS_IEMATH_VECTOR2F& rhs)
        {
            x += rhs.x;
            y += rhs.y;
        }

        _JCS_IEMATH_VECTOR2F operator-(const _JCS_IEMATH_VECTOR2F& rhs) const
        {
            return _JCS_IEMATH_VECTOR2F(x - rhs.x, y - rhs.y);
        }

        /**
            
        */
        void operator-=(const _JCS_IEMATH_VECTOR2F& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
        }

        /**
            
        */
        float32 LenSqr(void) const
        {
            return x * x + y * y;
        }

        /**
            
        */
        float32 Len(void) const
        {
            return std::sqrt(x * x + y * y);
        }

        /**
            Rotate by the vector point.
        */
        void Rotate(float32 radians)
        {
            float32 c = std::cos(radians);
            float32 s = std::sin(radians);

            float32 xp = x * c - y * s;
            float32 yp = x * s + y * c;

            x = xp;
            y = yp;
        }

        /**
            Calculate the nomarl vector from this vector.
        */
        void Normalize(void)
        {
            float32 len = Len();

            if (len > EPSILON)            // EPSILON 是浮點數容許值
            {
                float32 invLen = 1.0f / len;
                x *= invLen;
                y *= invLen;
            }
        }
    } JIVec2f;

    inline JIVec2f operator*(float s, const JIVec2f& v)
    {
        return JIVec2f(s * v.x, s * v.y);
    }

    //====================================================================================
    // Struct Name: _JCS_IEMATH_MATRIX2
    // 
    // Description : JCSCC Matrix defines.
    //====================================================================================
    typedef struct _JCS_IEMATH_MATRIX2
    {
        union {
            struct {
                float32 m00, m01;
                float32 m10, m11;
            };

            float32 m[2][2];
            float32 v[4];
        };

        _JCS_IEMATH_MATRIX2()
        {  }
        _JCS_IEMATH_MATRIX2(float32 radians)
        {
            float32 c = std::cos(radians);
            float32 s = std::sin(radians);

            m00 = c; m01 = -s;
            m10 = s; m11 = c;
        }
        _JCS_IEMATH_MATRIX2(float32 a, float32 b, float32 c, float32 d)
            : m00(a), m01(b)
            , m10(c), m11(d)
        {  }

        /**
            
        */
        void Set(float32 radians)
        {
            float32 c = std::cos(radians);
            float32 s = std::sin(radians);

            m00 = c; m01 = -s;
            m10 = s; m11 = c;
        }
        /**
            
        */
        _JCS_IEMATH_MATRIX2 Abs(void) const
        {
            return _JCS_IEMATH_MATRIX2(std::abs(m00), std::abs(m01), std::abs(m10), std::abs(m11));
        }
        /**
            
        */
        JIVec2f AxisX(void) const
        {
            return JIVec2f(m00, m10);
        }
        /**
            
        */
        JIVec2f AxisY(void) const
        {
            return JIVec2f(m01, m11);
        }
        /**
            
        */
        _JCS_IEMATH_MATRIX2 Transpose(void) const
        {
            return _JCS_IEMATH_MATRIX2(m00, m10, m01, m11);
        }

        /**
            
        */
        const JIVec2f operator*(const JIVec2f& rhs) const
        {
            return JIVec2f(m00 * rhs.x + m01 * rhs.y, m10 * rhs.x + m11 * rhs.y);
        }
        /**
            
        */
        const _JCS_IEMATH_MATRIX2 operator*(const _JCS_IEMATH_MATRIX2& rhs) const
        {
            return _JCS_IEMATH_MATRIX2(
                m[0][0] * rhs.m[0][0] + m[0][1] * rhs.m[1][0],
                m[0][0] * rhs.m[0][1] + m[0][1] * rhs.m[1][1],
                m[1][0] * rhs.m[0][0] + m[1][1] * rhs.m[1][0],
                m[1][0] * rhs.m[0][1] + m[1][1] * rhs.m[1][1]
                );
        }

    } JIMat2;

    //-- useful functions
    /**
        
    */
    inline JIVec2f Min(const JIVec2f& a, const JIVec2f& b)
    {
        return JIVec2f(min(a.x, b.x), min(a.y, b.y));
    }
    /**
        
    */
    inline JIVec2f Max(const JIVec2f& a, const JIVec2f& b)
    {
        return JIVec2f(max(a.x, b.x), max(a.y, b.y));
    }
    /**
        
    */
    inline float32 Dot(const JIVec2f& a, const JIVec2f& b)
    {
        return a.x * b.x + a.y * b.y;
    }
    /**
        
    */
    inline float32 DistSqr(const JIVec2f& a, const JIVec2f& b)
    {
        JIVec2f c = a - b;
        return Dot(c, c);
    }
    /**

    */
    inline JIVec2f Cross(const JIVec2f& v, float32 a)
    {
        return JIVec2f(a * v.y, -a * v.x);
    }
    /**

    */
    inline JIVec2f Cross(float32 a, const JIVec2f& v)
    {
        return JIVec2f(-a * v.y, a * v.x);
    }
    /**

    */
    inline float32 Cross(const JIVec2f& a, const JIVec2f& b)
    {
        return a.x * b.y - a.y * b.x;
    }
    /**
        Comparison with tolerance of EPSILON
    */
    inline bool Equal(float32 a, float32 b)
    {
        // <= instead of < for NaN comparison safety
        return std::abs(a - b) <= EPSILON;
    }
    /**
        Return the squared the value.

        @param value to square.
    */
    inline float32 Sqr(float32 a)
    {
        return a * a;
    }
    /**
        Compare the two value and return the by either of them, 
        this can be check to see if in the range.

        @param min value
        @param max value
        @param current value
    */
    inline float32 Clamp(float32 min, float32 max, float32 a)
    {
        if (a < min) return min;
        if (a > max) return max;
        return a;
    }
    /**
        Round the Float value to Integer value.

        @param value to round
    */
    inline int32 Round(float32 a)
    {
        return (int32)(a + 0.5f);
    }
    /**
        Return random value.

        @param lower value
        @param higher value
    */
    inline float32 Random(float32 l, float32 h)
    {
        float32 a = (float32)rand();
        a /= RAND_MAX;
        a = (h - l) * a + l;
        return a;
    }
    /**

    */
    inline bool BiasGreaterThan(float32 a, float32 b)
    {
        const float32 k_biasRelative = 0.95f;
        const float32 k_biasAbsolute = 0.01f;
        return a >= b * k_biasRelative + a * k_biasAbsolute;
    }

    const float32 gravityScale = 5.0f;
    const JIVec2f gravity(0, 10.0f * gravityScale);
    const float dt = 1.0f / 60.0f;

}

typedef JCS_GameInterface::JIVec2f JIVec2f;

#endif // __JCS_IEMATH_H__

