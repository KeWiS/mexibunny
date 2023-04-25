#include "character.h"

Character::Character(float posX, float posY, SDL_Texture *texLeft, SDL_Texture *texRight) : x(posX), y(posY),
textureLeft(texLeft), textureRight(texRight) {}

SDL_FRect &Character::getModel() {
    return model;
}

SDL_Texture *Character::getTextureLeft() {
    return textureLeft;
}

SDL_Texture *Character::getTextureRight() {
    return textureRight;
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
