#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "GraphicsManager.h"
#include "ScreenManager.h"
#include "InputManager.h"
#include "Shader.h"
#include "Sprite.h"
#include "Camera.h"

class GameManager
{
private: // MEMBER POINTER VARIABLE DECLARATIONS
	GraphicsManager* p_GraphicsManager;
	ScreenManager* p_ScreenManager;
	InputManager* p_Inputs;

private: // MEMBER VARIABLE DECLARATIONS
	Camera _Camera;
	glm::vec3 _CameraPos;
	glm::vec3 _CameraFront;
	glm::vec3 _CameraUp;

	bool _ExitGame;
	SDL_Event _Event;

private: // SINGLETON
	static GameManager* p_ThisInstance;

public: // SINGLETON
	static GameManager* Instance();

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	GameManager();
	~GameManager();

public: // DOERS
	void Run();
	void Update();
	void LateUpdate();
	void Render();

public: // CLEANUP
	static void Release();
};
#endif // !GAME_MANAGER_H