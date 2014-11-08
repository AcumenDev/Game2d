#include "Texture.hpp"

Texture::Texture() {
    _texture = NULL;
    mWidth = 0;
    mHeight = 0;
}

Texture::~Texture() {
    free();
}

bool Texture::loadFromFile(std::string path ) {
    free();
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ) {
        std::cout<<"Unable to load image "<<path.c_str()<<" SDL_image Error: %s\n"<<IMG_GetError();
    } else {
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        newTexture = SDL_CreateTextureFromSurface(_render, loadedSurface );
        if( newTexture == NULL ) {
            std::cout<<"Unable to create texture from "<<path.c_str()<<" SDL Error: %s\n"<<SDL_GetError();
        } else {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface( loadedSurface );
    }

    _texture = newTexture;
    return _texture != NULL;
}

void Texture::free() {
    if( _texture != NULL ) {
        SDL_DestroyTexture( _texture );
        _texture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::render(int x, int y ) {
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopy( _render, _texture, NULL, &renderQuad );
}

int Texture::getWidth() {
    return mWidth;
}

int Texture::getHeight() {
    return mHeight;
}

void Texture::Init(SDL_Renderer* render) {
    _render = render;
}


