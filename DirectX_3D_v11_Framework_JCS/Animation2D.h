#ifndef __D3D11_ANIMATION2D_H__
/**
* $File: Animation2D.h $
* $Date: $
* $Revision: $
* $Creator: Jen-Chieh Shen $
* $Notice: See LICENSE.txt for modification and distribution information
*                   Copyright (c) 2015 by Shen, Jen-Chieh $
*/
#define __D3D11_ANIMATION2D_H__

#include <GameTool_JCS\AnimationXML_Loader.h>

#include <DirectXTK\Inc\SpriteBatch.h>


namespace JCS_D3DX_v11_Engine
{
	class GraphicsD3D11;
	class Sprite2D;

	//====================================================================================---------------------------------------------------------------
	// Name : Animation2D
	//
	// Description : Diplay one animation sequence.
	//====================================================================================---------------------------------------------------------------
	class Animation2D
	{
	private:
		GraphicsD3D11& m_pDevice;

		JCS_VECTOR2F m_origin;
		uint32 m_delay;
		uint32 m_frame;

		uint32 m_frameCounter;
		uint32 m_delayCounter;

		// Sprites Data
		std::vector<Sprite2D*> m_animation;

		// XML Loader
		AnimationXML_Loader m_xmlLoader;

	public:
		explicit Animation2D(const wchar_t* basename, const wchar_t* filename, GraphicsD3D11& m_pDevice);
		~Animation2D();

		void DrawAnimation(DirectX::SpriteBatch& sprite_batch, bool loop = true);
		Sprite2D* GetFrame(const uint32 nFrame) const { return m_animation.at(nFrame); }

		/** setter **/
		void SetAnimationOrigin(const JCS_VECTOR2F origin) { this->m_origin = origin; }
		void SetDelay(const uint32 delay) { this->m_delay = delay; }
		void SetFrame(const uint32 frame) { this->m_frame = frame; }

		/** getter **/
		JCS_VECTOR2F GetAnimationOrigin() const { return this->m_origin; }
		uint32 GetDelay() const { return this->m_delay; }
		uint32 GetFrame() const { return this->m_frame; }

	private:
		void LoadAnimationXML(const wchar_t* animationName, const wchar_t* filename);
		void LoadAnimationSprite(const wchar_t* animationName);

		void DrawFrame(DirectX::SpriteBatch& sprite_batch, const uint32 nFrame);
	};

}

#endif // __D3D11_ANIMATION2D_H__

