#ifndef MEXIBUNNY_MAP_H
#define MEXIBUNNY_MAP_H

#include "level.h"
#include <vector>
#include <tuple>

class Map {
public:
    Map(Map &otherMap) = delete;

    void operator=(const Map &) = delete;

    static Map *getInstance();

    std::vector<map::Level> getLevels();

    template<typename EnvBlock>
    void createLevel(std::vector<std::tuple<float, float, float, float, int, int>> entitiesSegments) {
        map::Level level = map::Level(std::vector<SDL_FRect>());

        for (auto entitySegment : entitiesSegments) {
            auto segmentX = std::get<0>(entitySegment);
            auto segmentY = std::get<1>(entitySegment);
            auto segmentHeight = std::get<2>(entitySegment);
            auto segmentBlockAmount = std::get<3>(entitySegment);
            auto segmentBlockTextureIndex = std::get<4>(entitySegment);
            auto segmentBlockSize = std::get<5>(entitySegment);

            level.addToSegments({segmentX, segmentY, segmentBlockAmount * segmentBlockSize,
                                 segmentHeight});

            for (int i = 0; i < segmentBlockAmount; i++) {
                level.addToEntities(EnvBlock(segmentX + i * segmentBlockSize, segmentY, segmentBlockTextureIndex,
                                             segmentBlockSize, segmentBlockSize));
            }
        }

        levels.push_back(level);
    }

private:
    Map() = default;

    inline static Map *map = nullptr;

    std::vector<map::Level> levels;
};

#endif //MEXIBUNNY_MAP_H
