#ifndef _GUN_H
#define _GUN_H

#include "Bullet.h"
#include <glm/glm.hpp>
#include <vector>

class Gun {
public:
    Gun();
    void draw();
    void shoot();
    void updateBullets(float deltaTime);

private:
    glm::vec3 position;
    int bulletsRemaining;
    std::vector<Bullet> bullets;
};

#endif