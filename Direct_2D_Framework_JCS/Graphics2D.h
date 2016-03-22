#ifndef __GRAPHICS_2D_H__
#define __GRAPHICS_2D_H__

#include "D2D_StdAfx.h"

#include <GameInterface_JCS\RenderDevice.h>

namespace JCS_D2DEngine
{
	class Graphics2D
        : public JCS_GameInterface::RenderDevice
	{
	private:
		ID2D1Factory* m_pDirect2dFactory;
		ID2D1HwndRenderTarget* m_pRenderTarget;
		ID2D1SolidColorBrush* m_pBrush;

	public:
		Graphics2D();
		virtual ~Graphics2D();

        bool Initialize(HWND hWnd);

        virtual void BeginRender() const override { m_pRenderTarget->BeginDraw(); }
        virtual void EndRender() const override { m_pRenderTarget->EndDraw(); }

		void SetTransform(const D2D1_MATRIX_3X2_F& transform);
		void ClearScreen(float r, float g, float b, float a);

		// 圓形
		void drawCircle(float x = 0.0f, float y = 0.0f, 
			float radius = 50.0f, 
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		// 橢圓形
		void drawElipse(float x = 0.0f, float y = 0.0f, 
			float radiusA = 50.0f, float radiiusB = 100.0f, 
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		// 矩形
		void drawRectangle(float x, float y, float width, float height,
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		// 用線畫矩形
		void drawRectangleWithLine(
			JCS_VECTOR2F* p1, JCS_VECTOR2F* p2, 
			JCS_VECTOR2F* p3, JCS_VECTOR2F* p4,
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		void drawRectangleWithLine(
			JCS_VECTOR2F& p1, JCS_VECTOR2F& p2,
			JCS_VECTOR2F& p3, JCS_VECTOR2F& p4,
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		// 正方形
		void drawSquare(float x, float y, float length,
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle *strokeStyle = nullptr);
		// 三角形
		void drawTriangle(D2D1_POINT_2F p0, D2D1_POINT_2F p1, D2D1_POINT_2F p2, 
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		void drawTriangle(JCS_GameInterface::JCS_VECTOR2F& p0, JCS_GameInterface::JCS_VECTOR2F& p1, JCS_GameInterface::JCS_VECTOR2F& p2,
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		// 線
		void drawLine(D2D1_POINT_2F p0, D2D1_POINT_2F p1, 
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		void drawLine(JCS_GameInterface::JCS_VECTOR2F p0, JCS_GameInterface::JCS_VECTOR2F p1,
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		// 圓角矩形
		void drawRoundedRectangle(float x, float y, float width, float height,
			float radiusX, float radiusY,
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);
		// Hexagon
		void drawHexagon(
			JCS_VECTOR2F& p0, JCS_VECTOR2F& p1,
			JCS_VECTOR2F& p2, JCS_VECTOR2F& p3,
			JCS_VECTOR2F& p4, JCS_VECTOR2F& p5,
			float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f,
			float strokeWidth = 1.0f, ID2D1StrokeStyle* strokeStyle = nullptr);

		// setter
		void SetBrushColor(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);

		// getter
		ID2D1Factory* getFactory() { return this->m_pDirect2dFactory; }
		ID2D1HwndRenderTarget* getRenderTarget() { return this->m_pRenderTarget; }
		ID2D1SolidColorBrush* getBrush() { return this->m_pBrush; }
	};

}

#endif // __GRAPHICS_2D_H__

