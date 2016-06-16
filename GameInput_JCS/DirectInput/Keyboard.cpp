#include "Keyboard.h"


namespace JCS_GameInput
{
    KeyboardClient::KeyboardClient(KeyboardServer* kServer)
        : server(kServer)
    {

    }

    KeyboardClient::~KeyboardClient()
    {
        server = nullptr;
    }

    bool KeyboardClient::KeyIsPressed(uint8 keycode) const
    {
        return server->keystates[keycode];
    }

    uint8 KeyboardClient::ReadKey()
    {
        if (server->keybuffer.size() > 0)
        {
            uint8 keycode = server->keybuffer.front();
            server->keybuffer.pop();
            return keycode;
        }
        else
        {
            return 0;
        }
    }

    uint8 KeyboardClient::PeekKey() const
    {
        if (server->keybuffer.size() > 0)
        {
            return server->keybuffer.front();
        }
        else{
            return 0;
        }
    }

    uint8 KeyboardClient::ReadChar()
    {
        if (server->charbuffer.size() > 0)
        {
            uint8 charcode = server->charbuffer.front();
            server->charbuffer.pop();
            return charcode;
        }
        else{
            return 0;
        }
    }

    uint8 KeyboardClient::PeekChar() const
    {
        if (server->charbuffer.size() > 0)
        {
            return server->charbuffer.front();
        }
        else{
            return 0;
        }
    }

    void KeyboardClient::FlushKeyBuffer()
    {
        while (!server->keybuffer.empty())
        {
            server->keybuffer.pop();
        }
    }

    void KeyboardClient::FlushCharBuffer()
    {
        while (!server->charbuffer.empty())
        {
            server->charbuffer.pop();
        }
    }

    void KeyboardClient::FlushBuffers()
    {
        FlushKeyBuffer();
        FlushCharBuffer();
    }


    ///////////////////////////////////Server
    KeyboardServer::KeyboardServer()
    {
        for (int i = 0; i < nKeys; i++)
        {
            keystates[i] = false;
        }
    }

    KeyboardServer::~KeyboardServer()
    {

    }

    void KeyboardServer::OnKeyPressed(uint8 keycode)
    {
        keystates[keycode] = true;

        keybuffer.push(keycode);
        if (keybuffer.size() > bufferSize)
        {
            keybuffer.pop();
        }
    }

    void KeyboardServer::OnKeyReleased(uint8 keycode)
    {
        keystates[keycode] = false;
    }

    void KeyboardServer::OnChar(uint8 character)
    {
        charbuffer.push(character);
        if (charbuffer.size() > bufferSize)
        {
            charbuffer.pop();
        }
    }

}

