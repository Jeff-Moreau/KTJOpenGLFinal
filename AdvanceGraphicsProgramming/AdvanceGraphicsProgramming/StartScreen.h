#pragma once
#include "Screen.h"
#include "Sprite.h"
#include "Font.h"
#include "glm/glm.hpp"

class StartScreen : public Screen
{
private:
	Sprite* background;
	Shader shader;
	Shader fontShader;
	Font* testFont;

public:
	StartScreen();
	~StartScreen();

	void Update();
	void Render();
};

