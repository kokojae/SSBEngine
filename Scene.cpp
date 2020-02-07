#include "Scene.h"
#include "GameObject.h"

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
	for (auto obj : objectList)
	{
		obj->LateUpdate();
	}
}

void Scene::AddGameObject(GameObject* obj)
{
	objectList.push_back(obj);
	obj->Init();
}
