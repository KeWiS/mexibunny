#include "player.h"

Player::Player(float x, float y) : Character(x, y, "player") {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 32;
    getModel().h = 32;
}
