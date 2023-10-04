#include "PlayScreen.h"
#include "ScreenManager.h"

PlayScreen::PlayScreen()
{
	p_SoundFX = AudioManager::Load();

    p_BackGroundImage = new Image("Assets/Textures/TheBackground.png", GraphicsManager::Load()->TextureShader);
	p_CurtainsImage = new Image("Assets/Textures/Curtains.png", GraphicsManager::Load()->TextureShader);

    p_Score = new Font("Assets/Fonts/Starjedi.ttf", 24, GraphicsManager::Load()->FontShader);
	p_ScoreTotal = new Font("Assets/Fonts/Starjedi.ttf", 24, GraphicsManager::Load()->FontShader);
    p_Round = new Font("Assets/Fonts/Starjedi.ttf", 24, GraphicsManager::Load()->FontShader);
    p_MainMenu = new Font("Assets/Fonts/Starjedi.ttf", 32, GraphicsManager::Load()->FontShader);

	for (int i = 0; i < 4; i++)
	{
		p_JarJarHeadsRowOne.push_back(new Model("Assets/Models/CubeJarJar.obj"));
	}
	for (int i = 0; i < 3; i++)
	{
		p_JarJarHeadsRowTwo.push_back(new Model("Assets/Models/CubeJarJar.obj"));
		p_JarJarHeadsRowThree.push_back(new Model("Assets/Models/CubeJarJar.obj"));
	}

	p_SaberOne = new Model("Assets/Models/3dRedblueSaber.obj");
	p_SaberTwo = new Model("Assets/Models/3dRedblueSaber.obj");

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

	delete p_SaberOne;
	p_SaberOne = nullptr;

	delete p_SaberTwo;
	p_SaberTwo = nullptr;
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
	
	int buttonstate = glfwGetMouseButton(GraphicsManager::Load()->GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
	glfwGetCursorPos(GraphicsManager::Load()->GetWindow(), &_MouseX, &_MouseY);

	if ((_MouseY < ((GraphicsManager::Load()->SCREEN_HEIGHT - p_MainMenu->GetTextPosition().y) - p_MainMenu->TextHeight) + p_MainMenu->TextHeight) && (_MouseY > (GraphicsManager::Load()->SCREEN_HEIGHT - p_MainMenu->GetTextPosition().y) - p_MainMenu->TextHeight))
	{
		if ((_MouseX > p_MainMenu->GetTextPosition().x) && (_MouseX < p_MainMenu->GetTextPosition().x + p_MainMenu->TextWidth))
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
		ScreenManager::Load()->SetCurrentScreen(ScreenManager::Load()->Start);
		_TimerReset = true;
		_Time = 0;
		_NewTime = 0;
		std::cout << "Main Menu" << std::endl;
	}

	static int laststate = GLFW_PRESS;
	int keystate = glfwGetKey(GraphicsManager::Load()->GetWindow(), GLFW_KEY_K);
	if (keystate == GLFW_PRESS && laststate == GLFW_RELEASE)
	{
		for (int i = 0; i < p_JarJarHeadsRowOne.size(); i++)
		{
			p_JarJarHeadsRowOne.erase(p_JarJarHeadsRowOne.begin());
		}
	}
	laststate = keystate;

	/*keystate = glfwGetKey(GraphicsManager::Instance()->GetWindow(), GLFW_KEY_A);
	if (keystate == GLFW_PRESS && laststate == GLFW_RELEASE)
	{
		if (p_JarJarHeadsRowOne.size() <= 5)
		{
			p_JarJarHeadsRowOne.push_back(new Model("Assets/Models/CubeJarJar.obj"));
		}
	}
	laststate = keystate;*/

	/*if (p_JarJarHeadsRowOne[0]->GetPosition().z <= -5.0f)
	{
		p_JarJarHeadsRowOne[0]->SetPosition(glm::vec3(p_JarJarHeadsRowOne[0]->GetPosition().x, p_JarJarHeadsRowOne[0]->GetPosition().y, p_JarJarHeadsRowOne[0]->GetPosition().z + 2.0f));
		std::cout << "Lets Resize" << std::endl;
	}*/
}

void PlayScreen::Render()
{
    p_BackGroundImage->Render();

	GraphicsManager::Load()->ModelShader.Use();


	float randNum = (rand() % ((80 - 30) + 1) + 30);
	float angle = glfwGetTime() * 200;
	float newPosition = -9.0f;
	float bounce = glfwGetTime();
	bool first = true;



	for (int i = 0; i < p_JarJarHeadsRowOne.size(); i++)
	{
		p_JarJarHeadsRowOne[i]->SetPerspective(45);
		if (!first)
		{
			p_JarJarHeadsRowOne[i]->SetPosition(glm::vec3(newPosition += 6.0f, 4.5f, -30.0f));
			p_JarJarHeadsRowOne[i]->SetRotation(angle += 50, glm::vec3(0.0f, 1.0f, 0.0f));
		}
		else
		{
			p_JarJarHeadsRowOne[i]->SetPosition(glm::vec3(newPosition, 4.5f, -30.0f));
			p_JarJarHeadsRowOne[i]->SetRotation(angle, glm::vec3(0.0f, 1.0f, 0.0f));
		}
		p_JarJarHeadsRowOne[i]->Draw(GraphicsManager::Load()->ModelShader);
		first = false;
	}

	if (p_SaberOne->GetPosition().x > -5 && p_SaberOne->GetPosition().x < 10)
	{
		p_SaberOne->SetPerspective(45);
		p_SaberOne->SetPosition(glm::vec3(bounce, 3, -30.0f));
		p_SaberOne->SetRotation(angle, glm::vec3(0.0f, 1.0f, 0.0f));
		p_SaberOne->Draw(GraphicsManager::Load()->ModelShader);
		std::cout << p_SaberOne->GetPosition().x << std::endl;
	}
	else if (p_SaberOne->GetPosition().x > 10)
	{
		p_SaberOne->SetPerspective(45);
		p_SaberOne->SetPosition(glm::vec3(-4, 3, -30.0f));
		p_SaberOne->SetRotation(angle, glm::vec3(0.0f, 1.0f, 0.0f));
		p_SaberOne->Draw(GraphicsManager::Load()->ModelShader);
		std::cout << "We Got here" << std::endl;
	}
	
	first = true;
	newPosition = -3.5f;
	for (int i = 0; i < p_JarJarHeadsRowTwo.size(); i++)
	{
		p_JarJarHeadsRowTwo[i]->SetPerspective(45);
		if (!first)
		{
			p_JarJarHeadsRowTwo[i]->SetPosition(glm::vec3(newPosition += 4.0f, 0.0f, -20.0f));
			p_JarJarHeadsRowTwo[i]->SetRotation(angle += 100, glm::vec3(0.0f, 1.0f, 0.0f));
		}
		else
		{
			p_JarJarHeadsRowTwo[i]->SetPosition(glm::vec3(newPosition, 0.0f, -20.0f));
			p_JarJarHeadsRowTwo[i]->SetRotation(angle, glm::vec3(0.0f, 1.0f, 0.0f));
		}
		p_JarJarHeadsRowTwo[i]->Draw(GraphicsManager::Load()->ModelShader);
		first = false;
	}

	p_SaberTwo->SetPerspective(45);
	p_SaberTwo->SetPosition(glm::vec3(0, -1.5, -20.0f));
	p_SaberTwo->SetRotation(angle, glm::vec3(0.0f, 1.0f, 0.0f));
	p_SaberTwo->Draw(GraphicsManager::Load()->ModelShader);

	first = true;
	newPosition = -4.0f;
	for (int i = 0; i < p_JarJarHeadsRowThree.size(); i++)
	{
		p_JarJarHeadsRowThree[i]->SetPerspective(45);
		if (!first)
		{
			p_JarJarHeadsRowThree[i]->SetPosition(glm::vec3(newPosition += 3.5f, -3.2f, -13.0f));
			p_JarJarHeadsRowThree[i]->SetRotation(angle += 75, glm::vec3(0.0f, 1.0f, 0.0f));
		}
		else
		{
			p_JarJarHeadsRowThree[i]->SetPosition(glm::vec3(newPosition, -3.2f, -13.0f));
			p_JarJarHeadsRowThree[i]->SetRotation(angle, glm::vec3(0.0f, 1.0f, 0.0f));
		}
		p_JarJarHeadsRowThree[i]->Draw(GraphicsManager::Load()->ModelShader);
		first = false;
	}

	p_CurtainsImage->Render();

    p_Score->RenderText("Score :", 40, 57, 1, glm::vec3(0, 0, 0));
	p_ScoreTotal->RenderText(std::to_string(_NewTime), 150, 57, 1, glm::vec3(0, 0, 0));

    p_Round->RenderText("Round :", 590, 57, 1, glm::vec3(0, 0, 0));
    p_MainMenu->RenderText("Main Menu", (GraphicsManager::Load()->SCREEN_WIDTH / 2) - (p_MainMenu->TextWidth / 2), 10, 1, _MainMenuColor);
}