#ifndef __D2D_BOX_H__
/**
 * $File: Box.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __D2D_BOX_H__


#include "D2D_StdAfx.h"

namespace JCS_D2DEngine
{
    class Rectangle2D;

    //====================================================================================
    // Class Class Name : Box
    //
    // Description : 
    //====================================================================================
    class Box
    {
    private:
        Rectangle2D* m_rect;

        b2Body* m_body;
        b2Fixture* m_fixture;

    public:
        Box();
        ~Box();

        /**
            Initialize the shap itself.

            @param world to render to.
            @param position in the world.
            @param dimension in the world.
        */
        void Initialize(b2World& world, 
            const JCS_VECTOR2F& position, 
            const JCS_VECTOR2F& dimension);

        /** setter **/

        /** getter **/
        /**  */
        b2Body* getBody() const { return this->m_body; }
        /**  */
        b2Fixture* getFixture() const { return this->m_fixture; }

    };

}

#endif // __D2D_BOX_H__

