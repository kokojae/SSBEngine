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
	void OnRender() override;
	void LateUpdate() override;
	void Release() override;
	
	void PlayerMove();
	void MouseInput();
	void CameraMove();
};

