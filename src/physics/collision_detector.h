#ifndef MEXIBUNNY_COLLISION_DETECTOR_H
#define MEXIBUNNY_COLLISION_DETECTOR_H

#include "../game_objects/character.h"

class CollisionDetector {
public:
    static bool checkCharacterCollisionWithEnvironment(const Character &character);

private:
    CollisionDetector() = default;
};

#endif //MEXIBUNNY_COLLISION_DETECTOR_H
