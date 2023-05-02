#include "player.h"

Player::Player(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight) :
        Character(x, y, "player", mass, 3, 1, destinationRenderWidth,
                  destinationRenderHeight) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 32;
    getModel().h = 32;

    getMutableCollider().w = 64;
    getMutableCollider().h = 62;

    setGravity(20);
}
