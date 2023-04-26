#ifndef MEXIBUNNY_ENTITY_H
#define MEXIBUNNY_ENTITY_H

#include <SDL.h>
#include <string>

// Top-level class for non-character objects (surfaces etc.)
class Entity {
public:
    const std::string objectName;

    Entity(float posX, float posY, std::string objName);

    SDL_Rect &getModel();

    float getX();

    float getY();

private:
    float x, y;
    SDL_Rect model;
};

#endif //MEXIBUNNY_ENTITY_H
