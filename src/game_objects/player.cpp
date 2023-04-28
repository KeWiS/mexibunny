#include "player.h"

Player::Player(float x, float y, float mass) : Character(x, y, "player", mass) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 32;
    getModel().h = 32;
}

int Player::getIdleIndex() const {
    return idleIndex;
}

void Player::setIdleIndex(int idleIndex) const {
    this->idleIndex = idleIndex;
}
