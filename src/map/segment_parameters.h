#ifndef MEXIBUNNY_SEGMENT_PARAMETERS_H
#define MEXIBUNNY_SEGMENT_PARAMETERS_H

#include <string>

struct SegmentParameters {
    SegmentParameters(float p_segmentX, float p_segmentY, float p_segmentHeight, float p_segmentBlockAmount,
                      int p_segmentBlockTextureIndex, int p_segmentBlockSize, std::string p_segmentObjectName,
                      bool p_allowSpawnOnSegment) :
                      segmentX(p_segmentX), segmentY(p_segmentY), segmentHeight(p_segmentHeight),
                      segmentBlockAmount(p_segmentBlockAmount), segmentBlockTextureIndex(p_segmentBlockTextureIndex),
                      segmentBlockSize(p_segmentBlockSize), segmentObjectName(p_segmentObjectName),
                      allowSpawnOnSegment(p_allowSpawnOnSegment) {}

    float segmentX;
    float segmentY;
    float segmentHeight;
    float segmentBlockAmount;
    int segmentBlockTextureIndex;
    int segmentBlockSize;
    std::string segmentObjectName;
    bool allowSpawnOnSegment;
};

#endif //MEXIBUNNY_SEGMENT_PARAMETERS_H
