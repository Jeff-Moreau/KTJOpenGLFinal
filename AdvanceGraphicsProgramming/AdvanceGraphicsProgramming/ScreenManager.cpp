#include "ScreenManager.h"

ScreenManager* ScreenManager::p_ThisInstance = nullptr;

ScreenManager* ScreenManager::Instance()
{
	if (p_ThisInstance == nullptr)
	{
		p_ThisInstance = new ScreenManager();
	}

	return p_ThisInstance;
}

ScreenManager::ScreenManager()
{
	p_Screens.push_back(new StartScreen());
	p_Screens.push_back(new PlayScreen());
	_CurrentScreen = Start;
}

ScreenManager::~ScreenManager()
{
	for (int i = 0; i < p_Screens.size(); i++)
	{
		delete p_Screens[i];
		p_Screens[i] = nullptr;
	}
}

void ScreenManager::SetCurrentScreen(Screens newScreen)
{
	_CurrentScreen = newScreen;
}

void ScreenManager::Update()
{
	p_Screens[(int)_CurrentScreen]->Update();
}

void ScreenManager::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	p_Screens[(int)_CurrentScreen]->Render();
}

void ScreenManager::Release()
{
	delete p_ThisInstance;
	p_ThisInstance = nullptr;
}