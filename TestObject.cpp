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
}
