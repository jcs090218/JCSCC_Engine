#ifndef __SCENETYPE_H__
/**
 * $File: SceneType.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __SCENETYPE_H__

namespace JCS_GameInterface
{
    enum class SceneType
    {
        SCENE_2D,
        SCENE_3D,
        SCENE_2p5D
    };
}

typedef JCS_GameInterface::SceneType SceneType;

#endif // __SCENETYPE_H__

