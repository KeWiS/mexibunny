#ifndef MEXIBUNNY_PLAYER_H
#define MEXIBUNNY_PLAYER_H

#include "character.h"

class Player : public Character {
public:
    Player() {}

    Player(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight,
           float modelWidth, float modelHeight, float colliderWidth, float colliderHeight, double maxStrikeTime);

    bool checkHasBeenStrikeUp();

    void setHasBeenStrikeUp(bool hasBeenStrikeUp);

private:
    bool hasBeenStrikeUp;
};

#endif //MEXIBUNNY_PLAYER_H
