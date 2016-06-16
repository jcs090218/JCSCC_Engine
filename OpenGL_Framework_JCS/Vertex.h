/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __VERTEX_H__
#define __VERTEX_H__


#include "OpenGL_StdAfx.h"

namespace JCS_OpenGLEngine
{
    struct Position 
    {
        float32 x;
        float32 y;
    };

    struct ColorRGBA8
    {
        GLubyte r;
        GLubyte g;
        GLubyte b;
        GLubyte a;

        ColorRGBA8(GLubyte r = 255, GLubyte g = 255, GLubyte b = 255, GLubyte a = 255)
            : r(r), g(g), b(b), a(a)
        { }
    };

    struct UV
    {
        float32 u;
        float32 v;
    };

    //The vertex definition
    struct Vertex
    {
        //This is the position struct. When you store a struct or class
        //inside of another struct or class, it is called composition. This is
        //layed out exactly the same in memory as if we had a float position[2],
        //but doing it this way makes more sense.
        Position position;

        //4 bytes for r g b a color.
        ColorRGBA8 color;

        //UV texture coordinates.
        UV uv;

        void setPosition(float32 x, float32 y) 
        {
            position.x = x;
            position.y = y;
        }

        void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) 
        {
            color.r = r;
            color.g = g;
            color.b = b;
            color.a = a;
        }

        void setUV(float32 u, float32 v) 
        {
            uv.u = u;
            uv.v = v;
        }
    };

}

#endif // __VERTEX_H__

