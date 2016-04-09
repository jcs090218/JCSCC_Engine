/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

// JayCeS_StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __JAYCES_STDAFX_H__
#define __JAYCES_STDAFX_H__

// Memory Leak Detector
#include "JCS_vld.h"

#ifdef _WIN32
// Windows Header Files:
#include <windows.h>
#include <windowsx.h>
#endif // _WIN32

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory>
#include <tchar.h>
#include <assert.h>
#include <ctime>
#include <string>
#include <cstring>		// strlen, memcpy, etc.
#include <cstdlib>		// exit
#include <cfloat>		// FLT_MAX
#include <sstream>
#include <cmath>		// abs, sqrt
#include <cassert>		// assert
#include <algorithm>	// max, min
#include <iomanip>
#include <queue>
#include <stdint.h>     // all the uint8 and int8 stuff in "JCS_IEMath.h"
#include <iostream>
#include <random>       // random generator
#include <map>
#include <list>
#include <unordered_map>
#include <functional>
#include <commctrl.h>   // Tree View Window needed.
#include <ShObjIdl.h>
#include <fstream>      // for file I/O
#include <stack>
#include <deque>

// Libraries


// Local Header Files
#include "JCS_Name.h"
#include "SafePointer.h"
#include "JayCeS_Globals.h"
#include "JayCeS_Error.h"
#include "JCS_Type.h"

////// LINKER ////////////////
#ifdef _WIN32
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "strmiids.lib")
#endif // _WIN32


#endif // __JAYCES_STDAFX_H__

