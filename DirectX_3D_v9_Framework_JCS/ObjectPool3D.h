#ifndef __OBJECTPOOL3D_H__
#define __OBJECTPOOL3D_H__

#include "GameObject3D.h"

namespace JCS_D3DX_v9_Engine
{
	template <class T>
	class ObjectPool3D : public GameObject3D
	{
	protected:
		std::vector<T*>* objects;		// array storing objects
		std::vector<bool>* availableObject;

	public:
		ObjectPool3D(byte num);
		virtual ~ObjectPool3D();

		virtual void Update(float3232 gameTime) override;
		virtual void Draw(float32 gameTime)) override;

		T* execute();		// give out object for use!
		void back_to_pool(T* obj);		// send object back to pool

		// setter

		// getter
		int32 getNumObj() { return this->objects->size(); }
		std::vector<T*>* getObjects() { return this->objects; }
		T* getObjectsWithIndex(int32 i) { return this->objects->at(i); }
		std::vector<bool>* getAvailableObject() { return this->availableObject; }
		bool getAvailableObjectWidthIndex(int32 i) { return this->availableObject->at(i); }

	};

	template <class T>
	ObjectPool3D<T>::ObjectPool3D(byte num)
	{
		availableObject = new std::vector < bool >;
		objects = new std::vector < T* >;

		for (int32 i = 0; i < num; i++) {
			availableObject->push_back(false);
			objects->push_back(new T);
		}
	}

	template <class T>
	ObjectPool3D<T>::~ObjectPool3D()
	{
		for (int32 i = 0; i < objects->size(); i++) {
			SafeDelete(objects->at(i));
		}
		SafeDelete(availableObject);
		SafeDelete(objects);
	}

	template <class T>
	void ObjectPool3D<T>::update(float3232 gameTime)
	{
		/*for (int32 i = 0; i < objects->size(); i++) {
		if (objects->at(i) != nullptr) {
		if (availableObject->at(i)) objects->at(i)->update();
		if (!objects->at(i)->getIsVisible())
		back_to_pool(objects->at(i));
		}
		}*/
	}

	template <class T>
	void ObjectPool3D<T>::draw(bool drawThis)
	{
		/*for (int32 i = 0; i < objects->size(); i++) {
		if (objects->at(i) != nullptr && availableObject->at(i)) objects->at(i)->draw();
		}*/
	}

	/**
	* In the case, do linear sort are better choice!
	*/
	template <class T>
	T* ObjectPool3D<T>::execute()
	{
		for (int32 i = 0; i < objects->size(); i++) {
			if (!availableObject->at(i) && objects->at(i) != nullptr) {
				availableObject->at(i) = true;
				return objects->at(i);
				break;
			}
		}

		return nullptr;
	}
	/**
	* send object back to pool
	*/
	template <class T>
	void ObjectPool3D<T>::back_to_pool(T* obj)
	{
		for (int32 i = 0; i < objects->size(); i++) {
			if (objects->at(i) == obj) {
				availableObject->at(i) = false;			// turn it to deactive for next use
				break;
			}
		}
	}
}// end namespace "JCS_D3DX_v9_Engine"

#endif // __OBJECTPOOL3D_H__

