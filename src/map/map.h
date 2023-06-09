#ifndef MEXIBUNNY_MAP_H
#define MEXIBUNNY_MAP_H

#include "level.h"
#include "segment_parameters.h"
#include <string>
#include <vector>
#include <tuple>

class Map {
public:
    Map(Map &otherMap) = delete;

    void operator=(const Map &) = delete;

    static Map *getInstance();

    std::vector<map::Level> getLevels();

    void createLevel(std::vector<SegmentParameters> entitiesSegments);

    void registerSpawnableSegments();

    std::vector<SegmentFrect *> getSpawnableSegments();

private:
    Map() = default;

    inline static Map *map = nullptr;

    std::vector<map::Level> levels;

    std::vector<SegmentFrect *> spawnableSegments;
};

#endif //MEXIBUNNY_MAP_H
