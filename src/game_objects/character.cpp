#include "character.h"

Character::Character(float posX, float posY, std::string objName, float mass, int idleAnimFrames, int movingAnimFrames,
                     int destRenderWidth, int destRenderHeight) : RigidBody(mass),
                                                                  textureKeyName(objName),
                                                                  idleAnimationFrames(idleAnimFrames),
                                                                  movingAnimationFrames(movingAnimFrames),
                                                                  destinationRenderWidth(destRenderWidth),
                                                                  destinationRenderHeight(destRenderHeight) {
    this->positionVector = physics::Vector2D(posX, posY);
    model.x = posX;
    model.y = posY;
}

physics::Vector2D &Character::getPositionVector() {
    return positionVector;
}

physics::Vector2D &Character::getLastSafePosition() {
    return lastSafePosition;
}

bool Character::getIsGrounded() {
    return isGrounded;
}

void Character::setIsGrounded(bool isGrounded) {
    this->isGrounded = isGrounded;
}

bool Character::getIsJumping() {
    return isJumping;
}

void Character::setIsJumping(bool isJumping) {
    this->isJumping = isJumping;
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

float Character::getJumpTime() {
    return jumpTime;
}

void Character::setJumpTime(float jumpTime) {
    this->jumpTime = jumpTime;
}

void Character::decreaseJumpTime(double timeToDecrease) {
    this->jumpTime -= timeToDecrease;
}

float Character::getJumpForce() {
    return jumpForce;
}

void Character::setJumpForce(float jumpForce) {
    this->jumpForce = jumpForce;
}

SDL_FRect &Character::getModel() {
    return model;
}

SDL_FRect &Character::getMutableCollider() {
    return collider;
}

const SDL_FRect &Character::getCollider() const {
    return collider;
}

Movement Character::getMovement() {
    return movement;
}

void Character::setMovement(Movement movement) {
    this->movement = movement;
}
