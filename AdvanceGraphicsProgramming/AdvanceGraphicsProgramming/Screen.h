#ifndef SCREEN_H
#define SCREEN_H

#include "AudioManager.h"
#include "GraphicsManager.h"
#include "ModelOBJ.h"
#include "Model.h"
#include "InputManager.h"
#include "Image.h"
#include "Font.h"
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
#include <cmath>
#include <iostream>

class Screen
{
protected:
	double _MouseX;
	double _MouseY;

public: // SHARED DOERS
	virtual void SinglePlayer() {};
	virtual void Update() = 0;
	virtual void Render() = 0;
};
#endif // !SCREEN_H