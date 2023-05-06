#include "player.h"

Player::Player(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight,
               int modelWidth, int modelHeight, int colliderWidth, int colliderHeight) :
        Character(x, y, "player", mass, 3, 1,
                  destinationRenderWidth, destinationRenderHeight) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = modelWidth;
    getModel().h = modelHeight;

    getMutableCollider().w = colliderWidth;
    getMutableCollider().h = colliderHeight;

    setGravity(1000);
    setJumpForce(1350);
}
