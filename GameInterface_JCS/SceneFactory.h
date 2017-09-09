#ifndef _SCENEFACTORY_H__
/**
 * $File: SceneFactory.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define _SCENEFACTORY_H__


#include "GameInterface_StdAfx.h"

#include <Direct_2D_Framework_JCS\Scene2D.h>
#include <DirectX_3D_v11_Framework_JCS\Scene2D.h>
#include <DirectX_3D_v9_Framework_JCS\Scene3D.h>

namespace JCS_GameInterface
{
    class SceneFactory
    {
    public:
        static JCS_Scene* CreateScene(API_Type api, SceneType scene)
        {
            switch (api)
            {
            // Direct 2D
            case API_Type::DIRECT2D: 
            {
                return new JCS_D2DEngine::Scene2D(); 
            } break;
            // Direct 11
            case API_Type::DIRECTX3D_11:
            {
                switch (scene)
                {
                case SceneType::SCENE_2D: { return new JCS_D3DX_v11_Engine::Scene2D(); } 
                case SceneType::SCENE_3D: { return nullptr; } 
                }
            } break;
            // Direct 9
            case API_Type::DIRECTX3D_9:
            {
                switch (scene)
                {
                case SceneType::SCENE_2D: { return nullptr; }
                case SceneType::SCENE_3D: { return new JCS_D3DX_v9_Engine::Scene3D(); }
                }
            } break;
            // OpenGL
            case API_Type::OPENGL:
            {
                switch (scene)
                {
                case SceneType::SCENE_2D: { return nullptr; }
                case SceneType::SCENE_3D: { return nullptr; }
                }
            } break;
            // SDL
            case API_Type::SDL:
            {
                switch (scene)
                {
                case SceneType::SCENE_2D: { return nullptr; }
                case SceneType::SCENE_3D: { return nullptr; }
                }
            } break;
            }

            return nullptr;
        }
    };

}

typedef JCS_GameInterface::SceneFactory SceneFactory;

#endif // _SCENEFACTORY_H__

