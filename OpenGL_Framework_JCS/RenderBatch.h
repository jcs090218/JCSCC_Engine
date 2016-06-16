/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __RENDERBATCH_H__
#define __RENDERBATCH_H__


#include "OpenGL_StdAfx.h"

namespace JCS_OpenGLEngine
{

    //-----------------------------------------------------------------------------------------------------------
    // Name : RenderBatch
    // 
    // Desc : 
    //-----------------------------------------------------------------------------------------------------------
    class RenderBatch
    {
    private:
        GLuint m_offset;
        GLuint m_numVertices;
        GLuint m_texture;

    public:
        RenderBatch(GLuint offset, GLuint numVertices, GLuint texture)
            : m_offset(offset)
            , m_numVertices(numVertices)
            , m_texture(texture)
        { }

        void DeltaNumVetices(const int32 delta) { this->m_numVertices += delta; }

        // setter
        void SetOffset(const GLuint offset) { this->m_offset = offset; }
        void SetNumVertices(const GLuint numVertices) { this->m_numVertices = numVertices; }
        void SetTexture(const GLuint texture) { this->m_texture = texture; }

        // getter
        GLuint GetOffset() const { return this->m_offset; }
        GLuint GetNumVertices() const { return this->m_numVertices; }
        GLuint GetTexture() const { return this->m_texture; }
    };
}

#endif // __RENDERBATCH_H__

