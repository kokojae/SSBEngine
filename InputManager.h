#pragma once
#include <vector>
#include <d3dx9.h>

class KeyState
{
public:
	KeyState();
	KeyState(int vkCode);
	~KeyState();

	int vkCode;
	bool isOn;		// Ű�� ��� ������������
	bool isDown;	// Ű�� �ѹ� ���ȴ°�
	bool isUp;		// Ű�� �������°�
};

static class InputManager
{
public:
	InputManager();
	~InputManager();

	enum class KeyCode { W, A, S, D, SPACE, MOUSE0, MOUSE1, MAX };

	static HWND hWnd;
	static std::vector<KeyState*> keyStateVector;
	static D3DXVECTOR2 mousePosition;

	static void Init(HWND hWnd);
	static void Update();

	static void AddKey(KeyCode keyCode, int vkCode);

	static bool GetKey(KeyCode keyCode);
	static bool GetKeyDown(KeyCode keyCode);
	static bool GetKeyUp(KeyCode keyCode);
};

