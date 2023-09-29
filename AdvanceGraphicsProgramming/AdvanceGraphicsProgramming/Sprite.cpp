#include "Sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(std::string imageName, Shader& shaderToUse)
{
	_Shader = shaderToUse;
	
	GLSettings();

	int width;
	int height;
	int textureColorChannels;
	unsigned char* newTexture = nullptr;
	stbi_set_flip_vertically_on_load(true);
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
	_Shader.Use();
	glUniform1i(glGetUniformLocation(_Shader.ID, "texture1"), 0);
	_Shader.SetInt("texture2", 1);
}

Sprite::Sprite(std::string imageName, Shader& shaderToUse, float x, float y, float w, float h)
{
	_Shader = shaderToUse;

	GLSettings();

	int width;
	int height;
	int colorChannels;
	unsigned char* newTexture = nullptr;
	stbi_set_flip_vertically_on_load(true);
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
	
	_Shader.Use(); 
	glUniform1i(glGetUniformLocation(_Shader.ID, "texture1"), 0);
	_Shader.SetInt("texture2", 1);
}

Sprite::~Sprite()
{
	glDeleteVertexArrays(1, &_VAO);
	glDeleteBuffers(1, &_VBO);
	glDeleteBuffers(1, &_EBO);
}

void Sprite::GLSettings()
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
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Sprite::Render()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _Texture);
	_Shader.Use();
	glBindVertexArray(_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
