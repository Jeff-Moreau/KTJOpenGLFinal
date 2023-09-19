#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include "Shader.h"
#include "stb_image.h"

class Sprite
{
private: // MEMBER VARIABLE DECLARATIONS
	unsigned int _Texture;
	unsigned int _VBO;
	unsigned int _VAO;
	unsigned int _EBO;
	float _XPos;
	float _YPos;
	float _Width;
	float _Height;
	Shader _Shader;

private: // MEMBER CONTAINER DECLARATIONS
	float _Vertices[32];
	unsigned int _Indices[6] = {
								0, 1, 3,	//first triangle
								1, 2, 3		//second triangle
							   };

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	Sprite();
	Sprite(std::string imageName, Shader& shaderToUse); //fullscreen image
	Sprite(std::string imageName, Shader& shaderToUse, float x, float y, float w, float h);
	~Sprite();

public: // DOERS
	void GLSettings();
	void Render();
};
#endif // !SPRITE_H