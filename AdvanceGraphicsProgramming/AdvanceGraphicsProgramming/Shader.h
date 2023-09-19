#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
private: // MEMBER VARIABLE DECLARATIONS
	unsigned int _ID;

public: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
	Shader();
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

public: // GETTERS
	unsigned int GetID();

public: // SETTERS
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetMat4(const std::string& name, glm::mat4& value) const;

public: // DOERS
	void Use();
};
#endif // !SHADER_H