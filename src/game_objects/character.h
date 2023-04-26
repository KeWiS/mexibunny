#ifndef MEXIBUNNY_CHARACTER_H
#define MEXIBUNNY_CHARACTER_H

#include <SDL.h>
#include "../enums/movement.h"
#include <string>

// Top-level class for character objects (player, enemies)
class Character {
public:
    std::string objectName;

    Character() {}

    Character(float posX, float posY, std::string objName);

    SDL_FRect &getModel();

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
};

#endif //MEXIBUNNY_CHARACTER_H
