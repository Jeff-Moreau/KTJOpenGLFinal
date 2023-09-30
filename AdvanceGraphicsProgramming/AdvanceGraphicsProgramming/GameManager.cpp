#include "GameManager.h"

GameManager* GameManager::p_ThisInstance = nullptr;

GameManager* GameManager::Instance()
{
	if (p_ThisInstance == nullptr)
	{
		p_ThisInstance = new GameManager();
	}

	return p_ThisInstance;
}


GameManager::GameManager()
{
	_ExitGame = false;

	stbi_set_flip_vertically_on_load(true);

	p_GraphicsManager = GraphicsManager::Instance();
	p_ScreenManager = ScreenManager::Instance();
}

GameManager::~GameManager()
{
	GraphicsManager::Release();
}

void GameManager::Run()
{
	while (!glfwWindowShouldClose(GraphicsManager::Instance()->GetWindow()))
	{
		while (SDL_PollEvent(&_Event))
		{
			switch (_Event.type)
			{
			case SDL_QUIT:
				_ExitGame = true;
				break;
			}
		}
		Update();
		LateUpdate();
		Render();
		glfwPollEvents();
	}
}

void GameManager::Update()
{
	if (glfwGetKey(GraphicsManager::Instance()->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(GraphicsManager::Instance()->GetWindow(), true);
	}

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