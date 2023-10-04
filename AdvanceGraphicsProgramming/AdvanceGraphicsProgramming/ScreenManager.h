#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include "StartScreen.h"
#include "PlayScreen.h"

class ScreenManager
{
public: // ACCESSABLE VARIABLE DECLARATIONS
	enum Screens
	{
		Start,
		Play
	};

private: // MEMBER CONTAINER DECLARATIONS
	std::vector<Screen*> p_Screens;

private: // MEMBER VARIABLE DECLARATIONS
	Screens _CurrentScreen;

private: // SINGLETON
	static ScreenManager* p_ThisInstance;

public: // SINGLETON
	static ScreenManager* Load();

private: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
	ScreenManager();
	~ScreenManager();

public: // SETTERS
	void SetCurrentScreen(Screens newScreen);

public: // DOERS
	void Update();
	void Render();

public: // CLEANUP
	static void UnLoad();
};
#endif // !SCREEN_MANAGER_H