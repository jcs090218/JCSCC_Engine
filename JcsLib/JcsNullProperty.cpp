/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*                Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#include "JcsNullProperty.h"


namespace JcsLib
{

    JcsNullProperty::JcsNullProperty(wchar_t* propName /*= nullptr*/)
    {
        SetName(propName);
        SetObjectType(JcsObjectType::PROPERTY);
    }

    JcsNullProperty::~JcsNullProperty()
    {
        Dispose();
    }

    void JcsNullProperty::Dispose()
    {
        m_name = nullptr;
    }

}

