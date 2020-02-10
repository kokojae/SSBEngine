#pragma once
#include "GameObject.h"
class TestObject :
	public GameObject
{
public:
	TestObject();
	~TestObject();

	void Init() override;
	void Update() override;
	void LateUpdate() override;
};

