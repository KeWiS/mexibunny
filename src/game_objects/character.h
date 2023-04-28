#ifndef MEXIBUNNY_CHARACTER_H
#define MEXIBUNNY_CHARACTER_H

#include "../enums/movement.h"
#include "../physics/vector2D.h"
#include <SDL.h>
#include <string>

// Top-level class for character objects (player, enemies)
class Character {
public:
    // TODO: Try to make it const
    std::string textureKeyName;

    Character() {}

    virtual ~Character() = default;

    Character(float posX, float posY, std::string objName, float mass);

    physics::Vector2D getCVector();

    void setCVector(physics::Vector2D cVector);

    double getX();

    void setX(double x);

    double getY();

    void setY(double y);

    SDL_FRect &getModel();

    Movement getMovement();

    void setMovement(Movement movement);

private:
    physics::Vector2D cVector;
    float ph_mass = 1.0f;
    Movement movement;
    SDL_FRect model;
};

#endif //MEXIBUNNY_CHARACTER_H
