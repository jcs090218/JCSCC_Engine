/**
 * $File: Sprite3D.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2014 by Shen, Jen-Chieh $
 */

#include "Sprite3D.h"


namespace JCS_D3DX_v9_Engine
{

    Sprite3D::Sprite3D()
    {
        // We are not initialized yet
        initialized = false;
    }

    Sprite3D::~Sprite3D()
    {

    }

    bool Sprite3D::Initialize(LPDIRECT3DDEVICE9 device, std::wstring fileName, float width, float height, float alpha)
    {

        // When color is set white, what you see is exactly what the image looks like.
        this->a = alpha;
        color = D3DCOLOR_ARGB((int)a, (int)r, (int)g, (int)b);

        // 依據pixel設定 width, height
        this->width = width;
        this->height = height;

        // Same functionality as D3DXCreateTextureFromFile EXCEPT width and height are manually entered
        if (!SUCCEEDED(D3DXCreateTextureFromFileEx(device, fileName.c_str(), (int)width, (int)height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN,
            D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &d3dtex)))
        {
            std::wstring s = L"There was an issue creating the texture. Make sure the requested image is available. Requested image: " + fileName;
            MessageBox(NULL, s.c_str(), NULL, NULL);
            return false;
        }

        // Attempt to create the sprite
        if (!SUCCEEDED(D3DXCreateSprite(device, &d3dspt)))
        {
            MessageBox(NULL, L"There was an issue creating the sprite", NULL, NULL);
            return false;
        }

        return true;
    }

    bool Sprite3D::IsInitialize()
    {
        return initialized;
    }

    void Sprite3D::Draw(float deltaTime, D3DXVECTOR3 position)
    {
        color = D3DCOLOR_ARGB((int)a, (int)r, (int)g, (int)b);

        if (d3dspt && d3dtex)
        {
            d3dspt->Begin(D3DXSPRITE_ALPHABLEND);    // Begin Render Sprite

            onSetPivot();        // 設置中心位置
            isScaling();            // 調整大小

            d3dspt->Draw(d3dtex, NULL, NULL, &position, color);
            d3dspt->End();        // End Render Sprite
        }
    }

    /**
     * 重讀Texture...
     */
    bool Sprite3D::reloadTexture()
    {
        return false;
    }

    /**
     * 調整大小 (Pixels)
     * 輸入目標: n 畫素
     *
     * widthPixel,        直接更改 畫素(寬)
     * heightPixel,        直接更改 畫素(長)
     */
    void Sprite3D::scaleTextureWithPixels(float widthPixel, float heightPixel)
    {
        if (this->width == widthPixel && this->height == heightPixel) {
            OutputDebugString(L"\nSprite::scaleTextureWithPixels()-> Width or Height are exactly the same!\n");
        }
        else if (isScale) {
            OutputDebugString(L"\nSprite::scaleTextureWithPixels()-> Is still scaling Texture!\n");
        }
        else {
            this->scaleX = widthPixel / width;
            this->scaleY = heightPixel / height;
            if (width != widthPixel) this->width = widthPixel;
            if (height != heightPixel) this->height = heightPixel;

            isScale = true;            // 開始調整大小
        }
    }
    /**
    * 調整大小 (Ratio)
    * 輸入目標: n 倍數
    *
    * newScaleX,    設置倍數  1 = 原來的樣子, -1 相反大小,
    *                        1.5 = 一點五倍大小依此類推, 2 = 兩倍大小依此類推
    * newScaleY,    設置倍數  1 = 原來的樣子, -1 相反大小,
    *                        1.5 = 一點五倍大小依此類推, 2 = 兩倍大小依此類推
    */
    void Sprite3D::scaleTextureWithRatio(float newScaleX, float newScaleY)
    {
        if (this->scaleX == newScaleX || this->scaleY == newScaleY) {
            OutputDebugString(L"\nSprite::scaleTextureWithRatio-()> Width or Height are exactly the same!\n");
        }
        else if (isScale) {
            OutputDebugString(L"\nSprite::scaleTextureWithRatio()-> Is still scaling Texture!\n");
        }
        else {
            this->scaleX = newScaleX;
            this->scaleY = newScaleY;
            isScale = true;                // 開始調整大小
        }
    }
    /**
     *
     */
    void Sprite3D::scaleTextureIncreasingPixels(float increasingWidth, float increasingHeight)
    {
        if (isScale) {
            OutputDebugString
                (L"\nSprite::scaleTextureIncreasingPixels()-> Is still scaling Texture!\n");
        }
        else {
            static float x = getWidth();
            static float y = getHeight();
            setWidth(width + increasingWidth);
            setHeight(height + increasingHeight);
            this->scaleX = getWidth() / x;
            this->scaleY = getHeight() / y;

            isScale = true;                // 開始調整大小
        }
    }
    void Sprite3D::isScaling()
    {
        if (isScale) {
            D3DXVECTOR2 scaling(scaleX, scaleY);
            D3DXMATRIX mat;
            D3DXMatrixTransformation2D(&mat, NULL, NULL, &scaling, NULL, NULL, NULL);
            d3dspt->SetTransform(&mat);
            isScale = false;                // 開始調整大小
        }
    }

    /**
     * 設置中心位置
     */
    void Sprite3D::setPivot(D3DXVECTOR2 newPivot)
    {
        if (this->pivot != newPivot) {
            this->pivot = newPivot;
            settingPivot = true;            // 開始調整中心位置
        }
    }
    void Sprite3D::onSetPivot()
    {
        if (settingPivot) {
            D3DXVECTOR2 spriteCentre = pivot;
            D3DXMATRIX mat;
            D3DXMatrixTransformation2D(&mat, NULL, NULL, NULL, &spriteCentre, NULL, NULL);
            d3dspt->SetTransform(&mat);
            settingPivot = false;
        }
    }

}

