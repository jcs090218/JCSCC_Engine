#ifndef __MOUSE_H__
#define __MOUSE_H__


#include "..\GameInput_StdAfx.h"

namespace JCS_GameInput
{
	class MouseServer;

	class MouseClient
        : public JCS_Input
	{
	private:
		const MouseServer* server;		// declare mouse server

	public:
		MouseClient(const MouseServer* server);
		virtual ~MouseClient();

		int32 GetMouseX() const;
		int32 GetMouseY() const;
		bool LeftIsPressed() const;
		bool RightIsPressed() const;
		bool IsInWindow() const;

	};

	class MouseServer
        : public JCS_Input
	{
    private:
		friend MouseClient;

        // value we send to client
        int32 x;
        int32 y;
        bool leftIsPressed;
        bool rightIsPressed;
        bool isInWindow;

	public:
		// Constructor
		MouseServer();
		~MouseServer();

		void OnMouseMove(int32 x, int32 y);
		void OnMouseLeave();
		void OnMouseEnter();
		void OnLeftPressed();		// left mouse
		void OnLeftReleased();
		void OnRightPressed();		// right mouse
		void OnRightReleased();
		bool IsInWindow() const;	// check mouse are in window or not
	};

}

typedef JCS_GameInput::MouseClient MouseClient;
typedef JCS_GameInput::MouseServer MouseServer;

#endif // __MOUSE_H__

