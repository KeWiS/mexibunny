#include "character.h"

Character::Character(float posX, float posY, float modelWidth, float modelHeight, float colliderWidth,
                     float colliderHeight, std::string objName, float mass, int idleAnimFrames, int movingAnimFrames,
                     int inAirAnimFrames, int strikeAnimFrames, int destRenderWidth, int destRenderHeight,
                     double maxStrTime, int maxHealth, int minDmg, int maxDmg) :
        RigidBody(mass),
        textureKeyName(objName),
        idleAnimationFrames(idleAnimFrames),
        movingAnimationFrames(movingAnimFrames),
        inAirAnimationFrames(inAirAnimFrames),
        strikeAnimationFrames(strikeAnimFrames),
        destinationRenderWidth(destRenderWidth),
        destinationRenderHeight(destRenderHeight),
        maxStrikeTime(maxStrTime),
        health(maxHealth),
        minDamage(minDmg),
        maxDamage(maxDmg) {
    // Setting up position vector
    positionVector = physics::Vector2D(posX, posY);
    // Setting up texture source model
    model.x = 0;
    model.y = 0;
    model.w = modelWidth;
    model.h = modelHeight;
    // Setting collider size
    collider.x = posX;
    collider.y = posY;
    collider.w = colliderWidth;
    collider.h = colliderHeight;
    // Setting strike time counter for the first time
    strikeTimeCounter = maxStrikeTime;
    // Setting up initial destination render width and model width for rollback after strike
    initialModelWidth = model.w;
    initialDestinationRenderWidth = destinationRenderWidth;
    initialColliderWidth = collider.w;
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

int Character::getCurrentSegment() {
    return currentSegment;
}

void Character::setCurrentSegment(int currentSegment) {
    this->currentSegment = currentSegment;
}

int Character::getHealth() {
    return health;
}

void Character::removeHealth(int damage) {
    health -= damage;
}

bool Character::checkDeathCondition() {
    return health <= 0;
}

int Character::getMinDamage() {
    return minDamage;
}

int Character::getMaxDamage() {
    return maxDamage;
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

int Character::getInAirAnimationFrames() {
    return inAirAnimationFrames;
}

int Character::getInAirAnimationIndex() {
    return inAirAnimationIndex;
}

void Character::setInAirAnimationIndex(int inAirAnimationIndex) {
    this->inAirAnimationIndex = inAirAnimationIndex;
}

int Character::getStrikeAnimationFrames() {
    return strikeAnimationFrames;
}

int Character::getStrikeAnimationIndex() {
    return strikeAnimationIndex;
}

void Character::setStrikeAnimationIndex(int strikeAnimationIndex) {
    this->strikeAnimationIndex = strikeAnimationIndex;
}

int Character::getDestinationRenderWidth() {
    return destinationRenderWidth;
}

void Character::setDestinationRenderWidth(int destinationRenderWidth) {
    this->destinationRenderWidth = destinationRenderWidth;
}

int Character::getDestinationRenderHeight() {
    return destinationRenderHeight;
}

int Character::getInitialDestinationRenderWidth() {
    return initialDestinationRenderWidth;
}

float Character::getInitialModelWidth() {
    return initialModelWidth;
}

float Character::getInitialColliderWidth() {
    return initialColliderWidth;
}

bool Character::shouldTextureBeHorizontallyFlipped() {
    return lastRecordedMovementDirection == Movement::kLeft;
}

double Character::getAnimationTimeCounter() {
    return animationTimeCounter;
}

void Character::resetAnimationTimeCounter() {
    animationTimeCounter = 0;
}

void Character::addToAnimationTimeCounter(double timeToAdd) {
    animationTimeCounter += timeToAdd;
}

bool Character::checkIsStriking() {
    return isStriking;
}

void Character::setIsStriking(bool isStriking) {
    this->isStriking = isStriking;
}

double Character::getMaxStrikeTime() {
    return maxStrikeTime;
}

double Character::getStrikeTimeCounter() {
    return strikeTimeCounter;
}

void Character::resetStrikeTimeCounter() {
    strikeTimeCounter = maxStrikeTime;
}

void Character::decreaseStrikeTimeCounter(double timeToDecrease) {
    strikeTimeCounter -= timeToDecrease;
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

const SDL_FRect &Character::getWeaponCollider() const {
    return weaponCollider;
}

SDL_FRect &Character::getMutableWeaponCollider() {
    return weaponCollider;
}

Movement Character::getMovement() {
    return movement;
}

void Character::setMovement(Movement movement) {
    this->movement = movement;
}

void Character::setLastRecordedMovementDirection(Movement lastRecordedMovementDirection) {
    this->lastRecordedMovementDirection = lastRecordedMovementDirection;
}
