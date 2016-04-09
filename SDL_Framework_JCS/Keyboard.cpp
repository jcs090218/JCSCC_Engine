/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Keyboard.h"


namespace JCS_SDL_Engine
{
    Keyboard::Keyboard()
        : m_keyMap()
    {

    }

    Keyboard::~Keyboard()
    {

    }

    void Keyboard::update()
    {
        // Loop through "m_keyMap" using a for each, and copy it over to "m_previousKeyMap"
        for (auto& it : m_keyMap)
            m_previousKeyMap[it.first] = it.second;
    }

    void Keyboard::pressKey(uint32 keyID)
    {
        m_keyMap[keyID] = true;
    }

    void Keyboard::releaseKey(uint32 keyID)
    {
        m_keyMap[keyID] = false;
    }

    bool Keyboard::isKeyDown(uint32 keyID)
    {
        // Try to find the key cuz we do not want to return an un-intialize memory
        auto it = m_keyMap.find(keyID);

        if (it != m_keyMap.end()) {      // found it then return it
            return it->second;
        }
        else {                        // not found return false as default
            return false;
        }

    }

    bool Keyboard::isKeyPressed(uint32 keyID)
    {
        // Check if it is pressed this frame, and was't pressed last frame
        if (isKeyDown(keyID) && !wasKeyDown(keyID))
            return true;

        return false;
    }

    bool Keyboard::wasKeyDown(uint32 keyID)
    {
        // Try to find the key cuz we do not want to return an un-intialize memory
        auto it = m_previousKeyMap.find(keyID);

        if (it != m_previousKeyMap.end()) {      // found it then return it
            return it->second;
        }
        else {                        // not found return false as default
            return false;
        }
    }

}

