#ifndef BULLET_H
#define BULLET_H

#include "GraphicsManager.h"
#include "Model.h"

class Bullet
{
private:
    Model* p_Bullet;
    GraphicsManager* p_Graphics;
    double _MouseX;
    double _MouseY;

public:
    Bullet();
    ~Bullet();

public:
    void Update();
    void Render();
};
#endif // !BULLET_H