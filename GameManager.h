#pragma once
#include <d3dx9.h>

class GameManager
{
public:
	static LPDIRECT3D9 g_pD3D;
	static LPDIRECT3DDEVICE9 g_pd3dDevice;

	GameManager();
	~GameManager();

	static void Init(HWND hWnd);
	static void Render();
	static void Release();
};

