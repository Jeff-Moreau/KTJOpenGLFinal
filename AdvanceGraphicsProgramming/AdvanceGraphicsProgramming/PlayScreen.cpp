#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
    _Shader = Shader("Assets/Shaders/texture.vs", "Assets/Shaders/texture.fs");
    p_BackGroundImage = new Sprite("Assets/Textures/KTJPlayScreenBackDrop.png", _Shader);
}

PlayScreen::~PlayScreen()
{

}

void PlayScreen::Update()
{

}

void PlayScreen::Render()
{
    p_BackGroundImage->Render();
}
