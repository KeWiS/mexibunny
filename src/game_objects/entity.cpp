#include "entity.h"

SDL_Rect &Entity::getModel() {
    return model;
}

SDL_Texture *Entity::getTexture() {
    return texture;
}

void Entity::setTexture(SDL_Texture *texture) {
    this->texture = texture;
}

void Entity::setModel(SDL_Rect model) {
    this->model = model;
}
