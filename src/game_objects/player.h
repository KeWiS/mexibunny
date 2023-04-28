#ifndef MEXIBUNNY_PLAYER_H
#define MEXIBUNNY_PLAYER_H

#include "character.h"

class Player : public Character {
public:
    Player() {}

    Player(float x, float y, float mass);

    int getIdleIndex() const;

    void setIdleIndex(int idleIndex) const;

private:
    mutable int idleIndex = -1;
};

#endif //MEXIBUNNY_PLAYER_H
