/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __IDISPOSABLE_H__
#define __IDISPOSABLE_H__


namespace JcsLib
{

    //------------------------------------------------------------------------------------
    // Name : IDisposable (Interface) 
    //
    // Desc : Performs application - defined tasks associated with freeing, releasing, or
    //        resetting unmanaged resources.
    //------------------------------------------------------------------------------------
    struct IDisposable
    {
        virtual ~IDisposable() { }

        virtual void Dispose() = 0;
    };

}

typedef JcsLib::IDisposable IDisposable;

#endif // __IDISPOSABLE_H__

