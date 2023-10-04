#ifndef IMAGE_H
#define IMAGE_H

// EXTERNAL INCLUDES
#include "glad/glad.h"
#include "GLFW/glfw3.h"

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include "GraphicsManager.h"
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
	float _Vertices[32] = {
		  //Positions		  //Colors			 //Coords
		  1.0f, 1.0f, 0.0f,	  1.0f, 0.0f, 0.0f,	 1.0f, 1.0f, // top right
		  1.0f, -1.0f, 0.0f,  0.0f, 1.0f, 0.0f,	 1.0f, 0.0f, // bottom right
		  -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, // bottom left
		  -1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,	 0.0f, 1.0f	 // top left
	};

	unsigned int _Indices[6] = {
				 0, 1, 3, //first triangle
				 1, 2, 3  //second triangle
	};

public: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
	Image();
	Image(std::string imageName, Shader& shader); //fullscreen image
	Image(std::string imageName, Shader& shader, float x, float y, float w, float h);
	~Image();

public: // DOERS
	void GLSettings();
	void Render();
};
#endif // !IMAGE_H