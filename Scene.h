#pragma once
#include <list>
#include <d3dx9.h>
#include "GameManager.h"
#include <string>

class GameObject;

class Scene
{
public:
	Scene();
	~Scene();

	std::string nextScene;
	std::list<GameObject*> objectList;

	void Update();
	void LateUpdate();

	void AddGameObject(GameObject* obj);
	bool AABB(GameObject* obj1, GameObject* obj2);
	void CollisionCheck();

	void ChangeScene(std::string sceneName);
	void CheckNextScene();
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

	gameObject->position = position;
	GameManager::nowScene->AddGameObject(obj);

	return obj;
}

