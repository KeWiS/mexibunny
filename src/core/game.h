#ifndef MEXIBUNNY_GAME_H
#define MEXIBUNNY_GAME_H
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "render_helper.h"
#include "../game_objects/player.h"

class Game {
public:
    Game(int gameWindowWidth, int gameWindowHeight);

private:
    bool gameInProgress;

    Uint64 previousTick = 0;
    Uint64 currentTick = SDL_GetTicks64();
    double deltaTime = 0;

    RenderHelper renderHelper;

    Player player;

    void initGame();

    void startGame();

    void updateGameState();

    void handleGameEvents();

    void updateGraphics();

    void closeGame();
};

#endif //MEXIBUNNY_GAME_H
