#include "Texture.hpp"

Texture::Texture(SDL_Renderer *render, SDL_Texture *texture, int w, int h) {
    _render = render;
    _texture = texture;
    _w = w;
    _h = h;
}

Texture::~Texture() {
    free();
}

void Texture::free() {
    if (_texture != NULL) {
        SDL_DestroyTexture(_texture);
        _texture = NULL;
    }
}

void Texture::Draw(IPoint iPoint) {
    SDL_Rect renderQuad = {iPoint.x, iPoint.y, getWidth(), getHeight()};
    SDL_RenderCopy(_render, _texture, NULL, &renderQuad);
}

void Texture::Draw(FPoint fPoint) {
    Draw(IPoint(fPoint.x, fPoint.y));
}
int Texture::getWidth() {
    return _w;
}

int Texture::getHeight() {
    return _h;
}
