#ifndef SCREEN_H
#define SCREEN_H

// EXTERNAL INCLUDES
#include "glm/glm.hpp"

// SYSTEM INCLUDES
#include <iostream>
#include <vector>
#include <cmath>

// PROJECT INCLUDES
#include "GraphicsManager.h"
#include "AudioManager.h"
#include "Model.h"
#include "Image.h"
#include "Font.h"

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