/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "BitmapFont.h"


inline void apply_surface(int32 x, int32 y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = nullptr)
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface(source, clip, destination, &offset);
}

inline Uint32 get_pixel32(int32 x, int32 y, SDL_Surface* surface)
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = static_cast<Uint32*>(surface->pixels);

    //Get the pixel requested
    return pixels[(y * surface->w) + x];
}

namespace JCS_SDL_Engine
{
    BitmapFont::BitmapFont()
        : m_pBitmap(nullptr)
        , m_newLine(0)
        , m_space(0)
    {

    }

    BitmapFont::BitmapFont(SDL_Surface* surface)
    {
        //Build the font
        build_font(surface);
    }

    BitmapFont::~BitmapFont()
    {

    }

    void BitmapFont::build_font(SDL_Surface* surface)
    {
        //If surface is nullptr
        if (!surface)
            return;

        //Get the bitmap
        m_pBitmap = surface;

        //Set the background color
        Uint32 bgColor = SDL_MapRGB(m_pBitmap->format, 0, 0xFF, 0xFF);

        //Set the cell dimensions
        int32 cellW = m_pBitmap->w / 16;
        int32 cellH = m_pBitmap->h / 16;

        //New line variables
        int32 top = cellH;
        int32 baseA = cellH;

        //The current character we're setting
        int32 currentChar = 0;

        //Go through the cell rows
        for (int32 rows = 0; rows < 16; rows++)
        {
            //Go through the cell columns
            for (int32 cols = 0; cols < 16; cols++)
            {
                //Set the character offset
                m_chars[currentChar].x = cellW * cols;
                m_chars[currentChar].y = cellH * rows;

                //Set the dimensions of the character
                m_chars[currentChar].w = cellW;
                m_chars[currentChar].h = cellH;

                //Find Left Side
                //Go through pixel columns
                for (int32 pCol = 0; pCol < cellW; pCol++)
                {
                    //Go through pixel rows
                    for (int32 pRow = 0; pRow < cellH; pRow++)
                    {
                        //Get the pixel offsets
                        int32 pX = (cellW * cols) + pCol;
                        int32 pY = (cellH * rows) + pRow;

                        //If a non colorkey pixel is found
                        if (get_pixel32(pX, pY, m_pBitmap) != bgColor)
                        {
                            //Set the x offset
                            m_chars[currentChar].x = pX;

                            //Break the loops
                            pCol = cellW;
                            pRow = cellH;
                        }
                    }
                }

                //Find Right Side
                //Go through pixel columns
                for (int32 pCol_w = cellW - 1; pCol_w >= 0; pCol_w--)
                {
                    //Go through pixel rows
                    for (int32 pRow_w = 0; pRow_w < cellH; pRow_w++)
                    {
                        //Get the pixel offsets
                        int32 pX = (cellW * cols) + pCol_w;
                        int32 pY = (cellH * rows) + pRow_w;

                        //If a non colorkey pixel is found
                        if (get_pixel32(pX, pY, m_pBitmap) != bgColor)
                        {
                            //Set the width
                            m_chars[currentChar].w = (pX - m_chars[currentChar].x) + 1;

                            //Break the loops
                            pCol_w = -1;
                            pRow_w = cellH;
                        }
                    }
                }

                //Find Top
                //Go through pixel rows
                for (int32 pRow = 0; pRow < cellH; pRow++)
                {
                    //Go through pixel columns
                    for (int32 pCol = 0; pCol < cellW; pCol++)
                    {
                        //Get the pixel offsets
                        int32 pX = (cellW * cols) + pCol;
                        int32 pY = (cellH * rows) + pRow;

                        //If a non colorkey pixel is found
                        if (get_pixel32(pX, pY, m_pBitmap) != bgColor)
                        {
                            //If new top is found
                            if (pRow < top)
                            {
                                top = pRow;
                            }

                            //Break the loops
                            pCol = cellW;
                            pRow = cellH;
                        }
                    }
                }

                //Find Bottom of A
                if (currentChar == 'A')
                {
                    //Go through pixel rows
                    for (int32 pRow = cellH - 1; pRow >= 0; pRow--)
                    {
                        //Go through pixel columns
                        for (int32 pCol = 0; pCol < cellW; pCol++)
                        {
                            //Get the pixel offsets
                            int32 pX = (cellW * cols) + pCol;
                            int32 pY = (cellH * rows) + pRow;

                            //If a non colorkey pixel is found
                            if (get_pixel32(pX, pY, m_pBitmap) != bgColor)
                            {
                                //Bottom of a is found
                                baseA = pRow;

                                //Break the loops
                                pCol = cellW;
                                pRow = -1;
                            }
                        }
                    }
                }

                //Go to the next character
                currentChar++;
            }
        }

        //Calculate space
        m_space = cellW / 2;

        //Calculate new line
        m_newLine = baseA - top;

        //Lop off excess top pixels
        for (int32 t = 0; t < 256; ++t)
        {
            m_chars[t].y += top;
            m_chars[t].h -= top;
        }
    }

    void BitmapFont::show_text(int32 x, int32 y, std::string text, SDL_Surface* surface)
    {
        //Temp offsets
        int32 X = x, Y = y;

        //If the font has been built
        if (!m_pBitmap)
            return;
        
        //Go through the text
        for (uint32 show = 0; show < text.length(); ++show)
        {
            //If the current character is a space
            if (text[show] == ' ')
            {
                //Move over
                X += m_space;
            }
            //If the current character is a newline
            else if (text[show] == '\n')
            {
                //Move down
                Y += m_newLine;

                //Move back
                X = x;
            }
            else
            {
                //Get the ASCII value of the character
                int32 ascii = static_cast<uint8>(text[show]);

                //Show the character
                apply_surface(X, Y, m_pBitmap, surface, &m_chars[ascii]);

                //Move over the width of the character with one pixel of padding
                X += m_chars[ascii].w + 1;
            }
        }
    }

}

