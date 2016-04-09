/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __SFML_WINDOW_H__
#define __SFML_WINDOW_H__


#include "SFML_StdAfx.h"

namespace JCS_SFML_Engine
{

    //-----------------------------------------------------------------------------------------------------------
    // Name : Window
    // 
    // Desc : 
    //-----------------------------------------------------------------------------------------------------------
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

        // setter 

        // getter 

    };
}

#endif // __SFML_WINDOW_H__

