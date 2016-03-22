#ifndef __JCS_MOVABLEOBJECT2D_H__
#define __JCS_MOVABLEOBJECT2D_H__


#include "GameInterface_StdAfx.h"

#include "JCS_GameObject2D.h"

namespace JCS_GameInterface
{
    class JCS_MovableObject2D
    {
    protected:
        JCS_VECTOR2F* velocity;		// 速率

    public:
        virtual ~JCS_MovableObject2D() { SafeDeleteObject(velocity); }

        // setter

        // getter

    };

}

typedef JCS_GameInterface::JCS_MovableObject2D JCS_MovableObject2D;

#endif // __JCS_MOVABLEOBJECT2D_H__

