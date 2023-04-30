#ifndef MEXIBUNNY_RENDER_HELPER_H
#define MEXIBUNNY_RENDER_HELPER_H

#include <SDL.h>
#include "texture_holder.h"
#include "../game_objects/character.h"
#include "../game_objects/player.h"
#include "../game_objects/entity.h"

class RenderHelper {
public:
    RenderHelper() {};

    RenderHelper(int gameWindowWidth, int gameWindowHeight);

    void initiateWindowAndRender();

    SDL_Texture *loadTexture(const char *p_filePath);

    void cleanRenderer();

    void renderBackground(SDL_Texture *texture);

    void renderEntity(Entity &entity);

    void renderCharacter(Character &character);

    float getXCoordinateForCharacterSource(Character &character);

    std::string getCharacterTextureKeyNameSuffix(Movement characterMovement);

    SDL_Rect generateRectForRender(int x, int y, int w, int h);

    std::_Rb_tree_iterator<std::pair<const std::basic_string<char>, SDL_Texture *>>
    getTextureMapIterator(std::string key);

    void display();

    void cleanup();

    TextureHolder getTextureHolder();

    void setTextureHolder(const TextureHolder &textureHolder);

private:
    int gameWindowWidth;
    int gameWindowHeight;

    TextureHolder textureHolder;

    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif //MEXIBUNNY_RENDER_HELPER_H
