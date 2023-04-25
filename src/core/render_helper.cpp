#include "render_helper.h"
#include <SDL_image.h>
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
    SDL_Rect source;
    source.x = entity.getModel().x;
    source.y = entity.getModel().y;
    source.w = entity.getModel().w;
    source.h = entity.getModel().h;

    SDL_Rect destination;
    destination.x = entity.getX() * 2;
    destination.y = entity.getY() * 2;
    destination.w = 32 * 2;
    destination.h = 32 * 2;

    SDL_RenderCopy(renderer, entity.getTexture(), &source, &destination);
}

void RenderHelper::renderCharacter(Character &character) {
    SDL_Rect source;
    source.x = character.getModel().x;
    source.y = character.getModel().y;
    source.w = character.getModel().w;
    source.h = character.getModel().h;

    SDL_Rect destination;
    destination.x = character.getX() * 2;
    destination.y = character.getY()  * 2;
    destination.w = 32  * 2;
    destination.h = 32  * 2;

    SDL_Texture *texture;
    if (character.getMovement() == Movement::kLeft) {
        texture = character.getTextureLeft();
    }
    else {
        texture = character.getTextureRight();
    }

    SDL_RenderCopy(renderer, texture, &source, &destination);
}

void RenderHelper::display() {
    SDL_RenderPresent(renderer);
}

void RenderHelper::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
