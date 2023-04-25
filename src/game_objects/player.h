#ifndef MEXIBUNNY_PLAYER_H
#define MEXIBUNNY_PLAYER_H

#include "character.h"

class Player : public Character {
public:
    Player() {}
    Player(float x, float y, SDL_Texture *textureLeft, SDL_Texture *textureRight);
};

#endif //MEXIBUNNY_PLAYER_H
