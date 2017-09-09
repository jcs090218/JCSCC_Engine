/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __SOCKET_LIB_H__
/**
 * $File: Socket_Lib.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __SOCKET_LIB_H__


//------------------------------------------------------------------------------
#ifdef _WIN32

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

// this should be ontop <windows.h> and <vld.h>
#include <winsock2.h>

////// LINKER ////////////////
#pragma comment(lib,"ws2_32.lib")            // socket lib

//------------------------------------------------------------------------------
#elif _OSX


//------------------------------------------------------------------------------
#else   // Cross Platform

// Boost Asio Network Libraries
#include <boost\asio.hpp>

// SDL net
#include <SDL_net.h>

#endif 

#endif // __SOCKET_LIB_H__

