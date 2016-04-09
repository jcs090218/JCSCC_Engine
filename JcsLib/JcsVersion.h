/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCSVERSION_H__
#define __JCSVERSION_H__


namespace JcsLib
{
    enum class JcsVersion
    {
        JCS_v01 = 0, 
        JCS_v02 = 1
    };

}

typedef JcsLib::JcsVersion JcsVersion;

#endif // __JCSVERSION_H__

