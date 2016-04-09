/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __INPUTMANAGER_H__
#define __INPUTMANAGER_H__


#include <GameInput_JCS\DirectInput\Keyboard.h>
#include <GameInput_JCS\DirectInput\Mouse.h>

#include <GameInput_JCS\XInput\GamePad.h>

namespace JCS_GameTool
{
    
    //------------------------------------------------------------------------------------
    // Name : InputManager 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
	class InputManager
	{
	private:
		static InputManager* s_pInputManager;
        InputManager();


		JCS_GameInput::KeyboardClient* m_pKeyboardClient;		// for keyboard input
        JCS_GameInput::MouseClient* m_pMouseClient;		// for mouse input

        JCS_Input* m_pInput;    // Platform controller

	public:
		virtual ~InputManager();

        static InputManager* getInstance()
		{
			if (!s_pInputManager)
				s_pInputManager = new InputManager();
			return s_pInputManager;
		}

        void setKeyboard(KeyboardServer* kServer);
        void setMouse(const MouseServer* mServer);
        void setInput(JCS_Input* pInput) { this->m_pInput = pInput; }


		// getter
        JCS_GameInput::KeyboardClient* getKeyboard() const { return this->m_pKeyboardClient; }
        JCS_GameInput::MouseClient* getMouse() const { return this->m_pMouseClient; }
        JCS_Input* getInputAsPtr() const { return this->m_pInput; }
        JCS_Input& getInputAsRef() const { return *(this->m_pInput); }

        // PS4
        // ...

        // XBox 360
        GamePad* getGamePad_XBox360_AsPtr() const { return dynamic_cast<GamePad*>(m_pInput); }
        GamePad& getGamePad_XBox360_AsRef() const { return *(dynamic_cast<GamePad*>(m_pInput)); }

        // XBox One
        // ...
	};

}

typedef JCS_GameTool::InputManager InputManager;

#endif // __INPUTMANAGER_H__

