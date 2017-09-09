#ifndef __JCSPROPERTYTYPE_H__
/**
 * $File: JcsPropertyType.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCSPROPERTYTYPE_H__

#undef NULL

namespace JcsLib
{

	/**
	@enum JcsPropertyType (Enum)
	@brief Jcs extension Property type list here.
	*/
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
