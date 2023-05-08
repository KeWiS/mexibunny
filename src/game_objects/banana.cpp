#include "banana.h"

Banana::Banana(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight,
               int modelWidth, int modelHeight, int colliderWidth, int colliderHeight, double maxStrikeTime) :
        Character(x, y, modelWidth, modelHeight, "banana", mass, 1, 1,
                  1, 1, destinationRenderWidth,
                  destinationRenderHeight, maxStrikeTime) {
    // Setting collider size
    getMutableCollider().w = colliderWidth;
    getMutableCollider().h = colliderHeight;
    // Setting weapon collider size
    getMutableWeaponCollider().w = colliderWidth;
    getMutableWeaponCollider().h = colliderHeight / 2;
    // Setting gravity and jump force
    setGravity(6000);
    setJumpForce(18000);
}
