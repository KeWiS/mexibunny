#include "grass.h"

Grass::Grass(int posX, int posY) : Entity(posX, posY, "grass") {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 630;
    getModel().h = 500;
}
