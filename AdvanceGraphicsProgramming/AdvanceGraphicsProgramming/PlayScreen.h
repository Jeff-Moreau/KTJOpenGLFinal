#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

#include "Screen.h"
#include "Shader.h"
#include <vector>

using namespace SDLFramework;

class PlayScreen : public Screen
{
private: // MEMBER POINTER VARIABLE DECLARATIONS
	AudioManager* p_SoundFX;

	Image* p_BackGroundImage;
	Image* p_CurtainsImage;

	std::vector<Model*> p_JarJarHeadsRowOne;
	std::vector<Model*> p_JarJarHeadsRowTwo;
	std::vector<Model*> p_JarJarHeadsRowThree;

	Font* p_MainMenu;
	Font* p_Score;
	Font* p_Round;
	Font* p_ScoreTotal;

private: // MEMBER VARIABLE DECLARATIONS
	glm::vec3 _MainMenuColor;
	bool _HoverMainMenu;

private: // MEMBER VARIABLE DECLARATIONS
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