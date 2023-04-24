#ifndef MEXIBUNNY_CHARACTER_H
#define MEXIBUNNY_CHARACTER_H

#include <SDL.h>

// Top-level class for character objects (player, enemies)
class Character {
public:
    Character(float posX, float posY, SDL_Texture *tex);

    SDL_FRect &getModel();

    SDL_Texture *getTexture();

    float getX();

    float getY();

private:
    float x, y;
    SDL_FRect model;
    SDL_Texture *texture;
};

#endif //MEXIBUNNY_CHARACTER_H
