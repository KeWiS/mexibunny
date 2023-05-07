#ifndef MEXIBUNNY_CHARACTER_H
#define MEXIBUNNY_CHARACTER_H

#include "../enums/movement.h"
#include "../physics/vector2D.h"
#include "../physics/rigid_body.h"
#include "../core/constants.h"
#include <SDL.h>
#include <string>

// Top-level class for character objects (player, enemies)
class Character : public RigidBody {
public:
    const std::string textureKeyName;

    Character() {}

    virtual ~Character() = default;

    Character(float posX, float posY, std::string objName, float mass, int idleAnimFrames, int movingAnimFrames,
              int inAirAnimFrames, int destRenderWidth, int destRenderHeight);

    physics::Vector2D &getPositionVector();

    physics::Vector2D &getLastSafePosition();

    bool getIsGrounded();

    void setIsGrounded(bool isGrounded);

    bool getIsJumping();

    void setIsJumping(bool isJumping);

    float getX();

    void setX(float x);

    float getY();

    void setY(float y);

    int getIdleAnimationFrames();

    int getIdleAnimationIndex();

    void setIdleAnimationIndex(int idleAnimationIndex);

    int getMovingAnimationFrames();

    int getMovingAnimationIndex();

    void setMovingAnimationIndex(int movingAnimationIndex);

    int getInAirAnimationFrames();

    int getInAirAnimationIndex();

    void setInAirAnimationIndex(int inAirAnimationIndex);

    int getDestinationRenderWidth();

    int getDestinationRenderHeight();

    bool shouldTextureBeHorizontallyFlipped();

    float getJumpTime();

    void setJumpTime(float jumpTime);

    void decreaseJumpTime(double timeToDecrease);

    float getJumpForce();

    void setJumpForce(float jumpForce);

    SDL_FRect &getModel();

    SDL_FRect &getMutableCollider();

    const SDL_FRect &getCollider() const;

    Movement getMovement();

    void setMovement(Movement movement);

    Movement getLastRecordedMovementDirection();

    void setLastRecordedMovementDirection(Movement lastRecordedMovementDirection);

private:
    physics::Vector2D positionVector;
    physics::Vector2D lastSafePosition;

    bool isGrounded;
    bool isJumping = false;

    int idleAnimationFrames, idleAnimationIndex = 0;
    int movingAnimationFrames, movingAnimationIndex = 0;
    int inAirAnimationFrames, inAirAnimationIndex = 0;
    int destinationRenderWidth, destinationRenderHeight;

    float jumpTime = constants::physics::kJumpTime;
    float jumpForce;

    SDL_FRect model;
    SDL_FRect collider;
    Movement movement;
    Movement lastRecordedMovementDirection;
};

#endif //MEXIBUNNY_CHARACTER_H
