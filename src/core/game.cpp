#include "game.h"
#include "constants.h"
#include "texture_holder.h"
#include "../utility/randomizer.h"
#include "../physics/collision_detector.h"
#include "../map/map.h"
#include "../game_objects/banana.h"
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

    generateEnvironment();
    this->player = generatePlayer();
    generateInitialEnemies();

    startGame();
}

TextureHolder Game::loadAllTextures() {
    TextureHolder textureHolder;

    // Background
    textureHolder.textureMap.insert({"background",
                                     renderHelper.loadTexture(constants::file_names::kBackground)});
    // Environment
    textureHolder.textureMap.insert({"ground1",
                                     renderHelper.loadTexture(constants::file_names::kGroundFilePath)});
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
    textureHolder.textureMap.insert({"playerInAir",
                                     renderHelper.loadTexture(constants::file_names::kBunnyInAir)});

    // Enemies
    textureHolder.textureMap.insert({"bananaIdle",
                                     renderHelper.loadTexture(constants::file_names::kBananaIdle)});

    return textureHolder;
}

Player *Game::generatePlayer() {
    return new Player(0, 450, 2, 64, 64, 32, 32,
                      64, 62);
}

void Game::generateInitialEnemies() {
    // Generating one enemy per level
    for (auto level : Map::getInstance()->getLevels()) {
        // Choosing first segment with possibility of spawn
        for (auto segment : level.getSegments()) {
            if (segment.allowSpawnOnSegment) {
                auto bananaXCoordinate = utility::Randomizer::getRandomIntegerInRange(
                        segment.frect.x,
                        segment.frect.x + segment.frect.w - 64
                );

                auto bananaYCoordinate = segment.frect.y - segment.frect.h;

                enemies.push_back(Banana(bananaXCoordinate, bananaYCoordinate, 2, 64,
                                         64, 32, 32, 64, 62));

                break;
            }
        }
    }
}

void Game::generateEnvironment() {
    // Generating first level with grass
    Map::getInstance()->createLevel(
            {
                    SegmentParameters(0, 656, 62, 7,
                                      utility::Randomizer::getRandomIntegerInRange(1, 1),
                                      64, "ground", false),
                    SegmentParameters(0, 592, 62, 7,
                                      utility::Randomizer::getRandomIntegerInRange(1, 3),
                                      64, "grass", false),
                    SegmentParameters(7 * 64, 656, 62, 10,
                                      utility::Randomizer::getRandomIntegerInRange(1, 3),
                                      64, "grass", true),
                    SegmentParameters(17 * 64, 656, 62, 3,
                                      utility::Randomizer::getRandomIntegerInRange(1, 1),
                                      64, "ground", false),
                    SegmentParameters(17 * 64, 592, 62, 3,
                                      utility::Randomizer::getRandomIntegerInRange(1, 3),
                                      64, "grass", true)
            });
    // Generating second level
    Map::getInstance()->createLevel(
            {
                    SegmentParameters(128, 400, 62, 3,
                                      utility::Randomizer::getRandomIntegerInRange(1, 3),
                                      64, "grass", true),
                    SegmentParameters(320, 400, 62, 10,
                                      utility::Randomizer::getRandomIntegerInRange(1, 3),
                                      64, "grass", true),
            });
    // Generating third level
    Map::getInstance()->createLevel(
            {
                    SegmentParameters(192, 208, 62, 4,
                                      utility::Randomizer::getRandomIntegerInRange(1, 3),
                                      64, "grass", true),
                    SegmentParameters(448, 144, 62, 4,
                                      utility::Randomizer::getRandomIntegerInRange(1, 3),
                                      64, "grass", true),
                    SegmentParameters(704, 208, 62, 2,
                                      utility::Randomizer::getRandomIntegerInRange(1, 3),
                                      64, "grass", true),
                    SegmentParameters(1088, 272, 62, 3,
                                      utility::Randomizer::getRandomIntegerInRange(1, 3),
                                      64, "grass", true)
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
    // Limiting frame rate to 144
    delayToMeetFrameRateLimit();
    // Handling game events, player movement, calculations of NPC movements and physics, graphics display
    handleGameEvents();
    handlePlayerMovement();
    calculateBodiesPhysics();
    updateGraphics();
}

double Game::calculateDeltaTime() {
    previousTick = currentTick;
    currentTick = SDL_GetPerformanceCounter();
    // TODO: Check with Daniel if game runs correctly
    double deltaT = (double) ((currentTick - previousTick) * 1000 / (double) SDL_GetPerformanceFrequency());

    if (deltaT > maxDeltaTime) deltaT = maxDeltaTime;

    return deltaT;
}

void Game::delayToMeetFrameRateLimit() {
    if (deltaTime < targetDeltaTime) SDL_Delay(targetDeltaTime - deltaTime);
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
        player->applyForceOnXAxis(0);
        player->applyFriction(physics::Vector2D(0, 0));
    } else {
        player->setMovement(Movement::kRightIdle);
        player->applyForceOnXAxis(0);
        player->applyFriction(physics::Vector2D(0, 0));
    }
    // Checking if moving
    if (keyStates[SDL_SCANCODE_A] || keyStates[SDL_SCANCODE_LEFT]) {
        player->applyForceOnXAxis(constants::physics::kBackwardForce * 750);
        player->applyFriction(physics::Vector2D(200, 1));
        player->setMovement(Movement::kLeft);
        player->setLastRecordedMovementDirection(Movement::kLeft);
    }
    if (keyStates[SDL_SCANCODE_D] || keyStates[SDL_SCANCODE_RIGHT]) {
        player->applyForceOnXAxis(constants::physics::kForwardForce * 750);
        player->applyFriction(physics::Vector2D(200, 1));
        player->setMovement(Movement::kRight);
        player->setLastRecordedMovementDirection(Movement::kRight);
    }
    // Checking if jumping
    if (player->getIsGrounded() && !player->getIsJumping() && keyStates[SDL_SCANCODE_SPACE]) {
        player->setIsGrounded(false);
        player->setIsJumping(true);
        player->applyForceOnYAxis(constants::physics::kUpwardForce * player->getJumpForce());
        player->setMovement(Movement::kInAir);
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

    if (CollisionDetector::checkCharacterCollisionWithEnvironment(character)) {
        character.getPositionVector().setVY(character.getLastSafePosition().getVY());
        character.setIsGrounded(true);
        character.resetGravitationalAcceleration();
    } else {
        character.setIsGrounded(false);
        character.setMovement(Movement::kInAir);
    }

    // Checking if character is out of boundaries of the map
    if (character.getPositionVector().getVY() > (windowHeight - 32)) {
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
    player->addToAnimationTimeCounter(deltaTime);
    renderEnemies();

    renderHelper.display();
}

void Game::renderEntities() {
    for (auto level : Map::getInstance()->getLevels()) {
        for (auto entity : level.getEntities()) {
            renderHelper.renderEntity(entity);
        }
    }
}

void Game::renderEnemies() {
    for (auto &enemy : enemies) {
        enemy.addToAnimationTimeCounter(deltaTime);
        renderHelper.renderCharacter(enemy);
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
