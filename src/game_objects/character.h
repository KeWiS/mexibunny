#ifndef MEXIBUNNY_CHARACTER_H
#define MEXIBUNNY_CHARACTER_H

#include "../enums/movement.h"
#include <SDL.h>
#include <string>

// Top-level class for character objects (player, enemies)
class Character {
public:
    // TODO: Try to make it const
    std::string textureKeyName;

    Character() {}

    Character(float posX, float posY, std::string objName, float mass);

    SDL_FRect &getModel();

    float getX();

    void setX(float x);

    float getY();

    void setY(float y);

    Movement getMovement();

    void setMovement(Movement movement);

private:
    float x, y, ph_mass = 1.0f;
    Movement movement;
    SDL_FRect model;
};

#endif //MEXIBUNNY_CHARACTER_H
