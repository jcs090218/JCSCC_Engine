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

