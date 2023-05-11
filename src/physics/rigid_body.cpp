#include "rigid_body.h"

RigidBody::RigidBody(float mass) {
    this->mass = mass;
    this->gravity = 9.81f;
}

float RigidBody::getGravity() {
    return gravity;
}

void RigidBody::setGravity(float gravity) {
    this->gravity = gravity;
}

physics::Vector2D RigidBody::getRigidPosition() {
    return position;
}

void RigidBody::applyForceOnXAxis(float forceX) {
    force.setVX(forceX);
}

void RigidBody::applyForceOnYAxis(float forceY) {
    force.setVY(forceY);
}

void RigidBody::applyFriction(physics::Vector2D friction) {
    this->friction = friction;
}

void RigidBody::calculateMovement(double deltaTime, float gravity) {
    acceleration.setVX((force.getVX() * friction.getVX()) / mass);
    // Gravity is taken into account here
    acceleration.setVY(acceleration.getVY() + force.getVY() + gravity / mass);

    velocity = acceleration * deltaTime;

    position = velocity * deltaTime;
}

void RigidBody::resetGravitationalAcceleration() {
    acceleration.setVY(0);
}
