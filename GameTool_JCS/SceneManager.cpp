/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "SceneManager.h"


#include <GameInterface_JCS\SceneFactory.h>

namespace JCS_GameTool
{
	SceneManager* SceneManager::_instance = nullptr;

	SceneManager::SceneManager(API_Type api, SceneType scene)
        : m_pScene(nullptr)
        , m_apiType(api)
        , m_sceneType(scene)
	{
        // Ceate Scene Type
        m_pScene = SceneFactory::CreateScene(api, scene);
	}

	SceneManager::~SceneManager()
	{
        SafeDeleteObject(m_pScene);
		_instance = nullptr;
	}

	void SceneManager::update(float32 deltaTime)
	{
        m_pScene->update(deltaTime);
	}

	void SceneManager::draw()
	{
        m_pScene->draw();
	}

}// end namespace "JCS_GameTool"

