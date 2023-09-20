#include "StartScreen.h"


StartScreen::StartScreen()
{
	// MEMBER VARIABLE AND POINTERS INSTANTIATION
	p_Inputs = InputManager::Instance();

	_Shader = Shader("Assets/Shaders/texture.vs", "Assets/Shaders/texture.fs");
	p_BackGroundImage = new Sprite("Assets/Textures/KTJBackground.png", _Shader);

	_FontShader = Shader("Assets/Shaders/Font.vs", "Assets/Shaders/Font.fs");
	p_NewGame = new Font("Assets/Fonts/Starjedi.ttf", _FontShader);
	p_ExitGame = new Font("Assets/Fonts/Starjedi.ttf", _FontShader);
}

StartScreen::~StartScreen()
{
	delete p_BackGroundImage;
	p_BackGroundImage = nullptr;

	delete p_NewGame;
	p_NewGame = nullptr;
}

void StartScreen::Update()
{

}

void StartScreen::Render()
{
	p_BackGroundImage->Render();
	p_NewGame->RenderText("Start New Game", 285, 275, 0.5f, glm::vec3(255,255,255));
	p_ExitGame->RenderText("Exit Game", 575, 25, 0.75f, _ExitColor);
}