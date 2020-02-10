#include "GameObject.h"
#include "Animation.h"

GameObject::GameObject() : position({ 0.0f,0.0f }), rotation(0.0f), scale({ 1.0f,1.0f }), isActive(true)
{
	animation = new Animation();
}

GameObject::~GameObject()
{
	delete animation;
}

void GameObject::Init()
{
}

void GameObject::Update()
{
	animation->Update();
}

void GameObject::LateUpdate()
{
}

void GameObject::Render()
{
}

void GameObject::Release()
{
}

void GameObject::UpdateAnimation()
{
	animation->Update();
}
