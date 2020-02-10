#include "TestObject.h"
#include "Animation.h"

TestObject::TestObject()
{
}

TestObject::~TestObject()
{
}

void TestObject::Init()
{
	animation->SetAnimation("TestImage");

	position = { 500,500 };
}

void TestObject::Update()
{
	position.x += 5.0f;

	rotation += 5.0f;

	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	float ss = abs(sin(D3DXToRadian(rotation) * 20.0f) * 2.0f) + 0.5f;
	scale.x = scale.y = ss;

	//scale.x = abs(sin(D3DXToRadian(rotation)));
	//scale.y = abs(sin(D3DXToRadian(rotation)));
	//scale.y = abs(cos(D3DXToRadian(rotation)));
}

void TestObject::LateUpdate()
{
	position.x -= 5.0f;
}
