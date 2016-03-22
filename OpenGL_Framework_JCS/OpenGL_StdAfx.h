//OpenGL_StdAfx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#ifndef __OPENGL_STDAFX_H__
#define __OPENGL_STDAFX_H__

#include <GameTool_JCS\GameTool_StdAfx.h>

#include <OpenGL_Framework_JCS\OpenGL\include\GL\glew.h>
#include <OpenGL_Framework_JCS\OpenGL\include\glm\glm.hpp>
#include <OpenGL_Framework_JCS\OpenGL\include\glm\gtx\rotate_vector.hpp>

// Libraries

// Local Header Files
#include "Vertex.h"
#include "GLTexture.h"
#include "OpenGL_CrashReason.h"

////// LINKER ////////////////
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")


#endif // __OPENGL_STDAFX_H__

