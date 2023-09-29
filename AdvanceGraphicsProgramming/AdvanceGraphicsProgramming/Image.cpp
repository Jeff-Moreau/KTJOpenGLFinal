#include "Image.h"

Image::Image()
{

}

Image::Image(std::string imageName) :
	_Vertices
{
	// positions		// colors			// texture coords
	1.0f, 1.0f, 0.0f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f,	// top right
	1.0f, -1.0f, 0.0f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f,	// bottom right
	-1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,	0.0f, 0.0f,	// bottom left
	-1.0f, 1.0f, 0.0f,	1.0f, 1.0f, 0.0f,	0.0f, 1.0f	// top left
}
{
	_Shader = Shader("Assets/Shaders/texture.vs", "Assets/Shaders/texture.fs");
	
	GLSettings();

	int width;
	int height;
	int textureColorChannels;
	unsigned char* newTexture = nullptr;

	newTexture = stbi_load(imageName.c_str(), &width, &height, &textureColorChannels, 0);

	if (newTexture)
	{
		if (textureColorChannels == 3)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, newTexture);
		}
		else if (textureColorChannels == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, newTexture);
		}
		
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(newTexture);
}

Image::Image(std::string imageName, float x, float y, float w, float h)
{
	_Shader = Shader("Assets/Shaders/texture.vs", "Assets/Shaders/texture.fs");

	GLSettings();

	int width;
	int height;
	int colorChannels;
	unsigned char* newTexture = nullptr;

	newTexture = stbi_load(imageName.c_str(), &width, &height, &colorChannels, 0);

	if (newTexture)
	{
		if (colorChannels == 3)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, newTexture);
		}
		else if (colorChannels == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, newTexture);
		}
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(newTexture);
}

Image::~Image()
{
	glDeleteVertexArrays(1, &_VAO);
	glDeleteBuffers(1, &_VBO);
	glDeleteBuffers(1, &_EBO);
}

void Image::GLSettings()
{
	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &_VBO);
	glGenBuffers(1, &_EBO);

	glBindVertexArray(_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_Vertices), _Vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_Indices), _Indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glGenTextures(1, &_Texture);
	glBindTexture(GL_TEXTURE_2D, _Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Image::Render()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _Texture);
	_Shader.Use();
	glBindVertexArray(_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
