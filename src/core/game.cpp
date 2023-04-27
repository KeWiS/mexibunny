#include "game.h"
#include "constants.h"
#include "texture_holder.h"
#include <SDL_image.h>
#include <cmath>
#include <iostream>

Game::Game(int gameWindowWidth, int gameWindowHeight) : windowWidth(gameWindowWidth), windowHeight(gameWindowHeight) {
    this->renderHelper = RenderHelper(gameWindowWidth, gameWindowHeight);

    initGame();
}

void Game::initGame() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    renderHelper.initiateWindow();
    renderHelper.setTextureHolder(loadAllTextures());

    this->player = generatePlayer();
    this->entitiesCollection = generateEntitiesCollection();

    startGame();
}

TextureHolder Game::loadAllTextures() {
    TextureHolder textureHolder;

    textureHolder.textureMap.insert({"grass",
                                     renderHelper.loadTexture(constants::file_names::kGrassFilePath)});
    textureHolder.textureMap.insert({"playerLeft",
                                     renderHelper.loadTexture(constants::file_names::kBunnyLeft)});
    textureHolder.textureMap.insert({"playerRight",
                                     renderHelper.loadTexture(constants::file_names::kBunnyRight)});

    return textureHolder;
}

Player Game::generatePlayer() {
    return Player(100, 592, 80);
}

std::vector<Entity> Game::generateEntitiesCollection() {
    std::vector<Entity> generatedGrass = std::vector<Entity>();

    // Calculating how many ground grass there should be
    for (int i = 0; i < std::floor(windowWidth / 64); i++) {
        Grass grass = Grass(i * 64, 656);

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

    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            case SDL_QUIT:
                gameInProgress = false;

                return;
        }
    }

    auto *keyStates = SDL_GetKeyboardState(nullptr);

    handlePlayerMovement(keyStates);
}

void Game::handlePlayerMovement(const Uint8 *keyStates) {
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

    for (Entity entity : entitiesCollection) {
        renderHelper.renderEntity(entity);
    }

    renderHelper.renderCharacter(player);
    renderHelper.display();
}

void Game::closeGame() {
    destroyTextures();

    renderHelper.cleanup();

    SDL_Quit();

    std::cout << "Game has been closed.";
}

void Game::destroyTextures() {
    for (auto &textureMapEntry : renderHelper.getTextureHolder().textureMap) {
        SDL_DestroyTexture(textureMapEntry.second);
    }
}
