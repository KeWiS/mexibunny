#ifndef MEXIBUNNY_ANIMATOR_H
#define MEXIBUNNY_ANIMATOR_H

#include "../game_objects/character.h"

class Animator {
public:
    static float computePlayerIdleTextureOffset(Character &character);
};

#endif //MEXIBUNNY_ANIMATOR_H
