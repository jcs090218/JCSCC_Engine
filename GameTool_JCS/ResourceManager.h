#ifndef __RESOURCEMANAGER_H__
#define __RESOURCEMANAGER_H__



namespace JCS_GameTool
{

    //------------------------------------------------------------------------------------
    // Name : ResourceManager 
    //
    // Desc : Take care of all the resources and are already loaded to
    //        memory or load instantly. 
    //------------------------------------------------------------------------------------
    class ResourceManager
    {
    private:
        static ResourceManager* s_pResourceManager;

        ResourceManager();

    public:
        static ResourceManager* getInstance()
        {
            if (!s_pResourceManager)
                s_pResourceManager = new ResourceManager;
            return s_pResourceManager;
        }
        virtual ~ResourceManager();


        // setter 
        
        // getter

    };

}

typedef JCS_GameTool::ResourceManager ResourceManager;

#endif // __RESOURCEMANAGER_H__

