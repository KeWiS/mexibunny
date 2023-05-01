#include "animator.h"
#include "game.h"
#include <iostream>

float Animator::computeCharacterIdleTextureOffset(Character &character) {
    int playerIdleIndex = character.getIdleAnimationIndex();

    if (Game::animationTimeCounter >= 500) {
        if (character.getIdleAnimationIndex() == character.getIdleAnimationFrames()) {
            character.setIdleAnimationIndex(0);
            playerIdleIndex = 0;
        } else {
            character.setIdleAnimationIndex(++playerIdleIndex);
        }

        Game::animationTimeCounter = 0;
    }

    return playerIdleIndex * 32;
}

float Animator::computeCharacterMovingTextureOffset(Character &character) {
    int playerMovingIndex = character.getMovingAnimationIndex();

    if (Game::animationTimeCounter >= 250) {
        if (character.getMovingAnimationIndex() == character.getMovingAnimationFrames()) {
            character.setMovingAnimationIndex(0);
            playerMovingIndex = 0;
        } else {
            character.setMovingAnimationIndex(++playerMovingIndex);
        }

        Game::animationTimeCounter = 0;
    }

    std::cout << playerMovingIndex * 32 << std::endl;

    return playerMovingIndex * 32;
}
