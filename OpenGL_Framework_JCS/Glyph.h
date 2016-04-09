/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __GLYPH_H__
#define __GLYPH_H__


#include "Vertex.h"

namespace JCS_OpenGLEngine
{
    class Glyph
    {
    public:
        GLuint texture;
        float32 depth;

        Vertex topLeft;
        Vertex bottomLeft;
        Vertex topRight;
        Vertex bottomRight;

    public:
        Glyph() { }
        Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, 
            GLuint texture, float32 depth, const ColorRGBA8& color)
            : texture(texture)
            , depth(depth)
        {
            topLeft.color = color;
            topLeft.setPosition(destRect.x, destRect.y + destRect.w);
            topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);

            bottomLeft.color = color;
            bottomLeft.setPosition(destRect.x, destRect.y);
            bottomLeft.setUV(uvRect.x, uvRect.y);

            bottomRight.color = color;
            bottomRight.setPosition(destRect.x + destRect.z, destRect.y);
            bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);

            topRight.color = color;
            topRight.setPosition(destRect.x + destRect.z, destRect.y + destRect.w);
            topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);
        }
    };

}

#endif // __GLYPH_H__

