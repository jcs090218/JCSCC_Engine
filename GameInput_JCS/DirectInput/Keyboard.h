#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include "..\GameInput_StdAfx.h"

namespace JCS_GameInput
{

	class KeyboardServer;

	// Mainly handle meesage for the server side (main.cpp)
	// and do what the server said (messsage from server)
	class KeyboardClient
        : public JCS_Input
	{
	private:
		KeyboardServer* server;

	public:
		KeyboardClient(KeyboardServer* kServer);
		virtual ~KeyboardClient();

		bool KeyIsPressed(uint8 keycode) const;
		uint8 ReadKey();
		uint8 PeekKey() const;
		uint8 ReadChar();
		uint8 PeekChar() const;
		void FlushKeyBuffer();
		void FlushCharBuffer();
		void FlushBuffers();
	};

	// Mainly handle message from the main.cpp
	// and send message to client side (Game.cpp)
	class KeyboardServer
        : public JCS_Input
	{
    private:
		friend KeyboardClient;

        static const int32 nKeys = 256;
        static const int32 bufferSize = 4;
        bool keystates[nKeys];
        std::queue<uint8> keybuffer;
        std::queue<uint8> charbuffer;

	public:
		// constructor
		KeyboardServer();
		~KeyboardServer();

		void OnKeyPressed(unsigned char keycode);
		void OnKeyReleased(unsigned char keycode);
		void OnChar(unsigned char character);
	};

}

typedef JCS_GameInput::KeyboardClient KeyboardClient;
typedef JCS_GameInput::KeyboardServer KeyboardServer;

#endif // __KEYBOARD_H__

