#include "map.h"
#include "../game_objects/environment_block.h"
#include "segment_frect.h"

Map *Map::getInstance() {
    if (map == nullptr) {
        map = new Map();
    }

    return map;
}

std::vector<map::Level> Map::getLevels() {
    return levels;
}

void Map::createLevel(
        std::vector<SegmentParameters> entitiesSegments
) {
    map::Level level = map::Level(std::vector<SegmentFrect>());

    for (auto entitySegment : entitiesSegments) {
        SDL_FRect segmentRect = {entitySegment.segmentX, entitySegment.segmentY,
                                 entitySegment.segmentBlockAmount * entitySegment.segmentBlockSize,
                                 entitySegment.segmentHeight};

        level.addToSegments(SegmentFrect(entitySegment.allowSpawnOnSegment, segmentRect));

        for (int i = 0; i < entitySegment.segmentBlockAmount; i++) {
            level.addToEntities(EnvironmentBlock(entitySegment.segmentX + i * entitySegment.segmentBlockSize,
                                                 entitySegment.segmentY,
                                                 entitySegment.segmentBlockTextureIndex,
                                                 entitySegment.segmentBlockSize,
                                                 entitySegment.segmentBlockSize,
                                                 entitySegment.segmentObjectName));
        }
    }

    levels.push_back(level);
}

void Map::registerSpawnableSegments() {
    for (auto &level : levels) {
        for (auto &segment : level.getSegments()) {
            if (segment.allowSpawnOnSegment) spawnableSegments.push_back(&segment);
        }
    }
}

std::vector<SegmentFrect *> Map::getSpawnableSegments() {
    return spawnableSegments;
}
