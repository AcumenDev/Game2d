#include "ResourceManager.hpp"

ResourceManager::ResourceManager() {
    //ctor
}

ResourceManager::~ResourceManager() {
    //dtor
}

Texture * ResourceManager::GetTextureFromFile(SDL_Renderer* render, std::string path) {
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    Texture* texture;
    if( loadedSurface == NULL ) {
        std::cout<<"Unable to load image "<<path.c_str()<<" SDL_image Error: "<<IMG_GetError()<<std::endl;
    } else {
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        newTexture = SDL_CreateTextureFromSurface(render, loadedSurface );
        if( newTexture == NULL ) {
            std::cout<<"Unable to create texture from "<<path.c_str()<< " SDL Error: "<<SDL_GetError()<<std::endl;
        }

        texture =  new Texture(render, newTexture, loadedSurface->w, loadedSurface->h);
        SDL_FreeSurface( loadedSurface );
    }

    return texture;
}
