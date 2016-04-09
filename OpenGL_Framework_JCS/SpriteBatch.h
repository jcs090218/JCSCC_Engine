/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __SPRITEBATCH_H__
#define __SPRITEBATCH_H__


#include "OpenGL_StdAfx.h"

#include "GlyphSortType.h"
#include "Vertex.h"
#include "Glyph.h"
#include "RenderBatch.h"

namespace JCS_OpenGLEngine
{

    //-----------------------------------------------------------------------------------------------------------
    // Name : SpriteBatch
    // 
    // Desc : 
    //-----------------------------------------------------------------------------------------------------------
    class SpriteBatch
    {
    private:
        GLuint m_vbo;
        GLuint m_vao;

        GlyphSortType m_sortType;

        std::vector<Glyph*> m_glyphsPointer;
        std::vector<Glyph> m_glyphs;
        std::vector<RenderBatch> m_renderBatches;

    public:
        SpriteBatch();
        ~SpriteBatch();

        void initialize();

        void begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
        void end();

        void draw(const glm::vec4& destRect,
            const glm::vec4& uvRect,
            GLuint texture,
            float32 depth,
            const ColorRGBA8& color);

        void renderBatch();
        
    private:
        void createRenderBatches();
        void createVertexArray();
        void sortGlyphs();

        static bool compareFrontToBack(Glyph* a, Glyph* b);
        static bool compareBackToFront(Glyph* a, Glyph* b);
        static bool compareTexture(Glyph* a, Glyph* b);

    };

}

#endif // __SPRITEBATCH_H__

