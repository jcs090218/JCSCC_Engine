#ifndef __GAME_MANAGER_H__
/**
 * $File: GameManager.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __GAME_MANAGER_H__


#include "GameTool_StdAfx.h"


namespace JCS_GameTool
{

    //====================================================================================
    // Name : GameManager 
    //
    // Description : Manager manage the game. (support Game Layer)
    //====================================================================================
    class GameManager
		: public JCSSTL::JCSSTL_Singleton<GameManager>
    {
    private:
		friend class JCSSTL::JCSSTL_Singleton<GameManager>;

        bool m_gamePaused;        // use when we want to stop the game


    public:
        /**
         * Singleton 不同Impl方法
         * http://stackoverflow.com/questions/13047526/difference-between-singleton-implemention-using-pointer-and-using-static-object
         */
		/*
        static GameManager* getInstance()
        {
            if (!s_pGameManager)
                s_pGameManager = new GameManager;
            return s_pGameManager;        // singleton
        }
		*/
        virtual ~GameManager();

        /** setter **/

        /** Set the game pause */
        void SetGamePause(bool pause) { this->m_gamePaused = pause; }

        /** getter **/
        /** Get the game pause */
        bool IsGamePause() const { return this->m_gamePaused; }        // 檢查是否為暫停遊戲

	private:
		// Constructor
		GameManager();
		GameManager(const GameManager& right) = delete;
    };

}

typedef JCS_GameTool::GameManager GameManager;

#endif // __GAME_MANAGER_H__
