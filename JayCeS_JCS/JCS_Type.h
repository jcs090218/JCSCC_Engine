/*******************************************************************
*                   JCSCC_Framework Version 0.2.7
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCS_TYPE_H__
/**
 * $File: JCS_Type.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __JCS_TYPE_H__


#include "JCS_Name.h"

namespace JayCeS
{

    /**
    @struct _JCS_FLOAT32
    @brief 
    */
    typedef struct _JCS_FLOAT32
    {
        union
        {
            float32 f;
            byte bytes[sizeof(float32)];
        } buffer;

        _JCS_FLOAT32(float32 data = 0.0f)
        {
            buffer.f = data;
        }

    } JCS_FLOAT32;

    /**
    @struct _JCS_FLOAT64
    @brief
    */
    typedef struct _JCS_FLOAT64
    {
        union
        {
            float64 f;
            byte bytes[sizeof(float64)];
        } buffer;

        _JCS_FLOAT64(float64 data = 0.0f)
        {
            buffer.f = data;
        }

    } JCS_FLOAT64;

}

typedef JayCeS::JCS_FLOAT32 JCS_FLOAT32;
typedef JayCeS::JCS_FLOAT64 JCS_FLOAT64;

#endif // __JCS_TYPE_H__

