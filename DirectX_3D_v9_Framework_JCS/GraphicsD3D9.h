#ifndef __GRAPHICSD3D9_H__
#define __GRAPHICSD3D9_H__

#include "D3DX_v9_StdAfx.h"

#include <GameInterface_JCS\RenderDevice.h>

namespace JCS_D3DX_v9_Engine
{
    class GraphicsD3D9
        : public JCS_GameInterface::RenderDevice
	{
    private:
        LPDIRECT3D9 m_direct3d;
        LPDIRECT3DDEVICE9 m_d3ddev;

	public:
        GraphicsD3D9();
        virtual ~GraphicsD3D9();

		// Direct3D functions
        bool Initialize(HWND hWnd, bool windowed);

		virtual void BeginRender() const override;		// not using this in Direct 11
		virtual void EndRender() const override;		// not using this in Direct 11

        void Clear(D3DXCOLOR& color);		// this will help us clear the frame
        void ClearDepth();
		void RenderPresent();

        // setter

        // getter
        LPDIRECT3DDEVICE9 GetDevice() const { return this->m_d3ddev; }
	};

}

#endif // __GRAPHICSD3D9_H__

