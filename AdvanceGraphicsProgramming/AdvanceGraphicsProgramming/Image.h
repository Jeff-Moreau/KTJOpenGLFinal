#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "GraphicsManager.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include "Shader.h"

class Image
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
	Image();
	Image(std::string imageName); //fullscreen image
	Image(std::string imageName, float x, float y, float w, float h);
	~Image();

public: // DOERS
	void GLSettings();
	void Render();
};
#endif // !IMAGE_H