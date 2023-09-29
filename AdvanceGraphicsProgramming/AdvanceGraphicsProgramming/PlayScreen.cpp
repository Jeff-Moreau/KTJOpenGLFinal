﻿#include "PlayScreen.h"
#include "ScreenManager.h"

PlayScreen::PlayScreen()
{
	p_SoundFX = AudioManager::Instance();

    p_BackGroundImage = new Image("Assets/Textures/TheBackground.png");
	p_CurtainsImage = new Image("Assets/Textures/Curtains.png");

    p_Score = new Font("Assets/Fonts/Starjedi.ttf", 24);
	p_ScoreTotal = new Font("Assets/Fonts/Starjedi.ttf", 24);
    p_Round = new Font("Assets/Fonts/Starjedi.ttf", 24);
    p_MainMenu = new Font("Assets/Fonts/Starjedi.ttf", 32);

	//_3DShader = Shader("Assets/Shaders/3DTexture.vs", "Assets/Shaders/3DTexture.fs");
	p_Tammy = new Model("Assets/Models/CubeJarJar.obj");
	_TimerReset = true;
	_Time = 0;
	_NewTime = 0;
}

PlayScreen::~PlayScreen()
{
	delete p_BackGroundImage;
	p_BackGroundImage = nullptr;

	delete p_CurtainsImage;
	p_CurtainsImage = nullptr;

	delete p_Score;
	p_Score = nullptr;

	delete p_ScoreTotal;
	p_ScoreTotal = nullptr;

	delete p_Round;
	p_Round = nullptr;

	delete p_MainMenu;
	p_MainMenu = nullptr;

	delete p_Tammy;
	p_Tammy = nullptr;
}

void PlayScreen::Update()
{
	if (_TimerReset)
	{
		_Time = 0;
		_NewTime = 0;
		_TimerReset = false;
	}
	_Time = glfwGetTime();
	_NewTime = trunc(_Time);
	
	int buttonstate = glfwGetMouseButton(GraphicsManager::Instance()->GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
	glfwGetCursorPos(GraphicsManager::Instance()->GetWindow(), &_MouseX, &_MouseY);

	if ((_MouseY < ((GraphicsManager::Instance()->SCREEN_HEIGHT - p_MainMenu->GetFontPosition().y) - p_MainMenu->TextHeight) + p_MainMenu->TextHeight) && (_MouseY > (GraphicsManager::Instance()->SCREEN_HEIGHT - p_MainMenu->GetFontPosition().y) - p_MainMenu->TextHeight))
	{
		if ((_MouseX > p_MainMenu->GetFontPosition().x) && (_MouseX < p_MainMenu->GetFontPosition().x + p_MainMenu->TextWidth))
		{
			_MainMenuColor = glm::vec3(255, 0, 0);
			_HoverMainMenu = true;
		}
		else
		{
			_HoverMainMenu = false;
			_MainMenuColor = glm::vec3(0, 0, 0);
		}
	}
	else
	{
		_HoverMainMenu = false;
		_MainMenuColor = glm::vec3(0, 0, 0);
	}

	if (buttonstate == GLFW_PRESS && _HoverMainMenu)
	{
		p_SoundFX->PlaySFX("CursorMovementSFX.mp3");
		ScreenManager::Instance()->SetCurrentScreen(ScreenManager::Instance()->Start);
		_TimerReset = true;
		_Time = 0;
		_NewTime = 0;
		std::cout << "Main Menu" << std::endl;
	}
}

void PlayScreen::Render()
{
    p_BackGroundImage->Render();
	//p_Tammy->Draw(_3DShader);
	p_CurtainsImage->Render();
    p_Score->RenderText("Score :", 40, 57, 1, glm::vec3(0,0,0));
	p_ScoreTotal->RenderText(std::to_string(_NewTime), 150, 57, 1, glm::vec3(0, 0, 0));
    p_Round->RenderText("Round :", 590, 57, 1, glm::vec3(0, 0, 0));
    p_MainMenu->RenderText("Main Menu", (GraphicsManager::Instance()->SCREEN_WIDTH / 2) - (p_MainMenu->TextWidth / 2), 10, 1, _MainMenuColor);
}