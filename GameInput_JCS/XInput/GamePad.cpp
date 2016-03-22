#include "GamePad.h"


#define X_INPUT_GET_STATE(name) DWORD WINAPI name(DWORD dwUserIndex, XINPUT_STATE *pState)
typedef X_INPUT_GET_STATE(x_input_get_state);
X_INPUT_GET_STATE(XInputGetStateStub)
{
    return(0);
}
static x_input_get_state *XInputGetState_ = XInputGetStateStub;
#define XInputGetState XInputGetState_

#define X_INPUT_SET_STATE(name) DWORD WINAPI name(DWORD dwUserIndex, XINPUT_VIBRATION *pVibration)
typedef X_INPUT_SET_STATE(x_input_set_state);
X_INPUT_SET_STATE(XInputSetStateStub)
{
    return(0);
}
static x_input_set_state *XInputSetState_ = XInputSetStateStub;
#define XInputSetState XInputSetState_


namespace JCS_GameInput
{
    GamePad::GamePad()
        : m_controllerState()
        , m_controllerIndex(0)
    {

    }

    GamePad::~GamePad()
    {

    }

    XINPUT_STATE GamePad::GetState()
    {
        // Zeroise the state
        ZeroMemory(&m_controllerState, sizeof(XINPUT_STATE));

        // Get the state
        XInputGetState(m_controllerIndex, &m_controllerState);

        return m_controllerState;
    }

    void GamePad::LoadXInput(void)
    {
        // current version we are using for XInput API
        HMODULE XInputLibrary = LoadLibraryA("xinput1_3.dll");

        // Try to load
        if (XInputLibrary)
        {
            XInputGetState = (x_input_get_state*)GetProcAddress(XInputLibrary, "XInputGetState");
            if (!XInputGetState) 
                XInputGetState = XInputGetStateStub;

            XInputSetState = (x_input_set_state*)GetProcAddress(XInputLibrary, "XInputSetState");
            if (!XInputSetState) 
                XInputSetState = XInputSetStateStub;
        }
    }

    bool GamePad::IsConnected()
    {
        // Zeroise the state
        ZeroMemory(&m_controllerState, sizeof(XINPUT_STATE));

        // Get the state
        DWORD Result = XInputGetState(m_controllerIndex, &m_controllerState);

        if (Result == ERROR_SUCCESS)
            return true;
        else
            return false;

    }

    bool GamePad::isButtonPressed(ulong32 button)
    {
        // get runtime input buffer from Game Pad
        WORD buttons = GetGamePad().wButtons;
        
        if (buttons & XINPUT_GAMEPAD_DPAD_UP &&
            button & XINPUT_GAMEPAD_DPAD_UP)
            return true;

        if (buttons & XINPUT_GAMEPAD_DPAD_DOWN &&
            button & XINPUT_GAMEPAD_DPAD_DOWN)
            return true;

        if (buttons & XINPUT_GAMEPAD_DPAD_LEFT &&
            button & XINPUT_GAMEPAD_DPAD_LEFT)
            return true;

        if (buttons & XINPUT_GAMEPAD_DPAD_RIGHT &&
            button & XINPUT_GAMEPAD_DPAD_RIGHT)
            return true;

        if (buttons & XINPUT_GAMEPAD_START &&
            button & XINPUT_GAMEPAD_START)
            return true;

        if (buttons & XINPUT_GAMEPAD_BACK &&
            button & XINPUT_GAMEPAD_BACK)
            return true;

        if (buttons & XINPUT_GAMEPAD_LEFT_SHOULDER &&
            button & XINPUT_GAMEPAD_LEFT_SHOULDER)
            return true;

        if (buttons & XINPUT_GAMEPAD_RIGHT_SHOULDER &&
            button & XINPUT_GAMEPAD_RIGHT_SHOULDER)
            return true;

        if (buttons & XINPUT_GAMEPAD_A &&
            button & XINPUT_GAMEPAD_A)
            return true;

        if (buttons & XINPUT_GAMEPAD_B &&
            button & XINPUT_GAMEPAD_B)
            return true;

        if (buttons & XINPUT_GAMEPAD_X &&
            button & XINPUT_GAMEPAD_X)
            return true;

        if (buttons & XINPUT_GAMEPAD_Y &&
            button & XINPUT_GAMEPAD_Y)
            return true;

        return false;
    }

    void GamePad::Vibrate(int32 leftVal, int32 rightVal)
    {
        // Create a Vibraton State
        XINPUT_VIBRATION Vibration;

        // Zeroise the Vibration
        ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

        // Set the Vibration Values
        Vibration.wLeftMotorSpeed = leftVal;
        Vibration.wRightMotorSpeed = rightVal;

        // Vibrate the controller
        XInputSetState(m_controllerIndex, &Vibration);
    }

}

