/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Mouse.h"


namespace JCS_SDL_Engine
{
    Mouse::Mouse()
        : m_mouseCoords(0.0f)
    {

    }

    Mouse::~Mouse()
    {

    }

    void Mouse::SetMouseCoords(float32 x, float32 y)
    {
        m_mouseCoords.x = x;
        m_mouseCoords.y = y;
    }

}

