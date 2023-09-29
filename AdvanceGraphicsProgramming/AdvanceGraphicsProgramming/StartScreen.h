#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "Screen.h"

using namespace SDLFramework;

class StartScreen : public Screen
{
private: // MEMBER POINTER VARIABLE DECLARATIONS
	AudioManager* p_SoundFX;
	InputManager* p_Inputs;
	Image* p_BackGroundImage;
	ModelOBJ* p_TestBlock;
	Font* p_ExitGame;
	Font* p_NewGame;

private: // MEMBER VARIABLE DECLARATIONS
	Shader _Shader;
	Shader _3DShader;
	Shader _FontShader;
	glm::vec3 _ExitColor;
	glm::vec3 _StartColor;
	bool _HoverExitGame;
	bool _HoverNewGame;
	int _HoverNewGameSound;

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	StartScreen();
	~StartScreen();

public: // DOERS
	void Update();
	void Render();
};
#endif // !START_SCREEN_H