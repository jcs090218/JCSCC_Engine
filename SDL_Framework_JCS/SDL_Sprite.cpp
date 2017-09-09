/**
 * $File: SDL_Sprite.cpp $
 * $Date: 2016-11-09 22:44:14 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "SDL_Sprite.h"


namespace JCS_SDL_Engine
{

	SDL_Sprite::SDL_Sprite()
		: m_pSurface(nullptr)
	{

	}

	SDL_Sprite::~SDL_Sprite()
	{
		SDL_FreeSurface(m_pSurface);
		m_pSurface = nullptr;
	}

	void SDL_Sprite::Update(float32 deltaTime)
	{
		// check active?
		if (!m_active)
			return;

	}

	void SDL_Sprite::Draw(SDL_Surface* screenSurface)
	{
		// check active?
		if (!m_active)
			return;

		SDL_BlitSurface(m_pSurface, NULL, screenSurface, NULL);
	}

	bool SDL_Sprite::LoadSprite(char* filePath, char* ext)
	{
		// combine tow char pointer.
		std::string fullFilePath = filePath;
		fullFilePath += ext;

		// load the sprite using SDL api.
		m_pSurface = SDL_LoadBMP(fullFilePath.c_str());

		// check success?
		if (!m_pSurface)
		{
			printf("Unable to load image %s! SDL Error: %s\n", fullFilePath.c_str(), SDL_GetError());
			return false;
		}

		return true;
	}

}
