#include "Shader.h"

Shader::Shader()
{

}

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    // retrieve the vertex/fragment source code from the filePath
    // LOCAL VARIABLE DECLARATIONS
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vertexShader;
    std::ifstream fragmentShader;

    // ensure ifstream objects can throw exceptions:
    vertexShader.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentShader.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // open files
        vertexShader.open(vertexPath);
        fragmentShader.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        // read file's buffer contents into streams
        vShaderStream << vertexShader.rdbuf();
        fShaderStream << fragmentShader.rdbuf();

        // close file handlers
        vertexShader.close();
        fragmentShader.close();

        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure streamError)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESULLY_READ" << streamError.what() << std::endl;
    }

    // LOCAL VARIABLE DECLARATIONS
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    unsigned int vertex;
    unsigned int fragment;
    int success;
    char infoLog[512];

    // vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);

    // check for compile errors
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << std::endl;
    }

    // fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);

    // check for compile errors
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED" << std::endl;
    }

    // shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    glUseProgram(ID);

    // check for compile errors
    glGetProgramiv(ID, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED" << infoLog << std::endl;
    }

    // delete the shaders as they're linked into our program now and no longer needed
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{

}

unsigned int Shader::GetID()
{
    return ID;
}

void Shader::SetBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string& name, int value) const
{
    (glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetMat4(const std::string& name, glm::mat4& value) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, false, glm::value_ptr(value));
}

void Shader::Use()
{
    glUseProgram(ID);
}