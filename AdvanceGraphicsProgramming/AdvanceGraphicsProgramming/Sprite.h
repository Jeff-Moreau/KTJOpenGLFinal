#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include "Shader.h"
#include "stb_image.h"

class Sprite
{
private:
	unsigned int tex;
	float vertices[32];
	unsigned int indices[6] = {
		0, 1, 3,	//first triangle
		1, 2, 3		//second triangle
	};
	unsigned int VBO, VAO, EBO;
	float x, y, w, h;
	Shader shader;

public:
	Sprite() {};
	Sprite(std::string filename, Shader& aShader); //fullscreen image
	Sprite(std::string filename, Shader& aShader, float x, float y, float w, float h);
	~Sprite();

	void GLSettings();
	void Render();
};
#endif // !SPRITE_H