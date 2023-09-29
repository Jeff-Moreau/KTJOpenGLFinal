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
	//stbi_set_flip_vertically_on_load(true);
	_ExitGame = false;
	p_GraphicsManager = GraphicsManager::Instance();
	p_Inputs = InputManager::Instance();
	p_ScreenManager = ScreenManager::Instance();
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

	p_Inputs->Update();
	p_ScreenManager->Update();
}

void GameManager::LateUpdate()
{
	p_Inputs->UpdatePrevInput();
}

void GameManager::Render()
{
	p_ScreenManager->Render();
	glfwSwapBuffers(GraphicsManager::Instance()->GetWindow());
}

void GameManager::Release()
{
	delete p_ThisInstance;
	p_ThisInstance = nullptr;
}