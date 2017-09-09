/**
 * $File: TestApp.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "TestApp.h"

#include <GUI_Framework_JCS\JCS_GUI.h>

#include "OwnIdentifier.h"
#include "Resource.h"

TestApp::TestApp(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    : JCS_GameResourceS::Application(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
{
    
}

TestApp::~TestApp()
{

}

bool TestApp::Initialize()
{
    // Set Screen Width and Height before "Application::Initialize", 
    // or else it will not work...
    SetScreenWidth(800);
    SetScreenHeight(600);
    SetWindowTitle(L"Utitlity_GameResourceS_JCS_Test_VS2013");
    SetIcon(IDI_JCS_UTILITY_ICON);
    SetExeIcon(IDI_MAIN_ICON);

    // Init Application
    if (!Application::Initialize())
    {
        return false;
    }

    return true;
}

// Main Game Loop
void TestApp::RunApp()
{
    // Run the "Program" here.
    
}

// Design GUI here...
void TestApp::CreateGUI(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // --Push Button
    {
        JCS_GUI::JCS_PushButton button;
        button.Create(hWnd, L"Button 1", 50, 220, 100, 24, BUTTON_001);
        button.Create(hWnd, L"Button 2", 150, 220, 100, 24, BUTTON_002);
        button.Create(hWnd, L"Exit", 50, 280, 100, 24, IDC_EXIT);
    }

    // --Text Box
    {
        JCS_GUI::JCS_TextBox editBox;
        editBox.Create(hWnd, L"No initialize word...", 50, 100, 200, 100);
    }

    // --Menu Bar
    JCS_GUI::JCS_MenuBar menuBar;   // Main
    {
        // Test
        JCS_GUI::JCS_MenuBar testMenu;

        JCS_GUI::JCS_MenuBar fileMenu;  // Sub
        JCS_GUI::JCS_MenuBar propertyMenu;
        JCS_GUI::JCS_MenuBar imgMenu;
        JCS_GUI::JCS_MenuBar xmlMenu;

        menuBar.AddMenuAttribute((int32)fileMenu.GetMenuBar(), L"File");
        menuBar.AddMenuAttribute((int32)propertyMenu.GetMenuBar(), L"Property");
        menuBar.AddMenuAttribute((int32)imgMenu.GetMenuBar(), L"img");
        menuBar.AddMenuAttribute((int32)xmlMenu.GetMenuBar(), L"XML");

        // File
        fileMenu.AddFunctionAttribute(L"New\tCrtl+N", FILE_MENU_NEW);
        fileMenu.AddFunctionAttribute(L"Load\tCrtl+O");
        fileMenu.AddFunctionAttribute(L"Save\tCrtl+S");
        fileMenu.AddFunctionAttribute(L"Reload All");
        fileMenu.AddFunctionAttribute(L"Unload All");

        // Property
        propertyMenu.AddFunctionAttribute(L"Remove Property\tCrtl+R");
        propertyMenu.AddFunctionAttribute(L"Add Property\tCrtl+A");
        propertyMenu.AddFunctionAttribute(L"Change Property\tCrtl+M");
        propertyMenu.AddFunctionAttribute(L"Search\tCrtl+F");

        // img
        imgMenu.AddFunctionAttribute(L"Copy img\tCrtl+C");
        imgMenu.AddFunctionAttribute(L"Paste img\tCrtl+V");

        // XML
        xmlMenu.AddFunctionAttribute(L"Dump");
        xmlMenu.AddFunctionAttribute(L"Import");

        fileMenu.AddMenuAttribute((int32)testMenu.GetMenuBar(), L"Test");
        fileMenu.AddFunctionAttribute(L"Exit", IDC_EXIT);

        // Edit
        testMenu.AddFunctionAttribute(L"Message Box", BUTTON_002);
    }

    // --Tree View
    {
        JCS_GUI::JCS_TreeView treeView;
        treeView.Create(hWnd, L"Tree View", 300, 30, 450, 230);
    }


    // Ending
    menuBar.SetJCS_MenuBar(hWnd);
}

// Design Command Function here...
void TestApp::ListenCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (LOWORD(wParam))
    {
    case FILE_MENU_NEW:
    {

    } break;
    case BUTTON_001:
    {
        MessageBox(NULL, L"Test", L"Information", MB_ICONINFORMATION);
    } break;
    case BUTTON_002:
    {
        MessageBox(NULL, L"Button2", L"Information2", MB_OK);
    } break;
    }
}

