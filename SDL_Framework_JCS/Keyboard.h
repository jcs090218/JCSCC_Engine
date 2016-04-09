/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __SDL_KEYBOARD_H__
#define __SDL_KEYBOARD_H__


#include "SDL_StdAfx.h"

namespace JCS_SDL_Engine
{
    class Keyboard
    {
    private:
        std::unordered_map<uint32, bool> m_keyMap;
        std::unordered_map<uint32, bool> m_previousKeyMap;

    public:
        Keyboard();
        ~Keyboard();

        void update();

        void pressKey(uint32 keyID);
        void releaseKey(uint32 keyID);

        // Returns true if the key is held down
        bool isKeyDown(uint32 keyID);

        // Returns turn if the key was just pressed
        bool isKeyPressed(uint32 keyID);

    private:
        bool wasKeyDown(uint32 keyID);
    };

}

#endif // __SDL_KEYBOARD_H__

