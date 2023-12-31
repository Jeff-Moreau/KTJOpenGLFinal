#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

// EXTERNAL INCLUDES
#include "SDL2_mixer-2.0.4/include/SDL_mixer.h"
#include "SDL2/SDL.h"

// SYSTEM INCLUDES
#include <sstream>
#include <map>

// PROJECT INCLUDES
#include "GraphicsManager.h"

namespace SDLFramework
{
	class AssetManager
	{
	private: // MEMBER CONTAINER DECLARATION
		std::map<std::string, Mix_Music*> p_Music;
		std::map<Mix_Music*, unsigned> p_MusicList;

		std::map<std::string, Mix_Chunk*> p_SFXs;
		std::map<Mix_Chunk*, unsigned> p_SFXsList;

	private: // SINGLETON
		static AssetManager* p_Instance;

	public: // SINGLETON
		static AssetManager* Load();

	private: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
		AssetManager();
		~AssetManager();

	public: // GETTERS
		Mix_Music* GetMusic(std::string fileName, bool managed = false);
		Mix_Chunk* GetSFX(std::string fileName, bool managed = false);

	public: // CLEANUP
		void DestroyMusic(Mix_Music* music);
		void DestroySFX(Mix_Chunk* sfx);
		static void UnLoad();
	};
}
#endif // !ASSET_MANAGER_H