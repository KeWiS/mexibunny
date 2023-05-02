#ifndef MEXIBUNNY_ENGINE_H
#define MEXIBUNNY_ENGINE_H

#include "rigid_body.h"
#include <SDL.h>

namespace physics {
    class Engine {
    public:
        static bool collisionAABB(const SDL_FRect &rectangle1, const SDL_FRect &rectangle2);

        static void calculateRigidBodyMovement(RigidBody &body, const double deltaTime);

    private:
        Engine() = default;
    };
}

#endif //MEXIBUNNY_ENGINE_H
