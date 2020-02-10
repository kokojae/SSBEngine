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
}
