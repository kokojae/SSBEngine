#include "GameObject.h"

GameObject::GameObject() : position({ 0.0f,0.0f }), rotation(0.0f), scale({ 0.0f,0.0f }), isActive(true)
{
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
}

void GameObject::Update()
{
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
