/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __SDL_MOUSE_H__
#define __SDL_MOUSE_H__

#include "SDL_StdAfx.h"
#include <OpenGL_Framework_JCS\OpenGL\include\glm\glm.hpp>

namespace JCS_SDL_Engine
{
    class Mouse
    {
    private:
        glm::vec2 m_mouseCoords;

    public:
        Mouse();
        ~Mouse();

        // setter
        void SetMouseCoords(float32 x, float32 y);

        // getter
        glm::vec2 GetMouseCoords() { return this->m_mouseCoords; }
    };

}

#endif // __SDL_MOUSE_H__

