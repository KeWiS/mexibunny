#include "grass.h"

Grass::Grass(int posX, int posY, int width, int height) {
    SDL_Rect grassModel = {posX, posY, width, height};
    setModel(grassModel);
}
