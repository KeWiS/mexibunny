#include "game.h"

Game::Game(int gameWindowWidth, int gameWindowHeight) {
    this->gameWindowWidth = gameWindowWidth;
    this->gameWindowHeight = gameWindowHeight;

    initGame();
}

void Game::initGame() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("MexiBunny", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              gameWindowWidth, gameWindowHeight, SDL_WINDOW_SHOWN);
    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
