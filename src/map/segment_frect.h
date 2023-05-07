#ifndef MEXIBUNNY_SEGMENT_FRECT_H
#define MEXIBUNNY_SEGMENT_FRECT_H

#include <SDL.h>

struct SegmentFrect {
    SegmentFrect(bool p_allowSpawnOnSegment, SDL_FRect p_frect) :
            allowSpawnOnSegment(p_allowSpawnOnSegment), frect(p_frect) {}

    bool allowSpawnOnSegment;
    SDL_FRect frect;
};

#endif //MEXIBUNNY_SEGMENT_FRECT_H
