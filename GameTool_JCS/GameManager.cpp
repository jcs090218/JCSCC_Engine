#include "GameManager.h"

namespace JCS_GameTool
{
	GameManager* GameManager::s_pGameManager = nullptr;

	GameManager::GameManager()
		: m_gamePaused(false)
	{
		
	}

	GameManager::~GameManager()
	{
		s_pGameManager = nullptr;
	}

}

