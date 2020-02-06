#pragma once
#include <d3dx9.h>
#include "Component.h"

class Transform :
	public Component
{
public:
	Transform();
	~Transform();

	D3DXVECTOR2 position;
	float rotation;
	D3DXVECTOR2 scale;
};

