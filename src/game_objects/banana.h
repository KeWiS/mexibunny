#ifndef MEXIBUNNY_BANANA_H
#define MEXIBUNNY_BANANA_H

#include "character.h"

class Banana : public Character {
public:
    Banana() {}

    Banana(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight,
           int modelWidth, int modelHeight, int colliderWidth, int colliderHeight);
};

#endif //MEXIBUNNY_BANANA_H
