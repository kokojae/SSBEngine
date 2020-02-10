#include "Camera.h"

int Camera::screenWidth = 1280;
int Camera::screenHeight = 720;
D3DXVECTOR2 Camera::position = { 0.0f,0.0f };
float Camera::rotation = 0.0f;
D3DXVECTOR2 Camera::scale = { 1.0f,1.0f };
D3DXMATRIX Camera::matrix = D3DXMATRIX();

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
	D3DXMATRIX cent, pos, sca, rot;

	D3DXMatrixTranslation(&cent, screenWidth * 0.5f, screenHeight * 0.5f, 0.0f);
	D3DXMatrixTranslation(&pos, -position.x, -position.y, 0.0f);
	D3DXMatrixRotationZ(&rot, D3DXToRadian(rotation));
	D3DXMatrixScaling(&sca, scale.x, scale.y, 0.0f);

	matrix = cent * sca * rot * pos;
}
