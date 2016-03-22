#include "ResourceManager.h"


namespace JCS_GameTool
{
    ResourceManager* ResourceManager::s_pResourceManager = nullptr;

    ResourceManager::ResourceManager()
    {

    }

    ResourceManager::~ResourceManager()
    {
        s_pResourceManager = nullptr;
    }

}

