#ifndef __OBJECTPOOL2D_H__
/**
 * $File: ObjectPool2D.h $
 * $Date: $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright (c) 2015 by Shen, Jen-Chieh $
 */
#define __OBJECTPOOL2D_H__


#include "GameObject2D.h"

namespace JCS_D2DEngine
{

    //====================================================================================
    // Class Name : ObjectPool2D
    //
    // Description : Simulate the object pool.
    //====================================================================================
    template <class T>
    class ObjectPool2D 
        : public GameObject2D
    {
    protected:
        std::vector<T*> objects;        // array storing objects
        std::vector<bool> availableObject;

    public:
        ObjectPool2D(uint32 num);
        virtual ~ObjectPool2D();

        virtual void initialize() override;
        virtual void update(const float32 deltaTime) override;
        virtual void draw() override;

        T* execute();        // give out object for use!
        void back_to_pool(T* obj);        // send object back to pool

        /** setter **/

        /** getter **/
        uint32 GetLength() const { return this->objects.size(); }
        std::vector<T*>* getObjects() const { return this->objects; }
        T* getObjectsWithIndex(uint32 i) const { return this->objects.at(i); }
        std::vector<bool>* getAvailableObject() const { return this->availableObject; }
        bool getAvailableObjectWidthIndex(uint32 i) const { return this->availableObject.at(i); }

    };

    template <class T>
    ObjectPool2D<T>::ObjectPool2D(uint32 num)
    {
        for (uint32 i = 0; i < num; ++i)
        {
            availableObject.push_back(false);
            objects.push_back(new T);
        }
    }

    template <class T>
    ObjectPool2D<T>::~ObjectPool2D()
    {
        for (uint32 i = 0; i < GetLength(); ++i)
        {
            SafeDeleteObject(objects.at(i));
        }
        objects.clear();
        availableObject.clear();
    }

    template <class T>
    void ObjectPool2D<T>::initialize()
    {
        for (uint32 i = 0; i < GetLength(); ++i)
        {
            objects.at(i)->initialize();
        }
    }

    template <class T>
    void ObjectPool2D<T>::update(const float32 deltaTime)
    {
        //for (uint32 i = 0; i < GetLength(); ++i) 
        //{
        //    if (objects.at(i) != nullptr) 
        //    {
        //        if (availableObject.at(i)) 
        //            objects.at(i)->update();

        //        // Condition going back to pool
        //        if (!objects.at(i)->getIsVisible())
        //            back_to_pool(objects.at(i));
        //    }
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
        for (uint32 i = 0; i < GetLength(); ++i) 
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
        for (uint32 i = 0; i < GetLength(); ++i)
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

