#include "GameManager.h"

GameManager* GameManager::p_ThisInstance = nullptr;
// SINGLETON START
GameManager* GameManager::Instance()
{
	if (p_ThisInstance == nullptr)
	{
		p_ThisInstance = new GameManager();
	}

	return p_ThisInstance;
}
// SINGLETON END


GameManager::GameManager()
{
	stbi_set_flip_vertically_on_load(true);

	// MEMBER POINTER VARIABLE INSTANTIATION
	p_GraphicsManager = GraphicsManager::Instance();
	p_ScreenManager = ScreenManager::Instance();
	//camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

GameManager::~GameManager()
{
	GraphicsManager::Release();
}

void GameManager::Run()
{
	// Game Loop
	while (!glfwWindowShouldClose(GraphicsManager::Instance()->GetWindow()))
	{
		Update();
		LateUpdate();
		Render();
		glfwPollEvents();
	}
}

void GameManager::Update()
{
	p_ScreenManager->Update();
}

void GameManager::LateUpdate()
{

}

void GameManager::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	p_ScreenManager->Render();
	glfwSwapBuffers(GraphicsManager::Instance()->GetWindow());
}

void GameManager::Release()
{
	delete p_ThisInstance;
	p_ThisInstance = nullptr;
}