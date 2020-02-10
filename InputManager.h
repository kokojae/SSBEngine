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
	bool isOn;		// 키가 계속 눌리고있을때
	bool isDown;	// 키가 한번 눌렸는가
	bool isUp;		// 키가 떼여졌는가
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

