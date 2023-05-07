#ifndef MEXIBUNNY_LEVEL_H
#define MEXIBUNNY_LEVEL_H

#include "../game_objects/entity.h"
#include "segment_frect.h"
#include <vector>
#include <tuple>

namespace map {
    class Level {
    public:
        Level(std::vector<SegmentFrect> p_segments);

        std::vector<Entity> getEntities();

        void addToEntities(Entity entity);

        std::vector<SegmentFrect> getSegments();

        void addToSegments(SegmentFrect segment);

    private:
        std::vector<Entity> entities;
        std::vector<SegmentFrect> segments;
    };
}

#endif //MEXIBUNNY_LEVEL_H
