/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "Camera2D.h"


namespace JCS_OpenGLEngine
{
    Camera2D::Camera2D()
        : m_position(0.0f, 0.0f)
        , m_cameraMatrix(1.0f)
        , m_orthoMatrix(1.0f)
        , m_scale(1.0f)
        , m_needsMatrixUpdate(true)
        , m_screenWidth(500)
        , m_screenHeight(500)
    {
    }


    Camera2D::~Camera2D()
    {
    }

    void Camera2D::init(int32 screenWidth, int32 screenHeight)
    {
        m_screenWidth = screenWidth;
        m_screenHeight = screenHeight;
        m_orthoMatrix = glm::ortho(0.0f, static_cast<float32>(m_screenWidth), 0.0f, static_cast<float32>(m_screenHeight));
    }

    void Camera2D::update()
    {
        if (m_needsMatrixUpdate)
        {
            // Camera Translation
            glm::vec3 translate(-m_position.x + m_screenWidth / 2, -m_position.y + m_screenHeight / 2, 0.0f);
            m_cameraMatrix = glm::translate(m_orthoMatrix, translate);

            // Camera Scale
            glm::vec3 scale(m_scale, m_scale, 0.0f);
            m_cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * m_cameraMatrix;
            m_needsMatrixUpdate = false;
        }
    }

}

