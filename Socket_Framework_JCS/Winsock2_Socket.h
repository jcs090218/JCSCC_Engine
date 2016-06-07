/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __WINSOCK2_SOCKET_H__
#define __WINSOCK2_SOCKET_H__


#include "Socket_StdAfx.h"


namespace JCS_Network
{

    //------------------------------------------------------------------------------------
    // Name : WinSock2_Socket 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class WinSock2_Socket
        : public JCS_Socket
    {
    private:
        SOCKET m_sockClient;
        const char* m_pHostName = DEFAULT_HOST_NAME;
        int32 m_port = DEFAULT_PORT;

        bool RecvFromSock(void);		// 从网络中读取尽可能多的数据
        bool HasError();		// 是否發生错误，注意，異同步模式未完成非錯誤
        void CloseSocket();

        void ConnectToOfficialWebsite();			// 檢查是否要連上官網

        // 發送數據緩衝
        char m_bufOutput[OUTBUFSIZE];	//? 可優化为指针數组
        int32 m_nOutbufLen;

        // 环形缓冲区
        char m_bufInput[INBUFSIZE];
        int32 m_nInbufLen;
        int32 m_nInbufStart;				// INBUF使用循环式队列，该变量为队列起点，0 - (SIZE-1)

    public:
        WinSock2_Socket(void);
        ~WinSock2_Socket();

        bool Create(const char* pszServerIP = DEFAULT_HOST_NAME,
            int32 nServerPort = DEFAULT_PORT,
            int32 nBlockSec = BLOCKSECONDS,
            bool bKeepAlive = false);

        bool SendPacket(void* pBuf, int32 nSize);
        bool ReceivePacket(void* pBuf, int32& nSize);

        bool Flush(void);
        bool Check(void);
        void Destroy(void);

        // getter/setter
        SOCKET GetSocket(void) const { return m_sockClient; }
        int32 GetPort() { return this->m_port; }
        const char* GetIPAddress() { return this->m_pHostName; }
    };

    inline bool SendPacket(byte data)
    {
        //return GameSocket::SendPacket(data);
        return true;
    }
}

typedef JCS_Network::WinSock2_Socket WinSock2_Socket;

#endif // __WINSOCK2_SOCKET_H__

