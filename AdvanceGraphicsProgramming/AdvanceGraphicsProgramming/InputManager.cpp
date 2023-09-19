#include "InputManager.h"

namespace SDLFramework
{
	InputManager* InputManager::p_ThisInstance = nullptr;

	// SINGLETON START
	InputManager* InputManager::Instance()
	{
		if (p_ThisInstance == nullptr)
		{
			p_ThisInstance = new InputManager();
		}

		return p_ThisInstance;
	}
	// SINGLETON END

	InputManager::InputManager()
	{
		p_CurrentKeyPressed = SDL_GetKeyboardState(&_KeyPressed);
		p_PreviousKeyPressed = new Uint8[_KeyPressed];
		memcpy(p_PreviousKeyPressed, p_CurrentKeyPressed, _KeyPressed);
	}

	InputManager::~InputManager()
	{
		delete[] p_PreviousKeyPressed;
		p_PreviousKeyPressed = nullptr;
	}

	bool InputManager::GetKeyDown(SDL_Scancode scancode)
	{
		return p_CurrentKeyPressed[scancode];
	}

	bool InputManager::GetKeyPressed(SDL_Scancode scancode)
	{
		return !p_PreviousKeyPressed[scancode] && p_CurrentKeyPressed[scancode];
	}

	bool InputManager::GetKeyReleased(SDL_Scancode scancode)
	{
		return p_PreviousKeyPressed[scancode] && !p_CurrentKeyPressed[scancode];
	}

	bool InputManager::GetMouseButtonDown(MouseButton button)
	{
		Uint32 mask = 0;

		switch (button)
		{
			case Left:
				mask = SDL_BUTTON_LMASK;
				break;

			case Right:
				mask = SDL_BUTTON_RMASK;
				break;

			case Middle:
				mask = SDL_BUTTON_MMASK;
				break;

			case Back:
				mask = SDL_BUTTON_X1MASK;
				break;

			case Forward:
				mask = SDL_BUTTON_X2MASK;
				break;
		}
		return (_CurrentMouseKeyPressed & mask) != 0;
	}

	bool InputManager::GetMouseButtonPressed(MouseButton button)
	{
		Uint32 mask = 0;

		switch (button)
		{
			case Left:
				mask = SDL_BUTTON_LMASK;
				break;

			case Right:
				mask = SDL_BUTTON_RMASK;
				break;

			case Middle:
				mask = SDL_BUTTON_MMASK;
				break;

			case Back:
				mask = SDL_BUTTON_X1MASK;
				break;

			case Forward:
				mask = SDL_BUTTON_X2MASK;
				break;
		}
		return !(_PreviousMouseKeyPressed & mask) && (_CurrentMouseKeyPressed & mask);
	}

	bool InputManager::GetMouseButtonReleased(MouseButton button)
	{
		Uint32 mask = 0;

		switch (button)
		{
			case Left:
				mask = SDL_BUTTON_LMASK;
				break;

			case Right:
				mask = SDL_BUTTON_RMASK;
				break;

			case Middle:
				mask = SDL_BUTTON_MMASK;
				break;

			case Back:
				mask = SDL_BUTTON_X1MASK;
				break;

			case Forward:
				mask = SDL_BUTTON_X2MASK;
				break;
		}
		return (_PreviousMouseKeyPressed & mask) && !(_CurrentMouseKeyPressed & mask);
	}

	Vector2 InputManager::GetMousePosition()
	{
		return Vector2((float)_CurrentMouseXPos, (float)_CurrentMouseYPos);
	}

	void InputManager::Update()
	{
		_CurrentMouseKeyPressed = SDL_GetMouseState(&_CurrentMouseXPos, &_CurrentMouseYPos);
	}

	void InputManager::UpdatePrevInput()
	{
		memcpy(p_PreviousKeyPressed, p_CurrentKeyPressed, _KeyPressed);
		_PreviousMouseKeyPressed = _CurrentMouseKeyPressed;
	}

	void InputManager::Release()
	{
		delete p_ThisInstance;
		p_ThisInstance = nullptr;
	}
}
