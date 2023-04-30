#ifndef MEXIBUNNY_ENTITY_H
#define MEXIBUNNY_ENTITY_H

#include <SDL.h>
#include <string>

// Top-level class for non-character objects (surfaces etc.)
class Entity {
public:
    const std::string textureKeyName;

    Entity(float posX, float posY, std::string objName, int destRenderWidth, int destRenderHeight);

    float getX();

    float getY();

    int getDestinationRenderWidth();

    int getDestinationRenderHeight();

    SDL_Rect &getModel();

private:
    float x, y;
    int destinationRenderWidth, destinationRenderHeight;
    SDL_Rect model;
};

#endif //MEXIBUNNY_ENTITY_H
