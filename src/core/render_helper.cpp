#include "render_helper.h"
#include "animator.h"
#include <SDL_image.h>
#include <string>
#include <iostream>

RenderHelper::RenderHelper(int gameWindowWidth, int gameWindowHeight) {
    this->gameWindowWidth = gameWindowWidth;
    this->gameWindowHeight = gameWindowHeight;
}

void RenderHelper::initiateWindowAndRender() {
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

    SDL_Rect destination = generateRectForRender(entity.getX(), entity.getY(),
                                                 entity.getDestinationRenderWidth(),
                                                 entity.getDestinationRenderHeight());

    auto texturePosition = getTextureMapIterator(entity.textureKeyName);

    SDL_RenderCopy(renderer, texturePosition->second, &source, &destination);
}

void RenderHelper::renderCharacter(Character &character) {
    SDL_Rect source = generateRectForRender(getXCoordinateForCharacterSource(character), character.getModel().y,
                                            character.getModel().w, character.getModel().h);

    SDL_Rect destination = generateRectForRender(character.getX(), character.getY(),
                                                 character.getDestinationRenderWidth(),
                                                 character.getDestinationRenderHeight());

    std::string textureKey = character.textureKeyName +
                             getCharacterTextureKeyNameSuffix(character.getMovement());

    auto texturePosition = getTextureMapIterator(textureKey);

    SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE;
    if (character.shouldTextureBeHorizontallyFlipped()) flip = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;

    SDL_RenderCopyEx(renderer, texturePosition->second, &source, &destination, 0,
                     nullptr, flip);
}

float RenderHelper::getXCoordinateForCharacterSource(Character &character) {
    if (character.getMovement() == Movement::kLeftIdle || character.getMovement() == Movement::kRightIdle) {
        return Animator::computeCharacterIdleTextureOffset(character);
    } else if (character.getMovement() == Movement::kLeft || character.getMovement() == Movement::kRight) {
        return Animator::computeCharacterMovingTextureOffset(character);
    }

    return 0;
}

std::string RenderHelper::getCharacterTextureKeyNameSuffix(Movement characterMovement) {
    if (characterMovement == Movement::kLeftIdle || characterMovement == Movement::kRightIdle) return "Idle";
    return "Run";
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
