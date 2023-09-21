#include "AudioManager.h"
#include <iostream>

AudioManager::AudioManager() : audioDevice(0) {}

AudioManager::~AudioManager() {
    Shutdown();
}

bool AudioManager::Initialize() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL audio initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    if (SDL_OpenAudio(NULL, NULL) < 0) {
        std::cout << "SDL_OpenAudio failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    return true;
}

void AudioManager::Shutdown() {
    StopAllSounds();

    for (Uint8* buffer : soundBuffers) {
        SDL_FreeWAV(buffer);
    }

    SDL_CloseAudio();
    SDL_Quit();
}

bool AudioManager::LoadSound(const std::string& soundPath) {
    SDL_AudioSpec soundSpec;
    Uint8* soundBuffer;
    Uint32 soundLength;

    if (SDL_LoadWAV(soundPath.c_str(), &soundSpec, &soundBuffer, &soundLength) == nullptr) {
        std::cout << "SDL_LoadWAV failed for " << soundPath << ": " << SDL_GetError() << std::endl;
        return false;
    }

    soundSpecs.push_back(soundSpec);
    soundBuffers.push_back(soundBuffer);

    return true;
}

void AudioManager::PlaySound(int soundIndex, int volume) {
    if (soundIndex >= 0 && soundIndex < static_cast<int>(soundBuffers.size())) {
        SDL_LockAudio();
        SDL_QueueAudio(audioDevice, soundBuffers[soundIndex], soundSpecs[soundIndex].size);
        SDL_UnlockAudio();
        SDL_PauseAudio(0);
    }
}

void AudioManager::StopAllSounds() {
    SDL_PauseAudio(1);
    SDL_ClearQueuedAudio(audioDevice);
}
