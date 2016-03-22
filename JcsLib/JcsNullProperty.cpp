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

