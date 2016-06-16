#ifndef __MP3SOUND_H__
#define __MP3SOUND_H__

#include "../GameSound_StdAfx.h"

#pragma warning(disable : 4996)


namespace JCS_GameSound
{
    class MP3SoundServer;

    //------------------------------------------------------------------------------------
    // Name : MP3SoundClient 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class MP3SoundClient
    {
    public:
        MP3SoundClient(MP3SoundServer &mp3Serv);
        ~MP3SoundClient();

        bool play_mp3(char* filePath, bool bLoop = false);
        bool PlayOneShot(char* filePath);

        // getter/setter
        MP3SoundServer &getServer() { return server; }

    private:

        MP3SoundServer &server;
    };

    //------------------------------------------------------------------------------------
    // Name : MP3SoundServer 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class MP3SoundServer
    {
        friend class MP3SoundClient;    // this will make "MP3SoundClient" direct access this class!
    public:
        MP3SoundServer(HWND);
        ~MP3SoundServer();

        bool Initialize(HWND);
        bool play_mp3(char* filePath, bool bLoop = false);
        bool PlayOneShot(char* filePath);
        void OnFlag(void);

        // getter/setter
        IGraphBuilder* getGraphBuilder() { return g_pGraphBuilder; }
        IMediaControl* getMediaControl() { return g_pMediaCtrl; }
        IMediaEventEx* getMediaEvent() { return g_pMediaEvent; }
        IMediaPosition* getMediaPos() { return g_pMediaPos; }

    private:
        IGraphBuilder* g_pGraphBuilder = NULL;
        IMediaControl* g_pMediaCtrl = NULL;
        IMediaEventEx* g_pMediaEvent = NULL;
        IMediaPosition* g_pMediaPos = NULL;
    };

}

#endif    // __MP3SOUND_H__

