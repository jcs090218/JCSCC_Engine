#ifndef __D2D_SCRIPT2D_H__
#define __D2D_SCRIPT2D_H__


#include <GameInterface_JCS\JCS_Script.h>

namespace JCS_D2DEngine
{
    //------------------------------------------------------------------------------------
    // Script2D (Interface)
    // 
    // Desc : interface for this "JCS_D3DX_v9_Engine" Framework
    //
    // Func : initialize -> initialize the script
    //        update -> run the script per frame
    //------------------------------------------------------------------------------------
    struct Script2D
        : public JCS_Script
    {
        virtual ~Script2D() { }

        virtual void initialize() = 0;
        virtual void update(float32 gameTime) = 0;
    };

}

#endif // __D2D_SCRIPT2D_H__

