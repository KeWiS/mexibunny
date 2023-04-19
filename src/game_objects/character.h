#ifndef MEXIBUNNY_CHARACTER_H
#define MEXIBUNNY_CHARACTER_H

#include <SDL.h>

class Character {
public:
    SDL_FRect &getModel();

private:
    SDL_FRect model = {10, 10, 100, 200};
};

#endif //MEXIBUNNY_CHARACTER_H
