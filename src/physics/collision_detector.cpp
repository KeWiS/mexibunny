#include "collision_detector.h"
#include "../map/map.h"
#include "../physics/engine.h"

bool CollisionDetector::checkCharacterCollisionWithEnvironment(const Character &character) {
    for (auto level : Map::getInstance()->getLevels()) {
        for (auto segment : level.getSegments()) {
            if (physics::Engine::collisionAABB(character.getCollider(), segment.frect)) {
                return true;
            }
        }
    }

    return false;
}
