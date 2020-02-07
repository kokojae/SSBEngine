#include "GraphicManager.h"

LPDIRECT3DDEVICE9 GraphicManager::device = nullptr;
LPD3DXSPRITE GraphicManager::sprite = nullptr;
std::map<std::string, LPDIRECT3DTEXTURE9> GraphicManager::textureMap = std::map<std::string, LPDIRECT3DTEXTURE9>();


GraphicManager::GraphicManager()
{
}

GraphicManager::~GraphicManager()
{
}

void GraphicManager::Init(LPDIRECT3DDEVICE9 device)
{
	GraphicManager::device = device;

	D3DXCreateSprite(device, &sprite);

	//testTexture = CreateTexture(L"dd.png");
	AddTexture("TestImage", L"dd.png");
}

void GraphicManager::Render()
{
	D3DXMATRIX mat, pos;

	D3DXMatrixTranslation(&pos, 0.0f, 0.0f, 0.0f);

	mat = pos;

	auto texSize = GetTextureSize();
	RECT rc = { 0,0,texSize.x,texSize.y };

	sprite->SetTransform(&mat);
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	for (auto tex : textureMap)
	{
		sprite->Draw(tex.second, &rc, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	sprite->End();
}

LPDIRECT3DTEXTURE9 GraphicManager::CreateTexture(LPCWSTR fileName)
{
	LPDIRECT3DTEXTURE9 texture;

	D3DXCreateTextureFromFileEx(
		device,
		fileName,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		1,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		1,
		1,
		NULL,
		NULL,
		NULL,
		&texture);

	return texture;
}

D3DXVECTOR2 GraphicManager::GetTextureSize()
{
	D3DSURFACE_DESC de;

	//testTexture->GetLevelDesc(0, &de);

	return { static_cast<float>(de.Width),static_cast<float>(de.Height) };
}

void GraphicManager::AddTexture(std::string textureName, LPCWSTR fileName)
{
	auto pair = textureMap.find(textureName);
	if (pair == textureMap.end())
	{
		auto tex = CreateTexture(fileName);

		textureMap.insert(std::make_pair(textureName, tex));

	}
}

LPDIRECT3DTEXTURE9 GraphicManager::GetTexture(std::string textureName)
{
	auto pair = textureMap.find(textureName);
	if (pair == textureMap.end())
	{
		return nullptr;
	}

	return pair->second;
}
