#ifdef _WIN32

/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __WINSOCK2_SOCKET_H__
/**
 * $File: WinSock2_Socket.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __WINSOCK2_SOCKET_H__


#include "Socket_StdAfx.h"


namespace JCS_Network
{

    /**
     * @class WinSock2_Socket
     * @brief Socket Layer using Winsock. (Windows OS Only)
     */
    class WinSock2_Socket
        : public JCS_Socket
    {
    private:
        SOCKET m_sockClient;
        const char* m_pHostName = DEFAULT_HOST_NAME;
        int32 m_port = DEFAULT_PORT;

        bool RecvFromSock(void);        // 从网络中读取尽可能多的数据

        /**
         * @func HasError
         * @brief 是否發生错误，注意，異同步模式未完成非錯誤
         * @return bool : true, has error. false, no error.
         */
        bool HasError();

        /**
         * @func CloseSocket
         * @brief Close the connect socket.
         */
        void CloseSocket();

        /**
         * @func ConnectToOfficialWebsite
         * @brief 檢查是否要連上官網
         */
        void ConnectToOfficialWebsite();

        // 發送數據緩衝
        char m_bufOutput[OUTBUFSIZE];    //? 可優化为指针數组
        int32 m_nOutbufLen;

        // 环形缓冲区
        char m_bufInput[INBUFSIZE];
        int32 m_nInbufLen;
        int32 m_nInbufStart;                // INBUF使用循环式队列，该变量为队列起点，0 - (SIZE-1)

    public:
        WinSock2_Socket(void);
        ~WinSock2_Socket();

        /**
         * @func Create
         * @brief Create the connect socket. (CLIENT)
         * @return bool : true, success. false, failed to create socket.
         */
        bool Create(const char* pszServerIP = DEFAULT_HOST_NAME,
            int32 nServerPort = DEFAULT_PORT,
            int32 nBlockSec = BLOCKSECONDS,
            bool bKeepAlive = false);

        /**
         * @func SendPacket
         * @brief Send the packet.
         * @param pBuf : data to send.
         * @param nSize : size of the data to send.
         * @return bool : true, data sent successful, false, failed 
         * to send data.
         */
        bool SendPacket(void* pBuf, int32 nSize);

        /**
         * @func ReceivePacket
         * @brief Receive the packet.
         * @param pBuf : data to receive.
         * @param nSize : size of the data to receive.
         * @return bool : true, data received successful, false, failed
         * to receive data.
         */
        bool ReceivePacket(void* pBuf, int32& nSize);

        /**
         * @func Flush
         * @brief Trigger send out the data.
         * @return bool : true, success. false, failed.
         */
        bool Flush(void);

        /**
         * @func Check
         * @brief Check if the server still alive.
         * @return bool : true, server is fine. false, server is dead.
         */
        bool Check(void);

        /**
         * @func Destroy
         * @brief Destroy the connect socket (CLIENT), and do 
         * socket descriptor cleanup.
         */
        void Destroy(void);

        /** setter **/

        /** getter **/
        SOCKET GetSocket(void) const { return m_sockClient; }
        int32 GetPort() { return this->m_port; }
        const char* GetIPAddress() { return this->m_pHostName; }
    };

    /**
     * @func SendPacket
     * @brief send packet rewrapper for easier access.
     */
    inline bool SendPacket(byte data)
    {
        //return GameSocket::SendPacket(data);
        return true;
    }
}

typedef JCS_Network::WinSock2_Socket WinSock2_Socket;

#endif // __WINSOCK2_SOCKET_H__

#endif // _WIN32
