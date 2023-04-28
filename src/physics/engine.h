#ifndef MEXIBUNNY_ENGINE_H
#define MEXIBUNNY_ENGINE_H

#include <SDL.h>

namespace physics {
    class Engine {
    public:
        inline static const float gravity = 9.8f;

        static bool collisionAABB(const SDL_Rect &rectangle1, const SDL_Rect &rectangle2);
    };
}

#endif //MEXIBUNNY_ENGINE_H
