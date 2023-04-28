#include "vector2D.h"

physics::Vector2D::Vector2D(double vX, double vY) {
    this->vX = vX;
    this->vY = vY;
}

double physics::Vector2D::getVX() {
    return vX;
}

void physics::Vector2D::setVX(double vX) {
    this->vX = vX;
}

double physics::Vector2D::getVY() {
    return vY;
}

void physics::Vector2D::setVY(double vY) {
    this->vY = vY;
}
