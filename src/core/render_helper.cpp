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

// Function for rendering characters
void RenderHelper::render(Character &p_character) {
    SDL_SetRenderDrawColor(renderer, 255, 100, 50, 255);
    SDL_RenderFillRectF(renderer, &p_character.getModel());
}

void RenderHelper::display() {
    SDL_RenderPresent(renderer);
}

void RenderHelper::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
