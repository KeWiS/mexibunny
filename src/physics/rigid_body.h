#ifndef MEXIBUNNY_RIGID_BODY_H
#define MEXIBUNNY_RIGID_BODY_H

#include "vector2D.h"

class RigidBody {
public:
    RigidBody() {}

    RigidBody(float mass);

    float getGravity();

    void setGravity(float gravity);

    physics::Vector2D getRigidPosition();

    void applyForceOnXAxis(float forceX);

    void applyForceOnYAxis(float forceY);

    void applyFriction(physics::Vector2D friction);

    void calculateMovement(double deltaTime, float gravity);

    void resetGravitationalAcceleration();

private:
    float mass;
    float gravity;

private:
    physics::Vector2D force;
    physics::Vector2D friction;

    physics::Vector2D position;
    physics::Vector2D velocity;
    physics::Vector2D acceleration;
};

#endif //MEXIBUNNY_RIGID_BODY_H
