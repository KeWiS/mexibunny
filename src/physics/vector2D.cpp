#include "vector2D.h"

Vector2D::Vector2D(float vX, float vY) {
    this->vX = vX;
    this->vY = vY;
}

float Vector2D::getVX() {
    return vX;
}

void Vector2D::setVX(float vX) {
    this->vX = vX;
}

float Vector2D::getVY() {
    return vY;
}

void Vector2D::setVY(float vY) {
    this->vY = vY;
}
