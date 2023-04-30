#ifndef MEXIBUNNY_ENGINE_H
#define MEXIBUNNY_ENGINE_H

#include "rigid_body.h"
#include <SDL.h>

namespace physics {
    class Engine {
    public:
        inline static const float gravity = 9.81f;

        static bool collisionAABB(const SDL_Rect &rectangle1, const SDL_Rect &rectangle2);

        static void calculateRigidBodyMovement(RigidBody &body, const double deltaTime);
    };
}

#endif //MEXIBUNNY_ENGINE_H
