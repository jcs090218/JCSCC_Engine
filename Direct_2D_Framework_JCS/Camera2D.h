/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D2D_CAMERA2D_H__
#define __D2D_CAMERA2D_H__

#include "D2D_StdAfx.h"

#include "GameObject2D.h"

namespace JCS_D2DEngine
{

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Camera2D
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
	class Camera2D : 
        public GameObject2D
	{
	public:
        Camera2D();
        Camera2D(JCS_VECTOR2F _position);
        virtual ~Camera2D();

		void Update(JCS_VECTOR2F _position, float32 deltaTime);
        void CoordModify(float32 mapLeft, float32 mapRight, float32 mapTop, float32 mapBot);

		// setter
		void setRange(int32 newRange) { this->range = newRange; }
		void setTarget(void* target) { this->target = target; }		// 設定追蹤的目標

		// getter
		int getRange() { return this->range; }
		void* getTarget() { return this->target; }

	private:
		uint32 range;		// 跟蹤的範圍
		void* target;	// 追蹤的物件

	};
}

#endif	// __D2D_CAMERA2D_H__

