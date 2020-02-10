#pragma once
#include <d3dx9.h>

class Camera
{
public:
	Camera();
	~Camera();

	static int screenHeight;
	static int screenWidth;

	static D3DXVECTOR2	position;
	static float		rotation;
	static D3DXVECTOR2	scale;
	static D3DXMATRIX	matrix;

	static void Update();
};

