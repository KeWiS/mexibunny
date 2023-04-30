#include "entity.h"

Entity::Entity(float posX, float posY, std::string objName, int destRenderWidth, int destRenderHeight) :
        x(posX), y(posY), textureKeyName(objName), destinationRenderWidth(destRenderWidth),
        destinationRenderHeight(destRenderHeight) {}

float Entity::getX() {
    return x;
}

float Entity::getY() {
    return y;
}

int Entity::getDestinationRenderWidth() {
    return destinationRenderWidth;
}

int Entity::getDestinationRenderHeight() {
    return destinationRenderHeight;
}

SDL_Rect &Entity::getModel() {
    return model;
}
