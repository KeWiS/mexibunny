#ifndef MEXIBUNNY_PLAYER_H
#define MEXIBUNNY_PLAYER_H

#include "character.h"

class Player : public Character {
public:
    Player() {}

    Player(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight);
};

#endif //MEXIBUNNY_PLAYER_H
