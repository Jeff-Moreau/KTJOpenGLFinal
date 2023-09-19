#include "StartScreen.h"

StartScreen::StartScreen()
{
	shader = Shader("Assets/Shaders/texture.vs", "Assets/Shaders/texture.fs");
	background = new Sprite("Assets/Textures/KTJBackground.png", shader);
	fontShader = Shader("Assets/Shaders/Font.vs", "Assets/Shaders/Font.fs");
	testFont = new Font("Assets/Fonts/Starjedi.ttf", fontShader);
}

StartScreen::~StartScreen()
{
	delete background;
	background = nullptr;

	delete testFont;
	testFont = nullptr;
}

void StartScreen::Update()
{

}

void StartScreen::Render()
{
	background->Render();
	testFont->RenderText("Start New Game", 225, 300, 0.75f, glm::vec3(255,255,255));
	testFont->RenderText("Exit Game", 300, 250, 0.75f, glm::vec3(255, 255, 255));
}
