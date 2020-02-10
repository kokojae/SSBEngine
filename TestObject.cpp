#include "TestObject.h"
#include "Animation.h"
#include "InputManager.h"

TestObject::TestObject()
{
}

TestObject::~TestObject()
{
}

void TestObject::Init()
{
	animation->SetAnimation("TestImage");

	position = { 0.0f,0.0f };
	//position = { 100.0f,100.0f };
	sortingLayer = 1;
}

void TestObject::Update()
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

	position.x += 5.0f;

	rotation += 0.1f;

	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	float ss = abs(sin(D3DXToRadian(rotation) * 3.0f) * 2.0f) + 1.0f;
	scale.x = scale.y = ss;

	//scale.x = abs(sin(D3DXToRadian(rotation)));
	//scale.y = abs(sin(D3DXToRadian(rotation)));
	//scale.y = abs(cos(D3DXToRadian(rotation)));
}

void TestObject::LateUpdate()
{
	position.x -= 5.0f;
}
