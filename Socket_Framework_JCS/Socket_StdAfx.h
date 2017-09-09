/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/



#ifndef __SOCKET_STDAFX_H__
/**
 * $File: Socket_StdAfx.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __SOCKET_STDAFX_H__

 // Socket_StdAfx.h : include file for standard system include files,
 //  or project specific include files that are used frequently, but
 //      are changed infrequently
 //


#include "Socket_Lib.h"

#include <GameTool_JCS\GameTool_StdAfx.h>


//// Local Headers ////////////

//-- Interfaces
#include "JCS_Socket.h"
#include "JCS_CodecFactory.h"
#include "JCS_PacketDecoder.h"
#include "JCS_PacketEncoder.h"

//-- Setting
#include "NetworkConstants.h"


#endif // __SOCKET_STDAFX_H__

