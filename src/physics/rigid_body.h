#ifndef MEXIBUNNY_RIGID_BODY_H
#define MEXIBUNNY_RIGID_BODY_H

#include "vector2D.h"

class RigidBody {
public:
    RigidBody();

    float getMass();

    void setMass(float mass);

    physics::Vector2D getForce();

    void setForce(physics::Vector2D force);

    physics::Vector2D getFriction();

    void setFriction(physics::Vector2D friction);

    physics::Vector2D getPosition();

    void setPosition(physics::Vector2D position);

    physics::Vector2D getVelocity();

    void setVelocity(physics::Vector2D velocity);

    physics::Vector2D getAcceleration();

    void applyForce(physics::Vector2D force);

    void applyForceOnXAxis(float forceX);

    void applyForceOnYAxis(float forceY);

    void removeForce();

    void applyFriction(physics::Vector2D friction);

    void removeFriction();

    void calculateMovement(double deltaTime, float gravity);

private:
    float mass;

private:
    physics::Vector2D force;
    physics::Vector2D friction;

    physics::Vector2D position;
    physics::Vector2D velocity;
    physics::Vector2D acceleration;
};

#endif //MEXIBUNNY_RIGID_BODY_H
