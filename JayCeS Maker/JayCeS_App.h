#ifndef __JAYCES_APP_H__
/**
 * $File: JayCeS_App.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JAYCES_APP_H__


#include <GameResourceS_JCS\Application.h>

#include <JcsLib\JcsFile.h>

class JayCeS_App
    : public Application
{
public:
    JayCeS_App(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    ~JayCeS_App();

    virtual bool Initialize() override;
    virtual void CreateGUI(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
    virtual void ListenCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

private:
    JcsFile* load_file(wchar_t* path);

protected:
    virtual void RunApp() override;
};

#endif // __JAYCES_APP_H__

