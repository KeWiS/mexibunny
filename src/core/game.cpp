#include "game.h"

Game::Game(int gameWindowWidth, int gameWindowHeight) {
    this->renderHelper = RenderHelper(gameWindowWidth, gameWindowHeight);
    this->player = Player();

    initGame();
}

void Game::initGame() {
    SDL_Init(SDL_INIT_EVERYTHING);

    renderHelper.initiateWindow();

    startGame();
}

void Game::startGame() {
    gameInProgress = true;

    while (gameInProgress) {
        updateGameState();
    }

    closeGame();
}

void Game::updateGameState() {
    previousTick = currentTick;
    currentTick = SDL_GetTicks64();
    deltaTime = currentTick - previousTick;

    handleGameEvents();
    updateGraphics();
}

void Game::handleGameEvents() {
    SDL_Event e;
    auto *keyStates = SDL_GetKeyboardState(nullptr);

    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                gameInProgress = false;

                break;
        }
    }

    if (keyStates[SDL_SCANCODE_UP]) player.getModel().y -= 0.1 * deltaTime;
    if (keyStates[SDL_SCANCODE_DOWN]) player.getModel().y += 0.1 * deltaTime;
    if (keyStates[SDL_SCANCODE_LEFT]) player.getModel().x -= 0.1 * deltaTime;
    if (keyStates[SDL_SCANCODE_RIGHT]) player.getModel().x += 0.1 * deltaTime;
}

void Game::updateGraphics() {
    renderHelper.renderBackground();
    renderHelper.render(player);
    renderHelper.display();
}

void Game::closeGame() {
    renderHelper.cleanup();
    SDL_Quit();
}
