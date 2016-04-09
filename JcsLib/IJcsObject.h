/*******************************************************************
*                   JCSCC_Framework Version 1.0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*   See LICENSE.txt for modification and distribution information
*		        Copyright (c) 2016 by Shen, Jen-Chieh
******************************************************************/

#ifndef __IJCSOBJECT_H__
#define __IJCSOBJECT_H__

#include "JcsLib_StdAfx.h"
#include "IDisposable.h"
#include "JcsObjectType.h"

namespace JcsLib
{

    //------------------------------------------------------------------------------------
    // Name : IJcsObject (Interface)
    //
    // Desc : Root of all data type.
    //------------------------------------------------------------------------------------
    class IJcsObject
        : public IDisposable
    {
    protected:
        wchar_t* m_name;
        JcsObjectType m_objectType = JcsObjectType::NONE;
        IJcsObject* m_pParent = nullptr;

    public:
        virtual ~IJcsObject() 
        { 
            Dispose();
        }

        virtual void Dispose() override
        {
            SetName(L"");
            SetObjectType(JcsObjectType::NONE);
            SafeDeleteObject(m_pParent);
        }

        // setter 
        void SetName(wchar_t* propName) { this->m_name = propName; }
        void SetObjectType(const JcsObjectType type) { this->m_objectType = type; }
        void SetParent(IJcsObject* object) { this->m_pParent = object; }

        // getter 
        wchar_t* GetName() const { return this->m_name; }
        JcsObjectType GetObjectType() const { return this->m_objectType; }
        IJcsObject* GetParent() const { return this->m_pParent; }

    };
}

typedef JcsLib::IJcsObject IJcsObject;

#endif // __IJCSOBJECT_H__

