#pragma once
#include <list>
#include <d3dx9.h>
#include "GameManager.h"

class GameObject;

class Scene
{
public:
	Scene();
	~Scene();

	std::list<GameObject*> objectList;

	void Update();

	void AddGameObject(GameObject* obj);
};

template<typename T>
T* Instantiate(D3DXVECTOR2 position)
{
	auto obj = new T();
	auto gameObject = dynamic_cast<GameObject*>(obj);
	if (gameObject == nullptr)
	{
		delete obj;
		return nullptr;
	}

	GameManager::nowScene->AddGameObject(obj);

	gameObject->position = position;
	return gameObject;
}

