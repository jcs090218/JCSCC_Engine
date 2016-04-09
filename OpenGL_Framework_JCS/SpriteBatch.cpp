/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "SpriteBatch.h"


namespace JCS_OpenGLEngine
{
    SpriteBatch::SpriteBatch()
    {

    }

    SpriteBatch::~SpriteBatch()
    {
        m_renderBatches.clear();
        m_glyphs.clear();
    }

    void SpriteBatch::initialize()
    {
        createVertexArray();
    }

    void SpriteBatch::begin(GlyphSortType sortType/* = GlyphSortType::TEXTURE*/)
    {
        m_sortType = sortType;
        m_renderBatches.clear();
        m_glyphs.clear();
    }

    void SpriteBatch::end()
    {
        // Set up all pointers for fast sorting
        m_glyphsPointer.resize(m_glyphs.size());
        for (uint32 i = 0; i < m_glyphs.size(); ++i)
            m_glyphsPointer.at(i) = &m_glyphs.at(i);

        sortGlyphs();
        createRenderBatches();
    }

    void SpriteBatch::draw(const glm::vec4& destRect,
        const glm::vec4& uvRect, GLuint texture, 
        float32 depth, const ColorRGBA8& color)
    {
        m_glyphs.emplace_back(destRect, uvRect, texture, depth, color);
    }

    void SpriteBatch::renderBatch()
    {
        glBindVertexArray(m_vao);

        for (uint32 i = 0; i < m_renderBatches.size(); i++) 
        {
            glBindTexture(GL_TEXTURE_2D, m_renderBatches[i].GetTexture());

            glDrawArrays(GL_TRIANGLES, m_renderBatches[i].GetOffset(), m_renderBatches[i].GetNumVertices());
        }

        glBindVertexArray(0);
    }

    void SpriteBatch::createRenderBatches()
    {
        std::vector<Vertex> vertices;
        vertices.resize(m_glyphs.size() * 6);

        if (m_glyphs.empty())
            return;
        int offset = 0;
        int cv = 0;		// current vertex
        m_renderBatches.emplace_back(offset, 6, m_glyphsPointer[0]->texture);		// 他最自己產生新的"RenderBatch"
        vertices[cv++] = m_glyphsPointer[0]->topLeft;
        vertices[cv++] = m_glyphsPointer[0]->bottomLeft;
        vertices[cv++] = m_glyphsPointer[0]->bottomRight;
        vertices[cv++] = m_glyphsPointer[0]->bottomRight;
        vertices[cv++] = m_glyphsPointer[0]->topRight;
        vertices[cv++] = m_glyphsPointer[0]->topLeft;
        offset += 6;

        for (uint32 cg = 1; cg < m_glyphs.size(); cg++) 
        {
            if (m_glyphsPointer[cg]->texture != m_glyphsPointer[cg - 1]->texture)
                m_renderBatches.emplace_back(offset, 6, m_glyphsPointer[0]->texture);		// 他最自己產生新的"RenderBatch"
            else 
                m_renderBatches.back().DeltaNumVetices(6);

            vertices[cv++] = m_glyphsPointer[cg]->topLeft;
            vertices[cv++] = m_glyphsPointer[cg]->bottomLeft;
            vertices[cv++] = m_glyphsPointer[cg]->bottomRight;
            vertices[cv++] = m_glyphsPointer[cg]->bottomRight;
            vertices[cv++] = m_glyphsPointer[cg]->topRight;
            vertices[cv++] = m_glyphsPointer[cg]->topLeft;
            offset += 6;
        }

        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        // orphan the buffer
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_DYNAMIC_DRAW);
        // upload the data
        glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void SpriteBatch::createVertexArray()
    {
        if (m_vao == 0) 
            glGenVertexArrays(1, &m_vao);

        glBindVertexArray(m_vao);

        if (m_vbo == 0) 
            glGenBuffers(1, &m_vbo);

        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

        //Tell opengl that we want to use the fiest
        //attribute array. We only need one array right
        //now since we are onlyusing position.
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        //This is the position atribute pointer
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        //This is the color attribute pointer
        glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
        //This is the UV attribute pointer
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

        glBindVertexArray(0);
    }

    void SpriteBatch::sortGlyphs()
    {
        switch (m_sortType)
        {
        case GlyphSortType::BACK_TO_FRONT:
        {
            std::stable_sort(m_glyphsPointer.begin(), m_glyphsPointer.end(), compareBackToFront);
        } break;
        case GlyphSortType::FRONT_TO_BACK:
        {
            std::stable_sort(m_glyphsPointer.begin(), m_glyphsPointer.end(), compareFrontToBack);
        } break;
        case GlyphSortType::TEXTURE:
        {
            std::stable_sort(m_glyphsPointer.begin(), m_glyphsPointer.end(), compareTexture);
        } break;
        }
    }

    bool SpriteBatch::compareFrontToBack(Glyph* a, Glyph* b)
    {
        return (a->depth < b->depth);
    }
    bool SpriteBatch::compareBackToFront(Glyph* a, Glyph* b)
    {
        return (a->depth > b->depth);
    }
    bool SpriteBatch::compareTexture(Glyph* a, Glyph* b)
    {
        return (a->texture < b->texture);
    }


}

