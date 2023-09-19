#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include "StartScreen.h"
#include <vector>

class ScreenManager
{
public: // GLOBALS
	enum Screens
	{
		Start,
		Play
	};

private: // SINGLETON
	static ScreenManager* p_ThisInstance;

private: // CONTAINERS
	std::vector<Screen*> p_Screens;

private: // VARIABLES
	Screens _CurrentScreen; // <-- used to determine which screens needs to be render and updating

public:// SINGLETON
	static ScreenManager* Instance();

private: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	ScreenManager();
	~ScreenManager();

public: // DOERS
	void Update();
	void Render();
	static void Release();
};
#endif // !SCREEN_MANAGER_H