#ifndef MEXIBUNNY_GAME_H
#define MEXIBUNNY_GAME_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <vector>
#include "render_helper.h"
#include "../physics/engine.h"
#include "../game_objects/player.h"
#include "../map/map.h"

class Game {
public:
    Game(int gameWindowWidth, int gameWindowHeight);

    inline static double const targetDeltaTime = 1000 / 60;
    inline static double const maxDeltaTime = 7;

private:
    int windowWidth, windowHeight;

    bool gameInProgress;

    Uint64 previousTick = 0;
    Uint64 currentTick = SDL_GetPerformanceCounter();
    double deltaTime = 0;
    double spawnerTimer = 0;
    double spawnDelay = 2000;

    int spawnCounter = 0;

    RenderHelper renderHelper;

    Player *player;

    std::vector<Character*> enemies = std::vector<Character*>();

    void generateEnvironment();

    TextureHolder loadAllTextures();

    Player *generatePlayer();

    void generateInitialEnemies();

    void spawnBananaOnSegment(SegmentFrect &segment);

    void initGame();

    void startGame();

    void updateGameState();

    double calculateDeltaTime();

    void delayToMeetFrameRateLimit();

    void handleGameEvents();

    void handlePlayerMovement();

    void prepareForPlayerStrike();

    void checkPlayerStrikeCollision(Player *player);

    void applyDamageAfterHit(int minDamage, int maxDamage, Character &victim);

    bool checkIfEnemyDied(Character &enemy);

    void cleanupAfterPlayerStrike();

    void calculateBodiesPhysics();

    void checkCharacterCollisionsWithEnvironment(Character &character);

    void updateCharacterXPositionAfterCalculations(Character &character);

    void updateCharacterYPositionAfterCalculations(Character &character);

    void manageEnemySpawns();

    void spawnEnemyOnRandomSegment();

    void updateGraphics();

    void renderEntities();

    void renderEnemies();

    void closeGame();

    void destroyTextures();

    void destroyCharacters();

    void quitLibrariesEntities();
};

#endif //MEXIBUNNY_GAME_H
