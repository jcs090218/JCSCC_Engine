#include "Animation.h"

namespace JCS_D3DX_v9_Engine
{

	Animation::Animation(int frame)
		:totalFrame(frame)
	{
	}


	Animation::~Animation()
	{

	}

	bool Animation::Initialize(LPDIRECT3DDEVICE9 device, std::wstring fileName, float width, float height, float alpha)
	{
		color = D3DCOLOR_ARGB((int)alpha, 255, 255, 255);

		// Textrue the Object below
		if (!SUCCEEDED(D3DXCreateTextureFromFileEx(device, fileName.c_str(), D3DX_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, D3DFMT_A8R8G8B8,
			D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &d3dtex)))
		{
			std::wstring s = L"There was an issue creating the texture. Make sure the requested image is available. Requested image: " + fileName;
			MessageBox(NULL, s.c_str(), NULL, NULL);
			return false;
		}

		// Create Object of the Sprite (( Object
		if (!SUCCEEDED(D3DXCreateSprite(device, &d3dspt)))
		{
			MessageBox(NULL, L"There was an issue creating the sprite", NULL, NULL);
			return false;
		}

		return true;
	}

	/**
	 *	gameTime: time in real life
	 *	position:	origin for each frame??
	 *	frame:	total frame we want to display
	 *	alpha:	alpha of the animation
	 */
	void Animation::PlayAnimationWithSpriteSheet(float gameTime,
		D3DXVECTOR3 position, int totalFrame, bool bLoop, float alpha)
	{
		if (totalFrame > 0)		// in some case we want 1 frame animation
		{
			if (nFrame < totalFrame) nFrame++;
			else if (bLoop) nFrame = 0;
			//else frame = 0;

			int xpos = nFrame * 182 + 1;

			RECT part;
			SetRect(&part, xpos, 0, xpos + 181, 128);

			D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 position(50.0f, 50.0f, 0.0f);

			// set color
			color = D3DCOLOR_ARGB((int)alpha, 255, 255, 255);

			// Start Playing
			if (d3dspt && d3dtex)
			{
				d3dspt->Begin(D3DXSPRITE_ALPHABLEND);	// Begin Render Sprite
				d3dspt->Draw(d3dtex, &part, &center, &position, color);
				//d3dspt->Draw(d3dtex, NULL, NULL, &position, color);
				d3dspt->End();		// End Render Sprite
			}
		}
	}// end PlayAnimation()

}

