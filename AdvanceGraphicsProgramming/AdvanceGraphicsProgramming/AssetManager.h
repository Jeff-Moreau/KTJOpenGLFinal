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

		std::map<std::string, SDL_Texture*> p_SDLTextures;
		std::map<std::string, SDL_Texture*> p_SDLTexts;
		std::map<SDL_Texture*, unsigned> p_SDLTexturesList;

		std::map<std::string, SDL_Surface*> p_SDLSurfaceTextures;
		std::map<std::string, SDL_Surface*> p_SDLSurfaceTexts;
		std::map<SDL_Surface*, unsigned> p_SDLSurfaceTexturesList;

		std::map<std::string, Mix_Music*> p_Music;
		std::map<Mix_Music*, unsigned> p_MusicList;

		std::map<std::string, Mix_Chunk*> p_SFXs;
		std::map<Mix_Chunk*, unsigned> p_SFXsList;

	public: // SINGLETON
		static AssetManager* Instance();

	private: // CONSTRUCTORS / DESTRUCTOR
		AssetManager();
		~AssetManager();

	private: // GETTERS

	public: // GETTERS
		SDL_Texture* GetTexture(std::string fileName, bool managed = false);
		SDL_Texture* GetText(std::string text, std::string fileName, int size, SDL_Color color, bool managed = false);
		Mix_Music* GetMusic(std::string fileName, bool managed = false);
		Mix_Chunk* GetSFX(std::string fileName, bool managed = false);
		SDL_Surface* GetSurfaceTexture(std::string fileName, bool managed = false);
		SDL_Surface* GetSurfaceText(std::string text, std::string fileName, int size, SDL_Color color, bool managed = false);

	public: // DOERS
		void DestroySurface(SDL_Surface* surface);
		void DestroyMusic(Mix_Music* music);
		void DestroySFX(Mix_Chunk* sfx);
		void DestroyTexture(SDL_Texture* texture);
		static void Release();
	};
}
#endif // !ASSET_MANAGER_H