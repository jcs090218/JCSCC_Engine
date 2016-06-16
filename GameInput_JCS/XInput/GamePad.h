/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __GAMEPAD_H__
#define __GAMEPAD_H__


#include "..\GameInput_StdAfx.h"

namespace JCS_GameInput
{
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : GamePad
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class GamePad
        : public JCS_Input
    {
    private:
        XINPUT_STATE m_controllerState;
        ulong32 m_controllerIndex;

    public:
        GamePad();
        ~GamePad();

        void LoadXInput(void);

        bool IsConnected();

        bool isButtonPressed(ulong32 button);
        void Vibrate(int32 leftVal = 0, int32 rightVal = 0);

        // getter
        XINPUT_STATE GetState();
        XINPUT_GAMEPAD GetGamePad() const { return this->m_controllerState.Gamepad; }
    };

}

typedef JCS_GameInput::GamePad GamePad;

#endif // __GAMEPAD_H__

