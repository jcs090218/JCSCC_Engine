/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __CAPSULE3D_H__
#define __CAPSULE3D_H__

#include "Shape3D.h"

namespace JCS_D3DX_v9_Engine
{
    class Capsule3D
        : public Shape3D
    {
    public:
        Capsule3D();
        ~Capsule3D();
    };

}

#endif // __CAPSULE3D_H__

