#ifndef __SFML_WINDOW_H__
/**
 * $File: Window.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __SFML_WINDOW_H__


#include "SFML_StdAfx.h"

namespace JCS_SFML_Engine
{

    //====================================================================================-----------------------
    // Name : Window
    // 
    // Description : 
    //====================================================================================-----------------------
    class Window
    {
    private:
        sf::RenderWindow* m_pWindow;

    public:
        Window(std::string title = WINDOW_TITLE, int width = SCREEN_WIDTH, int height = SCREEN_HEIGHT);
        ~Window();

        void Initialize(void);
        void Close(void);

        void Clear() { m_pWindow->clear(); }

        /** setter **/ 

        /** getter **/ 

    };
}

#endif // __SFML_WINDOW_H__
