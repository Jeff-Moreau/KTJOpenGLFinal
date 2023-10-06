#ifndef SCREEN_H
#define SCREEN_H

// EXTERNAL INCLUDES
#include "irrklang/irrKlang.h"
#include "glm/glm.hpp"

// SYSTEM INCLUDES
#include <iostream>
#include <vector>
#include <cmath>

// PROJECT INCLUDES
#include "GraphicsManager.h"
#include "Model.h"
#include "Image.h"
#include "Font.h"

using namespace SDLFramework;
using namespace irrklang;

class Screen
{
protected:
	double _MouseX = 0;
	double _MouseY = 0;
	ISoundEngine* p_SoundFX = createIrrKlangDevice();
	GraphicsManager* p_Graphics = GraphicsManager::Use();

public: // SHARED DOERS
	virtual void SinglePlayer() {};
	virtual void Update() = 0;
	virtual void Render() = 0;
};
#endif // !SCREEN_H