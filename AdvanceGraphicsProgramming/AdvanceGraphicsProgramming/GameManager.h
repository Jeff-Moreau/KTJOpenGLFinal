#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

// PROJECT INCLUDES
#include "GraphicsManager.h"
#include "ScreenManager.h"

class GameManager
{
private: // MEMBER POINTER VARIABLE DECLARATIONS
	GraphicsManager* p_GraphicsManager;
	ScreenManager* p_ScreenManager;

private: // MEMBER VARIABLE DECLARATIONS
	bool _ExitGame;
	SDL_Event _Event;

private: // SINGLETON
	static GameManager* p_ThisInstance;

public: // SINGLETON
	static GameManager* Load();

public: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
	GameManager();
	~GameManager();

public: // DOERS
	void Run();
	void Update();
	void Render();

public: // CLEANUP
	static void UnLoad();
};
#endif // !GAME_MANAGER_H