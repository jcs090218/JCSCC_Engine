/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_TREENODE_H__
#define __JCS_TREENODE_H__

#ifdef _WIN32


#include "JCS_WindowHandle.h"


namespace JCS_GUI
{
    class JCS_TreeView;

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : JCS_TreeNode
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class JCS_TreeNode
        : public JCS_WindowHandle
    {
    private:
        HTREEITEM m_node;

    public:
        JCS_TreeNode();
        ~JCS_TreeNode();

        void Create(const HWND treeView, const LPWSTR name, const HTREEITEM node = nullptr);
        void Create(const JCS_TreeView treeView, const LPWSTR name, const JCS_TreeNode* node = nullptr);

        // getter
        HTREEITEM GetNode() const { return this->m_node; }

    };

}

typedef JCS_GUI::JCS_TreeNode JCS_TreeNode;

#endif // _WIN32

#endif // __JCS_TREENODE_H__

