#include "player.h"

Player::Player(float x, float y, SDL_Texture *textureLeft, SDL_Texture *textureRight) :
Character(x, y, textureLeft,textureRight) {
    getModel().x = 0;
    getModel().y = 0;
    getModel().w = 32;
    getModel().h = 32;
}
