#include "sound_handler.h"
#include "constants.h"
#include <iostream>

SoundHandler *SoundHandler::getInstance() {
    if (soundHandler == nullptr) {
        soundHandler = new SoundHandler();
    }

    return soundHandler;
}

void SoundHandler::init() {
    openAudio();
    loadAudio();
}

void SoundHandler::playMainMusic() {
    Mix_VolumeMusic(5);
    Mix_PlayMusic(mainMusic, -1);
}

void SoundHandler::openAudio() {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
}

void SoundHandler::loadAudio() {
    // Loading main music
    mainMusic = Mix_LoadMUS(constants::file_names::kMainMusic);
    if (!mainMusic) {
        std::cout << "Main music error: " << Mix_GetError() << std::endl;
    }
}
