#include "MP3Sound.h"

const int WM_GRAPHNOTIFY = 0x00008001;

namespace JCS_GameSound
{

    MP3SoundClient::MP3SoundClient(MP3SoundServer &mp3Serv)
        : server(mp3Serv)
    {

    }

    MP3SoundClient::~MP3SoundClient()
    {

    }

    bool MP3SoundClient::play_mp3(char* filePath, bool bLoop)
    {
        return server.play_mp3(filePath, bLoop);
    }

    bool MP3SoundClient::PlayOneShot(char* filePath)
    {
        return server.PlayOneShot(filePath);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////
    MP3SoundServer::MP3SoundServer(HWND hWnd)
    {
        Initialize(hWnd);
    }

    MP3SoundServer::~MP3SoundServer()
    {
        g_pMediaCtrl->Stop();        // stop the music

        SafeReleaseCOM(g_pMediaEvent);
        SafeReleaseCOM(g_pMediaCtrl);
        SafeReleaseCOM(g_pGraphBuilder);
        SafeReleaseCOM(g_pMediaPos);

        CoUninitialize();
    }

    bool MP3SoundServer::Initialize(HWND hWnd)
    {
        // initialize the COM library on the current thread and identifies the concurrency model as single-thread
        // apartment (STA).
        CoInitialize(0);

        // create the DirectMusic performance object
        //
        // creates a single uninitialized object of the class associated with a specified CLSID.
        if (FAILED(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder,
            (void**)&g_pGraphBuilder)))
        {
            MessageBox(NULL, L"Unable to create DirectShow Graph Builder object.", L"Error", MB_OK);
            return false;
        }

        // Query for the media control and event objects
        g_pGraphBuilder->QueryInterface(IID_IMediaEvent, (void**)&g_pMediaEvent);
        g_pGraphBuilder->QueryInterface(IID_IMediaPosition, (void**)&g_pMediaPos);

        g_pMediaEvent->SetNotifyWindow((OAHWND)hWnd, WM_GRAPHNOTIFY, 0);
        //g_pMediaEvent->SetNotifyFlags(0);

        g_pGraphBuilder->QueryInterface(IID_IMediaControl, (void**)&g_pMediaCtrl);

        return true;
    }

    bool MP3SoundServer::play_mp3(char* filePath, bool bLoop)
    {
        WCHAR w_filePath[MAX_PATH] = { 0 };
        mbstowcs(w_filePath, filePath, MAX_PATH);

        HRESULT hr;
        // render the file
        hr = g_pGraphBuilder->RenderFile(w_filePath, NULL);
        if (FAILED(hr))
        {
            MessageBox(NULL, L"Unable to find the \"mp3\" file.", L"Error", MB_OK);
            return false;
        }

        // play the file, switches the entire filter graph into a running state.
        g_pMediaCtrl->Run();

        return true;
    }

    /**
     *    Sound we only want to play once, not loop.
     */
    bool MP3SoundServer::PlayOneShot(char* filePath)
    {
        WCHAR w_filePath[MAX_PATH] = { 0 };
        mbstowcs(w_filePath, filePath, MAX_PATH);

        HRESULT hr;
        if (FAILED(hr = g_pGraphBuilder->RenderFile(w_filePath, NULL)))
        {
            MessageBox(NULL, L"Unable to find the \"mp3\" file.", L"Error", MB_OK);
            return false;
        }

        g_pMediaCtrl->Run();

        return true;
    }

    ////////////////////////////////////////////////////////////////////////////// Event Check
    /**
     *  This function will check in the WindowProc
     */
    void MP3SoundServer::OnFlag()
    {
        // get th status of the song, it if is done, exit program.
        long event_code, param1, param2;

        // retrieves the next notification event
        while (g_pMediaEvent->GetEvent(&event_code, &param1, &param2, 0) != E_ABORT)
        {
            switch (event_code)
            {
            case EC_COMPLETE:
                // Going back to the start of the clip
                g_pMediaPos->put_CurrentPosition(0);
                break;
            default:
                break;
            }
            // frees resources associated with the parameters of an events.
            g_pMediaEvent->FreeEventParams(event_code, param1, param2);
        }
    }

}

