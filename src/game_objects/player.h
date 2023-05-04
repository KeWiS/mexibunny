#ifndef MEXIBUNNY_PLAYER_H
#define MEXIBUNNY_PLAYER_H

#include "character.h"

class Player : public Character {
public:
    Player() {}

    Player(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight,
           int modelWidth, int modelHeight, int colliderWidth, int colliderHeight);
};

#endif //MEXIBUNNY_PLAYER_H
