/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

// GameInterface_StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __GAMEINTERFACE_STDAFX_H__
#define __GAMEINTERFACE_STDAFX_H__

#include <GameTool_JCS\GameTool_StdAfx.h>

// Multi-threading Handling
#include <thread>
#include <mutex>
#include <future>

// Addtion Tool
#include "JCS_IEMath.h"
#include "JCS_GameType.h"

// Precompiled
#include "API_Type.h"
#include "SceneType.h"
#include "RenderDevice.h"
#include "RenderDeviceFactory.h"

// Interface
#include "JCS_Scene.h"
#include "JCS_Application.h"
#include "JCS_Thread.h"
#include "JCS_Input.h"
#include "JCS_Component.h"
#include "JCS_GameType.h"
#include "JCS_Scene.h"
#include "JCS_Script.h"
#include "JCS_World.h"
#include "JCS_XML_Loader.h"


#endif // __GAMEINTERFACE_STDAFX_H__

