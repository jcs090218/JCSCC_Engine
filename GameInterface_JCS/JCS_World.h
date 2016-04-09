/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_WORLD_H__
#define __JCS_WORLD_H__


namespace JCS_GameInterface
{
    //------------------------------------------------------------------------------------
    // Name : JCS_World (Interface)
    //
    // Desc : interface for all the world sub-classes.
    //------------------------------------------------------------------------------------
    class JCS_World
    {
    public:
        virtual ~JCS_World() { }
    };
}

typedef JCS_GameInterface::JCS_World JCS_World;

#endif // __JCS_WORLD_H__

