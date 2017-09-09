/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JAYCES_APP_H__
#define __JAYCES_APP_H__



#include <GameResourceS_JCS\Application.h>

class JayCeS_App
    : public Application
{
public:
    JayCeS_App(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    ~JayCeS_App();

    virtual bool Initialize() override;
    virtual void CreateGUI(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
    virtual void ListenCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

protected:
    virtual void RunApp() override;
};

#endif // __JAYCES_APP_H__

