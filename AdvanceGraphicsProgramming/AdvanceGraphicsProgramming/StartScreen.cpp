#include "StartScreen.h"
#include "ScreenManager.h"

StartScreen::StartScreen()
{
	_HoverExitGame = false;
	_HoverNewGame = false;

	p_SoundFX = AudioManager::Instance();
	p_Inputs = InputManager::Instance();

	_Shader = Shader("Assets/Shaders/texture.vs", "Assets/Shaders/texture.fs");
	p_BackGroundImage = new Sprite("Assets/Textures/KTJTitleScreen.png", _Shader);

	_FontShader = Shader("Assets/Shaders/Font.vs", "Assets/Shaders/Font.fs");
	p_NewGame = new Font("Assets/Fonts/Starjedi.ttf", _FontShader, 24);
	p_ExitGame = new Font("Assets/Fonts/Starjedi.ttf", _FontShader, 32);
}

StartScreen::~StartScreen()
{
	delete p_BackGroundImage;
	p_BackGroundImage = nullptr;
	
	delete p_NewGame;
	p_NewGame = nullptr;

	delete p_ExitGame;
	p_ExitGame = nullptr;
}

void StartScreen::Update()
{
	/*static int laststate = GLFW_PRESS;
	int keystate = glfwGetKey(GraphicsManager::Instance()->GetWindow(), GLFW_KEY_ENTER);
	if (keystate == GLFW_PRESS && laststate == GLFW_RELEASE)
	{
		std::cout << "I pressed E" << std::endl;;
	}
	laststate = keystate;*/
	
	int buttonstate = glfwGetMouseButton(GraphicsManager::Instance()->GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
	glfwGetCursorPos(GraphicsManager::Instance()->GetWindow(), &_MouseX, &_MouseY);

	if ((_MouseY < ((GraphicsManager::Instance()->SCREEN_HEIGHT - p_ExitGame->GetFontPosition().y) - p_ExitGame->TextHeight) + p_ExitGame->TextHeight) && (_MouseY > (GraphicsManager::Instance()->SCREEN_HEIGHT - p_ExitGame->GetFontPosition().y) - p_ExitGame->TextHeight))
	{
		if ((_MouseX > p_ExitGame->GetFontPosition().x) && (_MouseX < p_ExitGame->GetFontPosition().x + p_ExitGame->TextWidth))
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
	
	if (buttonstate == GLFW_PRESS && _HoverExitGame)
	{
		glfwSetWindowShouldClose(GraphicsManager::Instance()->GetWindow(), 1);
	}


	if ((_MouseY < ((GraphicsManager::Instance()->SCREEN_HEIGHT - p_NewGame->GetFontPosition().y) - p_NewGame->TextHeight) + p_NewGame->TextHeight) && (_MouseY > (GraphicsManager::Instance()->SCREEN_HEIGHT - p_NewGame->GetFontPosition().y) - p_NewGame->TextHeight))
	{
		if ((_MouseX > p_NewGame->GetFontPosition().x) && (_MouseX < p_NewGame->GetFontPosition().x + p_NewGame->TextWidth))
		{
			_StartColor = glm::vec3(0, 255, 255);
			_HoverNewGameSound++;
			_HoverNewGame = true;
		}
		else
		{
			_HoverNewGameSound = 0;
			_HoverNewGame = false;
			_StartColor = glm::vec3(255, 255, 255);
		}
	}
	else
	{
		_HoverNewGameSound = 0;
		_HoverNewGame = false;
		_StartColor = glm::vec3(255, 255, 255);
	}

	if (buttonstate == GLFW_PRESS && _HoverNewGame)
	{
		p_SoundFX->PlaySFX("oh-no.mp3");
		ScreenManager::Instance()->SetCurrentScreen(ScreenManager::Instance()->Play);
		std::cout << "Start Game now" << std::endl;
	}

	if (_HoverNewGameSound == 1)
	{
		p_SoundFX->PlaySFX("droidnoise.mp3");
	}
}

void StartScreen::Render()
{
	p_BackGroundImage->Render();
	p_NewGame->RenderText("Start New Game", 285, 175, 1, _StartColor);
	p_ExitGame->RenderText("Exit Game", 575, 25, 1, _ExitColor);
}