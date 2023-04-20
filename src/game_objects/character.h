#ifndef MEXIBUNNY_CHARACTER_H
#define MEXIBUNNY_CHARACTER_H

#include <SDL.h>

// Top-level class for character objects (player, enemies)
class Character {
public:
    SDL_FRect &getModel();

    SDL_Texture *getTexture();

    void setTexture(SDL_Texture *texture);

protected:
    void setModel();

private:
    SDL_FRect model = {10, 10, 100, 200};
    SDL_Texture *texture;
};

#endif //MEXIBUNNY_CHARACTER_H
