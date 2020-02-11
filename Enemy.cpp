#include "Enemy.h"
#include "Animation.h"
#include "TestObject.h"

Enemy::Enemy() : target(nullptr)
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	animation->SetAnimation("Enemy");
	sortingLayer = 1;
	name = "Enemy";

	target = static_cast<TestObject*>(GameObject::Find("Player"));
}

void Enemy::Update()
{
	auto diff = target->position - position;

	D3DXVECTOR2 result;
	D3DXVec2Normalize(&result, &diff);

	position += result * 3.0f;
}

void Enemy::Release()
{
	PlaySound(L"Resorce/Sound/destroy.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void Enemy::OnCollisionEnter(GameObject* gameObject)
{
	if (gameObject->name == "Player")
	{// 맞은 애가 플레이어임
		gameObject->isActive = false;
	}
}
