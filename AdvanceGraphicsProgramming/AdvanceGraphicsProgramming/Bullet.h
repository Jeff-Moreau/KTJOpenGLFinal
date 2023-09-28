#ifndef _BULLET_H
#define _BULLET_H

#include <glm/glm.hpp>

class Bullet {
public:
    Bullet(glm::vec3 position, glm::vec3 direction);
    void draw();
    void update(float deltaTime);
    bool checkCollision(const glm::vec3& targetPosition, float targetRadius);

private:
    glm::vec3 position;
    glm::vec3 direction;
    float speed;
};

#endif