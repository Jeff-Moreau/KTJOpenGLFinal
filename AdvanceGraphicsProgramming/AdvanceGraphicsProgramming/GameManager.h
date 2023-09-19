#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "GraphicsManager.h"
#include "ScreenManager.h"
#include "Shader.h"
#include "Sprite.h"
#include "Camera.h"

class GameManager
{
private: // SINGLETON
	static GameManager* p_ThisInstance;

private: // POINTER VARIABLES
	GraphicsManager* p_GraphicsManager;
	ScreenManager* p_ScreenManager;

private: // VARIABLES
	Camera _Camera;
	glm::vec3 _CameraPos;
	glm::vec3 _CameraFront;
	glm::vec3 _CameraUp;

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
	static void Release();
};
#endif // !GAME_MANAGER_H