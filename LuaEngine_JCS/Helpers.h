#ifndef __HELPERS_H__
/**
 * $File: Helpers.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2016 by Shen, Jen-Chieh $
 */
#define __HELPERS_H__

#include "LuaEngine_StdAfx.h"

#define LOG_ERROR -1
#define LOG_WARNING 1
#define LOG_PLAIN 0
#define LOG_INFO 2
#define LOG_LUA_ERR 3

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define IXLOG(x, y, z) { ix_logprint(x, y, z); }

std::string readFile(std::string filepath);
//
std::string uint8_tToString(uint8_t* text, size_t len);

void ix_logprint(const char* msg, int type, bool breakln = false);

template <class DstType, class SrcType>
bool IsType(const SrcType* src)
{
    return dynamic_cast<const DstType*>(src) != 0;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);

std::vector<std::string> split(const std::string &s, char delim);

void stringToUpper(std::string &s);


#endif // __HELPERS_H__
