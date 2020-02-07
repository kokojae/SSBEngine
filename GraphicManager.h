#pragma once
#include <d3dx9.h>
#include <map>
#include <string>

static class GraphicManager
{
public:
	GraphicManager();
	~GraphicManager();

	static LPDIRECT3DDEVICE9 device;
	static LPD3DXSPRITE sprite;
	static std::map<std::string, LPDIRECT3DTEXTURE9> textureMap;

	static void Init(LPDIRECT3DDEVICE9 device);
	static void Render();

	static LPDIRECT3DTEXTURE9 CreateTexture(LPCWSTR fileName);
	static D3DXVECTOR2 GetTextureSize();
	static void AddTexture(std::string textureName, LPCWSTR fileName);
	static LPDIRECT3DTEXTURE9 GetTexture(std::string textureName);
};

