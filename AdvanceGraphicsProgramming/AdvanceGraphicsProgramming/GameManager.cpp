#include "GameManager.h"

GameManager* GameManager::sInstance = nullptr;

GameManager* GameManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new GameManager();
	}

	return sInstance;
}

void GameManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

GameManager::GameManager() {
	stbi_set_flip_vertically_on_load(true);
	pGraphics = GraphicsManager::Instance();
	pScreenManager = ScreenManager::Instance();
	//camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

GameManager::~GameManager() {
	GraphicsManager::Release();
}

void GameManager::Run() {
	// Game Loop
	while (!glfwWindowShouldClose(GraphicsManager::Instance()->GetWindow())) {
		Update();
		LateUpdate();
		Render();

		glfwPollEvents();
	}
}

void GameManager::Update() {
	pScreenManager->Update();
}

void GameManager::LateUpdate() {

}

void GameManager::Render() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	pScreenManager->Render();
	glfwSwapBuffers(GraphicsManager::Instance()->GetWindow());
}
