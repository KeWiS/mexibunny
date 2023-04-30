#include "grass.h"

Grass::Grass(int posX, int posY, int grassTextureIndex, int destinationRenderWidth, int destinationRenderHeight) :
        Entity(posX, posY, "grass" + std::to_string(grassTextureIndex), destinationRenderWidth,
               destinationRenderHeight) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 630;
    getModel().h = 500;
}
