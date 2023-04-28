#include "player.h"

Player::Player(float x, float y, float mass) : Character(x, y, "player", mass, 3) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 32;
    getModel().h = 32;
}
