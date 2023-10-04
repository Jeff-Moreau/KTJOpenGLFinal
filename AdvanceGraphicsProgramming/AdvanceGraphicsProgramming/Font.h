#ifndef FONT_H
#define FONT_H

// EXTERNAL INCLUDES
#include "glm/ext/matrix_clip_space.hpp"
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "ft2build.h"
#include FT_FREETYPE_H

// SYSTEM INCLUDES
#include <iostream>
#include <string>
#include <map>

// PROJECT INCLUDES
#include "MathHelper.h"
#include "Shader.h"

using namespace SDLFramework;

struct Character
{
	unsigned int ID;
	glm::ivec2 Size;
	glm::ivec2 Bearing;
	unsigned int Offset;
};

class Font
{
public: // ACCESSABLE VARIABLE DECLARATIONS
	int TextWidth;
	int TextHeight;

private: // MEMBER CONTAINER DECLARATIONS
	std::map<char, Character> _CharacterList;

private: // MEMBER VARIABLE DECLARATIONS
	unsigned int _VAO, _VBO;
	int _TotalCharacters;
	Shader _FontShader;
	float _XPos;
	float _YPos;
	glm::vec3 _TextColor;

public: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
	Font();
	Font(std::string fontName, int pixHeight, Shader shader);

public: // GETTERS
	Vector2 GetTextPosition();
	glm::vec3 GetTextColor();

public: // SETTERS
	void SetTextColor(glm::vec3 color);

public: // DOERS
	void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);
};
#endif // !FONT_H