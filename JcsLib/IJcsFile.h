/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __IJCSFILE_H__
#define __IJCSFILE_H__

#include "IJcsObject.h"
#include "IDisposable.h"

namespace JcsLib
{

    //------------------------------------------------------------------------------------
    // Name : IJcsFile (Interface)
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    struct IJcsFile
        : public IJcsObject
    {
        virtual ~IJcsFile() { }
    };
}

typedef JcsLib::IJcsFile IJcsFile;

#endif // __IJCSFILE_H__

