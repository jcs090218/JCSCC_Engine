/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __CAMERA2D__
#define __CAMERA2D__

#include "OpenGL_StdAfx.h"

#include "OpenGL\include\glm\glm.hpp"
#include "OpenGL\include\glm\gtc\matrix_transform.hpp"

namespace JCS_OpenGLEngine
{

    //====================================================================================-----------------------
    // Name : Camera2D
    // 
    // Description : 
    //====================================================================================-----------------------
    class Camera2D
    {
    public:
        Camera2D();
        virtual ~Camera2D();

        void init(int32 screenWidth, int32 screenHeight);
        void update();

        /** setter **/
        void setPosition(const glm::vec2& newPosition) { this->m_position = newPosition; this->m_needsMatrixUpdate = true; }
        void setScale(float32 newScale) { this->m_scale = newScale; this->m_needsMatrixUpdate = true; }

        /** getter **/
        glm::vec2 getPosition() { return this->m_position; }
        float32 getScale() { return this->m_scale; }
        glm::mat4 getCameraMatrix() { return this->m_cameraMatrix; }

    private:
        int32 m_screenWidth, m_screenHeight;
        bool m_needsMatrixUpdate;
        float32 m_scale;
        glm::vec2 m_position;
        glm::mat4 m_cameraMatrix;
        glm::mat4 m_orthoMatrix;
    };

}

#endif // __CAMERA2D__

