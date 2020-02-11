#include "Enemy.h"
#include "Animation.h"

Enemy::Enemy()
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
}

void Enemy::Release()
{
	PlaySound(L"Resorce/Sound/destroy.wav", NULL, SND_FILENAME | SND_ASYNC);
}
