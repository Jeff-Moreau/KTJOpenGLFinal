#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include "Screen.h"
#include "Shader.h"

using namespace SDLFramework;

class PlayScreen : public Screen
{
private: // MEMBER POINTER VARIABLE DECLARATIONS
	AudioManager* p_SoundFX;
	InputManager* p_Inputs;
	Image* p_BackGroundImage;
	Image* p_CurtainsImage;
	Model* p_Tammy;
	Font* p_MainMenu;
	Font* p_Score;
	Font* p_Round;
	Font* p_ScoreTotal;
	glm::vec3 _MainMenuColor;
	bool _HoverMainMenu;

private: // MEMBER VARIABLE DECLARATIONS
	//Shader _3DShader;
	//Shader _Shader;
	//Shader _FontShader;
	bool _TimerReset;
	float _Time;
	int _NewTime;

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	PlayScreen();
	~PlayScreen();

public: // DOERS
	void Update();
	void Render();
};
#endif // !START_SCREEN_H