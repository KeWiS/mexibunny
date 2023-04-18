#ifndef MEXIBUNNY_GAME_H
#define MEXIBUNNY_GAME_H
#define SDL_MAIN_HANDLED

#include <SDL.h>

class Game {
private:
    int gameWindowWidth;
    int gameWindowHeight;

    SDL_Window *window;

    void initGame();

public:
    Game(int gameWindowWidth, int gameWindowHeight);
};

#endif //MEXIBUNNY_GAME_H
