#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "InputManager.h"
#include "Screen.h"
#include "Sprite.h"
#include "Font.h"
#include "glm/glm.hpp"

using namespace SDLFramework;

class StartScreen : public Screen
{
private: // LOCAL POINTER VARIABLES
	InputManager* p_Inputs;
	Sprite* p_BackGroundImage;
	Font* p_MenuFont;

private: // LOCAL VARIABLES
	Shader _Shader;
	Shader _FontShader;

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	StartScreen();
	~StartScreen();

public: // DOERS
	void Update();
	void Render();
};
#endif // !START_SCREEN_H