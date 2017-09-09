#ifndef __D2D_SCRIPT2D_H__
/**
 * $File: Script2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __D2D_SCRIPT2D_H__


#include <GameInterface_JCS\JCS_Script.h>

namespace JCS_D2DEngine
{
    //====================================================================================
    // Script2D (Interface)
    // 
    // Description : interface for this "JCS_D3DX_v9_Engine" Framework
    //
    // Func : initialize -> initialize the script
    //        update -> run the script per frame
    //====================================================================================
    struct Script2D
        : public JCS_Script
    {
        virtual ~Script2D() { }

        virtual void initialize() = 0;
        virtual void update(float32 deltaTime) = 0;
    };

}

#endif // __D2D_SCRIPT2D_H__

