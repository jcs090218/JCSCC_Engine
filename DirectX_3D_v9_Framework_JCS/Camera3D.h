/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __CAMERA_3D_H__
#define __CAMERA_3D_H__

#include "D3DX_v9_StdAfx.h"
#include "GraphicsD3D9.h"

namespace JCS_D3DX_v9_Engine
{

    class Camera3D
    {
    public:
        Camera3D();
        virtual ~Camera3D();

        void Update(float32 deltaTime, GraphicsD3D9* gDevice);

        // setter
        void setCameraPosition(D3DXVECTOR3* newPosition) { this->vCamera = newPosition; }
        void setLookAtPoint(D3DXVECTOR3* newLookAtPoint) { this->vLookAt = newLookAtPoint; }
        void setUpDirection(D3DXVECTOR3* newUpVector) { this->vUpVector = newUpVector; }

        // getter
        D3DXVECTOR3* getCameraPosition() { return this->vCamera; }
        D3DXVECTOR3* getLookAtPoint() { return this->vLookAt; }
        D3DXVECTOR3* getUpDirection() { return this->vUpVector; }

    protected:
        D3DXVECTOR3* vCamera;            // position
        D3DXVECTOR3* vLookAt;            // look at position
        D3DXVECTOR3* vUpVector;            // the up direction
        D3DXMATRIX* matView;
        D3DXMATRIX* matProj;

    };
}

#endif // __CAMERA_3D_H__

