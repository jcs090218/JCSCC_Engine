/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

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
        virtual void update(float32 deltaTime) = 0;
    };

}

#endif // __D3D11_SCRIPT2D_H__

