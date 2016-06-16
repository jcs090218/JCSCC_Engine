/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "D3DX_v9_StdAfx.h"

namespace JCS_D3DX_v9_Engine
{

    class Animation
    {
    public:
        Animation(int frame = 0);
        ~Animation();

        bool Initialize(LPDIRECT3DDEVICE9 device, std::wstring fileName,
            float width, float height, float alpha = 255.0f);

        void PlayAnimationWithSpriteSheet(float deltaTime, D3DXVECTOR3 position = D3DXVECTOR3(0, 0, 0),
            int totalFrame = 1, bool bLoop = true, float alpha = 255.0f);

    private:
        LPD3DXSPRITE d3dspt;        // for Drawing Sprite preparation
        LPDIRECT3DTEXTURE9 d3dtex;        // the actual sprite!!

        D3DCOLOR color;
        int nFrame = 0;

        int totalFrame = 0;
    };

}

#endif // __ANIMATION_H__

