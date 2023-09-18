#include "GameManager.h"
//#include "stb_image.h"

int main(int argc, char* args[]) {
	GameManager* game = GameManager::Instance();
	game->Run();
	GameManager::Release();
	delete game;
	game = nullptr;
	return 0;
}