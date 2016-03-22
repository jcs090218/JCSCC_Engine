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

