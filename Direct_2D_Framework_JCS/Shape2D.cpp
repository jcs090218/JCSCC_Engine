/**
 * $File: Shape2D.cpp $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */

#include "Shape2D.h"


namespace JCS_D2DEngine
{

    Shape2D::Shape2D(Graphics2D& gfx, bool autoPivot)
        : GameObject2D(gfx)
        , auto_pivot(autoPivot)
    {
        
    }

    Shape2D::~Shape2D()
    {
        
    }

}
