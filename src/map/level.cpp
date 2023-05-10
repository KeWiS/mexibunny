#include "level.h"

map::Level::Level(std::vector<SegmentFrect> p_segments) : segments(p_segments) {}

std::vector<Entity> map::Level::getEntities() {
    return entities;
}

void map::Level::addToEntities(Entity entity) {
    entities.push_back(entity);
}

std::vector<SegmentFrect> &map::Level::getSegments() {
    return segments;
}

void map::Level::addToSegments(SegmentFrect segment) {
    segments.push_back(segment);
}
