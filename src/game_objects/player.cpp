#include "player.h"

Player::Player(float x, float y, SDL_Texture *texture) : Character(x, y, texture) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 32;
    getModel().h = 32;
}
