#pragma once
#include <d3dx9.h>

class Camera
{
public:
	Camera();
	~Camera();

	static int screenHeight;
	static int screenWidth;

	static D3DXVECTOR2 position;
};

