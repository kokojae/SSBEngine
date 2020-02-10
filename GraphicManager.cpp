#include "GraphicManager.h"
#include "Scene.h"
#include "Animation.h"
#include "GameObject.h"
#include "Camera.h"

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
	AddTexture("TestImage", L"Resorce/dd.png");
	AddTexture("TestBack", L"Resorce/Background.png");
	AddTexture("TestBullet", L"Resorce/Background.png");
}

void GraphicManager::Render()
{
	auto objList = GameManager::nowScene->objectList;

	//auto Compare = [](GameObject* o1, GameObject* o2)
	//{
	//	return o1->sortingLayer < o2->sortingLayer;
	//};

	objList.sort(Compare);

	for (auto obj : objList)
	{
		Render(obj);
	}
}

void GraphicManager::Render(GameObject* object)
{
	auto tex = GetTexture(object->animation->textureName);
	auto frameSize = object->animation->frameSize;

	if (tex == nullptr)
	{
		return;
	}

	D3DXMATRIX mat, pos, cent, rot, sca;

	D3DXMatrixTranslation(&pos, object->position.x, object->position.y, 0.0f);
	D3DXMatrixTranslation(&cent, -frameSize.x * 0.5f, -frameSize.y * 0.5f, 0.0f);	
	D3DXMatrixRotationZ(&rot, D3DXToRadian(object->rotation));
	D3DXMatrixScaling(&sca, object->scale.x, object->scale.y, 0.0f);

	mat = cent * sca * rot * pos;

	mat *= Camera::matrix;

	RECT rc = object->animation->GetRect();

	sprite->SetTransform(&mat);
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(tex, &rc, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
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

D3DXVECTOR2 GraphicManager::GetTextureSize(LPDIRECT3DTEXTURE9 texture)
{
	D3DSURFACE_DESC de;

	texture->GetLevelDesc(0, &de);

	return { static_cast<float>(de.Width),static_cast<float>(de.Height) };
}

D3DXVECTOR2 GraphicManager::GetTextureSize(std::string textureName)
{
	auto tex = GetTexture(textureName);
	return GetTextureSize(tex);
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

bool Compare(GameObject* o1, GameObject* o2)
{
	return o1->sortingLayer < o2->sortingLayer;
}
