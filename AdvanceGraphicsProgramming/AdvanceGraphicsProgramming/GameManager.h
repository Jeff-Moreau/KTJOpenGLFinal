#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GraphicsManager.h"
#include "ScreenManager.h"
#include "Shader.h"
#include "Sprite.h"
#include "Camera.h"

class GameManager
{
private: // SINGLETON
	static GameManager* sInstance;

private: // POINTER VARIABLES
	GraphicsManager* pGraphics;
	ScreenManager* pScreenManager;

private: // VARIABLES
	Camera camera;
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

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
#endif // !GAMEMANAGER_H