#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include "StartScreen.h"
#include "PlayScreen.h"
#include <vector>

class ScreenManager
{
public: // GLOBAL VARIABLE DECLARATIONS
	enum Screens
	{
		Start,
		Play
	};

private: // MEMBER CONTAINER DECLARATIONS
	std::vector<Screen*> p_Screens;

private: // MEMBER VARIABLE DECLARATIONS
	Screens _CurrentScreen; // <-- used to determine which screens needs to be render and updating

private: // SINGLETON
	static ScreenManager* p_ThisInstance;

public:// SINGLETON
	static ScreenManager* Instance();

private: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	ScreenManager();
	~ScreenManager();

public: // SETTERS
	void SetCurrentScreen(Screens newScreen);

public: // DOERS
	void Update();
	void Render();
	static void Release();
};
#endif // !SCREEN_MANAGER_H