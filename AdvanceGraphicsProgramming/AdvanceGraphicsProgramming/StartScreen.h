#ifndef START_SCREEN_H
#define START_SCREEN_H

// PROJECT INCLUDES
#include "Screen.h"

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

public: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
	StartScreen();
	~StartScreen();

public: // DOERS
	void Update();
	void Render();

private: // DOERS
	void HoverText(Font* font, glm::vec3& textColor, glm::vec3 hoverColor, glm::vec3 restColor, bool& hover);
};
#endif // !START_SCREEN_H