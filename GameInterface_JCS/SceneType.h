#ifndef __SCENETYPE_H__
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

