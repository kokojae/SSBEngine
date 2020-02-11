#pragma once
#include <d3dx9.h>
#include <map>
#include <string>

class GameObject;

static class GraphicManager
{
public:
	GraphicManager();
	~GraphicManager();

	static LPDIRECT3DDEVICE9 device;
	static LPD3DXSPRITE sprite;
	static ID3DXFont* font;
	static std::map<std::string, LPDIRECT3DTEXTURE9> textureMap;

	static void Init(LPDIRECT3DDEVICE9 device);
	static void Render();
	static void Render(GameObject* object);

	static LPDIRECT3DTEXTURE9 CreateTexture(LPCWSTR fileName);
	static D3DXVECTOR2 GetTextureSize(LPDIRECT3DTEXTURE9 texture);
	static D3DXVECTOR2 GetTextureSize(std::string textureName);
	static void AddTexture(std::string textureName, LPCWSTR fileName);
	static LPDIRECT3DTEXTURE9 GetTexture(std::string textureName);
	static void RenderText(std::string str, D3DXVECTOR2 pos);
};

bool Compare(GameObject* o1, GameObject* o2);

