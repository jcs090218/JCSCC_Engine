/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

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

