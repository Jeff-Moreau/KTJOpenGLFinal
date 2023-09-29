#include "PlayScreen.h"
#include "ScreenManager.h"

PlayScreen::PlayScreen()
{
	p_SoundFX = AudioManager::Instance();
    _Shader = Shader("Assets/Shaders/texture.vs", "Assets/Shaders/texture.fs");
    p_BackGroundImage = new Sprite("Assets/Textures/KTJPlayScreenBackDrop.png", _Shader);

    _FontShader = Shader("Assets/Shaders/Font.vs", "Assets/Shaders/Font.fs");
    p_Score = new Font("Assets/Fonts/Starjedi.ttf", _FontShader, 24);
    p_Round = new Font("Assets/Fonts/Starjedi.ttf", _FontShader, 24);
    p_MainMenu = new Font("Assets/Fonts/Starjedi.ttf", _FontShader, 32);
}

PlayScreen::~PlayScreen()
{

}

void PlayScreen::Update()
{
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
		std::cout << "Main Menu" << std::endl;
	}

	/*if (_HoverSoundOn == 1)
	{
		p_SoundFX->PlaySFX("droidnoise.mp3");
	}*/
}

void PlayScreen::Render()
{
    p_BackGroundImage->Render();
    p_Score->RenderText("Score :", 40, 57, 1, glm::vec3(0,0,0));
    p_Round->RenderText("Round :", 590, 57, 1, glm::vec3(0, 0, 0));
    p_MainMenu->RenderText("Main Menu", (GraphicsManager::Instance()->SCREEN_WIDTH / 2) - (p_MainMenu->TextWidth / 2), 10, 1, _MainMenuColor);
}
