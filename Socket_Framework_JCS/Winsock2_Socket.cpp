#ifdef _WIN32

/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

/**
 * $File: WinSock2_Socket.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Winsock2_Socket.h"


#include <JayCeS_JCS\JayCeS.h>

namespace JCS_Network
{
    WinSock2_Socket::WinSock2_Socket(void)
    {
        // 初始化  
        memset(m_bufOutput, 0, sizeof(m_bufOutput));
        memset(m_bufInput, 0, sizeof(m_bufInput));
    }

    WinSock2_Socket::~WinSock2_Socket()
    {
        CloseSocket();
    }

    void WinSock2_Socket::CloseSocket()
    {
        closesocket(m_sockClient);        // Close  our socket
        WSACleanup();        // Cleanup Winsock
    }

    /**
     *  初使化異同步客戶端...
     * Create the connect socket. (CLIENT)
     */
    bool WinSock2_Socket::Create(const char* pszServerIP, int32 nServerPort, int nBlockSec, bool bKeepAlive)
    {
        // 检查参数  
        if (pszServerIP == 0 || strlen(pszServerIP) > 15)
        {
            MessageBox(NULL, L"IP地址錯誤!", L"Internet Protocol Address, Error!", MB_ICONERROR);
            return false;
        }

#ifdef _WIN32  
        WSADATA wsaData;
        WORD version = MAKEWORD(2, 0);
        int32 ret = WSAStartup(version, &wsaData);//win sock start up  
        if (ret != 0) {
            MessageBox(NULL, L"WSA建立錯誤!", L"WSAData, Error!", MB_ICONERROR);
            return false;
        }
#endif  

        // 创建主套接字  
        m_sockClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (m_sockClient == INVALID_SOCKET)
        {
            MessageBox(NULL, L"建立連結錯誤!", L"Build Socket, Error!", MB_ICONERROR);
            CloseSocket();
            return false;
        }

        // 设置SOCKET为KEEPALIVE  
        if (bKeepAlive)
        {
            int32 optval = 1;
            if (setsockopt(m_sockClient, SOL_SOCKET, SO_KEEPALIVE, (char *)&optval, sizeof(optval)))
            {
                MessageBox(NULL, L"Keep Alive錯誤!", L"Keep Alive, Error!", MB_ICONERROR);
                CloseSocket();
                return false;
            }
        }

#ifdef _WIN32  
        DWORD nMode = 1;
        int32 nRes = ioctlsocket(m_sockClient, FIONBIO, &nMode);
        if (nRes == SOCKET_ERROR)
        {
            MessageBox(NULL, L"设置为非阻塞方式錯誤!", L"Non-Input/Output Setting, Error!", MB_ICONERROR);
            CloseSocket();
            return false;
        }
#else  
        // 设置为非阻塞方式  
        fcntl(m_sockClient, F_SETFL, O_NONBLOCK);
#endif  

        ulong32 serveraddr = inet_addr(pszServerIP);
        if (serveraddr == INADDR_NONE)   // 检查IP地址格式错误  
        {
            MessageBox(NULL, L"IP格式錯誤!", L"IP Format, Error!", MB_ICONERROR);
            CloseSocket();
            return false;
        }

        sockaddr_in addr_in;
        memset((void *)&addr_in, 0, sizeof(addr_in));
        addr_in.sin_family = AF_INET;
        addr_in.sin_port = htons(nServerPort);
        addr_in.sin_addr.s_addr = serveraddr;

        if (connect(m_sockClient, (sockaddr *)&addr_in, sizeof(addr_in)) == SOCKET_ERROR)
        {
            if (HasError())
            {
                ConnectToOfficialWebsite();
                CloseSocket();
                return false;
            }
            else    // WSAWOLDBLOCK  
            {
                timeval timeout;
                timeout.tv_sec = nBlockSec;
                timeout.tv_usec = 0;
                fd_set writeset, exceptset;
                FD_ZERO(&writeset);
                FD_ZERO(&exceptset);
                FD_SET(m_sockClient, &writeset);
                FD_SET(m_sockClient, &exceptset);

                int32 ret = select(FD_SETSIZE, NULL, &writeset, &exceptset, &timeout);
                if (ret == 0 || ret < 0) {
                    MessageBox(NULL, L"Runtime Error: 0x00001", L"Runtime Out, Error!", MB_ICONERROR);
                    CloseSocket();
                    return false;
                }
                else  // ret > 0  
                {
                    ret = FD_ISSET(m_sockClient, &exceptset);
                    if (ret)     // or (!FD_ISSET(m_sockClient, &writeset)  
                    {
                        //MessageBox(NULL, L"Runtime Error: 0x00002", L"Runtime Out, Error!", MB_ICONERROR);
                        ConnectToOfficialWebsite();
                        CloseSocket();
                        return false;
                    }
                }
            }
        }

        m_nInbufLen = 0;
        m_nInbufStart = 0;
        m_nOutbufLen = 0;

        struct linger so_linger;
        so_linger.l_onoff = 1;
        so_linger.l_linger = 500;
        setsockopt(m_sockClient, SOL_SOCKET, SO_LINGER, (const char*)&so_linger, sizeof(so_linger));

        JCS_Print1(L"\n\nGame Connected to Server, Port: %i\n\n", nServerPort);
        return true;
    }

    /**
    *  檢查錯誤...
    */
    bool WinSock2_Socket::HasError()
    {
#ifdef _WIN32
        int32 err = WSAGetLastError();
        if (err != WSAEWOULDBLOCK)
        {
#else
        int32 err = errno;
        if (err != EINPROGRESS && err != EAGAIN) {
#endif
            return true;
        }
        return false;
        }

    /**
    *  傳送封包...
    */
    bool WinSock2_Socket::SendPacket(void* pBuf, int32 nSize)
    {
        if (pBuf == 0 || nSize <= 0)
            return false;

        if (m_sockClient == INVALID_SOCKET)
            return false;

        // 檢查通訊封包長度  
        int32 packsize = 0;
        packsize = nSize;

        // 检测BUF溢出  
        if (m_nOutbufLen + nSize > OUTBUFSIZE)
        {
            // 立即发送OUTBUF中的数据，以清空OUTBUF。  
            Flush();
            if (m_nOutbufLen + nSize > OUTBUFSIZE)
            {
                // 出错了  
                Destroy();
                return false;
            }
        }
        // 数据添加到BUF尾  
        memcpy(m_bufOutput + m_nOutbufLen, pBuf, nSize);
        m_nOutbufLen += nSize;

        return true;
    }

    /**
    *  接收封包...
    */
    bool WinSock2_Socket::ReceivePacket(void* pBuf, int32& nSize)
    {
        //检查参数  
        if (pBuf == NULL || nSize <= 0)
            return false;

        if (m_sockClient == INVALID_SOCKET)
            return false;

        // 检查是否有一个消息(小于2则无法获取到消息长度)  
        if (m_nInbufLen < 2)
        {
            //  如果没有请求成功  或者   如果没有数据则直接返回  
            if (!RecvFromSock() || m_nInbufLen < 2)      // 这个m_nInbufLen更新了
            {
                return false;
            }
        }

        // 计算要拷贝的消息的大小（一个消息，大小为整个消息的第一个16字节），因为环形缓冲区，所以要分开计算  
        int packsize = (uint8)m_bufInput[m_nInbufStart] +
            (unsigned char)m_bufInput[(m_nInbufStart + 1) % INBUFSIZE] * 256; // 注意字节序，高位+低位  

        // 检测消息包尺寸错误 暂定最大16k  
        if (packsize <= 0 || packsize > _MAX_MSGSIZE)
        {
            m_nInbufLen = 0;        // 直接清空INBUF  
            m_nInbufStart = 0;
            return false;
        }

        // 检查消息是否完整(如果将要拷贝的消息大于此时缓冲区数据长度，需要再次请求接收剩余数据)  
        if (packsize > m_nInbufLen)
        {
            // 如果没有请求成功   或者    依然无法获取到完整的数据包  则返回，直到取得完整包  
            if (!RecvFromSock() || packsize > m_nInbufLen)  // 这个m_nInbufLen已更新  
            {
                return false;
            }
        }

        // 复制出一个消息  
        if (m_nInbufStart + packsize > INBUFSIZE)
        {
            // 如果一个消息有回卷（被拆成两份在环形缓冲区的头尾）  
            // 先拷贝环形缓冲区末尾的数据  
            int copylen = INBUFSIZE - m_nInbufStart;
            memcpy(pBuf, m_bufInput + m_nInbufStart, copylen);

            // 再拷贝环形缓冲区头部的剩余部分  
            memcpy((unsigned char *)pBuf + copylen, m_bufInput, packsize - copylen);
            nSize = packsize;
        }
        else
        {
            // 消息没有回卷，可以一次拷贝出去  
            memcpy(pBuf, m_bufInput + m_nInbufStart, packsize);
            nSize = packsize;
        }

        // 重新计算环形缓冲区头部位置  
        m_nInbufStart = (m_nInbufStart + packsize) % INBUFSIZE;
        m_nInbufLen -= packsize;

        return true;
    }

    /**
    *  从网络中读取尽可能多的数据，实际向服务器请求数据的地方
    */
    bool WinSock2_Socket::RecvFromSock(void)
    {
        if (m_nInbufLen >= INBUFSIZE || m_sockClient == INVALID_SOCKET)
            return false;

        // 接收第一段数据  
        int savelen, savepos;           // 数据要保存的长度和位置  
        if (m_nInbufStart + m_nInbufLen < INBUFSIZE) // INBUF中的剩余空间有回绕  
        {
            savelen = INBUFSIZE - (m_nInbufStart + m_nInbufLen);        // 后部空间长度，最大接收数据的长度  
        }
        else
        {
            savelen = INBUFSIZE - m_nInbufLen;
        }

        // 缓冲区数据的末尾  
        savepos = (m_nInbufStart + m_nInbufLen) % INBUFSIZE;
        //CHECKF(savepos + savelen <= INBUFSIZE);
        int inlen = recv(m_sockClient, m_bufInput + savepos, savelen, 0);
        if (inlen > 0)
        {
            // 有接收到数据  
            m_nInbufLen += inlen;

            if (m_nInbufLen > INBUFSIZE)
                return false;

            // 接收第二段数据(一次接收没有完成，接收第二段数据)  
            if (inlen == savelen && m_nInbufLen < INBUFSIZE)
            {
                int32 savelen = INBUFSIZE - m_nInbufLen;
                int32 savepos = (m_nInbufStart + m_nInbufLen) % INBUFSIZE;
                //CHECKF(savepos + savelen <= INBUFSIZE);
                inlen = recv(m_sockClient, m_bufInput + savepos, savelen, 0);
                if (inlen > 0)
                {
                    m_nInbufLen += inlen;
                    if (m_nInbufLen > INBUFSIZE)
                        return false;
                }
                else if (inlen == 0)
                {
                    Destroy();
                    return false;
                }
                else
                {
                    // 连接已断开或者错误（包括阻塞）  
                    if (HasError())
                    {
                        Destroy();
                        return false;
                    }
                }
            }
        }
        else if (inlen == 0)
        {
            Destroy();
            return false;
        }
        else
        {
            // 连接已断开或者错误（包括阻塞）  
            if (HasError())
            {
                Destroy();
                return false;
            }
        }

        return true;
    }

    /**
     *   ? 如果 OUTBUF > SENDBUF 则需要多次SEND（）
     */
    // Trigger send out the data.
    bool WinSock2_Socket::Flush(void)
    {
        if (m_sockClient == INVALID_SOCKET)
            return false;

        if (m_nOutbufLen <= 0)
            return true;

        // 发送一段数据  
        int32 outsize;
        outsize = send(m_sockClient, m_bufOutput, m_nOutbufLen, 0);
        if (outsize > 0)
        {
            // 删除已发送的部分  
            if (m_nOutbufLen - outsize > 0)
                memcpy(m_bufOutput, m_bufOutput + outsize, m_nOutbufLen - outsize);

            m_nOutbufLen -= outsize;

            if (m_nOutbufLen < 0)
                return false;
        }
        else
        {
            if (HasError())
            {
                Destroy();
                return false;
            }
        }

        return true;
    }

    // Check if the server still alive.
    bool WinSock2_Socket::Check(void)
    {
        // 檢查狀態  
        if (m_sockClient == INVALID_SOCKET)
            return false;

        char buf[1];
        int32 ret = recv(m_sockClient, buf, 1, MSG_PEEK);
        if (ret == 0)
        {
            Destroy();
            return false;
        }
        else if (ret < 0)
        {
            if (HasError())
            {
                Destroy();
                return false;
            }
            else // 阻塞
            {
                return true;
            }
        }
        else // 有数据
        {
            return true;
        }

        return true;
    }

    // Destroy the connect socket (CLIENT), and do 
    // socket descriptor cleanup.
    void WinSock2_Socket::Destroy(void)
    {
        // 關閉  
        struct linger so_linger;
        so_linger.l_onoff = 1;
        so_linger.l_linger = 500;
        int32 ret = setsockopt(m_sockClient, SOL_SOCKET, SO_LINGER, (const char*)&so_linger, sizeof(so_linger));

        CloseSocket();

        m_sockClient = INVALID_SOCKET;
        m_nInbufLen = 0;
        m_nInbufStart = 0;
        m_nOutbufLen = 0;

        memset(m_bufOutput, 0, sizeof(m_bufOutput));
        memset(m_bufInput, 0, sizeof(m_bufInput));
    }

    /**
     * 檢查用戶是否點擊"是"
     * 相關文章: http://robbiem01.tripod.com/Tutorials/MessageBox_Demos.html
     * 相關文章: http://c.biancheng.net/cpp/html/2846.html
     * 相關文章: http://www.cplusplus.com/forum/general/92220/
     *
     * if 是: 連上官網
     * if 不是: 不做任何動作
     */
    void WinSock2_Socket::ConnectToOfficialWebsite()
    {
#ifdef _WIN32
        if (JCS_MessageBox(L"D3DVS2013_Framework_JCS", L"無法登入入伺服器...\n詳情請查看官網!", MB_ICONQUESTION | MB_YESNO) == IDYES)
        {
            // 如果點擊"是", 開啟流覽器並連上官網!!
            ShellExecute(
                NULL,
                L"open",
                L"http://54.148.134.127/",        // 要連結上的網址 (( 請放入官網url
                NULL,
                NULL,
                SW_SHOWNORMAL);
        }

        return;
#endif // _WIN32

#ifdef _OSX

        return;
#endif // _OSX
    }

    }

#endif // _WIN32
