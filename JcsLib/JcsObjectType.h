#ifndef __JCSOBJECTTYPE_H__
#define __JCSOBJECTTYPE_H__


namespace JcsLib
{

    //------------------------------------------------------------------------------------
    // Name : JcsObjectType (Enum)
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    enum class JcsObjectType
    {
        NONE,
        FILE,
        IMAGE,
        DIRECTORY,
        PROPERTY
    };
}

typedef JcsLib::JcsObjectType JcsObjectType;

#endif // __JCSOBJECTTYPE_H__

