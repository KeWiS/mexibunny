#include <iostream>
#include "collision_detector.h"
#include "../map/map.h"
#include "../physics/engine.h"

bool CollisionDetector::checkCharacterCollisionWithEnvironment(Character &character) {
    int segmentIndex = 0;

    for (auto level : Map::getInstance()->getLevels()) {
        for (int i = 0; i < level.getSegments().size(); i++) {
            if (physics::Engine::collisionAABB(character.getCollider(), level.getSegments()[i].frect)) {
                character.setCurrentSegment(segmentIndex + i);

                return true;
            }
        }
        segmentIndex += level.getSegments().size();
    }

    return false;
}

bool CollisionDetector::checkCharacterToCharacterStrikeCollision(const Character &strikingCharacter,
                                                                 const Character &victim) {
    return physics::Engine::collisionAABB(strikingCharacter.getWeaponCollider(), victim.getCollider());
}
