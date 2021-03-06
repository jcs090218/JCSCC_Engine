#ifndef __SPRITE3D_H__
/**
 * $File: Sprite3D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2014 by Shen, Jen-Chieh $
 */
#define __SPRITE3D_H__


#include "D3DX_v9_StdAfx.h"


namespace JCS_D3DX_v9_Engine
{

    /**
     * 相關教學:
     * http://www.toymaker.info/Games/html/sprites.html
     */

	 //====================================================================================
	 // Name : Sprite3D 
	 //
	 // Description : 
	 //====================================================================================
    class Sprite3D
    {
    public:
        Sprite3D();
        ~Sprite3D();

        bool Initialize(LPDIRECT3DDEVICE9 device, std::wstring fileName,
            float width, float height, float alpha = 255);
        bool IsInitialize();
        virtual void Draw(float deltaTime, D3DXVECTOR3 position);

        bool reloadTexture();
        void rotate();

        //-- Scale Functions
        void scaleTextureWithPixels(float width, float height);
        void scaleTextureWithRatio(float width, float height);
        void scaleTextureIncreasingPixels(float increasingWidth, float increasingHeight);

        float width, height;        // 畫素
        float scaleX = 1, scaleY = 1;
        float a = 255, r = 255, g = 255, b = 255;
        D3DXVECTOR2 pivot;

        /** setter **/
        void setPivot(D3DXVECTOR2 newPivot);
        void setWidth(const float newWidth) { this->width = newWidth; }
        void setHeight(const float newHeight) { this->height = newHeight; }
        // 更新 "寬" & "長" & "設置中心點"到中心位置
        void setWidthHeightPivotToCenter(const float width, const float height) {
            this->width = width;
            this->height = height;
            setPivot(D3DXVECTOR2(width / 2, height / 2));
        }
        void setScaleX(float newScaleX) { this->scaleX = newScaleX; }
        void setScaleY(float newScaleY) { this->scaleY = newScaleY; }

        /** getter **/
        D3DXVECTOR2 getPivot() { return this->pivot; }
        float getWidth() { return this->width; }
        float getHeight() { return this->height; }
        float getScaleX() { return this->scaleX; }
        float getScaleY() { return this->scaleY; }

    private:
        LPD3DXSPRITE d3dspt;        // for Drawing Sprite preparation
        LPDIRECT3DTEXTURE9 d3dtex;        // texture for sprite

        // Attributs
        D3DCOLOR color;
        bool initialized;

    protected:
        bool isScale = false;
        void isScaling();

        bool settingPivot = false;
        void onSetPivot();
    };

}

#endif    // __SPRITE3D_H__

