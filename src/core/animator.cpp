#include "animator.h"
#include "game.h"

float Animator::computePlayerIdleTextureOffset(Character &character) {
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
