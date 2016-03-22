#ifndef __JCS_GAMETYPE_H__
#define __JCS_GAMETYPE_H__


#include <JayCeS_JCS\JCS_Name.h>

namespace JCS_GameInterface
{
	/**
	 * r : RED, g : GREEN, b : BLUE, a : ALPHA
	 */
	typedef struct _JCS_COLOR4F
	{
		float r;
		float g;
		float b;
		float a;

		_JCS_COLOR4F(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f)
			: r(r), g(g), b(b), a(a)
		{  }
		~_JCS_COLOR4F() {  }
	} JCS_COLOR4F;
	/**
	 * x : X coordinate, y : Y coordinate
	 */
	typedef struct _JCS_VECTOR2F
	{
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

	/**
	 * x : X coordinate, y : Y coordinate, z : Z coordinate
	 */
	typedef struct _JCS_VECTOR3F
	{
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
	/**
	 * x : X coordinate, y : Y coordinate, z : Z coordinate, w : W coordinate
	 */
	typedef struct _JCS_VECTOR4F
	{
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
		JCS_VECTOR2F topLeft;			// top left corner
		JCS_VECTOR2F bottomRight;		// bottom right corner
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

