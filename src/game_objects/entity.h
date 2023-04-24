#ifndef MEXIBUNNY_ENTITY_H
#define MEXIBUNNY_ENTITY_H

#include <SDL.h>

// Top-level class for non-character objects (surfaces etc.)
class Entity {
public:
    Entity(float posX, float posY, SDL_Texture *tex);

    SDL_Rect &getModel();

    SDL_Texture *getTexture();

    float getX();

    float getY();

private:
    float x, y;
    SDL_Rect model;
    SDL_Texture *texture;
};

#endif //MEXIBUNNY_ENTITY_H
