#ifndef FONT_H
#define FONT_H

#include <glad/glad.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <string>
#include <iostream>
#include <map>
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "Shader.h"

struct Character {
	unsigned int TextureID;	// ID handle of the glyph texture
	glm::ivec2 Size;		// Size of glyph
	glm::ivec2 Bearing;		// Offset from baseline to left/top of glyph
	unsigned int Advance;	// Offset to advance to next glyph
};

class Font
{
private:
	std::map<char, Character> characters;
	unsigned int VAO, VBO;
	Shader shader;

public:
	Font();
	Font(std::string filename, Shader& aShader);

	void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);
};
#endif

