#include "game.h"
#include "constants.h"
#include "texture_holder.h"
#include "../physics/engine.h"
#include "../utility/randomizer.h"
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

    renderHelper.initiateWindowAndRender();
    renderHelper.setTextureHolder(loadAllTextures());

    this->player = generatePlayer();
    this->entitiesCollection = generateEntitiesCollection();

    startGame();
}

TextureHolder Game::loadAllTextures() {
    TextureHolder textureHolder;

    // Environment
    textureHolder.textureMap.insert({"grass1",
                                     renderHelper.loadTexture(constants::file_names::kGrass1FilePath)});
    textureHolder.textureMap.insert({"grass2",
                                     renderHelper.loadTexture(constants::file_names::kGrass2FilePath)});
    textureHolder.textureMap.insert({"grass3",
                                     renderHelper.loadTexture(constants::file_names::kGrass3FilePath)});
    // Player
    textureHolder.textureMap.insert({"playerLeft",
                                     renderHelper.loadTexture(constants::file_names::kBunnyLeft)});
    textureHolder.textureMap.insert({"playerRight",
                                     renderHelper.loadTexture(constants::file_names::kBunnyRight)});
    textureHolder.textureMap.insert({"playerLeftIdle",
                                     renderHelper.loadTexture(constants::file_names::kBunnyLeftIdle)});
    textureHolder.textureMap.insert({"playerRightIdle",
                                     renderHelper.loadTexture(constants::file_names::kBunnyRightIdle)});

    return textureHolder;
}

Player Game::generatePlayer() {
    return Player(100, 100, 80, 64, 64);
}

std::vector<Entity> Game::generateEntitiesCollection() {
    std::vector<Entity> generatedGrass = std::vector<Entity>();
    // Calculating how many ground grass there should be
    // Generating random number to pick grass texture (1-3 range)
    for (int i = 0; i < std::floor(windowWidth / 64); i++) {
        Grass grass = Grass(i * 64, 656,
                            utility::Randomizer::getRandomIntegerInRange(1, 3),
                            64, 64);

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
    // Updating animationTimeCounter for proper animations displaying
    updateAnimationTimeCounter();
    // Handling game events, player movement, calculations of NPC movements and physics, graphics display
    handleGameEvents();
    handlePlayerMovement();
    calculateBodiesPhysics();
    updateGraphics();
}

double Game::calculateDeltaTime() {
    previousTick = currentTick;
    currentTick = SDL_GetTicks64();

    return currentTick - previousTick;
}

void Game::updateAnimationTimeCounter() {
    animationTimeCounter += deltaTime;
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
}

void Game::handlePlayerMovement() {
    auto *keyStates = SDL_GetKeyboardState(nullptr);

    if (player.getMovement() == Movement::kLeft || player.getMovement() == Movement::kLeftIdle) {
        player.setMovement(Movement::kLeftIdle);
    } else {
        player.setMovement(Movement::kRightIdle);
    }


    // TODO: Rewrite movement logic to match new physics system
//    if (keyStates[SDL_SCANCODE_LEFT]) {
//        player.setX(player.getX() - 0.3 * deltaTime);
//        player.setMovement(Movement::kLeft);
//    }
//    if (keyStates[SDL_SCANCODE_RIGHT]) {
//        player.setX(player.getX() + 0.3 * deltaTime);
//        player.setMovement(Movement::kRight);
//    }
}

void Game::calculateBodiesPhysics() {
    // Player
    physics::Engine::calculateRigidBodyMovement(player, deltaTime);
    updatePlayerPositionAfterCalculations();
}

void Game::updatePlayerPositionAfterCalculations() {
    player.setX(player.getCVector().getVX() + player.getPosition().getVX());
    player.setY(player.getCVector().getVY() + player.getPosition().getVY());
}

void Game::updateGraphics() {
    renderHelper.cleanRenderer();

    renderEntities();
    renderHelper.renderCharacter(player);

    renderHelper.display();
}

void Game::renderEntities() {
    for (Entity entity : entitiesCollection) {
        renderHelper.renderEntity(entity);
    }
}

void Game::closeGame() {
    // Destroying all textures from texture map
    destroyTextures();
    // Cleanup inside renderHelper, destroying renderer and window
    renderHelper.cleanup();
    // Quitting initialized libraries
    quitLibrariesEntities();

    std::cout << "Game has been closed.";
}

void Game::destroyTextures() {
    for (auto &textureMapEntry : renderHelper.getTextureHolder().textureMap) {
        SDL_DestroyTexture(textureMapEntry.second);
    }

    renderHelper.getTextureHolder().textureMap.clear();
}

void Game::quitLibrariesEntities() {
    IMG_Quit();
    SDL_Quit();
}
