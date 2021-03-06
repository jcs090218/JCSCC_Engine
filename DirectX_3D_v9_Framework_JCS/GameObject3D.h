/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __GAMEOBJECT3D_H__
#define __GAMEOBJECT3D_H__

#define _USE_MATH_DEFINES

#include "Sprite3D.h"
#include "Animation.h"


/**
 * Since creating a 2D Framework we call this GameObject instead of GameSprite
 */
namespace JCS_D3DX_v9_Engine
{

    enum class ObjectStatus{ ALIVE, GET_HIT, DEAD };

    class GameObject3D
    {
    public:
        GameObject3D();
        GameObject3D(float32 x, float32 y, float32 z = 0, float32 rotation = 0);
        ~GameObject3D();

        virtual bool Initialize(LPDIRECT3DDEVICE9 device, std::wstring fileName,
            float32 width = 50.0f, float32 height = 50.0f, float32 alpha = 255.0f);
        virtual void Update(float32 deltaTime);
        virtual void Draw(float32 deltaTime);

        ObjectStatus GetStatus()const;

        /** setter **/
        void setWidth(float32 _width) { this->getSprite()->setWidth(_width); }
        void setHeight(float32 _height) { this->getSprite()->setWidth(_height); }
        void reloadTexture() { this->sprite->reloadTexture(); }
        void setPosition(float32 x, float32 y, float32 z = 0)
        {
            position.x = x; position.y = y; position.z = z;
        }

        /** getter **/
        Sprite3D* getSprite() { return this->sprite; }
        void setAlpha(float32 _alpha) { getSprite()->a = _alpha; }
        float32 getAlpha() { return getSprite()->a; }
        D3DXVECTOR3 getPosition() { return this->position; }
        float32 getWidth() { return this->getSprite()->width; }
        float32 getHeight() { return this->getSprite()->height; }
        float32 getScaleX() { return this->getSprite()->getScaleX(); }
        float32 getScaleY() { return this->getSprite()->getScaleY(); }


        // -- Effect
        void AlphaChange(int32 time, int32 type);        // time: time to fade, type: 0 for fade-out(255 - 0), 1 for fade-in(0 - 255)
        void Shake(int32 time, float32 margin);
        void ScaleChange(int32 time, float32 finalChangeWidth, float32 finalChangeHeight);
        void ScaleBounce(int32 time, float32 margin, int32 cycle);
        void MoveTo(int32 time, D3DXVECTOR3 position);

        // Variables
        float32 x = 0, y = 0, z = 0;        // 實際顯示的位置
        D3DXVECTOR3 position;    // pivot後的位置

    protected:
        // Physics Data
        float32 rotation;

        bool collision = true;

        // actual effect function
        void OnAlphaChange(float32 deltaTime);
        void OnShake(float32 deltaTime);
        void OnScaleChange(float32 deltaTime);
        void OnScaleBounce(float32 deltaTime);
        void OnMoveTo(float32 deltaTime);

        ObjectStatus status;
        Sprite3D *sprite;        // add texture to our gameObject
        Animation *animation;
        float32 maxSpeed;
        std::wstring currentDisplay;        // for SPRITE
        std::wstring currentAnim;            // for ANIMATION

        // 尋找TEXTURE中心點
        float32 pivotPosX() { return this->x - getSprite()->getPivot().x; }
        float32 pivotPosY() { return this->y - getSprite()->getPivot().y; }

        //-- Alpha Effect --//
        bool isAlphaChange = false;        // trigger of the fade effect
        int32 fadeType = 0;            // 0 for fade out, 1 for fade in
        float32 fadeTimer = 0;            // timer help to caculate the fade time
        int32 fadeTime = 0;            // the time we want to fade

        //-- Shake Effect --//
        bool isShake = false;
        D3DXVECTOR3 shakeOrigin;
        int32 shakeTime = 0;
        float32 shakeMargin = 0;
        float32 shakeTimer = 0;

        //-- Scale Effect --//
        bool isScale = false;
        int32 scaleTime = 0;
        float32 scaleFinalChangeWidth = 0;
        float32 scaleFinalChangeHeight = 0;
        float32 scaleTimer = 0;
        D3DXVECTOR3 scaleOrigin;

        //-- Scale Bounce Effect --//
        bool isBounce = false;
        int32 bounceTime = 0;
        float32 bounceMargin = 0;
        int32 bounceCycle = 0;
        D3DXVECTOR3 bounceOrigin;
        float32 bounceTimer = 0;
        float32 bounceScaleOrigin = 0;

        //-- Move Effect --//
        bool isMoveTo = false;
        int32 moveToTime = 0;
        D3DXVECTOR3 movePosition;
        float32 moveToTimer = 0;

    };
}

#endif // __GAMEOBJECT3D_H__
