#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2_mixer-2.0.4/include/SDL_mixer.h>
#include <sstream>
#include <map>
#include "GraphicsManager.h"

namespace SDLFramework
{
	class AssetManager
	{
	private:
		static AssetManager* p_Instance;

		std::map<std::string, Mix_Music*> p_Music;
		std::map<Mix_Music*, unsigned> p_MusicList;

		std::map<std::string, Mix_Chunk*> p_SFXs;
		std::map<Mix_Chunk*, unsigned> p_SFXsList;

	public: // SINGLETON
		static AssetManager* Instance();

	private: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
		AssetManager();
		~AssetManager();

	public: // GETTERS
		Mix_Music* GetMusic(std::string fileName, bool managed = false);
		Mix_Chunk* GetSFX(std::string fileName, bool managed = false);

	public: // DOERS
		void DestroyMusic(Mix_Music* music);
		void DestroySFX(Mix_Chunk* sfx);
		static void Release();
	};
}
#endif // !ASSET_MANAGER_H