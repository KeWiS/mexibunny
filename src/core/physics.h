#ifndef MEXIBUNNY_PHYSICS_H
#define MEXIBUNNY_PHYSICS_H

#include <SDL.h>

class Physics {
public:
    static bool collisionAABB(const SDL_Rect &rectangle1, const SDL_Rect &rectangle2);
};

#endif //MEXIBUNNY_PHYSICS_H
