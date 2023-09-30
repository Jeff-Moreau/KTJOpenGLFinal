#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "Screen.h"
#include "Shader.h"

using namespace SDLFramework;

class StartScreen : public Screen
{
private: // MEMBER POINTER VARIABLE DECLARATIONS
	AudioManager* p_SoundFX;
	Image* p_BackGroundImage;
	Font* p_ExitGame;
	Font* p_NewGame;

private: // MEMBER VARIABLE DECLARATIONS
	glm::vec3 _ExitColor;
	glm::vec3 _StartColor;
	bool _HoverExitGame;
	bool _HoverNewGame;
	int _HoverNewGameSound;

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	StartScreen();
	~StartScreen();

public: // DOERS
	void Update();
	void Render();
};
#endif // !START_SCREEN_H