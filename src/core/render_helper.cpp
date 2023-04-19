#include "render_helper.h"

RenderHelper::RenderHelper(int gameWindowWidth, int gameWindowHeight) {
    this->gameWindowWidth = gameWindowWidth;
    this->gameWindowHeight = gameWindowHeight;
}

void RenderHelper::initiateWindow() {
    SDL_CreateWindowAndRenderer(gameWindowWidth, gameWindowHeight, SDL_WINDOW_SHOWN,
                                &window, &renderer);
}

void RenderHelper::cleanRenderer() {
    SDL_RenderClear(renderer);
}

void RenderHelper::renderBackground() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void RenderHelper::render(Character &p_character) {
    cleanRenderer();
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
