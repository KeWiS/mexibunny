#include "rigid_body.h"

RigidBody::RigidBody() {
    this->mass = 1.0f;
}

float RigidBody::getMass() {
    return mass;
}

void RigidBody::setMass(float mass) {
    this->mass = mass;
}

physics::Vector2D RigidBody::getForce() {
    return force;
}

void RigidBody::setForce(physics::Vector2D force) {
    this->force = force;
}

physics::Vector2D RigidBody::getFriction() {
    return friction;
}

void RigidBody::setFriction(physics::Vector2D friction) {
    this->friction = friction;
}

physics::Vector2D RigidBody::getPosition() {
    return position;
}

void RigidBody::setPosition(physics::Vector2D position) {
    this->position = position;
}

physics::Vector2D RigidBody::getVelocity() {
    return velocity;
}

void RigidBody::setVelocity(physics::Vector2D velocity) {
    this->velocity = velocity;
}

physics::Vector2D RigidBody::getAcceleration() {
    return acceleration;
}

void RigidBody::applyForce(physics::Vector2D force) {
    this->force = force;
}

void RigidBody::applyForceOnXAxis(float forceX) {
    force.setVX(forceX);
}

void RigidBody::applyForceOnYAxis(float forceY) {
    force.setVY(forceY);
}

void RigidBody::removeForce() {
    this->force = physics::Vector2D();
}

void RigidBody::applyFriction(physics::Vector2D friction) {
    this->friction = friction;
}

void RigidBody::removeFriction() {
    this->friction = physics::Vector2D();
}

void RigidBody::calculateMovement(double deltaTime, float gravity) {
    acceleration.setVX((force.getVX() * friction.getVX()) / mass);
    // Gravity is taken into account here
    acceleration.setVY(acceleration.getVY() + gravity / mass);

    velocity = acceleration * deltaTime;

    position = velocity * deltaTime;
}
