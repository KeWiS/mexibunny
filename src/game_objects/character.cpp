#include "character.h"

Character::Character(float posX, float posY, std::string objName, float mass, int idleAnimFrames, int movingAnimFrames,
                     int destRenderWidth, int destRenderHeight) :
        textureKeyName(objName), ph_mass(mass), idleAnimationFrames(idleAnimFrames),
        movingAnimationFrames(movingAnimFrames), destinationRenderWidth (destRenderWidth),
        destinationRenderHeight(destRenderHeight) {
    this->positionVector = physics::Vector2D(posX, posY);
}

physics::Vector2D Character::getPositionVector() {
    return positionVector;
}

void Character::setPositionVector(physics::Vector2D cVector) {
    this->positionVector = cVector;
}

float Character::getX() {
    return positionVector.getVX();
}

void Character::setX(float x) {
    positionVector.setVX(x);
}

float Character::getY() {
    return positionVector.getVY();
}

void Character::setY(float y) {
    positionVector.setVY(y);
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

int Character::getMovingAnimationFrames() {
    return movingAnimationFrames;
}

int Character::getMovingAnimationIndex() {
    return movingAnimationIndex;
}

void Character::setMovingAnimationIndex(int movingAnimationIndex) {
    this->movingAnimationIndex = movingAnimationIndex;
}

int Character::getDestinationRenderWidth() {
    return destinationRenderWidth;
}

int Character::getDestinationRenderHeight() {
    return destinationRenderHeight;
}

bool Character::shouldTextureBeHorizontallyFlipped() {
    return shouldTextureBeHorizFlipped;
}

void Character::setShouldTextureBeHorizontallyFlipped(bool shouldTextureBeHorizFlipped) {
    this->shouldTextureBeHorizFlipped = shouldTextureBeHorizFlipped;
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
