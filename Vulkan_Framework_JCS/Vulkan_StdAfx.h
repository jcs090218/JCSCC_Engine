#ifndef __VULKAN_STDAFX_H__
/**
* $File: Vulkan_StdAfx.h $
* $Date: $
* $Revision: $
* $Creator: Jen-Chieh Shen $
* $Notice: See LICENSE.txt for modification and distribution information
*                   Copyright (c) 2016 by Shen, Jen-Chieh $
*/
#define __VULKAN_STDAFX_H__

// Vulkan_StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
// 


#include <GameTool_JCS\GameTool_StdAfx.h>

// Vulkan
#include <Vulkan_Framework_JCS\VulkanSDK\1.0.17.0\Include\vulkan\vulkan.h>

// Vulkan using GLFW for window api
// GLFW are able to run on linux and window
#define GLFW_INCLUDE_VULKAN
#include <Libraries\glfw-3.2.bin.WIN32\include\GLFW\glfw3.h>

// Vulkan using GLM for 3D mathmatic
// also cross platform.
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <Libraries\glm\glm\vec4.hpp>
#include <Libraries\glm\glm\mat4x4.hpp>

// Libraries

// Local Header Files
#include "Vulkan_CrashReason.h"

////// LINKER ////////////////
#pragma comment(lib, "vulkan-1.lib")
#pragma comment(lib, "glfw3.lib")



#endif // __VULKAN_STDAFX_H__

