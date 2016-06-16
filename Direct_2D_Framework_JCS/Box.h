/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __D2D_BOX_H__
#define __D2D_BOX_H__


#include "D2D_StdAfx.h"

namespace JCS_D2DEngine
{
    class Rectangle2D;

    //---------------------------------------------------------------------------------------------------------------------------------------------------
    // Name : Box
    //
    // Desc : 
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    class Box
    {
    private:
        Rectangle2D* m_rect;

        b2Body* m_body;
        b2Fixture* m_fixture;

    public:
        Box();
        ~Box();

        void initialize(b2World& world, 
            const JCS_VECTOR2F& position, 
            const JCS_VECTOR2F& dimension);

        // setter

        // getter
        b2Body* getBody() const { return this->m_body; }
        b2Fixture* getFixture() const { return this->m_fixture; }

    };

}

#endif // __D2D_BOX_H__

