#ifndef __JCSVERSION_H__
/**
 * $File: JcsVersion.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCSVERSION_H__


namespace JcsLib
{

	/**
	@enum JcsVersion
	@brief Jcs extension version list here.
	*/
    enum class JcsVersion
    {
        JCS_v01 = 0, 
        JCS_v02 = 1
    };

}

typedef JcsLib::JcsVersion JcsVersion;

#endif // __JCSVERSION_H__
