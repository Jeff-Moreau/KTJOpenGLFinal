#include "PlayScreen.h"
#include "ScreenManager.h"

PlayScreen::PlayScreen()
{
	p_SoundFX = AudioManager::Instance();

    p_BackGroundImage = new Image("Assets/Textures/TheBackground.png", GraphicsManager::Instance()->TextureShader);
	p_CurtainsImage = new Image("Assets/Textures/Curtains.png", GraphicsManager::Instance()->TextureShader);

    p_Score = new Font("Assets/Fonts/Starjedi.ttf", 24, GraphicsManager::Instance()->FontShader);
	p_ScoreTotal = new Font("Assets/Fonts/Starjedi.ttf", 24, GraphicsManager::Instance()->FontShader);
    p_Round = new Font("Assets/Fonts/Starjedi.ttf", 24, GraphicsManager::Instance()->FontShader);
    p_MainMenu = new Font("Assets/Fonts/Starjedi.ttf", 32, GraphicsManager::Instance()->FontShader);

	for (int i = 0; i < 4; i++)
	{
		p_JarJarHeadsRowOne.push_back(new Model("Assets/Models/CubeJarJar.obj"));
	}
	for (int i = 0; i < 3; i++)
	{
		p_JarJarHeadsRowTwo.push_back(new Model("Assets/Models/CubeJarJar.obj"));
		p_JarJarHeadsRowThree.push_back(new Model("Assets/Models/CubeJarJar.obj"));
	}

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

	for (int i = 0; i < p_JarJarHeadsRowOne.size(); i++)
	{
		delete p_JarJarHeadsRowOne[i];
		p_JarJarHeadsRowOne[i] = nullptr;
	}
	for (int i = 0; i < p_JarJarHeadsRowTwo.size(); i++)
	{
		delete p_JarJarHeadsRowTwo[i];
		p_JarJarHeadsRowTwo[i] = nullptr;
		delete p_JarJarHeadsRowThree[i];
		p_JarJarHeadsRowThree[i] = nullptr;
	}
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

	GraphicsManager::Instance()->ModelShader.Use();

	float randNum = (rand() % ((80 - 30) + 1) + 30);
	float angle = glfwGetTime() * 200;
	float newPosition = -9.0f;
	float bounce = glfwGetTime() * 2;
	bool first = true;

	for (int i = 0; i < p_JarJarHeadsRowOne.size(); i++)
	{
		p_JarJarHeadsRowOne[i]->SetPerspective(45);
		p_JarJarHeadsRowOne[i]->SetRotation(angle, glm::vec3(0.0f, 1.0f, 0.0f));
		if (!first)
		{
			p_JarJarHeadsRowOne[i]->SetPosition(glm::vec3(newPosition += 6.0f, 4.5f, -30.0f));
		}
		else
		{
			p_JarJarHeadsRowOne[i]->SetPosition(glm::vec3(newPosition, 4.5f, -30.0f));
		}
		p_JarJarHeadsRowOne[i]->Draw(GraphicsManager::Instance()->ModelShader);
		first = false;
	}

	newPosition = -7.5f;
	for (int i = 0; i < p_JarJarHeadsRowTwo.size(); i++)
	{
		p_JarJarHeadsRowTwo[i]->SetPerspective(45);
		p_JarJarHeadsRowTwo[i]->SetRotation(angle, glm::vec3(0.0f, 1.0f, 0.0f));
		if (!first)
		{
			p_JarJarHeadsRowTwo[i]->SetPosition(glm::vec3(newPosition += 4.0f, 0.0f, -20.0f));
		}
		else
		{
			p_JarJarHeadsRowTwo[i]->SetPosition(glm::vec3(newPosition, 0.0f, -20.0f));
		}
		p_JarJarHeadsRowTwo[i]->Draw(GraphicsManager::Instance()->ModelShader);
		first = false;
	}

	newPosition = -7.0f;
	for (int i = 0; i < p_JarJarHeadsRowThree.size(); i++)
	{
		p_JarJarHeadsRowThree[i]->SetPerspective(45);
		p_JarJarHeadsRowThree[i]->SetRotation(angle, glm::vec3(0.0f, 1.0f, 0.0f));
		if (!first)
		{
			p_JarJarHeadsRowThree[i]->SetPosition(glm::vec3(newPosition += 3.5f, -3.2f, -13.0f));
		}
		else
		{
			p_JarJarHeadsRowThree[i]->SetPosition(glm::vec3(newPosition, -3.2f, -13.0f));
		}
		p_JarJarHeadsRowThree[i]->Draw(GraphicsManager::Instance()->ModelShader);
		first = false;
	}

	p_CurtainsImage->Render();

    p_Score->RenderText("Score :", 40, 57, 1, glm::vec3(0,0,0));
	p_ScoreTotal->RenderText(std::to_string(_NewTime), 150, 57, 1, glm::vec3(0, 0, 0));

    p_Round->RenderText("Round :", 590, 57, 1, glm::vec3(0, 0, 0));
    p_MainMenu->RenderText("Main Menu", (GraphicsManager::Instance()->SCREEN_WIDTH / 2) - (p_MainMenu->TextWidth / 2), 10, 1, _MainMenuColor);
}