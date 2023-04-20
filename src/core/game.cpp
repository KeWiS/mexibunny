#include "game.h"
#include "constants.h"
#include <SDL_image.h>

Game::Game(int gameWindowWidth, int gameWindowHeight) {
    this->renderHelper = RenderHelper(gameWindowWidth, gameWindowHeight);
    this->player = Player();

    this->grassCollection = generateGrassCollection();

    initGame();
}

std::vector<Grass> Game::generateGrassCollection() {
    std::vector<Grass> generatedGrass = std::vector<Grass>();

    Grass grass = Grass(0, 0, 32, 32);
    generatedGrass.push_back(grass);

    return generatedGrass;
}

void Game::initGame() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    renderHelper.initiateWindow();
    loadAllTextures();

    startGame();
}

void Game::loadAllTextures() {
    // Texture loading for player
    //player.setTexture(renderHelper.loadTexture(""));
    // Texture loading for grass
    for (auto &grass: grassCollection) {
        grass.setTexture(renderHelper.loadTexture(constants::file_names::kGrassFilePath));
    }
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
    renderHelper.cleanRenderer();
    renderHelper.renderBackground(grassCollection[0].getTexture());
    renderHelper.render(player);
    renderHelper.display();
}

void Game::closeGame() {
    renderHelper.cleanup();
    SDL_Quit();
}
