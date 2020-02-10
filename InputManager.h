#pragma once
#include <vector>

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

	enum class KeyCode { W, A, S, D, MAX };

	static std::vector<KeyState*> keyStateVector;

	static void Init();
	static void Update();

	static void AddKey(KeyCode keyCode, int vkCode);

	static bool GetKey(KeyCode keyCode);
	static bool GetKeyDown(KeyCode keyCode);
	static bool GetKeyUp(KeyCode keyCode);
};

