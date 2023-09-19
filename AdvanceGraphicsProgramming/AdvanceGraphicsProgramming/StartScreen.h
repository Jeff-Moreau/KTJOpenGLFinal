#pragma once
#include "Screen.h"
#include "Sprite.h"
#include "Font.h"
#include "glm/glm.hpp"

class StartScreen : public Screen
{
private: // LOCAL POINTER VARIABLES
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

