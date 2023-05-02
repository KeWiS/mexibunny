#include "map.h"

Map *Map::getInstance() {
    if (map == nullptr) {
        map = new Map();
    }

    return map;
}

std::vector<map::Level> Map::getLevels() {
    return levels;
}
