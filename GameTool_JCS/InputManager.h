#ifndef __INPUTMANAGER_H__
/**
 * $File: InputManager.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __INPUTMANAGER_H__


#include <GameInput_JCS\DirectInput\Keyboard.h>
#include <GameInput_JCS\DirectInput\Mouse.h>

#include <GameInput_JCS\XInput\GamePad.h>

namespace JCS_GameTool
{
    
    //====================================================================================
    // Class Name : InputManager 
    //
    // Description : Manage the input of the application layer.
    //====================================================================================
    class InputManager
		: public JCSSTL::JCSSTL_Singleton<InputManager>
    {
    private:
		friend class JCSSTL::JCSSTL_Singleton<InputManager>;

        JCS_GameInput::KeyboardClient* m_pKeyboardClient;        // for keyboard input
        JCS_GameInput::MouseClient* m_pMouseClient;        // for mouse input

        JCS_Input* m_pInput;    // Platform controller

    public:
        virtual ~InputManager();

        /** Set the keyboard devices. */
        void setKeyboard(KeyboardServer* kServer);
        /** Set the mouse devices. */
        void setMouse(const MouseServer* mServer);
        /**  */
        void setInput(JCS_Input* pInput) { this->m_pInput = pInput; }


        /** getter **/
        /** Get the keyboard device by pointer. */
        JCS_GameInput::KeyboardClient* getKeyboard() const { return this->m_pKeyboardClient; }
        /** Get the keyboard device by reference. */
        JCS_GameInput::MouseClient* getMouse() const { return this->m_pMouseClient; }
        /**  */
        JCS_Input* getInputAsPtr() const { return this->m_pInput; }
        /**  */
        JCS_Input& getInputAsRef() const { return *(this->m_pInput); }

        // PS4
        // ...

        // XBox 360
        /** Get the XBOX 360 GamePad hardware api device by pointer. */
        GamePad* getGamePad_XBox360_AsPtr() const { return dynamic_cast<GamePad*>(m_pInput); }
        /** Get the XBOX 360 GamePad hardware api device by reference. */
        GamePad& getGamePad_XBox360_AsRef() const { return *(dynamic_cast<GamePad*>(m_pInput)); }

        // XBox One
        // ...

	private:
		// Constructor
		InputManager();
		InputManager(const InputManager& right) = delete;
    };

}

typedef JCS_GameTool::InputManager InputManager;

#endif // __INPUTMANAGER_H__

