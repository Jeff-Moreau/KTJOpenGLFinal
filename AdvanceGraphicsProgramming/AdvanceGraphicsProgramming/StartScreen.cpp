#include "StartScreen.h"

StartScreen::StartScreen()
{
	_Shader = Shader("Assets/Shaders/texture.vs", "Assets/Shaders/texture.fs");
	p_BackGroundImage = new Sprite("Assets/Textures/KTJBackground.png", _Shader);

	_FontShader = Shader("Assets/Shaders/Font.vs", "Assets/Shaders/Font.fs");
	p_MenuFont = new Font("Assets/Fonts/Starjedi.ttf", _FontShader);
}

StartScreen::~StartScreen()
{
	delete p_BackGroundImage;
	p_BackGroundImage = nullptr;

	delete p_MenuFont;
	p_MenuFont = nullptr;
}

void StartScreen::Update()
{

}

void StartScreen::Render()
{
	p_BackGroundImage->Render();
	p_MenuFont->RenderText("Start New Game", 225, 300, 0.75f, glm::vec3(255,255,255));
	p_MenuFont->RenderText("Exit Game", 300, 250, 0.75f, glm::vec3(255, 255, 255));
}
