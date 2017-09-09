#ifndef __D2D_CAMERA2D_H__
/**
 * $File: Camera2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __D2D_CAMERA2D_H__

#include "D2D_StdAfx.h"

#include "GameObject2D.h"


namespace JCS_D2DEngine
{

    //====================================================================================
    // Class Name : Camera2D
    //
    // Description : Simulate the Camrea in the world.
    //====================================================================================
    class Camera2D : 
        public GameObject2D
    {
    public:
        Camera2D();
        Camera2D(JCS_VECTOR2F _position);
        virtual ~Camera2D();

        /**
            Logic Update.

            @param camera position
            @param time for implementing movement.
        */
        void Update(JCS_VECTOR2F _position, float32 deltaTime);

        /**
            Coordinate Modify within the camera movement, so the
            camera cannot move out of this coordinates.

            @param map left boundaries
            @param map right boundaries
            @param map top boundaries
            @param map bot boundaries
        */
        void CoordModify(float32 mapLeft, float32 mapRight, float32 mapTop, float32 mapBot);

        /** setter **/

        /** Set the follow range. */
        void setRange(int32 newRange) { this->range = newRange; }
        /** Set the target to follow. */
        void setTarget(void* target) { this->target = target; }        // 設定追蹤的目標

        /** getter **/
        /** Get the follow range. */
        int getRange() { return this->range; }
        /** Get the following target. */
        void* getTarget() { return this->target; }

    private:
        uint32 range;        // 跟蹤的範圍
        void* target;    // 追蹤的物件

    };
}

#endif    // __D2D_CAMERA2D_H__

