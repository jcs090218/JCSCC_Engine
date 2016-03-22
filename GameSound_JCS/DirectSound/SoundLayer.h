#ifndef __SOUNDLAYER_H__
#define __SOUNDLAYER_H__

#include "..\GameSound_StdAfx.h"

namespace JCS_GameSound
{
    class GameError;

    class SoundLayer
    {
    private:
        LPDIRECTSOUND8 m_pDSound;
        LPDIRECTSOUNDBUFFER8 m_pPrimary;	// primary mixer

        static SoundLayer* _instance;

        // singleton
        SoundLayer(HWND hWnd);

    public:
        virtual ~SoundLayer();

        // get instance
        static SoundLayer* getInstance(HWND hWnd = nullptr)
        {
            if (!_instance)
                _instance = new SoundLayer(hWnd);
            return _instance;
        }

        LPDIRECTSOUND8 GetDSound(){ return m_pDSound; }
    };

    inline SoundLayer* getSoundLayer(HWND hWnd = nullptr)
    {
        return SoundLayer::getInstance(hWnd);
    }
}

typedef JCS_GameSound::SoundLayer SoundLayer;

#endif // __SOUNDLAYER_H__
