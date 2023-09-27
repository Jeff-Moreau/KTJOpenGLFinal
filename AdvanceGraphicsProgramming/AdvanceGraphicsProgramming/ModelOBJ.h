#ifndef MODEL_OBJ_H
#define MODEL_OBJ_H

#include <string>
#include "Shader.h"
#include "stb_image.h"
#include "GraphicsManager.h"

using namespace SDLFramework;

class ModelOBJ
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
	float _Vertices[180];
	unsigned int _Indices[6] = {
								0, 1, 3,	//first triangle
								1, 2, 3		//second triangle
	};

	glm::vec3 _CubePositions[10] = {
		glm::vec3(-1.5f,  1.75f,  -10.0f),
		glm::vec3(-4.0f,  1.75f, -10.0f),
		glm::vec3(1.5f, 1.75f, -10.0f),
		glm::vec3(4.0f, 1.75f, -10.0f),
		glm::vec3(2.0f, 0.0f, -7.5f),
		glm::vec3(-2.0f,  0.0f, -7.5f),
		glm::vec3(0.0f, 0.0, -7.5f),
		glm::vec3(3.0f,  -1.25f, -5.0f),
		glm::vec3(-3.0f,  -1.25f, -5.0f),
		glm::vec3(0.0f,  -1.25f, -5.0f)
	};

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	ModelOBJ();
	ModelOBJ(std::string imageName, Shader& shaderToUse); //fullscreen image
	ModelOBJ(std::string imageName, Shader& shaderToUse, float x, float y, float w, float h);
	~ModelOBJ();

public: // DOERS
	void GLSettings();
	void Render();
};
#endif // !MODEL_OBJ_H