#ifndef _D2D_SPRITE2D_H
#define _D2D_SPRITE2D_H

#include "D2D_StdAfx.h"

#include "Graphics2D.h"		// Includes windows and D2d1.h

namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Sprite2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
	class Sprite2D
	{
	private:
		Graphics2D& gDevice2D;		// Reference to the graphics class
		ID2D1Bitmap* bmp;		// Bitmap loaded file and coverted to Direct2D format

        // For animation this is regarded as origin, 
        // but if just a sprite then will regarded as position
        JCS_VECTOR2F m_topLeft;
        JCS_VECTOR2F m_bottomRight;
        float32 m_spriteWidth, m_spriteHeight;

        JCS_VECTOR2F m_origin;

        // alpha blending
        float32 m_alpha;

        // Scale
        JCS_VECTOR2F m_originScale;

	public:
		Sprite2D(wchar_t* filename, Graphics2D& gfx);
		~Sprite2D();

		void update(float32 gameTime);
		void draw();	// Draw the bitmap to the render target

        // setter
        void SetOrigin(const JCS_VECTOR2F origin) { this->m_origin = origin; }

        // getter
        JCS_VECTOR2F GetOrigin() const { return this->m_origin; }
	};
}

#endif	// _D2D_SPRITE2D_H

