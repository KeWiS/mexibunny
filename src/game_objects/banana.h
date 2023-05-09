#ifndef MEXIBUNNY_BANANA_H
#define MEXIBUNNY_BANANA_H

#include "character.h"

class Banana : public Character {
public:
    Banana() {}

    Banana(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight,
           float modelWidth, float modelHeight, float colliderWidth, float colliderHeight, double maxStrikeTime,
           int maxHealth, int minDamage, int maxDamage);
};

#endif //MEXIBUNNY_BANANA_H
