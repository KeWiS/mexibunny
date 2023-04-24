#include "entity.h"

Entity::Entity(float posX, float posY, SDL_Texture *tex) : x(posX), y(posY), texture(tex) {}

SDL_Rect &Entity::getModel() {
    return model;
}

SDL_Texture *Entity::getTexture() {
    return texture;
}

float Entity::getX() {
    return x;
}

float Entity::getY() {
    return y;
}
