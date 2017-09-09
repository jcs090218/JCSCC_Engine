/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Keyboard.h"
#include <stdio.h>


namespace JCS_SDL_Engine
{
    Keyboard::Keyboard()
        : m_keysPressedThisFrame()
		, m_keysReleasedThisFrame()
		, m_keysDown()
    {

    }

    Keyboard::~Keyboard()
    {

    }

	// Use track the key.
    void Keyboard::update()
    {
		// clear everything back to false.
		for (auto it = m_keysPressedThisFrame.begin(); it != m_keysPressedThisFrame.end(); ++it)
			m_keysPressedThisFrame[it->first] = false;

		for (auto it = m_keysReleasedThisFrame.begin(); it != m_keysReleasedThisFrame.end(); ++it)
			m_keysReleasedThisFrame[it->first] = false;
    }

    void Keyboard::KeysPressedThisFrame(uint32 keyID, bool act)
    {
		// if already is down do nothing.
		if (GetKey(keyID))
			return;

		// Here we are treating _keyMap as an associative array.
		// if keyID doesn't already exist in _keyMap, it will get added
		m_keysPressedThisFrame[keyID] = act;
    }

    void Keyboard::KeysReleasedThisFrame(uint32 keyID, bool act)
    {
		m_keysReleasedThisFrame[keyID] = act;
    }

	void Keyboard::KeyDownThisFrame(uint32 keyID, bool act)
	{
		m_keysDown[keyID] = act;
	}

	// Returns turn if the key was just pressed
    bool Keyboard::GetKeyDown(uint32 keyID)
    {
		auto it = m_keysPressedThisFrame.find(keyID);
		if (it != m_keysPressedThisFrame.end() && !GetKeyUp(keyID))
		{
			// Found the key
			return it->second;
		}

		return false;
    }

	// Returns true if the key is held down
    bool Keyboard::GetKey(uint32 keyID)
    {
		auto it = m_keysDown.find(keyID);
		if (it != m_keysDown.end())
		{
			// Found the key
			return it->second;
		}

		return false;
    }

    bool Keyboard::GetKeyUp(uint32 keyID)
    {
		auto it = m_keysReleasedThisFrame.find(keyID);
		if (it != m_keysReleasedThisFrame.end())
		{
			// Found the key
			return it->second;
		}

		return false;
    }

}

