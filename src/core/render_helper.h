#ifndef MEXIBUNNY_RENDER_HELPER_H
#define MEXIBUNNY_RENDER_HELPER_H

#include <SDL.h>
#include "../game_objects/character.h"
#include "../game_objects/entity.h"

class RenderHelper {
public:
    RenderHelper() {};

    RenderHelper(int gameWindowWidth, int gameWindowHeight);

    void initiateWindow();

    SDL_Texture *loadTexture(const char *p_filePath);

    void cleanRenderer();

    void renderBackground(SDL_Texture *texture);

    void renderEntity(Entity &entity);

    void renderCharacter(Character &character);

    void display();

    void cleanup();

private:
    int gameWindowWidth;
    int gameWindowHeight;

    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif //MEXIBUNNY_RENDER_HELPER_H
