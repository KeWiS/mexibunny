#include "map.h"
#include "../game_objects/environment_block.h"

Map *Map::getInstance() {
    if (map == nullptr) {
        map = new Map();
    }

    return map;
}

std::vector<map::Level> Map::getLevels() {
    return levels;
}

void Map::createLevel(std::vector<std::tuple<float, float, float, float, int, int, std::string>> entitiesSegments) {
    map::Level level = map::Level(std::vector<SDL_FRect>());

    for (auto entitySegment : entitiesSegments) {
        auto segmentX = std::get<0>(entitySegment);
        auto segmentY = std::get<1>(entitySegment);
        auto segmentHeight = std::get<2>(entitySegment);
        auto segmentBlockAmount = std::get<3>(entitySegment);
        auto segmentBlockTextureIndex = std::get<4>(entitySegment);
        auto segmentBlockSize = std::get<5>(entitySegment);
        auto segmentObjectName = std::get<6>(entitySegment);

        level.addToSegments({segmentX, segmentY, segmentBlockAmount * segmentBlockSize,
                             segmentHeight});

        for (int i = 0; i < segmentBlockAmount; i++) {
            level.addToEntities(EnvironmentBlock(segmentX + i * segmentBlockSize, segmentY,
                                                 segmentBlockTextureIndex, segmentBlockSize,
                                                 segmentBlockSize, segmentObjectName));
        }
    }

    levels.push_back(level);
}
