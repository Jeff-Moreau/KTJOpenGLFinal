#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include "AssetManager.h"

namespace SDLFramework
{
	class AudioManager
	{
	private:
		static AudioManager* p_Instance;

		AssetManager* m_pAssetManager;

	public: // SINGLETON
		static AudioManager* Instance();

	private: // CONSTRUCTORS / DESTRUCTOR
		AudioManager();
		~AudioManager();

	public: // DOERS
		void PlayMusic(std::string filename, int loops = -1);
		void PauseMusic();
		void ResumeMusic();
		void StopMusic();
		void PlaySFX(std::string filename, int loops = 0, int channel = -1);
		static void Release();
	};
}
#endif // !AUDIO_MANAGER_H