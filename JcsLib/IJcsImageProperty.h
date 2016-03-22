#ifndef __IJCSIMAGEPROPERTY_H__
#define __IJCSIMAGEPROPERTY_H__

#include "JcsImage.h"
#include "JcsPropertyType.h"

namespace JcsLib
{

    //------------------------------------------------------------------------------------
    // Name : IJcsImageProperty (Interface)
    //
    // Desc : 
    //------------------------------------------------------------------------------------
    class IJcsImageProperty
        : public IJcsObject
    {
    protected:
        JcsImage* m_pParentImage = nullptr;
        JcsPropertyType m_propertyType = JcsPropertyType::NONE;

    public:
        virtual ~IJcsImageProperty() 
        { 
            Dispose();
        }

        virtual void Dispose() override
        {
            IJcsObject::Dispose();

            SetParentImage(nullptr);
            SetPropertyType(JcsPropertyType::NONE);
        }

        // setter 
        void SetParentImage(JcsImage* object) { this->m_pParent = object; }
        void SetPropertyType(const JcsPropertyType type) { this->m_propertyType = type; }

        // getter
        JcsImage* GetParentImage() const { return this->m_pParentImage; }
        JcsPropertyType GetPropertyType() const { return this->m_propertyType; }

    };
}

typedef JcsLib::IJcsImageProperty IJcsImageProperty;

#endif // __IJCSIMAGEPROPERTY_H__

