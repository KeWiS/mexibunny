#ifndef MEXIBUNNY_PHYSICS_H
#define MEXIBUNNY_PHYSICS_H

#include <SDL.h>

class Physics {
public:
    inline static const float gravity = 9.8f;

    static bool collisionAABB(const SDL_Rect &rectangle1, const SDL_Rect &rectangle2);
};

#endif //MEXIBUNNY_PHYSICS_H
