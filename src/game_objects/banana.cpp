#include "banana.h"

Banana::Banana(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight,
               float modelWidth, float modelHeight, float colliderWidth, float colliderHeight, double maxStrikeTime) :
        Character(x, y, modelWidth, modelHeight, colliderWidth, colliderHeight,
                  "banana", mass, 1, 1, 1, 1,
                  destinationRenderWidth, destinationRenderHeight, maxStrikeTime) {
    // Setting weapon collider size
    getMutableWeaponCollider().w = colliderWidth;
    getMutableWeaponCollider().h = colliderHeight / 2;
    // Setting gravity and jump force
    setGravity(6000);
    setJumpForce(18000);
}
