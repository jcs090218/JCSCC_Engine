#ifndef __RESOURCEMANAGER_H__
/**
 * $File: ResourceManager.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __RESOURCEMANAGER_H__


#include "GameTool_StdAfx.h"


namespace JCS_GameTool
{

    //====================================================================================
    // Class Name : ResourceManager 
    //
    // Description : Take care of all the resources and are already loaded to
    //        memory or load instantly. 
    //====================================================================================
    class ResourceManager
		: public JCSSTL::JCSSTL_Singleton<ResourceManager>
    {
    private:
		friend class JCSSTL::JCSSTL_Singleton<ResourceManager>;

    public:

        virtual ~ResourceManager();


        /** setter **/ 
        
        /** getter **/

	private:
		// Constructor
		ResourceManager();
		ResourceManager(const ResourceManager& right) = delete;

    };

}

typedef JCS_GameTool::ResourceManager ResourceManager;

#endif // __RESOURCEMANAGER_H__

