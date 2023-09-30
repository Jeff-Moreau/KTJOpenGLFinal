#ifndef _GUN_H
#define _GUN_H

#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include <GLFW/glfw3.h>

class Gun : public Shader {
public:
    Gun();
    ~Gun();
    void draw();
private:
    GLuint VAO, VBO;
    glm::vec3 position;
    glm::mat4 model;
};

#endif