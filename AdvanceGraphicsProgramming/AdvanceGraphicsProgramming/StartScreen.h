#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "GraphicsManager.h"
#include "InputManager.h"
#include "Screen.h"
#include "Sprite.h"
#include "Font.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

using namespace SDLFramework;

class StartScreen : public Screen
{
private: // MEMBER POINTER VARIABLE DECLARATIONS
	InputManager* p_Inputs;
	Sprite* p_BackGroundImage;
	Font* p_ExitGame;
	Font* p_NewGame;

private: // MEMBER VARIABLE DECLARATIONS
	Shader _Shader;
	Shader _FontShader;
	glm::vec3 _ExitColor;
	glm::vec3 _StartColor;
	double _MouseX;
	double _MouseY;
	bool _HoverExitGame;
	bool _HoverNewGame;

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	StartScreen();
	~StartScreen();

public: // DOERS
	void Update();
	void Render();
};
#endif // !START_SCREEN_H