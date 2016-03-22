#include "Camera2D.h"


namespace JCS_D2DEngine
{

	Camera2D::Camera2D()
		: GameObject2D(gDevice2D)
		, range(0)
	{

	}

	Camera2D::Camera2D(JCS_VECTOR2F _position)
		: GameObject2D(gDevice2D)
	{

	}

	Camera2D::~Camera2D()
	{
		GameObject2D::~GameObject2D();
	}

	/**
	 * 跟著目標...
	 */
    void Camera2D::Update(JCS_VECTOR2F _position, float32 gameTime)
	{

	}

	/**
	 * 檢查看看是否超出地圖範圍!
	 *
	 * D3DXVECTOR4->x:		地圖最左邊
	 * D3DXVECTOR4->y:		地圖最右邊
	 * D3DXVECTOR4->z:		地圖最上面
	 * D3DXVECTOR4->w:		地圖最下面
	 */
    void Camera2D::CoordModify(float32 mapLeft, float32 mapRight, float32 mapTop, float32 mapBot)
	{
		// 檢查左右
		if (mapLeft > position->x) position->x = mapRight;		// 地圖最左邊
		else if (mapRight < position->x) position->x = mapRight;		// 地圖最右邊

		// 檢查上下
		if (mapTop > position->y) position->y = mapTop;		// 地圖最上面
		else if (mapBot > position->y) position->y = mapBot;		// 地圖最下面

		// IMPORTANT: 未來還要減掉寬長的一半!!!!
	}

}

