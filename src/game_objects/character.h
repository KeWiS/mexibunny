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

    Character(float posX, float posY, int modelWidth, int modelHeight, std::string objName, float mass,
              int idleAnimFrames, int movingAnimFrames, int inAirAnimFrames, int strikeAnimFrames,
              int destRenderWidth, int destRenderHeight, double maxStrTime);

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

    int getStrikeAnimationFrames();

    int getStrikeAnimationIndex();

    void setStrikeAnimationIndex(int strikeAnimationIndex);

    int getDestinationRenderWidth();

    void setDestinationRenderWidth(int destinationRenderWidth);

    int getDestinationRenderHeight();

    int getInitialDestinationRenderWidth();

    int getInitialModelWidth();

    bool shouldTextureBeHorizontallyFlipped();

    double getAnimationTimeCounter();

    void resetAnimationTimeCounter();

    void addToAnimationTimeCounter(double timeToAdd);

    bool checkIsStriking();

    void setIsStriking(bool isStriking);

    double getMaxStrikeTime();

    double getStrikeTimeCounter();

    void resetStrikeTimeCounter();

    void decreaseStrikeTimeCounter(double timeToDecrease);

    float getJumpTime();

    void setJumpTime(float jumpTime);

    void decreaseJumpTime(double timeToDecrease);

    float getJumpForce();

    void setJumpForce(float jumpForce);

    SDL_FRect &getModel();

    SDL_FRect &getMutableCollider();

    const SDL_FRect &getCollider() const;

    const SDL_FRect &getWeaponCollider() const;

    SDL_FRect &getMutableWeaponCollider();

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
    int strikeAnimationFrames, strikeAnimationIndex = 0;
    int destinationRenderWidth, destinationRenderHeight;

    int initialDestinationRenderWidth, initialModelWidth;

    double animationTimeCounter = 0;

    bool isStriking = false;
    double maxStrikeTime;
    double strikeTimeCounter;

    float jumpTime = constants::physics::kJumpTime;
    float jumpForce;

    SDL_FRect model;
    SDL_FRect collider;
    SDL_FRect weaponCollider;

    Movement movement = Movement::kRightIdle;
    Movement lastRecordedMovementDirection = Movement::kRight;
};

#endif //MEXIBUNNY_CHARACTER_H
