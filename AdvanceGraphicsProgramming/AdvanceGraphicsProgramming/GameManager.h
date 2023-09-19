#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "GraphicsManager.h"
#include "ScreenManager.h"
#include "Shader.h"
#include "Sprite.h"
#include "Camera.h"

class GameManager
{
private: // LOCAL POINTER VARIABLES
	GraphicsManager* p_GraphicsManager;
	ScreenManager* p_ScreenManager;

private: // LOCAL VARIABLES
	Camera _Camera;
	glm::vec3 _CameraPos;
	glm::vec3 _CameraFront;
	glm::vec3 _CameraUp;

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
	static void Release();
};
#endif // !GAME_MANAGER_H