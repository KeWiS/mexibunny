#include "entity.h"

Entity::Entity(float posX, float posY, std::string objName) : x(posX), y(posY), textureKeyName(objName) {}

SDL_Rect &Entity::getModel() {
    return model;
}

float Entity::getX() {
    return x;
}

float Entity::getY() {
    return y;
}
