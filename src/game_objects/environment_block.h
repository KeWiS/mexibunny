#ifndef MEXIBUNNY_ENVIRONMENT_BLOCK_H
#define MEXIBUNNY_ENVIRONMENT_BLOCK_H

#include "entity.h"
#include <string>

class EnvironmentBlock : public Entity {
public:
    EnvironmentBlock(int posX, int posY, int blockTextureIndex, int destinationRenderWidth,
                     int destinationRenderHeight, std::string objectName);
};

#endif //MEXIBUNNY_ENVIRONMENT_BLOCK_H
