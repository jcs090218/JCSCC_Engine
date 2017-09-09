/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __GAMEPAD_H__
/**
 * $File: GamePad.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __GAMEPAD_H__


#include "..\GameInput_StdAfx.h"

namespace JCS_GameInput
{
    //====================================================================================---------------------------------------------------------------
    // Name : GamePad
    //
    // Description : 
    //====================================================================================---------------------------------------------------------------
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

        /** getter **/
        XINPUT_STATE GetState();
        XINPUT_GAMEPAD GetGamePad() const { return this->m_controllerState.Gamepad; }
    };

}

typedef JCS_GameInput::GamePad GamePad;

#endif // __GAMEPAD_H__

