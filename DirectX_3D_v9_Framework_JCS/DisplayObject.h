/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __DISPLAYOBJECT_H__
#define __DISPLAYOBJECT_H__

#include "Sprite3D.h"
#include "Animation.h"

namespace JCS_D3DX_v9_Engine
{
	class DisplayObject
	{
	public:
		DisplayObject(float x, float y, int frame = 0, float z = 0, float rotation = 0, bool bLoop = false);
		~DisplayObject();

		virtual bool Initialize(LPDIRECT3DDEVICE9 device, std::wstring fileName, int type = 0,
			float width = 50, float height = 50, float alpha = 255);
		virtual void update(float deltaTime);
		virtual void Draw(float deltaTime);

		Animation *getAnimatObj() { return this->animation; }

		// setter
		void setPosition(float x, float y, float z = 0)
		{
			position.x = x; position.y = y; position.z = z;
		}
		void setPositionX(float x) { position.x = x; }
		void setPositionY(float y) { position.y = y; }
		void setPositionZ(float z) { position.z = z; }
		void setWidth(float _width) { thisWidth = _width; }
		void setHeight(float _height) { thisHeight = _height; }
		void setAlpha(float _alpha) { thisAlpha = _alpha; }
		void setFrame(int newTotalFrame) { totalFrame = newTotalFrame; }
		// getter
		float getPostiionX() { return position.x; }
		float getPositionY() { return position.y; }
		float getPositionZ() { return position.z; }
		float getWidth() { return thisWidth; }
		float getHeight() { return thisHeight; }
		float getAlpha() { return thisAlpha; }

		float x, y, z;

	protected:
		D3DXVECTOR3 position;
		D3DXVECTOR3 velocity;
		float thisRotation;
		float speed;
		float thisWidth;
		float thisHeight;
		float thisAlpha;

	private:
		Sprite3D *sprite;		// add texture to our gameObject
		Animation *animation;
		bool isLoop;		// for animation

		std::wstring currentDisplay;		// for SPRITE
		std::wstring currentAnim;			// for ANIMATION

		int totalFrame;

	};

}

#endif // __DISPLAYOBJECT_H__

