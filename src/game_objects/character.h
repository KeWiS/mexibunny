#ifndef MEXIBUNNY_CHARACTER_H
#define MEXIBUNNY_CHARACTER_H

#include <SDL.h>
#include "../enums/movement.h"

// Top-level class for character objects (player, enemies)
class Character {
public:
    Character() {}

    Character(float posX, float posY, SDL_Texture *texLeft, SDL_Texture *texRight);

    SDL_FRect &getModel();

    SDL_Texture *getTextureLeft();

    SDL_Texture *getTextureRight();

    float getX();

    void setX(float x);

    float getY();

    void setY(float y);

    Movement getMovement();

    void setMovement(Movement movement);

private:
    float x, y;
    Movement movement;
    SDL_FRect model;
    SDL_Texture *textureLeft;
    SDL_Texture *textureRight;
};

#endif //MEXIBUNNY_CHARACTER_H
