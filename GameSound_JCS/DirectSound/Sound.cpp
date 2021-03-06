#include "Sound.h"

#include "SoundLayer.h"

namespace JCS_GameSound
{
    std::map< CWaveSoundRead*, int > Sound::m_waveMap;

    Sound::Sound(TCHAR* filename)
    {
        m_pWaveSoundRead = nullptr;
        m_pBuffer = nullptr;

        // Create a new wave file class;
        m_pWaveSoundRead = new CWaveSoundRead();
        m_waveMap[m_pWaveSoundRead] = 1;

        // Load the wave file
        if (FAILED(m_pWaveSoundRead->Open(filename)))
        {
            throw JCS_GameTool::GameError(L"couldn't open file!");
        }

        Init();
        Fill();
    }

    Sound::Sound(Sound& in)
    {
        m_pWaveSoundRead = in.m_pWaveSoundRead;
        m_waveMap[m_pWaveSoundRead]++;
        Init();
        Fill();
    }

    Sound& Sound::operator=(const Sound &in)
    {
        /**
        * Destroy the old object
        */
        int count = --m_waveMap[m_pWaveSoundRead];
        if (!count) {
            SafeDeleteObject(m_pWaveSoundRead);
        }
        SafeReleaseCOM(m_pBuffer);

        /**
        * Clone the incoming one
        */
        m_pWaveSoundRead = in.m_pWaveSoundRead;
        m_waveMap[m_pWaveSoundRead]++;

        Init();
        Fill();

        return *this;
    }


    Sound::~Sound()
    {
        int count = m_waveMap[m_pWaveSoundRead];
        if (count == 1) {
            SafeDeleteObject(m_pWaveSoundRead);
        }
        else {
            m_waveMap[m_pWaveSoundRead] = count - 1;
        }

        SafeReleaseCOM(m_pBuffer);
    }

    void Sound::Init()
    {
        /**
        * Set up the DirectSound surface. the size of the sound file
        * and the format of the data can be retrieved from the wave
        * sound object.  Besides that, we only set the STATIC flag,
        * so that the driver isn't restricted in setting up the
        * buffer.
        */
        AutoZero<DSBUFFERDESC> dsbd;
        dsbd.dwFlags = DSBCAPS_STATIC;
        dsbd.dwBufferBytes = m_pWaveSoundRead->m_ckIn.cksize;
        dsbd.lpwfxFormat = m_pWaveSoundRead->m_pwfx;

        HRESULT hr;

        // Temporary pointer to old DirectSound interface
        LPDIRECTSOUNDBUFFER pTempBuffer = 0;

        // Create the sound buffer
        hr = getSoundLayer()->GetDSound()->CreateSoundBuffer(&dsbd, &pTempBuffer, nullptr);
        if (FAILED(hr))
        {
            throw JCS_GameTool::GameError(L"CreateSoundBuffer failed!");
        }

        // Upgrade the sound buffer to version 8
        pTempBuffer->QueryInterface(IID_IDirectSoundBuffer8, (void**)&m_pBuffer);
        if (FAILED(hr))
        {
            throw JCS_GameTool::GameError(L"SoundBuffer query to 8 failed!");
        }

        // Release the temporary old buffer
        pTempBuffer->Release();

        /**
        * Remember how big the buffer is
        */
        m_bufferSize = dsbd.dwBufferBytes;
    }


    void Sound::Restore()
    {
        HRESULT hr;

        if (m_pBuffer == nullptr)
        {
            return;
        }

        DWORD dwStatus;
        if (FAILED(hr = m_pBuffer->GetStatus(&dwStatus)))
        {
            throw JCS_GameTool::GameError(L"couldn't get buffer status");
        }

        if (dwStatus & DSBSTATUS_BUFFERLOST)
        {
            /**
            * Chances are, we got here because the app /just/
            * started, and DirectSound hasn't given us any
            * control yet.  Just spin until we can restore
            * the buffer
            */
            do
            {
                hr = m_pBuffer->Restore();
                if (hr == DSERR_BUFFERLOST)
                    Sleep(10);
            } while (hr = m_pBuffer->Restore());

            /**
            * The buffer was restored.  Fill 'er up.
            */
            Fill();
        }
    }


    void Sound::Fill()
    {
        HRESULT hr;
        BYTE*   pbWavData; // Pointer to actual wav data 
        UINT    cbWavSize; // Size of data
        void*   pbData = nullptr;
        void*   pbData2 = nullptr;
        ULONG   dwLength;
        ULONG   dwLength2;

        /**
        * How big the wav file is
        */
        UINT nWaveFileSize = m_pWaveSoundRead->m_ckIn.cksize;

        /**
        * Allocate enough data to hold the wav file data
        */
        pbWavData = new BYTE[nWaveFileSize];
        if (pbWavData == nullptr)
        {
            SafeDeleteArrayObject(pbWavData);
            throw JCS_GameTool::GameError(L"Out of memory!");
        }

        hr = m_pWaveSoundRead->Read(
            nWaveFileSize,
            pbWavData,
            &cbWavSize);
        if (FAILED(hr))
        {
            SafeDeleteArrayObject(pbWavData);
            throw JCS_GameTool::GameError(L"m_pWaveSoundRead->Read failed");
        }

        /**
        * Reset the file to the beginning
        */
        m_pWaveSoundRead->Reset();

        /**
        * Lock the buffer so we can copy the data over
        */
        hr = m_pBuffer->Lock(0, m_bufferSize, &pbData, &dwLength, &pbData2, &dwLength2, 0L);
        if (FAILED(hr))
        {
            SafeDeleteArrayObject(pbWavData);
            throw JCS_GameTool::GameError(L"m_pBuffer->Lock failed");
        }

        /**
        * Copy said data over, unlocking afterwards
        */
        memcpy(pbData, pbWavData, m_bufferSize);
        m_pBuffer->Unlock(pbData, m_bufferSize, NULL, 0);

        /**
        * We're done with the wav data memory.
        */
        SafeDeleteArrayObject(pbWavData);
    }


    bool Sound::IsPlaying()
    {
        DWORD dwStatus = 0;

        m_pBuffer->GetStatus(&dwStatus);

        if (dwStatus & DSBSTATUS_PLAYING)
            return true;
        else
            return false;
    }


    void Sound::Play(bool bLoop)
    {
        HRESULT hr;
        if (m_pBuffer == nullptr)
            return;

        // Restore the buffers if they are lost
        Restore();

        // Play buffer 
        DWORD dwLooped = bLoop ? DSBPLAY_LOOPING : 0L;
        if (FAILED(hr = m_pBuffer->Play(0, 0, dwLooped)))
        {
            throw JCS_GameTool::GameError(L"m_pBuffer->Play failed");
        }
    }

}

