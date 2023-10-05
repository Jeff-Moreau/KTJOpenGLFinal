#ifndef PLAY_SCREEN_H
#define PLAY_SCREEN_H

// PROJECT INCLUDES
#include "Screen.h"

class PlayScreen : public Screen
{
private: // MEMBER POINTER VARIABLE DECLARATIONS
	Image* p_BackGroundImage;
	Image* p_CurtainsImage;

	std::vector<Model*> p_JarJarHeadsRowOne;
	std::vector<Model*> p_JarJarHeadsRowTwo;
	std::vector<Model*> p_JarJarHeadsRowThree;

	Model* p_SaberOne;
	Model* p_SaberTwo;	
	Model* p_Bullet;
	Model* p_Gun;

	Font* p_MainMenu;
	Font* p_Score;
	Font* p_Round;
	Font* p_ScoreTotal;

private: // MEMBER VARIABLE DECLARATIONS
	glm::vec3 _MainMenuColor;
	bool _HoverMainMenu;
	bool _CanShoot;

private: // MEMBER VARIABLE DECLARATIONS
	bool _TimerReset;
	float _Time;
	int _NewTime;

public: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
	PlayScreen();
	~PlayScreen();

public: // DOERS
	void Update();
	void Render();
};
#endif // !START_SCREEN_H