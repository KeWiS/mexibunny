#ifndef MEXIBUNNY_TEXTURE_HOLDER_H
#define MEXIBUNNY_TEXTURE_HOLDER_H

#include <SDL.h>
#include <map>
#include <string>

struct TextureHolder {
    std::map<std::string, SDL_Texture *> textureMap;
};

#endif //MEXIBUNNY_TEXTURE_HOLDER_H
