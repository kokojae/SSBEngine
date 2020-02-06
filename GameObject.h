#pragma once
#include <map>
#include <list>
#include <string>
#include <typeinfo>

class Component;

class GameObject
{
public:
	GameObject();
	~GameObject();

	std::map<std::string, Component*> componentMap;
	std::list<Component*> componentList;

	template<typename T>
	T* AddComponent();
	template<typename T>
	T* GetComponent();
};

template<typename T>
inline T* GameObject::AddComponent()
{
	auto comp = new T();

	auto component = dynamic_cast<Component*>(comp);
	if (component == nullptr)
	{
		return nullptr;
	}

	auto componentName = typeid(comp).name();;

	componentMap.insert(std::make_pair(componentName, comp));
	componentList.insert(comp);

	return comp;
}

template<typename T>
inline T* GameObject::GetComponent()
{	
	auto componentName = typeid(T*).name();

	auto pair = componentMap.find(componentName);

	if (pair == componentMap.end())
	{
		return nullptr;
	}

	return pair->second;
}
