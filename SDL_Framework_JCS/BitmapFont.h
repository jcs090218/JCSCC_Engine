#ifndef __BITMAPFONT_H__
/**
 * $File: BitmapFont.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __BITMAPFONT_H__


#include "SDL_StdAfx.h"


namespace JCS_SDL_Engine
{
	
	//====================================================================================
	// Name : BitmapFont 
	//
	// Description : 
	//====================================================================================
    class BitmapFont
    {
    private:
        SDL_Surface* m_pBitmap;
        SDL_Rect m_chars[256];
        int32 m_newLine, m_space;

    public:
        BitmapFont();
        BitmapFont(SDL_Surface* surface);
        ~BitmapFont();

        void build_font(SDL_Surface* surface);

        void show_text(int32 x, int32 y, std::string text, SDL_Surface* surface);
    };

}

#endif //  __BITMAPFONT_H__
