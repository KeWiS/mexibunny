#ifndef MEXIBUNNY_GRASS_H
#define MEXIBUNNY_GRASS_H

#include "entity.h"

class Grass : public Entity {
public:
    Grass(int posX, int posY, int grassTextureIndex, int destinationRenderWidth, int destinationRenderHeight);
};

#endif //MEXIBUNNY_GRASS_H
