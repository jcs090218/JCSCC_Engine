#ifndef __D2D_SCENE2D_H__
/**
* $File: Scene2D.h $
* $Date: $
* $Revision: $
* $Creator: Jen-Chieh Shen $
* $Notice: See LICENSE.txt for modification and distribution information
*                   Copyright (c) 2015 by Shen, Jen-Chieh $
*/
#define __D2D_SCENE2D_H__

#include "D2D_StdAfx.h"

#include "ObjectPool2D.h"
#include <GameTool_JCS\GameTimer.h>
#include <GameInterface_JCS\JCS_Scene.h>

namespace JCS_D2DEngine
{

    //====================================================================================
    // Class Name : Scene2D
    //
    // Description : 
    //====================================================================================
    class Scene2D 
        : public JCS_Scene
    {
    private:
        std::vector<GameObject2D*> game_objects;
        std::vector<ObjectPool2D<GameObject2D>*> op_game_objects;
        std::vector<Sprite2D*> sprites;


        // Multi-threading Handling        
        std::thread m_updateThread;
        std::thread m_drawThread;

        bool m_endThread;
        void SetEndThread(const bool active) { this->m_endThread = active; }
        bool GetEndThread() const { return this->m_endThread; }

    public:
        Scene2D();
        virtual ~Scene2D();

        virtual void initialize() override;
        virtual void update(float32 deltaTime) override;
        virtual void draw() override;

        // using parallel calculation thread handling
        void thread_initialize(JCS_GameTool::GameTimer& pTimer);

        //-- 加入物件
        void AddGameObject2DToScene(GameObject2D* game_object);
        void AddObjectPoolGameObject2DToScene(ObjectPool2D<GameObject2D>* op_game_object);
        void AddSprite2DToScene(Sprite2D* sprite);

        //-- 移除物件
        void RemoveGameObject2DFromScene(GameObject2D* game_object);
        void RemoveObjectPoolGameObject2DFromScene(ObjectPool2D<GameObject2D>* op_game_object);
        void RemoveSprite2DFromScene(Sprite2D* sprite);        

        /** setter **/

        /** getter **/
        std::vector<GameObject2D*> getGameObjects() const { return this->game_objects; }
        std::vector<ObjectPool2D<GameObject2D>*> getOPGameObjects() const { return this->op_game_objects; }
        GameObject2D* getGameObjectPointerWithIndex(const uint32 index) const { return this->game_objects.at(index); }
        GameObject2D& getGameObjectReferenceWithIndex(const uint32 index) const { return *this->game_objects.at(index); }

    private:
        // parallel calculation thread handling functions
        void thread_update(JCS_GameTool::GameTimer& pTimer);
        void thread_draw();
        void clear_thread();
    };

}

#endif // __D2D_SCENE2D_H__

