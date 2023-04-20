#ifndef MEXIBUNNY_ENTITY_H
#define MEXIBUNNY_ENTITY_H

#include <SDL.h>

// Top-level class for non-character objects (surfaces etc.)
class Entity {
public:
    SDL_Rect &getModel();

    SDL_Texture *getTexture();

    void setTexture(SDL_Texture *texture);

protected:
    void setModel(SDL_Rect model);

private:
    SDL_Rect model;
    SDL_Texture *texture;
};

#endif //MEXIBUNNY_ENTITY_H
