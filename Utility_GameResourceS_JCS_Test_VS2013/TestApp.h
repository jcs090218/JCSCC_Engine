#ifndef __TESTAPP_H__
/**
 * $File: TestApp.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __TESTAPP_H__


#include <GameResourceS_JCS\Application.h>

class TestApp
    : public Application
{
public:
    TestApp(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    ~TestApp();

    virtual bool Initialize() override;
    virtual void CreateGUI(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
    virtual void ListenCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

protected:
    virtual void RunApp() override;

};

#endif // __TESTAPP_H__

