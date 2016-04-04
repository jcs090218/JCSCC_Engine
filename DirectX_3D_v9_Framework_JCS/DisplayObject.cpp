#include "DisplayObject.h"

namespace JCS_D3DX_v9_Engine
{

	/**
	 *	frame: set to 0 if aren't animation
	 *	x: position on X coordinate
	 *	y: position on Y coordinate
	 *	z: position on Z coordiante
	 *	rotation:
	 */
	DisplayObject::DisplayObject(float x, float y, int frame, float z, float rotation, bool bLoop)
		: thisWidth(0),
		thisHeight(0),
		thisAlpha(0),
		position(x, y, z),
		thisRotation(rotation),
		totalFrame(frame),
		isLoop(bLoop)
	{
		// Constructor
	}


	DisplayObject::~DisplayObject()
	{
		SafeDeleteObject(sprite);
		SafeDeleteObject(animation);
	}

	/**
	 *	Here we create sprite or animation
	 *  device: device we need to create our sprite
	 *	fileName: name of the fill we want to texture on this Display Object
	 *	type: 0 for sprite, 1 for animation (default: 0)
	 */
	bool DisplayObject::Initialize(LPDIRECT3DDEVICE9 device, std::wstring fileName, int type, float width, float height, float alpha)
	{
		thisWidth = width;
		thisHeight = height;
		thisAlpha = alpha;		// default 255 for alpha

		if (fileName != L""){
			if (type == 0 && !sprite){
				sprite = new Sprite3D();
				if (!sprite->Initialize(device, fileName, width, height, alpha))
				{
					return false;
				}
			}
			else if (type == 1 && !animation){
				animation = new Animation();
				if (!animation->Initialize(device, fileName, width, height, alpha))
				{
					return false;
				}
			}
		}

		return true;
	}

	void DisplayObject::update(float deltaTime)
	{

	}

	void DisplayObject::Draw(float deltaTime)
	{
		if (sprite) sprite->Draw(deltaTime, position);
		if (animation) animation->PlayAnimationWithSpriteSheet(deltaTime, position, totalFrame, isLoop);
	}

}

