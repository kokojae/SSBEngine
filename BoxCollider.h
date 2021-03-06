#pragma once
#include <d3dx9.h>

class GameObject;

class BoxCollider
{
public:
	BoxCollider();
	~BoxCollider();

	D3DXVECTOR2 size;
	bool isTrigger;
	bool isUI;

	GameObject* parent;

	RECT GetRect();
};

