#pragma once
#include <d3dx9.h>

class Scene;

class GameManager
{
public:
	GameManager();
	~GameManager();

	static LPDIRECT3D9 g_pD3D;
	static LPDIRECT3DDEVICE9 g_pd3dDevice;

	static Scene* nowScene;

	static void Init(HWND hWnd);
	static void Update();
	static void Render();
	static void Release();
};

