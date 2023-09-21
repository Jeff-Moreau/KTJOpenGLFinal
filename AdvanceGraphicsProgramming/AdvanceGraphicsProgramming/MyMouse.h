#pragma once

#include "GraphicsManager.h"
#include <iostream>

class MyMouse
{
public:


public:
    MyMouse();
    ~MyMouse();

public:
    static void GetCursorPosition(GLFWwindow* window, double xPos, double yPos);
};

