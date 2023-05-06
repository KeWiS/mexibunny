#ifndef MEXIBUNNY_CONSTANTS_H
#define MEXIBUNNY_CONSTANTS_H

namespace constants::physics {
    // Physics
    // Force modifiers
    inline const float kForwardForce = 1;
    inline const float kBackwardForce = -1;
    inline const float kUpwardForce = -1;
    inline const float kDownwardForce = 1;
    // Rigid body
    inline const float kJumpTime = 0.06;
}

namespace constants::file_names {
    // Background, credits to: https://www.pinterest.com/pin/39054721754164011/
    inline const char *kBackground = "../resources/textures/background.png";
    // Environment
    inline const char *kGrass1FilePath = "../resources/textures/grass_1.png";
    inline const char *kGrass2FilePath = "../resources/textures/grass_2.png";
    inline const char *kGrass3FilePath = "../resources/textures/grass_3.png";
    // Characters
    // Player
    inline const char *kBunnyRun = "../resources/textures/bunny_run.png";
    inline const char *kBunnyIdle = "../resources/textures/bunny_idle.png";
}

#endif //MEXIBUNNY_CONSTANTS_H
