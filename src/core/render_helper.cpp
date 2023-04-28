#include "render_helper.h"
#include "game.h"
#include <SDL_image.h>
#include <string>
#include <iostream>

RenderHelper::RenderHelper(int gameWindowWidth, int gameWindowHeight) {
    this->gameWindowWidth = gameWindowWidth;
    this->gameWindowHeight = gameWindowHeight;
}

void RenderHelper::initiateWindow() {
    window = SDL_CreateWindow("MexiBunny", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gameWindowWidth,
                              gameWindowHeight, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Window initiation failed, error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *RenderHelper::loadTexture(const char *p_filePath) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, p_filePath);

    return texture;
}

void RenderHelper::cleanRenderer() {
    SDL_RenderClear(renderer);
}

void RenderHelper::renderBackground(SDL_Texture *texture) {
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
}

void RenderHelper::renderEntity(Entity &entity) {
    SDL_Rect source = generateRectForRender(entity.getModel().x, entity.getModel().y, entity.getModel().w,
                                            entity.getModel().h);

    SDL_Rect destination = generateRectForRender(entity.getX(), entity.getY(), 32 * 2, 32 * 2);

    auto texturePosition = getTextureMapIterator(entity.textureKeyName);

    SDL_RenderCopy(renderer, texturePosition->second, &source, &destination);
}

void RenderHelper::renderCharacter(Character &character) {
    float xSource = 0;
    if (character.getMovement() == Movement::kLeftIdle || character.getMovement() == Movement::kRightIdle) {
        xSource = computePlayerIdleTextureOffset(dynamic_cast<Player *>(&character));
    }

    SDL_Rect source = generateRectForRender(xSource, character.getModel().y, character.getModel().w,
                                            character.getModel().h);

    SDL_Rect destination = generateRectForRender(character.getX(), character.getY(), 32 * 2, 32 * 2);

    std::string textureKey = character.textureKeyName +
                             getCharacterTextureKeyNameSuffix(character.getMovement());

    auto texturePosition = getTextureMapIterator(textureKey);

    SDL_RenderCopy(renderer, texturePosition->second, &source, &destination);
}

float RenderHelper::computePlayerIdleTextureOffset(Player *player) {
    int playerIdleIndex = player->getIdleIndex();

    if (Game::animationTimeCounter >= 500) {
        if (playerIdleIndex == 3) {
            player->setIdleIndex(0);
            playerIdleIndex = 0;
        } else {
            player->setIdleIndex(++playerIdleIndex);
        }

        Game::animationTimeCounter = 0;
    }

    return playerIdleIndex * 32;
}

std::string RenderHelper::getCharacterTextureKeyNameSuffix(Movement characterMovement) {
    if (characterMovement == Movement::kLeftIdle) return "LeftIdle";
    if (characterMovement == Movement::kRightIdle) return "RightIdle";
    if (characterMovement == Movement::kLeft) return "Left";
    return "Right";
}

SDL_Rect RenderHelper::generateRectForRender(int x, int y, int w, int h) {
    return SDL_Rect{x, y, w, h};
}

std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, SDL_Texture *>>
RenderHelper::getTextureMapIterator(std::string key) {
    auto texturePosition = textureHolder.textureMap.find(key);
    if (texturePosition == textureHolder.textureMap.end()) {
        // TODO: Perform error exception handling
    }

    return texturePosition;
}

void RenderHelper::display() {
    SDL_RenderPresent(renderer);
}

void RenderHelper::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

TextureHolder RenderHelper::getTextureHolder() {
    return textureHolder;
}

void RenderHelper::setTextureHolder(const TextureHolder &textureHolder) {
    this->textureHolder = textureHolder;
}
