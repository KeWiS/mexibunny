#include "animator.h"
#include <iostream>

float Animator::computeCharacterIdleTextureOffset(Character &character) {
    int playerIdleIndex = character.getIdleAnimationIndex();

    if (character.getAnimationTimeCounter() >= 400) {
        if (character.getIdleAnimationIndex() == character.getIdleAnimationFrames()) {
            character.setIdleAnimationIndex(0);
            playerIdleIndex = 0;
        } else {
            character.setIdleAnimationIndex(++playerIdleIndex);
        }

        character.resetAnimationTimeCounter();
    }

    return playerIdleIndex * 32;
}

float Animator::computeCharacterMovingTextureOffset(Character &character) {
    int playerMovingIndex = character.getMovingAnimationIndex();

    if (character.getAnimationTimeCounter() >= 200) {
        if (character.getMovingAnimationIndex() == character.getMovingAnimationFrames()) {
            character.setMovingAnimationIndex(0);
            playerMovingIndex = 0;
        } else {
            character.setMovingAnimationIndex(++playerMovingIndex);
        }

        character.resetAnimationTimeCounter();
    }

    return playerMovingIndex * 32;
}

float Animator::computeCharacterInAirTextureOffset(Character &character) {
    int playerInAirIndex = character.getInAirAnimationIndex();

    if (character.getAnimationTimeCounter() >= 150) {
        if (character.getInAirAnimationIndex() == character.getInAirAnimationFrames()) {
            character.setInAirAnimationIndex(0);
            playerInAirIndex = 0;
        } else {
            character.setInAirAnimationIndex(++playerInAirIndex);
        }

        character.resetAnimationTimeCounter();
    }

    return playerInAirIndex * 32;
}
