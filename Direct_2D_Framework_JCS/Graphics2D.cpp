/**
 * $File: Graphics2D.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Graphics2D.h"

/**
 * 相關文章: 
 *        - http://www.cnblogs.com/graphics/archive/2011/05/25/1963563.html
 *      - https://msdn.microsoft.com/en-us/library/windows/desktop/dd370994(v=vs.85).aspx
 */
namespace JCS_D2DEngine
{
    Graphics2D::Graphics2D() 
        : 
        m_pDirect2dFactory(nullptr),
        m_pRenderTarget(nullptr),
        m_pBrush(nullptr)
    {

    }


    Graphics2D::~Graphics2D()
    {
        SafeReleaseCOM(m_pDirect2dFactory);
        SafeReleaseCOM(m_pRenderTarget);
        SafeReleaseCOM(m_pBrush);
    }

    bool Graphics2D::Initialize(HWND hWnd)
    {
        HRESULT rs = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &m_pDirect2dFactory);
        if (rs != S_OK) 
            return false;

        RECT rect;
        GetClientRect(hWnd, &rect);

        // Create a Direct2D render target.
        rs = m_pDirect2dFactory->CreateHwndRenderTarget(
            D2D1::RenderTargetProperties(),
            D2D1::HwndRenderTargetProperties(
            hWnd, D2D1::SizeU(rect.right, rect.bottom)),
            &m_pRenderTarget);
        if (rs != S_OK) 
            return false;

        // Set Default Color as white
        SetBrushColor(1.0f, 1.0f, 1.0f, 1.0f);

        return true;
    }

    /**
     * Inside the if statement you just created, initiate 
     * drawing by calling the render target's BeginDraw method. 
     * Set the render target's transform to the identity matrix, and clear the window.
     * 
     * https://msdn.microsoft.com/en-us/library/windows/desktop/dd370994(v=vs.85).aspx
     */
    void Graphics2D::SetTransform(const D2D1_MATRIX_3X2_F& transform/* = D2D1::Matrix3x2F::Identity()*/)
    { 
        m_pRenderTarget->SetTransform(transform); 
    }

    /**
     * float r :                                紅色
     * float g :                                綠色
     * float b :                                藍色
     * float a :                                Alpha Channel
     */
    void Graphics2D::SetBrushColor(float r, float g, float b, float a)
    {
        SafeReleaseCOM(m_pBrush);
        m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(r, g, b, a), &m_pBrush);
    }
    /**
     * Screen Color
     * 
     * r : RED, g : GREEN, b : BLUE, a : ALPHA
     */
    void Graphics2D::ClearScreen(float r, float g, float b, float a)
    {
        m_pRenderTarget->Clear(D2D1::ColorF(r, g, b, a));
    }

    /**
     * Function that could Draw a "圓形".
     * 
     * float x :        X 座標位置
     * float y :        Y 座標位置
     * float radius :    圓的半徑
     * float r :        Red Color
     * float g :        Green Color
     * float b :        Blue Color
     * float a :        Alpha Color
     * float stroke :   Stroke Width
     */
    void Graphics2D::drawCircle(float x, float y,
        float radius, 
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);
        m_pRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), m_pBrush, strokeWidth, strokeStyle);
    }
    /**
    * Function that could Draw a "橢圓型".
    *
    * float x :        X 座標位置
    * float y :        Y 座標位置
    * float radiusA :    長軸半徑
    * float radiusB :    短軸半徑
    * float r :        Red Color
    * float g :        Green Color
    * float b :        Blue Color
    * float a :        Alpha Color
    * float stroke :   Stroke Width
    */
    void Graphics2D::drawElipse(float x, float y,
        float radiusA, float radiiusB, 
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);
        m_pRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radiusA, radiiusB), m_pBrush, strokeWidth, strokeStyle);
    }
    /**
    * This function will draw a "矩形".
    * 
    * float x :                                X 座標位置        (左上角坐标.x)
    * float y :                                Y 座標位置        (左上角坐标.y)
    * float width :                            長方形的寬度        (右下角坐标.x)
    * float height :                        長方形的高度        (右下角坐标.y)
    * float r :        Red Color
    * float g :        Green Color
    * float b :        Blue Color
    * float a :        Alpha Color
    * float strokeWidth :                    Stroke Width
    * ID2D1StrokeSytle* strokeStyle :        Stroke 風格
    */
    void Graphics2D::drawRectangle(float x, float y, float width, float height,
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);
        m_pRenderTarget->DrawRectangle(D2D1::RectF(x, y, width, height), m_pBrush, strokeWidth, strokeStyle);
    }
    /**
    * This function will draw a "用線畫的矩形".
    *
    * D2D1_POINT_2F* p1 :                    點一
    * D2D1_POINT_2F* p2 :                    點二
    * D2D1_POINT_2F* p3 :                    點三
    * D2D1_POINT_2F* p4 :                    點四
    * float r :        Red Color
    * float g :        Green Color
    * float b :        Blue Color
    * float a :        Alpha Color
    * float strokeWidth :                    Stroke Width
    * ID2D1StrokeSytle* strokeStyle :        Stroke 風格
    */
    void Graphics2D::drawRectangleWithLine(
        JCS_VECTOR2F* p1, JCS_VECTOR2F* p2,
        JCS_VECTOR2F* p3, JCS_VECTOR2F* p4,
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);

        D2D1_POINT_2F _p1, _p2, _p3, _p4;
        _p1.x = p1->x; _p1.y = p1->y;
        _p2.x = p2->x; _p2.y = p2->y;
        _p3.x = p3->x; _p3.y = p3->y;
        _p4.x = p4->x; _p4.y = p4->y;

        m_pRenderTarget->DrawLine(_p1, _p2, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(_p2, _p3, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(_p3, _p4, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(_p4, _p1, m_pBrush, strokeWidth, strokeStyle);
    }
    /**
    * This function will draw a "用線畫的矩形".
    *
    * D2D1_POINT_2F& p1 :                    點一
    * D2D1_POINT_2F& p2 :                    點二
    * D2D1_POINT_2F& p3 :                    點三
    * D2D1_POINT_2F& p4 :                    點四
    * float r :        Red Color
    * float g :        Green Color
    * float b :        Blue Color
    * float a :        Alpha Color
    * float strokeWidth :                    Stroke Width
    * ID2D1StrokeSytle* strokeStyle :        Stroke 風格
    */
    void Graphics2D::drawRectangleWithLine(
        JCS_VECTOR2F& p1, JCS_VECTOR2F& p2,
        JCS_VECTOR2F& p3, JCS_VECTOR2F& p4,
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);

        D2D1_POINT_2F _p1, _p2, _p3, _p4;
        _p1.x = p1.x; _p1.y = p1.y;
        _p2.x = p2.x; _p2.y = p2.y;
        _p3.x = p3.x; _p3.y = p3.y;
        _p4.x = p4.x; _p4.y = p4.y;

        m_pRenderTarget->DrawLine(_p1, _p2, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(_p2, _p3, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(_p3, _p4, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(_p4, _p1, m_pBrush, strokeWidth, strokeStyle);
    }
    /**
    * This function will draw a "正方形".
    *
    * float x :                                X 座標位置        (左上角坐标.x)
    * float y :                                Y 座標位置        (左上角坐标.y)
    * float length :                        正方形的長度        (右下角坐标.xy)
    * float r :        Red Color
    * float g :        Green Color
    * float b :        Blue Color
    * float a :        Alpha Color
    * float strokeWidth :                    Stroke Width
    * ID2D1StrokeSytle* strokeStyle :        Stroke 風格
    */
    void Graphics2D::drawSquare(float x, float y, float length, 
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);
        m_pRenderTarget->DrawRectangle(D2D1::RectF(x, y, length, length), m_pBrush, strokeWidth, strokeStyle);
    }
    /**
     * This function will draw a "三角形".
     *
     * D2D1_POINT_2F p0 :                        頂點一
     * D2D1_POINT_2F p1 :                        頂點二
     * D2D1_POINT_2F p2 :                        頂點三
     * float r :        Red Color
     * float g :        Green Color
     * float b :        Blue Color
     * float a :        Alpha Color
     * float strokeWidth :                        Stroke Width
     * ID2D1StrokeSytle* strokeStyle :            Stroke 風格
     */
    void Graphics2D::drawTriangle(D2D1_POINT_2F p0, D2D1_POINT_2F p1, D2D1_POINT_2F p2,
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);
        m_pRenderTarget->DrawLine(p0, p1, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(p1, p2, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(p2, p0, m_pBrush, strokeWidth, strokeStyle);
    }
    /**
    * This function will draw a "三角形".
    *
    * D2D1_POINT_2F p0 :                        頂點一
    * D2D1_POINT_2F p1 :                        頂點二
    * D2D1_POINT_2F p2 :                        頂點三
    * float r :        Red Color
    * float g :        Green Color
    * float b :        Blue Color
    * float a :        Alpha Color
    * float strokeWidth :                        Stroke Width
    * ID2D1StrokeSytle* strokeStyle :            Stroke 風格
    */
    void Graphics2D::drawTriangle(JCS_VECTOR2F& p0, JCS_VECTOR2F& p1, JCS_VECTOR2F& p2,
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);

        D2D1_POINT_2F tempP0;
        tempP0.x = p0.x;
        tempP0.y = p0.y;
        D2D1_POINT_2F tempP1;
        tempP1.x = p1.x;
        tempP1.y = p1.y;
        D2D1_POINT_2F tempP2;
        tempP2.x = p2.x;
        tempP2.y = p2.y;

        m_pRenderTarget->DrawLine(tempP0, tempP1, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(tempP1, tempP2, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(tempP2, tempP0, m_pBrush, strokeWidth, strokeStyle);
    }
    /**
    * This function will draw a "Line".
    *
    * D2D1_POINT_2F p0 :                    點一
    * D2D1_POINT_2F p1 :                    點二
    * float r :        Red Color
    * float g :        Green Color
    * float b :        Blue Color
    * float a :        Alpha Color
    * float strokeWidth :                    Stroke Width
    * ID2D1StrokeSytle* strokeStyle :        Stroke 風格
    */
    void Graphics2D::drawLine(D2D1_POINT_2F p0, D2D1_POINT_2F p1,
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);
        m_pRenderTarget->DrawLine(p0, p1, m_pBrush, strokeWidth, strokeStyle);
    }
    /**
    * This function will draw a "Line".
    *
    * JCS_GameTool::JCS_VECTOR2F p0 :        點一
    * JCS_GameTool::JCS_VECTOR2F p1 :        點二
    * float r :        Red Color
    * float g :        Green Color
    * float b :        Blue Color
    * float a :        Alpha Color
    * float strokeWidth :                    Stroke Width
    * ID2D1StrokeSytle* strokeStyle :        Stroke 風格
    */
    void Graphics2D::drawLine(JCS_VECTOR2F p0, JCS_VECTOR2F p1,
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);

        D2D1_POINT_2F tempP0, tempP1;
        tempP0.x = p0.x;
        tempP0.y = p0.y;
        tempP1.x = p1.x;
        tempP1.y = p1.y;

        m_pRenderTarget->DrawLine(tempP0, tempP1, m_pBrush, strokeWidth, strokeStyle);
    }
    /**
    * This function will draw a "圓角矩形".
    *
    * float x :                                X 座標位置        (左上角坐标.x)
    * float y :                                Y 座標位置        (左上角坐标.y)
    * float width :                            圓角矩形的寬度    (右下角坐标.x)
    * float height :                        圓角矩形的高度    (右下角坐标.y)
    * float radiusX :                        X轴半径
    * float radiusY :                        Y轴半径
    * float r :        Red Color
    * float g :        Green Color
    * float b :        Blue Color
    * float a :        Alpha Color
    * float strokeWidth :                    Stroke Width
    * ID2D1StrokeSytle* strokeStyle :        Stroke 風格
    */
    void Graphics2D::drawRoundedRectangle(float x, float y, float width, float height,
        float radiusX, float radiusY,
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);

        D2D1_ROUNDED_RECT roundedRect = D2D1::RoundedRect(
            D2D1::RectF(x, y, width, height),
            radiusX,
            radiusY
        );

        m_pRenderTarget->DrawRoundedRectangle(roundedRect, m_pBrush, strokeWidth, strokeStyle);
    }



    /**
     * Actual function drawing Hexagon Shape in 2D
     */
    void Graphics2D::drawHexagon(
        JCS_VECTOR2F& p0, JCS_VECTOR2F& p1,
        JCS_VECTOR2F& p2, JCS_VECTOR2F& p3,
        JCS_VECTOR2F& p4, JCS_VECTOR2F& p5,
        float r, float g, float b, float a,
        float strokeWidth, ID2D1StrokeStyle* strokeStyle)
    {
        SetBrushColor(r, g, b, a);

        D2D1_POINT_2F tempP0;
        tempP0.x = p0.x;
        tempP0.y = p0.y;
        D2D1_POINT_2F tempP1;
        tempP1.x = p1.x;
        tempP1.y = p1.y;
        D2D1_POINT_2F tempP2;
        tempP2.x = p2.x;
        tempP2.y = p2.y;
        D2D1_POINT_2F tempP3;
        tempP3.x = p3.x;
        tempP3.y = p3.y;
        D2D1_POINT_2F tempP4;
        tempP4.x = p4.x;
        tempP4.y = p4.y;
        D2D1_POINT_2F tempP5;
        tempP5.x = p5.x;
        tempP5.y = p5.y;

        m_pRenderTarget->DrawLine(tempP0, tempP1, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(tempP1, tempP2, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(tempP2, tempP3, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(tempP3, tempP4, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(tempP4, tempP5, m_pBrush, strokeWidth, strokeStyle);
        m_pRenderTarget->DrawLine(tempP5, tempP0, m_pBrush, strokeWidth, strokeStyle);
    }

}

