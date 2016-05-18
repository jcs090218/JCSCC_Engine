/*******************************************************************
 *                   JCSCC_Framework Version 1.0
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   See LICENSE.txt for modification and distribution information
 *              Copyright (c) 2016 by Shen, Jen-Chieh
 ******************************************************************/


#include "Collision2D.h"

namespace JCS_D3DX_v11_Engine
{
    
    class Rectangle2D
        : public Collision2D
    {
    public:
        Rectangle2D();
        ~Rectangle2D();
        
        virtual void Update() override;
        virtual void Draw() override;
    };
}
