#include "StartScreen.h"
#include "ScreenManager.h"

StartScreen::StartScreen()
{
	_HoverExitGame = false;
	_HoverNewGame = false;

	//p_SoundFX = AudioManager::Load();
	p_SoundFX = createIrrKlangDevice();
	p_BackGroundImage = new Image("KTJTitleScreen.png", GraphicsManager::Load()->TextureShader);

	p_NewGame = new Font("Starjedi.ttf", 24, GraphicsManager::Load()->FontShader);
	p_ExitGame = new Font("Starjedi.ttf", 32, GraphicsManager::Load()->FontShader);
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
	int buttonstate = glfwGetMouseButton(GraphicsManager::Load()->GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
	glfwGetCursorPos(GraphicsManager::Load()->GetWindow(), &_MouseX, &_MouseY);

	HoverText(p_ExitGame, _ExitColor, glm::vec3(0, 255, 255), glm::vec3(0, 0, 0), _HoverExitGame);
	HoverText(p_NewGame, _StartColor, glm::vec3(0, 255, 255), glm::vec3(255, 255, 255), _HoverNewGame);

	if (buttonstate == GLFW_PRESS && _HoverExitGame)
	{
		glfwSetWindowShouldClose(GraphicsManager::Load()->GetWindow(), 1);
	}

	if (buttonstate == GLFW_PRESS && _HoverNewGame)
	{
		p_SoundFX->play2D("Assets/Sounds/oh-no.mp3", false);
		//p_SoundFX->PlaySFX("oh-no.mp3");
		ScreenManager::Load()->SetCurrentScreen(ScreenManager::Load()->Play);
		std::cout << "Start Game now" << std::endl;
	}

	if (_HoverNewGameSound == 1)
	{
		p_SoundFX->play2D("Assets/Sounds/droidnoise.mp3", false);
		//p_SoundFX->PlaySFX("droidnoise.mp3");
	}
}

void StartScreen::Render()
{
	p_BackGroundImage->Render();

	p_NewGame->RenderText("Start New Game", 285, 175, 1, _StartColor);
	p_ExitGame->RenderText("Exit Game", 575, 25, 1, _ExitColor);
}

void StartScreen::HoverText(Font* font, glm::vec3& textColor, glm::vec3 hoverColor, glm::vec3 restColor, bool& hover)
{
	if ((_MouseY < ((GraphicsManager::Load()->SCREEN_HEIGHT - font->GetTextPosition().y) - font->TextHeight) + font->TextHeight) && (_MouseY > (GraphicsManager::Load()->SCREEN_HEIGHT - font->GetTextPosition().y) - font->TextHeight))
	{
		if ((_MouseX > font->GetTextPosition().x) && (_MouseX < font->GetTextPosition().x + font->TextWidth))
		{
			textColor = hoverColor;
			hover = true;
		}
		else
		{
			textColor = restColor;
			hover = false;
		}
	}
	else
	{
		textColor = restColor;
		hover = false;
	}
}
