/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "GameObject3D.h"


namespace JCS_D3DX_v9_Engine
{
	GameObject3D::GameObject3D(float32 x, float32 y, float32 z, float32 rotation)
	{
		float32 twopi = (float32)(M_PI * 2);
		position.x = x;
		position.y = y;
		position.z = z;

		if (rotation > twopi) rotation = twopi;
		if (rotation < 0) rotation = 0;

		this->rotation = rotation;
		//this->speed = speed;

		//velocity.x = cos(rotation) * speed;
		//velocity.y = sin(rotation) * speed;
		//velocity.z = 0;		// not rotating in z direction

		this->maxSpeed = maxSpeed;
	}


	GameObject3D::~GameObject3D()
	{
		SafeDeleteObject(sprite);
		SafeDeleteObject(animation);
	}

	bool GameObject3D::Initialize(LPDIRECT3DDEVICE9 device, std::wstring fileName, 
		float32 width, float32 height, float32 alpha)
	{
		status = ObjectStatus::ALIVE;

		if (!sprite)
		{
			sprite = new Sprite3D();
			if (!sprite->Initialize(device, fileName, width, height, alpha))
			{
				return false;
			}
		}

		return true;
	}

	void GameObject3D::Update(float32 deltaTime)
	{
		if (status == ObjectStatus::ALIVE)
		{
			if (position.x != pivotPosX()) position.x = pivotPosX();
			if (position.y != pivotPosY()) position.y = pivotPosY();
		}

		// Effects
		OnAlphaChange(deltaTime);
		OnShake(deltaTime);
		OnScaleChange(deltaTime);
		OnScaleBounce(deltaTime);
		OnMoveTo(deltaTime);
	}

	void GameObject3D::Draw(float32 deltaTime)
	{
		if (sprite) sprite->Draw(deltaTime, position);
	}

	ObjectStatus GameObject3D::GetStatus() const
	{
		return status;
	}

	/**
	 * Effect
	 * this GameObject3D from transparent to full alpha (appear)
	 * or from full alpha to transparent (disappear),
	 * type 0: disappear,
	 * type 1: appear,
	 */
	void GameObject3D::AlphaChange(int32 time, int32 type)
	{
		if (isAlphaChange)
		{
			OutputDebugString(L"trying to call a alpha change effect while there is already one!!\n");
		}
		else{
			if (type == 0){			// fade out
				fadeTime = time;
				//reset alpha to current and right alpha
				fadeTimer = 0;
				getSprite()->a = 255;
				fadeType = type;
				isAlphaChange = true;
			}
			// fade in
			else if (type == 1){
				fadeTime = time;
				//reset alpha to current and right alpha
				fadeTimer = 0;
				getSprite()->a = 0;
				fadeType = type;
				isAlphaChange = true;
			}
			else {
				JCS_Print(L"GameObject3D.class: Invalid Aplpha Change Index...");
			}
		}
	}
	/**
	 * function actually doing alphaChange
	 */
	void GameObject3D::OnAlphaChange(float32 deltaTime)
	{
		if (isAlphaChange)
		{
			// do fade change
			if (fadeTimer < fadeTime){
				if (fadeType == 0) getSprite()->a -= 255 / fadeTime * deltaTime;
				else if (fadeType == 1) getSprite()->a += 255 / fadeTime * deltaTime;
			}
			else {		// else we do this in normal
				// check alpha
				if (fadeType == 0) getSprite()->a = 0;
				else if (fadeType == 1) getSprite()->a = 255;

				fadeTimer = 0;
				isAlphaChange = false;
			}
			fadeTimer += deltaTime;
		}// end if(isAlpha)
	}

	/**
	 * Effect
	 * this function use to set shake attribute and start a shake effect
	 * last: how much time will this shake
	 * margin: how int32ense the shake willbe
	 */
	void GameObject3D::Shake(int32 time, float32 margin)
	{
		if (isShake){
			OutputDebugString(L"trying to call a shake effect while there is already one!!\n");
		}
		else{
			isShake = true;
			shakeTime = time;
			shakeMargin = margin;
			// start shaking
			shakeOrigin.x = position.x;
			shakeOrigin.y = position.y;
		}
	}
	/**
	 * this will do actualy shake according to the shake attribute
	 */
	void GameObject3D::OnShake(float32 deltaTime)
	{
		if (isShake){
			// while we move and shake we recore our position every frame
			shakeOrigin.x = this->x;
			shakeOrigin.y = this->y;

			shakeTimer += deltaTime;
			// still on shake
			if (shakeTimer < shakeTime){
				// shake randomly
				position.x += (rand() % 3 - 1) * shakeMargin * (shakeTime / shakeTimer) / 5;		// shakeTime / shakeTimer = shakeRate
				position.y += (rand() % 3 - 1) * shakeMargin * (shakeTime / shakeTimer) / 5;
			}
			else{	// finish the shake
				// back to original position
				this->x = shakeOrigin.x;
				this->y = shakeOrigin.y;

				shakeTimer = 0;
				isShake = false;
			}
		}
	}

	/**
	 * Effect
	 * smoothly scale to target scale in given time peroid
	 */
	void GameObject3D::ScaleChange(int32 time, float32 finalChangeWidth, float32 finalChangeHeight)
	{
		if (isScale){
			OutputDebugString(L"trying to call a scalechange effect while there is already one!!\n");
		}
		else{
			if (scaleFinalChangeWidth != finalChangeWidth ||
				scaleFinalChangeHeight != finalChangeHeight)
			{
				isScale = true;
				scaleTime = time;
				scaleFinalChangeWidth = finalChangeWidth;
				scaleFinalChangeHeight = finalChangeHeight;
				scaleOrigin.x = this->x;
				scaleOrigin.y = this->y;
			}
		}
	}
	void GameObject3D::OnScaleChange(float32 deltaTime)
	{
		if (isScale){
			scaleTimer += deltaTime;
			scaleOrigin.x = this->x;
			scaleOrigin.y = this->y;

			if (scaleTimer < scaleTime){
				// change height and with to final change
				getSprite()->scaleTextureIncreasingPixels(
					(scaleFinalChangeWidth - getWidth()) / scaleTime * deltaTime,
					(scaleFinalChangeHeight - getHeight()) / scaleTime * deltaTime
					);

				//if is not shaking stay in center
				if (!isShake){
					//this->x = scaleOrigin.x - (getScaleX() - 1) * (getWidth() / getScaleX()) / 2;
					//this->y = scaleOrigin.y - (getScaleY() - 1) * (getWidth() / getScaleY()) / 2;
					// 設置中心點
					getSprite()->setWidthHeightPivotToCenter(
						((scaleFinalChangeWidth - getScaleX()) / scaleTime * deltaTime) + getWidth(),
						((scaleFinalChangeHeight - getScaleY()) / scaleTime * deltaTime) + getHeight()
						);
				}
			}
			else{
				scaleTimer = 0;
				isScale = false;
			}
		}
	}

	/**
	 * Effect
	 * Scale Bounce,
	 * time: effect time length,
	 * margin: how big the bounce is,
	 * cycle: how many time will bounce
	 */
	void GameObject3D::ScaleBounce(int32 time, float32 margin, int32 cycle)
	{
		if (isBounce){
			OutputDebugString(L"trying to call a bounce effect while there is already one!!\n");
		}
		else{
			bounceTime = time;
			bounceMargin = margin;
			bounceCycle = cycle;
			isBounce = true;
			//record oringin scale
			bounceScaleOrigin = getScaleX();
		}
	}
	void GameObject3D::OnScaleBounce(float32 deltaTime)
	{
		if (isBounce) {
			bounceTimer += deltaTime;
			bounceOrigin.x = this->x;
			bounceOrigin.y = this->y;

			// do bounce effect
			if (bounceTimer <= bounceTime){
				// scale formula
				float32 scale = sin(
					2.0f * PI *									//2 PI, one cycle
					bounceCycle *								//how many cycle
					bounceTimer / bounceTime) * 				//speed
					bounceMargin / 100.0f *						//set margin
					(-0.5f * bounceTimer + bounceTime * 0.5f)	//line boucing decline
					+ 1.0f;

				//if is not shaking stay in center
				if (!isShake){
					this->x = bounceOrigin.x - (scale - 1) * (getWidth() / getScaleX()) / 2;
					this->y = bounceOrigin.y - (scale - 1) * (getWidth() / getScaleY()) / 2;
				}
				getSprite()->scaleTextureWithRatio(scale, scale);
			}
			else{
				// reset scale
				getSprite()->scaleTextureWithRatio(bounceScaleOrigin, bounceScaleOrigin);

				// test position
				this->x = 0;
				this->y = 0;

				bounceTimer = 0;
				isBounce = false;
			}
		}
	}

	/**
	 * displament to shift point32 in last time
	 */
	void GameObject3D::MoveTo(int32 time, D3DXVECTOR3 position)
	{
		if (isMoveTo){
			OutputDebugString(L"already in move to function!!\n");
		}
		else{
			if (this->x != position.x || this->y != position.y) {
				isMoveTo = true;
				moveToTime = time;		// * 60 frame rate ?!
				movePosition.x = position.x;
				movePosition.y = position.y;
				movePosition.z = position.z;
			}
		}
	}
	void GameObject3D::OnMoveTo(float32 deltaTime)
	{
		if (isMoveTo){
			moveToTimer += deltaTime;

			if (moveToTimer < moveToTime)
			{
				int32 calX = (int32)(movePosition.x - this->x);
				if (calX > 1.0f || calX < -1.0f)
					this->x += ((calX / moveToTime) * deltaTime);
				else
					this->x = movePosition.x;

				int32 calY = (int32)(movePosition.y - this->y);
				if (calY > 1.0f || calY < -1.0f)
					this->y += ((calY / moveToTime) * deltaTime);
				else
					this->y = movePosition.y;
			}
			// end
			else{
				moveToTimer = 0;
				isMoveTo = false;
			}
		}
	}

}

