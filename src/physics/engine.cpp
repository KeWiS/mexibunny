#include "engine.h"

bool physics::Engine::collisionAABB(const SDL_Rect &rectangle1, const SDL_Rect &rectangle2) {
    // Checking all 4 corners of rectangles to their corresponding one at second rectangle
    return (rectangle1.x + rectangle1.w >= rectangle2.x &&
           rectangle2.x + rectangle2.w >= rectangle1.x &&
           rectangle1.y + rectangle1.h >= rectangle2.y &&
           rectangle2.y + rectangle2.h >= rectangle1.y);
}

void physics::Engine::calculateRigidBodyMovement(RigidBody *body, const double deltaTime) {
    // Dividing delta time by 1000 to get time in seconds
    body->calculateMovement(deltaTime / 1000, gravity);
}
