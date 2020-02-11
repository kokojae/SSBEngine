#include "TestObject.h"
#include "Animation.h"
#include "InputManager.h"
#include "Camera.h"
#include "Scene.h"
#include "Bullet.h"
#include "GraphicManager.h"

TestObject::TestObject()
{
}

TestObject::~TestObject()
{
}

void TestObject::Init()
{
	name = "Player";
	animation->SetAnimation("TestImage");

	position = { 0.0f,0.0f };
	sortingLayer = 5;
}

void TestObject::Update()
{
	PlayerMove();
	MouseInput();
}

void TestObject::OnRender()
{
	GraphicManager::RenderText("Player", position);
}

void TestObject::LateUpdate()
{
	CameraMove();
}

void TestObject::PlayerMove()
{
	if (InputManager::GetKey(InputManager::KeyCode::W))
	{
		position.y -= 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::A))
	{
		position.x -= 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::S))
	{
		position.y += 5.0f;
	}
	if (InputManager::GetKey(InputManager::KeyCode::D))
	{
		position.x += 5.0f;
	}

	//rotation += 0.1f;

	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	//float ss = abs(sin(D3DXToRadian(rotation) * 3.0f) * 2.0f) + 1.0f;
	//scale.x = scale.y = ss;

	//scale.x = abs(sin(D3DXToRadian(rotation)));
	//scale.y = abs(sin(D3DXToRadian(rotation)));
}

void TestObject::MouseInput()
{
	auto mousePosition = InputManager::mousePosition;

	auto diff = mousePosition - position;
	
	auto rotation = atan2(diff.y, diff.x);

	TestObject::rotation = D3DXToDegree(rotation);

	D3DXVECTOR2 normal;
	D3DXVec2Normalize(&normal, &diff);

	if (InputManager::GetKeyDown(InputManager::KeyCode::MOUSE0))
	{
		auto bullet = Instantiate<Bullet>(position);
		if (bullet != nullptr)
		{
			bullet->SetOption(normal, 10.0f);
		}
	}
}

void TestObject::CameraMove()
{
	//Camera::position = position;
	//position = InputManager::mousePosition;

	auto diff = position - Camera::position;

	Camera::position += diff * 0.05f;
}
