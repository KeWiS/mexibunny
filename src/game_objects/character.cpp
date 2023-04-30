#include "character.h"

Character::Character(float posX, float posY, std::string objName, float mass, int idleAnimFrames,
                     int destRenderWidth, int destRenderHeight) :
        textureKeyName(objName), ph_mass(mass), idleAnimationFrames(idleAnimFrames),
        destinationRenderWidth(destRenderWidth), destinationRenderHeight(destRenderHeight) {
    this->cVector = physics::Vector2D(posX, posY);
}

physics::Vector2D Character::getCVector() {
    return cVector;
}

void Character::setCVector(physics::Vector2D cVector) {
    this->cVector = cVector;
}

float Character::getX() {
    return cVector.getVX();
}

void Character::setX(float x) {
    cVector.setVX(x);
}

float Character::getY() {
    return cVector.getVY();
}

void Character::setY(float y) {
    cVector.setVY(y);
}

int Character::getIdleAnimationFrames() {
    return idleAnimationFrames;
}

int Character::getIdleAnimationIndex() {
    return idleAnimationIndex;
}

void Character::setIdleAnimationIndex(int idleAnimationIndex) {
    this->idleAnimationIndex = idleAnimationIndex;
}

int Character::getDestinationRenderWidth() {
    return destinationRenderWidth;
}

int Character::getDestinationRenderHeight() {
    return destinationRenderHeight;
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
