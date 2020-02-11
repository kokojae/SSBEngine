#pragma once
#include "GameObject.h"

class TestObject;

class Enemy :
	public GameObject
{
public:
	Enemy();
	~Enemy();

	TestObject* target;

	void Init() override;
	void Update() override;
	void Release() override;

	void OnCollisionEnter(GameObject* gameObject) override;
};

