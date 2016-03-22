#ifndef __TRIANGLE_2D__
#define __TRIANGLE_2D__

#include "Shape2D.h"


namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Triangle2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
	class Triangle2D 
        : public Shape2D
	{
	private:
	    JCS_VECTOR2F p0, p1, p2;

	public:
		Triangle2D(JCS_VECTOR2F p0, JCS_VECTOR2F p1, JCS_VECTOR2F p2, 
			Graphics2D& gfx, bool autoPivot = true);
		virtual ~Triangle2D();

		virtual void initialize() override;
		virtual void update(const float32 gameTime) override;
		virtual void draw() override;

		virtual void rotation_rotate(float32 angle = 1.0f) override;
		virtual void revolution_rotate(GameObject2D& target, float32 angle = 1.0f) override;
	};
}

#endif // __TRIANGLE_2D__

