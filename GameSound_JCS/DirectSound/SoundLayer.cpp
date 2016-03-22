#include "SoundLayer.h"


#include "Sound.h"

namespace JCS_GameSound
{
    SoundLayer* SoundLayer::_instance = nullptr;

    SoundLayer::SoundLayer(HWND hWnd)
        : m_pDSound(nullptr)
        , m_pPrimary(nullptr)
    {
        if (_instance)
            throw JCS_GameTool::GameError(L"SoundLayer already initialized!");


        HRESULT hr;
        LPDIRECTSOUNDBUFFER pDSBPrimary = nullptr;

        // Create IDirectSound using the primary sound device
        hr = DirectSoundCreate8(nullptr, &m_pDSound, nullptr);
        if (FAILED(hr))
            throw JCS_GameTool::GameError(L"DirectSoundCreate failed!");

        // Set coop level to DSSCL_PRIORITY
        hr = m_pDSound->SetCooperativeLevel(hWnd, DSSCL_PRIORITY);
        if (FAILED(hr))
            throw JCS_GameTool::GameError(L"SetCooperativeLevel (DS) failed!");

        // Get the primary buffer 
        sAutoZero<DSBUFFERDESC> dsbd;
        dsbd.dwFlags = DSBCAPS_PRIMARYBUFFER;
        dsbd.dwBufferBytes = 0;
        dsbd.lpwfxFormat = nullptr;

        hr = m_pDSound->CreateSoundBuffer(&dsbd, &pDSBPrimary, NULL);
        if (FAILED(hr))
            throw JCS_GameTool::GameError(L"CreateSoundBuffer (DS) failed!");

        // Set primary buffer format to 22kHz and 16-bit output.
        WAVEFORMATEX wfx;
        ZeroMemory(&wfx, sizeof(WAVEFORMATEX));
        wfx.wFormatTag = WAVE_FORMAT_PCM;
        wfx.nChannels = 2;
        wfx.nSamplesPerSec = 22050;		// hz
        wfx.wBitsPerSample = 16;
        wfx.nBlockAlign = wfx.wBitsPerSample / 8 * wfx.nChannels;
        wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;

        if (FAILED(hr = pDSBPrimary->SetFormat(&wfx)))
            throw JCS_GameTool::GameError(L"SetFormat (DS) failed!");

        SafeReleaseCOM(pDSBPrimary);
    }


    SoundLayer::~SoundLayer()
    {
        SafeReleaseCOM(m_pPrimary);
        SafeReleaseCOM(m_pDSound);
        _instance = nullptr;
    }

}

