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
    // Music, credits to: https://youtu.be/EQmIBHObtCs
    inline const char *kMainMusic = "../resources/sound/The_Only_Thing_They_Fear_Is_You_DOOM_Eternal_OST.mp3";
    // Background, credits to: https://www.pinterest.com/pin/39054721754164011/
    inline const char *kBackground = "../resources/textures/background.png";
    // Environment
    inline const char *kGroundFilePath = "../resources/textures/ground.png";
    inline const char *kGrass1FilePath = "../resources/textures/grass_1.png";
    inline const char *kGrass2FilePath = "../resources/textures/grass_2.png";
    inline const char *kGrass3FilePath = "../resources/textures/grass_3.png";
    // Characters
    // Player
    inline const char *kBunnyRun = "../resources/textures/bunny_run.png";
    inline const char *kBunnyIdle = "../resources/textures/bunny_idle.png";
    inline const char *kBunnyInAir = "../resources/textures/bunny_in_air.png";
    inline const char *kBunnyStrike = "../resources/textures/bunny_strike.png";
    // Enemies
    inline const char *kBananaRun = "../resources/textures/banana_run.png";
    inline const char *kBananaIdle = "../resources/textures/banana_idle.png";
    inline const char *kBananaInAir = "../resources/textures/banana_in_air.png";
}

#endif //MEXIBUNNY_CONSTANTS_H
