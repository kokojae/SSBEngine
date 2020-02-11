#include "Camera.h"

int Camera::screenWidth = 1280;
int Camera::screenHeight = 720;
D3DXVECTOR2 Camera::position = { 0.0f,0.0f };
float Camera::rotation = 0.0f;
D3DXVECTOR2 Camera::scale = { 1.0f,1.0f };
float Camera::shake = 0.0f;
D3DXMATRIX Camera::matrix = D3DXMATRIX();

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
	if (shake > 1.0f)
	{
		auto rotation_ = rand() % 360;
		auto radian_ = D3DXToRadian(rotation_);
		position += {static_cast<float>(cos(radian_))* shake, static_cast<float>(sin(radian_))* shake};
		shake *= 0.9f;
	}
	else
	{
		shake = 0.0f;
	}

	D3DXMATRIX cent, pos, sca, rot;

	D3DXMatrixTranslation(&cent, screenWidth * 0.5f, screenHeight * 0.5f, 0.0f);
	D3DXMatrixTranslation(&pos, -position.x, -position.y, 0.0f);
	D3DXMatrixRotationZ(&rot, D3DXToRadian(rotation));
	D3DXMatrixScaling(&sca, scale.x, scale.y, 0.0f);

	matrix = cent * sca * rot * pos;
}

void Camera::AddShake(float shake)
{
	Camera::shake += shake;
}
