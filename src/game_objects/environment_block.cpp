#include "environment_block.h"

EnvironmentBlock::EnvironmentBlock(int posX, int posY, int blockTextureIndex, int destinationRenderWidth,
                                   int destinationRenderHeight, std::string objectName) :
        Entity(posX, posY, objectName + std::to_string(blockTextureIndex),
               destinationRenderWidth, destinationRenderHeight) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 630;
    getModel().h = 500;
}
