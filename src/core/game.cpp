#include "game.h"
#include "constants.h"
#include <SDL_image.h>
#include <cmath>

Game::Game(int gameWindowWidth, int gameWindowHeight) : windowWidth(gameWindowWidth), windowHeight(gameWindowHeight) {
    this->renderHelper = RenderHelper(gameWindowWidth, gameWindowHeight);

    initGame();
}

void Game::initGame() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    renderHelper.initiateWindow();

    this->player = generatePlayer();
    this->grassCollection = generateGrassCollection();

    startGame();
}

Player Game::generatePlayer() {
    SDL_Texture *bunnyLeft = renderHelper.loadTexture(constants::file_names::kBunnyLeft);
    SDL_Texture *bunnyRight = renderHelper.loadTexture(constants::file_names::kBunnyRight);

    return Player(100, 592, bunnyLeft, bunnyRight);
}

std::vector<Grass> Game::generateGrassCollection() {
    std::vector<Grass> generatedGrass = std::vector<Grass>();


    for (int i = 0; i < std::floor(windowWidth / 64); i++) {
        Grass grass = Grass(i * 64, 656,
                            renderHelper.loadTexture(constants::file_names::kGrassFilePath));

        generatedGrass.push_back(grass);
    }

    return generatedGrass;
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
    if (keyStates[SDL_SCANCODE_UP]) player.setY(player.getY() - 0.3 * deltaTime);
    if (keyStates[SDL_SCANCODE_DOWN]) player.setY(player.getY() + 0.3 * deltaTime);
    if (keyStates[SDL_SCANCODE_LEFT]) {
        player.setX(player.getX() - 0.3 * deltaTime);
        player.setMovement(Movement::kLeft);
    }
    if (keyStates[SDL_SCANCODE_RIGHT]) {
        player.setX(player.getX() + 0.3 * deltaTime);
        player.setMovement(Movement::kRight);
    }
}

void Game::updateGraphics() {
    renderHelper.cleanRenderer();
    for (Entity grass : grassCollection) {
        renderHelper.renderEntity(grass);
    }
    renderHelper.renderCharacter(player);
    renderHelper.display();
}

void Game::closeGame() {
    renderHelper.cleanup();
    SDL_Quit();
}
