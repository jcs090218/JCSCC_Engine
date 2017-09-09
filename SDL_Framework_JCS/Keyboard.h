/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __SDL_KEYBOARD_H__
#define __SDL_KEYBOARD_H__


#include "SDL_StdAfx.h"

namespace JCS_SDL_Engine
{

	/**
	 * @class Keyboard
	 * @brief Handle keyboard buffer from OS layer to application layer.
	 */
    class Keyboard
    {
    private:
        std::unordered_map<uint32, bool> m_keysPressedThisFrame;
        std::unordered_map<uint32, bool> m_keysReleasedThisFrame;
		std::unordered_map<uint32, bool> m_keysDown;

    public:
        Keyboard();
        ~Keyboard();

		/**
		 * @func update
		 * @brief Use track the key.
		 */
        void update();

        void KeysPressedThisFrame(uint32 keyID, bool act);
        void KeysReleasedThisFrame(uint32 keyID, bool act);
		void KeyDownThisFrame(uint32 keyID, bool act);

		/**
		 * @func GetKey
		 * @brief Returns turn if the key was just pressed
		 * @param uint32 : key buffer id.
		 * return bool : is key down?
		 */
        bool GetKeyDown(uint32 keyID);
        
		/**
		 * @func GetKey
		 * @brief Returns true if the key is held down
		 * @param uint32 : key buffer id.
		 * return bool : is key held down?
		 */
        bool GetKey(uint32 keyID);

		/** 
		 * @func GetKeyUp
		 * @brief Return true if the key is up.
		 * @param uint32 : key buffer id.
		 * return bool : is key up?
		 */
        bool GetKeyUp(uint32 keyID);
    };

}

#endif // __SDL_KEYBOARD_H__

