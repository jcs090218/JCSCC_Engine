#include "Scene2D.h"

#include "Physics2D.h"

#include <GameTool_JCS\DeviceManager.h>

namespace JCS_D2DEngine
{
	Scene2D::Scene2D()
		: game_objects()
		, op_game_objects()
		, sprites()
        // Multi-threading Handling
        , m_endThread(false)
        , m_updateThread()
        , m_drawThread()
	{

	}

	Scene2D::~Scene2D()
	{
        // Close the thread before we delete RenderableObject
        clear_thread();

        // Delete RenderableObject
		for (GameObject2D* pGameObject2D : game_objects)
			SafeDeleteObject(pGameObject2D);

		for (ObjectPool2D<GameObject2D>* pObjectPoolObjectGameObject2D : op_game_objects)
			SafeDeleteObject(pObjectPoolObjectGameObject2D);

		for (Sprite2D* pSprite2D : sprites)
			SafeDeleteObject(pSprite2D);

		game_objects.clear();
		op_game_objects.clear();
		sprites.clear();
	}

	void Scene2D::initialize()
	{
		for (GameObject2D* temp : game_objects)
			temp->initialize();

		for (ObjectPool2D<GameObject2D>* temp : op_game_objects)
			temp->initialize();

	}

	void Scene2D::update(float32 gameTime)
	{
        for (Sprite2D* tempSprite : sprites)
            tempSprite->update(gameTime);

		for (GameObject2D* temp : game_objects)
			temp->update(gameTime);

		for (ObjectPool2D<GameObject2D>* temp : op_game_objects)
			temp->update(gameTime);

	}

	void Scene2D::draw()
	{
        for (Sprite2D* tempSprite : sprites)
            tempSprite->draw();

        for (GameObject2D* temp : game_objects)
            temp->draw();

        for (ObjectPool2D<GameObject2D>* temp : op_game_objects)
            temp->draw();
	}

    //-------------------------------------------------------------------------------------------------------
    // 執行緒平行運算
    //-------------------------------------------------------------------------------------------------------
    /**
    * 開啟執行緒
    */
    void Scene2D::thread_initialize(JCS_GameTool::GameTimer& pTimer)
    {
        // initialize all the object preparing to get render
        initialize();

        // Create Thread
        //m_updateThread = std::thread(&Scene2D::thread_update, this, pTimer);
        m_drawThread = std::thread(&Scene2D::thread_draw, this);
    }
    /**
     * "遊戲邏輯"執行緒
     */
    void Scene2D::thread_update(JCS_GameTool::GameTimer& pTimer)
    {
        // Thread Loop
        while (!GetEndThread())
        {
            this->update(pTimer.DeltaTime());
        }
    }
    /**
    * "渲染"執行緒
    */
    void Scene2D::thread_draw()
    {
        // Get the device to render
        JCS_D2DEngine::Graphics2D& device = 
            JCS_GameTool::DeviceManager::getInstance()
            ->GetDirect2DDeviceAsRef();

        // Thread Loop
        while (!GetEndThread())
        {
            device.BeginRender();
            device.SetTransform(D2D1::Matrix3x2F::Identity());
            device.ClearScreen(0.0f, 0.0f, 0.0f, 1.0f);

            this->draw();

            device.EndRender();
        }
    }
    /**
     * 清除執行緒
     *
     * m_updatThread : "遊戲邏輯"執行緒
     * m_drawThread : "渲染"執行緒
     */
    void Scene2D::clear_thread()
    {
        // End the Thread and Clean it up
        SetEndThread(true);

        if (m_updateThread.joinable())
            m_updateThread.join();

        if (m_drawThread.joinable())
            m_drawThread.join();
    }

    //-------------------------------------------------------------------------------------------------------
    // 相關輔助
    //-------------------------------------------------------------------------------------------------------
	/**
	 * 加入一個 "GameObject2D"
	 *
	 * 如果是物理物件我們加入來進行計算
	 */
	void Scene2D::AddGameObject2DToScene(GameObject2D* game_object)
	{
		if (game_object != nullptr)
			game_objects.push_back(game_object);
	}
	/**
	 * 加入一個 "ObjectPool<GameObject2D>*"
	 */
	void Scene2D::AddObjectPoolGameObject2DToScene(ObjectPool2D<GameObject2D>* op_game_object)
	{
		if (op_game_object != nullptr)
			op_game_objects.push_back(op_game_object);
	}
	/**
	* 加入一個 "Sprite2D*"
	*/
	void Scene2D::AddSprite2DToScene(Sprite2D* sprite)
	{
		if (sprite != nullptr)
			sprites.push_back(sprite);
	}
	/**
	 * 刪除一個 "GameObject2D"
	 */
	void Scene2D::RemoveGameObject2DFromScene(GameObject2D* game_object)
	{
		if (game_object == nullptr)
		{
			throw GameError(L"Scene2D::RemoveGO2DFromScene(GameObject2D*) :\
							  Object equals to nullptr!");
			return;
		}

		uint16 i, j;
		for (i = 0; i < game_objects.size(); ++i)
		{
			if (game_objects.at(i) == game_object)
			{
				// 刪除物件
				SafeDeleteObject(game_objects.at(i));

				// 移動來補上原本的位置
				for (j = i; j < game_objects.size(); ++j)
					game_objects.at(i) = game_objects.at(i + 1);

				// 改變Array大小
				game_objects.erase(game_objects.begin() + i);
				return;
			}
		}

		throw GameError(L"Scene2D::RemoveGO2DFromScene(GameObject2D*) :\
							清單中沒有此物體!");
	}
	/**
	 * 刪除一個 "ObjectPool<GameObject2D>*"
	 */
	void Scene2D::RemoveObjectPoolGameObject2DFromScene(ObjectPool2D<GameObject2D>* op_game_object)
	{
		if (op_game_object == nullptr)
		{
			throw GameError(L"Scene2D::RemoveOPGO2DFromScene\
				(JCS_GameTool::ObjectPool<GameObject2D>*) :\
				Object equals to nullptr!");
			return;
		}


		uint16 i, j;
		for (i = 0; i < op_game_objects.size(); i++)
		{
			if (op_game_objects.at(i) == op_game_object)
			{
				// 刪除物件
				SafeDeleteObject(op_game_objects.at(i));

				// 移動來補上原本的位置
				for (j = i; j < op_game_objects.size(); ++j)
					op_game_objects.at(i) = op_game_objects.at(i + 1);

				// 改變Array大小
				op_game_objects.erase(op_game_objects.begin() + i);
				return;
			}
		}

		throw GameError(L"Scene2D::RemoveOPGO2DFromScene\
					(JCS_GameTool::ObjectPool<GameObject2D>*) : \
					清單中沒有此物體!");
	}
	/**
	* 刪除一個 "Sprite2D*"
	*/
	void Scene2D::RemoveSprite2DFromScene(Sprite2D* sprite)
	{
		if (sprite == nullptr)
		{
			throw GameError(L"Scene2D::RemoveSprite2DFromScene(cSprite2D*) : \
							  Object equals to nullptr!");
			return;
		}

		uint8 i, j;
		for (i = 0; i < sprites.size(); ++i)
		{
			if (sprites.at(i) == sprite)
			{
				// 刪除物件
				SafeDeleteObject(sprites.at(i));

				// 移動來補上原本的位置
				for (j = i; j < sprites.size(); ++j)
					sprites.at(i) = sprites.at(i + 1);

				// 改變Array大小
				sprites.erase(sprites.begin() + i);
				return;
			}
		}
		throw GameError(L"Scene2D::RemoveSprite2DFromScene(cSprite2D*) : \
						  清單中沒有此物體!");
	}


}// end namespace "JCS_D2DEngine"

