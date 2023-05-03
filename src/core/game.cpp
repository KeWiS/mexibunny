#include "game.h"
#include "constants.h"
#include "texture_holder.h"
#include "../utility/randomizer.h"
#include "../physics/collision_detector.h"
#include "../map/map.h"
#include <SDL_image.h>
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

    // Background
    textureHolder.textureMap.insert({"background",
                                     renderHelper.loadTexture(constants::file_names::kBackground)});
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
    return new Player(100, 550, 2, 64, 64);
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
        player->applyForceOnXAxis(constants::physics::kBackwardForce * 2500);
        player->applyFriction(physics::Vector2D(200, 1));
        player->setMovement(Movement::kLeft);
    }
    if (keyStates[SDL_SCANCODE_D] || keyStates[SDL_SCANCODE_RIGHT]) {
        player->setShouldTextureBeHorizontallyFlipped(false);
        player->applyForceOnXAxis(constants::physics::kForwardForce * 2500);
        player->applyFriction(physics::Vector2D(200, 1));
        player->setMovement(Movement::kRight);
    }
    // Checking if jumping
    if (player->getIsGrounded() && !player->getIsJumping() && keyStates[SDL_SCANCODE_SPACE]) {
        player->setIsGrounded(false);
        player->setIsJumping(true);
        player->applyForceOnYAxis(constants::physics::kUpwardForce * player->getJumpForce());
    } else if (player->getIsJumping() && player->getJumpTime() > 0) {
        player->decreaseJumpTime(deltaTime / 1000);
    } else if (player->getIsJumping()) {
        player->setIsJumping(false);
        player->setJumpTime(constants::physics::kJumpTime);
        player->applyForceOnYAxis(0);
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

    character.setIsGrounded(false);
    if (CollisionDetector::checkCharacterCollisionWithEnvironment(character)) {
        character.getPositionVector().setVY(character.getLastSafePosition().getVY());
        character.setIsGrounded(true);
        character.resetGravitationalAcceleration();
    }

    // Checking if character is out of boundaries of the map
    if (character.getPositionVector().getVY() > (windowHeight - 32) || character.getPositionVector().getVY() < 0) {
        character.getPositionVector().setVY(character.getLastSafePosition().getVY());
    }
    if (character.getPositionVector().getVX() > (windowWidth - character.getModel().w * 2)
        || character.getPositionVector().getVX() < 0) {
        character.getPositionVector().setVX(character.getLastSafePosition().getVX());
    }
}

void Game::updateCharacterXPositionAfterCalculations(Character &character) {
    float newX = character.getPositionVector().getVX() + character.getRigidPosition().getVX();

    character.setX(newX);
    character.getMutableCollider().x = newX;
    character.getMutableCollider().y = character.getY();
}

void Game::updateCharacterYPositionAfterCalculations(Character &character) {
    float newY = character.getPositionVector().getVY() + character.getRigidPosition().getVY();

    character.setY(newY);
    character.getMutableCollider().x = character.getX();
    character.getMutableCollider().y = newY;
}

void Game::updateGraphics() {
    renderHelper.cleanRenderer();

    renderHelper.renderBackground();
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
