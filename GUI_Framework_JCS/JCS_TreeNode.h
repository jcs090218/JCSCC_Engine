#ifndef __JCS_TREENODE_H__
/**
 * $File: JCS_TreeNode.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __JCS_TREENODE_H__

#ifdef _WIN32


#include "JCS_WindowHandle.h"


namespace JCS_GUI
{
    class JCS_TreeView;

    //====================================================================================---------------------------------------------------------------
    // Class Name : JCS_TreeNode
    //
    // Description : 
    //====================================================================================---------------------------------------------------------------
    class JCS_TreeNode
        : public JCS_WindowHandle
    {
    private:
        HTREEITEM m_node;   // 

    public:
        JCS_TreeNode();
        ~JCS_TreeNode();

        /**
            
        */
        void Create(const HWND treeView, const LPWSTR name, const HTREEITEM node = nullptr);
        /**
            
        */
        void Create(const JCS_TreeView treeView, const LPWSTR name, const JCS_TreeNode* node = nullptr);

        /** getter **/
        /**  */
        HTREEITEM GetNode() const { return this->m_node; }

    };

}

typedef JCS_GUI::JCS_TreeNode JCS_TreeNode;

#endif // _WIN32

#endif // __JCS_TREENODE_H__

