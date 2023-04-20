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
    // Calculating delta time for physics and other computations
    deltaTime = calculateDeltaTime();
    // Handling game events, player movement, calculations of NPC movements and physics
    handleGameEvents();
    updateGraphics();
}

double Game::calculateDeltaTime() {
    previousTick = currentTick;
    currentTick = SDL_GetTicks64();

    return currentTick - previousTick;
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

    handlePlayerMovement(keyStates);
}

void Game::handlePlayerMovement(const Uint8 *keyStates) {
    if (keyStates[SDL_SCANCODE_UP]) player.getModel().y -= 0.3 * deltaTime;
    if (keyStates[SDL_SCANCODE_DOWN]) player.getModel().y += 0.3 * deltaTime;
    if (keyStates[SDL_SCANCODE_LEFT]) player.getModel().x -= 0.3 * deltaTime;
    if (keyStates[SDL_SCANCODE_RIGHT]) player.getModel().x += 0.3 * deltaTime;
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
