#ifndef __SDL_SPRITE_H__
/**
 * $File: SDL_Sprite.h $
 * $Date: 2016-11-09 22:42:34 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __SDL_SPRITE_H__

#include "SDL_StdAfx.h"


namespace JCS_SDL_Engine
{

	//====================================================================================
	// Name : SDL_Sprite 
	//
	// Description : Sprite Handle.
	// SOURCE(jenchieh): http://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php
	//====================================================================================
	class SDL_Sprite
	{
	private:
		SDL_Surface* m_pSurface = nullptr;
		bool m_active = true;

	public:
		SDL_Sprite();
		virtual ~SDL_Sprite();

		void Update(float32 deltaTime);
		void Draw(SDL_Surface* screenSurface);

		/**
			Load the sprite from the path.
		*/
		bool LoadSprite(char* filePath, char* ext);

		/** setter **/

		/** getter **/

	};
}

#endif // __SDL_SPRITE_H__
