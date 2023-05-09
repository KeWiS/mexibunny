#include "player.h"

Player::Player(float x, float y, float mass, int destinationRenderWidth, int destinationRenderHeight,
               float modelWidth, float modelHeight, float colliderWidth, float colliderHeight, double maxStrikeTime,
               int maxHealth, int minDamage, int maxDamage) :
        Character(x, y, modelWidth, modelHeight, colliderWidth, colliderHeight,
                  "player", mass, 3, 1, 1, 2,
                  destinationRenderWidth, destinationRenderHeight, maxStrikeTime,
                  maxHealth, minDamage, maxDamage) {
    // Setting weapon collider size
    getMutableWeaponCollider().w = colliderWidth;
    getMutableWeaponCollider().h = colliderHeight / 2;
    // Setting gravity and jump force
    setGravity(6000);
    setJumpForce(18000);
}

bool Player::checkHasBeenStrikeUp() {
    return hasBeenStrikeUp;
}

void Player::setHasBeenStrikeUp(bool hasBeenStrikeUp) {
    this->hasBeenStrikeUp = hasBeenStrikeUp;
}
