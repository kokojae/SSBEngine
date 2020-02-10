#pragma once
#include "GameObject.h"
#include <ctime>

class Bullet :
	public GameObject
{
public:
	Bullet();
	~Bullet();

	D3DXVECTOR2 direction;
	float speed;
	float spawnTime;
	float aliveTime;

	void Init() override;
	void Update() override;

	void SetOption(D3DXVECTOR2 direction, float speed);
};

