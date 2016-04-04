#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "GameTool_StdAfx.h"

#include <GameInterface_JCS\API_Type.h>
#include <GameInterface_JCS\SceneType.h>

#include <Direct_2D_Framework_JCS\Scene2D.h>
#include <DirectX_3D_v11_Framework_JCS\Scene2D.h>
#include <DirectX_3D_v9_Framework_JCS\Scene3D.h>


namespace JCS_GameTool
{

    //------------------------------------------------------------------------------------
    // Name : SceneManager 
    //
    // Desc : Take care of all the scene. Three main thing this class should 
    //        consider. Load scene, Exit scene, Switch scene and Render scene. 
    //------------------------------------------------------------------------------------
	class SceneManager
	{
	private:
		static SceneManager* _instance;
        SceneManager(API_Type api, SceneType scene);

		bool isPhysicsWorld;				// 物理引擎開關

        SceneType m_sceneType;
        API_Type m_apiType;
        JCS_Scene* m_pScene;

	public:
		virtual ~SceneManager();

        static SceneManager* getInstance(API_Type api, SceneType scene)
		{
			if (!_instance)
                _instance = new SceneManager(api, scene);
			return _instance;
		}

		void update(float32 deltaTime);
		void draw();

		// setter
		void setIsPhysicsWorld(bool active) { if (isPhysicsWorld != active) this->isPhysicsWorld = active; }
        void SetScene(JCS_Scene* scene) { this->m_pScene = scene; }

		// getter
		bool getIsPhysicsWorld() { return this->isPhysicsWorld; }
        JCS_Scene* GetSceneAsPtr() const { return this->m_pScene; }
        JCS_Scene& GetSceneAsRef() const { return *(this->m_pScene); }
        
        JCS_D2DEngine::Scene2D* GetDirect2D_Scene2DAsPtr() { return dynamic_cast<JCS_D2DEngine::Scene2D*>(m_pScene); }
        JCS_D2DEngine::Scene2D& GetDirect2D_Scene2DAsRef() { return *(dynamic_cast<JCS_D2DEngine::Scene2D*>(m_pScene)); }
        
        JCS_D3DX_v11_Engine::Scene2D* GetDriectX3D_v11_Scene2DAsPtr() { return dynamic_cast<JCS_D3DX_v11_Engine::Scene2D*>(m_pScene); }
        JCS_D3DX_v11_Engine::Scene2D& GetDriectX3D_v11_Scene2DAsRef() { return *(dynamic_cast<JCS_D3DX_v11_Engine::Scene2D*>(m_pScene)); }
        
        JCS_D3DX_v9_Engine::Scene3D* GetDriectX3D_v9_Scene3DAsPtr() { return dynamic_cast<JCS_D3DX_v9_Engine::Scene3D*>(m_pScene); }
        JCS_D3DX_v9_Engine::Scene3D& GetDriectX3D_v9_Scene3DAsRef() { return *(dynamic_cast<JCS_D3DX_v9_Engine::Scene3D*>(m_pScene)); }
	};

}// end namespace "JCS_GameTool"

typedef JCS_GameTool::SceneManager SceneManager;

#endif // __SCENEMANAGER_H__

