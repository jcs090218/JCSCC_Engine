/**
 * $File: JCS_TreeNode.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */

#include "JCS_TreeNode.h"


#include "JCS_TreeView.h"

namespace JCS_GUI
{
    JCS_TreeNode::JCS_TreeNode()
    {

    }

    JCS_TreeNode::~JCS_TreeNode()
    {

    }
#ifdef _WIN32

    void JCS_TreeNode::Create(
        const HWND treeView, 
        const LPWSTR name, 
        const HTREEITEM node/*= nullptr*/)
    {
        TVINSERTSTRUCT tvis = { 0 };

        tvis.item.mask = TVIF_TEXT;
        tvis.item.pszText = name;
        tvis.hInsertAfter = TVI_LAST;

        // set default as root
        if (node == nullptr)
            tvis.hParent = TVI_ROOT;
        // if there is root already add it on.
        else
            tvis.hParent = node;

        m_node = reinterpret_cast<HTREEITEM>(
            SendMessage(treeView,
            TVM_INSERTITEM, 
            0, 
            reinterpret_cast<LPARAM>(&tvis)));
    }

    void JCS_TreeNode::Create(
        const JCS_TreeView treeView, 
        const LPWSTR name, 
        const JCS_TreeNode* node/*= nullptr*/)
    {
        TVINSERTSTRUCT tvis = { 0 };

        tvis.item.mask = TVIF_TEXT;
        tvis.item.pszText = name;
        tvis.hInsertAfter = TVI_LAST;

        // set default as root
        if (node == nullptr)
            tvis.hParent = TVI_ROOT;
        // if there is root already add it on.
        else
            tvis.hParent = node->GetNode();

        m_node = reinterpret_cast<HTREEITEM>(
            SendMessage(treeView.GetOwnWindowHandle(),
            TVM_INSERTITEM,
            0,
            reinterpret_cast<LPARAM>(&tvis)));
    }

#endif // _WIN32

}

