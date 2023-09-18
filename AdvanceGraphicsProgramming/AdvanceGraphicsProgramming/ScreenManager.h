#pragma once

#include "StartScreen.h"
#include <vector>

class ScreenManager
{
public:
	enum Screens { Start, Play};

private:
	static ScreenManager* sInstance;
	std::vector<Screen*> m_pScreens;
	Screens mCurrentScreen; // <-- used to determine which screens needs to be render and updating

public:
	static ScreenManager* Instance();
	static void Release();

private:
	ScreenManager();
	~ScreenManager();

public:

	void Update();
	void Render();
};



