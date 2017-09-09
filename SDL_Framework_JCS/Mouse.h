/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
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

	//====================================================================================
	// Name : Mouse 
	//
	// Description : 
	//====================================================================================
    class Mouse
    {
    private:
        glm::vec2 m_mouseCoords;

		bool m_mouseDownThisFrame = false;
		bool m_mouseIsDown = false;
		bool m_mouseUpThisFrame = false;

    public:
        Mouse();
        ~Mouse();

		void SetMouseButton(const bool act)
		{
			this->m_mouseIsDown = act;
		}
		void SetMouseButtonDown(const bool act)
		{
			this->m_mouseDownThisFrame = act;
		}
		void SetMouseButtonUp(const bool act)
		{
			this->m_mouseUpThisFrame = act;
		}

		bool GetMouseButton() const
		{
			return this->m_mouseIsDown;
		}
		bool GetMouseButtonDown() const
		{
			return this->m_mouseDownThisFrame;
		}
		bool GetMouseButtonUp() const
		{
			return this->m_mouseUpThisFrame;
		}

        /** setter **/
        void SetMouseCoords(float32 x, float32 y);

        /** getter **/
        glm::vec2 GetMouseCoords() { return this->m_mouseCoords; }
    };

}

#endif // __SDL_MOUSE_H__

