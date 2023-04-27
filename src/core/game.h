#ifndef MEXIBUNNY_GAME_H
#define MEXIBUNNY_GAME_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <vector>
#include "render_helper.h"
#include "../engine/physics.h"
#include "../game_objects/player.h"
#include "../game_objects/grass.h"

class Game {
public:
    Game(int gameWindowWidth, int gameWindowHeight);

private:
    int windowWidth, windowHeight;

    bool gameInProgress;

    Uint64 previousTick = 0;
    Uint64 currentTick = SDL_GetTicks64();
    double deltaTime = 0;

    RenderHelper renderHelper;

    Physics physics = Physics();

    Player player;

    std::vector<Entity> entitiesCollection;

    std::vector<Entity> generateEntitiesCollection();

    TextureHolder loadAllTextures();

    Player generatePlayer();

    void initGame();

    void startGame();

    void updateGameState();

    double calculateDeltaTime();

    void handleGameEvents();

    void handlePlayerMovement(const Uint8 *keyStates);

    void updateGraphics();

    void closeGame();

    void destroyTextures();
};

#endif //MEXIBUNNY_GAME_H
