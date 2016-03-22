#ifndef __OBJECTPOOL2D_H__
#define __OBJECTPOOL2D_H__


#include "GameObject2D.h"

namespace JCS_D2DEngine
{
	template <class T>
	class ObjectPool2D 
        : public GameObject2D
	{
	protected:
		std::vector<T*> objects;		// array storing objects
		std::vector<bool> availableObject;

	public:
		ObjectPool2D(uint8 num);
		virtual ~ObjectPool2D();

		virtual void initialize() override;
		virtual void update(const float32 gameTime) override;
		virtual void draw() override;

		T* execute();		// give out object for use!
		void back_to_pool(T* obj);		// send object back to pool

		// setter

		// getter
		uint8 GetLength() const { return this->objects.size(); }
		std::vector<T*>* getObjects() const { return this->objects; }
		T* getObjectsWithIndex(uint8 i) const { return this->objects.at(i); }
		std::vector<bool>* getAvailableObject() const { return this->availableObject; }
		bool getAvailableObjectWidthIndex(uint8 i) const { return this->availableObject.at(i); }

	};

	template <class T>
	ObjectPool2D<T>::ObjectPool2D(uint8 num)
	{
		for (int32 i = 0; i < num; ++i)
		{
			availableObject.push_back(false);
			objects.push_back(new T);
		}
	}

	template <class T>
	ObjectPool2D<T>::~ObjectPool2D()
	{
		for (int32 i = 0; i < GetLength(); ++i)
		{
			SafeDeleteObject(objects.at(i));
		}
		objects.clear();
		availableObject.clear();
	}

	template <class T>
	void ObjectPool2D<T>::initialize()
	{
		for (int32 i = 0; i < GetLength(); ++i)
		{
			objects.at(i)->initialize();
		}
	}

	template <class T>
	void ObjectPool2D<T>::update(const float32 gameTime)
	{
		//for (int i = 0; i < GetLength(); ++i) 
		//{
		//	if (objects.at(i) != nullptr) 
		//	{
		//		if (availableObject.at(i)) 
		//			objects.at(i)->update();

		//		// Condition going back to pool
		//		if (!objects.at(i)->getIsVisible())
		//			back_to_pool(objects.at(i));
		//	}
		//}
	}

	template <class T>
	void ObjectPool2D<T>::draw()
	{
		/*for (int i = 0; i < GetLength; ++i) 
		{
			if (objects.at(i) != nullptr && availableObject.at(i)) 
				objects.at(i)->draw();
		}*/
	}

	/**
	* In the case, do linear sort are better choice!
	*/
	template <class T>
	T* ObjectPool2D<T>::execute()
	{
		for (int i = 0; i < GetLength(); ++i) 
		{
			if (!availableObject.at(i) && 
				objects.at(i) != nullptr) 
			{
				availableObject.at(i) = true;
				return objects.at(i);
			}
		}

		return nullptr;
	}

	/**
	* send object back to pool
	*/
	template <class T>
	void ObjectPool2D<T>::back_to_pool(T* obj)
	{
		for (int i = 0; i < GetLength(); ++i)
		{
			if (objects.at(i) == obj) 
			{
				// turn it to deactive for next use
				availableObject.at(i) = false;
				break;
			}
		}
	}
}// end namespace "JCS_D2DEngine"

#endif // __OBJECTPOOL2D_H__

