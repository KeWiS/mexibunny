#ifndef MEXIBUNNY_MAP_H
#define MEXIBUNNY_MAP_H

#include "level.h"
#include <string>
#include <vector>
#include <tuple>

class Map {
public:
    Map(Map &otherMap) = delete;

    void operator=(const Map &) = delete;

    static Map *getInstance();

    std::vector<map::Level> getLevels();

    void createLevel(std::vector<std::tuple<float, float, float, float, int, int, std::string>> entitiesSegments);

private:
    Map() = default;

    inline static Map *map = nullptr;

    std::vector<map::Level> levels;
};

#endif //MEXIBUNNY_MAP_H
