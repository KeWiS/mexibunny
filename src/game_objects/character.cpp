#include "character.h"

Character::Character(float posX, float posY, std::string objName, float mass) : textureKeyName(objName), ph_mass(mass) {
    this->cVector = physics::Vector2D(posX, posY);
}

physics::Vector2D Character::getCVector() {
    return cVector;
}

void Character::setCVector(physics::Vector2D cVector) {
    this->cVector = cVector;
}

double Character::getX() {
    return cVector.getVX();
}
void Character::setX(double x) {
    cVector.setVX(x);
}
double Character::getY() {
    return cVector.getVY();
}
void Character::setY(double y) {
    cVector.setVY(y);
}

SDL_FRect &Character::getModel() {
    return model;
}

Movement Character::getMovement() {
    return movement;
}

void Character::setMovement(Movement movement) {
    this->movement = movement;
}
