#ifndef __SCENEMANAGER_H__
/**
 * $File: SceneManager.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __SCENEMANAGER_H__

#include "GameTool_StdAfx.h"

#include <GameInterface_JCS\API_Type.h>
#include <GameInterface_JCS\SceneType.h>

#include <Direct_2D_Framework_JCS\Scene2D.h>
#include <DirectX_3D_v11_Framework_JCS\Scene2D.h>
#include <DirectX_3D_v9_Framework_JCS\Scene3D.h>


namespace JCS_GameTool
{

    //====================================================================================
    // Class Name : SceneManager 
    //
    // Description : Take care of all the scene. Three main thing this class should 
    //        consider. Load scene, Exit scene, Switch scene and Render scene. 
    //====================================================================================
    class SceneManager
		: public JCSSTL::JCSSTL_Singleton<SceneManager>
    {
    private:
		friend class JCSSTL::JCSSTL_Singleton<SceneManager>;
        SceneManager(API_Type api, SceneType scene);

        bool isPhysicsWorld;                // 物理引擎開關

        SceneType m_sceneType;
        API_Type m_apiType;
        JCS_Scene* m_pScene;

    public:
        virtual ~SceneManager();

		/**
         * Singleton 不同Impl方法
         * http://stackoverflow.com/questions/13047526/difference-between-singleton-implemention-using-pointer-and-using-static-object
         */
		static SceneManager* GetInstance(API_Type api, SceneType scene)
		{
			if (!s_pSingleton)
				s_pSingleton = new SceneManager(api, scene);
			return s_pSingleton;
		}

        void update(float32 deltaTime);
        void draw();

        /** setter **/
        void setIsPhysicsWorld(bool active) { if (isPhysicsWorld != active) this->isPhysicsWorld = active; }
        void SetScene(JCS_Scene* scene) { this->m_pScene = scene; }

        /** getter **/
        bool getIsPhysicsWorld() { return this->isPhysicsWorld; }
        JCS_Scene* GetSceneAsPtr() const { return this->m_pScene; }
        JCS_Scene& GetSceneAsRef() const { return *(this->m_pScene); }
        
        JCS_D2DEngine::Scene2D* GetDirect2D_Scene2DAsPtr() { return dynamic_cast<JCS_D2DEngine::Scene2D*>(m_pScene); }
        JCS_D2DEngine::Scene2D& GetDirect2D_Scene2DAsRef() { return *(dynamic_cast<JCS_D2DEngine::Scene2D*>(m_pScene)); }
        
        JCS_D3DX_v11_Engine::Scene2D* GetDriectX3D_v11_Scene2DAsPtr() { return dynamic_cast<JCS_D3DX_v11_Engine::Scene2D*>(m_pScene); }
        JCS_D3DX_v11_Engine::Scene2D& GetDriectX3D_v11_Scene2DAsRef() { return *(dynamic_cast<JCS_D3DX_v11_Engine::Scene2D*>(m_pScene)); }
        
        JCS_D3DX_v9_Engine::Scene3D* GetDriectX3D_v9_Scene3DAsPtr() { return dynamic_cast<JCS_D3DX_v9_Engine::Scene3D*>(m_pScene); }
        JCS_D3DX_v9_Engine::Scene3D& GetDriectX3D_v9_Scene3DAsRef() { return *(dynamic_cast<JCS_D3DX_v9_Engine::Scene3D*>(m_pScene)); }

	private:
		// Constructor
		SceneManager();
		SceneManager(const SceneManager& right) = delete;
    };

}// end namespace "JCS_GameTool"

typedef JCS_GameTool::SceneManager SceneManager;

#endif // __SCENEMANAGER_H__

