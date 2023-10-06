// OpenGLRenderer.h
#ifndef _GUN_H
#define _GUN_H

#include <GLFW/glfw3.h>
#include "GameManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

class Gun {
public:
    Gun(int width, int height, const std::string& title);
    ~Gun();
    void init();
    void processInput();
    void update();
    void render();
    bool shouldClose() const;
private:
    int width, height;
    GLFWwindow* window;
    GLuint gunVAO, bulletVAO, shaderProgram;
    float gunVertices[9];
    float bulletVertices[9];
    float gunX, gunY, bulletX, bulletY;
    float bulletSpeed;
    double lastTime;
};

#endif