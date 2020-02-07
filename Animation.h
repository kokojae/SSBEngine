#pragma once
#include <d3dx9.h>
#include <ctime>
#include <string>

class Animation
{
public:
	Animation();
	~Animation();

	std::string textureName;

	D3DXVECTOR2 imageSize;	// �ִϸ��̼� �̹����� ��ü ũ��
	D3DXVECTOR2 frameSize;	// �� �������� ������
	D3DXVECTOR2 nowFrame;	// ���� �������� ��ġ

	clock_t lastChangeTime;	// ���� �ֱ� ������ ���� �ð�
	clock_t timePerFrame;	// �� �����Ӵ� �ð�

	void Update();

	void SetAnimation(std::string textureName);
};

