#ifndef __JCSOBJECTTYPE_H__
/**
 * $File: JcsObjectType.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCSOBJECTTYPE_H__


namespace JcsLib
{

	/**
	@enum JcsObjectType (Enum)
	@brief File format organize here.
	*/
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
