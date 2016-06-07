/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __NETWORK_CONSTANTS_H__
#define __NETWORK_CONSTANTS_H__


#define _MAX_MSGSIZE 16 * 1024	// 暫定一個消息最大回16k
#define BLOCKSECONDS 30		// INIT函數阻塞時間
#define INBUFSIZE	(64 * 1024)		//?	具体尺寸根据剖面报告调整  接收数据的缓存
#define OUTBUFSIZE	(8 * 1024)		//? 具体尺寸根据剖面报告调整。 发送数据的缓存，当不超过8K时，FLUSH只需要SEND一次

#define DEFAULT_HOST_NAME "127.0.0.1"
#define DEFAULT_PORT 8585



#endif // __NETWORK_CONSTANTS_H__
