#ifndef __SOUNDMANAGER_H__
/**
 * $File: SoundManager.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __SOUNDMANAGER_H__

#include "GameTool_StdAfx.h"

#include <GameSound_JCS\DirectSound\Sound.h>
#include <GameSound_JCS\DirectSound\SoundLayer.h>

namespace JCS_GameTool
{
    class AudioXML_Loader;

    //====================================================================================
    // Class Name : SoundManager 
    //
    // Description : Control all the Sound Effect in the Program(Game). 
    //        Should have relationship with "ResourceManager".
    //====================================================================================
    class SoundManager
		: public JCSSTL::JCSSTL_Singleton<SoundManager>
    {
    private:
		friend class JCSSTL::JCSSTL_Singleton<SoundManager>;
        SoundLayer* mCSoundLayer;        // for sound
        Sound* backgroundMusic;
        Sound* sound1;
        Sound* sound2;

        AudioXML_Loader* m_pAudioXMLLoader;

    public:
		/**
         * Singleton 不同Impl方法
         * http://stackoverflow.com/questions/13047526/difference-between-singleton-implemention-using-pointer-and-using-static-object
         */
		static SoundManager* GetInstance(HWND hWnd)
		{
			if (!s_pSingleton)
				s_pSingleton = new SoundManager(hWnd);
			return s_pSingleton;
		}
        virtual ~SoundManager();

        void playBGM(TCHAR*, bool bLoop = true);    // 循環播放
        void playOneShot(TCHAR*);                    // 只播放一次
        void playCompleteShot(TCHAR*);                // 播放一次完整的以後才能在播放

        //setter

        /** getter **/
        SoundLayer* getSoundLayer() { return this->mCSoundLayer; }

	private:
		// Constructor
		SoundManager(HWND);
		SoundManager(const SoundManager& right) = delete;
    };

}

typedef JCS_GameTool::SoundManager SoundManager;

#endif // __SOUNDMANAGER_H__

