/**
 * $File: JayCeS_App.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "JayCeS_App.h"

#include <GUI_Framework_JCS\JCS_GUI.h>

#include "CommandIdentifier.h"
#include "resource.h"

#include <JcsLib\JcsTools.h>
#include <JayCeS_JCS\JayCeS.h>


JayCeS_App::JayCeS_App(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
    : JCS_GameResourceS::Application(hInstance, hPrevInstance, lpCmdLine, nCmdShow)
{

}

JayCeS_App::~JayCeS_App()
{

}

bool JayCeS_App::Initialize()
{
    // Set Screen Width and Height before "Application::Initialize", 
    // or else it will not work...
    SetScreenWidth(1082);
    SetScreenHeight(588);
    SetWindowTitle(L"JayCeS File Management");

    SetIcon(IDI_JAYCES_FILE_MANAGEMENT);
    SetExeIcon(IDI_MAIN_ICON);

    // Init Application
    if (!Application::Initialize())
    {
        return false;
    }

    return true;
}

// Main Game Loop
void JayCeS_App::RunApp()
{
    // Run the "Program" here.

}

void JayCeS_App::CreateGUI(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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
        fileMenu.AddFunctionAttribute(L"New\tCrtl+N");
        fileMenu.AddFunctionAttribute(L"Load\tCrtl+O", FILE_MENU_NEW);
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
    }

    // --Tree View
    JCS_GUI::JCS_TreeView treeView;
    {
        treeView.Create(hWnd, L"Tree View", 0, 0, 352, 515);
    }

    // --Tree Node
    {
        JCS_TreeNode treeNode, treeNode2;
        treeNode.Create(treeView, L"Root");
        treeNode2.Create(treeView, L"Node1", &treeNode);
        treeNode2.Create(treeView, L"Node2", &treeNode);
        treeNode2.Create(treeView, L"Node3", &treeNode);
    }

    // Text box
    {
        /*JCS_GUI::JCS_TextBox textBox;
        textBox.Create(hWnd, L"", 3, 46, 719, 538);*/
    }

    // Combo box
    {
        JCS_ComboBox comboBox;
        comboBox.Create(hWnd, L"Testing 1 2 3...", 7, 10, 185, 24);
    }

    // Ending
    menuBar.SetJCS_MenuBar(hWnd);
}

// Design Command Function here...
void JayCeS_App::ListenCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (LOWORD(wParam))
    {
    case FILE_MENU_NEW:
    {
        HANDLE hFile;

        // Open a File Dialog using JCS Lib information!
        JayCeS::JCS_FileDialog fileDialog;
        bool open_file = fileDialog.OpenFileDialog(hWnd, FILE_TITLE, FILE_FILTER, FILE_EXTENSION);

        if (!open_file)
            return;

        hFile = CreateFile(fileDialog.fileName, 
            GENERIC_READ, 
            FILE_SHARE_READ, 
            NULL,
            OPEN_EXISTING, 0, NULL);

        JcsFile* jcsFile = load_file(fileDialog.fileName);

        SafeDeleteObject(jcsFile);

    } break;
    }
}

JcsFile* JayCeS_App::load_file(wchar_t* path)
{
    JcsFile* jcsf = new JcsFile(path, JcsVersion::JCS_v01);
    jcsf->ParseJcsFile();
    

    return jcsf;
}

