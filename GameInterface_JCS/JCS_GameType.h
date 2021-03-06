#ifndef __JCS_GAMETYPE_H__
/**
 * $File: JCS_GameType.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_GAMETYPE_H__


#include <JayCeS_JCS\JCS_Name.h>

namespace JCS_GameInterface
{
    
    //====================================================================================
    // Struct Name: _JCS_IEMATH_VECTOR2F
    // 
    // Description : JCSCC Color 4 functions struct.
    //             r: RED, g : GREEN, b : BLUE, a : ALPHA
    //====================================================================================
    typedef struct _JCS_COLOR4F
    {
        float r;    // red
        float g;    // green
        float b;    // blue
        float a;    // alpha

        _JCS_COLOR4F(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f)
            : r(r), g(g), b(b), a(a)
        {  }
        ~_JCS_COLOR4F() {  }
    } JCS_COLOR4F;
    
    //====================================================================================
    // Struct Name: _JCS_VECTOR2F
    // 
    // Description : JCSCC Vector 2 functions struct.
    //             x : X coordinate, y : Y coordinate
    //====================================================================================
    typedef struct _JCS_VECTOR2F
    {
		/** equals to JCS_VECTOR2F(0,0) */
		static const _JCS_VECTOR2F ZERO;
		/** equals to JCS_VECTOR2F(1,1) */
		static const _JCS_VECTOR2F ONE;
		/** equals to JCS_VECTOR2F(1,0) */
		static const _JCS_VECTOR2F UNIT_X;
		/** equals to JCS_VECTOR2F(0,1) */
		static const _JCS_VECTOR2F UNIT_Y;
		/** equals to JCS_VECTOR2F(0.5, 0.5) */
		static const _JCS_VECTOR2F ANCHOR_MIDDLE;
		/** equals to JCS_VECTOR2F(0, 0) */
		static const _JCS_VECTOR2F ANCHOR_BOTTOM_LEFT;
		/** equals to JCS_VECTOR2F(0, 1) */
		static const _JCS_VECTOR2F ANCHOR_TOP_LEFT;
		/** equals to JCS_VECTOR2F(1, 0) */
		static const _JCS_VECTOR2F ANCHOR_BOTTOM_RIGHT;
		/** equals to JCS_VECTOR2F(1, 1) */
		static const _JCS_VECTOR2F ANCHOR_TOP_RIGHT;
		/** equals to JCS_VECTOR2F(1, 0.5) */
		static const _JCS_VECTOR2F ANCHOR_MIDDLE_RIGHT;
		/** equals to JCS_VECTOR2F(0, 0.5) */
		static const _JCS_VECTOR2F ANCHOR_MIDDLE_LEFT;
		/** equals to JCS_VECTOR2F(0.5, 1) */
		static const _JCS_VECTOR2F ANCHOR_MIDDLE_TOP;
		/** equals to JCS_VECTOR2F(0.5, 0) */
		static const _JCS_VECTOR2F ANCHOR_MIDDLE_BOTTOM;

        float x;
        float y;

        _JCS_VECTOR2F(float x = 0.0f, float y = 0.0f)
            : x(x), y(y)
        {  }
        ~_JCS_VECTOR2F()
        {  }

        // 如果會更改本身的Components, 則不要加const
        _JCS_VECTOR2F& operator=(const _JCS_VECTOR2F& vec)
        {
            this->x = vec.x;
            this->y = vec.y;
            return *this;
        }

        // 這裡我們只回傳結果, 不會更改自身的Components, 所以可以加const
        _JCS_VECTOR2F operator+(const _JCS_VECTOR2F& vec) const
        {
            return _JCS_VECTOR2F(this->x + vec.x, this->y + vec.y);
        }
        _JCS_VECTOR2F operator-(const _JCS_VECTOR2F& vec) const
        {
            return _JCS_VECTOR2F(this->x - vec.x, this->y - vec.y);
        }
        _JCS_VECTOR2F operator/(const _JCS_VECTOR2F& vec) const
        {
            return _JCS_VECTOR2F(this->x / vec.x, this->y / vec.y);
        }
        _JCS_VECTOR2F operator*(const _JCS_VECTOR2F& vec) const
        {
            return _JCS_VECTOR2F(this->x * vec.x, this->y * vec.y);
        }

        bool operator==(const _JCS_VECTOR2F& vec) const
        {
            return (x == vec.x && y == vec.y);
        }
        void operator-=(const _JCS_VECTOR2F& vec)
        {
            x -= vec.x;
            y -= vec.y;
        }
        void operator+=(const _JCS_VECTOR2F& vec)
        {
            x += vec.x;
            y += vec.y;
        }

    } JCS_VECTOR2F;

    // "向量"or"純量"運算
    inline JCS_VECTOR2F operator*(float force, const JCS_VECTOR2F& vector)
    {
        return JCS_VECTOR2F(force * vector.x, force * vector.y);
    }
    inline JCS_VECTOR2F operator+(const JCS_VECTOR2F& vector1, const JCS_VECTOR2F& vector2)
    {
        return JCS_VECTOR2F(vector2.x + vector1.x, vector2.y + vector1.y);
    }

    //====================================================================================
    // Struct Name: _JCS_VECTOR3F
    // 
    // Description : JCSCC Vector 3 functions struct.
    //             x : X coordinate, y : Y coordinate, 
    //             z : Z coordinate
    //====================================================================================
    typedef struct _JCS_VECTOR3F
    {
		/** equals to Vec3(0,0,0) */
		static const _JCS_VECTOR3F ZERO;
		/** equals to Vec3(1,1,1) */
		static const _JCS_VECTOR3F ONE;
		/** equals to Vec3(1,0,0) */
		static const _JCS_VECTOR3F UNIT_X;
		/** equals to Vec3(0,1,0) */
		static const _JCS_VECTOR3F UNIT_Y;
		/** equals to Vec3(0,0,1) */
		static const _JCS_VECTOR3F UNIT_Z;

        float x;
        float y;
        float z;

        _JCS_VECTOR3F(float x = 0.0f, float y = 0.0f, float z = 0.0f)
            : x(x), y(y), z(z)
        {  }
        ~_JCS_VECTOR3F()
        {  }

        // 如果會更改本身的Components, 則不要加const
        _JCS_VECTOR3F& operator=(const _JCS_VECTOR3F& vec)
        {
            this->x = vec.x;
            this->y = vec.y;
            this->z = vec.z;
            return *this;
        }

        // 這裡我們只回傳結果, 不會更改自身的Components, 所以可以加const
        _JCS_VECTOR3F operator+(const _JCS_VECTOR3F& vec) const
        {
            return _JCS_VECTOR3F(this->x + vec.x, this->y + vec.y, this->z + vec.z);
        }
        _JCS_VECTOR3F operator-(const _JCS_VECTOR3F& vec) const
        {
            return _JCS_VECTOR3F(this->x - vec.x, this->y - vec.y, this->z - vec.z);
        }
        _JCS_VECTOR3F operator/(const _JCS_VECTOR3F& vec) const
        {
            return _JCS_VECTOR3F(this->x / vec.x, this->y / vec.y, this->z / vec.z);
        }
        _JCS_VECTOR3F operator*(const _JCS_VECTOR3F& vec) const
        {
            return _JCS_VECTOR3F(this->x * vec.x, this->y * vec.y, this->z * vec.z);
        }

        bool operator==(const _JCS_VECTOR3F& vec) const
        {
            return (x == vec.x && y == vec.y && z == vec.z);
        }
        void operator-=(const _JCS_VECTOR3F& vec)
        {
            x -= vec.x;
            y -= vec.y;
            z -= vec.z;
        }
        void operator+=(const _JCS_VECTOR3F& vec)
        {
            x += vec.x;
            y += vec.y;
            z += vec.z;
        }
    } JCS_VECTOR3F;

    //====================================================================================
    // Struct Name: _JCS_VECTOR4F
    // 
    // Description : JCSCC Vector 4 functions struct.
    //             x : X coordinate, y : Y coordinate, 
    //             z : Z coordinate, w : W coordinate
    //====================================================================================
    typedef struct _JCS_VECTOR4F
    {
		/** equals to Vec4(0,0,0,0) */
		static const _JCS_VECTOR4F ZERO;
		/** equals to Vec4(1,1,1,1) */
		static const _JCS_VECTOR4F ONE;
		/** equals to Vec4(1,0,0,0) */
		static const _JCS_VECTOR4F UNIT_X;
		/** equals to Vec4(0,1,0,0) */
		static const _JCS_VECTOR4F UNIT_Y;
		/** equals to Vec4(0,0,1,0) */
		static const _JCS_VECTOR4F UNIT_Z;
		/** equals to Vec4(0,0,0,1) */
		static const _JCS_VECTOR4F UNIT_W;

        float x; 
        float y;
        float z;
        float w;

        _JCS_VECTOR4F(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
            : x(x), y(y), z(z), w(w)
        {  }
        ~_JCS_VECTOR4F()
        {  }

        // 如果會更改本身的Components, 則不要加const
        _JCS_VECTOR4F& operator=(const _JCS_VECTOR4F& vec)
        {
            this->x = vec.x;
            this->y = vec.y;
            this->z = vec.z;
            this->w = vec.w;
            return *this;
        }

        // 這裡我們只回傳結果, 不會更改自身的Components, 所以可以加const
        _JCS_VECTOR4F operator+(const _JCS_VECTOR4F& vec) const
        {
            return _JCS_VECTOR4F(this->x + vec.x, this->y + vec.y, this->z + vec.z, this->w + vec.w);
        }
        _JCS_VECTOR4F operator-(const _JCS_VECTOR4F& vec) const
        {
            return _JCS_VECTOR4F(this->x - vec.x, this->y - vec.y, this->z - vec.z, this->w - vec.w);
        }
        _JCS_VECTOR4F operator/(const _JCS_VECTOR4F& vec) const
        {
            return _JCS_VECTOR4F(this->x / vec.x, this->y / vec.y, this->z / vec.z, this->w / vec.w);
        }
        _JCS_VECTOR4F operator*(const _JCS_VECTOR4F& vec) const
        {
            return _JCS_VECTOR4F(this->x * vec.x, this->y * vec.y, this->z * vec.z, this->w * vec.w);
        }

        bool operator==(const _JCS_VECTOR4F& vec) const
        {
            return (x == vec.x && y == vec.y && z == vec.z && w == vec.w);
        }
        void operator-=(const _JCS_VECTOR4F& vec)
        {
            x -= vec.x;
            y -= vec.y;
            z -= vec.z;
            w -= vec.w;
        }
        void operator+=(const _JCS_VECTOR4F& vec)
        {
            x += vec.x;
            y += vec.y;
            z += vec.z;
            w += vec.w;
        }

    } JCS_VECTOR4F;

    /**
     * 記錄兩點 作出一個矩形
     *
     * JCS_VECTOR2F topLeft : x, y
     * JCS_VECTOR2F bottomRight : x, y
     */
    typedef struct _JCS_RECT
    {
        JCS_VECTOR2F topLeft;            // top left corner
        JCS_VECTOR2F bottomRight;        // bottom right corner
    } JCS_RECT;

    /**
     * float radius : 半徑
     */
    typedef struct _JCS_CIRCLE
    {
        float radius;
    } JCS_CIRCLE;

} // end namespace "JCS_GameInterface"


typedef JCS_GameInterface::JCS_COLOR4F JCS_COLOR4F;

typedef JCS_GameInterface::JCS_VECTOR2F JCS_VECTOR2F;
typedef JCS_GameInterface::JCS_VECTOR3F JCS_VECTOR3F;
typedef JCS_GameInterface::JCS_VECTOR4F JCS_VECTOR4F;

typedef JCS_GameInterface::JCS_RECT JCS_RECT;
typedef JCS_GameInterface::JCS_CIRCLE JCS_CIRCLE;

#endif // __JCS_GAMETYPE_H__

