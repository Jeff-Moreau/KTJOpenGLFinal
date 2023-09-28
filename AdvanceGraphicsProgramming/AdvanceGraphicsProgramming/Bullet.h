#ifndef _BULLET_H
#define _BULLET_H

#include "Shader.h"

class Bullet : public Shader {
public:
    Bullet(glm::vec3 startPos);
    ~Bullet();
    void draw();
    void update();
private:
    GLuint VAO, VBO;
    glm::vec3 position;
    glm::mat4 model;
};

#endif