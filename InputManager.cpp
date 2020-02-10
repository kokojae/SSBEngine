#include "InputManager.h"
#include <Windows.h>

std::vector<KeyState*> InputManager::keyStateVector = std::vector<KeyState*>();

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Init()
{
	keyStateVector.resize(static_cast<int>(KeyCode::MAX));
	AddKey(KeyCode::W, 'W');
	AddKey(KeyCode::A, 'A');
	AddKey(KeyCode::S, 'S');
	AddKey(KeyCode::D, 'D');
}

void InputManager::Update()
{
	for (auto key : keyStateVector)
	{
		key->isUp = key->isDown = false;
		if (GetAsyncKeyState(key->vkCode) & 0x8000)
		{

			if (!key->isOn)
			{
				key->isDown = true;
			}
			key->isOn = true;
		}
		else
		{
			if (!key->isOn)
			{
				key->isUp = true;
			}
			key->isOn = false;
		}
	}
}

void InputManager::AddKey(KeyCode keyCode, int vkCode)
{
	keyStateVector[static_cast<int>(keyCode)] = new KeyState(vkCode);
}

bool InputManager::GetKey(KeyCode keyCode)
{
	return keyStateVector[static_cast<int>(keyCode)]->isOn;
}

bool InputManager::GetKeyDown(KeyCode keyCode)
{
	return keyStateVector[static_cast<int>(keyCode)]->isDown;
}

bool InputManager::GetKeyUp(KeyCode keyCode)
{
	return keyStateVector[static_cast<int>(keyCode)]->isUp;
}

KeyState::KeyState() :vkCode(0), isOn(false), isDown(false), isUp(false)
{
}

KeyState::KeyState(int vkCode) : vkCode(vkCode), isOn(false), isDown(false), isUp(false)
{
}

KeyState::~KeyState()
{
}
