#include "ScreenManager.h"

ScreenManager* ScreenManager::p_ThisInstance = nullptr;

// SINGLETON START
ScreenManager* ScreenManager::Instance()
{
	if (p_ThisInstance == nullptr)
	{
		p_ThisInstance = new ScreenManager();
	}

	return p_ThisInstance;
}
// SINGLETON END

ScreenManager::ScreenManager()
{
	p_Screens.push_back(new StartScreen());
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

void ScreenManager::Update()
{
	p_Screens[(int)_CurrentScreen]->Update();
}

void ScreenManager::Render()
{
	p_Screens[(int)_CurrentScreen]->Render();
}

void ScreenManager::Release()
{
	delete p_ThisInstance;
	p_ThisInstance = nullptr;
}