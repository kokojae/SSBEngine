#include "Scene.h"
#include "GameObject.h"
#include "BoxCollider.h"
#include <vector>
#include "TestObject.h"
#include "Background.h"
#include "Enemy.h"

Scene::Scene() : nextScene("")
{
}

Scene::~Scene()
{
}

void Scene::Update()
{
	//for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
	//{
	//	auto obj = *iter;

	//	if (!obj->isActive)
	//	{
	//		obj->Release();
	//		objectList.erase(iter--);
	//		delete obj;
	//	}
	//	else
	//	{
	//		obj->Update();
	//		obj->UpdateAnimation();
	//	}
	//}

	auto iter = objectList.begin();
	while (iter != objectList.end())
	{
		auto obj = *iter;
		if (obj->isActive)
		{
			obj->Update();
			obj->UpdateAnimation();
			iter++;
		}
		else
		{
			obj->Release();
			delete obj;
			iter = objectList.erase(iter++);
		}
	}
}

void Scene::LateUpdate()
{
	for (auto obj : objectList)
	{
		obj->LateUpdate();
	}
}

void Scene::CollisionCheck()
{
	auto size = objectList.size();

	if (size < 1)
	{
		return;
	}

	std::vector<GameObject*> vec(size);
	int idx = 0;

	for (auto obj : objectList)
	{
		vec[idx++] = obj;
	}

	for (int i = 0; i < idx; i++)
	{
		auto obj1 = vec[i];

		if (!obj1->isActive)
		{
			continue;
		}

		for (int j = i; j < size; j++)
		{
			auto obj2 = vec[j];

			if (!obj2->isActive)
			{
				continue;
			}

			if (obj1 == obj2)
			{
				continue;
			}


			// 여기서 충돌체크
			// 원충돌
			// AABB -> 오늘쓸거
			// obb
			if (AABB(obj1, obj2))
			{
				obj1->OnCollisionEnter(obj2);
				obj2->OnCollisionEnter(obj1);
			}
		}
	}
}

void Scene::ChangeScene(std::string sceneName)
{
	for (auto obj : objectList)
	{
		obj->isActive = false;
	}

	Update();

	if (sceneName == "Main")
	{
		mciSendString(L"close BGM", 0, 0, 0);
		mciSendString(L"open ./Resorce/Sound/BGM.wav type mpegvideo alias Bgm", 0, 0, 0);
		mciSendString(L"play BGM repeat", 0, 0, 0);
		mciSendString(L"setaudio BGM volume to 300", 0, 0, 0);

		Instantiate<TestObject>({ 0.0f,0.0f });
		Instantiate<Background>({ 0.0f,0.0f });
		Instantiate<Enemy>({ 0.0f,-500.0f });
		Instantiate<Enemy>({ 500.0f,-500.0f });
		Instantiate<Enemy>({ 500.0f,0.0f });
		Instantiate<Enemy>({ 500.0f,500.0f });
		Instantiate<Enemy>({ 0.0f,500.0f });
		Instantiate<Enemy>({ -500.0f,500.0f });
		Instantiate<Enemy>({ -500.0f,0.0f });
		Instantiate<Enemy>({ -500.0f,-500.0f });
	}
}

void Scene::CheckNextScene()
{
	if (nextScene != "")
	{
		ChangeScene(nextScene);
		nextScene = "";
	}
}

void Scene::AddGameObject(GameObject* obj)
{
	objectList.push_back(obj);
		obj->Init();
}

bool Scene::AABB(GameObject* obj1, GameObject* obj2)
{
	RECT result;

	auto rect1 = &obj1->collider->GetRect();
	auto rect2 = &obj2->collider->GetRect();

	return IntersectRect(&result, rect1, rect2);
}
