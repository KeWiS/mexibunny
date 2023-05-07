#include "banana.h"

Banana::Banana(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight,
               int modelWidth, int modelHeight, int colliderWidth, int colliderHeight) :
        Character(x, y, "banana", mass, 1, 1, 1,
                  destinationRenderWidth, destinationRenderHeight) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = modelWidth;
    getModel().h = modelHeight;

    getMutableCollider().w = colliderWidth;
    getMutableCollider().h = colliderHeight;

    setGravity(6000);
    setJumpForce(18000);
}
