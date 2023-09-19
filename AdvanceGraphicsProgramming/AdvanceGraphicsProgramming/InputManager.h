#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "MathHelper.h"
#include "SDL2/SDL.h"
#include <string>

namespace SDLFramework
{
	class InputManager
	{
	public: // GLOBAL VARIABLES
		enum MouseButton
		{
			Left = 0,
			Right,
			Middle,
			Back,
			Forward
		};

	private: // LOCAL POINTER VARIABLES
		const Uint8* p_CurrentKeyPressed;
		Uint8* p_PreviousKeyPressed;

	private: // LOCAL VARIABLES
		Uint32 _CurrentMouseKeyPressed;
		Uint32 _PreviousMouseKeyPressed;
		int _KeyPressed;
		int _CurrentMouseXPos;
		int _CurrentMouseYPos;

	private: // SINGLETON
		static InputManager* p_ThisInstance;

	public: // SINGLETON
		static InputManager* Instance();

	private: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
		InputManager();
		~InputManager();

	public: // GETTERS
		bool GetKeyDown(SDL_Scancode scancode);
		bool GetKeyPressed(SDL_Scancode scancode);
		bool GetKeyReleased(SDL_Scancode scancode);

		bool GetMouseButtonDown(MouseButton button);
		bool GetMouseButtonPressed(MouseButton button);
		bool GetMouseButtonReleased(MouseButton button);

		Vector2 GetMousePosition();

	public: // DOERS
		void Update();
		void UpdatePrevInput();
		static void Release();
	};
}
#endif // !INPUT_MANAGER_H