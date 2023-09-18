#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GraphicsManager.h"
#include "ScreenManager.h"
#include "Shader.h"
#include "Sprite.h"
#include "Camera.h"

class GameManager
{
private:
	static GameManager* sInstance;

	GraphicsManager* pGraphics;
	ScreenManager* pScreenManager;
	Camera camera;

	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;

public:
	static GameManager* Instance();
	static void Release();

	void Run();
	void Update();
	void LateUpdate();
	void Render();

	GameManager();
	~GameManager();
};
#endif // !GAMEMANAGER_H