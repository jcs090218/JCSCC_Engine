/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __JCSNULLPROPERTY_H__
#define __JCSNULLPROPERTY_H__


#include "IJcsImageProperty.h"
#include "JcsObjectType.h"

namespace JcsLib
{

    //------------------------------------------------------------------------------------
    // Name : JcsNullProperty 
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class JcsNullProperty
        : public IJcsImageProperty
    {
    public:
        JcsNullProperty(wchar_t* propName = nullptr);
        virtual ~JcsNullProperty();

        virtual void Dispose() override;
    };

}

#endif // __JCSNULLPROPERTY_H__

