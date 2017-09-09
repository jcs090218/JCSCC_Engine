#ifndef __IJCSOBJECT_H__
/**
 * $File: IJcsObject.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __IJCSOBJECT_H__

#include "JcsLib_StdAfx.h"
#include "IDisposable.h"
#include "JcsObjectType.h"

EXTERN_C_BEGIN

namespace JcsLib
{

	/**
	@class IJcsObject (Interface)
	@brief Root of all data type.
	*/
	class IJcsObject
		: public IDisposable
	{
	protected:
		wchar_t* m_name;    // name of the object.
		JcsObjectType m_objectType = JcsObjectType::NONE;   // type of the object.
		IJcsObject* m_pParent = nullptr;    // parent of this node.

	public:
		DECLSPEC_ACTION virtual ~IJcsObject()
		{
			Dispose();
		}

		/**
			Override dipose in JcsLib Object format.
		*/
		DECLSPEC_ACTION virtual void Dispose() override
		{
			SetName(L"");
			SetObjectType(JcsObjectType::NONE);
			SafeDeleteObject(m_pParent);
		}

		/** setter **/
		/**  */
		DECLSPEC_ACTION void SetName(wchar_t* propName) { this->m_name = propName; }
		/**  */
		DECLSPEC_ACTION void SetObjectType(const JcsObjectType type) { this->m_objectType = type; }
		/**  */
		DECLSPEC_ACTION void SetParent(IJcsObject* object) { this->m_pParent = object; }

		/** getter **/
		/**  */
		DECLSPEC_ACTION wchar_t* GetName() const { return this->m_name; }
		/**  */
		DECLSPEC_ACTION JcsObjectType GetObjectType() const { return this->m_objectType; }
		/**  */
		DECLSPEC_ACTION IJcsObject* GetParent() const { return this->m_pParent; }

	};
}

typedef JcsLib::IJcsObject IJcsObject;

EXTERN_C_END

#endif // __IJCSOBJECT_H__
