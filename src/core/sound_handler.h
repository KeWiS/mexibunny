#ifndef MEXIBUNNY_SOUND_HANDLER_H
#define MEXIBUNNY_SOUND_HANDLER_H

#include <SDL_mixer.h>

class SoundHandler {
public:
    SoundHandler(SoundHandler &otherSoundHandler) = delete;

    void operator=(const SoundHandler &) = delete;

    static SoundHandler *getInstance();

    void init();

    void playMainMusic();

private:
    SoundHandler() = default;

    inline static SoundHandler *soundHandler = nullptr;

    Mix_Music *mainMusic;

    static void openAudio();

    void loadAudio();
};

#endif //MEXIBUNNY_SOUND_HANDLER_H
