/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Camera3D.h"


namespace JCS_D3DX_v9_Engine
{

    Camera3D::Camera3D()
    {
        vCamera = new D3DXVECTOR3(0.0f, 0.0f, 0.0f);
        vLookAt = new D3DXVECTOR3(0.0f, 0.0f, 0.0f),
            vUpVector = new D3DXVECTOR3(0.0f, 1.0f, 0.0f);
        matView = new D3DXMATRIX;
        matProj = new D3DXMATRIX;
    }


    Camera3D::~Camera3D()
    {
    }

    void Camera3D::Update(float32 deltaTime, GraphicsD3D9* gDevice)
    {
        D3DXMatrixLookAtLH(matView, vCamera, vLookAt, vUpVector);
        gDevice->GetDevice()->SetTransform(D3DTS_VIEW, matView);        // set the view transform to matView

        D3DXMatrixPerspectiveFovLH(matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
        gDevice->GetDevice()->SetTransform(D3DTS_PROJECTION, matProj);
    }

}

