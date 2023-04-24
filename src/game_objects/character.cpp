#include "character.h"

Character::Character(float posX, float posY, SDL_Texture *tex) : x(posX), y(posY), texture(tex) {}

SDL_FRect &Character::getModel() {
    return model;
}

SDL_Texture *Character::getTexture() {
    return texture;
}

float Character::getX() {
    return x;
}

float Character::getY() {
    return y;
}
