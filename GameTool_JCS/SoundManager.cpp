/**
 * $File: SoundManager.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "SoundManager.h"


#include "AudioXML_Loader.h"

namespace JCS_GameTool
{

    SoundManager::SoundManager(HWND hWnd)
        : mCSoundLayer(nullptr)
        , backgroundMusic(nullptr)
        , sound1(nullptr)
        , sound2(nullptr)
        , m_pAudioXMLLoader(nullptr)
    {
        mCSoundLayer = SoundLayer::getInstance(hWnd);
    }


    SoundManager::~SoundManager()
    {
        SafeDeleteObject(sound1);
        SafeDeleteObject(sound2);
        SafeDeleteObject(backgroundMusic);
        SafeDeleteObject(mCSoundLayer);
        SafeDeleteObject(m_pAudioXMLLoader);
    }

    /**
     *  更換背景音樂...
     */
    void SoundManager::playBGM(TCHAR* filename, bool bLoop)
    {
        SafeDeleteObject(backgroundMusic);
        backgroundMusic = new Sound(filename);
        backgroundMusic->Play(bLoop);
    }
    /**
     *  播放一次, 會中斷
     */
    void SoundManager::playOneShot(TCHAR* filename)
    {
        SafeDeleteObject(sound1);
        sound1 = new Sound(filename);
        sound1->Play(false);
    }
    /**
     *  播放一次完整的以後才能在播放
     */
    void SoundManager::playCompleteShot(TCHAR* filename)
    {
        if (sound2 == nullptr) {
            sound2 = new Sound(filename);
            sound2->Play(false);
        }
        else if (!sound2->IsPlaying()) {
            sound2->Play(false);
        }
    }

} // end namespace "JCS_GameTool"

