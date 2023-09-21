#include "StartScreen.h"


StartScreen::StartScreen()
{
	_HoverExitGame = false;
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
	glfwGetCursorPos(GraphicsManager::Instance()->GetWindow(), &_MouseX, &_MouseY);

	//std::cout << _MouseY << std::endl;
	std::cout << (((GraphicsManager::Instance()->SCREEN_HEIGHT - p_ExitGame->GetFontPosition().y) - 30) + p_ExitGame->TextHeight) << std::endl;

	if ((_MouseY < ((GraphicsManager::Instance()->SCREEN_HEIGHT - p_ExitGame->GetFontPosition().y) - 30) + p_ExitGame->TextHeight) && (_MouseY > (GraphicsManager::Instance()->SCREEN_HEIGHT - p_ExitGame->GetFontPosition().y) - 30))
	{
		if ((_MouseX > p_ExitGame->GetFontPosition().x) && (_MouseX < p_ExitGame->GetFontPosition().x + 210))
		{
			_ExitColor = glm::vec3(255,0,0);
			_HoverExitGame = true;
		}
		else
		{
			_HoverExitGame = false;
			_ExitColor = glm::vec3(0, 0, 0);
		}
	}
	else
	{
		_HoverExitGame = false;
		_ExitColor = glm::vec3(0, 0, 0);
	}
	
	int state = glfwGetMouseButton(GraphicsManager::Instance()->GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
	if (state == GLFW_PRESS && _HoverExitGame)
	{
		std::cout << "StartGame now" << std::endl;
	}
}

void StartScreen::Render()
{
	p_BackGroundImage->Render();
	p_NewGame->RenderText("Start New Game", 285, 275, 0.5f, glm::vec3(255,255,255));
	p_ExitGame->RenderText("Exit Game", 575, 25, 0.75f, _ExitColor);
}