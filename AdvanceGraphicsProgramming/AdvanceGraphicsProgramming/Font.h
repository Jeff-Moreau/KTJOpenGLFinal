#ifndef FONT_H
#define FONT_H

#include <glad/glad.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <string>
#include <iostream>
#include <map>
#include "MathHelper.h"
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "Shader.h"

using namespace SDLFramework;

struct Character
{
	unsigned int ID;		// ID handle of the glyph texture
	glm::ivec2 Size;		// Size of glyph
	glm::ivec2 Bearing;		// Offset from baseline to left/top of glyph
	unsigned int Offset;	// Offset to advance to next glyph
};

class Font
{
private: // MEMBER CONTAINER DECLARATIONS
	std::map<char, Character> _CharacterList;

private: // MEMBER VARIABLE DECLARATIONS
	float _XPos;
	float _YPos;
	unsigned int _VAO, _VBO;
	Shader _FontShader;
	int _TotalCharacters;

public:
	int TextWidth;
	int TextHeight;

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	Font();
	Font(std::string fontName, Shader& shaderToUse, int pixHeight);

public: // GETTERS
	Vector2 GetFontPosition();

public: // DOERS
	void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);
};
#endif // !FONT_H