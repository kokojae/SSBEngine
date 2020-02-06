#include "GameManager.h"
#include "Camera.h"

LPDIRECT3D9 GameManager::g_pD3D = nullptr;
LPDIRECT3DDEVICE9 GameManager::g_pd3dDevice = nullptr;

GameManager::GameManager()
{
	g_pD3D = nullptr;
}

GameManager::~GameManager()
{
}

void GameManager::Init(HWND hWnd)
{
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferHeight = Camera::screenHeight;
	d3dpp.BackBufferWidth = Camera::screenWidth;

	g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice);
}

void GameManager::Render()
{
	// Clear the back buffer to a blue color
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// Begin the scene
	g_pd3dDevice->BeginScene();

	// Rendering of scene objects happens here


	// End the scene
	g_pd3dDevice->EndScene();

	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GameManager::Release()
{
	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();
	if (g_pD3D != NULL)
		g_pD3D->Release();
}
