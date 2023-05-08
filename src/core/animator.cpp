#include "animator.h"
#include <iostream>

float Animator::computeCharacterIdleTextureOffset(Character &character) {
    int characterIdleIndex = character.getIdleAnimationIndex();

    if (character.getAnimationTimeCounter() >= 400) {
        if (character.getIdleAnimationIndex() == character.getIdleAnimationFrames()) {
            character.setIdleAnimationIndex(0);
            characterIdleIndex = 0;
        } else {
            character.setIdleAnimationIndex(++characterIdleIndex);
        }

        character.resetAnimationTimeCounter();
    }

    return characterIdleIndex * 32;
}

float Animator::computeCharacterMovingTextureOffset(Character &character) {
    int characterMovingIndex = character.getMovingAnimationIndex();

    if (character.getAnimationTimeCounter() >= 200) {
        if (character.getMovingAnimationIndex() == character.getMovingAnimationFrames()) {
            character.setMovingAnimationIndex(0);
            characterMovingIndex = 0;
        } else {
            character.setMovingAnimationIndex(++characterMovingIndex);
        }

        character.resetAnimationTimeCounter();
    }

    return characterMovingIndex * 32;
}

float Animator::computeCharacterInAirTextureOffset(Character &character) {
    int characterInAirIndex = character.getInAirAnimationIndex();

    if (character.getAnimationTimeCounter() >= 150) {
        if (character.getInAirAnimationIndex() == character.getInAirAnimationFrames()) {
            character.setInAirAnimationIndex(0);
            characterInAirIndex = 0;
        } else {
            character.setInAirAnimationIndex(++characterInAirIndex);
        }

        character.resetAnimationTimeCounter();
    }

    return characterInAirIndex * 32;
}

float Animator::computeCharacterStrikeTextureOffset(Character &character) {
    int playerStrikeIndex = character.getStrikeAnimationIndex();
    // Time of one animation frame is based on max strike time divided by animation frames count (+1 indexing from 0)
    if (character.getAnimationTimeCounter() >=
        character.getMaxStrikeTime() / (character.getStrikeAnimationFrames() + 1)) {
        if (character.getStrikeAnimationIndex() == character.getStrikeAnimationFrames()) {
            character.setStrikeAnimationIndex(0);
            playerStrikeIndex = 0;
        } else {
            character.setStrikeAnimationIndex(++playerStrikeIndex);
        }

        character.resetAnimationTimeCounter();
    }

    return playerStrikeIndex * 64;
}
