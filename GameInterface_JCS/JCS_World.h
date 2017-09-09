#ifndef __JCS_WORLD_H__
/**
 * $File: JCS_World.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_WORLD_H__


namespace JCS_GameInterface
{
    //====================================================================================
    // Name : JCS_World (Interface)
    //
    // Description : interface for all the world sub-classes.
    //====================================================================================
    class JCS_World
    {
    public:
        virtual ~JCS_World() { }
    };
}

typedef JCS_GameInterface::JCS_World JCS_World;

#endif // __JCS_WORLD_H__

