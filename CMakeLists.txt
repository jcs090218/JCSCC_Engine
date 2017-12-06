# ========================================================================
# $File: CMakeLists.txt $
# $Date: 2017-12-06 16:49:50 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#					Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# project settings
PROJECT(JCSCC)
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

# environment settings
ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

# include directories
INCLUDE_DIRECTORIES()

# link directories
LINK_DIRECTORIES(Libraries/glfw-3.2.bin.WIN32/lib-vc2015)
LINK_DIRECTORIES(Vulkan_Framework_JCS/VulkanSDK/1.0.17.0/Bin32)
LINK_DIRECTORIES(Allegro_Framework_JCS\Allegro\lib)
LINK_DIRECTORIES(GameSound_JCS\FMOD\lib\x86)
LINK_DIRECTORIES(DirectX_3D_v9_Framework_JCS\DirectX SDK\lib\x86)
LINK_DIRECTORIES(SDL_Framework_JCS\SDL\lib\x86)
LINK_DIRECTORIES(OpenGL_Framework_JCS\OpenGL\lib\x86)
LINK_DIRECTORIES(LuaEngine_JCS\Lua\lib\x86)

# subdir settings
MESSAGE("Porject Directory Tree: ${PROJECT_BINARY_DIR}")
ADD_SUBDIRECTORY(Allegro_Framework_JCS)
ADD_SUBDIRECTORY(D3DVS2013_Test_JCS)
ADD_SUBDIRECTORY(Direct_2D_Framework_JCS)
ADD_SUBDIRECTORY(DirectX_3D_v9_Framework_JCS)
ADD_SUBDIRECTORY(DirectX_3D_v11_Framework_JCS)
ADD_SUBDIRECTORY(DirectX_3D_v12_Framework_JCS)
ADD_SUBDIRECTORY(GameInput_JCS)
ADD_SUBDIRECTORY(GameInterface_JCS)
ADD_SUBDIRECTORY(GameResourceS_JCS)
ADD_SUBDIRECTORY(GameSound_JCS)
ADD_SUBDIRECTORY(GameTool_JCS)
ADD_SUBDIRECTORY(GameUtility_JCS)
ADD_SUBDIRECTORY(GUI_Framework_JCS)
ADD_SUBDIRECTORY(JayCeS Maker)
ADD_SUBDIRECTORY(JayCeS_GamePatcher)
ADD_SUBDIRECTORY(JayCeS_JCS)
ADD_SUBDIRECTORY(JcsLib)
ADD_SUBDIRECTORY(JCSMath_Lib)
ADD_SUBDIRECTORY(JCSSTL_Lib)
ADD_SUBDIRECTORY(LuaEngine_JCS)
ADD_SUBDIRECTORY(OpenGL_Framework_JCS)
ADD_SUBDIRECTORY(SDL_Framework_JCS)
ADD_SUBDIRECTORY(SFML_Framework_JCS)
ADD_SUBDIRECTORY(Socket_Framework_JCS)
ADD_SUBDIRECTORY(Test_VS2013_GamePatcher_Game)
ADD_SUBDIRECTORY(Test_VS2013_JayCeS_OS)
ADD_SUBDIRECTORY(Utility_GameResourceS_JCS_Test_VS2013)
ADD_SUBDIRECTORY(Vulkan_Framework_JCS)

ADD_SUBDIRECTORY(Libraries)
