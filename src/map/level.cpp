#include "level.h"

map::Level::Level(std::vector<SDL_FRect> p_segments) : segments(p_segments) {}

std::vector<Entity> map::Level::getEntities() {
    return entities;
}

void map::Level::addToEntities(Entity entity) {
    entities.push_back(entity);
}

std::vector<SDL_FRect> map::Level::getSegments() {
    return segments;
}

void map::Level::addToSegments(SDL_FRect segment) {
    segments.push_back(segment);
}
