#ifndef __IJCSIMAGEPROPERTY_H__
/**
 * $File: IJcsImageProperty.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __IJCSIMAGEPROPERTY_H__

#include "JcsImage.h"
#include "JcsPropertyType.h"

EXTERN_C_BEGIN

namespace JcsLib
{

	/**
	@class IJcsImageProperty (Interface)
	@brief
	*/
	class IJcsImageProperty
		: public IJcsObject
	{
	protected:
		JcsImage* m_pParentImage = nullptr; // 
		JcsPropertyType m_propertyType = JcsPropertyType::NONE; // 

	public:
		DECLSPEC_ACTION virtual ~IJcsImageProperty()
		{
			Dispose();
		}

		/**
			Override dipose in JcsLib Object format.
		*/
		DECLSPEC_ACTION virtual void Dispose() override
		{
			IJcsObject::Dispose();

			SetParentImage(nullptr);
			SetPropertyType(JcsPropertyType::NONE);
		}

		/** setter **/
		/**  */
		DECLSPEC_ACTION void SetParentImage(JcsImage* object) { this->m_pParent = object; }
		/**  */
		DECLSPEC_ACTION void SetPropertyType(const JcsPropertyType type) { this->m_propertyType = type; }

		/** getter **/
		/**  */
		DECLSPEC_ACTION JcsImage* GetParentImage() const { return this->m_pParentImage; }
		/**  */
		DECLSPEC_ACTION JcsPropertyType GetPropertyType() const { return this->m_propertyType; }

	};
}

typedef JcsLib::IJcsImageProperty IJcsImageProperty;

EXTERN_C_END

#endif // __IJCSIMAGEPROPERTY_H__
