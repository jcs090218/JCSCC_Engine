/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __WINSOCK2_SOCKET_H__
#define __WINSOCK2_SOCKET_H__


#include "Socket_StdAfx.h"
#include "JCS_Socket.h"

#define _MAX_MSGSIZE 16 * 1024	// 暫定一個消息最大回16k
#define BLOCKSECONDS 30		// INIT函數阻塞時間
#define INBUFSIZE	(64 * 1024)		//?	具体尺寸根据剖面报告调整  接收数据的缓存
#define OUTBUFSIZE	(8 * 1024)		//? 具体尺寸根据剖面报告调整。 发送数据的缓存，当不超过8K时，FLUSH只需要SEND一次

#define DEFAULT_HOST_NAME "127.0.0.1"
#define DEFAULT_PORT 8585

namespace JCS_Network
{
    class WinSock2_Socket
        : public JCS_Socket
    {
    private:
        SOCKET m_sockClient;
        const char* hostname = DEFAULT_HOST_NAME;
        int32 port = DEFAULT_PORT;

        bool recvFromSock(void);		// 从网络中读取尽可能多的数据
        bool hasError();		// 是否發生错误，注意，異同步模式未完成非錯誤
        void closeSocket();

        void connectToOfficialWebsite();			// 檢查是否要連上官網

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

        bool sendPacket(void* pBuf, int32 nSize);
        bool receivePacket(void* pBuf, int32& nSize);

        bool Flush(void);
        bool Check(void);
        void Destroy(void);

        // getter/setter
        SOCKET GetSocket(void) const { return m_sockClient; }
        int32 getPort() { return port; }
        const char* getIPAddress() { return hostname; }
    };

    inline bool sendPacket(byte data)
    {
        //return GameSocket::sendPacket(data);
        return true;
    }
}

typedef JCS_Network::WinSock2_Socket WinSock2_Socket;

#endif // __WINSOCK2_SOCKET_H__

