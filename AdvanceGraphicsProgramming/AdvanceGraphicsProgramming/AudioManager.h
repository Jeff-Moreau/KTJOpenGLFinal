#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include "AssetManager.h"

namespace SDLFramework
{
	class AudioManager
	{
	private: // MEMBER POINTER VARIABLES
		AssetManager* m_pAssetManager;

	private: // SINGLETON
		static AudioManager* p_Instance;

	public: // SINGLETON
		static AudioManager* Instance();

	private: // CONSTRUCTORS / DESTRUCTOR / OVERLOADS
		AudioManager();
		~AudioManager();

	public: // DOERS
		void PlayMusic(std::string filename, int loops = -1);
		void PauseMusic();
		void ResumeMusic();
		void StopMusic();

	public: // DOERS
		void PlaySFX(std::string filename, int loops = 0, int channel = -1);

	public: // CLEANUP
		static void Release();
	};
}
#endif // !AUDIO_MANAGER_H