#include "grass.h"

Grass::Grass(int posX, int posY, SDL_Texture *texture) : Entity(posX, posY, texture) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 630;
    getModel().h = 500;
}
