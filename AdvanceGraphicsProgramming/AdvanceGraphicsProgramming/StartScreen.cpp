#include "StartScreen.h"


StartScreen::StartScreen()
{
	// MEMBER VARIABLE AND POINTERS INSTANTIATION
	p_Inputs = InputManager::Instance();

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
	std::cout << p_Inputs->GetMousePosition().x << std::endl;
	if ((p_Inputs->GetMousePosition().x >= p_MenuFont->GetFontPosition().x))
	{
		_ExitColor = glm::vec3(0, 0, 0);
	}
	else
	{
		_ExitColor = glm::vec3(255, 255, 255);
	}
}

void StartScreen::Render()
{
	p_BackGroundImage->Render();
	p_MenuFont->RenderText("Start New Game", 285, 275, 0.5f, glm::vec3(255,255,255));
	p_MenuFont->RenderText("Exit Game", 575, 25, 0.75f, _ExitColor);
}
