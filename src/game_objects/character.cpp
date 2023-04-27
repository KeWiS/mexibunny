#include "character.h"

Character::Character(float posX, float posY, std::string objName) : x(posX), y(posY), textureKeyName(objName) {}

SDL_FRect &Character::getModel() {
    return model;
}

float Character::getX() {
    return x;
}

void Character::setX(float x) {
    this->x = x;
}

float Character::getY() {
    return y;
}

void Character::setY(float y) {
    this->y = y;
}

Movement Character::getMovement() {
    return movement;
}

void Character::setMovement(Movement movement) {
    this->movement = movement;
}
