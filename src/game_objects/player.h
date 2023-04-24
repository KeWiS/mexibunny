#ifndef MEXIBUNNY_PLAYER_H
#define MEXIBUNNY_PLAYER_H

#include "character.h"

class Player : public Character {
public:
    Player(float x, float y, SDL_Texture *texture);
};

#endif //MEXIBUNNY_PLAYER_H
