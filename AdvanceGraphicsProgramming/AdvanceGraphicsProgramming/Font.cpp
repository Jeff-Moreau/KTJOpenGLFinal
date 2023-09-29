#include "Font.h"

Font::Font()
{
	_TotalCharacters = 0;
}

Font::Font(std::string fontName, Shader& shaderToUse, int pixHeight)
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	_FontShader = shaderToUse;
	glm::mat4 screenProjection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
	_FontShader.Use();
	glUniformMatrix4fv(glGetUniformLocation(_FontShader.GetID(), "projection"), 1, GL_FALSE, glm::value_ptr(screenProjection));

	FT_Library fontLibrary;
	FT_Face fontTypeFace;

	if (FT_Init_FreeType(&fontLibrary))
	{
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
		return;
	}

	if (FT_New_Face(fontLibrary, fontName.c_str(), 0, &fontTypeFace))
	{
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
		return;
	}
	else
	{
		FT_Set_Pixel_Sizes(fontTypeFace, 0, pixHeight);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		for (unsigned char c = 0; c < 128; c++)
		{
			if (FT_Load_Char(fontTypeFace, c, FT_LOAD_RENDER))
			{
				std::cout << "ERROR::FREETYPE: Failed to load Glyph" << std::endl;
				continue;
			}

			unsigned int texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(GL_TEXTURE_2D,0,GL_RED,fontTypeFace->glyph->bitmap.width,fontTypeFace->glyph->bitmap.rows,0,GL_RED,GL_UNSIGNED_BYTE,fontTypeFace->glyph->bitmap.buffer);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			Character character = {texture,glm::ivec2(fontTypeFace->glyph->bitmap.width, fontTypeFace->glyph->bitmap.rows),glm::ivec2(fontTypeFace->glyph->bitmap_left, fontTypeFace->glyph->bitmap_top),fontTypeFace->glyph->advance.x};
			_CharacterList.insert(std::pair<char, Character>(c, character));
		}
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	FT_Done_Face(fontTypeFace);
	FT_Done_FreeType(fontLibrary);

	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glBindVertexArray(_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Vector2 Font::GetFontPosition()
{
	return Vector2(_XPos, _YPos);
}

void Font::RenderText(std::string text, float x, float y, float scale, glm::vec3 color)
{
	// MEMBER VARIABLE INSTANTIATION
	_TotalCharacters = 0;
	_XPos = x;
	_YPos = y;
	_FontShader.Use();

	glUniform3f(glGetUniformLocation(_FontShader.GetID(), "textColor"), color.x, color.y, color.z);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(_VAO);

	// iterate through all characters
	// LOCAL VARIABLE DECLARATIONS
	std::string::const_iterator totalCharacters;

	for (totalCharacters = text.begin(); totalCharacters != text.end(); totalCharacters++)
	{
		Character singleCharacter = _CharacterList[*totalCharacters];

		float characterXPos = x + singleCharacter.Bearing.x * scale;
		float characterYPos = y - (singleCharacter.Size.y - singleCharacter.Bearing.y) * scale;

		float characterWidth = singleCharacter.Size.x * scale;
		float characterHeight = singleCharacter.Size.y * scale;

		float vertices[6][4] = {{characterXPos, characterYPos + characterHeight, 0.0f, 0.0f},
								{characterXPos, characterYPos, 0.0f, 1.0f},
								{characterXPos + characterWidth, characterYPos, 1.0f, 1.0f},
								{characterXPos, characterYPos + characterHeight, 0.0f, 0.0f},
								{characterXPos + characterWidth, characterYPos, 1.0f, 1.0f},
								{characterXPos + characterWidth, characterYPos + characterHeight, 1.0f, 0.0f}
							   };

		glBindTexture(GL_TEXTURE_2D, singleCharacter.ID);
		glBindBuffer(GL_ARRAY_BUFFER, _VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glDrawArrays(GL_TRIANGLES, 0, 6);
		x += (singleCharacter.Offset >> 6) * scale;
		_TotalCharacters++;
		TextWidth = _TotalCharacters * characterWidth;
		TextHeight = characterHeight;
	}

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}