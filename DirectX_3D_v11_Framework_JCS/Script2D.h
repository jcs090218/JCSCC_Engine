#ifndef __D3D11_SCRIPT2D_H__
#define __D3D11_SCRIPT2D_H__

#include <GameInterface_JCS\JCS_Script.h>

namespace JCS_D3DX_v11_Engine
{
    //------------------------------------------------------------------------------------
    // Name : Script2D (Interface)
    // 
    // Desc : interface for this "JCS_D3DX_v11_Engine" Framework
    //
    // Func : initialize -> initialize the script
    //        update -> run the script per frame
    //------------------------------------------------------------------------------------
    class Script2D
        : public JCS_Script
    {
    public:
        virtual ~Script2D() { }

        virtual void initialize() = 0;
        virtual void update(float32 gameTime) = 0;
    };

}

#endif // __D3D11_SCRIPT2D_H__

