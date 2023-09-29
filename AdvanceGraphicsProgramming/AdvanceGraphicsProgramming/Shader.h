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
public: // MEMBER VARIABLE DECLARATIONS
	unsigned int ID;

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
	void setVec2(const std::string& name, const glm::vec2& value) const;
	void setVec2(const std::string& name, float x, float y) const;
	void setVec3(const std::string& name, const glm::vec3& value) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec4(const std::string& name, const glm::vec4& value) const;
	void setVec4(const std::string& name, float x, float y, float z, float w) const;
	void setMat2(const std::string& name, const glm::mat2& mat) const;
	void setMat3(const std::string& name, const glm::mat3& mat) const;
	void SetMat4(const std::string& name, glm::mat4& value) const;
public: // DOERS
	void Use();
};
#endif // !SHADER_H