#ifndef __JCSPROPERTYTYPE_H__
#define __JCSPROPERTYTYPE_H__

#undef NULL

namespace JcsLib
{

    //------------------------------------------------------------------------------------
    // Name : JcsPropertyType (Enum)
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    enum class JcsPropertyType
    {
        NONE,
        NULL,
        UNSIGNED_SHORT,
        COMPRESSED_INT,
        BYTE_FLOAT,
        DOUBLE,
        STRING,
        EXTENDED,
        SUB_PROPERTY,
        CANVAS,
        VECTOR,
        CONVEX,
        SOUND,
        UOL,
        PNG
    };
}

typedef JcsLib::JcsPropertyType JcsPropertyType;

#endif // __JCSPROPERTYTYPE_H__

