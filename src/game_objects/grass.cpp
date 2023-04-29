#include "grass.h"

Grass::Grass(int posX, int posY, int grassTextureIndex) : Entity(posX, posY,
                                                                 "grass" + std::to_string(grassTextureIndex)) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 630;
    getModel().h = 500;
}
