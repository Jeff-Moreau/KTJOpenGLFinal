#include "GameManager.h"

GameManager* GameManager::p_ThisInstance = nullptr;

GameManager* GameManager::Load()
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
	_Event.type = SDL_FIRSTEVENT;

	stbi_set_flip_vertically_on_load(true);

	p_GraphicsManager = GraphicsManager::Load();
	p_ScreenManager = ScreenManager::Load();
}

GameManager::~GameManager()
{
	GraphicsManager::UnLoad();
}

void GameManager::Run()
{
	while (!glfwWindowShouldClose(GraphicsManager::Use()->GetWindow()))
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
		Render();
		glfwPollEvents();
	}
}

void GameManager::Update()
{
	p_ScreenManager->Update();
}

void GameManager::Render()
{
	p_ScreenManager->Render();
	glfwSwapBuffers(GraphicsManager::Use()->GetWindow());
}

void GameManager::UnLoad()
{
	delete p_ThisInstance;
	p_ThisInstance = nullptr;
}