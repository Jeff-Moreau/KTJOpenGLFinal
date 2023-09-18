#include "StartScreen.h"

StartScreen::StartScreen()
{
	shader = Shader("Assets/Shaders/texture.vs", "Assets/Shaders/texture.fs");
	background = new Sprite("Assets/Textures/container.jpg", shader);
	fontShader = Shader("Assets/Shaders/Font.vs", "Assets/Shaders/Font.fs");
	testFont = new Font("Assets/Fonts/Antonio-Bold.ttf", fontShader);
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
	testFont->RenderText("Hello World!!", 50, 400, 2, glm::vec3(255,255,255));
}
