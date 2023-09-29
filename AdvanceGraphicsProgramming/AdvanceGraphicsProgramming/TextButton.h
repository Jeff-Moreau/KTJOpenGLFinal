#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include <iostream>
#include <string>
#include "MathHelper.h"
#include "Sprite.h"
#include "Font.h"

using namespace SDLFramework;

class TextButton
{
private:
    std::string _ButtonText;
    std::string _FontType;
    int _FontSize;
    Vector2 _TextPosition;
    float _XPos;
    float _Ypos;
    Shader _FontShader;
    glm::vec3 _Color;

public:
    TextButton();
    ~TextButton();

    void CreateNewTextButton(std::string text, std::string font, int fontSize = 24, Vector2 position = (0,0));
};
#endif // !TEXT_BUTTON_H