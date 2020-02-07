#pragma once
#include <d3dx9.h>

static class GraphicManager
{
public:
	GraphicManager();
	~GraphicManager();

	static LPDIRECT3DDEVICE9 device;
	static LPDIRECT3DTEXTURE9 testTexture;
	static LPD3DXSPRITE sprite;

	static void Init(LPDIRECT3DDEVICE9 device);
	static void Render();

	static LPDIRECT3DTEXTURE9 CreateTexture(LPCWSTR fileName);
	static D3DXVECTOR2 GetTextureSize();
};

