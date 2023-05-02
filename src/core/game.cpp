#include "game.h"
#include "constants.h"
#include "texture_holder.h"
#include "../utility/randomizer.h"
#include "../physics/collision_detector.h"
#include "../map/map.h"
#include <SDL_image.h>
#include <utility>
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
    generateEnvironment();

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
    textureHolder.textureMap.insert({"playerRun",
                                     renderHelper.loadTexture(constants::file_names::kBunnyRun)});
    textureHolder.textureMap.insert({"playerIdle",
                                     renderHelper.loadTexture(constants::file_names::kBunnyIdle)});

    return textureHolder;
}

Player *Game::generatePlayer() {
    return new Player(100, 400, 80, 64, 64);
}

void Game::generateEnvironment() {
    // Generating ground level
    Map::getInstance()->createLevel<Grass>(
            {
                    std::make_tuple(0, 656, 32, windowWidth / 64,
                                    utility::Randomizer::getRandomIntegerInRange(1, 3), 64)
            });
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

    // Checking if idle
    if (player->getMovement() == Movement::kLeft || player->getMovement() == Movement::kLeftIdle) {
        player->setMovement(Movement::kLeftIdle);
        player->setShouldTextureBeHorizontallyFlipped(true);
        player->applyForceOnXAxis(0);
        player->applyFriction(physics::Vector2D(0, 0));
    } else {
        player->setMovement(Movement::kRightIdle);
        player->setShouldTextureBeHorizontallyFlipped(false);
        player->applyForceOnXAxis(0);
        player->applyFriction(physics::Vector2D(0, 0));
    }
    // Checking if moving
    if (keyStates[SDL_SCANCODE_A] || keyStates[SDL_SCANCODE_LEFT]) {
        player->setShouldTextureBeHorizontallyFlipped(true);
        player->applyForceOnXAxis(-1000);
        player->applyFriction(physics::Vector2D(200, 1));
        player->setMovement(Movement::kLeft);
    }
    if (keyStates[SDL_SCANCODE_D] || keyStates[SDL_SCANCODE_RIGHT]) {
        player->setShouldTextureBeHorizontallyFlipped(false);
        player->applyForceOnXAxis(1000);
        player->applyFriction(physics::Vector2D(200, 1));
        player->setMovement(Movement::kRight);
    }
}

void Game::calculateBodiesPhysics() {
    // Player
    physics::Engine::calculateRigidBodyMovement(*player, deltaTime);
    checkCharacterCollisionsWithEnvironment(*player);
}

void Game::checkCharacterCollisionsWithEnvironment(Character &character) {
    // X Axis
    character.getLastSafePosition().setVX(character.getPositionVector().getVX());
    updateCharacterXPositionAfterCalculations(character);

    if (CollisionDetector::checkCharacterCollisionWithEnvironment(character)) {
        character.getPositionVector().setVX(character.getLastSafePosition().getVX());
    }
    // Y Axis
    character.getLastSafePosition().setVY(character.getPositionVector().getVY());
    updateCharacterYPositionAfterCalculations(character);

    if (CollisionDetector::checkCharacterCollisionWithEnvironment(character)) {
        character.getPositionVector().setVY(character.getLastSafePosition().getVY());
    }
}

void Game::updateCharacterXPositionAfterCalculations(Character &character) {
    float newX = character.getPositionVector().getVX() + character.getRigidPosition().getVX();

    character.setX(newX);
    character.getMutableCollider().x = newX;
}

void Game::updateCharacterYPositionAfterCalculations(Character &character) {
    float newY = character.getPositionVector().getVY() + character.getRigidPosition().getVY();

    character.setY(newY);
    character.getMutableCollider().y = newY;
}

void Game::updateGraphics() {
    renderHelper.cleanRenderer();

    renderEntities();
    renderHelper.renderCharacter(*player);

    renderHelper.display();
}

void Game::renderEntities() {
    for (auto level : Map::getInstance()->getLevels()) {
        for (auto entity : level.getEntities()) {
            renderHelper.renderEntity(entity);
        }
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
