#ifndef MEXIBUNNY_CHARACTER_H
#define MEXIBUNNY_CHARACTER_H

#include "../enums/movement.h"
#include "../physics/vector2D.h"
#include "../physics/rigid_body.h"
#include <SDL.h>
#include <string>

// Top-level class for character objects (player, enemies)
class Character : public RigidBody {
public:
    const std::string textureKeyName;

    Character() {}

    virtual ~Character() = default;

    Character(float posX, float posY, std::string objName, float mass, int idleAnimFrames, int movingAnimFrames,
              int destRenderWidth, int destRenderHeight);

    physics::Vector2D &getPositionVector();

    void setPositionVector(physics::Vector2D positionVector);

    physics::Vector2D &getLastSafePosition();

    void setLastSafePosition(physics::Vector2D lastSafePosition);

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

    int getDestinationRenderWidth();

    int getDestinationRenderHeight();

    bool shouldTextureBeHorizontallyFlipped();

    void setShouldTextureBeHorizontallyFlipped(bool shouldTextureBeHorizFlipped);

    SDL_FRect &getModel();

    SDL_FRect &getMutableCollider();

    const SDL_FRect &getCollider() const;

    Movement getMovement();

    void setMovement(Movement movement);

private:
    physics::Vector2D positionVector;
    physics::Vector2D lastSafePosition;

    int idleAnimationFrames, idleAnimationIndex = -1;
    int movingAnimationFrames, movingAnimationIndex = 0;
    int destinationRenderWidth, destinationRenderHeight;
    bool shouldTextureBeHorizFlipped;

    float ph_mass = 1.0f;

    SDL_FRect model;
    SDL_FRect collider;
    Movement movement;
};

#endif //MEXIBUNNY_CHARACTER_H
