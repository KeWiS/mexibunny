#include "vector2D.h"

physics::Vector2D::Vector2D(float vX, float vY) {
    this->vX = vX;
    this->vY = vY;
}

float physics::Vector2D::getVX() {
    return vX;
}

void physics::Vector2D::setVX(float vX) {
    this->vX = vX;
}

float physics::Vector2D::getVY() {
    return vY;
}

void physics::Vector2D::setVY(float vY) {
    this->vY = vY;
}
