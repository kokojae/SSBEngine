#include "Scene.h"
#include "GameObject.h"
#include "BoxCollider.h"
#include <vector>

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Update()
{
	for (auto iter = objectList.begin(); iter != objectList.end(); iter++)
	{
		auto obj = *iter;

		if (!obj->isActive)
		{
			obj->Release();
			objectList.erase(iter--);
			delete obj;
		}
		else
		{
			obj->Update();
			obj->UpdateAnimation();
		}
	}

	CollisionCheck();

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

		for (int j = i; j < size; j++)
		{
			auto obj2 = vec[j];

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
