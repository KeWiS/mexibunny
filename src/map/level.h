#ifndef MEXIBUNNY_LEVEL_H
#define MEXIBUNNY_LEVEL_H

#include <vector>
#include "../game_objects/entity.h"

namespace map {
    class Level {
    public:
        Level(std::vector<SDL_FRect> p_segments);

        std::vector<Entity> getEntities();

        void addToEntities(Entity entity);

        std::vector<SDL_FRect> getSegments();

        void addToSegments(SDL_FRect segment);

    private:
        std::vector<Entity> entities;
        std::vector<SDL_FRect> segments;
    };
}

#endif //MEXIBUNNY_LEVEL_H
