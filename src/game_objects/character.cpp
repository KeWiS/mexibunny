#include "character.h"

SDL_FRect &Character::getModel() {
    return model;
}

SDL_Texture *Character::getTexture() {
    return texture;
}

void Character::setTexture(SDL_Texture *texture) {
    this->texture = texture;
}
